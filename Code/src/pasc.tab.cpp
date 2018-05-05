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
#line 6 "pasc.y" /* yacc.c:316  */

	#include "../yacc/lex.yy.c"
	#include <stdio.h>
	#include <string>
	#include <iostream>

	typedef pair<Id*, Const_Value*> p_Const;
	typedef pair<Id_List*, Type*> p_Var;
	typedef pair<int,int> p_Per;

	Programstruct* ROOT;			//语法树根节点
	int errorNum = 0;				//错误数量

	int yyparse(void);				//语法分析接口
	void yyerror(const char* s);	//输出错误信息
	extern int yylineno;			//行号信息

	#define YYERROR_VERBOSE 1		//输出详细的错误信息
	extern int yydebug;
	#define YYDEBUG 1				//输出yacc的分析过程

	using namespace std;

#line 87 "pasc.tab.c" /* yacc.c:316  */



/* Copy the first part of user declarations.  */

#line 93 "pasc.tab.c" /* yacc.c:339  */

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
#line 1 "pasc.y" /* yacc.c:355  */

	#include "Public_define.h"
	#include "Syntax_Tree.h"

#line 128 "pasc.tab.c" /* yacc.c:355  */

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
    LETTER = 299,
    BOOL = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "pasc.y" /* yacc.c:355  */

	Programstruct* programstruct;
	Program_Body* program_Body;
	Const_Declarations* const_Declarations;
	Var_Declarations* var_Declarations;
	SubProgram_Declarations* subProgram_Declarations;
	Statement_List* statement_List;
	Common* common;
	Procedure* procedure;
	Function* function;
	Statement* statement;
	Parameter_List* parameter_List;
	Variable* variable;
	Procedure_Call* procedure_Call;
	Function_Call* function_Call;
	Expression* expression;
	Simple_Expression* simple_Expression;
	Term* term;
	Factor* factor;
	Not* NOt;
	Uminus* uminus;
	Type* type;
	Const_Value* const_Value;
	Assignop* assignop;
	If_Then_Else* if_Then_Else;
	For* FOr;
	Parameter* parameter;
	Relop* relop;
	Addop* addop;
	Mulop* mulop;
	Id* id;
	Id_List* id_List;
	Period* period;
	Expression_List* expression_List;
	Program_Head* program_Head;
	Compound_Statement* compound_Statement;
	Const_Declaration* const_Declaration;
	Var_Declaration* var_Declaration;
	SubProgram_Declaration* subProgram_Declaration;
	Subprogram* subprogram;
	Subprogram_Head* subprogram_Head;
	Subprogram_Body* subprogram_Body;
	Formal_Parameter* formal_Parameter;
	Var_Parameter* var_Parameter;
	Value_Parameter* value_Parameter;
	Id_Varpart* id_Varpart;
	int m_int;
	float m_float;
	std::string* m_str;
	char m_char;
 	bool m_bool;

#line 239 "pasc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PASC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 256 "pasc.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      35,    36,    37,    38,    39,    57,    58,    59,    60,    61,
      62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   140,   140,   146,   153,   156,   161,   165,   170,   178,
     194,   197,   203,   211,   221,   232,   243,   254,   260,   266,
     272,   278,   284,   290,   296,   304,   307,   314,   318,   325,
     331,   338,   344,   347,   350,   353,   360,   364,   370,   373,
     376,   386,   390,   396,   406,   412,   418,   422,   429,   432,
     438,   442,   450,   455,   462,   468,   474,   477,   482,   488,
     493,   498,   501,   508,   519,   529,   539,   549,   552,   565,
     568,   571,   578,   597,   600,   606,   617,   630,   633,   641,
     645,   652,   658,   664,   670,   676,   682,   688,   697,   700,
     703,   706,   712,   715,   718,   721,   724,   727,   732,   735,
     740,   746,   752,   758,   764,   774,   787,   800,   810
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
  "DIGITS", "NUMBER", "IDENTIFIER", "LETTER", "BOOL", "$accept", "program",
  "program_head", "program_body", "identifier_list", "const_declarations",
  "const_declaration", "const_variable", "var_declarations",
  "var_declaration", "type", "standard_type", "period", "SDIGITS",
  "subprogram_declarations", "subprogram", "subprogram_head",
  "formal_parameter", "parameter_list", "parameter", "var_parameter",
  "value_parameter", "subprogram_body", "compound_statement",
  "statement_list", "statement", "variable", "id_varpart",
  "call_procedure_statement", "else_part", "expression_list", "expression",
  "simple_expression", "term", "SNUMBER", "factor", YY_NULLPTR
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
     298,   299,   300
};
# endif

