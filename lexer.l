%option noyywrap

%{

#define T_eof 0
#define T_and 1001
#define T_dim 1002
#define T_false 1003
#define T_let 1004
#define T_of 1005
#define T_type 1006
#define T_array 1007
#define T_do 1008
#define T_float 1009
#define T_match 1010
#define T_rec 1011
#define T_unit 1012
#define T_begin 1013
#define T_done 1014
#define T_for 1015
#define T_mod 1016
#define T_ref 1017
#define T_while 1018
#define T_bool 1019
#define T_downto 1020
#define T_if 1021
#define T_mutable 1022
#define T_then 1023
#define T_with 1024
#define T_char 1025
#define T_else 1026
#define T_in 1027
#define T_new 1028
#define T_to 1029
#define T_delete 1030
#define T_end 1031
#define T_int 1032
#define T_not 1033
#define T_true 1034

#define T_constr 1035
#define T_var 1036
#define T_int_expr 1037
#define T_float_expr 1038
#define T_char_expr 1039
#define T_str_expr 1040

#define T_arrow_op 1041
#define T_plus_op 1042
#define T_minus_op 1043
#define T_mult_op 1044
#define T_div_op 1045
#define T_pow_op 1046
#define T_and_op 1047
#define T_or_op 1048
#define T_struct_diff_op 1049
#define T_leq_op 1050
#define T_geq_op 1051
#define T_eq_op 1052
#define T_diff_op 1053
#define T_assign_op 1054

%}


l [a-z]
L [A-Z]
D [0-9]
W [ \t\r\n]
HEX x[0-9A-Fa-f][0-9A-Fa-f]
ESC_CHAR \\([ntr0\\\'\"]|{HEX})
SIMPLE_CHAR [^\'\"\x00-\x19\x80-\xff]
CHAR {SIMPLE_CHAR}|{ESC_CHAR}


%%



"and"   { return T_and; }
"dim" { return T_dim; }
"false"   { return T_false; }
"let"    { return T_let; }
"of"  { return T_of; }
"type"    { return T_type; }
"array" { return T_array; }
"do"   { return T_do; }
"float"   { return T_float; }
"match"   { return T_match; }
"rec"   { return T_rec; }
"unit"   { return T_unit; }
"begin"   { return T_begin; }
"done"   { return T_done; }
"for"   { return T_for; }
"mod"   { return T_mod; }
"ref"   { return T_ref; }
"while" { return T_while; }
"bool"   { return T_bool; }
"downto"    { return T_downto; }
"if"  { return T_if; }
"mutable"    { return T_mutable; }
"then" { return T_then; }
"with"   { return T_with; }
"char"   { return T_char; }
"else" { return T_else; }
"in"   { return T_in; }
"new"    { return T_new; }
"to"  { return T_to; }
"delete"    { return T_delete; }
"end" { return T_end; }
"int"   { return T_int; }
"not"    { return T_not; }
"true"  { return T_true; }


[A-Z][A-Za-z_0-9]* { return T_constr; }
[a-z][A-Za-z_0-9]*   { return T_var; }
[0-9]+\.[0-9]+([eE][\-+][0-9]+)? { return T_float_expr; }
 
\'{CHAR}\' { return T_char_expr; }

\"{CHAR}*\" { return T_str_expr; }

{D}+                {return T_int_expr; }

"->"  {return T_arrow_op; }
"+."  {return T_plus_op; }
"-."  {return T_minus_op; }
"*."  {return T_mult_op; }
"/."  {return T_div_op; }
"**"  {return T_pow_op; }
"&&"  {return T_and_op; }
"||" { return T_or_op; }
"<>" { return T_struct_diff_op; }
"<=" { return T_leq_op; }
">=" { return T_geq_op; }
"==" { return T_eq_op; }
"!=" { return T_diff_op; }
":=" { return T_assign_op; }

\-\-.*  { /* nothing' */ }


[()\[\],:=|+\-*\/!;<>]  { return yytext[0]; }

{W}+    { /* nothing */ }

\(\*([^*]+|\*+[^*)])*\*+\)  { /* nothing' */ }




. {  fprintf(stderr, "Illegal character with code %d", yytext[0]); exit(1); }


%%

#ifdef yyFlexLexer
int main () {
  yyFlexLexer lexer;
  int token;
  do {
    token = lexer.yylex();
    printf("token=%d, lexeme=\"%s\"\n", token, lexer.YYText());
  } while (token != T_eof);
}
#else
int main () {
  int token;
  do {
    token = yylex();
    printf("token=%d, lexeme=\"%s\"\n", token, yytext);
  } while (token != T_eof);
}
#endif