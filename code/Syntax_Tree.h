
//    File Name    : Syntax_Tree.h
//    Notes        : Define the Syntax Tree DataStructure
//    Version        : 0.6
//    Author        : Yun Zhang
//                : Boxi Cao

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Public_define.h"
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

//    以下类都是在抽象语法树中没有的类
class Program_Head {
public:
    Program_Head(Id * M_Id,Id_List *M_Id_List){
        m_Id=M_Id;
        m_Id_List=M_Id_List;
    }
    Program_Head(){
        m_Id=NULL;
        m_Id_List=NULL;
    };
    ~Program_Head();

    Id * m_Id;
    Id_List *m_Id_List;

};
class Compound_Statement{
public:
    Compound_Statement(Statement_List * M_Statement_List){
        m_Statement_List=M_Statement_List;
    }
    Compound_Statement(){
        m_Statement_List=NULL;
    };
    ~Compound_Statement();

    Statement_List * m_Statement_List;

};
class Const_Declaration {
public:
    Const_Declaration(){};
    Const_Declaration(vector<pair<Id*, Const_Value*> > Mv_Const){
        mv_Const=Mv_Const;
    }
    ~Const_Declaration();

    vector<pair<Id*, Const_Value*> > mv_Const;
};

class Var_Declaration {
public:
    Var_Declaration(){};
    Var_Declaration(vector<pair<Id_List*, Type*> > Mv_Var){
        mv_Var=Mv_Var;
    }
    ~Var_Declaration();

    vector<pair<Id_List*, Type*> > mv_Var;

};

class SubProgram_Declaration {
public:
    SubProgram_Declaration(){};
    ~SubProgram_Declaration();
    vector<Subprogram*> mv_Subprogram;

};

class Subprogram {
public:
    Subprogram(){
        m_Subprogram_Head=NULL;
        m_Subprogram_Body=NULL;
    };
    ~Subprogram();


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
    Subprogram_Head(){
        m_ID=NULL;
        m_Formal_Parameter=NULL;
        Simple_Type=0;
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
    Subprogram_Body(){
        m_Const_Declarations=NULL;
        m_Var_Declarations=NULL;
        m_Compound_Statement=NULL;
    }
    ~Subprogram_Body();


    Const_Declarations * m_Const_Declarations;
    Var_Declarations *m_Var_Declarations;
    Compound_Statement *m_Compound_Statement;
};

class Formal_Parameter {
public:
    Formal_Parameter(Parameter_List * M_Parameter_List){
        m_Parameter_List=M_Parameter_List;
    }
    Formal_Parameter(){
        m_Parameter_List=NULL;

    }
    ~Formal_Parameter();
    Parameter_List * m_Parameter_List;

};
class Var_Parameter {
public:
    Var_Parameter(Value_Parameter * M_Value_Parameter){
        m_Value_Parameter=M_Value_Parameter;
    }
    Var_Parameter(){
        m_Value_Parameter=NULL;
    }


    ~Var_Parameter();


    Value_Parameter * m_Value_Parameter;



};
class Value_Parameter {
public:
    Value_Parameter(Id_List *M_Id_List,int SType){
        m_Id_List=M_Id_List;
        Simple_Type=SType;
    }
    Value_Parameter(){
        Simple_Type=0;
        m_Id_List=NULL;
    }
    ~Value_Parameter();

    int Simple_Type;
    Id_List * m_Id_List;
};

class Id_Varpart{
public:
    Id_Varpart(Expression_List *M_Expression_List){
        m_Expression_List=M_Expression_List;
    }
    Id_Varpart(){
        m_Expression_List=NULL;
    }
    ~Id_Varpart();

    Expression_List *m_Expression_List;    //这个指针可以为NULL
};


//    Program Total node
//    The Root of Syntax Tree
class Programstruct {
public:
    Programstruct(Id * Mp_Id,Id_List *Mp_Id_List,Program_Body *Mp_Program_Body){
        mp_Id=Mp_Id;
        mp_Id_List=Mp_Id_List;
        mp_Program_Body=Mp_Program_Body;
    }
    Programstruct(){
        mp_Id=NULL;
        mp_Id_List=NULL;
        mp_Program_Body=NULL;
    }
    ~Programstruct();

