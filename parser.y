%{
#include <cstdio>
#include "lexer.hpp"
%}

%token T_and
%token T_dim
%token T_false
%token T_let
%token T_of
%token T_type
%token T_array
%token T_do
%token T_float
%token T_match
%token T_rec
%token T_unit
%token T_begin
%token T_done
%token T_for
%token T_mod
%token T_ref
%token T_while
%token T_bool
%token T_downto
%token T_if
%token T_mutable
%token T_then
%token T_with
%token T_char
%token T_else
%token T_in
%token T_new
%token T_to
%token T_delete
%token T_end
%token T_int
%token T_not
%token T_true
%token T_Id
%token T_id
%token T_int_expr
%token T_float_expr
%token T_char_expr
%token T_str_expr
%token T_arrow_op
%token T_plus_op
%token T_minus_op
%token T_mult_op
%token T_div_op
%token T_pow_op
%token T_and_op
%token T_or_op
%token T_struct_diff_op
%token T_leq_op
%token T_geq_op
%token T_eq_op
%token T_diff_op
%token T_assign_op




%nonassoc LET_IN
%nonassoc LET_DEF
%left ';'
%nonassoc IF_THEN_ELSE
%nonassoc T_assign_op
%left T_or_op
%left T_and_op
%nonassoc '=' T_struct_diff_op '>' '<' T_leq_op T_geq_op T_eq_op T_diff_op
%left '+' '-' T_plus_op T_minus_op
%left '*' '/' T_mult_op T_div_op T_mod
%right T_pow // To be fixed
%nonassoc PLUS_UNOP MINUS_UNOP PLUS_DOT_UNOP MINUS_DOT_UNOP T_not T_delete
%nonassoc FUN_CALL
%nonassoc '!'
%nonassoc ARRAY_ELEM
%nonassoc T_new

%%

program:
  stmt_list
;

stmt_list:
  %empty
| stmt_list stmt
;

stmt:
  letdef {printf("letdef");}
| typedef
;

letdef:
 T_let def and_def_list %prec LET_DEF
| T_let T_rec def and_def_list %prec LET_DEF
;

and_def_list:
  %empty
| and_def_list T_and def
;

def:
 T_id par_list '=' expr
| T_id par_list ':' type '=' expr
| T_mutable T_id
| T_mutable T_id '[' expr comma_expr_list ']'
| T_mutable T_id ':' type
| T_mutable T_id '[' expr comma_expr_list ']' ':' type
;

comma_expr_list:
  %empty
| comma_expr_list ',' expr 
;

typedef:
 T_type tdef and_tdef_list
;

and_tdef_list:
  %empty
| and_tdef_list T_and tdef
;

tdef: T_id '=' constr constr_list;

constr_list:
  %empty
| constr_list '|' constr 
;

constr: T_Id 
| T_Id T_of constr_type_list
;

constr_type_list:
  type 
| constr_type_list type
;

par:
  T_id 
| '(' T_id ':' type ')'
;

par_list:
  %empty
| par_list par
;

type:
 T_unit
| T_int
| T_char
| T_bool
| T_float
| '(' type ')'
| type T_arrow_op type
| type T_ref
| T_array T_of type
| T_array '[' '*' comma_star_list ']' T_of type
| T_id
;

comma_star_list:
  %empty
| comma_star_list ',' '*'
;

expr:
  _expr
| unop expr
| expr binop expr
| T_id expr_list %prec FUN_CALL {printf("func");}
| T_Id expr_list
| T_delete expr
| letdef T_in expr %prec LET_IN
| T_begin expr T_end
| T_if expr T_then expr %prec IF_THEN_ELSE
| T_if expr T_then expr T_else expr %prec IF_THEN_ELSE
| T_while expr T_do expr T_done
| T_for T_id '=' expr T_to expr T_do expr T_done
| T_for T_id '=' expr T_downto expr T_do expr T_done
| T_match expr T_with clause or_clause_list T_end
;

or_clause_list:
 %empty
| or_clause_list '|' clause
;

expr_list:
  %empty {printf("expr");}
| expr_list _expr {printf("expr");}
;

_expr:
  T_int_expr
| T_float_expr
| T_char_expr
| T_str_expr
| T_true
| T_false
| '(' ')'
| '(' expr ')'
| T_id '[' expr comma_expr_list ']' %prec ARRAY_ELEM
| T_dim T_id
| T_dim T_int_expr T_id
| T_new type
| T_id
| T_Id
| '!' _expr
;

unop:
 '+' %prec PLUS_UNOP
| '-' %prec MINUS_UNOP
| T_plus_op %prec PLUS_DOT_UNOP
| T_minus_op %prec MINUS_DOT_UNOP
| T_not
;

binop:
 '+'
| '-'
| '*'
| '/'
| T_plus_op
| T_minus_op
| T_mult_op
| T_div_op
| T_mod
| T_pow_op
| '='
| T_struct_diff_op
| '<'
| '>'
| T_leq_op
| T_geq_op
| T_eq_op
| T_diff_op
| T_and_op
| T_or_op
| ';'
| T_assign_op
;

clause:
 pattern T_arrow_op expr
;

pattern:
 T_int_expr
| '+' T_int_expr
| '-' T_int_expr
| T_float_expr
| T_plus_op T_float_expr
| T_minus_op T_float_expr
| T_char_expr
| T_true
| T_false
| T_id
| '(' pattern ')'
| T_Id pattern_list
;

pattern_list:
 %empty
| pattern_list pattern
;

%%

void yyerror(const char *msg) {
   fprintf (stderr, "Error: %s\n", msg);
   exit(1);
}

int main() {
  int result = yyparse();
  if (result == 0) printf("Success.\n");
  return result;
}