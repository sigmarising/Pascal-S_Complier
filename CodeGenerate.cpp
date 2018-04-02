//	File Name	: CodeGenerate.cpp
//	Notes		: Define the code generation way
//	Version		: 0.3
//	Author		: Yun Zhang

#include <strstream>
#include "CodeGenerate.h"
using namespace std;


// any simple type convert to string
template<class src_type>
string type2str(src_type src) {
	strstream ss;
	ss << src;
	string ret;
	ss >> ret;

	return ret;
}


string Programstruct::func_codeGeneration() {

	string Code_head =
		"#include <stdio.h>\n"
		"#include <stdlib.h>\n"
		"\n"
		"#define bool int\n"
		"#define true 1\n"
		"#define false 0\n"
		"\n";

	string Code_program_body = mp_Program_Body->func_codeGeneration();
	
	string Code_return = Code_head + Code_program_body;

	return Code_return;
}

string Program_Body::func_codeGeneration() {

	string Code_const = mp_Const_Declarations->func_codeGeneration();

	string Code_var = mp_Var_Declarations->func_codeGeneration();

	string Code_sub_program = mp_SubProgram_Declarations->func_codeGeneration();

	string Code_main_begin = 
		"int main(int argc, char* argv[]) {\n";

	string Code_Statement_List = mp_Statement_List->func_codeGeneration();

	string Code_main_end =
		"	return 0;\n"
		"}\n"
		"\n";

	string Code_Return = Code_const + Code_var + Code_sub_program + Code_main_begin + Code_Statement_List + Code_main_end;

	return Code_Return;
}

string Const_Declarations::func_codeGeneration() {

	string Code_return = "\n";

	for (int i = 0; i < mv_Const.size(); i++) {
		
		Code_return += "const ";

		switch (mv_Const[i].second->func_checkValueType()) {
		case TYPE_INTERGER:
			Code_return += "int ";
			break;

		case TYPE_REAL:
			Code_return += "float ";
			break;

		case TYPE_CHAR:
			Code_return += "char ";
			break;

		default:
			throw "Invalid Type!!!";
			break;
		}

		Code_return += mv_Const[i].first->func_codeGeneration();
		Code_return += " = ";
		Code_return += mv_Const[i].second->func_codeGeneration();
		Code_return += ";\n";

	}

	Code_return += "\n";

	return Code_return;
}

string Var_Declarations::func_codeGeneration() {
	string Code_return = "\n";

	for (int i = 0; i < mv_Var.size(); i++) {
		if (mv_Var[i].second->func_check_isArray()) {
			// array type
			Code_return += mv_Var[i].second->func_codeGeneration();
			Code_return += " ";

			vector<Id*>mv_Id = mv_Var[i].first->func_get_mv_Id();
			vector<pair<int, int>> mv_Period = mv_Var[i].second->func_get_Period();
			string Code_Period = mv_Var[i].second->func_code_getperiod();

			for (int i = 0; i < mv_Id.size(); i++) {
				// range x..y
				// n = y - x + 1
				//
				// __A[n]
				// *A = &(__A[-1*x])

				string Code_Id = mv_Id[i]->func_codeGeneration();

				Code_return += "__";		// __
				Code_return += Code_Id;		// A
				Code_return += Code_Period;	// [n]
				Code_return += ", *";		// *
				Code_return += Code_Id;		// A
				Code_return += " = &(__";
				Code_return += Code_Id;
				Code_return += "[-1 * ";
				Code_return += type2str(mv_Period[i].first);
				Code_return += "])";

				if (i != mv_Id.size() - 1)
					Code_return += ", ";
			}

			Code_return += ";\n";
		}
		else {
			// simple type
			Code_return += mv_Var[i].second->func_codeGeneration();
			Code_return += " ";
			Code_return += mv_Var[i].first->func_codeGeneration();
			Code_return += ";\n";
		}
	}
	
	Code_return += "\n";
	
	return Code_return;
}

string SubProgram_Declarations::func_codeGeneration() {
	string Code_return = "";

	for (int i = 0; i < mv_Common.size(); i++) {
		Code_return += mv_Common[i]->func_codeGeneration();
	}
	
	return Code_return;
}

string Statement_List::func_codeGeneration() {
	string Code_return = "\n";

	for (int i = 0; i < mv_Statement.size(); i++) {
		Code_return += mv_Statement[i]->func_codeGeneration();
		Code_return += "\n";
	}

	Code_return += "\n";

	return Code_return;
}

string Procedure::func_codeGeneration() {
	string Code_return = "\n";

	Code_return += "void ";
	Code_return += mp_Id->func_codeGeneration();
	Code_return += "(";
	Code_return += mp_Parameter_List->func_codeGeneration();
	Code_return += ") {\n";
	
	Code_return += mp_Const_Declarations->func_codeGeneration();
	Code_return += mp_Var_Declarations->func_codeGeneration();
	Code_return += mp_Statement_List->func_codeGeneration();

	Code_return += "}\n";
	Code_return += "\n";
	
	return Code_return;
}

string Function::func_codeGeneration() {
	string Code_return = "\n";

	switch (func_checkReturnType()) {
	case TYPE_INTERGER:
		break;
	case TYPE_REAL:
		break;
	case TYPE_CHAR:
		break;
	case TYPE_BOOLEAN:
		break;
	default:
		break;
	}
	
	return 
}

string Id::func_codeGeneration() {
	return m_name;
}

string Const_Value::func_codeGeneration() {
	
	string Code_return = "";

	switch (m_postNeg) {
	case CONST_POSTNEG_NEGATIVE:
		Code_return += "-";
		break;

	case CONST_POSTNEG_POSITIVE:
		Code_return += "+";
		break;

	case CONST_POSTNEG_NULL:
		break;

	default:
		throw "Invalid CONST_POSTNEG Type!!!!";
		break;
	}

	if (m_isId) {
		Code_return += mp_Id->func_codeGeneration();
	}
	else {
		switch (m_valueType) {
		case TYPE_INTERGER:
			Code_return += type2str(m_int);
			break;

		case TYPE_REAL:
			Code_return += type2str(m_real);
			break;

		case TYPE_CHAR:
			Code_return += "\'";
			Code_return += type2str(m_char);
			Code_return += "\'";
			break;

		default:
			throw "Invalid BASIC Type!!!";
			break;
		}
	}

	return Code_return;
}

string Id_List::func_codeGeneration() {
	string Code_return = "";

	for (int i = 0; i < mv_Id.size(); i++) {
		Code_return += mv_Id[i]->func_codeGeneration();
		if (i != mv_Id.size() - 1)
			Code_return += ", ";
	}

	return Code_return;
}

string Type::func_codeGeneration() {
	string Code_return = "";

	switch (m_simpleType) {
	case TYPE_INTERGER:
		Code_return += "int";
		break;

	case TYPE_REAL:
		Code_return += "float";
		break;

	case TYPE_CHAR:
		Code_return += "char";
		break;

	case TYPE_BOOLEAN:
		Code_return += "bool";
		break;

	default:
		throw "Invalid TYPE!!!";
		break;
	}

	return Code_return;
}

string Period::func_codeGeneration() {
	string Code_return = "";

	for (int i = 0; i < mv_dims.size(); i++) {
		int n = mv_dims[i].second - mv_dims[i].first + 1;
		Code_return += "[";
		Code_return += type2str(n);
		Code_return += "]";
	}

	return Code_return;
}