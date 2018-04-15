/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 2 "pasc.y" /* yacc.c:1915  */

	#include "Public_define.h"
	#include "Syntax_Tree.h"

#line 49 "pasc.tab.h" /* yacc.c:1915  */

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
#line 30 "pasc.y" /* yacc.c:1915  */

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
 	

#line 159 "pasc.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PASC_TAB_H_INCLUDED  */