#define YYPACT_NINF -150

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define YYTABLE_NINF -75

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,  -150,     6,    30,   196,  -150,    -8,  -150,    49,    19,
      36,    67,    54,    67,    92,    93,  -150,    54,  -150,  -150,
      11,  -150,   162,    74,   159,   107,   103,    95,   127,   103,
     120,   140,  -150,  -150,  -150,  -150,  -150,  -150,   143,   152,
      54,    18,    17,    21,   144,    20,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,   162,  -150,   155,  -150,
    -150,  -150,  -150,  -150,  -150,   163,  -150,    25,    14,    78,
    -150,    -3,  -150,   157,  -150,   166,   161,   171,   161,  -150,
      49,    67,  -150,  -150,   113,   152,   186,   190,   198,   126,
     126,   105,   169,  -150,  -150,   -35,  -150,  -150,  -150,  -150,
     207,   154,   112,  -150,  -150,   126,   126,  -150,  -150,    50,
     126,  -150,   -22,   192,  -150,   193,    67,   232,   181,    10,
     206,  -150,   126,   126,    31,  -150,   194,  -150,  -150,  -150,
      89,    31,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,    75,  -150,   111,  -150,
    -150,  -150,    54,   170,   -17,  -150,  -150,  -150,    99,  -150,
     232,  -150,   113,   220,   113,   233,   214,   234,  -150,  -150,
     119,   234,   112,    -6,    -6,    -6,    -6,    -6,    -6,   112,
     112,  -150,  -150,  -150,  -150,  -150,   126,  -150,  -150,  -150,
      99,   -22,  -150,   200,  -150,   212,    99,  -150,    31,    42,
      31,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   113,  -150,
    -150,   237,   238,  -150,  -150,    31,    31,  -150,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,     4,     0,     1,    11,     0,
       0,    26,     0,    26,     0,     0,     2,     0,    42,     9,
       0,    42,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    19,    16,    23,    24,    13,     0,     0,
      25,     0,     0,     0,     0,     0,     6,     8,     3,     7,
      21,    18,    15,    20,    17,    14,     0,    31,     0,    34,
      35,    32,    33,    28,    29,     0,    62,     0,     0,    75,
      65,     0,    60,     0,    64,     0,    49,     0,    49,    41,
      11,    26,    43,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    98,    74,   102,   103,   100,   104,
       0,    87,    88,   101,    97,     0,     0,    72,    58,     0,
       0,    46,     0,     0,    47,     0,    26,     0,     0,     0,
       0,    27,     0,     0,    71,   108,     0,    40,    99,    39,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,    61,
      59,    63,     0,     0,     0,    51,    52,    53,     0,    45,
       0,    56,     0,     0,     0,     0,     0,    78,   107,   106,
       0,    78,    91,    84,    85,    83,    86,    82,    81,    90,
      89,    94,    95,    96,    92,    93,     0,    76,    73,    54,
       0,     0,    48,     0,    57,     0,     0,    37,    71,     0,
      71,    67,   105,    66,    79,    55,    50,    44,     0,    30,
      69,     0,     0,    77,    36,    71,    71,    70,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,  -150,    76,     0,  -150,   195,   -10,  -150,
     165,  -149,  -150,   -78,   231,  -150,  -150,   175,  -150,    63,
    -150,   104,  -150,   -25,  -150,  -104,   -41,  -150,  -150,    84,
     -93,   -66,    96,   -11,  -150,    -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    10,   153,    11,    15,    37,    18,    25,
      63,    64,   119,    98,    26,    44,    45,   113,   154,   155,
     156,   157,    82,    70,    71,    72,    99,   107,    74,   201,
     146,   147,   101,   102,   103,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    46,   100,    21,    49,   150,   120,     5,    13,   193,
     152,   108,   130,   148,   106,    88,   132,     1,    75,    66,
     167,    80,    77,    41,   126,   -11,    86,   171,   191,     9,
       7,   192,   -71,    67,    89,    68,    41,   170,    19,    12,
       2,   205,   109,   211,   151,    81,    67,   209,    68,   139,
     140,   149,   -11,   162,    27,    41,   165,   166,     9,    28,
     163,    90,    89,   -71,   -71,    67,     6,    68,    73,    91,
      92,   117,    93,    94,    95,    96,    97,    76,    69,    14,
     116,    78,    16,    73,   195,    87,   197,   125,    20,    90,
      73,    69,   161,    24,   210,   -71,   213,    91,    92,    17,
      93,    94,    95,    96,    97,    59,   160,    60,    41,    89,
      69,   217,   218,   -74,    19,   141,    65,    61,   186,    42,
     204,   172,   142,   187,    62,   105,    43,   106,   179,   180,
     214,   143,    22,   212,    38,   194,    90,   169,    23,   181,
     182,   183,   184,   185,    91,    92,    89,    93,    94,    95,
      96,    97,    40,    57,   186,    47,    58,    73,    59,    73,
      60,   188,   186,   127,   128,   144,   145,   202,   118,    92,
      61,    93,    48,    90,    73,    73,   132,    62,    50,    51,
      52,    91,    92,    56,    93,    94,    95,    96,    97,    79,
     133,   134,   110,   135,   136,   137,   138,     8,    53,    54,
      55,   -11,    27,    39,    84,     9,    27,    85,   112,   139,
     140,   111,   -11,    27,   190,   122,   114,    30,    31,   -11,
      32,    33,    34,    35,    36,   123,   124,   129,   -11,   173,
     174,   175,   176,   177,   178,   131,   158,    41,   159,   127,
     164,   196,   168,   199,   198,   207,   208,   200,   215,   216,
     121,    83,    29,   115,   206,   203,   189
};

