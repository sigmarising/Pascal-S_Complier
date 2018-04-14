/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 7 "pasc.y" /* yacc.c:316  */

	#include <stdio.h>
	#include "lex.yy.c"
	#define YYSTYPE int
	typedef pair<Id*, Const_Value*> p_Const
	typedef pair<Id_List*, Type*> p_Var
	typedef pair<int,int> p_Per

	int yyparse(void);
	void yyerror(char *s);
	extern int yylineno;


#line 77 "pasc.tab.c" /* yacc.c:316  */



/* Copy the first part of user declarations.  */

#line 83 "pasc.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "pasc.tab.h".  */
#ifndef YY_YY_PASC_TAB_H_INCLUDED
# define YY_YY_PASC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "pasc.y" /* yacc.c:355  */

	#include <Public_define.h>
	#include <Syntax_Tree.h>

#line 118 "pasc.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    ARRAY = 259,
    BEGIN_L = 260,
    BOOLEAN = 261,
    CASE = 262,
    CHAR = 263,
    CONST = 264,
    DIV = 265,
    DO = 266,
    DOWNTO = 267,
    ELSE = 268,
    END = 269,
    FOR = 270,
    FUNCTION = 271,
    IF = 272,
    INTEGER = 273,
    MOD = 274,
    NOT = 275,
    OF = 276,
    OR = 277,
    PROCEDURE = 278,
    PROGRAM = 279,
    REAL = 280,
    RECORD = 281,
    REPEAT = 282,
    THEN = 283,
    TO = 284,
    TYPE = 285,
    UNTIL = 286,
    VAR = 287,
    WHILE = 288,
    SUBBOUNDARY = 289,
    ASSIGNOP = 290,
    LE_OP = 291,
    GE_OP = 292,
    EQ_OP = 293,
    NE_OP = 294,
    else_conflict = 295,
    DIGITS = 296,
    NUMBER = 297,
    IDENTIFIER = 298,
    LETTER = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "pasc.y" /* yacc.c:355  */

	Programstruct;
	Program_Body;
	Const_Declarations;
	Var_Declarations;
	SubProgram_Declarations;
	Statement_List;
	Common;
	Procedure;
	Function;
	Statement;
	Parameter_List;
	Variable;
	Procedure_Call;
	Function_Call;
	Expression;
	Simple_Expression;
	Term;
	Factor;
	Not;
	Uminus;
	Type;
	Const_Value;
	Assignop;
	If_Then_Else;
	For;
	Parameter;
	Relop;
	Addop;
	Mulop;
	Id;
	Id_List;
	Period;
	Expression_List;
	Program_Head;
	Compound_Statement;
	Const_Declaration;
	Var_Declaration;
	SubProgram_Declaration;
	Subprogram;
	Subprogram_Head;
	Subprogram_Body;
	Formal_Parameter;
	Var_Parameter;
	Value_Parameter;
	Id_Varpart;
	int;
	float;
	string;
	char;
 	

#line 228 "pasc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PASC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 245 "pasc.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    48,    53,    56,    43,    55,    46,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    45,
      41,    40,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   131,   140,   145,   153,   164,   167,   173,
     182,   192,   203,   214,   225,   231,   237,   243,   289,   292,
     299,   303,   310,   316,   326,   329,   332,   335,   342,   346,
     353,   357,   363,   373,   379,   388,   391,   397,   401,   409,
     412,   418,   424,   430,   435,   441,   445,   465,   475,   485,
     495,   505,   518,   525,   549,   552,   558,   569,   582,   585,
     613,   617,   624,   630,   636,   642,   648,   654,   660,   669,
     672,   675,   678,   684,   687,   690,   693,   696,   699,   705,
     710,   719,   731,   740
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ARRAY", "BEGIN_L", "BOOLEAN",
  "CASE", "CHAR", "CONST", "DIV", "DO", "DOWNTO", "ELSE", "END", "FOR",
  "FUNCTION", "IF", "INTEGER", "MOD", "NOT", "OF", "OR", "PROCEDURE",
  "PROGRAM", "REAL", "RECORD", "REPEAT", "THEN", "TO", "TYPE", "UNTIL",
  "VAR", "WHILE", "SUBBOUNDARY", "ASSIGNOP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "'='", "'<'", "'>'", "','", "':'", "';'", "'.'", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "'*'", "'/'", "'-'", "'+'", "else_conflict",
  "DIGITS", "NUMBER", "IDENTIFIER", "LETTER", "$accept", "program",
  "program_head", "program_body", "identifier_list", "const_declarations",
  "const_declaration", "const_variable", "var_declarations",
  "var_declaration", "type", "standard_type", "period",
  "subprogram_declarations", "subprogram", "subprogram_head",
  "formal_parameter", "parameter_list", "parameter", "var_parameter",
  "value_parameter", "subprogram_body", "compound_statement",
  "statement_list", "statement", "variable", "id_varpart",
  "call_procedure_statement", "else_part", "expression_list", "expression",
  "simple_expression", "term", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      61,    60,    62,    44,    58,    59,    46,    40,    41,    91,
      93,   123,   125,    42,    47,    45,    43,   295,   296,   297,
     298,   299
};
# endif

