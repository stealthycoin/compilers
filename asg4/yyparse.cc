/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 5 "parser.y"


#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"

#define YYMALLOC yycalloc
static void *yycalloc (size_t size);


/* Line 268 of yacc.c  */
#line 85 "yyparse.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
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


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 181 "yyparse.cc"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   714

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

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
      58,    60,    65,    70,    74,    77,    80,    84,    87,    90,
      92,    95,    98,   100,   102,   104,   106,   108,   110,   113,
     119,   126,   132,   140,   146,   149,   153,   155,   157,   161,
     163,   165,   167,   169,   173,   177,   181,   185,   189,   193,
     197,   201,   205,   209,   213,   217,   220,   223,   226,   229,
     232,   237,   243,   249,   252,   256,   260,   264,   269,   273,
     275,   277,   279,   281,   283,   285
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
      79,    69,    80,    -1,    68,    80,    -1,    77,    25,    -1,
      77,    18,    25,    -1,    82,    64,    -1,    66,    64,    -1,
      65,    -1,    82,    83,    -1,    66,    83,    -1,    81,    -1,
      84,    -1,    80,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    65,    -1,    77,    25,    54,    88,    65,    -1,    77,
      18,    25,    54,    88,    65,    -1,    11,    68,    88,    67,
      83,    -1,     9,    68,    88,    67,    83,    10,    83,    -1,
       9,    68,    88,    67,    83,    -1,    12,    65,    -1,    12,
      88,    65,    -1,    89,    -1,    90,    -1,    68,    88,    67,
      -1,    91,    -1,    92,    -1,    94,    -1,    95,    -1,    88,
      54,    88,    -1,    88,    55,    88,    -1,    88,    56,    88,
      -1,    88,    57,    88,    -1,    88,    58,    88,    -1,    88,
      59,    88,    -1,    88,    24,    88,    -1,    88,    23,    88,
      -1,    88,    22,    88,    -1,    88,    21,    88,    -1,    88,
      20,    88,    -1,    88,    19,    88,    -1,    55,    88,    -1,
      56,    88,    -1,    30,    88,    -1,    31,    88,    -1,    60,
      88,    -1,    17,    25,    68,    67,    -1,    17,     7,    68,
      88,    67,    -1,    17,    77,    61,    88,    70,    -1,    93,
      67,    -1,    25,    68,    67,    -1,    93,    69,    88,    -1,
      25,    68,    88,    -1,    88,    61,    88,    70,    -1,    88,
      62,    25,    -1,    25,    -1,    27,    -1,    26,    -1,    28,
      -1,    14,    -1,    15,    -1,    16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    53,    54,    55,    56,    57,    58,    61,
      63,    67,    69,    75,    78,    84,    85,    86,    87,    88,
      89,    93,    99,   107,   109,   120,   121,   124,   125,   127,
     128,   129,   133,   134,   135,   136,   137,   138,   139,   142,
     146,   151,   157,   164,   170,   173,   177,   178,   181,   184,
     185,   186,   187,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   203,   205,   206,   207,   208,
     210,   215,   220,   226,   227,   228,   230,   233,   237,   239,
     242,   243,   244,   245,   246,   247
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "unop", "allocator", "call", "callhead", "variable", "constant", 0
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
      82,    82,    83,    83,    83,    83,    83,    83,    83,    84,
      84,    85,    86,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      91,    91,    91,    92,    92,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     3,
       4,     3,     4,     2,     3,     1,     1,     1,     1,     1,
       1,     4,     4,     3,     2,     2,     3,     2,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     5,
       6,     5,     7,     5,     2,     3,     1,     1,     3,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       4,     5,     5,     2,     3,     3,     3,     4,     3,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    15,    16,    17,    18,    19,
       0,     0,     0,     0,    83,    84,    85,     0,    79,    81,
      80,    82,     0,     0,     0,     0,     0,    29,     0,     0,
       3,     0,     4,    34,    32,     0,     5,    33,    35,    36,
      37,     0,    46,    47,    49,    50,     0,    51,    52,     6,
       7,     0,     0,    79,    44,     0,     0,     0,    19,    20,
       0,     0,    67,    68,    65,    66,    69,    28,    34,    31,
       0,     0,    25,     0,     0,    27,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    73,     0,     0,     0,    45,     0,    20,     9,
       0,     0,     0,     0,     0,    74,    76,    48,    26,     0,
       0,     0,    24,     0,     0,    64,    63,    62,    61,    60,
      59,    53,    54,    55,    56,    57,    58,     0,    78,    75,
       0,     0,    10,     0,    11,     0,    13,     0,    70,     0,
       0,     0,    22,     0,    25,    21,    23,    77,    43,    41,
      12,    14,    71,    72,     0,    39,    26,     0,    40,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    30,    57,   100,    31,    32,    74,    68,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
     -94,    40,   111,   -94,   -59,   -94,   -94,   -94,   -94,   -94,
     -16,    -2,   316,    39,   -94,   -94,   -94,   128,   -15,   -94,
     -94,   -94,   389,   389,   389,   389,   389,   -94,   177,   389,
     -94,   -17,   -94,    27,   -94,   243,   -94,   -94,   -94,   -94,
     -94,   534,   -94,   -94,   -94,   -94,   -30,   -94,   -94,   -94,
     -94,   389,   389,    28,   -94,   581,    22,    23,    30,    32,
      25,   371,    20,    20,    20,    20,    20,   -94,   -94,   -94,
     441,    66,    43,    18,    -4,   -94,   -94,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
      79,   -94,   -94,   389,   457,   506,   -94,    29,   -94,   -94,
      41,    -7,   389,    38,   389,   -94,   652,   -94,    53,   389,
      24,    13,   -94,    24,   140,     0,     0,     0,     0,     0,
       0,   652,   -12,   -12,    20,    20,    20,   413,   -94,   652,
     309,   309,   -94,    44,   -94,    83,   -94,   520,   -94,   431,
     389,   593,   -94,    85,   -94,   -94,   -94,   -94,   103,   -94,
     -94,   -94,   -94,   -94,   605,   -94,   -94,   309,   -94,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -94,    51,   -13,   -94,   -94,     7,
     -93,   -94,   -28,   -94,   -94,   -94,   -94,   -10,   -94,   -94,
     -94,   -94,   -94,   -94,   -94
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -21
static const yytype_int16 yytable[] =
{
      69,    71,    55,   -20,    60,    49,    50,    76,    72,    33,
     -20,   135,    62,    63,    64,    65,    66,   142,   136,    70,
     145,     5,     6,     7,     8,     9,     5,     6,     7,     8,
       9,   143,     5,     6,     7,     8,     9,    92,   144,    93,
       3,    94,    95,    98,   101,    86,    87,    88,    98,    89,
      90,   106,    51,    61,    98,    84,    85,    86,    87,    88,
     111,    89,    90,   113,    56,   114,    52,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     112,    89,    90,   129,   101,   110,   104,    99,    97,    27,
      28,   108,   137,   132,   139,    73,    61,   109,   102,   141,
     103,   111,   148,   149,   128,   138,   134,   140,   151,   150,
     156,    -2,     4,   157,     5,     6,     7,     8,     9,     0,
      10,   146,    11,    12,    13,    14,    15,    16,    17,   159,
     154,     5,     6,     7,     8,    58,    18,    19,    20,    21,
       0,    22,    23,     5,     6,     7,     8,     9,   133,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    24,    25,     0,     0,
       0,    26,     0,     0,     0,     0,    27,    28,     0,    29,
       5,     6,     7,     8,     9,     0,    10,     0,    11,    12,
       0,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,     0,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,     0,     0,     0,    26,     0,     0,
       0,    67,    27,    28,     0,    29,     5,     6,     7,     8,
       9,     0,    10,     0,    11,    12,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,     0,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
       0,     0,     0,    26,     0,     0,     0,    75,    27,    28,
       0,    29,     5,     6,     7,     8,     9,     0,    10,     0,
      11,    12,     0,    14,    15,    16,    17,     0,     0,     0,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
      23,    53,    19,    20,    21,     0,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,     0,     0,     0,    26,
       0,    24,    25,     0,    27,    28,    26,    29,     0,     0,
       0,    54,     0,     0,    29,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,    53,    19,    20,    21,
       0,    22,    23,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,    53,    19,    20,    21,     0,    22,
      23,     0,     0,     0,     0,     0,    24,    25,     0,     0,
       0,    26,    77,    78,    79,    80,    81,    82,   105,    29,
       0,     0,     0,     0,    24,    25,     0,     0,     0,    26,
      77,    78,    79,    80,    81,    82,     0,    29,     0,     0,
      77,    78,    79,    80,    81,    82,     0,    83,    84,    85,
      86,    87,    88,     0,    89,    90,    77,    78,    79,    80,
      81,    82,     0,   147,     0,    83,    84,    85,    86,    87,
      88,     0,    89,    90,     0,    83,    84,    85,    86,    87,
      88,   153,    89,    90,     0,     0,     0,     0,   107,     0,
       0,    83,    84,    85,    86,    87,    88,     0,    89,    90,
       0,     0,     0,     0,   130,    77,    78,    79,    80,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,     0,
      83,    84,    85,    86,    87,    88,     0,    89,    90,     0,
       0,     0,     0,   131,    83,    84,    85,    86,    87,    88,
       0,    89,    90,     0,     0,     0,     0,   152,    83,    84,
      85,    86,    87,    88,     0,    89,    90,     0,     0,    91,
      77,    78,    79,    80,    81,    82,     0,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    82,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
       0,     0,     0,     0,     0,    83,    84,    85,    86,    87,
      88,     0,    89,    90,     0,     0,    96,    83,    84,    85,
      86,    87,    88,     0,    89,    90,     0,     0,   155,    83,
      84,    85,    86,    87,    88,     0,    89,    90,     0,     0,
     158,    77,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,     0,    89,    90
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-94))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      28,    18,    12,    18,    17,    64,    65,    35,    25,     2,
      25,    18,    22,    23,    24,    25,    26,   110,    25,    29,
     113,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    18,     3,     4,     5,     6,     7,    67,    25,    69,
       0,    51,    52,    25,    57,    57,    58,    59,    25,    61,
      62,    61,    68,    68,    25,    55,    56,    57,    58,    59,
      73,    61,    62,    67,    25,    69,    68,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      73,    61,    62,    93,    97,    67,    61,    64,    66,    65,
      66,    25,   102,    64,   104,    68,    68,    54,    68,   109,
      68,   114,   130,   131,    25,    67,    65,    54,    25,    65,
      25,     0,     1,    10,     3,     4,     5,     6,     7,    -1,
       9,   114,    11,    12,    13,    14,    15,    16,    17,   157,
     140,     3,     4,     5,     6,     7,    25,    26,    27,    28,
      -1,    30,    31,     3,     4,     5,     6,     7,    97,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    55,    56,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    12,
      -1,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    64,    65,    66,    -1,    68,     3,     4,     5,     6,
       7,    -1,     9,    -1,    11,    12,    -1,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    64,    65,    66,
      -1,    68,     3,     4,     5,     6,     7,    -1,     9,    -1,
      11,    12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,
      14,    15,    16,    17,    25,    26,    27,    28,    -1,    30,
      31,    25,    26,    27,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,
      -1,    55,    56,    -1,    65,    66,    60,    68,    -1,    -1,
      -1,    65,    -1,    -1,    68,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    60,    19,    20,    21,    22,    23,    24,    67,    68,
      -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,
      19,    20,    21,    22,    23,    24,    -1,    68,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    19,    20,    21,    22,
      23,    24,    -1,    70,    -1,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    -1,    54,    55,    56,    57,    58,
      59,    70,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,    65,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    65,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    -1,    -1,    65,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      65,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,
      58,    59,    -1,    61,    62
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
      77,    68,    88,    88,    88,    88,    88,    64,    80,    83,
      88,    18,    25,    68,    79,    64,    83,    19,    20,    21,
      22,    23,    24,    54,    55,    56,    57,    58,    59,    61,
      62,    65,    67,    69,    88,    88,    65,    66,    25,    64,
      76,    77,    68,    68,    61,    67,    88,    67,    25,    54,
      67,    77,    80,    67,    69,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    25,    88,
      67,    67,    64,    76,    65,    18,    25,    88,    67,    88,
      54,    88,    81,    18,    25,    81,    80,    70,    83,    83,
      65,    25,    67,    70,    88,    65,    25,    10,    65,    83
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

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


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
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  *++yyvsp = yylval;

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

