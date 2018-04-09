//	File Name	: CodeGenerate.cpp
//	Notes		: Define the code generation way
//	Version		: 0.3
//	Author		: Yun Zhang

#include <fstream>
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

		case TYPE_BOOLEAN:
			Code_return += "bool ";
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
		Code_return += "int ";
		break;

	case TYPE_REAL:
		Code_return += "float ";
		break;

	case TYPE_CHAR:
		Code_return += "char ";
		break;

	case TYPE_BOOLEAN:
		Code_return += "bool ";
		break;

	default:
		throw "Invalid Type!!!";
		break;
	}
	
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

string Statement::func_codeGeneration() {
	string Code_return = "";

	switch (m_stateType) {
	case STATEMENT_ASSIGN:
		Code_return += mp_Assignop->func_codeGeneration();
		break;

	case STATEMENT_PROCEDURE:
		Code_return += mp_Procedure_call->func_codeGeneration();
		break;

	case STATEMENT_COMPOUND:
		Code_return += "{\n";
		Code_return += mp_Statement_List->func_codeGeneration();
		Code_return += "}\n";
		break;

	case STATEMENT_IF:
		Code_return += mp_If_Then_Else->func_codeGeneration();
		break;

	case STATEMENT_FOR:
		Code_return += mp_For->func_codeGeneration();
		break;

	default:
		throw "Invalid statement TYPE!!!";
		break;
	}

	return Code_return;
}

string Parameter_List::func_codeGeneration() {
	string Code_return = "";
	
	for (int i = 0; i < mv_Patameter.size(); i++) {
		Code_return += mv_Patameter[i]->func_codeGeneration();
		if (i != mv_Patameter.size() - 1) {
			Code_return += ", ";
		}
	}

	return Code_return;
}

string Parameter::func_codeGeneration() {
	string Code_return = "";
	string Code_Type = "";
	vector<Id*>mv_id = func_get_mv_id();

	switch (m_Type) {
	case TYPE_INTERGER:
		Code_Type += "int ";
		break;

	case TYPE_REAL:
		Code_Type += "float ";
		break;

	case TYPE_CHAR:
		Code_Type += "char ";
		break;

	case TYPE_BOOLEAN:
		Code_Type += "bool ";
		break;

	default:
		throw "Invalid Type!!!";
		break;
	}

	for (int i = 0; i < mv_id.size(); i++) {
		Code_return += Code_Type;
		Code_return += mv_id[i]->func_codeGeneration();
		if (i != mv_id.size() - 1)
			Code_return += ", ";
	}
	
	return Code_return;
}

string Variable::func_codeGeneration() {
	string Code_return = "";

	Code_return += mp_Id->func_codeGeneration();

	if (m_isArray) {
		vector<Expression*>mv_Expression = mp_Expression_List->func_get_mv_exp();
		
		for (int i = 0; i < mv_Expression.size(); i++) {
			Code_return += "[";

			Code_return += mv_Expression[i]->func_codeGeneration();

			Code_return += "]";
		}
	}
	
	return Code_return;
}

