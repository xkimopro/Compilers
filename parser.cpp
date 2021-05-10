/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <cstdio>
#include "lexer.hpp"

#line 76 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_and = 3,                      /* T_and  */
  YYSYMBOL_T_dim = 4,                      /* T_dim  */
  YYSYMBOL_T_false = 5,                    /* T_false  */
  YYSYMBOL_T_let = 6,                      /* T_let  */
  YYSYMBOL_T_of = 7,                       /* T_of  */
  YYSYMBOL_T_type = 8,                     /* T_type  */
  YYSYMBOL_T_array = 9,                    /* T_array  */
  YYSYMBOL_T_do = 10,                      /* T_do  */
  YYSYMBOL_T_float = 11,                   /* T_float  */
  YYSYMBOL_T_match = 12,                   /* T_match  */
  YYSYMBOL_T_rec = 13,                     /* T_rec  */
  YYSYMBOL_T_unit = 14,                    /* T_unit  */
  YYSYMBOL_T_begin = 15,                   /* T_begin  */
  YYSYMBOL_T_done = 16,                    /* T_done  */
  YYSYMBOL_T_for = 17,                     /* T_for  */
  YYSYMBOL_T_mod = 18,                     /* T_mod  */
  YYSYMBOL_T_ref = 19,                     /* T_ref  */
  YYSYMBOL_T_while = 20,                   /* T_while  */
  YYSYMBOL_T_bool = 21,                    /* T_bool  */
  YYSYMBOL_T_downto = 22,                  /* T_downto  */
  YYSYMBOL_T_if = 23,                      /* T_if  */
  YYSYMBOL_T_mutable = 24,                 /* T_mutable  */
  YYSYMBOL_T_then = 25,                    /* T_then  */
  YYSYMBOL_T_with = 26,                    /* T_with  */
  YYSYMBOL_T_char = 27,                    /* T_char  */
  YYSYMBOL_T_else = 28,                    /* T_else  */
  YYSYMBOL_T_in = 29,                      /* T_in  */
  YYSYMBOL_T_new = 30,                     /* T_new  */
  YYSYMBOL_T_to = 31,                      /* T_to  */
  YYSYMBOL_T_delete = 32,                  /* T_delete  */
  YYSYMBOL_T_end = 33,                     /* T_end  */
  YYSYMBOL_T_int = 34,                     /* T_int  */
  YYSYMBOL_T_not = 35,                     /* T_not  */
  YYSYMBOL_T_true = 36,                    /* T_true  */
  YYSYMBOL_T_Id = 37,                      /* T_Id  */
  YYSYMBOL_T_id = 38,                      /* T_id  */
  YYSYMBOL_T_int_expr = 39,                /* T_int_expr  */
  YYSYMBOL_T_float_expr = 40,              /* T_float_expr  */
  YYSYMBOL_T_char_expr = 41,               /* T_char_expr  */
  YYSYMBOL_T_str_expr = 42,                /* T_str_expr  */
  YYSYMBOL_T_arrow_op = 43,                /* T_arrow_op  */
  YYSYMBOL_T_plus_op = 44,                 /* T_plus_op  */
  YYSYMBOL_T_minus_op = 45,                /* T_minus_op  */
  YYSYMBOL_T_mult_op = 46,                 /* T_mult_op  */
  YYSYMBOL_T_div_op = 47,                  /* T_div_op  */
  YYSYMBOL_T_pow_op = 48,                  /* T_pow_op  */
  YYSYMBOL_T_and_op = 49,                  /* T_and_op  */
  YYSYMBOL_T_or_op = 50,                   /* T_or_op  */
  YYSYMBOL_T_struct_diff_op = 51,          /* T_struct_diff_op  */
  YYSYMBOL_T_leq_op = 52,                  /* T_leq_op  */
  YYSYMBOL_T_geq_op = 53,                  /* T_geq_op  */
  YYSYMBOL_T_eq_op = 54,                   /* T_eq_op  */
  YYSYMBOL_T_diff_op = 55,                 /* T_diff_op  */
  YYSYMBOL_T_assign_op = 56,               /* T_assign_op  */
  YYSYMBOL_LET_IN = 57,                    /* LET_IN  */
  YYSYMBOL_LET_DEF = 58,                   /* LET_DEF  */
  YYSYMBOL_59_ = 59,                       /* ';'  */
  YYSYMBOL_IF_THEN_ELSE = 60,              /* IF_THEN_ELSE  */
  YYSYMBOL_61_ = 61,                       /* '='  */
  YYSYMBOL_62_ = 62,                       /* '>'  */
  YYSYMBOL_63_ = 63,                       /* '<'  */
  YYSYMBOL_64_ = 64,                       /* '+'  */
  YYSYMBOL_65_ = 65,                       /* '-'  */
  YYSYMBOL_66_ = 66,                       /* '*'  */
  YYSYMBOL_67_ = 67,                       /* '/'  */
  YYSYMBOL_T_pow = 68,                     /* T_pow  */
  YYSYMBOL_PLUS_UNOP = 69,                 /* PLUS_UNOP  */
  YYSYMBOL_MINUS_UNOP = 70,                /* MINUS_UNOP  */
  YYSYMBOL_PLUS_DOT_UNOP = 71,             /* PLUS_DOT_UNOP  */
  YYSYMBOL_MINUS_DOT_UNOP = 72,            /* MINUS_DOT_UNOP  */
  YYSYMBOL_FUN_CALL = 73,                  /* FUN_CALL  */
  YYSYMBOL_74_ = 74,                       /* '!'  */
  YYSYMBOL_ARRAY_ELEM = 75,                /* ARRAY_ELEM  */
  YYSYMBOL_76_ = 76,                       /* ':'  */
  YYSYMBOL_77_ = 77,                       /* '['  */
  YYSYMBOL_78_ = 78,                       /* ']'  */
  YYSYMBOL_79_ = 79,                       /* ','  */
  YYSYMBOL_80_ = 80,                       /* '|'  */
  YYSYMBOL_81_ = 81,                       /* '('  */
  YYSYMBOL_82_ = 82,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 83,                  /* $accept  */
  YYSYMBOL_program = 84,                   /* program  */
  YYSYMBOL_stmt_list = 85,                 /* stmt_list  */
  YYSYMBOL_stmt = 86,                      /* stmt  */
  YYSYMBOL_letdef = 87,                    /* letdef  */
  YYSYMBOL_and_def_list = 88,              /* and_def_list  */
  YYSYMBOL_def = 89,                       /* def  */
  YYSYMBOL_comma_expr_list = 90,           /* comma_expr_list  */
  YYSYMBOL_typedef = 91,                   /* typedef  */
  YYSYMBOL_and_tdef_list = 92,             /* and_tdef_list  */
  YYSYMBOL_tdef = 93,                      /* tdef  */
  YYSYMBOL_constr_list = 94,               /* constr_list  */
  YYSYMBOL_constr = 95,                    /* constr  */
  YYSYMBOL_constr_type_list = 96,          /* constr_type_list  */
  YYSYMBOL_par = 97,                       /* par  */
  YYSYMBOL_par_list = 98,                  /* par_list  */
  YYSYMBOL_type = 99,                      /* type  */
  YYSYMBOL_comma_star_list = 100,          /* comma_star_list  */
  YYSYMBOL_expr = 101,                     /* expr  */
  YYSYMBOL_or_clause_list = 102,           /* or_clause_list  */
  YYSYMBOL_expr_list = 103,                /* expr_list  */
  YYSYMBOL__expr = 104,                    /* _expr  */
  YYSYMBOL_unop = 105,                     /* unop  */
  YYSYMBOL_binop = 106,                    /* binop  */
  YYSYMBOL_clause = 107,                   /* clause  */
  YYSYMBOL_pattern = 108,                  /* pattern  */
  YYSYMBOL_pattern_list = 109              /* pattern_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   731

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,     2,     2,     2,     2,     2,
      81,    82,    66,    64,    79,    65,     2,    67,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,    59,
      63,    61,    62,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    80,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    60,    68,    69,    70,    71,    72,
      73,    75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    88,    89,    93,    94,    98,    99,   103,
     104,   108,   109,   110,   111,   112,   113,   117,   118,   122,
     126,   127,   130,   133,   134,   137,   138,   142,   143,   147,
     148,   152,   153,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   171,   172,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     193,   194,   198,   199,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   221,
     222,   223,   224,   225,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   254,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   273,
     274
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_and", "T_dim",
  "T_false", "T_let", "T_of", "T_type", "T_array", "T_do", "T_float",
  "T_match", "T_rec", "T_unit", "T_begin", "T_done", "T_for", "T_mod",
  "T_ref", "T_while", "T_bool", "T_downto", "T_if", "T_mutable", "T_then",
  "T_with", "T_char", "T_else", "T_in", "T_new", "T_to", "T_delete",
  "T_end", "T_int", "T_not", "T_true", "T_Id", "T_id", "T_int_expr",
  "T_float_expr", "T_char_expr", "T_str_expr", "T_arrow_op", "T_plus_op",
  "T_minus_op", "T_mult_op", "T_div_op", "T_pow_op", "T_and_op", "T_or_op",
  "T_struct_diff_op", "T_leq_op", "T_geq_op", "T_eq_op", "T_diff_op",
  "T_assign_op", "LET_IN", "LET_DEF", "';'", "IF_THEN_ELSE", "'='", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "T_pow", "PLUS_UNOP", "MINUS_UNOP",
  "PLUS_DOT_UNOP", "MINUS_DOT_UNOP", "FUN_CALL", "'!'", "ARRAY_ELEM",
  "':'", "'['", "']'", "','", "'|'", "'('", "')'", "$accept", "program",
  "stmt_list", "stmt", "letdef", "and_def_list", "def", "comma_expr_list",
  "typedef", "and_tdef_list", "tdef", "constr_list", "constr",
  "constr_type_list", "par", "par_list", "type", "comma_star_list", "expr",
  "or_clause_list", "expr_list", "_expr", "unop", "binop", "clause",
  "pattern", "pattern_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,    59,
     314,    61,    62,    60,    43,    45,    42,    47,   315,   316,
     317,   318,   319,   320,    33,   321,    58,    91,    93,    44,
     124,    40,    41
};
#endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -123,    10,     5,  -123,     8,   -33,  -123,  -123,  -123,   -20,
     -14,  -123,  -123,   -19,  -123,  -123,   -61,    13,    52,    11,
      62,    52,    20,   166,  -123,   166,    20,    37,  -123,   -20,
      88,  -123,   -33,    -6,  -123,  -123,  -123,  -123,  -123,  -123,
      20,    -7,    45,  -123,   166,   166,    58,   166,   166,    20,
     166,  -123,  -123,  -123,    21,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,    40,   103,    71,   600,  -123,   166,   600,
      -5,    29,  -123,    20,    26,  -123,    20,    44,   -13,  -123,
      20,  -123,    78,   502,   526,    56,   228,   576,    -7,    74,
      40,   166,    40,  -123,    21,  -123,  -123,   204,   166,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,     7,   166,   600,   166,    20,    20,    -7,    11,    -7,
    -123,  -123,    -7,  -123,    23,  -123,   166,   166,   166,  -123,
     600,  -123,   600,    48,   166,   600,   600,   -10,    -7,  -123,
      12,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    85,    87,
      89,    90,    23,  -123,    91,   460,   344,   640,    14,    20,
     600,  -123,   123,    65,    23,  -123,  -123,  -123,  -123,    50,
     -31,   166,   166,   166,  -123,   166,  -123,    -7,    20,  -123,
    -123,  -123,  -123,    23,   600,   278,   302,   664,    -7,  -123,
     166,   166,   368,   410,  -123,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     4,     5,     6,     0,
       0,    31,     9,     0,    20,     9,    13,     0,     7,     0,
      19,     8,     0,     0,    29,     0,     0,     0,    32,     0,
      25,    23,     0,     0,    37,    33,    36,    35,    34,    43,
       0,    15,     0,    69,     0,     0,     0,     0,     0,     0,
       0,    83,    68,    62,    62,    64,    65,    66,    67,    81,
      82,    79,    80,     0,     0,     0,    17,    46,     0,    11,
       0,     0,    10,     0,    22,    21,     0,     0,     0,    40,
       0,    73,     0,     0,     0,     0,     0,     0,    75,    51,
      50,     0,    49,    77,    76,    78,    70,     0,     0,    92,
      88,    89,    90,    91,    93,   102,   103,    95,    98,    99,
     100,   101,   105,   104,    94,    97,    96,    84,    85,    86,
      87,     0,     0,    47,     0,     0,    26,    27,     0,    41,
      44,    38,    39,    74,     0,    53,     0,     0,     0,    63,
      17,    71,    52,    14,     0,    48,    12,     0,    28,    24,
       0,   115,   114,   119,   116,   107,   110,   113,     0,     0,
       0,     0,     0,    60,     0,     0,     0,    54,     0,     0,
      18,    30,     0,     0,   118,   111,   112,   108,   109,     0,
       0,     0,     0,     0,    56,     0,    72,    16,     0,    45,
     120,   117,    59,     0,   106,     0,     0,    55,    42,    61,
       0,     0,     0,     0,    58,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,  -123,   134,   122,    -2,     9,  -123,  -123,
     118,  -123,    24,  -123,  -123,  -123,   -23,  -123,   -25,  -123,
      97,   -55,  -123,  -123,   -40,  -122,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,    65,    18,    12,   121,     8,    20,
      14,    74,    31,   126,    28,    17,    41,   150,    66,   180,
      90,    67,    68,   122,   163,   164,   174
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    76,   192,    70,    10,    13,    79,    15,    95,    79,
       3,     4,    79,     5,    79,    22,    23,    78,    11,    83,
      84,     9,    86,    87,    16,    89,    88,    72,   151,    33,
      80,    34,    10,    80,    35,   139,    80,   139,    80,    97,
     179,    36,    19,   123,    42,    43,    11,    37,    30,   193,
     127,    24,   190,   129,    38,    29,   124,   132,    39,   152,
     153,   154,   155,   156,   157,    32,   140,   158,   159,   131,
      49,    77,   171,   142,    25,    71,    52,    93,    94,    55,
      56,    57,    58,    81,    82,   143,   144,   160,   161,    26,
     172,   173,   186,   144,    27,    73,    85,   145,    91,   146,
      98,    40,   147,   148,   162,   125,   128,    42,    43,     4,
     130,   165,   166,   167,    63,    44,   133,   136,    45,   170,
      46,    64,   104,    47,   169,   175,    48,   176,   177,   178,
     188,   189,   191,    49,   181,    50,     7,    21,    51,    52,
      53,    54,    55,    56,    57,    58,   187,    59,    60,   168,
      75,    92,   149,   199,     0,     0,   194,   195,   196,     0,
     197,     0,     0,     0,     0,   198,     0,    61,    62,     0,
      42,    43,     4,     0,     0,   202,   203,    63,    44,     0,
       0,    45,     0,    46,    64,    96,    47,     0,     0,    48,
       0,     0,     0,     0,     0,     0,    49,     0,    50,     0,
       0,    51,    52,    53,    54,    55,    56,    57,    58,     0,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
      61,    62,     0,     0,     0,     0,     0,     0,   137,     0,
      63,     0,     0,     0,     0,     0,    99,    64,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,     0,   113,     0,   114,   115,   116,   117,   118,
     119,   120,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   141,   113,   200,   114,
     115,   116,   117,   118,   119,   120,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,     0,     0,     0,     0,     0,     0,     0,
      99,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,   113,     0,   114,
     115,   116,   117,   118,   119,   120,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     184,   113,    99,   114,   115,   116,   117,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   204,     0,    99,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,     0,   113,     0,   114,   115,   116,   117,   118,
     119,   120,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   205,   113,    99,   114,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,   113,
       0,   114,   115,   116,   117,   118,   119,   120,    99,     0,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,   113,
      99,   114,   115,   116,   117,   118,   119,   120,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   135,
       0,   113,     0,   114,   115,   116,   117,   118,   119,   120,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,     0,   113,     0,   114,   115,   116,
     117,   118,   119,   120,    99,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,     0,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,    99,   113,
       0,   114,   115,   116,   117,   118,   119,   120,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120
};

static const yytype_int16 yycheck[] =
{
      25,     7,    33,    26,    24,    38,    19,     9,    63,    19,
       0,     6,    19,     8,    19,    76,    77,    40,    38,    44,
      45,    13,    47,    48,    38,    50,    49,    29,     5,     9,
      43,    11,    24,    43,    14,    90,    43,    92,    43,    64,
     162,    21,    61,    68,     4,     5,    38,    27,    37,    80,
      73,    38,   174,    76,    34,     3,    61,    80,    38,    36,
      37,    38,    39,    40,    41,     3,    91,    44,    45,    82,
      30,    77,    82,    98,    61,    38,    36,    37,    38,    39,
      40,    41,    42,    38,    39,    78,    79,    64,    65,    76,
      78,    79,    78,    79,    81,     7,    38,   122,    77,   124,
      29,    81,   125,   126,    81,    76,    80,     4,     5,     6,
      66,   136,   137,   138,    74,    12,    38,    61,    15,   144,
      17,    81,    48,    20,    76,    40,    23,    40,    39,    39,
       7,    66,    82,    30,    43,    32,     2,    15,    35,    36,
      37,    38,    39,    40,    41,    42,   169,    44,    45,   140,
      32,    54,   128,   193,    -1,    -1,   181,   182,   183,    -1,
     185,    -1,    -1,    -1,    -1,   188,    -1,    64,    65,    -1,
       4,     5,     6,    -1,    -1,   200,   201,    74,    12,    -1,
      -1,    15,    -1,    17,    81,    82,    20,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    18,    81,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    82,    59,    10,    61,
      62,    63,    64,    65,    66,    67,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      16,    59,    18,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    18,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    16,    59,    18,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    59,
      18,    61,    62,    63,    64,    65,    66,    67,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    33,
      -1,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    18,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,    67,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    84,    85,     0,     6,     8,    86,    87,    91,    13,
      24,    38,    89,    38,    93,    89,    38,    98,    88,    61,
      92,    88,    76,    77,    38,    61,    76,    81,    97,     3,
      37,    95,     3,     9,    11,    14,    21,    27,    34,    38,
      81,    99,     4,     5,    12,    15,    17,    20,    23,    30,
      32,    35,    36,    37,    38,    39,    40,    41,    42,    44,
      45,    64,    65,    74,    81,    87,   101,   104,   105,   101,
      99,    38,    89,     7,    94,    93,     7,    77,    99,    19,
      43,    38,    39,   101,   101,    38,   101,   101,    99,   101,
     103,    77,   103,    37,    38,   104,    82,   101,    29,    18,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    59,    61,    62,    63,    64,    65,    66,
      67,    90,   106,   101,    61,    76,    96,    99,    80,    99,
      66,    82,    99,    38,    26,    33,    61,    10,    25,   104,
     101,    82,   101,    78,    79,   101,   101,    99,    99,    95,
     100,     5,    36,    37,    38,    39,    40,    41,    44,    45,
      64,    65,    81,   107,   108,   101,   101,   101,    90,    76,
     101,    82,    78,    79,   109,    40,    40,    39,    39,   108,
     102,    43,    22,    31,    16,    28,    78,    99,     7,    66,
     108,    82,    33,    80,   101,   101,   101,   101,    99,   107,
      10,    10,   101,   101,    16,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    83,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      92,    92,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   105,
     105,   105,   105,   105,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     3,     4,     0,
       3,     4,     6,     2,     6,     4,     8,     0,     3,     3,
       0,     3,     4,     0,     3,     1,     3,     1,     2,     1,
       5,     0,     2,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     7,     1,     0,     3,     1,     2,     3,     2,
       2,     2,     3,     3,     4,     6,     5,     9,     9,     6,
       0,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     3,     5,     2,     3,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     3,     2,     0,
       2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* stmt: letdef  */
#line 93 "parser.y"
         {printf("letdef");}
#line 1430 "parser.cpp"
    break;

  case 49: /* expr: T_id expr_list  */
#line 179 "parser.y"
                                {printf("func");}
#line 1436 "parser.cpp"
    break;

  case 62: /* expr_list: %empty  */
#line 198 "parser.y"
         {printf("expr");}
#line 1442 "parser.cpp"
    break;

  case 63: /* expr_list: expr_list _expr  */
#line 199 "parser.y"
                  {printf("expr");}
#line 1448 "parser.cpp"
    break;


#line 1452 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 277 "parser.y"


void yyerror(const char *msg) {
   fprintf (stderr, "Error: %s\n", msg);
   exit(1);
}

int main() {
  int result = yyparse();
  if (result == 0) printf("Success.\n");
  return result;
}
