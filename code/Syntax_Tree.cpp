//
//  Syntax_Tree.cpp
//  syntax
//
//  Created by cbox on 2018/4/16.
//  Copyright © 2018年 cbox. All rights reserved.
//

#include <stdio.h>
#include "Syntax_Tree.h"
#include "Public_define.h"
#include <iostream>
using namespace std;

void Programstruct::outputTree() {
    cout<<"Programstruct"<<endl;
    if(mp_Id == NULL)
        cout<<"mp_Id is NULL"<<endl;
    else
        mp_Id -> outputTree();
    if(mp_Id_List == NULL)
        cout<<"Id_List is NULL"<<endl;
    else
        mp_Id_List -> outputTree();
    if(mp_Program_Body == NULL)
        cout<<"mp_Program_Body is NULL"<<endl;
    else
        mp_Program_Body -> outputTree();
}

void Program_Body::outputTree(){
    cout<<"Program_Body"<<endl;
    if(mp_Const_Declarations == NULL)
        cout<<"mp_Const_Declarations is NULL"<<endl;
    else
        mp_Const_Declarations -> outputTree();
    if(mp_Var_Declarations == NULL)
        cout<<"mp_Var_Declarations is NULL"<<endl;
    else
        mp_Var_Declarations -> outputTree();
    if(mp_SubProgram_Declarations == NULL)
        cout<<"mp_SubProgram_Declarations is NULL"<<endl;
    else
        mp_SubProgram_Declarations -> outputTree();
    if(mp_Statement_List == NULL)
        cout<<"mp_Statement_List is NULL"<<endl;
    else
        mp_Statement_List -> outputTree();
}

void Const_Declarations::outputTree(){
    cout<<"Const_Declarations"<<endl;
    if(mv_Const.empty())
        cout<<"mv_Const is NULL"<<endl;
    else
        for(int i = 0;i < mv_Const.size();i++){
            mv_Const[i].first -> outputTree();
            mv_Const[i].second -> outputTree();
        }
}

void Var_Declarations::outputTree() {
    cout<<"Var_Declarations";
    if(mv_Var.empty())
        cout<<"mv_Var is NULL"<<endl;
    else
        for(int i = 0;i < mv_Var.size();i++){
            mv_Var[i].first -> outputTree();
            mv_Var[i].second -> outputTree();
        }
    
}

void SubProgram_Declarations::outputTree(){
    cout<<"SubProgram_Declarations"<<endl;
    if(mv_Common.empty())
        cout<<"mv_Common is NULL"<<endl;
    else
        for(int i = 0;i < mv_Common.size();i++){
            mv_Common[i] -> outputTree();
        }
}

void Statement_List::outputTree(){
    cout<<"Statement_List"<<endl;
    if(mv_Statement.empty())
        cout<<"mv_Statement is NULL"<<endl;
    for(int i=0;i<mv_Statement.size();i++){
        mv_Statement[i]->outputTree();
    }
}

void Procedure::outputTree(){
    cout<<"Procedure"<<endl;
    cout<<"m_lineo = "<<m_lineno<<endl;
    if(mp_Id == NULL){
        cout<<"mp_Id is NULL"<<endl;
    }else {
        mp_Id -> outputTree();
    }
    if(mp_Parameter_List == NULL){
        cout<<"mp_Parameter_List is NULL"<<endl;
    }else{
        mp_Parameter_List -> outputTree();
    }
    if(mp_Const_Declarations == NULL){
        cout<<"mp_Const_Declarations is NULL"<<endl;
    }else{
        mp_Const_Declarations->outputTree();
    }
    if(mp_Var_Declarations == NULL){
        cout<<"mp_Var_Declarations is NULL"<<endl;
    }else{
        mp_Var_Declarations->outputTree();
    }
    if(mp_Statement_List == NULL){
        cout<<"mp_Statement_List is NULL"<<endl;
    }else{
        mp_Statement_List->outputTree();
    }
}

void Function::outputTree(){
    cout<<"Function"<<endl;
    cout<<"m_returnType = "<<m_returnType<<endl;
    cout<<"m_lineo = "<<m_lineno<<endl;
    if(mp_Id == NULL){
        cout<<"mp_Id is NULL"<<endl;
    }else {
        mp_Id -> outputTree();
    }
    if(mp_Parameter_List == NULL){
        cout<<"mp_Parameter_List is NULL"<<endl;
    }else{
        mp_Parameter_List -> outputTree();
    }
    if(mp_Const_Declarations == NULL){
        cout<<"mp_Const_Declarations is NULL"<<endl;
    }else{
        mp_Const_Declarations->outputTree();
    }
    if(mp_Var_Declarations == NULL){
        cout<<"mp_Var_Declarations is NULL"<<endl;
    }else{
        mp_Var_Declarations->outputTree();
    }
    if(mp_Statement_List == NULL){
        cout<<"mp_Statement_List is NULL"<<endl;
    }else{
        mp_Statement_List->outputTree();
    }
}

