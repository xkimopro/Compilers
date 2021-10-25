/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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
#include "ast.hpp"
#include "lexer.hpp"

SymbolTable st;
//ConstrTable ct;
TypeDefTable tt;

#line 80 "parser.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 82 "parser.y"


  Program *program;
  std::vector<Stmt *> *stmt_vec;
  Stmt *stmt;
  std::vector<Def *> *def_vec;
  LetDef *letdef;
  Def *def;
  std::vector<Par *> *par_vec;
  std::vector<Expr *> *expr_vec;
  TypeDef *type_def;
  std::vector<TDef *> *tdef_vec;
  TDef *tdef;
  std::vector<Constr *> *constr_vec;
  Constr *constr;
  std::vector<::Type *> *type_vec;
  Par *par;
  ::Type *type;
  int stars;
  Expr *expr;
  int int_expr;
  float float_expr;
  char char_expr;
  char* str_expr;
  char* var;
  Pattern* pattern;
  Clause* clause;
  std::vector<Clause *> *clause_vec;
  std::vector<Pattern *> *pattern_vec;

#line 222 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   589

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

#define YYUNDEFTOK  2
#define YYMAXUTOK   313


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,     2,     2,     2,     2,     2,
      73,    74,    65,    63,    71,    64,     2,    66,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    58,
      62,    60,    61,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    72,     2,     2,     2,     2,     2,
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
      55,    56,    57,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   143,   143,   151,   152,   156,   157,   161,   162,   166,
     167,   171,   172,   173,   174,   175,   176,   180,   181,   185,
     186,   190,   194,   195,   199,   202,   203,   207,   208,   212,
     213,   217,   218,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   236,   237,   241,   242,   243,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   270,
     271,   272,   276,   277,   278,   279,   280,   281,   282,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   311,   312,   313,   317,   318,   322,   323,   327,   331,
     332,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   351,   352
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_and", "T_dim", "T_false", "T_let",
  "T_of", "T_type", "T_array", "T_do", "T_float", "T_match", "T_rec",
  "T_unit", "T_begin", "T_done", "T_for", "T_mod", "T_ref", "T_while",
  "T_bool", "T_downto", "T_if", "T_mutable", "T_then", "T_with", "T_char",
  "T_else", "T_in", "T_new", "T_to", "T_delete", "T_end", "T_int", "T_not",
  "T_true", "T_Id", "T_id", "T_int_expr", "T_float_expr", "T_char_expr",
  "T_str_expr", "T_arrow_op", "T_plus_op", "T_minus_op", "T_mult_op",
  "T_div_op", "T_pow_op", "T_and_op", "T_or_op", "T_struct_diff_op",
  "T_leq_op", "T_geq_op", "T_eq_op", "T_diff_op", "T_assign_op", "LET_IN",
  "';'", "IF_THEN_ELSE", "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'!'", "':'", "'['", "']'", "','", "'|'", "'('", "')'", "$accept",
  "program", "stmt_list", "stmt", "letdef", "and_def_list", "def",
  "par_list", "comma_expr_list", "typedef", "and_tdef_list", "tdef",
  "constr_list", "constr", "constr_type_list", "par", "type",
  "comma_star_list", "expr", "expr1", "expr2", "expr3", "expr4", "expr5",
  "or_clause_list", "expr_list", "clause", "pattern", "pattern1",
  "pattern_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    59,   313,
      61,    62,    60,    43,    45,    42,    47,    33,    58,    91,
      93,    44,   124,    40,    41
};
# endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -67,     3,    30,   -67,    -6,   -28,   -67,   -67,   -67,    62,
     -22,   -67,    88,   -67,    36,    98,   -67,    88,    10,   128,
      62,    90,   -28,    81,   120,   -67,   120,    81,    76,   -67,
     -67,   132,    79,   -67,   -67,    -3,   -67,   -67,   -67,   -67,
     -67,   -67,    81,    80,    78,   -67,   120,   120,   111,   120,
     193,    81,   317,   317,   -67,   356,   277,   -67,   -67,   -67,
     -67,   317,   317,   317,   317,   356,     7,   124,    63,   105,
     -67,   -67,   -67,   386,   -67,   105,    86,    99,    81,    90,
      81,   103,   -18,   -67,    81,   -67,   131,    46,    40,   110,
      -4,   146,    80,   -67,   -67,   -67,   109,   -67,   356,   120,
     356,   -67,   -67,   -67,   -67,   -67,   -67,   -43,   120,   114,
     120,   120,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   120,    81,    81,    80,   -67,   166,   -67,
      74,   -67,    80,   -67,    24,   -67,   120,   120,   120,   -67,
      77,   -67,   105,    81,   105,   -67,   138,    65,    65,   138,
     138,   138,   471,   448,   502,   502,   502,   502,   502,   409,
     502,   502,   502,    65,    65,   138,   138,   105,    15,    80,
     182,   130,   -67,   -67,   136,   -67,   -67,   -67,   -67,   162,
     167,   172,   173,    24,    34,   -67,   163,   -67,   -17,    -8,
     186,   -67,    80,   -67,    81,   -67,   -67,   -67,   136,   -67,
     -67,   -67,   -67,   141,   -67,    24,   120,   120,   120,   -67,
     120,   166,   -67,   -67,   -67,   105,    -1,    18,   -67,   120,
     120,    17,    19,   -67,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     4,     5,     6,     0,
       0,    17,     7,     9,     0,    21,    22,     8,    13,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,    18,
      10,    27,    24,    25,    23,     0,    37,    33,    36,    35,
      34,    43,     0,    15,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    63,    62,    49,    50,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      69,    72,    79,   101,    46,    11,     0,     0,     0,     0,
       0,     0,     0,    40,     0,    59,     0,     0,     0,     0,
       0,     0,    61,    78,    77,    63,    62,   106,    71,     0,
      70,    75,    76,    73,    74,    64,    55,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    26,    41,    44,
       0,    38,    39,    60,     0,    57,     0,     0,     0,   107,
       0,    56,    47,     0,    20,    48,    88,    84,    85,    86,
      87,    89,    98,    99,    91,    94,    95,    96,    97,   100,
      90,    93,    92,    80,    81,    82,    83,    12,     0,    30,
       0,     0,   119,   118,   122,   120,   111,   114,   117,     0,
       0,     0,     0,     0,     0,   104,     0,   109,     0,     0,
     102,    58,    16,    32,     0,    45,   122,   123,   110,   115,
     116,   112,   113,     0,    68,     0,     0,     0,     0,    65,
       0,    42,   124,   121,   105,   108,     0,     0,   103,     0,
       0,     0,     0,    67,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   -67,   215,   209,   199,   -67,   121,   -67,
     -67,   200,   -67,   142,   -67,   -67,   -25,   -67,   -26,    38,
     248,   -67,   457,   174,   -67,   170,    12,    43,   -66,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,    67,    12,    13,    19,    68,     8,
      15,    16,    32,    33,   135,    29,    43,   140,    69,    70,
      71,    72,    73,    74,   194,    98,   195,   196,   197,   208
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    83,    76,     3,    80,   217,   147,     9,   219,   229,
      14,    44,    45,     4,   218,   111,    18,    82,    10,    46,
      87,    88,    47,    90,    48,    84,    92,    49,   230,   182,
      50,   151,    11,   233,    83,   234,     4,    51,     5,    52,
     107,   111,    53,    54,    55,    56,    57,    58,    59,    60,
     111,    61,    62,   136,   111,   138,   141,   111,    84,   142,
     183,   184,   185,   186,   187,   188,    81,   214,   189,   190,
      63,    64,   144,   145,    65,   111,   111,   111,    23,    24,
      66,   106,   152,   112,   154,   155,    10,   191,   192,   203,
      35,    20,    36,    97,    97,    37,    21,   193,   111,    83,
      11,    22,    38,   105,   111,    83,   215,   177,    39,   178,
     179,   115,   116,   117,    77,    40,    85,    86,   207,    41,
     198,   199,   200,    84,    44,    45,     4,    31,   202,    84,
     131,   132,    46,   109,   110,    47,   149,    48,   149,    78,
      49,   182,   222,    50,   180,   181,   133,   201,   110,    89,
      51,    79,    52,   108,    42,    53,    54,    55,    56,    57,
      58,    59,    60,   111,    61,    62,    25,   134,   139,   143,
     146,   148,   183,   206,   185,   186,   187,   188,    99,   221,
     189,   190,   153,    63,    64,    83,   117,    65,    26,   204,
     225,   226,   227,    66,   228,   205,    27,    44,    45,   191,
     192,    28,   209,   231,   232,    46,   216,   210,    47,   193,
      48,   211,   212,    49,   220,   223,    50,     7,    17,    30,
     150,   137,    34,    51,    91,    52,   100,   224,    53,    54,
      55,    56,    57,    58,    59,    60,   213,    61,    62,    44,
      45,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,    48,     0,     0,    49,    63,    64,     0,     0,
      65,     0,     0,     0,     0,    51,    66,    52,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,     0,    61,
      62,    44,    45,     0,     0,     0,     0,     0,     0,    46,
       0,     0,    47,     0,    48,     0,     0,    49,    63,    64,
      93,    94,    65,     0,     0,     0,     0,    51,    66,   101,
     102,   103,   104,    54,    95,    96,    57,    58,    59,    60,
       0,    44,    45,     0,     0,     0,     0,     0,     0,    46,
       0,     0,    47,     0,    48,     0,     0,    49,     0,     0,
       0,     0,     0,     0,    65,     0,    99,    51,     0,     0,
      66,     0,     0,    54,    55,    56,    57,    58,    59,    60,
      44,    45,     0,     0,     0,     0,     0,     0,    46,     0,
       0,    47,     0,    48,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,    65,     0,    51,     0,     0,     0,
      66,     0,    54,    95,    96,    57,    58,    59,    60,     0,
       0,     0,     0,     0,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,     0,     0,   112,     0,    66,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,   126,   127,   128,   129,
     130,   131,   132,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,   112,     0,     0,   126,
     127,   128,   129,   130,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,   113,   114,   115,   116,   117,   118,     0,   120,
     121,   122,   123,   124,     0,     0,     0,     0,   126,   127,
     128,   129,   130,   131,   132,   113,   114,   115,   116,   117,
     112,     0,   120,   121,   122,   123,   124,     0,     0,     0,
       0,   126,   127,   128,   129,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,   113,   114,   115,   116,
     117,     0,     0,    -1,    -1,    -1,    -1,    -1,     0,     0,
       0,     0,    -1,    -1,    -1,   129,   130,   131,   132,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176
};

