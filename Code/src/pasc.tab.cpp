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
	#include <string>
	#include "../yacc/lex.yy.c"
	#include <iostream>
	typedef pair<Id*, Const_Value*> p_Const;
	typedef pair<Id_List*, Type*> p_Var;
	typedef pair<int,int> p_Per;
	Programstruct* ROOT;
	int errorNum = 0;

	int yyparse(void);
	extern int yylineno;
	void yyerror(const char* s);

	#define YYERROR_VERBOSE 1
	extern int yydebug;
	#define YYDEBUG 1

	using namespace std;

#line 85 "pasc.tab.c" /* yacc.c:316  */



/* Copy the first part of user declarations.  */

#line 91 "pasc.tab.c" /* yacc.c:339  */

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

	#include "Public_define.h"
	#include "Syntax_Tree.h"

#line 126 "pasc.tab.c" /* yacc.c:355  */

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
#line 39 "pasc.y" /* yacc.c:355  */

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
 	

#line 236 "pasc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PASC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 253 "pasc.tab.c" /* yacc.c:358  */

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
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

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
       0,   138,   138,   144,   153,   158,   166,   177,   180,   186,
     195,   205,   216,   227,   238,   244,   250,   256,   262,   268,
     274,   320,   323,   330,   334,   341,   347,   357,   360,   363,
     366,   373,   377,   383,   386,   389,   399,   403,   409,   419,
     425,   434,   437,   443,   447,   455,   460,   467,   473,   479,
     489,   495,   500,   505,   508,   527,   538,   548,   558,   592,
     605,   612,   636,   639,   645,   656,   669,   672,   700,   704,
     711,   717,   723,   729,   735,   741,   747,   756,   759,   762,
     765,   771,   774,   777,   780,   783,   786,   791,   794,   799,
     805,   811,   821,   834,   847,   857
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
     298,   299
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -64

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,   -29,    74,    33,    30,  -124,    24,    46,    48,    43,
      67,    64,  -124,    43,  -124,  -124,    23,    88,    68,    51,
      89,    59,    76,    94,   101,   104,  -124,  -124,  -124,  -124,
    -124,   105,   102,    43,     7,   107,   108,   124,    33,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,    88,    73,
    -124,  -124,  -124,  -124,  -124,  -124,    87,  -124,   110,    42,
     -22,  -124,    16,  -124,   136,  -124,   125,   125,  -124,    48,
    -124,  -124,    82,   102,   138,    42,    42,    92,   116,  -124,
    -124,   -21,  -124,  -124,   147,    77,    34,  -124,  -124,    42,
      42,  -124,  -124,    18,    42,   -26,   132,   133,   172,   121,
      36,   146,  -124,    42,  -124,   134,  -124,  -124,  -124,    -9,
       0,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    78,  -124,    62,  -124,  -124,
    -124,    43,   122,    20,  -124,  -124,  -124,   117,  -124,  -124,
      82,   160,    82,   154,  -124,  -124,    81,   171,    34,   -15,
     -15,   -15,   -15,   -15,   -15,    34,    34,  -124,  -124,  -124,
    -124,  -124,    42,  -124,  -124,  -124,   117,   -26,  -124,   140,
     152,   117,  -124,    42,  -124,     0,  -124,  -124,  -124,  -124,
    -124,    82,  -124,   176,  -124,  -124,     0,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     0,     1,     0,     0,    22,     0,
       0,     0,     2,     0,    37,     6,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,    19,    16,    13,    20,
      10,     0,     0,    21,     0,     0,     0,     0,     8,     4,
       5,     3,    18,    15,    12,    17,    14,    11,     0,     0,
      29,    30,    27,    28,    24,    25,     0,    54,     0,     0,
      64,    57,     0,    52,     0,    56,    42,    42,    36,    22,
      38,     9,     0,     0,     0,     0,     0,     0,     0,    33,
      87,    63,    89,    91,     0,    76,    77,    90,    86,     0,
       0,    61,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,    95,     0,    35,    88,    34,     0,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,    53,    51,
      55,     0,     0,     0,    44,    45,    46,     0,    40,    49,
       0,     0,     0,     0,    94,    93,     0,    67,    80,    73,
      74,    72,    75,    71,    70,    79,    78,    83,    84,    85,
      81,    82,     0,    65,    62,    47,     0,     0,    41,     0,
       0,     0,    32,     0,    92,    60,    58,    68,    48,    43,
      39,     0,    26,     0,    66,    31,    60,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,  -124,    60,   150,  -124,   141,   123,  -124,
     118,  -123,  -124,   -70,  -124,  -124,  -124,   126,  -124,    27,
    -124,    65,  -124,   -17,  -124,   -90,   -34,  -124,  -124,  -124,
     -80,   -58,    41,   -28,  -124,   -66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,   132,     8,    11,    30,    14,    20,
      54,    55,   100,    82,    21,    37,    38,    96,   133,   134,
     135,   136,    70,    61,    62,    63,    83,    91,    65,   176,
     125,   126,    85,    86,    87,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    84,   101,   129,    39,    34,   131,   111,    57,   104,
     127,    75,    34,   -63,   169,    58,     1,    59,   105,   128,
     147,   -60,    58,    34,    59,    89,   109,    90,    90,   146,
      92,     4,   -60,    58,    15,    59,   130,   120,    76,   145,
     118,   119,     6,   178,   121,   143,    77,    78,   182,    79,
      80,    81,   -60,   122,   157,   158,   159,   160,   161,    64,
      60,    93,    75,   -60,    34,   167,    22,    60,   168,    16,
     170,    23,   172,    19,     5,    35,    64,     9,    60,   140,
      13,   139,    36,   148,    10,   184,   141,   123,   124,    76,
     155,   156,    12,    56,    22,    32,   187,    77,    78,   111,
      79,    80,    81,    15,   177,   162,    49,    17,    50,    18,
      51,   185,   164,   112,   113,   183,   114,   115,   116,   117,
      52,   162,    72,    50,   162,    51,   163,    53,    31,   174,
      22,    73,   118,   119,    33,    52,    40,    99,    78,    41,
      79,    64,    53,    24,    25,    48,    26,    27,    28,    29,
     106,   107,    64,   149,   150,   151,   152,   153,   154,    42,
      43,    44,    45,    46,    47,    22,   166,    66,    67,    68,
      74,    94,    95,   103,   108,   110,   137,    34,   138,   106,
     142,   171,   144,   173,   175,   180,   181,   186,    69,    71,
       0,   102,    98,    97,   179,     0,   165
};

