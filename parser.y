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
%token T_constr
%token T_var
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

%left '+' '-'
%left '*' '/' '%'

%expect 1

%%

program:
  stmt_list
;

stmt_list:
  /* nothing */
| stmt_list stmt
;

stmt:
  "let" T_var '=' expr
| "print" expr
| "for" expr "do" stmt
| "if" expr "then" stmt
| "if" expr "then" stmt "else" stmt
| "begin" stmt_list "end"
;

expr:
  T_var
| '(' expr ')'
| expr '+' expr
| expr '-' expr
| expr '*' expr
| expr '/' expr
| expr '%' expr
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