void Statement::outputTree(){
    cout<<"Statement"<<endl;
    cout<<"m_stateType = "<<m_stateType<<endl;
    cout<<"m_lineno = "<<m_lineno<<endl;
    if(mp_Assignop == NULL){
        cout<<"mp_Assignop is NULL"<<endl;
    }else{
        mp_Assignop->outputTree();
    }
    if(mp_Procedure_call == NULL){
        cout<<"mp_Procedure_call is NULL"<<endl;
    }else{
        mp_Procedure_call->outputTree();
    }
    if(mp_Statement_List == NULL){
        cout<<"mp_Statement_List is NULL"<<endl;
    }else{
        mp_Statement_List->outputTree();
    }
    if(mp_If_Then_Else == NULL){
        cout<<"mp_If_Then_Else is NULL"<<endl;
    }else {
        mp_If_Then_Else -> outputTree();
    }
    if(mp_For == NULL){
        cout<<"mp_For is NULL"<<endl;
    }else {
        mp_For -> outputTree();
    }
}

void Parameter_List::outputTree(){
    cout<<"Parameter_List"<<endl;
    cout<<"m_lineno = "<<m_lineno<<endl;
    if(mv_Patameter.empty()){
        cout<<"mv_Patameter is NULL"<<endl;
    }else{
        for(int i=0;i<mv_Patameter.size();i++){
            mv_Patameter[i]->outputTree();
        }
    }
}

void Variable::outputTree(){
    cout<<"Variable"<<endl;
    cout<<"m_isArray = "<<m_isArray<<endl;
    cout<<"m_lineno = "<<m_lineno<<endl;
    if(mp_Id == NULL){
        cout<<"mp_Id is NULL"<<endl;
    }else {
        mp_Id -> outputTree();
    }
    cout<<"type = "<<type<<endl;
    if(mp_Expression_List == NULL){
        cout<<"mp_Expression_List is NULL"<<endl;
    }else{
        mp_Expression_List->outputTree();
    }
}

void Procedure_Call::outputTree(){
    cout<<"Procedure_Call"<<endl;
    cout<<"m_proCall_Tpye = "<<m_proCall_Tpye<<endl;
    cout<<"m_expNum = "<<m_expNum<<endl;
    cout<<"m_lineno = "<<m_lineno<<endl;
    if(mp_Id == NULL){
        cout<<"mp_Id is NULL"<<endl;
    }else {
        mp_Id -> outputTree();
    }
    if(mp_Expression_List == NULL){
        cout<<"mp_Expression_List is NULL"<<endl;
    }else {
        mp_Expression_List -> outputTree();
    }
}

void Function_Call::outputTree(){
    cout<<"Function_Call"<<endl;
    cout<<"m_expNum = "<<m_expNum<<endl;
    cout<<"m_lineno = "<<m_lineno<<endl;
    if(mp_Id == NULL){
        cout<<"mp_Id is NULL"<<endl;
    }else {
        mp_Id -> outputTree();
    }
    if(mp_Expression_List == NULL){
        cout<<"mp_Expression_List is NULL"<<endl;
    }else {
        mp_Expression_List -> outputTree();
    }
}

void Expression::outputTree(){
    cout<<"Expression"<<endl;
    cout<<"m_lineno = "<<m_lineno<<endl;
    cout<<"rangeVal = "<<rangeVal<<endl;
    cout<<"rangeValid = "<<rangeValid<<endl;
    if(mp_Relop == NULL){
        cout<<"mp_Relop is NULL"<<endl;
    }else {
        mp_Relop -> outputTree();
    }
    if(mp_Simple_Expression == NULL){
        cout<<"mp_Simple_Expression is NULL"<<endl;
    }else {
        mp_Simple_Expression -> outputTree();
    }
    
    cout<<"type = "<<type<<endl;
}

void Simple_Expression::outputTree(){
    cout<<"Simple_Expression"<<endl;
    cout<<"type = "<<type<<endl;
    cout<<"m_lineno = "<<m_lineno<<endl;
    cout<<"rangeVal = "<<rangeVal<<endl;
    cout<<"rangeValid = "<<rangeValid<<endl;
    
    if(mp_Addop == NULL){
        cout<<"mp_Addop is NULL"<<endl;
    }else {
        mp_Addop -> outputTree();
    }
    if(mp_Term == NULL){
        cout<<"mp_Simple_Expression is NULL"<<endl;
    }else {
        mp_Term -> outputTree();
    }
}