static const yytype_uint8 yycheck[] =
{
      41,    26,    68,    13,    29,   109,    84,     1,     8,   158,
      32,    14,    47,   106,    49,     1,    22,     1,     1,     1,
     124,     1,     1,     5,    90,     5,     1,   131,    45,     9,
       0,    48,    14,    15,    20,    17,     5,   130,    60,    47,
      24,   190,    45,     1,   110,    45,    15,   196,    17,    55,
      56,     1,    32,    43,    43,     5,   122,   123,     9,    48,
      50,    47,    20,    45,    14,    15,    60,    17,   109,    55,
      56,    81,    58,    59,    60,    61,    62,    60,    60,    60,
      80,    60,    46,   124,   162,    60,   164,    89,    12,    47,
     131,    60,   117,    17,   198,    45,   200,    55,    56,    32,
      58,    59,    60,    61,    62,     6,   116,     8,     5,    20,
      60,   215,   216,    35,    60,     3,    40,    18,    43,    16,
     186,   132,    10,    48,    25,    47,    23,    49,   139,   140,
     208,    19,    40,   199,    60,   160,    47,    48,    45,   141,
     142,   143,   144,   145,    55,    56,    20,    58,    59,    60,
      61,    62,    45,     1,    43,    60,     4,   198,     6,   200,
       8,    50,    43,    58,    59,    53,    54,    48,    55,    56,
      18,    58,    45,    47,   215,   216,    22,    25,    58,    59,
      60,    55,    56,    40,    58,    59,    60,    61,    62,    45,
      36,    37,    35,    39,    40,    41,    42,     1,    58,    59,
      60,     5,    43,    44,    49,     9,    43,    44,    47,    55,
      56,    45,    16,    43,    44,    29,    45,    55,    56,    23,
      58,    59,    60,    61,    62,    35,    28,    58,    32,   133,
     134,   135,   136,   137,   138,    28,    44,     5,    45,    58,
      34,    21,    48,    29,    11,    45,    34,    13,    11,    11,
      85,    56,    21,    78,   191,   171,   152
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    24,    64,    65,     1,    60,     0,     1,     9,
      66,    68,    47,    68,    60,    69,    46,    32,    71,    60,
      67,    71,    40,    45,    67,    72,    77,    43,    48,    77,
      55,    56,    58,    59,    60,    61,    62,    70,    60,    44,
      45,     5,    16,    23,    78,    79,    86,    60,    45,    86,
      58,    59,    60,    58,    59,    60,    40,     1,     4,     6,
       8,    18,    25,    73,    74,    67,     1,    15,    17,    60,
      86,    87,    88,    89,    91,     1,    60,     1,    60,    45,
       1,    68,    85,    70,    49,    44,     1,    60,     1,    20,
      47,    55,    56,    58,    59,    60,    61,    62,    76,    89,
      94,    95,    96,    97,    98,    47,    49,    90,    14,    45,
      35,    45,    47,    80,    45,    80,    68,    71,    55,    75,
      76,    73,    29,    35,    28,    98,    94,    58,    59,    58,
      47,    28,    22,    36,    37,    39,    40,    41,    42,    55,
      56,     3,    10,    19,    53,    54,    93,    94,    93,     1,
      88,    94,    32,    67,    81,    82,    83,    84,    44,    45,
      71,    86,    43,    50,    34,    94,    94,    88,    48,    48,
      93,    88,    96,    95,    95,    95,    95,    95,    95,    96,
      96,    98,    98,    98,    98,    98,    43,    48,    50,    84,
      44,    45,    48,    74,    86,    76,    21,    76,    11,    29,
      13,    92,    48,    92,    94,    74,    82,    45,    34,    74,
      88,     1,    94,    88,    76,    11,    11,    88,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    78,    79,    79,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    84,    85,    85,    86,    87,
      87,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    95,    96,    96,    96,    96,    96,    96,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     6,     2,     1,     4,     5,     3,     1,
       3,     0,     5,     3,     2,     2,     1,     2,     2,     1,
       2,     2,     1,     1,     1,     3,     0,     5,     3,     1,
       6,     1,     1,     1,     1,     1,     5,     3,     1,     2,
       2,     3,     0,     2,     6,     4,     3,     3,     3,     0,
       3,     1,     1,     1,     2,     3,     3,     4,     3,     3,
       1,     3,     1,     3,     1,     1,     5,     5,     8,     6,
       8,     0,     2,     3,     0,     1,     4,     2,     0,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     3,     3,     2
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
#line 140 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.programstruct) = new Programstruct((yyvsp[-2].program_Head)->m_Id, (yyvsp[-2].program_Head)->m_Id_List, (yyvsp[-1].program_Body));
		ROOT = (yyval.programstruct);
	}
