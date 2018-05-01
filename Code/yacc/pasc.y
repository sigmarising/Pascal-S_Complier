/*警告：书上的文法具有移进规约冲突,135-137行部分，已解决*/
%code requires {
	#include "Public_define.h"
	#include "Syntax_Tree.h"
}

%code top {
	#include <stdio.h>
	#include <string>
	#include "lex.yy.c"
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
}


%token AND ARRAY BEGIN_L BOOLEAN CASE CHAR CONST DIV DO DOWNTO ELSE END FOR FUNCTION IF INTEGER MOD 
%token NOT OF OR PROCEDURE PROGRAM REAL RECORD REPEAT THEN TO TYPE UNTIL VAR WHILE
%token SUBBOUNDARY ASSIGNOP LE_OP GE_OP EQ_OP NE_OP
%token '=' '<' '>' ',' ':' ';' '.' '(' ')' '[' ']' '{' '}' '*' '/' '-' '+'

%left else_conflict
%left ELSE


%union {
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
}

%token <m_int> DIGITS
%token <m_float> NUMBER
%token <m_str> IDENTIFIER
%token <m_char> LETTER;
%token <m_bool> BOOL;

%type <m_int> SDIGITS
%type <m_float> SNUMBER
%type <programstruct> program
%type <program_Head> program_head
%type <program_Body> program_body
%type <id_List> identifier_list
%type <const_Declarations> const_declarations
%type <const_Declaration> const_declaration
%type <const_Value> const_variable
%type <var_Declarations> var_declarations
%type <var_Declaration> var_declaration
%type <type> type
%type <m_int> standard_type
%type <period> period
%type <subProgram_Declarations> subprogram_declarations
%type <common> subprogram
%type <subprogram_Head> subprogram_head
%type <formal_Parameter> formal_parameter
%type <parameter_List> parameter_list
%type <parameter> parameter
%type <var_Parameter> var_parameter
%type <value_Parameter> value_parameter
%type <subprogram_Body> subprogram_body
%type <compound_Statement> compound_statement
%type <statement_List> statement_list
%type <statement> statement
%type <variable> variable
%type <id_Varpart> id_varpart
%type <procedure_Call> call_procedure_statement
%type <statement> else_part
%type <expression_List> expression_list
%type <expression> expression
%type <simple_Expression> simple_expression
%type <term> term
%type <factor> factor



%%

program 
	: program_head program_body '.'	{
		$$ = new Programstruct($1->m_Id, $1->m_Id_List, $2);
		ROOT = $$;
	} 

program_head 
	: PROGRAM IDENTIFIER '(' identifier_list ')' ';' {
		Id* tmp = new Id();
		tmp -> m_name = *($2);
		tmp -> m_lineno = yylineno;
		tmp -> m_idType = TYPE_ID;
		$$ = new Program_Head(tmp, $4);
	}

program_body 
	: const_declarations var_declarations subprogram_declarations compound_statement {
		$$ = new Program_Body($1, $2, $3, $4);
	}

identifier_list 
	: identifier_list ',' IDENTIFIER {
		$$ = new Id_List();
		$$ = $1;
		Id* tmp = new Id();
		tmp -> m_name = *($3);
		tmp -> m_lineno = yylineno;
		$$ -> mv_Id.push_back(tmp);
	}
	| IDENTIFIER {
		Id* tmp = new Id();
		tmp -> m_name = *($1);
		tmp -> m_lineno = yylineno;
		$$ = new Id_List();
		$$ -> mv_Id.push_back(tmp);
		$$ -> m_lineno = yylineno;
	}
	;

const_declarations 
	: CONST const_declaration ';' {
		$$ = new Const_Declarations($2 -> mv_Const);
	}
	| {
		$$ = new Const_Declarations();
	}
	;

const_declaration 
	: const_declaration ';' IDENTIFIER '=' const_variable {

		Id* tmp = new Id();
		tmp -> m_name = *($3);
		tmp -> m_lineno = yylineno;

		$1 -> mv_Const.push_back(p_Const(tmp, $5));
		$$ = new Const_Declaration($1 -> mv_Const);
	}
	| IDENTIFIER '=' const_variable {
		Id* tmp = new Id();
		tmp -> m_name = *($1);
		tmp -> m_lineno = yylineno;
		$$ = new Const_Declaration();
		$$ -> mv_Const.push_back(p_Const(tmp,$3));
	}
	;