void Expression_List::outputTree() {
    cout<<"Expression_List"<<endl;
    
    if(rangeVal.empty())
        cout<<"rangeVal is empty"<<endl;
    else
        for(auto rangeValmun : rangeVal)
            cout<<rangeValmun<<endl;
    
    if(rangeVal.empty())
        cout<<"rangeVal is empty"<<endl;
    else
        for(auto rangeValmun : rangeVal)
            cout<<rangeValmun<<endl;
    
    if(mv_Expression.empty())
        cout<<"mv_Expression is empty"<<endl;
    else
        for(auto mExpression : mv_Expression)
            mExpression->outputTree();
    
    if(mv_Type.empty())
        cout<<"mv_Type is empty"<<endl;
    else
        for(auto mType : mv_Type)
            cout<<mType<<endl;
    
    if(mv_VarDefine.empty())
        cout<<"mv_VarDefine is empty"<<endl;
    else
        for(auto mVarDefine : mv_VarDefine)
            cout<<mVarDefine<<endl;
}
void Period::outputTree() {
    cout<<"Period"<<endl;
    
    if(mv_dims.empty())
        cout<<"mv_dims is empty"<<endl;
    else
        for(auto mdims : mv_dims)
            cout<<mdims.first<<" "<<mdims.second<<endl;
}
void Id_List::outputTree() {
    cout<<"Id_List"<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    
    if(mv_Id.empty())
        cout<<"mv_Id is empty"<<endl;
    else
        for(auto mId : mv_Id)
            mId->outputTree();
}
void Id::outputTree() {
    cout<<"Id"<<endl;
    cout<<"m_name is "<<m_name<<endl;
    cout<<"m_idType is "<<m_idType<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    cout<<"m_isVal is "<<m_isVal<<endl;
}
void Mulop::outputTree() {
    cout<<"Mulop"<<endl;
    cout<<"m_mulopType is "<<m_mulopType<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    cout<<"type is "<<type<<endl;
    if(mp_Term==NULL)
        cout<<"mp_Term is NULL"<<endl;
    else
        mp_Term->outputTree();
    if(mp_Factor==NULL)
        cout<<"mp_Factor is NULL"<<endl;
    else
        mp_Factor->outputTree();
}
void Addop::outputTree() {
    cout<<"Addop"<<endl;
    cout<<"m_addopType is "<<m_addopType<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    cout<<"type is "<<type<<endl;
    if(mp_Simple_Expression==NULL)
        cout<<"mp_Simple_Expression is NULL"<<endl;
    else
        mp_Simple_Expression->outputTree();
    if(mp_Term==NULL)
        cout<<"mp_Term is NULL"<<endl;
    else
        mp_Term->outputTree();
}
void Relop::outputTree() {
    cout<<"Relop"<<endl;
    cout<<"m_relopType is "<<m_relopType<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    cout<<"type is "<<type<<endl;
    if(mp_Simple_Expression_1==NULL)
        cout<<"mp_Simple_Expression_1 is NULL"<<endl;
    else
        mp_Simple_Expression_1->outputTree();
    if(mp_Simple_Expression_2==NULL)
        cout<<"mp_Simple_Expression_2 is NULL"<<endl;
    else
        mp_Simple_Expression_2->outputTree();
}
void Parameter::outputTree() {
    cout<<"Parameter"<<endl;
    cout<<"m_isVal is "<<m_isVal<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    cout<<"m_Type is "<<m_Type<<endl;
    if(mp_Id_List==NULL)
        cout<<"mp_Id_List is NULL"<<endl;
    else
        mp_Id_List->outputTree();
}
void For::outputTree() {
    cout<<"For"<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    if(mp_Id==NULL)
        cout<<"mp_Id is NULL"<<endl;
    else
        mp_Id->outputTree();
    if(mp_Expression_1==NULL)
        cout<<"mp_Expression_1 is NULL"<<endl;
    else
        mp_Expression_1->outputTree();
    if(mp_Expression_2==NULL)
        cout<<"mp_Expression_2 is NULL"<<endl;
    else
        mp_Expression_2->outputTree();
    if(mp_Statment==NULL)
        cout<<"mp_Statment is NULL"<<endl;
    else
        mp_Statment->outputTree();
}
void If_Then_Else::outputTree() {
    cout<<"If_Then_Else"<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    if(mp_Expression==NULL)
        cout<<"mp_Expression is NULL"<<endl;
    else
        mp_Expression->outputTree();
    if(mp_Statement_1==NULL)
        cout<<"mp_Statement_1 is NULL"<<endl;
    else
        mp_Statement_1->outputTree();
    if(mp_Statement_2==NULL)
        cout<<"mp_Statement_2 is NULL"<<endl;
    else
        mp_Statement_2->outputTree();
}
void Assignop::outputTree() {
    cout<<"Assignop"<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    if(mp_Variable==NULL)
        cout<<"mp_Variable is NULL"<<endl;
    else
        mp_Variable->outputTree();
    if(mp_Expression==NULL)
        cout<<"mp_Expression is NULL"<<endl;
    else
        mp_Expression->outputTree();
}
void Const_Value::outputTree() {
    cout<<"Const_Value"<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    cout<<"m_isId is "<<m_isId<<endl;
    cout<<"m_postNeg is "<<m_postNeg<<endl;
    cout<<"m_valueType is "<<m_valueType<<endl;
    cout<<"m_int is "<<m_int<<endl;
    cout<<"m_real is "<<m_real<<endl;
    cout<<"m_char is "<<m_char<<endl;
    cout<<"m_bool is "<<m_bool<<endl;
    if(mp_Id==NULL)
        cout<<"mp_Id is NULL"<<endl;
    else
        mp_Id->outputTree();
}
void Type::outputTree() {
    cout<<"Type"<<endl;
    cout<<"m_simpleType is "<<m_simpleType<<endl;
    cout<<"m_isArray is "<<m_isArray<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    if(mp_Period==NULL)
        cout<<"mp_Period is NULL"<<endl;
    else
        mp_Period->outputTree();
}
void Uminus::outputTree() {
    cout<<"Uminus"<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    cout<<"rangeVal is "<<rangeVal<<endl;
    cout<<"type is "<<type<<endl;
    cout<<"rangeValid is "<<rangeValid<<endl;
    cout<<"m_unimusType is "<<m_unimusType<<endl;
    if(mp_Factor==NULL)
        cout<<"mp_Factor is NULL"<<endl;
    else
        mp_Factor->outputTree();
}
void Not::outputTree() {
    cout<<"Not"<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    if(mp_Factor==NULL)
        cout<<"mp_Factor is NULL"<<endl;
    else
        mp_Factor->outputTree();
}
void Factor::outputTree() {
    cout<<"Factor"<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    cout<<"rangeVal is "<<rangeVal<<endl;
    cout<<"type is "<<type<<endl;
    cout<<"rangeValid is "<<rangeValid<<endl;
    cout<<"m_factorType is "<<m_factorType<<endl;
    cout<<"m_int is "<<m_int<<endl;
    cout<<"m_real is "<<m_real<<endl;
    cout<<"m_char is "<<m_char<<endl;
    cout<<"m_bool is "<<m_bool<<endl;
    if(mp_Variable==NULL)
        cout<<"mp_Variable is NULL"<<endl;
    else
        mp_Variable->outputTree();
    if(mp_Function_Call==NULL)
        cout<<"mp_Function_Call is NULL"<<endl;
    else
        mp_Function_Call->outputTree();
    if(mp_Expression==NULL)
        cout<<"mp_Expression is NULL"<<endl;
    else
        mp_Expression->outputTree();
    if(mp_Not==NULL)
        cout<<"mp_Not is NULL"<<endl;
    else
        mp_Not->outputTree();
    if(mp_Uminus==NULL)
        cout<<"mp_Uminus is NULL"<<endl;
    else
        mp_Uminus->outputTree();
}
void Term::outputTree() {
    cout<<"Term"<<endl;
    cout<<"m_lineno is "<<m_lineno<<endl;
    cout<<"rangeVal is "<<rangeVal<<endl;
    cout<<"type is "<<type<<endl;
    cout<<"rangeValid is "<<rangeValid<<endl;
    if(mp_Mulop==NULL)
        cout<<"mp_Mulop is NULL"<<endl;
    else
        mp_Mulop->outputTree();
    if(mp_Factor==NULL)
        cout<<"mp_Factor is NULL"<<endl;
    else
        mp_Factor->outputTree();
}

Procedure::Procedure(int M_lineno,Id *Mp_Id,Parameter_List *Mp_Parameter_List,Const_Declarations *Mp_Const_Declarations,Var_Declarations *Mp_Var_Declarations,Statement_List *Mp_Statement_List){
	m_lineno=M_lineno;
    mp_Id=Mp_Id;
    mp_Parameter_List=Mp_Parameter_List;
    mp_Const_Declarations=Mp_Const_Declarations;
    mp_Var_Declarations=Mp_Var_Declarations;
    mp_Statement_List=Mp_Statement_List;
}

Function::Function(int M_returnType,int M_lineno,Id *Mp_Id,Parameter_List *Mp_Parameter_List,Const_Declarations *Mp_Const_Declarations,Var_Declarations *Mp_Var_Declarations,Statement_List *Mp_Statement_List){
    m_returnType=M_returnType;
    m_lineno=M_lineno;
    mp_Id=Mp_Id;
    mp_Parameter_List=Mp_Parameter_List;
    mp_Const_Declarations=Mp_Const_Declarations;
    mp_Var_Declarations=Mp_Var_Declarations;
    mp_Statement_List=Mp_Statement_List;
}

