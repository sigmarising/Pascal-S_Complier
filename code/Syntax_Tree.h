//	File Name	: Syntax_Tree.h
//	Notes		: Define the Syntax Tree DataStructure
//	Version		: 0.6
//	Author		: Yun Zhang
//				: Boxi Cao

#pragma once

#include <vector>
#include <string>
using namespace std;

// class declare
class Programstruct;
class Program_Body;
class Const_Declarations;
class Var_Declarations;
class SubProgram_Declarations;
class Statement_List;
class Common;
class Procedure;
class Function;
class Statement;
class Parameter_List;
class Variable;
class Procedure_Call;
class Function_Call;
class Expression;
class Simple_Expression;
class Term;
class Factor;
class Not;
class Uminus;
class Type;
class Const_Value;
class Assignop;
class If_Then_Else;
class For;
class Parameter;
class Relop;
class Addop;
class Mulop;
class Id;
class Id_List;
class Period;
class Expression_List;

// 以下类都是在抽象语法树中没有的类，为实现翻译方案而创建
class Program_Head;
class Compound_Statement;
class Const_Declaration;
class Var_Declaration;
class SubProgram_Declaration;
class Subprogram;
class Subprogram_Head;
class Subprogram_Body;
class Formal_Parameter;
class Var_Parameter;
class Value_Parameter;
class Id_Varpart;


// class define

//	Program Total node
//	The Root of Syntax Tree
class Programstruct {
public:
	Programstruct(Id * Mp_Id,Id_List *Mp_Id_List,Program_Body *Mp_Program_Body){
        mp_Id=Mp_Id;
        mp_Id_List=Mp_Id_List;
        mp_Program_Body=Mp_Program_Body;
	}
	~Programstruct();

	string func_codeGeneration();
	bool error_detect(string);

	Id * mp_Id;
	Id_List			*mp_Id_List;
	Program_Body	*mp_Program_Body;
};

//	Define the Main Program body
//	include four parts
class Program_Body {
public:
	Program_Body(Const_Declarations *Mp_Const_Declarations,Var_Declarations	*Mp_Var_Declarations,SubProgram_Declarations *Mp_SubProgram_Declarations,Compound_Statement *Mp_Compound_Statements){
        mp_Const_Declarations=Mp_Const_Declarations;
        mp_Var_Declarations=Mp_Var_Declarations;
        mp_SubProgram_Declarations=Mp_SubProgram_Declarations;
        mp_Statement_List=Mp_Compound_Statements->m_Statement_List;
	}
	~Program_Body();

	string func_codeGeneration();
	bool error_detect(string);

	Const_Declarations		*mp_Const_Declarations;
	Var_Declarations		*mp_Var_Declarations;
	SubProgram_Declarations	*mp_SubProgram_Declarations;
	Statement_List			*mp_Statement_List;
};

//	Const Block
class Const_Declarations {
public:
	Const_Declarations(){};
	Const_Declarations(vector<pair<Id*, Const_Value*>> Mv_Const){
        mv_Const=Mv_Const;
	}
	~Const_Declarations();

	string func_codeGeneration();

	vector<pair<Id*, Const_Value*> >mv_Const;
};

//	Var Block
class Var_Declarations {
public:
	Var_Declarations();
	Var_Declarations(vector<pair<Id_List*, Type*> > Mv_Var){
        mv_Var=Mv_Var;
	}
	~Var_Declarations();

	string func_codeGeneration();

	vector<pair<Id_List*, Type*> >mv_Var;
};

//	SubProgram Block
//	Define the functions and procedures
class SubProgram_Declarations {
public:
	SubProgram_Declarations();
	SubProgram_Declarations(vector<Common*> Mv_Common){
        mv_Common=Mv_Common;
	}
	~SubProgram_Declarations();

	string	func_codeGeneration();
	void	func_checkType();

	vector<Common*>mv_Common;

};