const_variable 
	: '+' IDENTIFIER {
		$$ = new Const_Value();
		$$ -> m_lineno = yylineno;
		$$ -> m_postNeg = CONST_POSTNEG_POSITIVE;
		$$ -> m_valueType = TYPE_ID;
		$$ -> m_isId = true;
		Id* tmp = new Id();
		tmp -> m_name = *($2);
		tmp -> m_lineno = yylineno;
		$$ -> mp_Id = tmp;
	}
	| '-' IDENTIFIER {
		$$ = new Const_Value();
		$$ -> m_lineno = yylineno;
		$$ -> m_postNeg = CONST_POSTNEG_NEGATIVE;
		$$ -> m_valueType = TYPE_ID;
		$$ -> m_isId = true;
		Id* tmp = new Id();
		tmp -> m_name = *($2);
		tmp -> m_lineno = yylineno;
		$$ -> mp_Id = tmp;	
	} 
	| IDENTIFIER {
		$$ = new Const_Value();
		$$ -> m_lineno = yylineno;
		$$ -> m_postNeg = CONST_POSTNEG_POSITIVE;
		$$ -> m_valueType = TYPE_ID;
		$$ -> m_isId = true;
		Id* tmp = new Id();
		tmp -> m_name = *($1);
		tmp -> m_lineno = yylineno;
		$$ -> mp_Id = tmp;
	}
	| '+' NUMBER {
		$$ = new Const_Value();
		$$ -> m_postNeg = CONST_POSTNEG_POSITIVE;
		$$ -> m_valueType = TYPE_REAL;
		$$ -> m_real = $2;
	}
	| '-' NUMBER {
		$$ = new Const_Value();
		$$ -> m_postNeg = CONST_POSTNEG_NEGATIVE;
		$$ -> m_valueType = TYPE_REAL;
		$$ -> m_real = $2;	
	}
	| NUMBER {
		$$ = new Const_Value();
		$$ -> m_postNeg = CONST_POSTNEG_POSITIVE;
		$$ -> m_valueType = TYPE_REAL;
		$$ -> m_real = $1;
	}
	| '+' DIGITS {
		$$ = new Const_Value();
		$$ -> m_postNeg = CONST_POSTNEG_POSITIVE;
		$$ -> m_valueType = TYPE_INTERGER;
		$$ -> m_int = $2;
	}
	| '-' DIGITS {
		$$ = new Const_Value();
		$$ -> m_postNeg = CONST_POSTNEG_NEGATIVE;
		$$ -> m_valueType = TYPE_INTERGER;
		$$ -> m_int = $2;
	}
	| DIGITS {
		$$ = new Const_Value();
		$$ -> m_postNeg = CONST_POSTNEG_POSITIVE;
		$$ -> m_valueType = TYPE_INTERGER;
		$$ -> m_int = $1;
	}
	| LETTER {
		$$ = new Const_Value();
		$$ -> m_postNeg = CONST_POSTNEG_NULL;
		$$ -> m_valueType = TYPE_CHAR;
		$$ -> m_char = $1;
	}
	| BOOL {
		$$ = new Const_Value();
		$$ -> m_postNeg = CONST_POSTNEG_NULL;
		$$ -> m_valueType = TYPE_BOOLEAN;
		$$ -> m_bool = $1;
	}

/*
type_declarations 
	: TYPE type_declaration ';' {

	}

type_declaration 
	: type_declaration ';' IDENTIFIER '=' type
	| IDENTIFIER '=' type
	;

type 
	: standard_type
	| RECORD record_body END
	| ARRAY '[' periods ']' OF type
	;


standard_type 
	: INTEGER
	| REAL
	| BOOLEAN
	| CHAR
	;

record_body 
	: var_declaration
	;

periods 
	: periods ',' period
	| period
	;

period 
	: const_variable SUBBOUNDARY const_variable
*/

var_declarations 
	: VAR var_declaration ';' {
		$$ = new Var_Declarations($2 -> mv_Var);
	}
	| {
		vector<p_Var> tmp;
		$$ = new Var_Declarations(tmp);
	}
	;

var_declaration 
	: var_declaration ';' identifier_list ':' type {
		$$ = new Var_Declaration($1 -> mv_Var);
		$$ -> mv_Var.push_back(p_Var($3, $5));
	}
	| identifier_list ':' type {
		$$ = new Var_Declaration();
		$$ -> mv_Var.push_back(p_Var($1, $3));
	}
	;