static const yytype_int16 yycheck[] =
{
      26,    19,    27,     0,     7,    22,    10,    13,    16,    10,
      38,     4,     5,     6,    31,    58,    38,    42,    24,    12,
      46,    47,    15,    49,    17,    43,    51,    20,    10,     5,
      23,    74,    38,    16,    19,    16,     6,    30,     8,    32,
      66,    58,    35,    36,    37,    38,    39,    40,    41,    42,
      58,    44,    45,    78,    58,    80,    74,    58,    43,    84,
      36,    37,    38,    39,    40,    41,    69,    33,    44,    45,
      63,    64,    26,    33,    67,    58,    58,    58,    68,    69,
      73,    74,   108,    18,   110,   111,    24,    63,    64,    74,
       9,     3,    11,    55,    56,    14,    60,    73,    58,    19,
      38,     3,    21,    65,    58,    19,    72,   133,    27,   134,
     135,    46,    47,    48,    38,    34,    38,    39,   184,    38,
     146,   147,   148,    43,     4,     5,     6,    37,   153,    43,
      65,    66,    12,    70,    71,    15,    98,    17,   100,     7,
      20,     5,   208,    23,    70,    71,    60,    70,    71,    38,
      30,    72,    32,    29,    73,    35,    36,    37,    38,    39,
      40,    41,    42,    58,    44,    45,    38,    68,    65,    38,
      60,    25,    36,    37,    38,    39,    40,    41,    69,   204,
      44,    45,    68,    63,    64,    19,    48,    67,    60,     7,
     216,   217,   218,    73,   220,    65,    68,     4,     5,    63,
      64,    73,    40,   229,   230,    12,    43,    40,    15,    73,
      17,    39,    39,    20,    28,    74,    23,     2,     9,    20,
      99,    79,    22,    30,    50,    32,    56,   215,    35,    36,
      37,    38,    39,    40,    41,    42,   193,    44,    45,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      15,    -1,    17,    -1,    -1,    20,    63,    64,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    30,    73,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    15,    -1,    17,    -1,    -1,    20,    63,    64,
      52,    53,    67,    -1,    -1,    -1,    -1,    30,    73,    61,
      62,    63,    64,    36,    37,    38,    39,    40,    41,    42,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    30,    -1,    -1,
      73,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    30,    -1,    -1,    -1,
      73,    -1,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    18,    -1,    73,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    18,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    44,    45,    46,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    44,    45,    46,    47,    48,
      18,    -1,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    -1,    -1,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    76,    77,     0,     6,     8,    78,    79,    84,    13,
      24,    38,    80,    81,    38,    85,    86,    80,    38,    82,
       3,    60,     3,    68,    69,    38,    60,    68,    73,    90,
      81,    37,    87,    88,    86,     9,    11,    14,    21,    27,
      34,    38,    73,    91,     4,     5,    12,    15,    17,    20,
      23,    30,    32,    35,    36,    37,    38,    39,    40,    41,
      42,    44,    45,    63,    64,    67,    73,    79,    83,    93,
      94,    95,    96,    97,    98,    93,    91,    38,     7,    72,
       7,    69,    91,    19,    43,    38,    39,    93,    93,    38,
      93,    98,    91,    95,    95,    37,    38,    94,   100,    69,
     100,    95,    95,    95,    95,    94,    74,    93,    29,    70,
      71,    58,    18,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    60,    61,    62,    63,
      64,    65,    66,    60,    68,    89,    91,    88,    91,    65,
      92,    74,    91,    38,    26,    33,    60,    10,    25,    94,
      83,    74,    93,    68,    93,    93,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    93,    91,    91,
      70,    71,     5,    36,    37,    38,    39,    40,    41,    44,
      45,    63,    64,    73,    99,   101,   102,   103,    93,    93,
      93,    70,    91,    74,     7,    65,    37,   103,   104,    40,
      40,    39,    39,   102,    33,    72,    43,    22,    31,    16,
      28,    91,   103,    74,   101,    93,    93,    93,    93,    10,
      10,    93,    93,    16,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    81,    81,    81,    81,    82,    82,    83,
      83,    84,    85,    85,    86,    87,    87,    88,    88,    89,
      89,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    92,    92,    93,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    99,    99,   100,   100,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     2,     3,     1,
       3,     4,     6,     2,     5,     4,     7,     0,     2,     1,
       3,     2,     1,     3,     3,     1,     3,     1,     3,     1,
       2,     1,     5,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     6,     1,     1,     3,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     4,     2,
       3,     2,     1,     1,     2,     5,     9,     9,     5,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     4,     6,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     2,     1,     2,     2,     1,     1,     1,
       1,     3,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 143 "parser.y"
            { 
    (yyval.program) = new Program((yyvsp[0].stmt_vec)); 
    (yyval.program)->sem();
    //$$->llvm_compile_and_dump(false);
   }
#line 1641 "parser.cpp"
    break;

  case 3:
#line 151 "parser.y"
          { (yyval.stmt_vec) = new std::vector<Stmt *>; }
#line 1647 "parser.cpp"
    break;

  case 4:
#line 152 "parser.y"
                  { (yyvsp[-1].stmt_vec)->push_back((yyvsp[0].stmt)); (yyval.stmt_vec) = (yyvsp[-1].stmt_vec); }
#line 1653 "parser.cpp"
    break;

  case 5:
#line 156 "parser.y"
         { (yyval.stmt) = (yyvsp[0].letdef); }
#line 1659 "parser.cpp"
    break;

  case 6:
#line 157 "parser.y"
          { (yyval.stmt) = (yyvsp[0].type_def); }
#line 1665 "parser.cpp"
    break;

  case 7:
#line 161 "parser.y"
                      { (yyval.letdef) = new LetDef(false, (yyvsp[0].def_vec)); }
#line 1671 "parser.cpp"
    break;

  case 8:
#line 162 "parser.y"
                            { (yyval.letdef) = new LetDef(true, (yyvsp[0].def_vec)); }
#line 1677 "parser.cpp"
    break;

  case 9:
#line 166 "parser.y"
      { (yyval.def_vec) = new std::vector<Def *>; (yyval.def_vec)->push_back((yyvsp[0].def)); }
#line 1683 "parser.cpp"
    break;

  case 10:
#line 167 "parser.y"
                         { (yyvsp[-2].def_vec)->push_back((yyvsp[0].def)); (yyval.def_vec) = (yyvsp[-2].def_vec); }
#line 1689 "parser.cpp"
    break;

  case 11:
#line 171 "parser.y"
                          { (yyval.def) = new NormalDef((yyvsp[-3].var), (yyvsp[-2].par_vec), new Type_Undefined(), (yyvsp[0].expr)); }
#line 1695 "parser.cpp"
    break;

  case 12:
#line 172 "parser.y"
                                   { (yyval.def) = new NormalDef((yyvsp[-5].var), (yyvsp[-4].par_vec), (yyvsp[-2].type), (yyvsp[0].expr)); }
#line 1701 "parser.cpp"
    break;

  case 13:
#line 173 "parser.y"
                  { (yyval.def) = new MutableDef((yyvsp[0].var), nullptr, new Type_Undefined()); }
#line 1707 "parser.cpp"
    break;

  case 14:
#line 174 "parser.y"
                                          { (yyval.def) = new MutableDef((yyvsp[-3].var), (yyvsp[-1].expr_vec), new Type_Undefined()); }
#line 1713 "parser.cpp"
    break;

  case 15:
#line 175 "parser.y"
                           { (yyval.def) = new MutableDef((yyvsp[-2].var), nullptr, (yyvsp[0].type)); }
#line 1719 "parser.cpp"
    break;

  case 16:
#line 176 "parser.y"
                                                   { (yyval.def) = new MutableDef((yyvsp[-5].var), (yyvsp[-3].expr_vec), (yyvsp[0].type)); }
#line 1725 "parser.cpp"
    break;

  case 17:
#line 180 "parser.y"
          { (yyval.par_vec) = new std::vector<Par *>; }
#line 1731 "parser.cpp"
    break;

  case 18:
#line 181 "parser.y"
               { (yyvsp[-1].par_vec)->push_back((yyvsp[0].par)); (yyval.par_vec) = (yyvsp[-1].par_vec); }
#line 1737 "parser.cpp"
    break;

  case 19:
#line 185 "parser.y"
       { (yyval.expr_vec) = new std::vector<Expr *>; (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 1743 "parser.cpp"
    break;

  case 20:
#line 186 "parser.y"
                           { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 1749 "parser.cpp"
    break;

  case 21:
#line 190 "parser.y"
                       { (yyval.type_def) = new TypeDef((yyvsp[0].tdef_vec)); }
#line 1755 "parser.cpp"
    break;

  case 22:
#line 194 "parser.y"
       { (yyval.tdef_vec) = new std::vector<TDef *>; (yyval.tdef_vec)->push_back((yyvsp[0].tdef)); }
#line 1761 "parser.cpp"
    break;

  case 23:
#line 195 "parser.y"
                           { (yyvsp[-2].tdef_vec)->push_back((yyvsp[0].tdef)); (yyval.tdef_vec) = (yyvsp[-2].tdef_vec); }
#line 1767 "parser.cpp"
    break;

  case 24:
#line 199 "parser.y"
                       { (yyval.tdef) = new TDef((yyvsp[-2].var), (yyvsp[0].constr_vec)); }
#line 1773 "parser.cpp"
    break;

  case 25:
#line 202 "parser.y"
          { (yyval.constr_vec) = new std::vector<Constr *>; (yyval.constr_vec)->push_back((yyvsp[0].constr)); }
#line 1779 "parser.cpp"
    break;

  case 26:
#line 203 "parser.y"
                         { (yyvsp[-2].constr_vec)->push_back((yyvsp[0].constr)); (yyval.constr_vec) = (yyvsp[-2].constr_vec); }
#line 1785 "parser.cpp"
    break;

  case 27:
#line 207 "parser.y"
       { (yyval.constr) = new Constr((yyvsp[0].var), new std::vector<::Type *>); }
#line 1791 "parser.cpp"
    break;

  case 28:
#line 208 "parser.y"
                             { (yyval.constr) = new Constr((yyvsp[-2].var), (yyvsp[0].type_vec)); }
#line 1797 "parser.cpp"
    break;

  case 29:
#line 212 "parser.y"
       { (yyval.type_vec) = new std::vector<::Type *>; (yyval.type_vec)->push_back((yyvsp[0].type)); }
#line 1803 "parser.cpp"
    break;

  case 30:
#line 213 "parser.y"
                        { (yyvsp[-1].type_vec)->push_back((yyvsp[0].type)); (yyval.type_vec) = (yyvsp[-1].type_vec); }
#line 1809 "parser.cpp"
    break;

  case 31:
#line 217 "parser.y"
       { (yyval.par) = new Par((yyvsp[0].var), new Type_Undefined()); }
#line 1815 "parser.cpp"
    break;

  case 32:
#line 218 "parser.y"
                        { (yyval.par) = new Par((yyvsp[-3].var), (yyvsp[-1].type)); }
#line 1821 "parser.cpp"
    break;

  case 33:
#line 222 "parser.y"
         { (yyval.type) = new Type_Unit(); }
#line 1827 "parser.cpp"
    break;

  case 34:
#line 223 "parser.y"
        { (yyval.type) = new Type_Int(); }
#line 1833 "parser.cpp"
    break;

  case 35:
#line 224 "parser.y"
         { (yyval.type) = new Type_Char(); }
#line 1839 "parser.cpp"
    break;

  case 36:
#line 225 "parser.y"
         { (yyval.type) = new Type_Bool(); }
#line 1845 "parser.cpp"
    break;

  case 37:
#line 226 "parser.y"
          { (yyval.type) = new Type_Float(); }
#line 1851 "parser.cpp"
    break;

  case 38:
#line 227 "parser.y"
               { (yyval.type) = (yyvsp[-1].type); }
#line 1857 "parser.cpp"
    break;

  case 39:
#line 228 "parser.y"
                       { (yyval.type) = new Type_Func((yyvsp[-2].type), (yyvsp[0].type)); }
#line 1863 "parser.cpp"
    break;

  case 40:
#line 229 "parser.y"
              { (yyval.type) = new Type_Ref((yyvsp[-1].type)); }
#line 1869 "parser.cpp"
    break;

  case 41:
#line 230 "parser.y"
                     { (yyval.type) = new Type_Array(1, (yyvsp[0].type)); }
#line 1875 "parser.cpp"
    break;

  case 42:
#line 231 "parser.y"
                                             { (yyval.type) = new Type_Array((yyvsp[-3].stars), (yyvsp[0].type)); }
#line 1881 "parser.cpp"
    break;

  case 43:
#line 232 "parser.y"
       { (yyval.type) = new Type_id((yyvsp[0].var)); }
#line 1887 "parser.cpp"
    break;

  case 44:
#line 236 "parser.y"
      { (yyval.stars) = 1; }
#line 1893 "parser.cpp"
    break;

  case 45:
#line 237 "parser.y"
                          { (yyval.stars) = (yyvsp[-2].stars) + 1; }
#line 1899 "parser.cpp"
    break;

  case 46:
#line 241 "parser.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 1905 "parser.cpp"
    break;

  case 47:
#line 242 "parser.y"
                                { (yyval.expr) = new LetIn((yyvsp[-2].letdef), (yyvsp[0].expr)); }
#line 1911 "parser.cpp"
    break;

  case 48:
#line 243 "parser.y"
                { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_semicolon, (yyvsp[0].expr)); }
#line 1917 "parser.cpp"
    break;

  case 49:
#line 247 "parser.y"
             { (yyval.expr) = new Int_Expr((yyvsp[0].int_expr)); }
#line 1923 "parser.cpp"
    break;

  case 50:
#line 248 "parser.y"
               { (yyval.expr) = new Float_Expr((yyvsp[0].float_expr)); }
#line 1929 "parser.cpp"
    break;

  case 51:
#line 249 "parser.y"
              { (yyval.expr) = new Char_Expr((yyvsp[0].char_expr)); }
#line 1935 "parser.cpp"
    break;

  case 52:
#line 250 "parser.y"
             { (yyval.expr) = new Str_Expr((yyvsp[0].str_expr)); }
#line 1941 "parser.cpp"
    break;

  case 53:
#line 251 "parser.y"
         { (yyval.expr) = new Bool_Expr(true); }
#line 1947 "parser.cpp"
    break;

  case 54:
#line 252 "parser.y"
          { (yyval.expr) = new Bool_Expr(false); }
#line 1953 "parser.cpp"
    break;

  case 55:
#line 253 "parser.y"
          { (yyval.expr) = new Unit_Expr(); }
#line 1959 "parser.cpp"
    break;

  case 56:
#line 254 "parser.y"
               { (yyval.expr) = (yyvsp[-1].expr); }
#line 1965 "parser.cpp"
    break;

  case 57:
#line 255 "parser.y"
                     { (yyval.expr) = (yyvsp[-1].expr); }
#line 1971 "parser.cpp"
    break;

  case 58:
#line 256 "parser.y"
                               { (yyval.expr) = new Array((yyvsp[-3].var), (yyvsp[-1].expr_vec)); }
#line 1977 "parser.cpp"
    break;

  case 59:
#line 257 "parser.y"
             { (yyval.expr) = new Dim((yyvsp[0].var)); }
#line 1983 "parser.cpp"
    break;

  case 60:
#line 258 "parser.y"
                        { (yyval.expr) = new Dim((yyvsp[0].var), (yyvsp[-1].int_expr)); }
#line 1989 "parser.cpp"
    break;

  case 61:
#line 259 "parser.y"
            { (yyval.expr) = new New((yyvsp[0].type)); }
#line 1995 "parser.cpp"
    break;

  case 62:
#line 260 "parser.y"
       { (yyval.expr) = new id((yyvsp[0].var)); }
#line 2001 "parser.cpp"
    break;

  case 63:
#line 261 "parser.y"
       { (yyval.expr) = new Id((yyvsp[0].var)); }
#line 2007 "parser.cpp"
    break;

  case 64:
#line 262 "parser.y"
            { (yyval.expr) = new UnOp(unop_exclamation, (yyvsp[0].expr)); }
#line 2013 "parser.cpp"
    break;

  case 65:
#line 263 "parser.y"
                                { (yyval.expr) = new While((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2019 "parser.cpp"
    break;

  case 66:
#line 264 "parser.y"
                                                 { (yyval.expr) = new For((yyvsp[-7].var), (yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr), false); }
#line 2025 "parser.cpp"
    break;

  case 67:
#line 265 "parser.y"
                                                     { (yyval.expr) = new For((yyvsp[-7].var), (yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr), true); }
#line 2031 "parser.cpp"
    break;

  case 68:
#line 266 "parser.y"
                                           { (yyval.expr) = new Match((yyvsp[-3].expr),(yyvsp[-1].clause_vec)); }
#line 2037 "parser.cpp"
    break;

  case 69:
#line 270 "parser.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 2043 "parser.cpp"
    break;

  case 70:
#line 271 "parser.y"
                 { (yyval.expr) = new call((yyvsp[-1].var), (yyvsp[0].expr_vec)); }
#line 2049 "parser.cpp"
    break;

  case 71:
#line 272 "parser.y"
                 { (yyval.expr) = new call((yyvsp[-1].var), (yyvsp[0].expr_vec)); }
#line 2055 "parser.cpp"
    break;

  case 72:
#line 276 "parser.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 2061 "parser.cpp"
    break;

  case 73:
#line 277 "parser.y"
            { (yyval.expr) = new UnOp(unop_plus, (yyvsp[0].expr)); }
#line 2067 "parser.cpp"
    break;

  case 74:
#line 278 "parser.y"
             { (yyval.expr) = new UnOp(unop_minus, (yyvsp[0].expr)); }
#line 2073 "parser.cpp"
    break;

  case 75:
#line 279 "parser.y"
                  { (yyval.expr) = new UnOp(unop_float_plus, (yyvsp[0].expr)); }
#line 2079 "parser.cpp"
    break;

  case 76:
#line 280 "parser.y"
                   { (yyval.expr) = new UnOp(unop_float_minus, (yyvsp[0].expr)); }
#line 2085 "parser.cpp"
    break;

  case 77:
#line 281 "parser.y"
              { (yyval.expr) = new UnOp(unop_not, (yyvsp[0].expr)); }
#line 2091 "parser.cpp"
    break;

  case 78:
#line 282 "parser.y"
                 { (yyval.expr) = new UnOp(unop_delete, (yyvsp[0].expr)); }
#line 2097 "parser.cpp"
    break;

  case 79:
#line 286 "parser.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 2103 "parser.cpp"
    break;

  case 80:
#line 287 "parser.y"
                  { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_plus , (yyvsp[0].expr)); }
#line 2109 "parser.cpp"
    break;

  case 81:
#line 288 "parser.y"
                  { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_minus , (yyvsp[0].expr)); }
#line 2115 "parser.cpp"
    break;

  case 82:
#line 289 "parser.y"
                  { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_mult , (yyvsp[0].expr)); }
#line 2121 "parser.cpp"
    break;

  case 83:
#line 290 "parser.y"
                  { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_div , (yyvsp[0].expr)); }
#line 2127 "parser.cpp"
    break;

  case 84:
#line 291 "parser.y"
                        { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_float_plus , (yyvsp[0].expr)); }
#line 2133 "parser.cpp"
    break;

  case 85:
#line 292 "parser.y"
                         { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_float_minus , (yyvsp[0].expr)); }