static const yytype_int16 yycheck[] =
{
      34,    59,    72,    93,    21,     5,    32,    22,     1,    75,
      90,    20,     5,    35,   137,    15,    24,    17,    76,     1,
     110,    14,    15,     5,    17,    47,    47,    49,    49,   109,
      14,    60,    14,    15,    60,    17,    94,     3,    47,    48,
      55,    56,     9,   166,    10,   103,    55,    56,   171,    58,
      59,    60,    45,    19,   120,   121,   122,   123,   124,    93,
      60,    45,    20,    45,     5,    45,    43,    60,    48,     9,
     140,    48,   142,    13,     0,    16,   110,    47,    60,    43,
      32,    98,    23,   111,    60,   175,    50,    53,    54,    47,
     118,   119,    46,    33,    43,    44,   186,    55,    56,    22,
      58,    59,    60,    60,   162,    43,     4,    40,     6,    45,
       8,   181,    50,    36,    37,   173,    39,    40,    41,    42,
      18,    43,    49,     6,    43,     8,    48,    25,    60,    48,
      43,    44,    55,    56,    45,    18,    60,    55,    56,    45,
      58,   175,    25,    55,    56,    40,    58,    59,    60,    61,
      58,    59,   186,   112,   113,   114,   115,   116,   117,    58,
      59,    60,    58,    59,    60,    43,    44,    60,    60,    45,
      60,    35,    47,    35,    58,    28,    44,     5,    45,    58,
      34,    21,    48,    29,    13,    45,    34,    11,    38,    48,
      -1,    73,    69,    67,   167,    -1,   131
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    63,    64,    60,     0,     9,    65,    67,    47,
      60,    68,    46,    32,    70,    60,    66,    40,    45,    66,
      71,    76,    43,    48,    55,    56,    58,    59,    60,    61,
      69,    60,    44,    45,     5,    16,    23,    77,    78,    85,
      60,    45,    58,    59,    60,    58,    59,    60,    40,     4,
       6,     8,    18,    25,    72,    73,    66,     1,    15,    17,
      60,    85,    86,    87,    88,    90,    60,    60,    45,    67,
      84,    69,    49,    44,    60,    20,    47,    55,    56,    58,
      59,    60,    75,    88,    93,    94,    95,    96,    97,    47,
      49,    89,    14,    45,    35,    47,    79,    79,    70,    55,
      74,    75,    72,    35,    97,    93,    58,    59,    58,    47,
      28,    22,    36,    37,    39,    40,    41,    42,    55,    56,
       3,    10,    19,    53,    54,    92,    93,    92,     1,    87,
      93,    32,    66,    80,    81,    82,    83,    44,    45,    85,
      43,    50,    34,    93,    48,    48,    92,    87,    95,    94,
      94,    94,    94,    94,    94,    95,    95,    97,    97,    97,
      97,    97,    43,    48,    50,    83,    44,    45,    48,    73,
      75,    21,    75,    29,    48,    13,    91,    93,    73,    81,
      45,    34,    73,    93,    87,    75,    11,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    74,    74,    75,    75,    75,    76,    76,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    83,    84,
      85,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    96,    96,    97,
      97,    97,    97,    97,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     6,     4,     3,     1,     3,     0,     5,
       3,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       1,     3,     0,     5,     3,     1,     6,     1,     1,     1,
       1,     5,     3,     1,     2,     2,     3,     0,     2,     6,
       4,     3,     0,     3,     1,     1,     1,     2,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     1,     5,     8,
       0,     2,     3,     0,     1,     4,     2,     0,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     2,     1,
       1,     1,     4,     3,     3,     2
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
#line 138 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.programstruct) = new Programstruct((yyvsp[-2].program_Head)->m_Id, (yyvsp[-2].program_Head)->m_Id_List, (yyvsp[-1].program_Body));
		ROOT = (yyval.programstruct);
	}