    string func_codeGeneration();
    bool error_detect();

    Id * mp_Id;
    Id_List            *mp_Id_List;
    Program_Body    *mp_Program_Body;

    void outputTree();
};

//    Define the Main Program body
//    include four parts
class Program_Body {
public:
    Program_Body(Const_Declarations *Mp_Const_Declarations,Var_Declarations    *Mp_Var_Declarations,SubProgram_Declarations *Mp_SubProgram_Declarations,Compound_Statement *Mp_Compound_Statements){
        mp_Const_Declarations=Mp_Const_Declarations;
        mp_Var_Declarations=Mp_Var_Declarations;
        mp_SubProgram_Declarations=Mp_SubProgram_Declarations;
        mp_Statement_List=Mp_Compound_Statements -> m_Statement_List;
    }
    Program_Body(){
        mp_Const_Declarations=NULL;
        mp_Var_Declarations=NULL;
        mp_SubProgram_Declarations=NULL;
        mp_Statement_List=NULL;
    }
    ~Program_Body();

    string func_codeGeneration();
    pair<bool, string> create_symbolsheet();
    bool error_detect();

    Const_Declarations        *mp_Const_Declarations;
    Var_Declarations        *mp_Var_Declarations;
    SubProgram_Declarations    *mp_SubProgram_Declarations;
    Statement_List            *mp_Statement_List;

    void outputTree();
};

//    Const Block
class Const_Declarations {
public:
    Const_Declarations(vector<pair<Id*, Const_Value*> > Mv_Const){
        mv_Const=Mv_Const;
    }
    Const_Declarations(){

    };
    ~Const_Declarations();
    bool error_detect(string symbolSheet_name);
    string func_codeGeneration();

    vector<pair<Id*, Const_Value*> > mv_Const;

    void outputTree();
};

//    Var Block
class Var_Declarations {
public:
    Var_Declarations() {};
    Var_Declarations(vector<pair<Id_List*, Type*> > Mv_Var){
        mv_Var=Mv_Var;
    }
    ~Var_Declarations();
    bool error_detect(string symbolSheet_name);
    string func_codeGeneration();

    vector<pair<Id_List*, Type*> >mv_Var;

    void outputTree();
};

//    SubProgram Block
//    Define the functions and procedures
class SubProgram_Declarations {
public:
    SubProgram_Declarations(){};
    SubProgram_Declarations(vector<Common*> Mv_Common){
        mv_Common=Mv_Common;
    }
    ~SubProgram_Declarations();
    bool error_detect(string symbolSheet_name);
    bool definition_error_detect();
    string    func_codeGeneration();
    void    func_checkType();

    vector<Common*>mv_Common;

    void outputTree();

};

//    contain many statements
class Statement_List {
public:
    Statement_List(){};
    Statement_List(vector<Statement*>Mv_Statement){
        mv_Statement=Mv_Statement;
    }
    ~Statement_List();

    string func_codeGeneration();
    bool error_detect(string);

    vector<Statement*>mv_Statement;

    void outputTree();
};


class Common {
public:

     virtual string func_codeGeneration() = 0;
     virtual int func_checkReturnType() = 0;
     virtual int func_get_Common_Type() {
     return -1;
     }
     virtual pair<bool, string> create_symbolsheet() = 0;
     virtual bool error_detect() = 0;
     virtual Id * get_func_id() = 0;
     virtual Parameter_List * get_param_list() = 0;
     virtual Const_Declarations * get_const_dec() = 0;
     virtual Var_Declarations * get_var_dec() = 0;
     virtual int get_lineno() = 0;