string Procedure_Call::func_codeGeneration() {
	string Code_return = "";
	string Code_FormateStr = "";
	vector<int>mv_Type = mp_Expression_List->func_get_mv_type();

	if (m_proCall_Tpye != PROCECALL_NORMAL) {
		for (int i = 0; i < mv_Type.size(); i++) {
			switch (mv_Type[i]) {
			case TYPE_INTERGER:
				Code_FormateStr += "%d";
				break;

			case TYPE_REAL:
				Code_FormateStr += "%f";
				break;

			case TYPE_CHAR:
				Code_FormateStr += "%c";
				break;

			default:
				break;
			}
		}
	}


	string t_id_name = mp_Id->func_getName();
	if (t_id_name == "read") {
		Code_return += "scanf(\"";
		Code_return += Code_FormateStr;
		Code_return += "\", ";
		Code_return += mp_Expression_List->func_codeGeneration();
		Code_return += ");";
	}
	else if (t_id_name == "readln") {
		Code_return += "scanf(\"";
		Code_return += Code_FormateStr;
		Code_return += "\\n\", ";
		Code_return += mp_Expression_List->func_codeGeneration();
		Code_return += ");";
	}
	else if (t_id_name == "write") {
		Code_return += "printf(\"";
		Code_return += Code_FormateStr;
		Code_return += "\", ";
		Code_return += mp_Expression_List->func_codeGeneration();
		Code_return += ");";
	}
	else if (t_id_name == "writeln") {
		Code_return += "scanf(\"";
		Code_return += Code_FormateStr;
		Code_return += "\\n\", ";
		Code_return += mp_Expression_List->func_codeGeneration();
		Code_return += ");";
	}
	else {
		Code_return += mp_Id->func_codeGeneration();
		Code_return += "(";
		Code_return += mp_Expression_List->func_codeGeneration();
		Code_return += ");";
	}


	//switch (m_proCall_Tpye) {
	//case PROCECALL_NORMAL:
	//	Code_return += mp_Id->func_codeGeneration();
	//	Code_return += "(";
	//	Code_return += mp_Expression_List->func_codeGeneration();
	//	Code_return += ");";
	//	break;

	//case PROCECALL_READ:
	//	Code_return += "scanf(\"";
	//	Code_return += Code_FormateStr;
	//	Code_return += "\", ";
	//	Code_return += mp_Expression_List->func_codeGeneration();
	//	Code_return += ");";
	//	break;

	//case PROCECALL_READLN:
	//	Code_return += "scanf(\"";
	//	Code_return += Code_FormateStr;
	//	Code_return += "\\n\", ";
	//	Code_return += mp_Expression_List->func_codeGeneration();
	//	Code_return += ");";
	//	break;

	//case PROCECALL_WRITE:
	//	Code_return += "printf(\"";
	//	Code_return += Code_FormateStr;
	//	Code_return += "\", ";
	//	Code_return += mp_Expression_List->func_codeGeneration();
	//	Code_return += ");";
	//	break;

	//case PROCECALL_WRITELN:
	//	Code_return += "scanf(\"";
	//	Code_return += Code_FormateStr;
	//	Code_return += "\\n\", ";
	//	Code_return += mp_Expression_List->func_codeGeneration();
	//	Code_return += ");";
	//	break;
	//
	//default:
	//	throw "Invalid PROCECALL!!!";
	//	break;
	//}

	return Code_return;
}

string Function_Call::func_codeGeneration() {
	string Code_return = "";

	Code_return += mp_Id->func_codeGeneration();
	Code_return += "(";
	Code_return += mp_Expression_List->func_codeGeneration();
	Code_return += ")";

	return Code_return;
}

string Expression::func_codeGeneration() {
	string Code_return = "";

	if (mp_Relop != NULL) {
		Code_return += mp_Relop->func_codeGeneration();
	}
	else {
		Code_return += mp_Simple_Expression->func_codeGeneration();
	}
	
	return Code_return;
}

string Simple_Expression::func_codeGeneration() {
	string Code_return = "";

	if (mp_Addop != NULL) {
		Code_return += mp_Addop->func_codeGeneration();
	}
	else {
		Code_return += mp_Term->func_codeGeneration();
	}
	
	return Code_return;
}

string Term::func_codeGeneration() {
	string Code_return = "";

	if (mp_Mulop != NULL) {
		Code_return += mp_Mulop->func_codeGeneration();
	}
	else {
		Code_return += mp_Factor->func_codeGeneration();
	}
	
	return Code_return;
}

string Factor::func_codeGeneration() {
	string Code_return = "";

	switch (m_factorType) {
	case FACTOR_VAR:
		Code_return += mp_Variable->func_codeGeneration();
		break;

	case FACTOR_FUNCCALL:
		Code_return += mp_Function_Call->func_codeGeneration();
		break;

	case FACTOR_BRACKETS:
		Code_return += "(";
		Code_return += mp_Expression->func_codeGeneration();
		Code_return += ")";
		break;

	case FACTOR_NOT:
		Code_return += mp_Not->func_codeGeneration();
		break;

	case FACTOR_UMINUS:
		Code_return += mp_Uminus->func_codeGeneration();
		break;

	case FACTOR_VALUE_INT:
		Code_return += type2str(m_int);
		break;

	case FACTOR_VALUE_REAL:
		Code_return += type2str(m_real);
		break;

	case FACTOR_VALUE_CHAR:
		Code_return += "\'";
		Code_return += type2str(m_char);
		Code_return += "\'";
		break;

	case FACTOR_vALUE_BOOL:
		if (m_bool)
			Code_return += "true";
		else
			Code_return += "false";
		break;

	default:
		throw "Invalid FACTORTYPE!!!";
		break;
	}

	return Code_return;
}

string Not::func_codeGeneration() {
	string Code_return = "!";

	Code_return += mp_Factor->func_codeGeneration();
	
	return Code_return;
}

string Uminus::func_codeGeneration() {
	string Code_return = "";

	switch (m_unimusType) {
	case UMINUS_POSITIVE:
		Code_return += "+";
		break;

	case UMINUS_NEGATIVE:
		Code_return += "-";
		break;

	default:
		throw "Invalid UMINUS_TYPE!!!";
		break;
	}
	
	Code_return += mp_Factor->func_codeGeneration();

	return Code_return;
}

