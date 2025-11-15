
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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

/* Line 189 of yacc.c  */
#line 2 "sysy.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/ast.h"
#include "include/node_type.h"

void yyerror(const char *s);
int yylex(void);  // 由 flex 提供


/* Line 189 of yacc.c  */
#line 85 "sysy.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 14 "sysy.y"

#include "include/ast.h"



/* Line 209 of yacc.c  */
#line 115 "sysy.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     num_INT = 258,
     Y_INT = 259,
     Y_VOID = 260,
     Y_CONST = 261,
     Y_IF = 262,
     Y_ELSE = 263,
     Y_WHILE = 264,
     Y_BREAK = 265,
     Y_CONTINUE = 266,
     Y_FLOAT = 267,
     Y_RETURN = 268,
     Y_ADD = 269,
     Y_COMMA = 270,
     Y_DIV = 271,
     Y_LPAR = 272,
     Y_SUB = 273,
     Y_LSQUARE = 274,
     Y_MODULO = 275,
     Y_MUL = 276,
     Y_NOT = 277,
     Y_RPAR = 278,
     Y_RSQUARE = 279,
     Y_RBRACKET = 280,
     Y_LESS = 281,
     Y_LESSEQ = 282,
     Y_GREAT = 283,
     Y_GREATEQ = 284,
     Y_NOTEQ = 285,
     Y_EQ = 286,
     Y_AND = 287,
     Y_OR = 288,
     Y_ASSIGN = 289,
     Y_LBRACKET = 290,
     Y_SEMICOLON = 291,
     num_FLOAT = 292,
     Y_ID = 293,
     YYEOF = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 19 "sysy.y"

      /* 需拓展 */
    int ival;
    char* sval;
    double fval;
    past pval;