#define YYPACT_NINF -100

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define YYTABLE_NINF -56

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,   -26,    38,    44,    20,  -100,    23,    74,    37,    28,
      50,    76,  -100,    28,  -100,  -100,    17,    42,    62,    43,
      78,     6,    64,    80,    53,    55,  -100,  -100,  -100,  -100,
      86,    66,    28,    -1,    68,    69,    85,    44,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,    42,    82,  -100,  -100,  -100,
    -100,  -100,  -100,    73,    72,   -12,    14,  -100,     5,  -100,
      98,  -100,    87,    87,  -100,    37,  -100,  -100,    77,    66,
     101,   -12,   -12,  -100,    19,  -100,   109,    40,     2,  -100,
     -12,   -12,  -100,  -100,    -1,   -12,   -23,    95,    96,   135,
     108,   -20,  -100,   -12,  -100,    97,   -12,    -1,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,    51,  -100,   -17,  -100,  -100,    28,    75,     9,
    -100,  -100,  -100,    67,  -100,  -100,    88,    89,   122,   115,
    -100,    57,   136,     2,   -15,   -15,   -15,   -15,   -15,   -15,
       2,     2,  -100,  -100,  -100,  -100,  -100,   -12,  -100,  -100,
    -100,    67,   -23,  -100,   103,  -100,   116,    67,   -12,  -100,
      -1,  -100,  -100,  -100,  -100,  -100,    93,  -100,   141,  -100,
    -100,    -1,  -100
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     0,     1,     0,     0,    19,     0,
       0,     0,     2,     0,    31,     6,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,    16,    13,    17,    10,
       0,     0,    18,    52,     0,     0,     0,     8,     4,     5,
       3,    15,    12,    14,    11,     0,     0,    26,    27,    24,
      25,    21,    22,     0,     0,     0,    56,    49,     0,    46,
       0,    48,    36,    36,    30,    19,    32,     9,     0,     0,
       0,     0,     0,    79,    55,    80,     0,    68,    69,    78,
       0,     0,    53,    44,    52,     0,     0,     0,     0,     0,
       0,     0,    20,     0,    83,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,    45,    47,     0,     0,     0,
      38,    39,    40,     0,    34,    43,     0,     0,     0,     0,
      82,     0,    59,    72,    65,    66,    64,    67,    63,    62,
      71,    70,    75,    76,    77,    73,    74,     0,    57,    54,
      41,     0,     0,    35,     0,    29,     0,     0,     0,    81,
      52,    50,    60,    42,    37,    33,     0,    23,     0,    58,
      28,    52,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,  -100,  -100,     4,   117,  -100,   110,    91,  -100,
      84,   -99,  -100,  -100,  -100,  -100,    94,  -100,    10,  -100,
      41,  -100,   -18,  -100,   -82,   -33,  -100,  -100,  -100,   -71,
     -54,     7,   -78,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,   118,     8,    11,    29,    14,    20,
      51,    52,    91,    21,    36,    37,    87,   119,   120,   121,
     122,    66,    57,    58,    59,    75,    82,    61,   161,   112,
     113,    77,    78,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    76,   115,    38,    33,   107,    94,    98,    71,   117,
     114,    33,   108,    16,    54,   132,    55,    19,    95,    83,
     133,   109,    34,   127,   154,   131,   147,   140,   141,    35,
     128,   116,     1,   149,     4,    72,    53,    15,     5,   129,
     105,   106,   142,   143,   144,   145,   146,    73,    74,   -55,
      84,    60,   163,     6,   152,   110,   111,   153,   167,    56,
      22,    80,    98,    81,    60,    23,    96,     9,    81,    13,
      46,   125,    47,    47,    48,    48,    99,   100,   169,   101,
     102,   103,   104,    10,    49,    49,    22,    31,    15,   172,
      17,    50,    50,   162,   147,   105,   106,    24,    25,   148,
     147,    26,    27,    28,   168,   159,   134,   135,   136,   137,
     138,   139,    41,    42,    43,    44,    22,    69,    22,   151,
      12,    18,    30,    32,    39,    40,    45,    60,    62,    63,
      64,    68,    70,    85,    86,    90,    93,    97,    60,   123,
      33,   124,   126,   157,   158,   130,   155,   156,   165,   160,
     166,   170,   171,    92,    65,    67,    89,    88,   150,     0,
       0,     0,   164
};