//	contain many statements
class Statement_List {
public:
	Statement_List();
	Statement_List(vector<Statement*>Mv_Statement){
        mv_Statement=Mv_Statement;
	}
	~Statement_List();

	string func_codeGeneration();
	bool error_detect(string);

	vector<Statement*>mv_Statement;
};

class Common {
public:
	Common();
	virtual ~Common() = 0;

	virtual string func_codeGeneration() = 0;
	virtual int func_get_Common_Type() {
		return -1;
	}

private:

};

//	the Precodure block
class Procedure : public Common {
public:
	Procedure(int M_lineno,Id *Mp_Id,Parameter_List *Mp_Parameter_List,Const_Declarations *Mp_Const_Declarations,Var_Declarations *Mp_Var_Declarations,Statement_List *Mp_Statement_List){
        m_lineno=M_lineno;
        mp_Id=Mp_Id;
        mp_Parameter_List=Mp_Parameter_List;
        mp_Const_Declarations=Mp_Const_Declarations;
        mp_Var_Declarations=Mp_Var_Declarations;
        mp_Statement_List=Mp_Statement_List;
	}
	~Procedure();

	string	func_codeGeneration();
	int		func_get_Common_Type() {
		return COMMON_PROCEDURE;
	}

private:
	int m_lineno;

	Id					*mp_Id;
	Parameter_List		*mp_Parameter_List;
	Const_Declarations	*mp_Const_Declarations;
	Var_Declarations	*mp_Var_Declarations;
	Statement_List		*mp_Statement_List;
};

//	the Function block
class Function : public Common {
public:
	Function(int M_returnType,int M_lineno,Id *Mp_Id,Parameter_List *Mp_Parameter_List,Const_Declarations *Mp_Const_Declarations,Var_Declarations *Mp_Var_Declarations,Statement_List *Mp_Statement_List){
        m_returnType=M_returnType;
        m_lineno=M_lineno;
        mp_Id=Mp_Id;
        mp_Parameter_List=Mp_Parameter_List;
        mp_Const_Declarations=Mp_Const_Declarations;
        mp_Var_Declarations=Mp_Var_Declarations;
        mp_Statement_List=Mp_Statement_List;
	}
	~Function();

	string	func_codeGeneration();
	int 	func_checkReturnType() {
		return m_returnType;
	}
	int		func_get_Common_Type() {
		return COMMON_FUNCTION;
	}


private:
	int m_returnType;
	int m_lineno;

	Id					*mp_Id;
	Parameter_List		*mp_Parameter_List;
	Const_Declarations	*mp_Const_Declarations;
	Var_Declarations	*mp_Var_Declarations;
	Statement_List		*mp_Statement_List;
};

//	the statements are partitioned by ';'
class Statement {
public:
	Statement();
	~Statement();

	string	func_codeGeneration();
	void	func_checkType();
	bool error_detect(string symbol_sheet_name);

	int m_stateType;
	int m_lineno;

	//	the below pointers
	//	only one can be assigned to non-NULL
	//	the others must be null
	Assignop		*mp_Assignop;
	Procedure_Call	*mp_Procedure_call;		// which include the read and write call
	Statement_List	*mp_Statement_List;		// which refered to begin-block-end
	If_Then_Else	*mp_If_Then_Else;
	For				*mp_For;
};

// only used for function or procedure define
class Parameter_List {
public:
	Parameter_List();
	Parameter_List(int M_lineno,vector<Parameter*> Mv_Patameter){
        m_lineno=M_lineno;
        mv_Patameter=Mv_Patameter;
	}
	~Parameter_List();

	string func_codeGeneration();

	int m_lineno;

	vector<Parameter*> mv_Patameter;
};

//	define the variable type
class Variable {
public:
	Variable();
	~Variable();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

	bool	m_isArray;
	int		m_lineno;

	Id				*mp_Id;