#line 2139 "parser.cpp"
    break;

  case 86:
#line 293 "parser.y"
                        { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_float_mult , (yyvsp[0].expr)); }
#line 2145 "parser.cpp"
    break;

  case 87:
#line 294 "parser.y"
                       { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_float_div , (yyvsp[0].expr)); }
#line 2151 "parser.cpp"
    break;

  case 88:
#line 295 "parser.y"
                    { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_mod , (yyvsp[0].expr)); }
#line 2157 "parser.cpp"
    break;

  case 89:
#line 296 "parser.y"
                       { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_pow , (yyvsp[0].expr)); }
#line 2163 "parser.cpp"
    break;

  case 90:
#line 297 "parser.y"
                  { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_single_eq , (yyvsp[0].expr)); }
#line 2169 "parser.cpp"
    break;

  case 91:
#line 298 "parser.y"
                               { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_struct_diff , (yyvsp[0].expr)); }
#line 2175 "parser.cpp"
    break;

  case 92:
#line 299 "parser.y"
                  { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_l , (yyvsp[0].expr)); }
#line 2181 "parser.cpp"
    break;

  case 93:
#line 300 "parser.y"
                  { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_g , (yyvsp[0].expr)); }
#line 2187 "parser.cpp"
    break;

  case 94:
#line 301 "parser.y"
                       { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_leq , (yyvsp[0].expr)); }