static const yytype_int16 yycheck[] =
{
      33,    55,    84,    21,     5,     3,    71,    22,    20,    32,
      81,     5,    10,     9,    15,    97,    17,    13,    72,    14,
      98,    19,    16,    43,   123,    96,    43,   105,   106,    23,
      50,    85,    24,    50,    60,    47,    32,    60,     0,    93,
      55,    56,   107,   108,   109,   110,   111,    59,    60,    35,
      45,    84,   151,     9,    45,    53,    54,    48,   157,    60,
      43,    47,    22,    49,    97,    48,    47,    47,    49,    32,
       4,    89,     6,     6,     8,     8,    36,    37,   160,    39,
      40,    41,    42,    60,    18,    18,    43,    44,    60,   171,
      40,    25,    25,   147,    43,    55,    56,    55,    56,    48,
      43,    59,    60,    61,   158,    48,    99,   100,   101,   102,
     103,   104,    59,    60,    59,    60,    43,    44,    43,    44,
      46,    45,    60,    45,    60,    45,    40,   160,    60,    60,
      45,    49,    60,    35,    47,    58,    35,    28,   171,    44,
       5,    45,    34,    21,    29,    48,    58,    58,    45,    13,
      34,    58,    11,    69,    37,    45,    65,    63,   117,    -1,
      -1,    -1,   152
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    63,    64,    60,     0,     9,    65,    67,    47,
      60,    68,    46,    32,    70,    60,    66,    40,    45,    66,
      71,    75,    43,    48,    55,    56,    59,    60,    61,    69,
      60,    44,    45,     5,    16,    23,    76,    77,    84,    60,
      45,    59,    60,    59,    60,    40,     4,     6,     8,    18,
      25,    72,    73,    66,    15,    17,    60,    84,    85,    86,
      87,    89,    60,    60,    45,    67,    83,    69,    49,    44,
      60,    20,    47,    59,    60,    87,    92,    93,    94,    95,
      47,    49,    88,    14,    45,    35,    47,    78,    78,    70,
      58,    74,    72,    35,    95,    92,    47,    28,    22,    36,
      37,    39,    40,    41,    42,    55,    56,     3,    10,    19,
      53,    54,    91,    92,    91,    86,    92,    32,    66,    79,
      80,    81,    82,    44,    45,    84,    34,    43,    50,    92,
      48,    91,    86,    94,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    95,    95,    95,    43,    48,    50,
      82,    44,    45,    48,    73,    58,    58,    21,    29,    48,
      13,    90,    92,    73,    80,    45,    34,    73,    92,    86,
      58,    11,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    74,    74,
      75,    75,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    82,    83,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    87,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     6,     4,     3,     1,     3,     0,     5,
       3,     2,     2,     1,     2,     2,     1,     1,     3,     0,
       5,     3,     1,     6,     1,     1,     1,     1,     5,     3,
       3,     0,     2,     6,     4,     3,     0,     3,     1,     1,
       1,     2,     3,     3,     3,     3,     1,     3,     1,     1,
       5,     8,     0,     2,     3,     0,     1,     4,     2,     0,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     4,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
#line 126 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Programstruct) = new Programstruct((yyvsp[-2].Program_Head)->m_Id, (yyvsp[-2].Program_Head)->m_Id_List, (yyvsp[-1].Program_Body));
	}
#line 1450 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 131 "pasc.y" /* yacc.c:1661  */
    {
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[-4].string);
		tmp -> m_lineno = yylineno;
		tmp -> m_idType = TYPE_ID;
		(yyval.Program_Head) = new Program_Head(tmp, (yyvsp[-2].Id_List));
	}
#line 1462 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 140 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Program_Body) = new Program_Body((yyvsp[-3].Const_Declarations), (yyvsp[-2].Var_Declarations), (yyvsp[-1].SubProgram_Declarations), (yyvsp[0].Compound_Statement));
	}
#line 1470 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 145 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Id_List) = new ID_List();
		(yyval.Id_List) = (yyvsp[-2].Id_List);
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[0].string);
		tmp -> m_lineno = yylineno;
		(yyval.Id_List) -> mv_Id.push_back(tmp);
	}