#line 1471 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 144 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-4].m_str));
		tmp -> m_lineno = yylineno;
		tmp -> m_idType = TYPE_ID;
		(yyval.program_Head) = new Program_Head(tmp, (yyvsp[-2].id_List));
	}
#line 1483 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 153 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.program_Body) = new Program_Body((yyvsp[-3].const_Declarations), (yyvsp[-2].var_Declarations), (yyvsp[-1].subProgram_Declarations), (yyvsp[0].compound_Statement));
	}
#line 1491 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 158 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.id_List) = new Id_List();
		(yyval.id_List) = (yyvsp[-2].id_List);
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[0].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.id_List) -> mv_Id.push_back(tmp);
	}
#line 1504 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 166 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[0].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.id_List) = new Id_List();
		(yyval.id_List) -> mv_Id.push_back(tmp);
		(yyval.id_List) -> m_lineno = yylineno;
	}
#line 1517 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 177 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Declarations) = new Const_Declarations((yyvsp[-1].const_Declaration) -> mv_Const);
	}
#line 1525 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 180 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Declarations) = new Const_Declarations();
	}
#line 1533 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 186 "pasc.y" /* yacc.c:1646  */
    {

		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-2].m_str));
		tmp -> m_lineno = yylineno;

		(yyvsp[-4].const_Declaration) -> mv_Const.push_back(p_Const(tmp, (yyvsp[0].const_Value)));
		(yyval.const_Declaration) = new Const_Declaration((yyvsp[-4].const_Declaration) -> mv_Const);
	}
#line 1547 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 195 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-2].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.const_Declaration) = new Const_Declaration();
		(yyval.const_Declaration) -> mv_Const.push_back(p_Const(tmp,(yyvsp[0].const_Value)));
	}
#line 1559 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 205 "pasc.y" /* yacc.c:1646  */
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
#line 1575 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 216 "pasc.y" /* yacc.c:1646  */
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
#line 1591 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 227 "pasc.y" /* yacc.c:1646  */
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
#line 1607 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 238 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.const_Value) -> m_valueType = TYPE_REAL;
		(yyval.const_Value) -> m_real = (yyvsp[0].m_float);
	}
#line 1618 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 244 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_NEGATIVE;
		(yyval.const_Value) -> m_valueType = TYPE_REAL;
		(yyval.const_Value) -> m_real = (yyvsp[0].m_float);	
	}
#line 1629 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 250 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.const_Value) -> m_valueType = TYPE_REAL;
		(yyval.const_Value) -> m_real = (yyvsp[0].m_float);
	}
#line 1640 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 256 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.const_Value) -> m_valueType = TYPE_INTERGER;
		(yyval.const_Value) -> m_int = (yyvsp[0].m_int);
	}
#line 1651 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 262 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_NEGATIVE;
		(yyval.const_Value) -> m_valueType = TYPE_INTERGER;
		(yyval.const_Value) -> m_int = (yyvsp[0].m_int);
	}
