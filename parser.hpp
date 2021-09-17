/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_and = 258,
    T_dim = 259,
    T_false = 260,
    T_let = 261,
    T_of = 262,
    T_type = 263,
    T_array = 264,
    T_do = 265,
    T_float = 266,
    T_match = 267,
    T_rec = 268,
    T_unit = 269,
    T_begin = 270,
    T_done = 271,
    T_for = 272,
    T_mod = 273,
    T_ref = 274,
    T_while = 275,
    T_bool = 276,
    T_downto = 277,
    T_if = 278,
    T_mutable = 279,
    T_then = 280,
    T_with = 281,
    T_char = 282,
    T_else = 283,
    T_in = 284,
    T_new = 285,
    T_to = 286,
    T_delete = 287,
    T_end = 288,
    T_int = 289,
    T_not = 290,
    T_true = 291,
    T_Id = 292,
    T_id = 293,
    T_int_expr = 294,
    T_float_expr = 295,
    T_char_expr = 296,
    T_str_expr = 297,
    T_arrow_op = 298,
    T_plus_op = 299,
    T_minus_op = 300,
    T_mult_op = 301,
    T_div_op = 302,
    T_pow_op = 303,
    T_and_op = 304,
    T_or_op = 305,
    T_struct_diff_op = 306,
    T_leq_op = 307,
    T_geq_op = 308,
    T_eq_op = 309,
    T_diff_op = 310,
    T_assign_op = 311,
    LET_IN = 312,
    IF_THEN_ELSE = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "parser.y"

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
  Pattern* pattern;
  Clause* clause;
  std::vector<Clause *> *clause_vec;

#line 144 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