#line 2193 "parser.cpp"
    break;

  case 95:
#line 302 "parser.y"
                       { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_geq , (yyvsp[0].expr)); }
#line 2199 "parser.cpp"
    break;

  case 96:
#line 303 "parser.y"
                      { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_double_eq , (yyvsp[0].expr)); }
#line 2205 "parser.cpp"
    break;

  case 97:
#line 304 "parser.y"
                        { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_diff , (yyvsp[0].expr)); }
#line 2211 "parser.cpp"
    break;

  case 98:
#line 305 "parser.y"
                       { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_and , (yyvsp[0].expr)); }
#line 2217 "parser.cpp"
    break;

  case 99:
#line 306 "parser.y"
                      { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_or , (yyvsp[0].expr)); }
#line 2223 "parser.cpp"
    break;

  case 100:
#line 307 "parser.y"
                          { (yyval.expr) = new BinOp((yyvsp[-2].expr), binop_assign , (yyvsp[0].expr)); }
#line 2229 "parser.cpp"
    break;

  case 101:
#line 311 "parser.y"
        { (yyval.expr) = (yyvsp[0].expr); }
#line 2235 "parser.cpp"
    break;

  case 102:
#line 312 "parser.y"
                                            { (yyval.expr) = new If((yyvsp[-2].expr) ,(yyvsp[0].expr), nullptr ); }