#line 1662 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 268 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_POSITIVE;
		(yyval.const_Value) -> m_valueType = TYPE_INTERGER;
		(yyval.const_Value) -> m_int = (yyvsp[0].m_int);
	}
#line 1673 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 274 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.const_Value) = new Const_Value();
		(yyval.const_Value) -> m_postNeg = CONST_POSTNEG_NULL;
		(yyval.const_Value) -> m_valueType = TYPE_CHAR;
		(yyval.const_Value) -> m_real = (yyvsp[0].m_char);
	}
#line 1684 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 320 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.var_Declarations) = new Var_Declarations((yyvsp[-1].var_Declaration) -> mv_Var);
	}
#line 1692 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 323 "pasc.y" /* yacc.c:1646  */
    {
		vector<p_Var> tmp;
		(yyval.var_Declarations) = new Var_Declarations(tmp);
	}
#line 1701 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 330 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.var_Declaration) = new Var_Declaration((yyvsp[-4].var_Declaration) -> mv_Var);
		(yyval.var_Declaration) -> mv_Var.push_back(p_Var((yyvsp[-2].id_List), (yyvsp[0].type)));
	}
#line 1710 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 334 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.var_Declaration) = new Var_Declaration();
		(yyval.var_Declaration) -> mv_Var.push_back(p_Var((yyvsp[-2].id_List), (yyvsp[0].type)));
	}
#line 1719 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 341 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.type) = new Type();
		(yyval.type) -> m_simpleType = (yyvsp[0].m_int);
		(yyval.type) -> m_isArray = false;
		(yyval.type) -> m_lineno = yylineno; 
	}
#line 1730 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 347 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.type) = new Type();
		(yyval.type) -> m_lineno = yylineno;
		(yyval.type) -> m_isArray = true;
		(yyval.type) -> mp_Period = (yyvsp[-3].period);
		(yyval.type) -> m_simpleType = (yyvsp[0].m_int); 
	}
#line 1742 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 357 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = TYPE_INTERGER;
	}
#line 1750 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 360 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = TYPE_REAL;
	}
#line 1758 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 363 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = TYPE_BOOLEAN;
	}
#line 1766 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 366 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = TYPE_CHAR;
	}
#line 1774 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 373 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.period) = new Period((yyvsp[-4].period) -> mv_dims);
		(yyval.period) -> mv_dims.push_back(p_Per((yyvsp[-2].m_int), (yyvsp[0].m_int)));
	}
#line 1783 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 377 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.period) = new Period();
		(yyval.period) -> mv_dims.push_back(p_Per((yyvsp[-2].m_int), (yyvsp[0].m_int)));
	}
#line 1792 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 383 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = (yyvsp[0].m_int);
	}
#line 1800 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 386 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = (yyvsp[0].m_int);
	}
#line 1808 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 389 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_int) = -(yyvsp[0].m_int);
	}
#line 1816 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 399 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.subProgram_Declarations) = new SubProgram_Declarations((yyvsp[-2].subProgram_Declarations) -> mv_Common);
		(yyval.subProgram_Declarations) -> mv_Common.push_back((yyvsp[-1].common));
	}
#line 1825 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 403 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.subProgram_Declarations) = new SubProgram_Declarations();
	}
#line 1833 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 409 "pasc.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].subprogram_Head) -> Simple_Type == TYPE_NULL) {
			(yyval.common) = new Procedure(yylineno, (yyvsp[-1].subprogram_Head) -> m_ID, (yyvsp[-1].subprogram_Head)-> m_Formal_Parameter -> m_Parameter_List, (yyvsp[0].subprogram_Body) -> m_Const_Declarations, (yyvsp[0].subprogram_Body) -> m_Var_Declarations, (yyvsp[0].subprogram_Body)-> m_Compound_Statement -> m_Statement_List);
		}
		else {
			(yyval.common) = new Function((yyvsp[-1].subprogram_Head) -> Simple_Type, yylineno, (yyvsp[-1].subprogram_Head) -> m_ID, (yyvsp[-1].subprogram_Head)-> m_Formal_Parameter -> m_Parameter_List, (yyvsp[0].subprogram_Body) -> m_Const_Declarations, (yyvsp[0].subprogram_Body) -> m_Var_Declarations, (yyvsp[0].subprogram_Body)-> m_Compound_Statement -> m_Statement_List);
		}
	}
#line 1846 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 419 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-4].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.subprogram_Head) = new Subprogram_Head(tmp, (yyvsp[-3].formal_Parameter), (yyvsp[-1].m_int));
	}