#line 1483 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 153 "pasc.y" /* yacc.c:1661  */
    {
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[0].string);
		tmp -> m_lineno = yylineno;
		(yyval.Id_List) = new ID_List();
		(yyval.Id_List) -> mv_Id.push_back(tmp);
		(yyval.Id_List) -> m_lineno = yylineno;
	}
#line 1496 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 164 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Const_Declarations) = new Const_Declarations((yyvsp[-1].Const_Declaration) -> mv_Const);
	}
#line 1504 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 167 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Const_Declarations) = new Const_Declarations();
	}
#line 1512 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 173 "pasc.y" /* yacc.c:1661  */
    {

		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[-2].string);
		tmp -> m_lineno = yylineno;

		(yyvsp[-4].Const_Declaration) -> mv_Const.push_back(p_Const(tmp, (yyvsp[0].Const_Value)));
		(yyval.Const_Declaration) = new Const_Declarations((yyvsp[-4].Const_Declaration) -> mv_Const);
	}
#line 1526 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 182 "pasc.y" /* yacc.c:1661  */
    {
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[-2].string);
		tmp -> m_lineno = yylineno;
		(yyval.Const_Declaration) = new Const_Declarations();
		(yyval.Const_Declaration) -> mv_Const.push_back(p_Const(tmp,(yyvsp[0].Const_Value)));
	}
#line 1538 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 192 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Const_Value) = new Const_Value();
		(yyval.Const_Value) -> m_lineno = yylineno;
		(yyval.Const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.Const_Value) -> m_valueType = TYPE_ID;
		(yyval.Const_Value) -> m_isID = true;
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[0].string);
		tmp -> m_lineno = yylineno;
		(yyval.Const_Value) -> mp_ID = tmp;
	}
#line 1554 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 203 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Const_Value) = new Const_Value();
		(yyval.Const_Value) -> m_lineno = yylineno;
		(yyval.Const_Value) -> m_postNeg = CONST_POSTNEG_NEGATIVE;
		(yyval.Const_Value) -> m_valueType = TYPE_ID;
		(yyval.Const_Value) -> m_isID = true;
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[0].string);
		tmp -> m_lineno = yylineno;
		(yyval.Const_Value) -> mp_ID = tmp;	
	}
#line 1570 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 214 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Const_Value) = new Const_Value();
		(yyval.Const_Value) -> m_lineno = yylineno;
		(yyval.Const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.Const_Value) -> m_valueType = TYPE_ID;
		(yyval.Const_Value) -> m_isID = true;
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[0].string);
		tmp -> m_lineno = yylineno;
		(yyval.Const_Value) -> mp_ID = tmp;
	}
#line 1586 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 225 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Const_Value) = new Const_Value();
		(yyval.Const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.Const_Value) -> m_valueType = TYPE_REAL;
		(yyval.Const_Value) -> m_real = (yyvsp[0].float);
	}
#line 1597 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 231 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Const_Value) = new Const_Value();
		(yyval.Const_Value) -> m_postNeg = CONST_POSTNEG_NEGATIVE;
		(yyval.Const_Value) -> m_valueType = TYPE_REAL;
		(yyval.Const_Value) -> m_real = (yyvsp[0].float);	
	}
#line 1608 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 237 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Const_Value) = new Const_Value();
		(yyval.Const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.Const_Value) -> m_valueType = TYPE_REAL;
		(yyval.Const_Value) -> m_real = (yyvsp[0].float);
	}
#line 1619 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 243 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Const_Value) = new Const_Value();
		(yyval.Const_Value) -> m_postNeg = CONST_POSTNEG_NULL;
		(yyval.Const_Value) -> m_valueType = TYPE_CHAR;
		(yyval.Const_Value) -> m_real = (yyvsp[0].char);
	}
#line 1630 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 289 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Var_Declarations) = new Var_Declarations((yyvsp[-1].Var_Declaration) -> mv_Var);
	}
#line 1638 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 292 "pasc.y" /* yacc.c:1661  */
    {
		vector<p_Var> tmp;
		(yyval.Var_Declarations) = new Var_Declarations(tmp);
	}
#line 1647 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 299 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Var_Declaration) = new Var_Declaration((yyvsp[-4].Var_Declaration) -> mv_Var);
		(yyval.Var_Declaration) -> mv_Var.push_back(p_Var((yyvsp[-2].Id_List), (yyvsp[0].Type)));
	}
#line 1656 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 303 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Var_Declaration) = new Var_Declaration();
		(yyval.Var_Declaration) -> mv_Var.push_back(p_Var((yyvsp[-2].Id_List), (yyvsp[0].Type)));
	}