#line 1499 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 146 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-4].m_str));
		tmp -> m_lineno = yylineno;
		tmp -> m_idType = TYPE_ID;
		(yyval.program_Head) = new Program_Head(tmp, (yyvsp[-2].id_List));
	}
#line 1511 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 153 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.program_Head) = new Program_Head(NULL,NULL);
	}
#line 1519 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 156 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.program_Head) = new Program_Head(NULL,NULL);
	}
#line 1527 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 161 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.program_Body) = new Program_Body((yyvsp[-3].const_Declarations), (yyvsp[-2].var_Declarations), (yyvsp[-1].subProgram_Declarations), (yyvsp[0].compound_Statement));
	}
#line 1535 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 165 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.program_Body) = new Program_Body();
	}
#line 1543 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 170 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.id_List) = new Id_List();
		(yyval.id_List) = (yyvsp[-2].id_List);
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[0].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.id_List) -> mv_Id.push_back(tmp);
	}
#line 1556 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 178 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[0].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.id_List) = new Id_List();
		(yyval.id_List) -> mv_Id.push_back(tmp);
		(yyval.id_List) -> m_lineno = yylineno;
	}
#line 1569 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 194 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Declarations) = new Const_Declarations((yyvsp[-1].const_Declaration) -> mv_Const);
	}
#line 1577 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 197 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Declarations) = new Const_Declarations();
	}
#line 1585 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 203 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-2].m_str));
		tmp -> m_lineno = yylineno;

		(yyvsp[-4].const_Declaration) -> mv_Const.push_back(p_Const(tmp, (yyvsp[0].const_Value)));
		(yyval.const_Declaration) = new Const_Declaration((yyvsp[-4].const_Declaration) -> mv_Const);
	}
#line 1598 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 211 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-2].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.const_Declaration) = new Const_Declaration();
		(yyval.const_Declaration) -> mv_Const.push_back(p_Const(tmp,(yyvsp[0].const_Value)));
	}
#line 1610 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 221 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_lineno = yylineno;
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.const_Value) -> m_valueType = TYPE_ID;
		(yyval.const_Value) -> m_isId = true;
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[0].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.const_Value) -> mp_Id = tmp;
	}
#line 1626 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 232 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_lineno = yylineno;
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_NEGATIVE;
		(yyval.const_Value) -> m_valueType = TYPE_ID;
		(yyval.const_Value) -> m_isId = true;
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[0].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.const_Value) -> mp_Id = tmp;	
	}
#line 1642 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 243 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_lineno = yylineno;
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.const_Value) -> m_valueType = TYPE_ID;
		(yyval.const_Value) -> m_isId = true;
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[0].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.const_Value) -> mp_Id = tmp;
	}
#line 1658 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 254 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.const_Value) -> m_valueType = TYPE_REAL;
		(yyval.const_Value) -> m_real = (yyvsp[0].m_float);
	}
#line 1669 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 260 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_NEGATIVE;
		(yyval.const_Value) -> m_valueType = TYPE_REAL;
		(yyval.const_Value) -> m_real = (yyvsp[0].m_float);	
	}
#line 1680 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 266 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.const_Value) -> m_valueType = TYPE_REAL;
		(yyval.const_Value) -> m_real = (yyvsp[0].m_float);
	}
#line 1691 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 272 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.const_Value) -> m_valueType = TYPE_INTERGER;
		(yyval.const_Value) -> m_int = (yyvsp[0].m_int);
	}
#line 1702 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 278 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_NEGATIVE;
		(yyval.const_Value) -> m_valueType = TYPE_INTERGER;
		(yyval.const_Value) -> m_int = (yyvsp[0].m_int);
	}
#line 1713 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 284 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.const_Value) -> m_valueType = TYPE_INTERGER;
		(yyval.const_Value) -> m_int = (yyvsp[0].m_int);
	}