type 
	: standard_type {
		$$ = new Type();
		$$ -> m_simpleType = $1;
		$$ -> m_isArray = false;
		$$ -> m_lineno = yylineno; 
	}
	| ARRAY '[' period ']' OF standard_type {
		$$ = new Type();
		$$ -> m_lineno = yylineno;
		$$ -> m_isArray = true;
		$$ -> mp_Period = $3;
		$$ -> m_simpleType = $6; 
	}
	;

standard_type 
	: INTEGER {
		$$ = TYPE_INTERGER;
	}
	| REAL {
		$$ = TYPE_REAL;
	}
	| BOOLEAN {
		$$ = TYPE_BOOLEAN;
	}
	| CHAR {
		$$ = TYPE_CHAR;
	}
	;


period 
	: period ',' SDIGITS SUBBOUNDARY SDIGITS {
		$$ = new Period($1 -> mv_dims);
		$$ -> mv_dims.push_back(p_Per($3, $5));
	}
	| SDIGITS SUBBOUNDARY SDIGITS {
		$$ = new Period();
		$$ -> mv_dims.push_back(p_Per($1, $3));
	}

SDIGITS
	: DIGITS{
		$$ = $1;
	}	
	| '+' DIGITS{
		$$ = $2;
	}
	| '-' DIGITS{
		$$ = -$2;
	}






subprogram_declarations 
	: subprogram_declarations subprogram ';' {
		$$ = new SubProgram_Declarations($1 -> mv_Common);
		$$ -> mv_Common.push_back($2);
	}
	| {
		$$ = new SubProgram_Declarations();
	}
	;

subprogram
	: subprogram_head subprogram_body {
		if($1 -> Simple_Type == TYPE_NULL) {
			$$ = new Procedure(yylineno, $1 -> m_ID, $1-> m_Formal_Parameter -> m_Parameter_List, $2 -> m_Const_Declarations, $2 -> m_Var_Declarations, $2-> m_Compound_Statement -> m_Statement_List);
		}
		else {
			$$ = new Function($1 -> Simple_Type, yylineno, $1 -> m_ID, $1-> m_Formal_Parameter -> m_Parameter_List, $2 -> m_Const_Declarations, $2 -> m_Var_Declarations, $2-> m_Compound_Statement -> m_Statement_List);
		}
	}

subprogram_head 
	: FUNCTION IDENTIFIER formal_parameter ':' standard_type ';' {
		Id* tmp = new Id();
		tmp -> m_name = *($2);
		tmp -> m_lineno = yylineno;
		$$ = new Subprogram_Head(tmp, $3, $5);
	}
	| PROCEDURE IDENTIFIER formal_parameter ';' {
		Id* tmp = new Id();
		tmp -> m_name = *($2);
		tmp -> m_lineno = yylineno;
		$$ = new Subprogram_Head(tmp, $3, TYPE_NULL);
	}
	;

formal_parameter 
	: '(' parameter_list ')' {
		$$ = new Formal_Parameter($2);
	}
	| {
		$$ = new Formal_Parameter(NULL);
	}
	;

parameter_list 
	: parameter_list ';' parameter {
		$$ = new Parameter_List(yylineno, $1 -> mv_Patameter);
		$$ -> mv_Patameter.push_back($3);
	}
	| parameter {
		$$ = new Parameter_List();
		$$ -> m_lineno = yylineno;
		$$ -> mv_Patameter.push_back($1);
	}
	;

parameter
	: var_parameter {
		$$ = new Parameter(true, yylineno, $1 -> m_Value_Parameter -> m_Id_List);
		$$ -> m_Type = $1 -> m_Value_Parameter -> Simple_Type;

	}
	| value_parameter {
		$$ = new Parameter(false, yylineno, $1 -> m_Id_List);
		$$ -> m_Type = $1 -> Simple_Type;
	}
	;

var_parameter 
	: VAR value_parameter {
		$$ = new Var_Parameter($2);
	}
	;

value_parameter 
	: identifier_list ':' standard_type {
		$$ = new Value_Parameter($1, $3);
	}
	;

subprogram_body 
	: const_declarations var_declarations compound_statement {
		$$ = new Subprogram_Body($1, $2, $3);
	}
	/*
	| error const_declarations var_declarations compound_statement{
		$$ = new Subprogram_Body(NULL,NULL,NULL);
	}
	*/

