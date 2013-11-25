/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 5 "parser.y"


#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"

#define YYMALLOC yycalloc
static void *yycalloc (size_t size);

/* Line 371 of yacc.c  */
#line 81 "yyparse.cc"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_VOID = 258,
     TOK_BOOL = 259,
     TOK_CHAR = 260,
     TOK_INT = 261,
     TOK_STRING = 262,
     TOK_ROOT = 263,
     TOK_IF = 264,
     TOK_ELSE = 265,
     TOK_WHILE = 266,
     TOK_RETURN = 267,
     TOK_STRUCT = 268,
     TOK_FALSE = 269,
     TOK_TRUE = 270,
     TOK_NULL = 271,
     TOK_NEW = 272,
     TOK_ARRAY = 273,
     TOK_EQ = 274,
     TOK_NE = 275,
     TOK_LT = 276,
     TOK_LE = 277,
     TOK_GT = 278,
     TOK_GE = 279,
     TOK_IDENT = 280,
     TOK_INTCON = 281,
     TOK_CHARCON = 282,
     TOK_STRINGCON = 283,
     TOK_VARIABLE = 284,
     TOK_ORD = 285,
     TOK_CHR = 286,
     TOK_DECLID = 287,
     TOK_PROTOTYPE = 288,
     TOK_TYPE = 289,
     TOK_BASETYPE = 290,
     TOK_BLOCK = 291,
     TOK_BINOP = 292,
     TOK_UNOP = 293,
     TOK_CALL = 294,
     TOK_IFELSE = 295,
     TOK_INITDECL = 296,
     TOK_VARDECL = 297,
     TOK_CONSTANT = 298,
     TOK_POS = 299,
     TOK_NEG = 300,
     TOK_TYPEID = 301,
     TOK_FIELD = 302,
     TOK_RETURNVOID = 303,
     TOK_NEWARRAY = 304,
     TOK_NEWSTRING = 305,
     TOK_INDEX = 306,
     TOK_FUNCTION = 307,
     TOK_PARAMLIST = 308,
     TOK_PAREN = 309
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 201 "yyparse.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   645

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,    59,     2,     2,
      68,    67,    57,    55,    69,    56,    62,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    65,
       2,    54,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,    64,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    18,    22,    23,
      27,    32,    36,    41,    44,    48,    50,    52,    54,    56,
      58,    60,    65,    70,    74,    77,    81,    84,    87,    90,
      92,    95,    98,   100,   102,   104,   106,   108,   111,   117,
     123,   131,   137,   140,   144,   146,   148,   152,   154,   156,
     158,   160,   164,   168,   172,   176,   180,   184,   188,   192,
     196,   200,   204,   208,   211,   214,   217,   220,   223,   228,
     234,   240,   243,   247,   251,   255,   260,   264,   266,   268,
     270,   272,   274,   276
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      72,     0,    -1,    73,    -1,    73,    74,    -1,    73,    78,
      -1,    73,    83,    -1,    73,     1,    64,    -1,    73,     1,
      65,    -1,    -1,    13,    75,    64,    -1,    13,    25,    66,
      64,    -1,    75,    76,    65,    -1,    25,    66,    76,    65,
      -1,    77,    25,    -1,    77,    18,    25,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     7,    -1,    25,    -1,
      80,    79,    67,    81,    -1,    80,    68,    67,    81,    -1,
      79,    69,    80,    -1,    68,    80,    -1,    77,    18,    25,
      -1,    77,    25,    -1,    82,    64,    -1,    66,    64,    -1,
      65,    -1,    82,    83,    -1,    66,    83,    -1,    81,    -1,
      84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,    65,
      -1,    77,    25,    54,    88,    65,    -1,    11,    68,    88,
      67,    83,    -1,     9,    68,    88,    67,    83,    10,    83,
      -1,     9,    68,    88,    67,    83,    -1,    12,    65,    -1,
      12,    88,    65,    -1,    89,    -1,    90,    -1,    68,    88,
      67,    -1,    91,    -1,    92,    -1,    94,    -1,    95,    -1,
      88,    54,    88,    -1,    88,    55,    88,    -1,    88,    56,
      88,    -1,    88,    57,    88,    -1,    88,    58,    88,    -1,
      88,    59,    88,    -1,    88,    24,    88,    -1,    88,    23,
      88,    -1,    88,    22,    88,    -1,    88,    21,    88,    -1,
      88,    20,    88,    -1,    88,    19,    88,    -1,    55,    88,
      -1,    56,    88,    -1,    30,    88,    -1,    31,    88,    -1,
      60,    88,    -1,    17,    25,    68,    67,    -1,    17,     7,
      68,    88,    67,    -1,    17,    77,    61,    88,    70,    -1,
      93,    67,    -1,    25,    68,    67,    -1,    93,    69,    88,
      -1,    25,    68,    88,    -1,    88,    61,    88,    70,    -1,
      88,    62,    25,    -1,    25,    -1,    27,    -1,    26,    -1,
      28,    -1,    14,    -1,    15,    -1,    16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    54,    55,    56,    57,    58,    59,    62,
      64,    68,    70,    76,    79,    85,    86,    87,    88,    89,
      90,    94,   100,   108,   110,   114,   116,   120,   121,   123,
     124,   125,   129,   130,   131,   132,   133,   134,   137,   143,
     149,   156,   162,   165,   169,   170,   173,   176,   177,   178,
     179,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   195,   197,   198,   199,   200,   202,   207,
     212,   218,   219,   220,   222,   225,   229,   231,   234,   235,
     236,   237,   238,   239
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_BOOL", "TOK_CHAR",
  "TOK_INT", "TOK_STRING", "TOK_ROOT", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_RETURN", "TOK_STRUCT", "TOK_FALSE", "TOK_TRUE", "TOK_NULL",
  "TOK_NEW", "TOK_ARRAY", "TOK_EQ", "TOK_NE", "TOK_LT", "TOK_LE", "TOK_GT",
  "TOK_GE", "TOK_IDENT", "TOK_INTCON", "TOK_CHARCON", "TOK_STRINGCON",
  "TOK_VARIABLE", "TOK_ORD", "TOK_CHR", "TOK_DECLID", "TOK_PROTOTYPE",
  "TOK_TYPE", "TOK_BASETYPE", "TOK_BLOCK", "TOK_BINOP", "TOK_UNOP",
  "TOK_CALL", "TOK_IFELSE", "TOK_INITDECL", "TOK_VARDECL", "TOK_CONSTANT",
  "TOK_POS", "TOK_NEG", "TOK_TYPEID", "TOK_FIELD", "TOK_RETURNVOID",
  "TOK_NEWARRAY", "TOK_NEWSTRING", "TOK_INDEX", "TOK_FUNCTION",
  "TOK_PARAMLIST", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'['",
  "'.'", "TOK_PAREN", "'}'", "';'", "'{'", "')'", "'('", "','", "']'",
  "$accept", "start", "program", "structdef", "fieldecls", "fieldecl",
  "basetype", "function", "paramlist", "identdecl", "block", "blockhead",
  "statement", "vardecl", "while", "ifelse", "return", "expr", "binop",
  "unop", "allocator", "call", "callhead", "variable", "constant", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    61,    43,    45,    42,    47,    37,
      33,    91,    46,   309,   125,    59,   123,    41,    40,    44,
      93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    81,
      82,    82,    83,    83,    83,    83,    83,    83,    84,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    91,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    95,    95,
      95,    95,    95,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     3,
       4,     3,     4,     2,     3,     1,     1,     1,     1,     1,
       1,     4,     4,     3,     2,     3,     2,     2,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     2,     5,     5,
       7,     5,     2,     3,     1,     1,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     4,     5,
       5,     2,     3,     3,     3,     4,     3,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    15,    16,    17,    18,    19,
       0,     0,     0,     0,    81,    82,    83,     0,    77,    79,
      78,    80,     0,     0,     0,     0,     0,    29,     0,     0,
       3,     0,     4,     0,    32,     0,     5,    33,    34,    35,
      36,     0,    44,    45,    47,    48,     0,    49,    50,     6,
       7,     0,     0,    77,    42,     0,     0,     0,    19,    20,
       0,     0,    65,    66,    63,    64,    67,    28,     0,    31,
       0,     0,    26,     0,     0,    27,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    71,     0,     0,     0,    43,     0,    20,     9,
       0,     0,     0,     0,     0,    72,    74,     0,    46,    25,
       0,     0,     0,    24,     0,     0,    62,    61,    60,    59,
      58,    57,    51,    52,    53,    54,    55,    56,     0,    76,
      73,     0,     0,    10,     0,    11,     0,    13,     0,    68,
       0,     0,    22,    26,    21,    23,    75,    41,    39,    12,
      14,    69,    70,    38,     0,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    30,    57,   100,    68,    32,    74,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -109