	//	default to be null
	//
	//	if m_isArray == true
	//	this pointer point to the index of array(multi-dimension)
	//		partition by ',' in pascal
	Expression_List	*mp_Expression_List;
};

//	belong to statement
class Procedure_Call {
public:
	Procedure_Call();
	~Procedure_Call();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

	int	m_proCall_Tpye;

	int m_expNum;
	int m_lineno;

	Id				*mp_Id;
	Expression_List	*mp_Expression_List;
};

class Function_Call {
public:
	Function_Call();
	~Function_Call();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

	int m_expNum;
	int m_lineno;

	Id				*mp_Id;
	Expression_List	*mp_Expression_List;
};

// the expression can be calculate to a value
class Expression {
public:
	Expression();
	~Expression();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);
	void setType(int _type) { type = _type; };
	int getType() { return type; }
private:
	int m_lineno;
	

	//  the below two pointers
	//	only one can be assign to non-NULL
	//	the other must be NULL
	Relop				*mp_Relop;
	Simple_Expression	*mp_Simple_Expression;
	int type;
};

// belong to expression
class Simple_Expression {
public:
	Simple_Expression(int M_lineno,Addop *Mp_Addop,Term	*Mp_Term){
	    m_lineno=M_lineno;
	    mp_Addop=Mp_Addop;
	    mp_Term=Mp_Term;
	}
	~Simple_Expression();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);
	void setType(int _type) { type = _type; };
	int getType() { return type };
private:
	int m_lineno;
	int type;
	//  the below two pointers
	//	only one can be assign to non-NULL
	//	the other must be NULL
	Addop	*mp_Addop;
	Term	*mp_Term;
};

class Term {
public:
	Term(int M_lineno,Mulop	*Mp_Mulop,Factor	*Mp_Factor){
        m_lineno=M_lineno;
        mp_Mulop=Mp_Mulop;
        mp_Factor=Mp_Factor;
	}
	    ~Term();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);
	void setType(int _type) { type = _type; }
	int getType() { return type; };
private:
	int m_lineno;
	int type;
	//  the below two pointers
	//	only one can be assign to non-NULL
	//	the other must be NULL
	Mulop	*mp_Mulop;
	Factor	*mp_Factor;
};

// the smallest value unit
class Factor {
public:
	Factor();
	~Factor();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

	int	func_checkFactorType() {
		return m_factorType;
	}

	int		m_int;
	float	m_real;
	char	m_char;
	bool	m_bool;

	int m_factorType;
	int m_lineno;

	//	the below pointers
	//	only one can be assigned to non-NULL
	//	the others must be null
	Variable		*mp_Variable;
	Function_Call	*mp_Function_Call;
	Expression		*mp_Expression;
	Not				*mp_Not;
	Uminus			*mp_Uminus;
};

//	the operator 'not'
class Not {
public:
	Not();
	~Not();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

private:
	int m_lineno;

	Factor	*mp_Factor;
};

//	the operator + -
//	as for:
//		-1 +2 -i +j
class Uminus {
public:
	Uminus();
	~Uminus();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

private:
	int m_lineno;
	int m_unimusType;

	Factor	*mp_Factor;
};

// only used for var block
class Type {
public:
	Type();
	~Type();

	string	func_codeGeneration();
	string  func_code_getperiod();

	int		func_checkSimpleType() {
		return m_simpleType;
	}
	bool    func_check_isArray() {
		return m_isArray;
	}

	vector<pair<int, int>> func_get_Period();



private:
	int		m_simpleType;
	bool	m_isArray;
	int		m_lineno;

	//	if m_isArray == true
	//	this pointer will point to the period(multi-dimension)
	Period	*mp_Period;
};

//	used for const block
class Const_Value {
public:
	Const_Value();

	~Const_Value();

	string	func_codeGeneration();
	int		func_checkValueType() {
		return m_valueType;
	}


	int		m_postNeg;
	int		m_valueType;

	// the below value are all unsigned
	int		m_int;
	float	m_real;
	char	m_char;
	bool	m_bool;