     virtual void outputTree() = 0;

};

//    the Precodure block
class Procedure : public Common {
public:
    Procedure(int M_lineno,Id *Mp_Id,Parameter_List *Mp_Parameter_List,Const_Declarations *Mp_Const_Declarations,Var_Declarations *Mp_Var_Declarations,Statement_List *Mp_Statement_List);
    Procedure(){
        m_lineno=0;
        mp_Id=NULL;
        mp_Parameter_List=NULL;
        mp_Const_Declarations=NULL;
        mp_Var_Declarations=NULL;
        mp_Statement_List=NULL;
    }
    string    func_codeGeneration() override;
    int func_checkReturnType() override {
     return -1; // return VOID
     }
    int func_get_Common_Type() override {
     return COMMON_PROCEDURE;
     }
    pair<bool, string> create_symbolsheet() override;
    bool error_detect() override;
    Id * get_func_id() override {
     return mp_Id;
     }
    Parameter_List * get_param_list() override {
     return mp_Parameter_List;
     }
    Const_Declarations * get_const_dec() override {
     return mp_Const_Declarations;
     }
    Var_Declarations * get_var_dec() override {
     return mp_Var_Declarations;
     }
    int get_lineno() override {
     return m_lineno;
     }

    int m_lineno;

    Id                    *mp_Id;
    Parameter_List        *mp_Parameter_List;
    Const_Declarations    *mp_Const_Declarations;
    Var_Declarations    *mp_Var_Declarations;
    Statement_List        *mp_Statement_List;

    void outputTree();
};

//    the Function block
class Function : public Common {
public:
    Function(int M_returnType,int M_lineno,Id *Mp_Id,Parameter_List *Mp_Parameter_List,Const_Declarations *Mp_Const_Declarations,Var_Declarations *Mp_Var_Declarations,Statement_List *Mp_Statement_List);
    Function(){
        m_returnType=0;
        m_lineno=0;
        mp_Id=NULL;
        mp_Parameter_List=NULL;
        mp_Const_Declarations=NULL;
        mp_Var_Declarations=NULL;
        mp_Statement_List=NULL;
    }
    string    func_codeGeneration() override;
    int func_checkReturnType() override {
    return m_returnType;
    }
    int    func_get_Common_Type() override{
    return COMMON_FUNCTION;
    }
    pair<bool, string> create_symbolsheet() override;
    bool error_detect() override;
    Id * get_func_id() override {
    return mp_Id;
    }
    Parameter_List * get_param_list() override {
    return mp_Parameter_List;
    }
    Const_Declarations * get_const_dec() override {
    return mp_Const_Declarations;
    }
    Var_Declarations * get_var_dec() override {
    return mp_Var_Declarations;
    }
    int get_lineno() override {
    return m_lineno;
    }



    int m_returnType;
    int m_lineno;

    Id                    *mp_Id;
    Parameter_List        *mp_Parameter_List;
    Const_Declarations    *mp_Const_Declarations;
    Var_Declarations    *mp_Var_Declarations;
    Statement_List        *mp_Statement_List;

    void outputTree();
};


//    the statements are partitioned by ';'
class Statement {
public:
    Statement(){
        mp_Assignop=NULL;
        mp_Procedure_call=NULL;        // which include the read and write call
        mp_Statement_List=NULL;        // which refered to begin-block-end
        mp_If_Then_Else=NULL;
        mp_For=NULL;

    };
    ~Statement();

    string    func_codeGeneration();
    void    func_checkType();
    bool error_detect(string symbol_sheet_name);

    int m_stateType;
    int m_lineno;

    //    the below pointers
    //    only one can be assigned to non-NULL
    //    the others must be null
    Assignop        *mp_Assignop;
    Procedure_Call    *mp_Procedure_call;        // which include the read and write call
    Statement_List    *mp_Statement_List;        // which refered to begin-block-end
    If_Then_Else    *mp_If_Then_Else;
    For                *mp_For;