/* Line 1806 of yacc.c  */
#line 51 "parser.y"
    { yyparse_astree = (yyvsp[(1) - (1)]); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 53 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 54 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 55 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 56 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 57 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 58 "parser.y"
    { (yyval) = new_parseroot(); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 61 "parser.y"
    {(yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
                                            freeast((yyvsp[(3) - (3)]));}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 63 "parser.y"
    {changeSYM((yyvsp[(2) - (4)]),TOK_TYPEID);
                                             (yyval)=adopt1((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]));
                                             freeast((yyvsp[(3) - (4)]));
                                             freeast((yyvsp[(4) - (4)])); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 67 "parser.y"
    {(yyval) = adopt1 ((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)])); 
                                            freeast((yyvsp[(3) - (3)]));}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 69 "parser.y"
    {changeSYM ((yyvsp[(1) - (4)]), TOK_TYPEID);
                                            (yyval)=adopt1((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));
                                            freeast((yyvsp[(2) - (4)])); 
                                            freeast((yyvsp[(4) - (4)])); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 75 "parser.y"
    { (yyval)=(yyvsp[(2) - (2)]);
                                             changeSYM ((yyvsp[(2) - (2)]),TOK_FIELD);
                                             (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 78 "parser.y"
    { (yyval)=(yyvsp[(3) - (3)]);
                                             changeSYM ((yyvsp[(3) - (3)]),TOK_FIELD);
                                             (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 84 "parser.y"
    {(yyval)=adopt1(func_astree(TOK_BASETYPE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 85 "parser.y"
    {(yyval)=adopt1(func_astree(TOK_BASETYPE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 86 "parser.y"
    {(yyval)=adopt1(func_astree(TOK_BASETYPE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 87 "parser.y"
    {(yyval)=adopt1(func_astree(TOK_BASETYPE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 88 "parser.y"
    {(yyval)=adopt1(func_astree(TOK_BASETYPE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 89 "parser.y"
    {(yyval)=(yyvsp[(1) - (1)]);
                                            changeSYM ((yyvsp[(1) - (1)]),TOK_TYPEID);}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 94 "parser.y"
    { (yyval) =  func_astree
                                        (TOK_FUNCTION, (yyvsp[(1) - (4)]));
                                        (yyval) = adopt3 ((yyval), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
                                        changeIFproto((yyval),(yyvsp[(4) - (4)]));
                                        freeast((yyvsp[(3) - (4)]));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 100 "parser.y"
    { (yyval) = func_astree
                                        (TOK_FUNCTION, (yyvsp[(1) - (4)]));
                                        (yyval) = adopt2 ((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)])); 
                                        changeIFproto((yyval),(yyvsp[(4) - (4)]));
                                        freeast((yyvsp[(2) - (4)]));
                                        freeast((yyvsp[(3) - (4)]));}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 107 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); 
                                        freeast((yyvsp[(2) - (3)]));}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 109 "parser.y"
    { changeSYM((yyvsp[(1) - (2)]),TOK_PARAMLIST);
                                        (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 120 "parser.y"
    { (yyval) = adopt2 (func_astree(TOK_DECLID, (yyvsp[(1) - (2)])), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 121 "parser.y"
    { (yyval) = adopt3 (func_astree(TOK_DECLID, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 124 "parser.y"
    { freeast((yyvsp[(2) - (2)])); (yyval)=(yyvsp[(1) - (2)]);}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 125 "parser.y"
    { changeSYM((yyvsp[(1) - (2)]),TOK_BLOCK);
                                       (yyval)=(yyvsp[(1) - (2)]); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 127 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 128 "parser.y"
    { (yyval)=adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 129 "parser.y"
    { (yyval) = adopt1sym
                                       ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_BLOCK);}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 133 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 134 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 135 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 136 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 137 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 138 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 139 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]); freeast((yyvsp[(2) - (2)]));}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 142 "parser.y"
    { 
              (yyval) = adopt3(func_astree(TOK_VARDECL, (yyvsp[(1) - (5)])), (yyvsp[(1) - (5)]),(yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]));
	      freeast((yyvsp[(3) - (5)]));
                                       freeast((yyvsp[(4) - (5)]));}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 146 "parser.y"
    { 
	      (yyval) = adopt3(adopt1(func_astree(TOK_VARDECL, (yyvsp[(1) - (6)])), (yyvsp[(2) - (6)])), (yyvsp[(1) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]));
	      freeast((yyvsp[(4) - (6)]));}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 152 "parser.y"
    {(yyval)=adopt2((yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));
                                      freeast((yyvsp[(2) - (5)]));
                                      freeast((yyvsp[(4) - (5)]));}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 158 "parser.y"
    { freeast((yyvsp[(6) - (7)]));
                                            freeast((yyvsp[(2) - (7)]));
                                            freeast((yyvsp[(4) - (7)]));
                                            (yyval) = adopt2sym
                                              ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), TOK_IFELSE); 
                                            (yyval) = adopt1 ((yyvsp[(1) - (7)]), (yyvsp[(7) - (7)])); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 165 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                                            freeast((yyvsp[(2) - (5)]));
                                            freeast((yyvsp[(4) - (5)])); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 170 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)]);
                                       changeSYM ((yyvsp[(1) - (2)]),TOK_RETURNVOID);
                                       freeast((yyvsp[(2) - (2)]));}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 173 "parser.y"
    { (yyval)=adopt1((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]));
                                       freeast((yyvsp[(3) - (3)]));}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 181 "parser.y"
    { freeast((yyvsp[(1) - (3)]));
                                       freeast((yyvsp[(3) - (3)]));
                                       (yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 184 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 185 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 186 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 187 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 190 "parser.y"
    { (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 191 "parser.y"
    { (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 192 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 193 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 194 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 195 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 196 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 198 "parser.y"
    { (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));  }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 199 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 200 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 201 "parser.y"
    {  (yyval) = adopt3 (func_astree(TOK_BINOP, (yyvsp[(1) - (3)])), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 203 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]),
                                       TOK_POS); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 205 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),TOK_NEG);}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 206 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 207 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 208 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 210 "parser.y"
    {changeSYM((yyvsp[(2) - (4)]),
                                                         TOK_TYPEID);
                                               (yyval)=adopt1((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]));
                                               freeast((yyvsp[(3) - (4)]));
                                               freeast((yyvsp[(4) - (4)]));}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 215 "parser.y"
    {(yyval) = adopt1sym((yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]),
                                                        TOK_NEWSTRING);
                                               freeast((yyvsp[(1) - (5)]));
                                               freeast((yyvsp[(3) - (5)]));
                                               freeast((yyvsp[(4) - (5)]));}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 220 "parser.y"
    { (yyval) = adopt2sym((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), 
                                                     (yyvsp[(4) - (5)]), TOK_NEWARRAY); 
                                                freeast((yyvsp[(3) - (5)]));
                                                freeast((yyvsp[(5) - (5)]));}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 226 "parser.y"
    { freeast ((yyvsp[(2) - (2)]));}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 227 "parser.y"
    { (yyval)=adopt1sym((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), TOK_CALL);}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 228 "parser.y"
    { (yyval)=adopt1((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));
                                       freeast((yyvsp[(2) - (3)])); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 230 "parser.y"
    {(yyval)=adopt2sym((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),TOK_CALL);}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 233 "parser.y"
    { freeast((yyvsp[(4) - (4)]));

                                       (yyval) = adopt2sym
                                        ((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), TOK_INDEX);  }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 237 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                                       changeSYM ((yyvsp[(3) - (3)]), TOK_FIELD); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 239 "parser.y"
    { (yyval) = adopt1(func_astree(TOK_VARIABLE, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)])); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 242 "parser.y"
    { (yyval) = adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)])); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 243 "parser.y"
    { (yyval) =  adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));; }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 244 "parser.y"
    { (yyval) =  adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));; }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 245 "parser.y"
    { (yyval) =  adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));; }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 246 "parser.y"
    { (yyval) =  adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));; }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 247 "parser.y"
    { (yyval) =  adopt1(func_astree(TOK_CONSTANT, (yyvsp[(1) - (1)])), (yyvsp[(1) - (1)]));; }
    break;



/* Line 1806 of yacc.c  */
#line 2303 "yyparse.cc"
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 2067 of yacc.c  */
#line 249 "parser.y"


const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

static void *yycalloc (size_t size) {
   void *result = calloc (1, size);
   assert (result != NULL);
   return result;
}