#line 1857 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 425 "pasc.y" /* yacc.c:1646  */
    {
		Id* tmp = new Id();
		tmp -> m_name = *((yyvsp[-2].m_str));
		tmp -> m_lineno = yylineno;
		(yyval.subprogram_Head) = new Subprogram_Head(tmp, (yyvsp[-1].formal_Parameter), TYPE_NULL);
	}
#line 1868 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 434 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.formal_Parameter) = new Formal_Parameter((yyvsp[-1].parameter_List));
	}
#line 1876 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 437 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.formal_Parameter) = new Formal_Parameter(NULL);
	}
#line 1884 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 443 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.parameter_List) = new Parameter_List(yylineno, (yyvsp[-2].parameter_List) -> mv_Patameter);
		(yyval.parameter_List) -> mv_Patameter.push_back((yyvsp[0].parameter));
	}
#line 1893 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 447 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.parameter_List) = new Parameter_List();
		(yyval.parameter_List) -> m_lineno = yylineno;
		(yyval.parameter_List) -> mv_Patameter.push_back((yyvsp[0].parameter));
	}
#line 1903 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 455 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.parameter) = new Parameter(true, yylineno, (yyvsp[0].var_Parameter) -> m_Value_Parameter -> m_Id_List);
		(yyval.parameter) -> m_Type = (yyvsp[0].var_Parameter) -> m_Value_Parameter -> Simple_Type;

	}
#line 1913 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 460 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.parameter) = new Parameter(false, yylineno, (yyvsp[0].value_Parameter) -> m_Id_List);
		(yyval.parameter) -> m_Type = (yyvsp[0].value_Parameter) -> Simple_Type;
	}
#line 1922 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 467 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.var_Parameter) = new Var_Parameter((yyvsp[0].value_Parameter));
	}
#line 1930 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 473 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.value_Parameter) = new Value_Parameter((yyvsp[-2].id_List), (yyvsp[0].m_int));
	}
#line 1938 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 479 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.subprogram_Body) = new Subprogram_Body((yyvsp[-2].const_Declarations), (yyvsp[-1].var_Declarations), (yyvsp[0].compound_Statement));
	}
#line 1946 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 489 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.compound_Statement) = new Compound_Statement((yyvsp[-1].statement_List));
	}
#line 1954 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 495 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement_List) = new Statement_List((yyvsp[-2].statement_List) -> mv_Statement);
		if((yyvsp[0].statement) != NULL)
			(yyval.statement_List) -> mv_Statement.push_back((yyvsp[0].statement));
	}
#line 1964 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 500 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement_List) = new Statement_List();
		if((yyvsp[0].statement) != NULL)
			(yyval.statement_List) -> mv_Statement.push_back((yyvsp[0].statement));
	}
#line 1974 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 505 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement_List) = new Statement_List();
	}
#line 1982 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 508 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement_List) = new Statement_List();
	}
#line 1990 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 527 "pasc.y" /* yacc.c:1646  */
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
#line 2006 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 538 "pasc.y" /* yacc.c:1646  */
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
#line 2021 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 548 "pasc.y" /* yacc.c:1646  */
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
#line 2036 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 558 "pasc.y" /* yacc.c:1646  */
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
#line 2051 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 592 "pasc.y" /* yacc.c:1646  */
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
#line 2069 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 605 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement) = NULL;
	}
#line 2077 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 612 "pasc.y" /* yacc.c:1646  */
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
#line 2097 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 636 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.id_Varpart) = new Id_Varpart((yyvsp[-1].expression_List));
	}
#line 2105 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 639 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.id_Varpart) = new Id_Varpart(NULL);
	}
#line 2113 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 645 "pasc.y" /* yacc.c:1646  */
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
#line 2129 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 656 "pasc.y" /* yacc.c:1646  */
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
#line 2144 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 669 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement) = (yyvsp[0].statement);
	}
#line 2152 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 672 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.statement) = NULL;
	}
#line 2160 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 700 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression_List) = new Expression_List((yyvsp[-2].expression_List) -> mv_Expression, (yyvsp[-2].expression_List) -> mv_Type);
		(yyval.expression_List) -> mv_Expression.push_back((yyvsp[0].expression));
	}
#line 2169 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 704 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression_List) = new Expression_List();
		(yyval.expression_List) -> mv_Expression.push_back((yyvsp[0].expression));
	}