#line 1665 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 310 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Type) = new Type();
		(yyval.Type) -> m_simpleType = (yyvsp[0].int);
		(yyval.Type) -> m_isArray = false;
		(yyval.Type) -> m_lineno = yylineno; 
	}
#line 1676 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 316 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Type) = new Type();
		(yyval.Type) -> m_lineno = yylineno;
		(yyval.Type) -> m_isArray = true;
		(yyval.Type) -> mp_Period = (yyvsp[-3].Period);
		(yyval.Type) -> m_simpleType = (yyvsp[0].int); 
	}
#line 1688 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 326 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.int) = TYPE_INTERGER;
	}
#line 1696 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 329 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.int) = TYPE_REAL;
	}
#line 1704 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 332 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.int) = TYPE_BOOLEAN;
	}
#line 1712 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 335 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.int) = TYPE_CHAR;
	}
#line 1720 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 342 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Period) = new Period((yyvsp[-4].Period) -> mv_dims);
		(yyval.Period) -> mv_dims.push_back(p_Per((yyvsp[-2].int), (yyvsp[0].int)));
	}
#line 1729 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 346 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Period) = new Period();
		(yyval.Period) -> mv_dims.push_back(p_Per((yyvsp[-2].int), (yyvsp[0].int)));
	}
#line 1738 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 353 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.SubProgram_Declarations) = new SubProgram_Declarations((yyvsp[-2].SubProgram_Declarations) -> mv_Common);
		(yyval.SubProgram_Declarations) -> mv_Common.push_back((yyvsp[-1].Subprogram));
	}
#line 1747 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 357 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.SubProgram_Declarations) = new SubProgram_Declarations();
	}
#line 1755 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 363 "pasc.y" /* yacc.c:1661  */
    {
		if((yyvsp[-1].Subprogram_Head) -> Simple_Type == TYPE_NULL) {
			(yyval.Subprogram) = new Procedure(yylineno, (yyvsp[-1].Subprogram_Head) -> m_ID, (yyvsp[-1].Subprogram_Head)-> m_Formal_Parameter, (yyvsp[0].Subprogram_Body) -> m_Const_Declarations, (yyvsp[0].Subprogram_Body) -> m_Var_Declarations, (yyvsp[0].Subprogram_Body)-> m_Compound_Statement);
		}
		else {
			(yyval.Subprogram) = new Function((yyvsp[-1].Subprogram_Head) -> Simple_Type, yylineno, (yyvsp[-1].Subprogram_Head) -> m_ID, (yyvsp[-1].Subprogram_Head)-> m_Formal_Parameter, (yyvsp[0].Subprogram_Body) -> m_Const_Declarations, (yyvsp[0].Subprogram_Body) -> m_Var_Declarations, (yyvsp[0].Subprogram_Body)-> m_Compound_Statement)
		}
	}
#line 1768 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 373 "pasc.y" /* yacc.c:1661  */
    {
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[-4].string);
		tmp -> m_lineno = yylineno;
		(yyval.Subprogram_Head) = new Subprogram_Head(tmp, (yyvsp[-3].Formal_Parameter), (yyvsp[-1].int));
	}
#line 1779 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 379 "pasc.y" /* yacc.c:1661  */
    {
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[-2].string);
		tmp -> m_lineno = yylineno;
		(yyval.Subprogram_Head) = new Subprogram_Head(tmp, (yyvsp[-1].Formal_Parameter), TYPE_NULL);
	}
#line 1790 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 388 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Formal_Parameter) = new Formal_Parameter((yyvsp[-1].Parameter_List));
	}
#line 1798 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 391 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Formal_Parameter) = new Formal_Parameter(NULL);
	}
#line 1806 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 397 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Parameter_List) = new Parameter_List(yylineno, (yyvsp[-2].Parameter_List) -> mv_Patameter);
		(yyval.Parameter_List) -> mv_Patameter.push_back((yyvsp[0].Parameter));
	}
#line 1815 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 401 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Parameter_List) = new Parameter_List()
		(yyval.Parameter_List) -> m_lineno = yylineno;
		(yyval.Parameter_List) -> mv_Patameter.push_back((yyvsp[0].Parameter));
	}
#line 1825 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 409 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Parameter) = new Parameter(true, yylineno, (yyvsp[0].Var_Parameter) -> m_Value_Parameter -> m_Id_List);
	}
#line 1833 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 412 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Parameter) = new Parameter(false, yylineno, (yyvsp[0].Value_Parameter) -> m_Id_List);
	}
#line 1841 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 418 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Var_Parameter) = new Var_Parameter((yyvsp[0].Value_Parameter));
	}
#line 1849 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 424 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Value_Parameter) = new Value_Parameter((yyvsp[-2].Id_List), (yyvsp[0].int));
	}