static const yytype_int16 yypact[] =
{
    -109,     9,   116,  -109,   -60,  -109,  -109,  -109,  -109,  -109,
     -45,   -22,    37,    25,  -109,  -109,  -109,    36,    20,  -109,
    -109,  -109,   369,   369,   369,   369,   369,  -109,   182,   369,
    -109,    41,  -109,   -10,  -109,   248,  -109,  -109,  -109,  -109,
    -109,   509,  -109,  -109,  -109,  -109,   -52,  -109,  -109,  -109,
    -109,   369,   369,    -8,  -109,   536,    29,     7,    22,    31,
      46,   321,     8,     8,     8,     8,     8,  -109,    84,  -109,
     411,    85,    57,    24,   -43,  -109,  -109,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
      87,  -109,  -109,   369,   438,   460,  -109,    30,  -109,  -109,
      48,    83,   369,    51,   369,  -109,   583,    57,  -109,  -109,
     369,    21,   135,  -109,    21,   131,    93,    93,    93,    93,
      93,    93,   583,   100,   100,     8,     8,     8,   384,  -109,
     583,   314,   314,  -109,    50,  -109,    99,  -109,   487,  -109,
     394,   556,  -109,  -109,  -109,  -109,  -109,   129,  -109,  -109,
    -109,  -109,  -109,  -109,   314,  -109
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -109,  -109,  -109,  -109,  -109,    43,    -1,  -109,  -109,   -71,
    -108,  -109,   -28,  -109,  -109,  -109,  -109,    -4,  -109,  -109,
    -109,  -109,  -109,  -109,  -109
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -21
static const yytype_int16 yytable[] =
{
      69,    31,   113,   142,    49,    50,   144,    76,    55,     3,
       5,     6,     7,     8,     9,    92,    60,    93,    62,    63,
      64,    65,    66,    51,   114,    70,   115,     5,     6,     7,
       8,     9,    98,     5,     6,     7,     8,     9,   -20,     5,
       6,     7,     8,    58,   145,   -20,    52,    94,    95,    98,
      56,    14,    15,    16,    17,    98,   101,   106,    73,    71,
      61,    59,    53,    19,    20,    21,    72,    22,    23,    89,
      90,    99,   112,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    27,    28,    61,   130,
     102,   111,    24,    25,   133,    97,   101,    26,   138,   103,
     140,   136,    54,   147,   148,    29,   141,   104,   137,   107,
     109,   110,   129,   135,   112,   149,    -2,     4,   139,     5,
       6,     7,     8,     9,   150,    10,   155,    11,    12,    13,
      14,    15,    16,    17,     5,     6,     7,     8,     9,   154,
     134,    18,    19,    20,    21,     0,    22,    23,    84,    85,
      86,    87,    88,    71,    89,    90,    98,    86,    87,    88,
     143,    89,    90,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    25,     0,     0,     0,    26,     0,     0,     0,
       0,    27,    28,     0,    29,     5,     6,     7,     8,     9,
       0,    10,     0,    11,    12,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,    18,    19,    20,
      21,     0,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,     0,
       0,     0,    26,     0,     0,     0,    67,    27,    28,     0,
      29,     5,     6,     7,     8,     9,     0,    10,     0,    11,
      12,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,    21,     0,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,     0,     0,     0,    26,     0,
       0,     0,    75,    27,    28,     0,    29,     5,     6,     7,
       8,     9,     0,    10,     0,    11,    12,     0,    14,    15,
      16,    17,     0,     0,     0,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,    23,    53,    19,    20,    21,
       0,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,     0,     0,     0,    26,     0,    24,    25,     0,    27,
      28,    26,    29,    14,    15,    16,    17,     0,   105,    29,
       0,     0,     0,     0,    53,    19,    20,    21,     0,    22,
      23,     0,     0,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,    24,    25,     0,     0,     0,    26,
      77,    78,    79,    80,    81,    82,     0,    29,    83,    84,
      85,    86,    87,    88,     0,    89,    90,     0,    83,    84,
      85,    86,    87,    88,   146,    89,    90,    77,    78,    79,
      80,    81,    82,     0,   152,    83,    84,    85,    86,    87,
      88,     0,    89,    90,     0,     0,     0,     0,   108,    77,
      78,    79,    80,    81,    82,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,     0,    89,
      90,     0,     0,     0,     0,   131,    77,    78,    79,    80,
      81,    82,     0,     0,    83,    84,    85,    86,    87,    88,
       0,    89,    90,     0,     0,     0,     0,   132,    77,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,     0,    89,    90,
       0,     0,     0,     0,   151,    77,    78,    79,    80,    81,
      82,     0,     0,    83,    84,    85,    86,    87,    88,     0,
      89,    90,     0,     0,    91,    77,    78,    79,    80,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    86,    87,    88,     0,    89,    90,     0,
       0,    96,    77,    78,    79,    80,    81,    82,     0,     0,
      83,    84,    85,    86,    87,    88,     0,    89,    90,     0,
       0,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,     0,    89,    90
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      28,     2,    73,   111,    64,    65,   114,    35,    12,     0,
       3,     4,     5,     6,     7,    67,    17,    69,    22,    23,
      24,    25,    26,    68,    67,    29,    69,     3,     4,     5,
       6,     7,    25,     3,     4,     5,     6,     7,    18,     3,
       4,     5,     6,     7,   115,    25,    68,    51,    52,    25,
      25,    14,    15,    16,    17,    25,    57,    61,    68,    18,
      68,    25,    25,    26,    27,    28,    25,    30,    31,    61,
      62,    64,    73,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    65,    66,    68,    93,
      68,    67,    55,    56,    64,    66,    97,    60,   102,    68,
     104,    18,    65,   131,   132,    68,   110,    61,    25,    25,
      25,    54,    25,    65,   115,    65,     0,     1,    67,     3,
       4,     5,     6,     7,    25,     9,   154,    11,    12,    13,
      14,    15,    16,    17,     3,     4,     5,     6,     7,    10,
      97,    25,    26,    27,    28,    -1,    30,    31,    55,    56,
      57,    58,    59,    18,    61,    62,    25,    57,    58,    59,
      25,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,     3,     4,     5,     6,     7,
      -1,     9,    -1,    11,    12,    -1,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    64,    65,    66,    -1,
      68,     3,     4,     5,     6,     7,    -1,     9,    -1,    11,
      12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    64,    65,    66,    -1,    68,     3,     4,     5,
       6,     7,    -1,     9,    -1,    11,    12,    -1,    14,    15,
      16,    17,    -1,    -1,    -1,    14,    15,    16,    17,    25,
      26,    27,    28,    -1,    30,    31,    25,    26,    27,    28,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    -1,    -1,    -1,    60,    -1,    55,    56,    -1,    65,
      66,    60,    68,    14,    15,    16,    17,    -1,    67,    68,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,
      19,    20,    21,    22,    23,    24,    -1,    68,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    -1,    54,    55,
      56,    57,    58,    59,    70,    61,    62,    19,    20,    21,
      22,    23,    24,    -1,    70,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    67,    19,    20,    21,    22,
      23,    24,    -1,    -1,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    19,    20,    21,    22,    23,
      24,    -1,    -1,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    -1,    -1,    65,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    -1,
      -1,    65,    19,    20,    21,    22,    23,    24,    -1,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    59,    -1,    61,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,    73,     0,     1,     3,     4,     5,     6,     7,
       9,    11,    12,    13,    14,    15,    16,    17,    25,    26,
      27,    28,    30,    31,    55,    56,    60,    65,    66,    68,
      74,    77,    78,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    64,
      65,    68,    68,    25,    65,    88,    25,    75,     7,    25,
      77,    68,    88,    88,    88,    88,    88,    64,    77,    83,
      88,    18,    25,    68,    79,    64,    83,    19,    20,    21,
      22,    23,    24,    54,    55,    56,    57,    58,    59,    61,
      62,    65,    67,    69,    88,    88,    65,    66,    25,    64,
      76,    77,    68,    68,    61,    67,    88,    25,    67,    25,
      54,    67,    77,    80,    67,    69,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    25,
      88,    67,    67,    64,    76,    65,    18,    25,    88,    67,
      88,    88,    81,    25,    81,    80,    70,    83,    83,    65,
      25,    67,    70,    65,    10,    83
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = YYLEX;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
/* Line 1787 of yacc.c  */
#line 52 "parser.y"
    { yyparse_astree = (yyvsp[(1) - (1)]); }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 54 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 55 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 56 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 57 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 58 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 59 "parser.y"
    { (yyval) = new_parseroot(); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 62 "parser.y"
    {(yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
                                            freeast((yyvsp[(3) - (3)]));}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 64 "parser.y"
    {changeSYM((yyvsp[(2) - (4)]),TOK_TYPEID);
                                             (yyval)=adopt1((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]));
                                             freeast((yyvsp[(3) - (4)]));
                                             freeast((yyvsp[(4) - (4)])); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 68 "parser.y"
    {(yyval) = adopt1 ((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)])); 
                                            freeast((yyvsp[(3) - (3)]));}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 70 "parser.y"
    {changeSYM ((yyvsp[(1) - (4)]), TOK_TYPEID);
                                            (yyval)=adopt1((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));
                                            freeast((yyvsp[(2) - (4)])); 
                                            freeast((yyvsp[(4) - (4)])); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 76 "parser.y"
    { (yyval)=(yyvsp[(2) - (2)]);
                                             changeSYM ((yyvsp[(2) - (2)]),TOK_FIELD);
                                             (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 79 "parser.y"
    { (yyval)=(yyvsp[(3) - (3)]);
                                             changeSYM ((yyvsp[(3) - (3)]),TOK_FIELD);
                                             (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 85 "parser.y"
    {(yyval)=adopt1(func_astree(TOK_BASETYPE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 86 "parser.y"
    {(yyval)=adopt1(func_astree(TOK_BASETYPE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 87 "parser.y"
    {(yyval)=adopt1(func_astree(TOK_BASETYPE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 88 "parser.y"
    {(yyval)=adopt1(func_astree(TOK_BASETYPE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 89 "parser.y"
    {(yyval)=adopt1(func_astree(TOK_BASETYPE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 90 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);
                                            changeSYM ((yyvsp[(1) - (1)]),TOK_TYPEID);}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 95 "parser.y"
    { (yyval) =  func_astree
                                        (TOK_FUNCTION, (yyvsp[(1) - (4)]));
                                        (yyval) = adopt3 ((yyval), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
                                        changeIFproto((yyval),(yyvsp[(4) - (4)]));
                                        freeast((yyvsp[(3) - (4)]));}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 101 "parser.y"
    { (yyval) = func_astree
                                        (TOK_FUNCTION, (yyvsp[(1) - (4)]));
                                        (yyval) = adopt2 ((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)])); 
                                        changeIFproto((yyval),(yyvsp[(4) - (4)]));
                                        freeast((yyvsp[(2) - (4)]));
                                        freeast((yyvsp[(3) - (4)]));}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 108 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); 
                                        freeast((yyvsp[(2) - (3)]));}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 110 "parser.y"
    { changeSYM((yyvsp[(1) - (2)]),TOK_PARAMLIST);
                                        (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 114 "parser.y"
    {changeSYM ((yyvsp[(3) - (3)]),TOK_DECLID);
                                            (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 116 "parser.y"
    {changeSYM ((yyvsp[(2) - (2)]),TOK_DECLID);
                                            (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 120 "parser.y"
    { freeast((yyvsp[(2) - (2)])); (yyval)=(yyvsp[(1) - (2)]);}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 121 "parser.y"
    { changeSYM((yyvsp[(1) - (2)]),TOK_BLOCK);
                                       (yyval)=(yyvsp[(1) - (2)]); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 123 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 124 "parser.y"
    { (yyval)=adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 125 "parser.y"
    { (yyval) = adopt1sym
                                       ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_BLOCK);}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 129 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 130 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 131 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 132 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 133 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 134 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]); freeast((yyvsp[(2) - (2)]));}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 137 "parser.y"
    { 
  (yyval) = adopt3(func_astree(TOK_VARDECL, (yyvsp[(1) - (5)])), (yyvsp[(1) - (5)]),(yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]));
	      freeast((yyvsp[(3) - (5)]));
                                       freeast((yyvsp[(4) - (5)]));}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 144 "parser.y"
    {(yyval)=adopt2((yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));
                                      freeast((yyvsp[(2) - (5)]));
                                      freeast((yyvsp[(4) - (5)]));}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 150 "parser.y"
    { freeast((yyvsp[(6) - (7)]));
                                            freeast((yyvsp[(2) - (7)]));
                                            freeast((yyvsp[(4) - (7)]));
                                            (yyval) = adopt2sym
                                              ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), TOK_IFELSE); 
                                            (yyval) = adopt1 ((yyvsp[(1) - (7)]), (yyvsp[(7) - (7)])); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 157 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                                            freeast((yyvsp[(2) - (5)]));
                                            freeast((yyvsp[(4) - (5)])); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 162 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]);
                                       changeSYM ((yyvsp[(1) - (2)]),TOK_RETURNVOID);
                                       freeast((yyvsp[(2) - (2)]));}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 165 "parser.y"
    { (yyval)=adopt1((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]));
                                       freeast((yyvsp[(3) - (3)]));}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 173 "parser.y"
    { freeast((yyvsp[(1) - (3)]));
                                       freeast((yyvsp[(3) - (3)]));
                                       (yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 176 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 177 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 178 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 179 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 182 "parser.y"
    { (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 183 "parser.y"
    { (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 184 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 185 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 186 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 187 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 188 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 189 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 190 "parser.y"
    { (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));  }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 191 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 192 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 193 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 195 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]),
                                       TOK_POS); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 197 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),TOK_NEG);}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 198 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 199 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 200 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 202 "parser.y"
    {changeSYM((yyvsp[(2) - (4)]),
                                                         TOK_TYPEID);
                                               (yyval)=adopt1((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]));
                                               freeast((yyvsp[(3) - (4)]));
                                               freeast((yyvsp[(4) - (4)]));}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 207 "parser.y"
    {(yyval) = adopt1sym((yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]),
                                                        TOK_NEWSTRING);
                                               freeast((yyvsp[(1) - (5)]));
                                               freeast((yyvsp[(3) - (5)]));
                                               freeast((yyvsp[(4) - (5)]));}
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 212 "parser.y"
    { (yyval) = adopt2sym((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), 
                                                     (yyvsp[(4) - (5)]), TOK_NEWARRAY); 
                                                freeast((yyvsp[(3) - (5)]));
                                                freeast((yyvsp[(5) - (5)]));}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 218 "parser.y"
    { freeast ((yyvsp[(2) - (2)]));}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 219 "parser.y"
    { (yyval)=adopt1sym((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), TOK_CALL);}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 220 "parser.y"
    { (yyval)=adopt1((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));
                                       freeast((yyvsp[(2) - (3)])); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 222 "parser.y"
    {(yyval)=adopt2sym((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOK_CALL);}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 225 "parser.y"
    { freeast((yyvsp[(4) - (4)]));

                                       (yyval) = adopt2sym
                                        ((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), TOK_INDEX);  }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 229 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                                       changeSYM ((yyvsp[(3) - (3)]), TOK_FIELD); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 231 "parser.y"
    { (yyval) = adopt1(func_astree(TOK_VARIABLE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)])); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 234 "parser.y"
    { (yyval) = adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)])); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 235 "parser.y"
    { (yyval) =  adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));; }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 236 "parser.y"
    { (yyval) =  adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));; }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 237 "parser.y"
    { (yyval) =  adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));; }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 238 "parser.y"
    { (yyval) =  adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));; }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 239 "parser.y"
    { (yyval) =  adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));; }
    break;


/* Line 1787 of yacc.c  */
#line 2180 "yyparse.cc"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 241 "parser.y"


const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

static void *yycalloc (size_t size) {
   void *result = calloc (1, size);
   assert (result != NULL);
   return result;
}