#line 1724 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 290 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_NULL;
		(yyval.const_Value) -> m_valueType = TYPE_CHAR;
		(yyval.const_Value) -> m_char = (yyvsp[0].m_char);
	}
#line 1735 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 296 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_NULL;
		(yyval.const_Value) -> m_valueType = TYPE_BOOLEAN;
		(yyval.const_Value) -> m_bool = (yyvsp[0].m_bool);
	}
#line 1746 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 304 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.var_Declarations) = new Var_Declarations((yyvsp[-1].var_Declaration) -> mv_Var);
	}
#line 1754 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 307 "pasc.y" /* yacc.c:1646  */
    {
		vector<p_Var> tmp;
		(yyval.var_Declarations) = new Var_Declarations(tmp);
	}
#line 1763 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 314 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.var_Declaration) = new Var_Declaration((yyvsp[-4].var_Declaration) -> mv_Var);
		(yyval.var_Declaration) -> mv_Var.push_back(p_Var((yyvsp[-2].id_List), (yyvsp[0].type)));
	}
#line 1772 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 318 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.var_Declaration) = new Var_Declaration();
		(yyval.var_Declaration) -> mv_Var.push_back(p_Var((yyvsp[-2].id_List), (yyvsp[0].type)));
	}
#line 1781 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 325 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.type) = new Type();
		(yyval.type) -> m_simpleType = (yyvsp[0].m_int);
		(yyval.type) -> m_isArray = false;
		(yyval.type) -> m_lineno = yylineno; 
	}
#line 1792 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 331 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.type) = new Type();
		(yyval.type) -> m_lineno = yylineno;
		(yyval.type) -> m_isArray = true;
		(yyval.type) -> mp_Period = (yyvsp[-3].period);
		(yyval.type) -> m_simpleType = (yyvsp[0].m_int); 
	}
#line 1804 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 338 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.type) = new Type();
	}
#line 1812 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 344 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = TYPE_INTERGER;
	}
#line 1820 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 347 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = TYPE_REAL;
	}
#line 1828 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 350 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = TYPE_BOOLEAN;
	}
#line 1836 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 353 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = TYPE_CHAR;
	}
#line 1844 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 360 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.period) = new Period((yyvsp[-4].period) -> mv_dims);
		(yyval.period) -> mv_dims.push_back(p_Per((yyvsp[-2].m_int), (yyvsp[0].m_int)));
	}
#line 1853 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 364 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.period) = new Period();
		(yyval.period) -> mv_dims.push_back(p_Per((yyvsp[-2].m_int), (yyvsp[0].m_int)));
	}
#line 1862 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 370 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = (yyvsp[0].m_int);
	}
#line 1870 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 373 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = (yyvsp[0].m_int);
	}
#line 1878 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 376 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = -(yyvsp[0].m_int);
	}
#line 1886 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 386 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.subProgram_Declarations) = new SubProgram_Declarations((yyvsp[-2].subProgram_Declarations) -> mv_Common);
		(yyval.subProgram_Declarations) -> mv_Common.push_back((yyvsp[-1].common));
	}
#line 1895 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 390 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.subProgram_Declarations) = new SubProgram_Declarations();
	}
#line 1903 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 396 "pasc.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].subprogram_Head) -> Simple_Type == TYPE_NULL) {
			(yyval.common) = new Procedure(yylineno, (yyvsp[-1].subprogram_Head) -> m_ID, (yyvsp[-1].subprogram_Head)-> m_Formal_Parameter -> m_Parameter_List, (yyvsp[0].subprogram_Body) -> m_Const_Declarations, (yyvsp[0].subprogram_Body) -> m_Var_Declarations, (yyvsp[0].subprogram_Body)-> m_Compound_Statement -> m_Statement_List);
		}
		else {
			(yyval.common) = new Function((yyvsp[-1].subprogram_Head) -> Simple_Type, yylineno, (yyvsp[-1].subprogram_Head) -> m_ID, (yyvsp[-1].subprogram_Head)-> m_Formal_Parameter -> m_Parameter_List, (yyvsp[0].subprogram_Body) -> m_Const_Declarations, (yyvsp[0].subprogram_Body) -> m_Var_Declarations, (yyvsp[0].subprogram_Body)-> m_Compound_Statement -> m_Statement_List);
		}
	}
#line 1916 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 406 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-4].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.subprogram_Head) = new Subprogram_Head(tmp, (yyvsp[-3].formal_Parameter), (yyvsp[-1].m_int));
	}
#line 1927 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 412 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-2].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.subprogram_Head) = new Subprogram_Head(tmp, (yyvsp[-1].formal_Parameter), TYPE_NULL);
	}
#line 1938 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 418 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		(yyval.subprogram_Head) = new Subprogram_Head(tmp,new Formal_Parameter(),TYPE_NULL);
	}