/* Line 214 of yacc.c  */
#line 181 "sysy.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 193 "sysy.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    13,    15,    17,    19,
      24,    29,    33,    37,    41,    46,    50,    55,    57,    60,
      64,    69,    72,    76,    80,    85,    88,    92,    94,    98,
     101,   106,   108,   111,   115,   120,   123,   127,   133,   140,
     142,   146,   149,   154,   158,   164,   168,   171,   173,   176,
     178,   180,   185,   187,   190,   192,   198,   204,   212,   215,
     218,   222,   225,   227,   229,   232,   236,   241,   245,   247,
     249,   251,   253,   257,   262,   265,   268,   271,   273,   277,
     279,   283,   287,   291,   293,   297,   301,   303,   307,   311,
     315,   319,   321,   325,   329,   331,   335,   337,   341,   343,
     345,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    43,    42,    -1,    55,    42,
      -1,    43,    -1,    55,    -1,    44,    -1,    50,    -1,     6,
      75,    46,    36,    -1,     6,    75,    45,    36,    -1,    46,
      15,    46,    -1,    45,    15,    46,    -1,    38,    34,    48,
      -1,    38,    47,    34,    48,    -1,    19,    74,    24,    -1,
      19,    74,    24,    47,    -1,    74,    -1,    35,    25,    -1,
      35,    48,    25,    -1,    35,    48,    49,    25,    -1,    15,
      48,    -1,    15,    48,    49,    -1,    75,    52,    36,    -1,
      75,    52,    51,    36,    -1,    15,    52,    -1,    15,    52,
      51,    -1,    38,    -1,    38,    34,    53,    -1,    38,    47,
      -1,    38,    47,    34,    53,    -1,    62,    -1,    35,    25,
      -1,    35,    53,    25,    -1,    35,    53,    54,    25,    -1,
      15,    53,    -1,    15,    53,    54,    -1,    75,    38,    17,
      23,    58,    -1,    75,    38,    17,    56,    23,    58,    -1,
      57,    -1,    56,    15,    57,    -1,    75,    38,    -1,    75,
      38,    19,    24,    -1,    75,    38,    64,    -1,    75,    38,
      19,    24,    64,    -1,    35,    59,    25,    -1,    35,    25,
      -1,    60,    -1,    60,    59,    -1,    43,    -1,    61,    -1,
      63,    34,    62,    36,    -1,    36,    -1,    62,    36,    -1,
      58,    -1,     9,    17,    73,    23,    61,    -1,     7,    17,
      73,    23,    61,    -1,     7,    17,    73,    23,    61,     8,
      61,    -1,    10,    36,    -1,    11,    36,    -1,    13,    62,
      36,    -1,    13,    36,    -1,    69,    -1,    38,    -1,    38,
      64,    -1,    19,    62,    24,    -1,    19,    62,    24,    64,
      -1,    17,    62,    23,    -1,    63,    -1,     3,    -1,    37,
      -1,    65,    -1,    38,    17,    23,    -1,    38,    17,    67,
      23,    -1,    14,    66,    -1,    18,    66,    -1,    22,    66,
      -1,    62,    -1,    62,    15,    67,    -1,    66,    -1,    68,
      21,    66,    -1,    68,    16,    66,    -1,    68,    20,    66,
      -1,    68,    -1,    69,    14,    68,    -1,    69,    18,    68,
      -1,    69,    -1,    69,    26,    70,    -1,    69,    28,    70,
      -1,    69,    27,    70,    -1,    69,    29,    70,    -1,    70,
      -1,    70,    31,    71,    -1,    70,    30,    71,    -1,    71,
      -1,    71,    32,    72,    -1,    72,    -1,    72,    33,    73,
      -1,    69,    -1,     4,    -1,    12,    -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    53,    58,    63,    67,    72,    75,    79,
      84,    90,    95,   101,   106,   113,   116,   122,   125,   128,
     131,   137,   141,   147,   152,   159,   163,   168,   172,   177,
     182,   190,   193,   196,   200,   206,   210,   216,   222,   230,
     233,   239,   244,   249,   255,   262,   266,   270,   273,   278,
     281,   285,   291,   294,   297,   301,   306,   311,   317,   320,
     323,   327,   331,   333,   337,   343,   347,   353,   356,   359,
     363,   368,   371,   375,   380,   385,   390,   396,   400,   406,
     409,   415,   422,   429,   432,   438,   445,   448,   454,   460,
     466,   473,   476,   482,   489,   492,   500,   503,   510,   514,
     518,   522
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "num_INT", "Y_INT", "Y_VOID", "Y_CONST",
  "Y_IF", "Y_ELSE", "Y_WHILE", "Y_BREAK", "Y_CONTINUE", "Y_FLOAT",
  "Y_RETURN", "Y_ADD", "Y_COMMA", "Y_DIV", "Y_LPAR", "Y_SUB", "Y_LSQUARE",
  "Y_MODULO", "Y_MUL", "Y_NOT", "Y_RPAR", "Y_RSQUARE", "Y_RBRACKET",
  "Y_LESS", "Y_LESSEQ", "Y_GREAT", "Y_GREATEQ", "Y_NOTEQ", "Y_EQ", "Y_AND",
  "Y_OR", "Y_ASSIGN", "Y_LBRACKET", "Y_SEMICOLON", "num_FLOAT", "Y_ID",
  "YYEOF", "$accept", "program", "CompUnit", "Decl", "ConstDecl",
  "ConstDefs", "ConstDef", "ConstExps", "ConstInitVal", "ConstInitVals",
  "VarDecl", "VarDecls", "VarDef", "InitVal", "InitVals", "FuncDef",
  "FuncParams", "FuncParam", "Block", "BlockItems", "BlockItem", "Stmt",
  "Exp", "LVal", "ArraySubscripts", "PrimaryExp", "UnaryExp", "CallParams",
  "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp",
  "Type", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    42,    43,    43,    44,
      44,    45,    45,    46,    46,    47,    47,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    52,
      52,    53,    53,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    70,    70,    70,    70,
      70,    71,    71,    71,    72,    72,    73,    73,    74,    75,
      75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     4,
       4,     3,     3,     3,     4,     3,     4,     1,     2,     3,
       4,     2,     3,     3,     4,     2,     3,     1,     3,     2,
       4,     1,     2,     3,     4,     2,     3,     5,     6,     1,
       3,     2,     4,     3,     5,     3,     2,     1,     2,     1,
       1,     4,     1,     2,     1,     5,     5,     7,     2,     2,
       3,     2,     1,     1,     2,     3,     4,     3,     1,     1,
       1,     1,     3,     4,     2,     2,     2,     1,     3,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    99,   101,     0,   100,     0,     2,     5,     7,     8,
       6,     0,     0,     1,     3,     4,    27,     0,     0,     0,
       0,     0,     0,     0,    29,     0,    23,     0,     0,     0,
       0,    10,     0,     9,     0,     0,    39,     0,    69,     0,
       0,     0,     0,    70,    63,    68,    71,    79,    83,    98,
       0,     0,    28,    31,    62,     0,    27,    25,    24,     0,
      13,    17,     0,    12,    11,     0,    37,     0,     0,    41,
      74,     0,    75,    76,     0,     0,    64,     0,     0,     0,
       0,     0,    15,    32,     0,    30,    26,    18,     0,    14,
       0,     0,     0,     0,     0,    46,    52,    49,    54,     0,
      47,    50,     0,    68,     0,    40,    38,     0,    43,    67,
      72,    77,     0,     0,    81,    82,    80,    84,    85,    16,
       0,    33,     0,     0,    19,     0,     0,     0,    58,    59,
      61,     0,    45,    48,    53,     0,    42,     0,    73,    65,
      35,    34,    21,    20,    86,    91,    94,    96,     0,     0,
      60,     0,    44,    78,    66,    36,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    87,    89,
      88,    90,    93,    92,    95,    97,    56,    55,     0,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    19,    20,    24,    60,   125,
       9,    27,    17,    52,   122,    10,    35,    36,    98,    99,
     100,   101,   102,    45,    76,    46,    47,   112,    48,    54,
     145,   146,   147,   148,    61,    11
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -124
static const yytype_int16 yypact[] =
{
     117,  -124,  -124,    85,  -124,    25,  -124,   117,  -124,  -124,
     117,    -2,    24,  -124,  -124,  -124,    32,     2,    -5,     3,
      16,    52,   278,   207,    45,    56,  -124,    70,   213,    84,
      24,  -124,    24,  -124,    89,    40,  -124,    96,  -124,   278,
     278,   278,   278,  -124,    61,  -124,  -124,  -124,    82,   101,
     124,    10,  -124,  -124,   101,   207,    27,   153,  -124,   201,
    -124,  -124,   213,  -124,  -124,   140,  -124,    85,    89,   136,
    -124,   146,  -124,  -124,   238,   278,  -124,   278,   278,   278,
     278,   278,   151,  -124,     1,  -124,  -124,  -124,    18,  -124,
     154,   155,   137,   138,   250,  -124,  -124,  -124,  -124,   159,
     176,  -124,   156,   157,    56,  -124,  -124,   256,  -124,  -124,
    -124,   180,   173,   175,  -124,  -124,  -124,    82,    82,  -124,
     207,  -124,   172,   213,  -124,   177,   278,   278,  -124,  -124,
    -124,   164,  -124,  -124,  -124,   278,   182,   278,  -124,   182,
     188,  -124,   190,  -124,    99,   130,   174,   184,   185,   186,
    -124,   171,  -124,  -124,  -124,  -124,  -124,   278,   278,   278,
     278,   278,   278,   278,   278,    74,    74,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,   212,  -124,    74,  -124
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,   149,   -50,  -124,  -124,    63,    -6,   -51,    80,
    -124,   183,   203,   -46,    92,  -124,  -124,   166,   -24,   134,
    -124,   -96,   -21,   -58,   -68,  -124,   -19,   100,    83,   -22,
     -27,     5,    86,  -123,   221,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      49,   108,    53,    12,   149,    84,    49,   103,    88,    85,
      66,    89,    29,    38,    22,    97,   120,    25,    30,    71,
      70,    37,    72,    73,    39,    13,   121,    40,    41,    28,
      53,    32,    42,   123,    53,    83,    16,    49,    26,    31,
      49,   175,   103,   124,   106,    51,    22,    43,    44,    21,
      97,    22,    33,   111,   113,    67,     1,     2,   114,   115,
     116,    23,    18,    68,     4,   104,    23,    37,   152,   176,
     177,   154,   142,   131,   140,    34,   119,    38,    74,    55,
      75,    90,   179,    91,    92,    93,   113,    94,    39,     1,
       2,    40,    41,    63,    56,    64,    42,     4,    77,    53,
     104,    49,    78,    79,   144,   144,    58,   103,   103,    65,
      96,    43,    44,    80,   151,    80,   111,    81,    62,    81,
     103,     1,     2,     3,    65,   157,   158,   159,   160,     4,
     168,   169,   170,   171,    69,   144,   144,   144,   144,   144,
     144,   144,   144,    38,     1,     2,     3,    90,    82,    91,
      92,    93,     4,    94,    39,   107,    14,    40,    41,    15,
     161,   162,    42,   117,   118,    95,   172,   173,    25,   109,
      22,   126,   127,   128,   129,    65,    96,    43,    44,    38,
       1,     2,     3,    90,   132,    91,    92,    93,     4,    94,
      39,   135,   134,    40,    41,   137,   138,   141,    42,   139,
     150,    75,   143,   120,    38,   123,   163,   167,   165,   166,
      38,    65,    96,    43,    44,    39,    38,   164,    40,    41,
     178,    39,   156,    42,    40,    41,    87,    39,    57,    42,
      40,    41,   155,   105,   133,    42,    59,   153,    43,    44,
      86,    38,    51,    50,    43,    44,     0,     0,    59,   174,
      43,    44,    39,    38,     0,    40,    41,     0,     0,    38,
      42,   110,     0,     0,    39,     0,     0,    40,    41,     0,
      39,     0,    42,    40,    41,    43,    44,     0,    42,     0,
     136,    38,     0,     0,     0,     0,   130,    43,    44,     0,
       0,     0,    39,    43,    44,    40,    41,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    44
};