#line 1857 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 430 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Subprogram_Body) = new Subprogram_Body((yyvsp[-2].Const_Declarations), (yyvsp[-1].Var_Declarations), (yyvsp[0].Compound_Statement));
	}
#line 1865 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 435 "pasc.y" /* yacc.c:1661  */
    {
		compound_statement = new Compound_Statement((yyvsp[-1].Statement_List));
	}
#line 1873 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 441 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Statement_List) = new Statement_List((yyvsp[-2].Statement_List) -> mv_Statement);
		(yyval.Statement_List) -> mv_Statement.push_back((yyvsp[0].Statement));
	}
#line 1882 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 445 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Statement_List) = new Statement_List();
		(yyval.Statement_List) -> mv_Statement.push_back((yyvsp[0].Statement));
	}
#line 1891 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 465 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Statement) = new Statement();
		(yyval.Statement) -> m_stateType = STATEMENT_ASSIGN;
		(yyval.Statement) -> m_lineno = yylineno;
		(yyval.Statement) -> mp_Assignop = Assignop((yyvsp[-2].Variable), (yyvsp[0].Expression));
		(yyval.Statement) -> mp_Procedure_call = NULL;
		(yyval.Statement) -> Statement_List = NULL;
		(yyval.Statement) -> mp_If_Then_Else = NULL;
		(yyval.Statement) -> mp_For = NULL;
	}
#line 1906 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 475 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Statement) = new Statement();
		(yyval.Statement) -> m_stateType = STATEMENT_PROCEDURE;
		(yyval.Statement) -> m_lineno = yylineno;
		(yyval.Statement) -> mp_Procedure_call = (yyvsp[0].Procedure_Call);
		(yyval.Statement) -> mp_Assignop = NULL;
		(yyval.Statement) -> Statement_List = NULL;
		(yyval.Statement) -> mp_If_Then_Else = NULL;
		(yyval.Statement) -> mp_For = NULL;
	}
#line 1921 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 485 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Statement) = new Statement();
		(yyval.Statement) -> m_stateType = STATEMENT_COMPOUND;
		(yyval.Statement) -> m_lineno = yylineno;
		(yyval.Statement) -> Statement_List = (yyvsp[0].Compound_Statement);
		(yyval.Statement) -> mp_Assignop = NULL;
		(yyval.Statement) -> mp_Procedure_call = NULL;
		(yyval.Statement) -> mp_If_Then_Else = NULL;
		(yyval.Statement) -> mp_For = NULL;
	}
#line 1936 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 495 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Statement) = new Statement();
		(yyval.Statement) -> m_stateType = STATEMENT_IF;
		(yyval.Statement) -> m_lineno = yylineno;
		(yyval.Statement) -> mp_If_Then_Else = new If_Then_Else((yyvsp[-3].Expression), (yyvsp[-1].Statement), (yyvsp[0].Statement));
		(yyval.Statement) -> mp_Assignop = NULL;
		(yyval.Statement) -> mp_Procedure_call = NULL;
		(yyval.Statement) -> Statement_List = NULL;
		(yyval.Statement) -> mp_For = NULL;
	}
#line 1951 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 505 "pasc.y" /* yacc.c:1661  */
    {
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[-6].string);
		tmp -> m_lineno = yylineno;
		(yyval.Statement) = new Statement();
		(yyval.Statement) -> m_stateType = STATEMENT_FOR;
		(yyval.Statement) -> m_lineno = yylineno;
		(yyval.Statement) -> mp_For = new For(tmp, (yyvsp[-4].Expression), (yyvsp[-2].Expression), (yyvsp[0].Statement));
		(yyval.Statement) -> mp_Assignop = NULL;
		(yyval.Statement) -> mp_Procedure_call = NULL;
		(yyval.Statement) -> Statement_List = NULL;
		(yyval.Statement) -> mp_If_Then_Else = NULL;
	}
#line 1969 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 518 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Statement) = new Statement()
	}
#line 1977 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 525 "pasc.y" /* yacc.c:1661  */
    {
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[-1].string);
		tmp -> m_lineno = yylineno;
		(yyval.Variable) = new Variable();
		(yyval.Variable) -> mp_Id = tmp;
		(yyval.Variable) -> m_lineno = yylineno;
		if((yyvsp[0].Id_Varpart) -> m_Expression_List != NULL){
			(yyval.Variable) -> m_isArray = true;
			(yyval.Variable) -> mp_Expression_List = (yyvsp[0].Id_Varpart) -> m_Expression_List;
		}else {
			(yyval.Variable) -> m_isArray =false;
			(yyval.Variable) -> mp_Expression_List = NULL;
		}
	}