#line 1947 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 422 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		(yyval.subprogram_Head) = new Subprogram_Head(tmp,new Formal_Parameter(),TYPE_NULL);
	}
#line 1956 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 429 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.formal_Parameter) = new Formal_Parameter((yyvsp[-1].parameter_List));
	}
#line 1964 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 432 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.formal_Parameter) = new Formal_Parameter(NULL);
	}
#line 1972 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 438 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.parameter_List) = new Parameter_List(yylineno, (yyvsp[-2].parameter_List) -> mv_Patameter);
		(yyval.parameter_List) -> mv_Patameter.push_back((yyvsp[0].parameter));
	}
#line 1981 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 442 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.parameter_List) = new Parameter_List();
		(yyval.parameter_List) -> m_lineno = yylineno;
		(yyval.parameter_List) -> mv_Patameter.push_back((yyvsp[0].parameter));
	}
#line 1991 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 450 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.parameter) = new Parameter(true, yylineno, (yyvsp[0].var_Parameter) -> m_Value_Parameter -> m_Id_List);
		(yyval.parameter) -> m_Type = (yyvsp[0].var_Parameter) -> m_Value_Parameter -> Simple_Type;

	}
#line 2001 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 455 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.parameter) = new Parameter(false, yylineno, (yyvsp[0].value_Parameter) -> m_Id_List);
		(yyval.parameter) -> m_Type = (yyvsp[0].value_Parameter) -> Simple_Type;
	}
#line 2010 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 462 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.var_Parameter) = new Var_Parameter((yyvsp[0].value_Parameter));
	}
#line 2018 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 468 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.value_Parameter) = new Value_Parameter((yyvsp[-2].id_List), (yyvsp[0].m_int));
	}
#line 2026 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 474 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.subprogram_Body) = new Subprogram_Body((yyvsp[-2].const_Declarations), (yyvsp[-1].var_Declarations), (yyvsp[0].compound_Statement));
	}
#line 2034 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 477 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.subprogram_Body) = new Subprogram_Body(NULL,NULL,new Compound_Statement());
	}
#line 2042 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 482 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.compound_Statement) = new Compound_Statement((yyvsp[-1].statement_List));
	}
#line 2050 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 488 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement_List) = new Statement_List((yyvsp[-2].statement_List) -> mv_Statement);
		if((yyvsp[0].statement) != NULL)
			(yyval.statement_List) -> mv_Statement.push_back((yyvsp[0].statement));
	}
#line 2060 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 493 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement_List) = new Statement_List();
		if((yyvsp[0].statement) != NULL)
			(yyval.statement_List) -> mv_Statement.push_back((yyvsp[0].statement));
	}
#line 2070 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 498 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement_List) = new Statement_List();
	}
#line 2078 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 501 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement_List) = new Statement_List();
	}
#line 2086 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 508 "pasc.y" /* yacc.c:1646  */
    {	//赋值
		(yyval.statement) = new Statement();
		(yyval.statement) -> m_stateType = STATEMENT_ASSIGN;
		(yyval.statement) -> m_lineno = yylineno;
		(yyval.statement) -> mp_Assignop = new Assignop((yyvsp[-2].variable), (yyvsp[0].expression));
		(yyval.statement) -> mp_Assignop -> m_lineno = yylineno;
		(yyval.statement) -> mp_Procedure_call = NULL;
		(yyval.statement) -> mp_Statement_List = NULL;
		(yyval.statement) -> mp_If_Then_Else = NULL;
		(yyval.statement) -> mp_For = NULL;
	}
#line 2102 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 519 "pasc.y" /* yacc.c:1646  */
    {	//函数
		(yyval.statement) = new Statement();
		(yyval.statement) -> m_stateType = STATEMENT_PROCEDURE;
		(yyval.statement) -> m_lineno = yylineno;
		(yyval.statement) -> mp_Procedure_call = (yyvsp[0].procedure_Call);
		(yyval.statement) -> mp_Assignop = NULL;
		(yyval.statement) -> mp_Statement_List = NULL;
		(yyval.statement) -> mp_If_Then_Else = NULL;
		(yyval.statement) -> mp_For = NULL;
	}
#line 2117 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 529 "pasc.y" /* yacc.c:1646  */
    {	//函数内部
		(yyval.statement) = new Statement();
		(yyval.statement) -> m_stateType = STATEMENT_COMPOUND;
		(yyval.statement) -> m_lineno = yylineno;
		(yyval.statement) -> mp_Statement_List = (yyvsp[0].compound_Statement) -> m_Statement_List;
		(yyval.statement) -> mp_Assignop = NULL;
		(yyval.statement) -> mp_Procedure_call = NULL;
		(yyval.statement) -> mp_If_Then_Else = NULL;
		(yyval.statement) -> mp_For = NULL;
	}