compound_statement 
	: BEGIN_L statement_list END {
		$$ = new Compound_Statement($2);
	}
	;

statement_list 
	: statement_list ';' statement {
		$$ = new Statement_List($1 -> mv_Statement);
		if($3 != NULL)
			$$ -> mv_Statement.push_back($3);
	}
	| statement {
		$$ = new Statement_List();
		if($1 != NULL)
			$$ -> mv_Statement.push_back($1);
	}
	| statement_list ';' error {
		$$ = new Statement_List();
	}
	| error {
		$$ = new Statement_List();
	}
	;

/*
statement 
	: variable ASSIGNOP expression
	| call_procedure_statement
	| compound_statement
	| IF expression THEN statement else_part
	| CASE expression OF case_body END
	| WHILE expression DO statement
	| REPEAT statement_list UNTIL expression
	| FOR IDENTIFIER ASSIGNOP expression updown expression DO statement
	|
	;
*/
statement 
	: variable ASSIGNOP expression {	//赋值
		$$ = new Statement();
		$$ -> m_stateType = STATEMENT_ASSIGN;
		$$ -> m_lineno = yylineno;
		$$ -> mp_Assignop = new Assignop($1, $3);
		$$ -> mp_Assignop -> m_lineno = yylineno;
		$$ -> mp_Procedure_call = NULL;
		$$ -> mp_Statement_List = NULL;
		$$ -> mp_If_Then_Else = NULL;
		$$ -> mp_For = NULL;
	}
	| call_procedure_statement {	//函数
		$$ = new Statement();
		$$ -> m_stateType = STATEMENT_PROCEDURE;
		$$ -> m_lineno = yylineno;
		$$ -> mp_Procedure_call = $1;
		$$ -> mp_Assignop = NULL;
		$$ -> mp_Statement_List = NULL;
		$$ -> mp_If_Then_Else = NULL;
		$$ -> mp_For = NULL;
	}
	| compound_statement {	//函数内部
		$$ = new Statement();
		$$ -> m_stateType = STATEMENT_COMPOUND;
		$$ -> m_lineno = yylineno;
		$$ -> mp_Statement_List = $1 -> m_Statement_List;
		$$ -> mp_Assignop = NULL;
		$$ -> mp_Procedure_call = NULL;
		$$ -> mp_If_Then_Else = NULL;
		$$ -> mp_For = NULL;
	}
	| IF expression THEN statement else_part {	//if语句
		$$ = new Statement();
		$$ -> m_stateType = STATEMENT_IF;
		$$ -> m_lineno = yylineno;
		$$ -> mp_If_Then_Else = new If_Then_Else($2, $4, $5);
		$$ -> mp_Assignop = NULL;
		$$ -> mp_Procedure_call = NULL;
		$$ -> mp_Statement_List = NULL;
		$$ -> mp_For = NULL;
	}
	/*
	| IF error THEN statement else_part {
		$$ = new Statement();
		$$ -> m_stateType = STATEMENT_IF;
		$$ -> m_lineno = yylineno;
		$$ -> mp_If_Then_Else = new If_Then_Else(new Expression(), $4, $5);
		$$ -> mp_Assignop = NULL;
		$$ -> mp_Procedure_call = NULL;
		$$ -> mp_Statement_List = NULL;
		$$ -> mp_For = NULL;
	}
	*/
	/*
	| IF expression THEN error else_part {
		$$ = new Statement();
		$$ -> m_stateType = STATEMENT_IF;
		$$ -> m_lineno = yylineno;
		$$ -> mp_If_Then_Else = new If_Then_Else($2, new Statement(), $5);
		$$ -> mp_Assignop = NULL;
		$$ -> mp_Procedure_call = NULL;
		$$ -> mp_Statement_List = NULL;
		$$ -> mp_For = NULL;
	}
	*/
	| FOR IDENTIFIER ASSIGNOP expression TO expression DO statement {	//for循环
		Id* tmp = new Id();
		tmp -> m_name = *($2);
		tmp -> m_lineno = yylineno;
		$$ = new Statement();
		$$ -> m_stateType = STATEMENT_FOR;
		$$ -> m_lineno = yylineno;
		$$ -> mp_For = new For(tmp, $4, $6, $8);
		$$ -> mp_Assignop = NULL;
		$$ -> mp_Procedure_call = NULL;
		$$ -> mp_Statement_List = NULL;
		$$ -> mp_If_Then_Else = NULL;
	}
	| {
		$$ = NULL;
	}
	;