    void outputTree();
};

// only used for function or procedure define
class Parameter_List {
public:
    Parameter_List(){
        m_lineno=0;

    };
    Parameter_List(int M_lineno,vector<Parameter*> Mv_Patameter){
        m_lineno=M_lineno;
        mv_Patameter=Mv_Patameter;
    }
    ~Parameter_List();

    bool error_detect(string symbolSheet_name);
    string func_codeGeneration();

    int m_lineno;

    vector<Parameter*> mv_Patameter;

    void outputTree();
};

//    define the variable type
class Variable {
public:
    Variable(){
        m_isArray=false;
        m_lineno=0;
        mp_Id=NULL;
        mp_Expression_List=NULL;
        type=0;
    };
    ~Variable();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);
    int getType() { return type; }
    bool    m_isArray;
    int        m_lineno;

    Id                *mp_Id;
    int type;
    //    default to be null
    //
    //    if m_isArray == true
    //    this pointer point to the index of array(multi-dimension)
    //        partition by ',' in pascal
    Expression_List    *mp_Expression_List;

    void outputTree();
};

//    belong to statement
class Procedure_Call {
public:
    Procedure_Call(){
        m_proCall_Tpye=0;
        m_expNum=0;
        m_lineno=0;
        mp_Id=NULL;
        mp_Expression_List=NULL;
    };
    ~Procedure_Call();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);

    int    m_proCall_Tpye;

    int m_expNum;
    int m_lineno;

    Id                *mp_Id;
    Expression_List    *mp_Expression_List;

    void outputTree();

};

class Function_Call {
public:
    Function_Call(){
        mp_Id=NULL;
        mp_Expression_List=NULL;
    };
    Function_Call(int M_expNum,int M_lineno,Id                *Mp_Id,Expression_List    *Mp_Expression_List){
        m_expNum=M_expNum;
        m_lineno=M_lineno;
        mp_Id=Mp_Id;
        mp_Expression_List=Mp_Expression_List;
    }
    ~Function_Call();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);

    int m_expNum;
    int m_lineno;

    Id                *mp_Id;
    Expression_List    *mp_Expression_List;

    void outputTree();
};

// the expression can be calculate to a value
class Expression {
public:
    Expression(){
        mp_Relop=NULL;
        mp_Simple_Expression=NULL;
        m_lineno=0;
        rangeVal=0;
        rangeValid=0;
        type=0;
    };
    ~Expression();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);
    void setType(int _type) { type = _type; };
    int getType() { return type; }
    int getRangeVal() { return rangeVal; };
    bool getRangeValid() { return rangeValid; }

    int m_lineno;
    int rangeVal;
    bool rangeValid;

    //  the below two pointers
    //    only one can be assign to non-NULL
    //    the other must be NULL
    Relop                *mp_Relop;
    Simple_Expression    *mp_Simple_Expression;
    int type;

    void outputTree();
};

// belong to expression
class Simple_Expression {
public:
    Simple_Expression(int M_lineno,Addop *Mp_Addop,Term    *Mp_Term){
        m_lineno=M_lineno;
        mp_Addop=Mp_Addop;
        mp_Term=Mp_Term;
    }
    Simple_Expression(){
        mp_Addop=NULL;
        mp_Term=NULL;
        rangeValid=0;
        rangeVal=0;
        type=0;
        m_lineno=0;
    }
    ~Simple_Expression();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);
    void setType(int _type) { type = _type; };
    int getType() { return type; };
    int getRangeVal() { return rangeVal; }
    bool getRangeValid() { return rangeValid; }

    int m_lineno;
    int type;
    int rangeVal;
    bool rangeValid;
    //  the below two pointers
    //    only one can be assign to non-NULL
    //    the other must be NULL
    Addop    *mp_Addop;
    Term    *mp_Term;

    void outputTree();
};