#line 2132 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 539 "pasc.y" /* yacc.c:1646  */
    {	//if语句
		(yyval.statement) = new Statement();
		(yyval.statement) -> m_stateType = STATEMENT_IF;
		(yyval.statement) -> m_lineno = yylineno;
		(yyval.statement) -> mp_If_Then_Else = new If_Then_Else((yyvsp[-3].expression), (yyvsp[-1].statement), (yyvsp[0].statement));
		(yyval.statement) -> mp_Assignop = NULL;
		(yyval.statement) -> mp_Procedure_call = NULL;
		(yyval.statement) -> mp_Statement_List = NULL;
		(yyval.statement) -> mp_For = NULL;
	}
#line 2147 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 549 "pasc.y" /* yacc.c:1646  */
    {	//expression部分出错
		(yyval.statement) = new Statement();
	}
#line 2155 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 552 "pasc.y" /* yacc.c:1646  */
    {	//for循环
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-6].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.statement) = new Statement();
		(yyval.statement) -> m_stateType = STATEMENT_FOR;
		(yyval.statement) -> m_lineno = yylineno;
		(yyval.statement) -> mp_For = new For(tmp, (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].statement));
		(yyval.statement) -> mp_Assignop = NULL;
		(yyval.statement) -> mp_Procedure_call = NULL;
		(yyval.statement) -> mp_Statement_List = NULL;
		(yyval.statement) -> mp_If_Then_Else = NULL;
	}
#line 2173 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 565 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new Statement();
	}
#line 2181 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 568 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new Statement();
	}
#line 2189 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 571 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement) = NULL;
	}
#line 2197 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 578 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-1].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.variable) = new Variable();
		(yyval.variable) -> mp_Id = tmp;
		(yyval.variable) -> m_lineno = yylineno;
		if((yyvsp[0].id_Varpart) -> m_Expression_List != NULL){
			(yyval.variable) -> m_isArray = true;
			(yyval.variable) -> mp_Expression_List = (yyvsp[0].id_Varpart) -> m_Expression_List;
		}else {
			(yyval.variable) -> m_isArray =false;
			(yyval.variable) -> mp_Expression_List = NULL;
		}
	}
#line 2217 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 597 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.id_Varpart) = new Id_Varpart((yyvsp[-1].expression_List));
	}
#line 2225 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 600 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.id_Varpart) = new Id_Varpart(NULL);
	}
#line 2233 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 606 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[0].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.procedure_Call) = new Procedure_Call();
		(yyval.procedure_Call) -> m_lineno = yylineno;
		(yyval.procedure_Call) -> m_expNum = 0;
		(yyval.procedure_Call) -> mp_Id = tmp;
		(yyval.procedure_Call) -> mp_Expression_List = NULL;

	}
#line 2249 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 617 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.procedure_Call) = new Procedure_Call();
		(yyval.procedure_Call) -> m_lineno = yylineno;
		(yyval.procedure_Call) -> m_expNum = (yyvsp[-1].expression_List) -> mv_Expression.size();
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-3].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.procedure_Call) -> mp_Id = tmp;
		(yyval.procedure_Call) -> mp_Expression_List = (yyvsp[-1].expression_List);
	}
#line 2264 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 630 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement) = (yyvsp[0].statement);
	}
#line 2272 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 633 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement) = NULL;
	}
#line 2280 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 641 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression_List) = new Expression_List((yyvsp[-2].expression_List) -> mv_Expression, (yyvsp[-2].expression_List) -> mv_Type);
		(yyval.expression_List) -> mv_Expression.push_back((yyvsp[0].expression));
	}
#line 2289 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 645 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression_List) = new Expression_List();
		(yyval.expression_List) -> mv_Expression.push_back((yyvsp[0].expression));
	}
#line 2298 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 652 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_LARGE, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2309 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 658 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_LESS, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2320 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 664 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_NOT_EQUAL, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2331 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 670 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_LESS_EQUAL, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2342 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 676 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_LARGE_EQUAL, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2353 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 682 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_EQUAL, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2364 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 688 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = (yyvsp[0].simple_Expression);
		(yyval.expression) -> mp_Relop = NULL;
	}
#line 2375 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 697 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.simple_Expression) = new Simple_Expression(yylineno, NULL, (yyvsp[0].term));
	}
#line 2383 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 700 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.simple_Expression) = new Simple_Expression(yylineno, new Addop(ADDOP_ADD, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].term)),NULL);
	}
#line 2391 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 703 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.simple_Expression) = new Simple_Expression(yylineno, new Addop(ADDOP_SUB, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].term)),NULL);
	}
#line 2399 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 706 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.simple_Expression) = new Simple_Expression(yylineno, new Addop(ADDOP_OR, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].term)),NULL);
	}