string Assignop::func_codeGeneration() {
	string Code_return = "";

	Code_return += mp_Variable->func_codeGeneration();
	Code_return += " = ";
	Code_return += mp_Expression->func_codeGeneration();
	Code_return += ";";

	
	return Code_return;
}

string If_Then_Else::func_codeGeneration() {
	string Code_return = "if (";

	Code_return += mp_Expression->func_codeGeneration();
	Code_return += ") {\n";
	Code_return += mp_Statement_1->func_codeGeneration();
	Code_return += "\n}";

	if (mp_Statement_2 != NULL) {
		Code_return += "\nelse {\n";
		Code_return += mp_Statement_2->func_codeGeneration();
		Code_return += "\n}";
	}
	
	return Code_return;
}

string For::func_codeGeneration() {
	string Code_return = "for (";

	Code_return += mp_Id->func_codeGeneration();
	Code_return += " = ";
	Code_return += mp_Expression_1->func_codeGeneration();
	Code_return += " ; ";

	Code_return += mp_Id->func_codeGeneration();
	Code_return += " <= ";
	Code_return += mp_Expression_2->func_codeGeneration();
	Code_return += " ; ";

	Code_return += mp_Id->func_codeGeneration();
	Code_return += "++ ) {\n";

	Code_return += mp_Statment->func_codeGeneration();
	Code_return += "\n}";
	
	return Code_return;
}

string Id::func_codeGeneration() {
	string Code_return = "";

	if (m_isVal) {
		Code_return += "*";
	}
	Code_return += m_name;

	return Code_return;
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

		case TYPE_BOOLEAN:
			if (m_bool)
				Code_return += "true";
			else 
				Code_return += "false";

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

string Relop::func_codeGeneration() {
	string Code_return = "";

	Code_return += mp_Simple_Expression_1->func_codeGeneration();

	switch (m_relopType) {
	case RELOP_EQUAL:
		Code_return += " == ";
		break;

	case RELOP_NOT_EQUAL:
		Code_return += " != ";
		break;

	case RELOP_LESS:
		Code_return += " < ";
		break;

	case RELOP_LESS_EQUAL:
		Code_return += " <= ";
		break;

	case RELOP_LARGE:
		Code_return += " > ";
		break;

	case RELOP_LARGE_EQUAL:
		Code_return += " >= ";
		break;
	
	default:
		throw "Invalid RELOP_TYPE!!!";
		break;
	}

	Code_return += mp_Simple_Expression_2->func_codeGeneration();
	
	return Code_return;
}

string Addop::func_codeGeneration() {
	string Code_return;

	Code_return += mp_Simple_Expression->func_codeGeneration();
	
	switch (m_addopType) {
	case ADDOP_ADD:
		Code_return += " + ";
		break;

	case ADDOP_SUB:
		Code_return += " - ";
		break;

	case ADDOP_OR:
		Code_return += " || ";
		break;

	default:
		throw "Invalid AddopType!!!";
		break;
	}
	
	Code_return += mp_Term->func_codeGeneration();
	
	return Code_return;
}

string Mulop::func_codeGeneration() {
	string Code_return = "";

	Code_return += mp_Term->func_codeGeneration();

	switch (m_mulopType) {
	case MULOP_MULTIPLY:
		Code_return += " * ";
		break;

	case MULOP_READ_DIV:
		Code_return += " / ";
		break;

	case MULOP_INT_DIV:
		Code_return += " / ";
		break;

	case MULOP_MOD:
		Code_return += " % ";
		break;

	case MULOP_AND:
		Code_return += " && ";
		break;

	default:
		throw "Invalid MULTYPE!!!";
		break;
	}

	Code_return += mp_Factor->func_codeGeneration();
	
	return Code_return;
}

string Expression_List::func_codeGeneration() {
	string Code_return = "";

	for (int i = 0; i < mv_Expression.size(); i++) {
		Code_return += mv_Expression[i]->func_codeGeneration();
		if (i != mv_Expression.size() - 1)
			Code_return += ", ";
	}
	
	return Code_return;
}

void Code_Generate(Programstruct * input_Tree, string output_File) {
	fstream File_output;
	File_output.open("./" + output_File + ".c", fstream::out);

	string code = input_Tree->func_codeGeneration();

	File_output << code;

	File_output.close();
}

string Type::func_code_getperiod() {
	return mp_Period->func_codeGeneration();
}

vector<pair<int, int>> Type::func_get_Period() {
	return mp_Period->func_get_Range();
}

vector<Id*> Parameter::func_get_mv_id() {
	return mp_Id_List->func_get_mv_Id();
}