static const yytype_int16 yycheck[] =
{
      22,    69,    23,     3,   127,    51,    28,    65,    59,    55,
      34,    62,    18,     3,    19,    65,    15,    15,    15,    40,
      39,    21,    41,    42,    14,     0,    25,    17,    18,    34,
      51,    15,    22,    15,    55,    25,    38,    59,    36,    36,
      62,   164,   100,    25,    68,    35,    19,    37,    38,    17,
     100,    19,    36,    74,    75,    15,     4,     5,    77,    78,
      79,    34,    38,    23,    12,    65,    34,    67,   136,   165,
     166,   139,   123,    94,   120,    23,    82,     3,    17,    34,
      19,     7,   178,     9,    10,    11,   107,    13,    14,     4,
       5,    17,    18,    30,    38,    32,    22,    12,    16,   120,
     100,   123,    20,    21,   126,   127,    36,   165,   166,    35,
      36,    37,    38,    14,   135,    14,   137,    18,    34,    18,
     178,     4,     5,     6,    35,    26,    27,    28,    29,    12,
     157,   158,   159,   160,    38,   157,   158,   159,   160,   161,
     162,   163,   164,     3,     4,     5,     6,     7,    24,     9,
      10,    11,    12,    13,    14,    19,     7,    17,    18,    10,
      30,    31,    22,    80,    81,    25,   161,   162,    15,    23,
      19,    17,    17,    36,    36,    35,    36,    37,    38,     3,
       4,     5,     6,     7,    25,     9,    10,    11,    12,    13,
      14,    34,    36,    17,    18,    15,    23,    25,    22,    24,
      36,    19,    25,    15,     3,    15,    32,    36,    23,    23,
       3,    35,    36,    37,    38,    14,     3,    33,    17,    18,
       8,    14,   142,    22,    17,    18,    25,    14,    25,    22,
      17,    18,   140,    67,   100,    22,    35,   137,    37,    38,
      57,     3,    35,    22,    37,    38,    -1,    -1,    35,   163,
      37,    38,    14,     3,    -1,    17,    18,    -1,    -1,     3,
      22,    23,    -1,    -1,    14,    -1,    -1,    17,    18,    -1,
      14,    -1,    22,    17,    18,    37,    38,    -1,    22,    -1,
      24,     3,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      -1,    -1,    14,    37,    38,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,    12,    41,    42,    43,    44,    50,
      55,    75,    75,     0,    42,    42,    38,    52,    38,    45,
      46,    17,    19,    34,    47,    15,    36,    51,    34,    47,
      15,    36,    15,    36,    23,    56,    57,    75,     3,    14,
      17,    18,    22,    37,    38,    63,    65,    66,    68,    69,
      74,    35,    53,    62,    69,    34,    38,    52,    36,    35,
      48,    74,    34,    46,    46,    35,    58,    15,    23,    38,
      66,    62,    66,    66,    17,    19,    64,    16,    20,    21,
      14,    18,    24,    25,    53,    53,    51,    25,    48,    48,
       7,     9,    10,    11,    13,    25,    36,    43,    58,    59,
      60,    61,    62,    63,    75,    57,    58,    19,    64,    23,
      23,    62,    67,    62,    66,    66,    66,    68,    68,    47,
      15,    25,    54,    15,    25,    49,    17,    17,    36,    36,
      36,    62,    25,    59,    36,    34,    24,    15,    23,    24,
      53,    25,    48,    25,    69,    70,    71,    72,    73,    73,
      36,    62,    64,    67,    64,    54,    49,    26,    27,    28,
      29,    30,    31,    32,    33,    23,    23,    36,    70,    70,
      70,    70,    71,    71,    72,    73,    61,    61,     8,    61
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 47 "sysy.y"
    {
            showAst((yyvsp[(1) - (1)].pval), 0, 1);
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 53 "sysy.y"
    {
            (yyval.pval) = new_ast_node(TRANSLATION_UNIT);
            (yyval.pval)->left = (yyvsp[(1) - (2)].pval);
            (yyval.pval)->right = (yyvsp[(2) - (2)].pval);
      ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 58 "sysy.y"
    {
            (yyval.pval) = new_ast_node(TRANSLATION_UNIT);
            (yyval.pval)->left = (yyvsp[(1) - (2)].pval);
            (yyval.pval)->right = (yyvsp[(2) - (2)].pval);
      ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 63 "sysy.y"
    {
            (yyval.pval) = new_ast_node(TRANSLATION_UNIT);
            (yyval.pval)->left = (yyvsp[(1) - (1)].pval);
        ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 67 "sysy.y"
    {
            (yyval.pval) = new_ast_node(TRANSLATION_UNIT);
            (yyval.pval)->left = (yyvsp[(1) - (1)].pval);
        ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 72 "sysy.y"
    {
      (yyval.pval) = (yyvsp[(1) - (1)].pval);
;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 75 "sysy.y"
    {
      (yyval.pval) = (yyvsp[(1) - (1)].pval);
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 79 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->left = (yyvsp[(2) - (4)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (4)].pval);
      ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 84 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->left = (yyvsp[(2) - (4)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (4)].pval);
         ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 90 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);            
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);      
      ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 95 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);            
         ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 101 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->svalue = (yyvsp[(1) - (3)].sval);            
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);      
      ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 106 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->svalue = (yyvsp[(1) - (4)].sval);
            (yyval.pval)->left = (yyvsp[(2) - (4)].pval);
            (yyval.pval)->right = (yyvsp[(4) - (4)].pval);      
        ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 113 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(2) - (3)].pval);
      ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 116 "sysy.y"
    {
            (yyval.pval) = new_ast_node(INIT_LIST_EXPR);
            (yyval.pval)->left = (yyvsp[(2) - (4)].pval);
            (yyval.pval)->right = (yyvsp[(4) - (4)].pval);
         ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 122 "sysy.y"
    {
                  (yyval.pval) = (yyvsp[(1) - (1)].pval);
            ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 125 "sysy.y"
    {      
                  (yyval.pval) = NULL;
            ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 128 "sysy.y"
    {
                  (yyval.pval) = (yyvsp[(2) - (3)].pval)
            ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 131 "sysy.y"
    {
                  (yyval.pval) = new_ast_node(INIT_LIST_EXPR);
                  (yyval.pval)->left = (yyvsp[(2) - (4)].pval);
                  (yyval.pval)->right = (yyvsp[(3) - (4)].pval);
            ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 137 "sysy.y"
    {
                  (yyval.pval) = new_ast_node(INIT_LIST_EXPR);
                  (yyval.pval)->left = (yyvsp[(2) - (2)].pval);
            ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 141 "sysy.y"
    {
                  (yyval.pval) = new_ast_node(INIT_LIST_EXPR);
                  (yyval.pval)->left = (yyvsp[(2) - (3)].pval);
                  (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
             ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 147 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(2) - (3)].pval);
      ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 152 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->left = (yyvsp[(1) - (4)].pval);
            (yyval.pval)->right = (yyvsp[(2) - (4)].pval);
            (yyval.pval)->next = (yyvsp[(3) - (4)].pval);
       ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 159 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->left = (yyvsp[(2) - (2)].pval);
      ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 163 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->left = (yyvsp[(2) - (3)].pval);
        ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 168 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->svalue = (yyvsp[(1) - (1)].sval);
      ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 172 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->svalue = (yyvsp[(1) - (3)].sval);
            (yyval.pval)->left = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 177 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->svalue = (yyvsp[(1) - (2)].sval);
            (yyval.pval)->left = (yyvsp[(2) - (2)].pval);      
      ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 182 "sysy.y"
    {
            (yyval.pval) = new_ast_node(VAR_DECL);
            (yyval.pval)->svalue = (yyvsp[(1) - (4)].sval);
            (yyval.pval)->left = (yyvsp[(2) - (4)].pval);
            (yyval.pval)->ivalue = (yyvsp[(3) - (4)].ival);
            (yyval.pval)->right = (yyvsp[(4) - (4)].pval);
      ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 190 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 193 "sysy.y"
    {
            (yyval.pval) = new_ast_node(INIT_LIST_EXPR);
       ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 196 "sysy.y"
    {
            (yyval.pval) = new_ast_node(INIT_LIST_EXPR);
            (yyval.pval)->left = (yyvsp[(2) - (3)].pval);
       ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 200 "sysy.y"
    {
            (yyval.pval) = new_ast_node(INIT_LIST_EXPR);
            (yyval.pval)->left = (yyvsp[(2) - (4)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (4)].pval);
       ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 206 "sysy.y"
    {
            (yyval.pval) = new_ast_node(INIT_LIST_EXPR);
            (yyval.pval)->left = (yyvsp[(2) - (2)].pval);
      ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 210 "sysy.y"
    {
            (yyval.pval) = new_ast_node(INIT_LIST_EXPR);
            (yyval.pval)->left = (yyvsp[(2) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
        ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 216 "sysy.y"
    {
      (yyval.pval) = new_ast_node(FUNCTION_DECL);
      (yyval.pval)->left = (yyvsp[(1) - (5)].pval);
      (yyval.pval)->svalue = (yyvsp[(2) - (5)].sval);
      (yyval.pval)->next = (yyvsp[(5) - (5)].pval);
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 222 "sysy.y"
    {
            (yyval.pval) = new_ast_node(FUNCTION_DECL);
            (yyval.pval)->left = (yyvsp[(1) - (6)].pval);
            (yyval.pval)->svalue = (yyvsp[(2) - (6)].sval);
            (yyval.pval)->right = (yyvsp[(4) - (6)].pval);
            (yyval.pval)->next = (yyvsp[(6) - (6)].pval);
       ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 230 "sysy.y"
    {
      (yyval.pval) = (yyvsp[(1) - (1)].pval);
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 233 "sysy.y"
    {
            (yyval.pval) = new_ast_node(PARM_DECL);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
          ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 239 "sysy.y"
    {
                  (yyval.pval) = new_ast_node(PARM_DECL);
                  (yyval.pval)->left = (yyvsp[(1) - (2)].pval);
                  (yyval.pval)->svalue = (yyvsp[(2) - (2)].sval);
            ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 244 "sysy.y"
    {
             (yyval.pval) = new_ast_node(PARM_DECL);
             (yyval.pval)->left = (yyvsp[(1) - (4)].pval);
             (yyval.pval)->svalue = (yyvsp[(2) - (4)].sval);
         ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 249 "sysy.y"
    {
             (yyval.pval) = new_ast_node(PARM_DECL);
             (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
             (yyval.pval)->svalue = (yyvsp[(2) - (3)].sval);
             (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
         ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 255 "sysy.y"
    {
            (yyval.pval) = new_ast_node(PARM_DECL);
            (yyval.pval)->left = (yyvsp[(1) - (5)].pval);
            (yyval.pval)->svalue = (yyvsp[(2) - (5)].sval);
            (yyval.pval)->right = (yyvsp[(5) - (5)].pval);
         ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 262 "sysy.y"
    {
            (yyval.pval) = new_ast_node(COMPOUND_STMT);
            (yyval.pval)->left = (yyvsp[(2) - (3)].pval);
      ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 266 "sysy.y"
    {
      (yyval.pval) = new_ast_node(NULL_STMT);      
     ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 270 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 273 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (2)].pval);
            (yyval.pval)->next = (yyvsp[(2) - (2)].pval);
      ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 278 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 281 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 285 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->left = (yyvsp[(1) - (4)].pval);
            (yyval.pval)->ivalue = (yyvsp[(2) - (4)].ival);
            (yyval.pval)->right = (yyvsp[(3) - (4)].pval);
      ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 291 "sysy.y"
    {
      (yyval.pval) = new_ast_node(NULL_STMT);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 294 "sysy.y"
    {
        (yyval.pval) = (yyvsp[(1) - (2)].pval);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 297 "sysy.y"
    {
        (yyval.pval) = new_ast_node(COMPOUND_STMT);
        (yyval.pval)->left = (yyvsp[(1) - (1)].pval);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 301 "sysy.y"
    {
      (yyval.pval) = new_ast_node(WHILE_STMT);
      (yyval.pval)->left = (yyvsp[(3) - (5)].pval);
      (yyval.pval)->right = (yyvsp[(5) - (5)].pval);
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 306 "sysy.y"
    {
      (yyval.pval) = new_ast_node(IF_STMT);
      (yyval.pval)->if_cond = (yyvsp[(3) - (5)].pval);
      (yyval.pval)->left = (yyvsp[(5) - (5)].pval);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 311 "sysy.y"
    {
      (yyval.pval) = new_ast_node(IF_STMT);
      (yyval.pval)->if_cond = (yyvsp[(3) - (7)].pval);
      (yyval.pval)->left = (yyvsp[(5) - (7)].pval);
      (yyval.pval)->right = (yyvsp[(7) - (7)].pval);
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 317 "sysy.y"
    {
      (yyval.pval) = new_ast_node(BREAK_STMT);      
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 320 "sysy.y"
    {
      (yyval.pval) = new_ast_node(CONTINUE_STMT);      
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 323 "sysy.y"
    {
            (yyval.pval) = new_ast_node(RETURN_STMT);
            (yyval.pval)->left = (yyvsp[(2) - (3)].pval);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 327 "sysy.y"
    {
            (yyval.pval) = new_ast_node(RETURN_STMT);            
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 333 "sysy.y"
    {
            (yyval.pval) = new_ast_node(DECL_REF_EXPR);
            (yyval.pval)->svalue = (yyvsp[(1) - (1)].sval);
      ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 337 "sysy.y"
    {
            (yyval.pval) = new_ast_node(ARRAY_SUBSCRIPT_EXPR);
            (yyval.pval)->svalue = (yyvsp[(1) - (2)].sval);
            (yyval.pval)->left = (yyvsp[(2) - (2)].pval);
      ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 343 "sysy.y"
    {
            (yyval.pval) = new_ast_node(ARRAY_SUBSCRIPT_EXPR);
            (yyval.pval)->left = (yyvsp[(2) - (3)].pval);
      ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 347 "sysy.y"
    {
            (yyval.pval) = new_ast_node(ARRAY_SUBSCRIPT_EXPR);
            (yyval.pval)->left = (yyvsp[(2) - (4)].pval);
            (yyval.pval)->right = (yyvsp[(4) - (4)].pval);
      ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 353 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(2) - (3)].pval);    
      ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 356 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);    
      ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 359 "sysy.y"
    {
            (yyval.pval)  = new_ast_node(INTEGER_LITERAL);
            (yyval.pval)->ivalue = (yyvsp[(1) - (1)].ival);
      ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 363 "sysy.y"
    {
            (yyval.pval)  = new_ast_node(FLOATING_LITERAL);
            (yyval.pval)->fvalue = (yyvsp[(1) - (1)].fval);
      ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 368 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 371 "sysy.y"
    {
            (yyval.pval) = new_ast_node(CALL_EXPR);
            (yyval.pval)->svalue = (yyvsp[(1) - (3)].sval);
      ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 375 "sysy.y"
    {
            (yyval.pval) = new_ast_node(CALL_EXPR);
            (yyval.pval)->svalue = (yyvsp[(1) - (4)].sval);
            (yyval.pval)->left = (yyvsp[(3) - (4)].pval);
      ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 380 "sysy.y"
    {
            (yyval.pval) = new_ast_node(UNARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(1) - (2)].ival);
            (yyval.pval)->left = (yyvsp[(2) - (2)].pval);
      ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 385 "sysy.y"
    {
            (yyval.pval) = new_ast_node(UNARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(1) - (2)].ival);
            (yyval.pval)->left = (yyvsp[(2) - (2)].pval);
      ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 390 "sysy.y"
    {
            (yyval.pval) = new_ast_node(UNARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(1) - (2)].ival);
            (yyval.pval)->left = (yyvsp[(2) - (2)].pval);
      ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 396 "sysy.y"
    {
            (yyval.pval) = new_ast_node(PARM_DECL);
            (yyval.pval)->left = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 400 "sysy.y"
    {
            (yyval.pval) = new_ast_node(PARM_DECL);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 406 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 409 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 415 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 422 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 429 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 432 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 438 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 445 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 448 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 454 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 460 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 466 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 473 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 476 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 482 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 489 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 492 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 500 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 503 "sysy.y"
    {
            (yyval.pval) = new_ast_node(BINARY_OPERATOR);
            (yyval.pval)->ivalue = (yyvsp[(2) - (3)].ival);
            (yyval.pval)->left = (yyvsp[(1) - (3)].pval);
            (yyval.pval)->right = (yyvsp[(3) - (3)].pval);
      ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 510 "sysy.y"
    {
            (yyval.pval) = (yyvsp[(1) - (1)].pval);
      ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 514 "sysy.y"
    {
            (yyval.pval) = new_ast_node(UNEXPOSED_EXPR);
            (yyval.pval)->ivalue = (yyvsp[(1) - (1)].ival);
      ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 518 "sysy.y"
    {
          (yyval.pval) = new_ast_node(UNEXPOSED_EXPR);
          (yyval.pval)->ivalue = (yyvsp[(1) - (1)].ival);
     ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 522 "sysy.y"
    {
          (yyval.pval) = new_ast_node(UNEXPOSED_EXPR);
          (yyval.pval)->ivalue = (yyvsp[(1) - (1)].ival);
     ;}
    break;



/* Line 1455 of yacc.c  */
#line 2616 "sysy.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 527 "sysy.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}