#line 2178 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 711 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_LARGE, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2189 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 717 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_LESS, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2200 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 723 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_NOT_EQUAL, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2211 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 729 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_LESS_EQUAL, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2222 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 735 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_LARGE_EQUAL, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2233 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 741 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = NULL;
		(yyval.expression) -> mp_Relop = new Relop(RELOP_EQUAL, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].simple_Expression));
	}
#line 2244 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 747 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Expression();
		(yyval.expression) -> m_lineno = yylineno;
		(yyval.expression) -> mp_Simple_Expression = (yyvsp[0].simple_Expression);
		(yyval.expression) -> mp_Relop = NULL;
	}
#line 2255 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 756 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.simple_Expression) = new Simple_Expression(yylineno, NULL, (yyvsp[0].term));
	}
#line 2263 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 759 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.simple_Expression) = new Simple_Expression(yylineno, new Addop(ADDOP_ADD, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].term)),NULL);
	}
#line 2271 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 762 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.simple_Expression) = new Simple_Expression(yylineno, new Addop(ADDOP_SUB, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].term)),NULL);
	}
#line 2279 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 765 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.simple_Expression) = new Simple_Expression(yylineno, new Addop(ADDOP_OR, yylineno, (yyvsp[-2].simple_Expression), (yyvsp[0].term)),NULL);
	}
#line 2287 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 771 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, new Mulop(MULOP_MULTIPLY, yylineno, (yyvsp[-2].term), (yyvsp[0].factor)), NULL);
	}
#line 2295 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 774 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, new Mulop(MULOP_REAL_DIV, yylineno, (yyvsp[-2].term), (yyvsp[0].factor)), NULL);
	}
#line 2303 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 777 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, new Mulop(MULOP_AND, yylineno, (yyvsp[-2].term), (yyvsp[0].factor)), NULL);
	}
#line 2311 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 780 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, new Mulop(MULOP_INT_DIV, yylineno, (yyvsp[-2].term), (yyvsp[0].factor)), NULL);
	}
#line 2319 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 783 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, new Mulop(MULOP_MOD, yylineno, (yyvsp[-2].term), (yyvsp[0].factor)), NULL);
	}
#line 2327 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 786 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.term) = new Term(yylineno, NULL, (yyvsp[0].factor));
	}
#line 2335 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 791 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_float) = (yyvsp[0].m_float);
	}
#line 2343 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 794 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.m_float) = -(yyvsp[0].m_float);
	}
#line 2351 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 799 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> m_int = (yyvsp[0].m_int);
		(yyval.factor) -> m_factorType = FACTOR_VALUE_INT;
	}
#line 2362 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 805 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> m_real = (yyvsp[0].m_float);
		(yyval.factor) -> m_factorType = FACTOR_VALUE_REAL;
	}
#line 2373 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 811 "pasc.y" /* yacc.c:1646  */
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
#line 2388 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 821 "pasc.y" /* yacc.c:1646  */
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
#line 2406 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 834 "pasc.y" /* yacc.c:1646  */
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
#line 2424 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 847 "pasc.y" /* yacc.c:1646  */
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
#line 2439 "pasc.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 857 "pasc.y" /* yacc.c:1646  */
    {
		(yyval.factor) = new Factor();
		(yyval.factor) -> m_lineno = yylineno;
		(yyval.factor) -> mp_Variable = NULL;
		(yyval.factor) -> mp_Function_Call = NULL;
		(yyval.factor) -> mp_Expression = NULL;
		(yyval.factor) -> mp_Not -> mp_Factor = (yyvsp[0].factor);
		(yyval.factor) -> mp_Not -> m_lineno = yylineno;
		(yyval.factor) -> mp_Uminus = NULL;
		(yyval.factor) -> m_factorType = FACTOR_NOT;
	}
#line 2455 "pasc.tab.c" /* yacc.c:1646  */
    break;


#line 2459 "pasc.tab.c" /* yacc.c:1646  */
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
#line 869 "pasc.y" /* yacc.c:1906  */



int Lexic_Syntax() {
	//yydebug = 1;
    yyparse();
    //ROOT->outputTree();
    return errorNum;
    //cout<<"begin"<<endl;
}


extern void yyerror(const char* s) {
	/*
	va_list ap;
	va_start(ap,s);
	if(yylloc.first_line){
		fprintf(stderr,"%d.%d-%d.%d:error: ",yylloc.first_line,yylloc.first_column,yylloc.last_line,yylloc.last_column);
	}
	vfprintf(stderr,s,ap);
	fprintf(stderr,"\n");
	*/
	printf("line: %d, Error '%s'\n",yylineno,s);
	errorNum++;
}