variable 
	: IDENTIFIER id_varpart {
		Id* tmp = new Id();
		tmp -> m_name = *($1);
		tmp -> m_lineno = yylineno;
		$$ = new Variable();
		$$ -> mp_Id = tmp;
		$$ -> m_lineno = yylineno;
		if($2 -> m_Expression_List != NULL){
			$$ -> m_isArray = true;
			$$ -> mp_Expression_List = $2 -> m_Expression_List;
		}else {
			$$ -> m_isArray =false;
			$$ -> mp_Expression_List = NULL;
		}
	}

/*
id_varparts 
	: id_varparts id_varpart
	|
	;
*/

id_varpart 
	: '[' expression_list ']' {
		$$ = new Id_Varpart($2);
	}
	| {
		$$ = new Id_Varpart(NULL);
	}
	;	

call_procedure_statement 
	: IDENTIFIER {
		Id* tmp = new Id();
		tmp -> m_name = *($1);
		tmp -> m_lineno = yylineno;
		$$ = new Procedure_Call();
		$$ -> m_lineno = yylineno;
		$$ -> m_expNum = 0;
		$$ -> mp_Id = tmp;
		$$ -> mp_Expression_List = NULL;

	}
	| IDENTIFIER '(' expression_list ')' {
		$$ = new Procedure_Call();
		$$ -> m_lineno = yylineno;
		$$ -> m_expNum = $3 -> mv_Expression.size();
		Id* tmp = new Id();
		tmp -> m_name = *($1);
		tmp -> m_lineno = yylineno;
		$$ -> mp_Id = tmp;
		$$ -> mp_Expression_List = $3;
	}
	;

else_part 
	: ELSE statement {
		$$ = $2;
	}	
	| {
		$$ = NULL;
	}
	;

/*
case_body : branch_list
|
;

branch_list :branch_list ';' branch
| branch
;


branch : const_list ':' statement

const_list : const_list ';' const_variable
| const_variable 
;     

updown : TO
| DOWNTO
;
*/


expression_list 
	: expression_list ',' expression {
		$$ = new Expression_List($1 -> mv_Expression, $1 -> mv_Type);
		$$ -> mv_Expression.push_back($3);
	}
	| expression {
		$$ = new Expression_List();
		$$ -> mv_Expression.push_back($1);
	}
	;

expression 
	: simple_expression '>' simple_expression {
		$$ = new Expression();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Simple_Expression = NULL;
		$$ -> mp_Relop = new Relop(RELOP_LARGE, yylineno, $1, $3);
	}
	| simple_expression '<' simple_expression {
		$$ = new Expression();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Simple_Expression = NULL;
		$$ -> mp_Relop = new Relop(RELOP_LESS, yylineno, $1, $3);
	}
	| simple_expression NE_OP simple_expression {
		$$ = new Expression();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Simple_Expression = NULL;
		$$ -> mp_Relop = new Relop(RELOP_NOT_EQUAL, yylineno, $1, $3);
	}
	| simple_expression LE_OP simple_expression {
		$$ = new Expression();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Simple_Expression = NULL;
		$$ -> mp_Relop = new Relop(RELOP_LESS_EQUAL, yylineno, $1, $3);
	}
	| simple_expression GE_OP simple_expression {
		$$ = new Expression();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Simple_Expression = NULL;
		$$ -> mp_Relop = new Relop(RELOP_LARGE_EQUAL, yylineno, $1, $3);
	}
	| simple_expression '=' simple_expression {
		$$ = new Expression();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Simple_Expression = NULL;
		$$ -> mp_Relop = new Relop(RELOP_EQUAL, yylineno, $1, $3);
	}
	| simple_expression {
		$$ = new Expression();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Simple_Expression = $1;
		$$ -> mp_Relop = NULL;
	}
	;

simple_expression 
	: term {
		$$ = new Simple_Expression(yylineno, NULL, $1);
	}
	| simple_expression '+' term {
		$$ = new Simple_Expression(yylineno, new Addop(ADDOP_ADD, yylineno, $1, $3),NULL);
	}
	| simple_expression '-' term {
		$$ = new Simple_Expression(yylineno, new Addop(ADDOP_SUB, yylineno, $1, $3),NULL);
	}
	| simple_expression OR term {
		$$ = new Simple_Expression(yylineno, new Addop(ADDOP_OR, yylineno, $1, $3),NULL);
	}
	;

