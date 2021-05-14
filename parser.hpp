/* A Bison parser, made by GNU Bison 3.7.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_and = 258,                   /* T_and  */
    T_dim = 259,                   /* T_dim  */
    T_false = 260,                 /* T_false  */
    T_let = 261,                   /* T_let  */
    T_of = 262,                    /* T_of  */
    T_type = 263,                  /* T_type  */
    T_array = 264,                 /* T_array  */
    T_do = 265,                    /* T_do  */
    T_float = 266,                 /* T_float  */
    T_match = 267,                 /* T_match  */
    T_rec = 268,                   /* T_rec  */
    T_unit = 269,                  /* T_unit  */
    T_begin = 270,                 /* T_begin  */
    T_done = 271,                  /* T_done  */
    T_for = 272,                   /* T_for  */
    T_mod = 273,                   /* T_mod  */
    T_ref = 274,                   /* T_ref  */
    T_while = 275,                 /* T_while  */
    T_bool = 276,                  /* T_bool  */
    T_downto = 277,                /* T_downto  */
    T_if = 278,                    /* T_if  */
    T_mutable = 279,               /* T_mutable  */
    T_then = 280,                  /* T_then  */
    T_with = 281,                  /* T_with  */
    T_char = 282,                  /* T_char  */
    T_else = 283,                  /* T_else  */
    T_in = 284,                    /* T_in  */
    T_new = 285,                   /* T_new  */
    T_to = 286,                    /* T_to  */
    T_delete = 287,                /* T_delete  */
    T_end = 288,                   /* T_end  */
    T_int = 289,                   /* T_int  */
    T_not = 290,                   /* T_not  */
    T_true = 291,                  /* T_true  */
    T_Id = 292,                    /* T_Id  */
    T_id = 293,                    /* T_id  */
    T_int_expr = 294,              /* T_int_expr  */
    T_float_expr = 295,            /* T_float_expr  */
    T_char_expr = 296,             /* T_char_expr  */
    T_str_expr = 297,              /* T_str_expr  */
    T_arrow_op = 298,              /* T_arrow_op  */
    T_plus_op = 299,               /* T_plus_op  */
    T_minus_op = 300,              /* T_minus_op  */
    T_mult_op = 301,               /* T_mult_op  */
    T_div_op = 302,                /* T_div_op  */
    T_pow_op = 303,                /* T_pow_op  */
    T_and_op = 304,                /* T_and_op  */
    T_or_op = 305,                 /* T_or_op  */
    T_struct_diff_op = 306,        /* T_struct_diff_op  */
    T_leq_op = 307,                /* T_leq_op  */
    T_geq_op = 308,                /* T_geq_op  */
    T_eq_op = 309,                 /* T_eq_op  */
    T_diff_op = 310,               /* T_diff_op  */
    T_assign_op = 311,             /* T_assign_op  */
    LET_IN = 312,                  /* LET_IN  */
    IF_THEN_ELSE = 313,            /* IF_THEN_ELSE  */
    PLUS_UNOP = 314,               /* PLUS_UNOP  */
    MINUS_UNOP = 315,              /* MINUS_UNOP  */
    PLUS_DOT_UNOP = 316,           /* PLUS_DOT_UNOP  */
    MINUS_DOT_UNOP = 317           /* MINUS_DOT_UNOP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
