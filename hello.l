%{
 
#define T_eof 0
#define T_then 1001
#define T_begin 1002
#define T_end 1003
#define T_if 1004
#define T_let 1005
#define T_do 1006
#define T_else 1007
#define T_print 1008
#define T_for  1009
#define T_id  1010
#define T_const 1011

 
%}


L [a-z]
D [0-9]
W [\t\n\r]

%option noyywrap
 
%%
 
 
"if"  { return T_if; }
"then"  { return T_then; }
"begin"  { return T_begin; }
"end"  { return T_end; }
"let"  { return T_let; }
"do"  { return T_do; }
"else"  { return T_else; }
"print"  { return T_print; }
"for"  { return T_for; }
 
 
[\=\+\-\*\/\%\(\)] { return yytext[0];}

{L} { return T_id; }
{D}+ { return T_const; }
{W}+ {  } 
\'.*\n { 
    
 }

. { 
    fprintf(stderr, "illegal character\n"); 
    exit(1); 
    }
%%

int main(){
  int token;
  do {
      token = yylex();
      printf("token=%d, lexeme= \" %s \" \n", token, yytext);
  } while (token != T_eof);
}