	int		m_lineno;
	bool	m_isId;

	//	if m_isId == true
	//	this pointer point to the refered ID
	Id	*mp_Id;
};

class Assignop {
public:
	Assignop();
	~Assignop();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);
private:
	int m_lineno;

	Variable	*mp_Variable;
	Expression	*mp_Expression;
};

class If_Then_Else {
public:
	If_Then_Else();
	~If_Then_Else();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

private:
	int m_lineno;

	Expression	*mp_Expression;
	Statement	*mp_Statement_1;
	Statement	*mp_Statement_2;
};

class For {
public:
	For();
	~For();

	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

private:
	int m_lineno;

	Id			*mp_Id;
	Expression	*mp_Expression_1;
	Expression	*mp_Expression_2;
	Statement	*mp_Statment;
};

class Parameter {
public:
	Parameter(bool	M_isVal,int	M_lineno,Id_List	*Mp_Id_List){
        m_isVal=M_isVal;
        m_lineno=M_lineno;
        mp_Id_List=Mp_Id_List;
	}
	~Parameter();

	string	func_codeGeneration();
	bool	func_isVal() {
		return m_isVal;
	}
	vector<Id*> func_get_mv_id();

	int			func_get_m_type() {
		return m_Type;
	}

private:
	// define whether the parameter is variable element
	bool	m_isVal;
	int		m_lineno;
	int		m_Type;

	Id_List	*mp_Id_List;

};

class Relop {
public:
	Relop();
	~Relop();

	string	func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

	int		func_checkRelopType() {
		return m_relopType;
	}

private:
	int m_relopType;
	int m_lineno;

	Simple_Expression *mp_Simple_Expression_1;
	Simple_Expression *mp_Simple_Expression_2;
};

class Addop {
public:
	Addop();
	~Addop();

	string	func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

	int		func_checkAddopType() {
		return m_addopType;
	}
	void func_checkAddopType(int _type)
	{
		m_addopType = _type;
	}


private:
	int m_addopType;
	int m_lineno;

	Simple_Expression	*mp_Simple_Expression;
	Term				*mp_Term;
};

class Mulop {
public:
	Mulop();
	~Mulop();

	string	func_codeGeneration();
	bool error_detect(string symbol_sheet_name);
	int		func_checkMulopType() {
		return m_mulopType;
	}
	void setType(int _type) { m_mulopType = _type; }

private:
	int m_mulopType;
	int m_lineno;

	Term	*mp_Term;
	Factor	*mp_Factor;
};

class Id{
public:
	Id();
	~Id();

	string	func_codeGeneration();
	void	func_checkType();
	string	func_getName() {
		return m_name;
	}
	bool	func_isVal() {
		return m_isVal;
	}

	string	m_name;
	int		m_idType;
	int		m_lineno;

	// This note only used in function and procedure
	// to identify whether the id
	// is a variable element parameter declaration
	//
	// default to be false
	//
	bool	m_isVal;
};

class Id_List {
public:
	Id_List();
	~Id_List();

	string			func_codeGeneration();
	vector<Id*>		func_get_mv_Id() {
		return mv_Id;
	}

	int m_lineno;

	vector<Id*>mv_Id;
};

class Period {
public:
    Period();
	Period(vector<pair<int, int>> Mv_dims){
	    mv_dims=Mv_dims;
	}
	~Period();

	string					func_codeGeneration();
	vector<pair<int, int>>	func_get_Range() {
		return mv_dims;
	}


private:
	// record the multi-dimension ranges
	vector<pair<int, int>>mv_dims;

};

class Expression_List {
public:
	Expression_List();
	Expression_List(vector<Expression*>Mv_Expression,vector<int> MType){
        mv_Expression=Mv_Expression;
        mv_Type=MType;
	}
	~Expression_List();
	string func_codeGeneration();
	bool error_detect(string symbol_sheet_name);

