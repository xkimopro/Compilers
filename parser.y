%{
#include <cstdio>
#include "ast.hpp"
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
%left ';'
%nonassoc IF_THEN_ELSE
%right T_else
%nonassoc T_assign_op
%left T_or_op
%left T_and_op
%nonassoc '=' T_struct_diff_op '>' '<' T_leq_op T_geq_op T_eq_op T_diff_op
%left '+' '-' T_plus_op T_minus_op
%left '*' '/' T_mult_op T_div_op T_mod
%right T_pow_op
%right T_arrow_op
%nonassoc T_array T_of T_ref
%nonassoc '!'
%nonassoc T_new

%union {
  Stmt_list *stmt_list;
  LetDef *letdef;
  TypeDef *typdef;
  Stmt *stmt;
  Def *def;
  TDef *tdef;
  // Expr *expr;
  // Decl *decl;
  // Type type;
  // char var;
  // int num;
  // char op;
}

%type<stmt_list> program stmt_list
%type<stmt> stmt
%type<letdef> letdef and_def_list
%type<typdef> typedef and_tdef_list
%type<def> def
%type<tdef> tdef

%%

program:
  stmt_list { 
    std::cout << "AST: " << *$1 << std::endl; 
  }
;

stmt_list:
  %empty  { $$ = new Stmt_list; }
| stmt_list stmt  { $1->append_stmt($2); $$ = $1; }
;

stmt:
  letdef { $$ = $1; }
| typedef { $$ = $1; }
;

letdef:
  T_let def and_def_list  { $3->append_front_def($2); $$ = $3; }
| T_let T_rec def and_def_list  { $4->append_front_def($3); $$ = $4; }
;

and_def_list:
  %empty { $$ = new LetDef(); }
| and_def_list T_and def { $1->append_def($3); $$ = $1; }
;

def:
  T_id par_list '=' expr  { $$ = new Def(); }
| T_id par_list ':' type '=' expr  { $$ = new Def(); }
| T_mutable T_id  { $$ = new Def(); }
| T_mutable T_id '[' expr comma_expr_list ']'  { $$ = new Def(); }
| T_mutable T_id ':' type  { $$ = new Def(); }
| T_mutable T_id '[' expr comma_expr_list ']' ':' type  { $$ = new Def(); }
;

comma_expr_list:
  %empty
| comma_expr_list ',' expr 
;

typedef:
  T_type tdef and_tdef_list { $3->append_front_tdef($2); $$ = $3; }
;

and_tdef_list:
  %empty  { $$ = new TypeDef(); }
| and_tdef_list T_and tdef { $1->append_tdef($3); $$ = $1; }
;

tdef:
  T_id '=' constr constr_list  { $$ = new TDef(); }
  ;

constr_list:
  %empty
| constr_list '|' constr
;

constr:
  T_Id
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
  expr5
| letdef T_in expr                            %prec LET_IN
| T_while expr T_do expr T_done
| T_for T_id '=' expr T_to expr T_do expr T_done
| T_for T_id '=' expr T_downto expr T_do expr T_done
| T_match expr T_with clause or_clause_list T_end
| expr ';' expr
;

expr1:
  T_int_expr
| T_float_expr
| T_char_expr
| T_str_expr
| T_true
| T_false
| '(' ')'
| '(' expr ')'
| T_begin expr T_end
| T_id '[' expr comma_expr_list ']'
| T_dim T_id
| T_dim T_int_expr T_id
| T_new type
| T_id
| T_Id
| '!' expr1
;

expr2:
  expr1
| T_id expr1 expr_list
| T_Id expr1 expr_list
;

expr3:
  expr2
| '+' expr2
| '-' expr2
| T_plus_op expr2
| T_minus_op expr2
| T_not expr2
| T_delete expr2
;

expr4:
  expr3
| expr4 '+' expr4
| expr4 '-' expr4
| expr4 '*' expr4
| expr4 '/' expr4
| expr4 T_plus_op expr4
| expr4 T_minus_op expr4
| expr4 T_mult_op expr4
| expr4 T_div_op expr4
| expr4 T_mod expr4
| expr4 T_pow_op expr4
| expr4 '=' expr4
| expr4 T_struct_diff_op expr4
| expr4 '<' expr4
| expr4 '>' expr4
| expr4 T_leq_op expr4
| expr4 T_geq_op expr4
| expr4 T_eq_op expr4
| expr4 T_diff_op expr4
| expr4 T_and_op expr4
| expr4 T_or_op expr4
| expr4 T_assign_op expr4
;

expr5:
  expr4
| T_if expr5 T_then expr                     %prec IF_THEN_ELSE
| T_if expr5 T_then expr T_else expr         %prec IF_THEN_ELSE
;

or_clause_list:
  %empty
| or_clause_list '|' clause
;

expr_list:
  %empty
| expr_list expr1
;

clause:
  pattern T_arrow_op expr
;

pattern:
  pattern1
| T_Id pattern1 pattern_list
;

pattern1:
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
| T_Id
;

pattern_list:
  %empty
| pattern_list pattern1
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