class Term {
public:
    Term(int M_lineno,Mulop    *Mp_Mulop,Factor    *Mp_Factor){
        m_lineno=M_lineno;
        mp_Mulop=Mp_Mulop;
        mp_Factor=Mp_Factor;
    }
    Term(){
        mp_Mulop=NULL;
        mp_Factor=NULL;
        m_lineno=0;
        type=0;
        rangeVal=0;
        rangeValid=0;
    }
    ~Term();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);
    void setType(int _type) { type = _type; }
    int getType() { return type; };
    int getRangeVal() { return rangeVal; }
    bool getRangeValid() { return rangeValid; }

    int m_lineno;
    int type;
    int rangeVal;
    bool rangeValid;
    //  the below two pointers
    //    only one can be assign to non-NULL
    //    the other must be NULL
    Mulop    *mp_Mulop;
    Factor    *mp_Factor;

    void outputTree();
};

// the smallest value unit
class Factor {
public:
    Factor(){
        rangeVal=0;
        rangeValid=0;
        m_int=0;
        m_real=0;
        m_char=0;
        m_bool=0;
        m_factorType=0;
        m_lineno=0;
        type=0;

        mp_Variable=NULL;
        mp_Function_Call=NULL;
        mp_Expression=NULL;
        mp_Not=NULL;
        mp_Uminus=NULL;
    };
    ~Factor();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);
    int getType() { return type; }//返回数据类型，integer,char等等
    void setType(int _type) { type = _type; }
    int    func_checkFactorType() {
        return m_factorType;
    }
    int getRangeVal() { return rangeVal; }
    bool getRangeValid() { return rangeValid; }

    int rangeVal;
    bool rangeValid;

    int        m_int;
    float    m_real;
    char    m_char;
    bool    m_bool;

    int m_factorType;
    int m_lineno;
    int type;
    //    the below pointers
    //    only one can be assigned to non-NULL
    //    the others must be null
    Variable        *mp_Variable;
    Function_Call    *mp_Function_Call;
    Expression        *mp_Expression;
    Not                *mp_Not;
    Uminus            *mp_Uminus;

    void outputTree();
};

//    the operator 'not'
class Not {
public:
    Not(){
        mp_Factor=NULL;
        m_lineno=0;
    };
    ~Not();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);


    int m_lineno;

    Factor    *mp_Factor;

    void outputTree();
};

//    the operator + -
//    as for:
//        -1 +2 -i +j
class Uminus {
public:
    Uminus(){
    rangeVal=0;
    rangeValid=0;
    m_lineno=0;
    m_unimusType=0;
    type=0;
    mp_Factor=NULL;

    };
    ~Uminus();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);
    int getType() { return type; };
    void setType(int _type) {type = _type; }
    int getRangeVal() { return rangeVal; }
    bool getRangeValid() { return rangeValid; }

    int rangeVal;
    bool rangeValid;
    int m_lineno;
    int m_unimusType;
    int type;
    Factor    *mp_Factor;

    void outputTree();
};

// only used for var block
class Type {
public:
    Type(){
        m_simpleType=0;
        m_isArray=0;
        m_lineno=0;
        mp_Period=NULL;

    };
    ~Type();

    string    func_codeGeneration();
    string  func_code_getperiod();

    int        func_checkSimpleType() {
        return m_simpleType;
    }
    bool    func_check_isArray() {
        return m_isArray;
    }

    int get_lineno() {
        return m_lineno;
    }
    vector<pair<int, int> > func_get_Period();
    int        m_simpleType;
    bool    m_isArray;
    int        m_lineno;

    //    if m_isArray == true
    //    this pointer will point to the period(multi-dimension)
    Period    *mp_Period;

    void outputTree();

};

//    used for const block
class Const_Value {
public:
    Const_Value(){
        mp_Id=NULL;
    };

    ~Const_Value();

    string    func_codeGeneration();
    int        func_checkValueType() {
        return m_valueType;
    }


    int        m_postNeg;
    int        m_valueType;

    // the below value are all unsigned
    int        m_int;
    float    m_real;
    char    m_char;
    bool    m_bool;

    int        m_lineno;
    bool    m_isId;

    //    if m_isId == true
    //    this pointer point to the refered ID
    Id    *mp_Id;