	vector<Expression*> func_get_mv_exp() {
		return mv_Expression;
	}
	vector<int>			func_get_mv_type() {
		return mv_Type;
	}

	vector<Expression*>mv_Expression;

	// store the Type of each expression
	// allowed type:
	//		TYPE_INTERGER
	//		TYPE_REAL
	//		TYPE_CHAR
	vector<int>mv_Type;
};


//	以下类都是在抽象语法树中没有的类
class Program_Head {
public:
	Program_Head(Id * M_Id,Id_List *M_Id_List){
        m_Id=M_Id;
        m_Id_List=M_Id_List;
	}
	~Program_Head();

	Id * m_Id;
	Id_List *m_Id_List;

};
class Compound_Statement{
public:
	Compound_Statement(Statement_List * M_Statement_List){
        m_Statement_List=M_Statement_List;
	}
	~Compound_Statement();

	Statement_List * m_Statement_List;

};
class Const_Declaration {
public:
	Const_Declaration();
	Const_Declaration(vector<pair<Id*, Const_Value*>> Mv_Const){
        mv_Const=Mv_Const;
	}
	~Const_Declaration();

	vector<pair<Id*, Const_Value*>> mv_Const;
};

class Var_Declaration {
public:
	Var_Declaration();
	Var_Declaration(vector<pair<Id_List*, Type*>> Mv_Var){
        mv_Var=Mv_Var;
	}
	~Var_Declaration();

	vector<pair<Id_List*, Type*>> mv_Var;

};

class SubProgram_Declaration {
public:
	SubProgram_Declaration();
	~SubProgram_Declaration();

private:
	vector<Subprogram*> mv_Subprogram;

};

class Subprogram {
public:
	Subprogram();
	~Subprogram();

private:
	Subprogram_Head * m_Subprogram_Head;
	Subprogram_Body *m_Subprogram_Body;

};
class Subprogram_Head {
public:
	Subprogram_Head(Id * M_ID,Formal_Parameter *M_Formal_Parameter,int SType){
        m_ID=M_ID;
        m_Formal_Parameter=M_Formal_Parameter;
        Simple_Type=SType;
	}
	~Subprogram_Head();

	Id * m_ID;
	Formal_Parameter *m_Formal_Parameter;
	int Simple_Type;

};

class Subprogram_Body {
public:
	Subprogram_Body(Const_Declarations * M_Const_Declarations,Var_Declarations *M_Var_Declarations,Compound_Statement *M_Compound_Statement){
        m_Const_Declarations=M_Const_Declarations;
        m_Var_Declarations=M_Var_Declarations;
        m_Compound_Statement=M_Compound_Statement;
	}
	~Subprogram_Body();

private:
	Const_Declarations * m_Const_Declarations;
	Var_Declarations *m_Var_Declarations;
	Compound_Statement *m_Compound_Statement;
};

class Formal_Parameter {
public:
	Formal_Parameter(Parameter_List * M_Parameter_List){
        m_Parameter_List=M_Parameter_List;
	}
	~Formal_Parameter();

private:
	Parameter_List * m_Parameter_List;

};
class Var_Parameter {
public:
	Var_Parameter(Value_Parameter * M_Value_Parameter){
	    m_Value_Parameter=M_Value_Parameter;
	}
	~Var_Parameter();

private:
	Value_Parameter * m_Value_Parameter;



};
class Value_Parameter {
public:
	Value_Parameter(Id_List *M_Id_List,int SType){
	    M_Id_List=M_Id_List;
	    Simple_Type=SType;
	}
	~Value_Parameter();

	int Simple_Type;
	Id_List * m_Id_List;
};
class Id_Varpart{
public:
	Id_Varpart();
	Id_Varpart(Expression_List *M_Expression_List){
       m_Expression_List=M_Expression_List;
	}
	~Id_Varpart();
private:
	Expression_List *m_Expression_List;	//这个指针可以为NULL
};
