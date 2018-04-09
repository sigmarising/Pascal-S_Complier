#include "SemanticAnalysis.h"
#include <iostream>

//注意 Programstruct的错误检测，还不是特别完善
bool Programstruct::error_detect(string symbol_sheet_name)
{
	bool flag=true;
	if (this->mp_Program_Body)
		flag = mp_Program_Body->error_detect(symbol_sheet_name);
	return flag;
}

//注意 一半完成,还有声明部分没解决
bool Program_Body::error_detect(string symbol_sheet_name)
{
	bool flag = true;
	if (mp_Statement_List)
		flag = mp_Statement_List->error_detect(symbol_sheet_name);
	return flag;                                  //此处需要为flag&&另一个bool值
}

// Statement_List的语义错误检测
bool Statement_List::error_detect(string symbol_sheet_name)
{
	bool flag = true;
	for (auto i : mv_Statement)
	{
		flag = flag && i->error_detect(symbol_sheet_name);
	}
	return flag;
}


bool Statement::error_detect(string symbol_sheet_name)
{
	bool flag = true;
	if (mp_Assignop)
		flag = mp_Assignop->error_detect(symbol_sheet_name);
	else if (mp_Procedure_call)
		flag = mp_Procedure_call->error_detect(symbol_sheet_name);
	else if (mp_Statement_List)
		flag = mp_Statement_List->error_detect(symbol_sheet_name);
	else if (mp_If_Then_Else)
		flag = mp_If_Then_Else->error_detect(symbol_sheet_name);
	else
		flag = mp_For->error_detect(symbol_sheet_name);
	return flag;
}

//注意，这里需要做下标越界的处理, 判断范围还没进行
bool Variable::error_detect(string symbol_sheet_name)
{
	if (mp_Id)
	{
		if (lookup_symbol(symbol_sheet_name, mp_Id->func_getName()))
		{
			string type = get_symbol_type(symbol_sheet_name, mp_Id->func_getName);
			if (mp_Expression_List&&type.find("array") == string::npos)
			{
				m_isArray = false;
				std::cout << "行" << m_lineno << ": 变量非数组" << endl;
			}
			else if (mp_Expression_List&&
				mp_Expression_List->func_get_mv_exp().size()
				!= get_symbol_range(symbol_sheet_name, mp_Id->func_getName).size())
			{
				m_isArray = true;
				std::cout << "行" << m_lineno << ": 数组维数不对" << endl;
			}
			else if (mp_Expression_List)
			{

			}
			else
				m_isArray = false;
		}
		else
		{
			std::cout << "行" << m_lineno << ": 未声明变量"<<endl;
		}
	}
	else
	{
		std::cout << "行" << mp_Id->m_lineno << "语法树出错" << endl;
	}
	
}