term 
	: term '*' factor {
		$$ = new Term(yylineno, new Mulop(MULOP_MULTIPLY, yylineno, $1, $3), NULL);
	}
	| term '/' factor {
		$$ = new Term(yylineno, new Mulop(MULOP_REAL_DIV, yylineno, $1, $3), NULL);
	}
	| term AND factor {
		$$ = new Term(yylineno, new Mulop(MULOP_AND, yylineno, $1, $3), NULL);
	}
	| term DIV factor {
		$$ = new Term(yylineno, new Mulop(MULOP_INT_DIV, yylineno, $1, $3), NULL);
	}
	| term MOD factor {
		$$ = new Term(yylineno, new Mulop(MULOP_MOD, yylineno, $1, $3), NULL);
	}
	| factor {
		$$ = new Term(yylineno, NULL, $1);
	}
	;

SNUMBER: NUMBER{
		$$ = $1;
	}
	| '-' NUMBER{
		$$ = -$2;
	}

factor 
	: SDIGITS {
		$$ = new Factor();
		$$ -> m_lineno = yylineno;
		$$ -> m_int = $1;
		$$ -> m_factorType = FACTOR_VALUE_INT;
	}
	| SNUMBER {
		$$ = new Factor();
		$$ -> m_lineno = yylineno;
		$$ -> m_real = $1;
		$$ -> m_factorType = FACTOR_VALUE_REAL;
	}
	| LETTER {
		$$ = new Factor();
		$$ -> m_lineno = yylineno;
		$$ -> m_char = $1;
		$$ -> m_factorType = FACTOR_VALUE_CHAR;
	}
	| BOOL {
		$$ = new Factor();
		$$ -> m_lineno = yylineno;
		$$ -> m_bool = $1;
		$$ -> m_factorType = FACTOR_VALUE_BOOL;
	}
	| variable {
		$$ = new Factor();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Variable = $1;
		$$ -> mp_Function_Call = NULL;
		$$ -> mp_Expression = NULL;
		$$ -> mp_Not = NULL;
		$$ -> mp_Uminus = NULL;
		$$ -> m_factorType = FACTOR_VAR;
	}
	| IDENTIFIER '(' expression_list ')' {
		$$ = new Factor();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Variable = NULL;
		Id* tmp = new Id();
		tmp -> m_name = *($1);
		tmp -> m_lineno = yylineno;
		$$ -> mp_Function_Call = new Function_Call($3 -> mv_Expression.size(), yylineno, tmp, $3);
		$$ -> mp_Expression = NULL;
		$$ -> mp_Not = NULL;
		$$ -> mp_Uminus = NULL;
		$$ -> m_factorType = FACTOR_FUNCCALL;
	}
	| IDENTIFIER '(' ')'{
		$$ = new Factor();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Variable = NULL;
		Id* tmp = new Id();
		tmp -> m_name = *($1);
		tmp -> m_lineno = yylineno;
		$$ -> mp_Function_Call = new Function_Call(0, yylineno, tmp, NULL);
		$$ -> mp_Expression = NULL;
		$$ -> mp_Not = NULL;
		$$ -> mp_Uminus = NULL;
		$$ -> m_factorType = FACTOR_FUNCCALL;
	}
	| '(' expression ')' {
		$$ = new Factor();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Variable = NULL;
		$$ -> mp_Function_Call = NULL;
		$$ -> mp_Expression = $2;
		$$ -> mp_Not = NULL;
		$$ -> mp_Uminus = NULL;
		$$ -> m_factorType = FACTOR_BRACKETS;
	}
	| NOT factor {
		$$ = new Factor();
		$$ -> m_lineno = yylineno;
		$$ -> mp_Variable = NULL;
		$$ -> mp_Function_Call = NULL;
		$$ -> mp_Expression = NULL;
		$$ -> mp_Not = new Not();
		$$ -> mp_Not -> mp_Factor = $2;
		$$ -> mp_Not -> m_lineno = yylineno;
		$$ -> mp_Uminus = NULL;
		$$ -> m_factorType = FACTOR_NOT;
	}

	;
%%


int Lexic_Syntax() {
	yydebug = 0;
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