#line 1997 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 549 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Id_Varpart) = new Id_Varpart((yyvsp[-1].Expression_List));
	}
#line 2005 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 552 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Id_Varpart) = new Id_Varpart(NULL);
	}
#line 2013 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 558 "pasc.y" /* yacc.c:1661  */
    {
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[0].string);
		tmp -> m_lineno = yylineno;
		(yyval.Procedure_Call) = new Procedure_Call();
		(yyval.Procedure_Call) -> m_lineno = yylineno;
		(yyval.Procedure_Call) -> m_expNum = 0;
		(yyval.Procedure_Call) -> mp_Id = (yyvsp[0].string);
		(yyval.Procedure_Call) -> mp_Expression_List = NULL；

	}
#line 2029 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 569 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Procedure_Call) = new Procedure_Call();
		(yyval.Procedure_Call) -> m_lineno = yylineno;
		(yyval.Procedure_Call) -> m_expNum = (yyvsp[-1].Expression_List) -> mv_Expression.size();
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[-3].string);
		tmp -> m_lineno = yylineno;
		(yyval.Procedure_Call) -> mp_Id = tmp;
		(yyval.Procedure_Call) -> mp_Expression_List = (yyvsp[-1].Expression_List)；
	}
#line 2044 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 582 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Statement) = (yyvsp[0].Statement);
	}
#line 2052 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 585 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Statement) = NULL;
	}
#line 2060 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 613 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Expression_List) = new Expression_List((yyvsp[-2].Expression_List) -> mv_Expression, (yyvsp[-2].Expression_List) -> mv_Type);
		(yyval.Expression_List) -> mv_Expression.push_back((yyvsp[0].Expression));
	}
#line 2069 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 617 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Expression_List) = new Expression_List();
		(yyval.Expression_List) -> mv_Expression.push_back((yyvsp[0].Expression));
	}
#line 2078 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 624 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Expression) = new Expression();
		(yyval.Expression) -> m_lineno = yylineno;
		(yyval.Expression) -> mp_Simple_Expression = NULL;
		(yyval.Expression) -> mp_Relop = new Relop(RELOP_LARGE, yylineno, (yyvsp[-2].Simple_Expression), (yyvsp[0].Simple_Expression));
	}
#line 2089 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 630 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Expression) = new Expression();
		(yyval.Expression) -> m_lineno = yylineno;
		(yyval.Expression) -> mp_Simple_Expression = NULL;
		(yyval.Expression) -> mp_Relop = new Relop(RELOP_LESS, yylineno, (yyvsp[-2].Simple_Expression), (yyvsp[0].Simple_Expression));
	}
#line 2100 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 636 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Expression) = new Expression();
		(yyval.Expression) -> m_lineno = yylineno;
		(yyval.Expression) -> mp_Simple_Expression = NULL;
		(yyval.Expression) -> mp_Relop = new Relop(RELOP_NOT_EQUAL, yylineno, (yyvsp[-2].Simple_Expression), (yyvsp[0].Simple_Expression));
	}
#line 2111 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 642 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Expression) = new Expression();
		(yyval.Expression) -> m_lineno = yylineno;
		(yyval.Expression) -> mp_Simple_Expression = NULL;
		(yyval.Expression) -> mp_Relop = new Relop(RELOP_LESS_EQUAL, yylineno, (yyvsp[-2].Simple_Expression), (yyvsp[0].Simple_Expression));
	}
#line 2122 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 648 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Expression) = new Expression();
		(yyval.Expression) -> m_lineno = yylineno;
		(yyval.Expression) -> mp_Simple_Expression = NULL;
		(yyval.Expression) -> mp_Relop = new Relop(RELOP_LARGE_EQUAL, yylineno, (yyvsp[-2].Simple_Expression), (yyvsp[0].Simple_Expression));
	}
#line 2133 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 654 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Expression) = new Expression();
		(yyval.Expression) -> m_lineno = yylineno;
		(yyval.Expression) -> mp_Simple_Expression = NULL;
		(yyval.Expression) -> mp_Relop = new Relop(RELOP_EQUAL, yylineno, (yyvsp[-2].Simple_Expression), (yyvsp[0].Simple_Expression));
	}
#line 2144 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 660 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Expression) = new Expression();
		(yyval.Expression) -> m_lineno = yylineno;
		(yyval.Expression) -> mp_Simple_Expression = (yyvsp[0].Simple_Expression);
		(yyval.Expression) -> mp_Relop = NULL;
	}