    void outputTree();
};

class Assignop {
public:
    Assignop(){
        mp_Variable=NULL;
        mp_Expression=NULL;

    };
    Assignop(Variable    *Mp_Variable,Expression* Mp_Expression){
        mp_Variable = Mp_Variable;
        mp_Expression = Mp_Expression;
    }
    ~Assignop();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);

    int m_lineno;

    Variable    *mp_Variable;
    Expression    *mp_Expression;

    void outputTree();
};

class If_Then_Else {
public:
    If_Then_Else(){
        mp_Expression=NULL;
        mp_Statement_1=NULL;
        mp_Statement_2=NULL;
    };
    If_Then_Else(Expression    *_mp_Expression, Statement    *_mp_Statement_1, Statement    *_mp_Statement_2) {
        mp_Expression = _mp_Expression;
        mp_Statement_1 = _mp_Statement_1;
        mp_Statement_2 = _mp_Statement_2;
    }
    ~If_Then_Else();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);


    int m_lineno;

    Expression    *mp_Expression;
    Statement    *mp_Statement_1;
    Statement    *mp_Statement_2;

    void outputTree();
};

class For {
public:
    For(){
        mp_Id=NULL;
        mp_Expression_1=NULL;
        mp_Expression_2=NULL;
        mp_Statment=NULL;
    };
    For(Id    *_mp_Id, Expression    *_mp_Expression_1, Expression    *_mp_Expression_2, Statement    *_mp_Statment) {
        mp_Id = _mp_Id;
        mp_Expression_1 = _mp_Expression_1;
        mp_Expression_2 = _mp_Expression_2;
        mp_Statment = _mp_Statment;
    }
    ~For();

    string func_codeGeneration();
    bool error_detect(string symbol_sheet_name);


    int m_lineno;

    Id            *mp_Id;
    Expression    *mp_Expression_1;
    Expression    *mp_Expression_2;
    Statement    *mp_Statment;

    void outputTree();
};

class Parameter {
public:
    Parameter(bool    M_isVal,int    M_lineno,Id_List *Mp_Id_List){
        m_isVal=M_isVal;
        m_lineno=M_lineno;
        mp_Id_List=Mp_Id_List;
    }
    Parameter(){
        mp_Id_List=NULL;
    }
    ~Parameter();

    string    func_codeGeneration();
    bool    func_isVal() {
        return m_isVal;
    }
    vector<Id*> func_get_mv_id();
    int get_lineno() {
        return m_lineno;
    }
    int        func_get_m_type() {
        return m_Type;
    }
    Id_List* get_idlist() {
        return mp_Id_List;
    }


    // define whether the parameter is variable element
    bool    m_isVal;
    int        m_lineno;
    int        m_Type;

    Id_List    *mp_Id_List;

    void outputTree();

};

class Relop {
public:
    Relop(){
        mp_Simple_Expression_1=NULL;
        mp_Simple_Expression_2=NULL;
    };
    Relop(int M_relopType,int M_lineno,Simple_Expression *Mp_Simple_Expression_1,Simple_Expression *Mp_Simple_Expression_2){
        m_relopType=M_relopType;
        m_lineno=M_lineno;
        mp_Simple_Expression_1=Mp_Simple_Expression_1;
        mp_Simple_Expression_2=Mp_Simple_Expression_1;
    }
    ~Relop();

    string    func_codeGeneration();
    bool error_detect(string symbol_sheet_name);

    int        func_checkRelopType() {
        return m_relopType;
    }
    void func_setRelopType(int _type) { m_relopType = _type; }
    void setType(int _type) { type = _type; }           //设置或返回该表达式是什么类型；
    int getType() { return type; }

    int m_relopType;
    int m_lineno;
    int type;

    Simple_Expression *mp_Simple_Expression_1;
    Simple_Expression *mp_Simple_Expression_2;

    void outputTree();
};