#line 2407 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 712 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, new Mulop(MULOP_MULTIPLY, yylineno, (yyvsp[-2].term), (yyvsp[0].factor)), NULL);
	}
#line 2415 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 715 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, new Mulop(MULOP_REAL_DIV, yylineno, (yyvsp[-2].term), (yyvsp[0].factor)), NULL);
	}
#line 2423 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 718 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, new Mulop(MULOP_AND, yylineno, (yyvsp[-2].term), (yyvsp[0].factor)), NULL);
	}
#line 2431 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 721 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, new Mulop(MULOP_INT_DIV, yylineno, (yyvsp[-2].term), (yyvsp[0].factor)), NULL);
	}
#line 2439 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 724 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, new Mulop(MULOP_MOD, yylineno, (yyvsp[-2].term), (yyvsp[0].factor)), NULL);
	}
#line 2447 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 727 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, NULL, (yyvsp[0].factor));
	}
#line 2455 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 732 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_float) = (yyvsp[0].m_float);
	}
#line 2463 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 735 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_float) = -(yyvsp[0].m_float);
	}
#line 2471 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 740 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> m_int = (yyvsp[0].m_int);
		(yyval.factor) -> m_factorType = FACTOR_VALUE_INT;
	}
#line 2482 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 746 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> m_real = (yyvsp[0].m_float);
		(yyval.factor) -> m_factorType = FACTOR_VALUE_REAL;
	}
#line 2493 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 752 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> m_char = (yyvsp[0].m_char);
		(yyval.factor) -> m_factorType = FACTOR_VALUE_CHAR;
	}
#line 2504 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 758 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> m_bool = (yyvsp[0].m_bool);
		(yyval.factor) -> m_factorType = FACTOR_VALUE_BOOL;
	}
#line 2515 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 764 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> mp_Variable = (yyvsp[0].variable);
		(yyval.factor) -> mp_Function_Call = NULL;
		(yyval.factor) -> mp_Expression = NULL;
		(yyval.factor) -> mp_Not = NULL;
		(yyval.factor) -> mp_Uminus = NULL;
		(yyval.factor) -> m_factorType = FACTOR_VAR;
	}
#line 2530 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 774 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> mp_Variable = NULL;
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-3].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.factor) -> mp_Function_Call = new Function_Call((yyvsp[-1].expression_List) -> mv_Expression.size(), yylineno, tmp, (yyvsp[-1].expression_List));
		(yyval.factor) -> mp_Expression = NULL;
		(yyval.factor) -> mp_Not = NULL;
		(yyval.factor) -> mp_Uminus = NULL;
		(yyval.factor) -> m_factorType = FACTOR_FUNCCALL;
	}
#line 2548 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 787 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> mp_Variable = NULL;
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-2].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.factor) -> mp_Function_Call = new Function_Call(0, yylineno, tmp, NULL);
		(yyval.factor) -> mp_Expression = NULL;
		(yyval.factor) -> mp_Not = NULL;
		(yyval.factor) -> mp_Uminus = NULL;
		(yyval.factor) -> m_factorType = FACTOR_FUNCCALL;
	}
#line 2566 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 800 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> mp_Variable = NULL;
		(yyval.factor) -> mp_Function_Call = NULL;
		(yyval.factor) -> mp_Expression = (yyvsp[-1].expression);
		(yyval.factor) -> mp_Not = NULL;
		(yyval.factor) -> mp_Uminus = NULL;
		(yyval.factor) -> m_factorType = FACTOR_BRACKETS;
	}
#line 2581 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 810 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> mp_Variable = NULL;
		(yyval.factor) -> mp_Function_Call = NULL;
		(yyval.factor) -> mp_Expression = NULL;
		(yyval.factor) -> mp_Not = new Not();
		(yyval.factor) -> mp_Not -> mp_Factor = (yyvsp[0].factor);
		(yyval.factor) -> mp_Not -> m_lineno = yylineno;
		(yyval.factor) -> mp_Uminus = NULL;
		(yyval.factor) -> m_factorType = FACTOR_NOT;
	}
#line 2598 "pasc.tab.c" /* yacc.c:1646  */
    break;


#line 2602 "pasc.tab.c" /* yacc.c:1646  */
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
#line 823 "pasc.y" /* yacc.c:1906  */



int Lexic_Syntax() {
	yydebug = 0;
	int ans = yyparse();
	if(errorNum)
		cout<<"The number of syntax error is: "<<errorNum<<endl;
	//ROOT -> outputTree();
    if(ans || errorNum !=0 )
    	return 1;
    else
    	return 0;
}


extern void yyerror(const char* s) {
	printf("line: %d, Error '%s'\n",yylineno,s);
	errorNum++;
}