#line 2155 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 669 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Simple_Expression) = new Simple_Expression(yylineno, NULL, (yyvsp[0].Term));
	}
#line 2163 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 672 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Simple_Expression) = new Simple_Expression(yylineno, new Addop(ADDOP_ADD, yylineno, (yyvsp[-2].Simple_Expression), (yyvsp[0].Term)),NULL);
	}
#line 2171 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 675 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Simple_Expression) = new Simple_Expression(yylineno, new Addop(ADDOP_SUB, yylineno, (yyvsp[-2].Simple_Expression), (yyvsp[0].Term)),NULL);
	}
#line 2179 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 678 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Simple_Expression) = new Simple_Expression(yylineno, new Addop(ADDOP_OR, yylineno, (yyvsp[-2].Simple_Expression), (yyvsp[0].Term)),NULL);
	}
#line 2187 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 684 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Term) = new Term(yylineno, new Mulop(MULOP_MULTIPLY, yylineno, (yyvsp[-2].Term), (yyvsp[0].Factor)), NULL);
	}
#line 2195 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 687 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Term) = new Term(yylineno, new Mulop(MULOP_REAL_DIV, yylineno, (yyvsp[-2].Term), (yyvsp[0].Factor)), NULL);
	}
#line 2203 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 690 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Term) = new Term(yylineno, new Mulop(MULOP_AND, yylineno, (yyvsp[-2].Term), (yyvsp[0].Factor)), NULL);
	}
#line 2211 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 693 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Term) = new Term(yylineno, new Mulop(MULOP_INT_DIV, yylineno, (yyvsp[-2].Term), (yyvsp[0].Factor)), NULL);
	}
#line 2219 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 696 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Term) = new Term(yylineno, new Mulop(MULOP_MOD, yylineno, (yyvsp[-2].Term), (yyvsp[0].Factor)), NULL);
	}
#line 2227 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 699 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Term) = new Term(yylineno, NULL, (yyvsp[0].Factor));
	}
#line 2235 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 705 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Factor) = new Factor();
		(yyval.Factor) -> m_lineno = yylineno;
		(yyval.Factor) -> m_real((yyvsp[0].float));
	}
#line 2245 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 710 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Factor) = new Factor();
		(yyval.Factor) -> m_lineno = yylineno;
		(yyval.Factor) -> mp_Variable = (yyvsp[0].Variable);
		(yyval.Factor) -> mp_Function_Call = NULL;
		(yyval.Factor) -> mp_Expression = NULL;
		(yyval.Factor) -> mp_Not = NULL;
		(yyval.Factor) -> mp_Uminus = NULL;
	}
#line 2259 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 719 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Factor) = new Factor();
		(yyval.Factor) -> m_lineno = yylineno;
		(yyval.Factor) -> mp_Variable = NULL;
		Id* tmp = new Id();
		tmp -> m_name = (yyvsp[-3].string);
		tmp -> m_lineno = yylineno;
		(yyval.Factor) -> mp_Function_Call = new Function_Call((yyvsp[-1].Expression_List) -> mv_Expression.size(), yylineno, tmp, (yyvsp[-1].Expression_List));
		(yyval.Factor) -> mp_Expression = NULL;
		(yyval.Factor) -> mp_Not = NULL;
		(yyval.Factor) -> mp_Uminus = NULL;
	}
#line 2276 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 731 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Factor) = new Factor();
		(yyval.Factor) -> m_lineno = yylineno;
		(yyval.Factor) -> mp_Variable = NULL;
		(yyval.Factor) -> mp_Function_Call = NULL;
		(yyval.Factor) -> mp_Expression = (yyvsp[-1].Expression);
		(yyval.Factor) -> mp_Not = NULL;
		(yyval.Factor) -> mp_Uminus = NULL;
	}
#line 2290 "pasc.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 740 "pasc.y" /* yacc.c:1661  */
    {
		(yyval.Factor) = new Factor();
		(yyval.Factor) -> m_lineno = yylineno;
		(yyval.Factor) -> mp_Variable = NULL;
		(yyval.Factor) -> mp_Function_Call = NULL;
		(yyval.Factor) -> mp_Expression = NULL;
		(yyval.Factor) -> mp_Not = (yyvsp[0].Factor);
		(yyval.Factor) -> mp_Uminus = NULL;
	}
#line 2304 "pasc.tab.c" /* yacc.c:1661  */
    break;


#line 2308 "pasc.tab.c" /* yacc.c:1661  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
  return yyresult;
}
#line 750 "pasc.y" /* yacc.c:1906  */



int main() {
    return yyparse();
}


void yyerror(char* s) {
	fprintf(stderr,"%s",s);
}