#line 2241 "parser.cpp"
    break;

  case 103:
#line 313 "parser.y"
                                                        { (yyval.expr) = new If((yyvsp[-4].expr) ,(yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 2247 "parser.cpp"
    break;

  case 104:
#line 317 "parser.y"
         { (yyval.clause_vec) = new std::vector<Clause *>; (yyval.clause_vec)->push_back((yyvsp[0].clause)); }
#line 2253 "parser.cpp"
    break;

  case 105:
#line 318 "parser.y"
                            { (yyvsp[-2].clause_vec)->push_back((yyvsp[0].clause)); (yyval.clause_vec) = (yyvsp[-2].clause_vec); }
#line 2259 "parser.cpp"
    break;

  case 106:
#line 322 "parser.y"
        { (yyval.expr_vec) = new std::vector<Expr *>; (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 2265 "parser.cpp"
    break;

  case 107:
#line 323 "parser.y"
                  { (yyvsp[-1].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 2271 "parser.cpp"
    break;

  case 108:
#line 327 "parser.y"
                          { (yyval.clause) = new Clause((yyvsp[-2].pattern), (yyvsp[0].expr)); }
#line 2277 "parser.cpp"
    break;

  case 109:
#line 331 "parser.y"
           { (yyval.pattern) = (yyvsp[0].pattern); }
#line 2283 "parser.cpp"
    break;

  case 110:
#line 332 "parser.y"
                    { (yyval.pattern) = new Pattern_Call((yyvsp[-1].var), (yyvsp[0].pattern_vec)); }
#line 2289 "parser.cpp"
    break;

  case 111:
#line 336 "parser.y"
             { (yyval.pattern) = new Pattern_Int_Expr((yyvsp[0].int_expr)); }
#line 2295 "parser.cpp"
    break;

  case 112:
#line 337 "parser.y"
                 { (yyval.pattern) = new Pattern_Int_Expr((yyvsp[0].int_expr)); }
#line 2301 "parser.cpp"
    break;

  case 113:
#line 338 "parser.y"
                 { (yyval.pattern) = new Pattern_Int_Expr(-(yyvsp[0].int_expr)); }
#line 2307 "parser.cpp"
    break;

  case 114:
#line 339 "parser.y"
               { (yyval.pattern) = new Pattern_Float_Expr((yyvsp[0].float_expr)); }
#line 2313 "parser.cpp"
    break;

  case 115:
#line 340 "parser.y"
                         { (yyval.pattern) = new Pattern_Float_Expr((yyvsp[0].float_expr)); }
#line 2319 "parser.cpp"
    break;

  case 116:
#line 341 "parser.y"
                          { (yyval.pattern) = new Pattern_Float_Expr(-(yyvsp[0].float_expr)); }
#line 2325 "parser.cpp"
    break;

  case 117:
#line 342 "parser.y"
              { (yyval.pattern) = new Pattern_Char_Expr((yyvsp[0].char_expr)); }
#line 2331 "parser.cpp"
    break;

  case 118:
#line 343 "parser.y"
         { (yyval.pattern) = new Pattern_Bool_Expr(true); }
#line 2337 "parser.cpp"
    break;

  case 119:
#line 344 "parser.y"
          { (yyval.pattern) = new Pattern_Bool_Expr(false); }
#line 2343 "parser.cpp"
    break;

  case 120:
#line 345 "parser.y"
       { (yyval.pattern) = new Pattern_id((yyvsp[0].var)); }
#line 2349 "parser.cpp"
    break;

  case 121:
#line 346 "parser.y"
                  { (yyval.pattern) = (yyvsp[-1].pattern); }
#line 2355 "parser.cpp"
    break;

  case 122:
#line 347 "parser.y"
       { (yyval.pattern) = new Pattern_Id((yyvsp[0].var)); }
#line 2361 "parser.cpp"
    break;

  case 123:
#line 351 "parser.y"
           { (yyval.pattern_vec) = new std::vector<Pattern *>; (yyval.pattern_vec)->push_back((yyvsp[0].pattern)); }
#line 2367 "parser.cpp"
    break;

  case 124:
#line 352 "parser.y"
                        { (yyvsp[-1].pattern_vec)->push_back((yyvsp[0].pattern)); (yyval.pattern_vec) = (yyvsp[-1].pattern_vec); }
#line 2373 "parser.cpp"
    break;


#line 2377 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 355 "parser.y"


void yyerror(const char *msg) {
   fprintf (stderr, "Error: %s\n", msg);
   exit(1);
}

int main() {
  int result = yyparse();
  return result;
}