class Addop {
public:
    Addop(){
        mp_Simple_Expression=NULL;
        mp_Term=NULL;
    };
    Addop(int M_addopType,int M_lineno,Simple_Expression    *Mp_Simple_Expression,Term                *Mp_Term){
        m_addopType=M_addopType;
        m_lineno=M_lineno;
        mp_Simple_Expression=Mp_Simple_Expression;
        mp_Term=Mp_Term;
    }
    ~Addop();

    string    func_codeGeneration();
    bool error_detect(string symbol_sheet_name);
    int getType() { return type; }
    void setType(int _type) { type = _type; } //设置type的值

    int        func_checkAddopType() {
        return m_addopType;
    }
    void func_checkAddopType(int _type)
    {
        m_addopType = _type;
    }



    int m_addopType;
    int m_lineno;
    int type;
    Simple_Expression    *mp_Simple_Expression;
    Term                *mp_Term;

    void outputTree();
};

class Mulop {
public:
    Mulop(){
        mp_Term=NULL;
        mp_Factor=NULL;
    };
    Mulop(int M_mulopType,int M_lineno,Term    *Mp_Term,Factor    *Mp_Factor){
        m_mulopType=M_mulopType;
        m_lineno=M_lineno;
        mp_Term=Mp_Term;
        mp_Factor=Mp_Factor;
    }
    ~Mulop();

    string    func_codeGeneration();
    bool error_detect(string symbol_sheet_name);
    int        func_checkMulopType() {
        return m_mulopType;
    }
    void setType(int _type) { type = _type; }
    int getType() { return type; }

    int m_mulopType;
    int m_lineno;
    int type;

    Term    *mp_Term;
    Factor    *mp_Factor;

    void outputTree();
};

class Id{
public:
    Id(){};
    ~Id();

    string    func_codeGeneration();
    int    func_checkType() {
        return m_idType;
    };
    string    func_getName() {
        return m_name;
    }
    bool    func_isVal() {
        return m_isVal;
    }

    string    m_name;
    int        m_idType;
    int        m_lineno;


    // This note only used in function and procedure
    // to identify whether the id
    // is a variable element
    //
    // no matter in parameter declaration
    // or in the func/proc body
    //
    // default to be false
    //
    bool    m_isVal;

    void outputTree();
};

class Id_List {
public:
    Id_List(){
        m_lineno=0；
    };
    ~Id_List();

    string            func_codeGeneration();
    vector<Id*>        func_get_mv_Id() {
        return mv_Id;
    }
    int get_id_num() {
        return (int)mv_Id.size();
    }
    //    vector<int> get_id_types() {
    //        vector<int> id_types;
    //        for (auto id: mv_Id) {
    //            id_types.push_back(id->m_idType);
    //        }
    //        return id_types;
    //    }
    bool isVal() {
        return mv_Id.front()->m_isVal;  // the vector should be the same kind
    }

    int m_lineno;

    vector<Id*>mv_Id;

    void outputTree();
};

class Period {
public:
    Period(){};
    Period(vector<pair<int, int> > Mv_dims){
        mv_dims=Mv_dims;
    }
    ~Period();

    string                    func_codeGeneration();
    vector<pair<int, int> >    func_get_Range() {
        return mv_dims;
    }

    // record the multi-dimension ranges
    vector<pair<int, int> >mv_dims;

    void outputTree();

};

class Expression_List {
public:
    Expression_List(){};
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
    vector<int>            func_get_mv_type() {
        return mv_Type;
    }

    vector<int> rangeVal;
    vector<bool> rangeValid;
    vector<Expression*>mv_Expression;

    // store the Type of each expression
    // allowed type:
    //        TYPE_INTERGER
    //        TYPE_REAL
    //        TYPE_CHAR
    vector<int>mv_Type;

    // this vector default to be false
    //
    // if the expression list used in
    // function call or procedure call
    //
    // we should know whether the parameter is
    // a variable element
    //
    // if this parameter is a variable element
    // it must be an id
    vector<bool>mv_VarDefine;

    void outputTree();
};



