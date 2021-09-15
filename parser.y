%{
#include <cstdio>
#include "ast.hpp"
#include "lexer.hpp"
%}

%token T_and
%token T_dim
%token<bool_expr> T_false
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
%token<bool_expr> T_true
%token<var> T_Id
%token<var> T_id
%token<int_expr> T_int_expr
%token<float_expr> T_float_expr
%token<char_expr> T_char_expr
%token<str_expr> T_str_expr
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
%right T_array T_of T_ref
%nonassoc '!'
%nonassoc T_new

%union {
  std::vector<Stmt *> *stmt_vec;
  Stmt *stmt;
  std::vector<Def *> *def_vec;
  LetDef *letdef;
  Def *def;
  std::vector<Par *> *par_vec;

  TypeDef *type_def;
  std::vector<TDef *> *tdef_vec;
  TDef *tdef;
  std::vector<Constr *> *constr_vec;
  Constr *constr;
  Par *par;
  Expr *expr;
  std::vector<Expr *> *expr_vec;
  // Type type;
  int int_expr;
  float float_expr;
  char char_expr;
  char* str_expr;
  bool bool_expr;
  char* var;
  // char op;
}

%type<stmt_vec> program stmt_list
%type<stmt> stmt
%type<def_vec> and_def_list
%type<letdef> letdef
%type<def> def
%type<par_vec> par_list

%type<type_def> typedef
%type<tdef_vec> and_tdef_list
%type<tdef> tdef 
%type<constr_vec> constr_list
%type<constr> constr
%type<par> par
%type<expr> expr expr1 expr2 expr3 expr4 expr5
%type<expr_vec> comma_expr_list
%%

program:
  stmt_list { 
    std::cout << "AST: " << *$1 << std::endl; 
  }
;

stmt_list:
  %empty  { $$ = new std::vector<Stmt *>; }
| stmt_list stmt  { $1->push_back($2); $$ = $1; }
;

stmt:
  letdef { $$ = $1; }
| typedef { $$ = $1; }
;

letdef:
  T_let and_def_list  { $$ = new LetDef($2); }
| T_let T_rec and_def_list  { $$ = new LetDef($3); }
;

and_def_list:
  def { $$ = new std::vector<Def *>; $$->push_back($1); }
| and_def_list T_and def { $1->push_back($3); $$ = $1; }
;

def:
  T_id par_list '=' expr  { $$ = new NormalDef($2, $4); }
| T_id par_list ':' type '=' expr  { $$ = new NormalDef($2, $6); }
| T_mutable T_id  { $$ = new MutableDef(); }
| T_mutable T_id '[' comma_expr_list ']'  { $$ = new MutableDef(); }
| T_mutable T_id ':' type  { $$ = new MutableDef(); }
| T_mutable T_id '[' comma_expr_list ']' ':' type  { $$ = new MutableDef(); }
;

par_list:
  %empty  { $$ = new std::vector<Par *>; }
| par_list par { $1->push_back($2); $$ = $1; }
;

comma_expr_list:
  expr { $$ = new std::vector<Expr *>; $$->push_back($1); }
| comma_expr_list ',' expr { $1->push_back($3); $$ = $1; }
;

typedef:
  T_type and_tdef_list { $$ = new TypeDef($2); }
;

and_tdef_list:
  tdef { $$ = new std::vector<TDef *>; $$->push_back($1); }
| and_tdef_list T_and tdef { $1->push_back($3); $$ = $1; }
;

tdef:
  T_id '=' constr_list { $$ = new TDef($3); }
;

constr_list:
  constr  { $$ = new std::vector<Constr *>; $$->push_back($1); }
| constr_list '|' constr { $1->push_back($3); $$ = $1; }
;

constr:
  T_Id { $$ = new Constr(); }
| T_Id T_of constr_type_list { $$ = new Constr(); }
;

constr_type_list:
  type
| constr_type_list type
;

par:
  T_id { $$ = new Par(); }
| '(' T_id ':' type ')' { $$ = new Par(); }
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
| T_array '[' comma_star_list ']' T_of type
| T_id
;

comma_star_list:
  '*'
| comma_star_list ',' '*'
;

expr:
  expr5 { $$ = $1; }
| letdef T_in expr %prec LET_IN
| expr ';' expr
;

expr1:
  T_int_expr { $$ = new Int_Expr($1); }
| T_float_expr { $$ = new Float_Expr($1); }
| T_char_expr { $$ = new Char_Expr($1); }
| T_str_expr { $$ = new Str_Expr($1); }
| T_true { $$ = new Bool_Expr(true); }
| T_false { $$ = new Bool_Expr(false); }
| '(' ')' { $$ = new Unit(); }
| '(' expr ')' { $$ = $2; }
| T_begin expr T_end { $$ = $2; }
| T_id '[' comma_expr_list ']' { $$ = new Array($1, $3); }
| T_dim T_id { $$ = new Dim($2); }
| T_dim T_int_expr T_id { $$ = new Dim($3, $2); }
| T_new type
| T_id { $$ = new id($1); }
| T_Id { $$ = new Id($1); }
| '!' expr1 { $$ = new Exclamation($2); }
| T_while expr T_do expr T_done { $$ = new While($2, $4); }
| T_for T_id '=' expr T_to expr T_do expr T_done
| T_for T_id '=' expr T_downto expr T_do expr T_done
| T_match expr T_with or_clause_list T_end
;

expr2:
  expr1 { $$ = $1; }
| T_id expr_list
| T_Id expr_list
;

expr3:
  expr2 { $$ = $1; }
| '+' expr2
| '-' expr2
| T_plus_op expr2
| T_minus_op expr2
| T_not expr2
| T_delete expr2
;

expr4:
  expr3 { $$ = $1; }
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
  expr4 { $$ = $1; }
| T_if expr5 T_then expr %prec IF_THEN_ELSE
| T_if expr5 T_then expr T_else expr %prec IF_THEN_ELSE
;

or_clause_list:
  clause
| or_clause_list '|' clause
;

expr_list:
  expr1
| expr_list expr1
;

clause:
  pattern T_arrow_op expr
;

pattern:
  pattern1
| T_Id pattern_list
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
  pattern1
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