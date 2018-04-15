#include "SemanticAnalysis.h"
#include <iostream>

bool Program_Body::create_symbolsheet() {
    symbolSheet global_sheet;
    global_sheet.sheet_name = "0";
    if (global_sheet.add_const_symbols(mp_Const_Declarations) &&
        global_sheet.add_var_symbols(mp_Var_Declarations) &&
        global_sheet.add_subprgrm_symbols(mp_SubProgram_Declarations))
        symbolSheet_list.insert(symbolsheet_list_item("0", global_sheet));
    return !symbolSheet_list.empty();
}

bool Procedure::create_symbolsheet() {
    auto s = (int) symbolSheet_list.size();
    symbolSheet proc_sheet;
    proc_sheet.sheet_name = mp_Id->m_name;  // uses proc name
    if (proc_sheet.add_parameter_symbols(mp_Parameter_List) &&
        proc_sheet.add_const_symbols(mp_Const_Declarations) &&
        proc_sheet.add_var_symbols(mp_Var_Declarations))
        symbolSheet_list.insert(symbolsheet_list_item(proc_sheet.sheet_name, proc_sheet));
    return (bool) ((int) symbolSheet_list.size() - s);
}

bool Function::create_symbolsheet() {
    auto s = (int) symbolSheet_list.size();
    symbolSheet func_sheet;
    func_sheet.sheet_name = mp_Id->m_name;  // uses proc name
    if (func_sheet.add_parameter_symbols(mp_Parameter_List) &&
        func_sheet.add_const_symbols(mp_Const_Declarations) &&
        func_sheet.add_var_symbols(mp_Var_Declarations))
        symbolSheet_list.insert(symbolsheet_list_item(func_sheet.sheet_name, func_sheet));
    return (bool) ((int) symbolSheet_list.size() - s);
}

//注意 Programstruct的错误检测，还不是特别完善
bool Programstruct::error_detect(string symbol_sheet_name) {
    bool flag = true;
    if (this->mp_Program_Body)
        flag = mp_Program_Body->error_detect(symbol_sheet_name);
    return flag;
}

//注意 一半完成,还有声明部分没解决
bool Program_Body::error_detect(string symbol_sheet_name) {
    bool flag = true;
    if (mp_Statement_List)
        flag = mp_Statement_List->error_detect(symbol_sheet_name);
    return flag;                                  //此处需要为flag&&另一个bool值
}

// Statement_List的语义错误检测
bool Statement_List::error_detect(string symbol_sheet_name) {
    bool flag = true;
    for (auto i : mv_Statement) {
        flag = flag && i->error_detect(symbol_sheet_name);

    }
    return flag;
}


bool Statement::error_detect(string symbol_sheet_name) {
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

bool Assignop::error_detect(string symbol_sheet_name) {
    bool flag;
    if (mp_Variable)
        flag = flag && mp_Variable->error_detect(symbol_sheet_name);
    if (mp_Expression)
        flag = flag && mp_Variable->error_detect(symbol_sheet_name);
    if (!mp_Variable || !mp_Expression) {
        flag = false;
        std::cout << "行" << m_lineno << ": 语法树错误" << endl;
    }
    return flag;
}

bool If_Then_Else::error_detect(string symbol_sheet_name) {
    bool flag = true;
    if (mp_Expression)
        flag = mp_Expression->error_detect(symbol_sheet_name);
    else {
        cout << "行" << m_lineno << ": 语法树错误" << endl;
        flag = false;
    }
    if (mp_Statement_1)
        flag = flag && mp_Statement_1;
    if (mp_Statement_1 && mp_Statement_2)
        flag = flag && mp_Statement_2;
    else if (!mp_Statement_1 && mp_Statement_2) {
        cout << "行" << m_lineno << ": 语法树错误" << endl;
        flag = false;
    }
    return flag;
}

bool For::error_detect(string symbol_sheet_name) {
    if (mp_Id && mp_Expression_1 && mp_Expression_2)            //判断语法树是否出错
    {
        if (lookup_symbol(symbol_sheet_name, mp_Id->func_getName())) {
            bool flag = true;
            int type1 = get_symbol_type(symbol_sheet_name, mp_Id->func_getName());
            flag = flag && mp_Expression_1->error_detect(symbol_sheet_name);
            flag = flag && mp_Expression_2->error_detect(symbol_sheet_name);
            int type2 = mp_Expression_1->getType();
            int type3 = mp_Expression_2->getType();
            if ((type1 == TYPE_INTERGER || type1 == TYPE_CHAR) && type1 == type2 && type1 == type3)
                flag = flag;
            else {
                flag = false;
                std::cout << "行" << m_lineno << ": 循环变量有问题" << endl;

            }
            flag = flag && mp_Statment->error_detect(symbol_sheet_name);
            return flag;
        } else {
            std::cout << "行" << m_lineno << ": 未声明变量" << endl;
            return false;
        }
    } else {
        std::cout << "行" << mp_Id->m_lineno << "语法树出错" << endl;
        return false;
    }
}

//注意，这里需要做下标越界的处理, 判断范围还没进行
bool Variable::error_detect(string symbol_sheet_name) {
    if (mp_Id) {
        if (lookup_symbol(symbol_sheet_name, mp_Id->func_getName())) {
            int type1 = get_symbol_type(symbol_sheet_name, mp_Id->func_getName());
            bool flag = true;
            if (mp_Expression_List && type1 != 5) {
                m_isArray = false;
                std::cout << "行" << m_lineno << ": 变量非数组" << endl;
                flag = false;
            } else if (mp_Expression_List &&
                       mp_Expression_List->func_get_mv_exp().size()
                       != get_symbol_range(symbol_sheet_name, mp_Id->func_getName()).size()) {
                m_isArray = true;
                std::cout << "行" << m_lineno << ": 数组维数不对" << endl;
                flag = false;
			}
			else if (mp_Expression_List)
			{
				flag = flag&&mp_Expression_List->error_detect(symbol_sheet_name);
				this->type = get_array_type(symbol_sheet_name, mp_Id->func_getName());
				vector<int> rangeVal1 = mp_Expression_List->rangeVal;
				vector<bool> rangeValid1 = mp_Expression_List->rangeValid;
				vector<pair<int, int> > rangeTemp = get_symbol_range(symbol_sheet_name, mp_Id->func_getName());
				for (int i = 0; i < rangeTemp.size(); i++)
				{
					if (rangeValid1[i])
					{
						if (rangeVal1[i]<rangeTemp[i].first&&rangeVal1[i]>rangeTemp[i].second)
						{
							std::cout << "行" << m_lineno << ": 数组越界" << endl;
							flag = false;
						}
					}
				}
			}
			else
                m_isArray = false;
            return flag;
        } else {
            std::cout << "行" << m_lineno << ": 未声明变量" << endl;
            return false;
        }
    } else {
        std::cout << "行" << mp_Id->m_lineno << "语法树出错" << endl;
        return false;
    }

}


//注意，
bool Function_Call::error_detect(string symbol_sheet_name) {
    bool flag1 = lookup_func(mp_Id->func_getName());
    if (!flag1) {
        std::cout << "行" << m_lineno << ": 非函数" << endl;
        return false;
    }
    int nrgs = get_symbol_narg(symbol_sheet_name, mp_Id->func_getName());
    if (nrgs != mp_Expression_List->func_get_mv_type().size()) {
        std::cout << "行" << m_lineno << ": 实参形参数量不匹配" << endl;
        return false;
    }
    vector<int> types = mp_Expression_List->func_get_mv_type();
    vector<int> arg_types = get_symbol_narg_type(symbol_sheet_name, mp_Id->func_getName());
    for (int i = 0; i < types.size(); i++)
        if (types[i] != arg_types[i]) {
            std::cout << "行" << m_lineno << ": 第" << i << "个实参形参不匹配" << endl;
            return false;
        }
    return true;

}


bool Procedure_Call::error_detect(string symbol_sheet_name) {
    bool flag1 = lookup_procedure(mp_Id->func_getName());
    if (!flag1) {
        std::cout << "行" << m_lineno << ": 非过程" << endl;
        return false;
    }
    int nrgs = get_symbol_narg(symbol_sheet_name, mp_Id->func_getName());
    if (nrgs != mp_Expression_List->func_get_mv_type().size()) {
        std::cout << "行" << m_lineno << ": 实参形参数量不匹配" << endl;
        return false;
    }
    vector<int> types = mp_Expression_List->func_get_mv_type();
    vector<int> arg_types = get_symbol_narg_type(symbol_sheet_name, mp_Id->func_getName());
    for (int i = 0; i < types.size(); i++)
        if (types[i] != arg_types[i]) {
            std::cout << "行" << m_lineno << ": 第" << i << "个实参形参不匹配" << endl;
            return false;
        }
    return true;
}

bool Expression::error_detect(string symbol_sheet_name) {
    if (mp_Relop) {
        bool flag = mp_Relop->error_detect(symbol_sheet_name);
        this->setType(mp_Relop->getType());
		rangeVal = -1;
		rangeValid = false;
        return flag;
    } else if (mp_Simple_Expression) {
        bool flag = mp_Simple_Expression->error_detect(symbol_sheet_name);
        setType(mp_Simple_Expression->getType());
		rangeVal = mp_Simple_Expression->getRangeVal();
		rangeValid = mp_Simple_Expression->getRangeValid();
        return flag;
	}
	else
	{
		rangeVal = -1;
		rangeValid = false;
        std::cout << "行" << m_lineno << "语法树出错" << endl;
        return false;
    }

}


bool Expression_List::error_detect(string symbol_sheet_name) {
    bool flag = true;
    for (int i = 0; i < mv_Expression.size(); i++) {
        flag = flag && mv_Expression[i]->error_detect(symbol_sheet_name);
        mv_Type.push_back(mv_Expression[i]->getType());
		rangeVal.push_back(mv_Expression[i]->getRangeVal());
		rangeValid.push_back(mv_Expression[i]->getRangeValid());
    }
    return flag;
}

bool Relop::error_detect(string symbol_sheet_name) {
    if (mp_Simple_Expression_1 && mp_Simple_Expression_2) {
        bool flag;
        int type1 = mp_Simple_Expression_1->getType();
        int type2 = mp_Simple_Expression_2->getType();
        flag = (type1 == type2 || type1 == TYPE_INTERGER && type2 == TYPE_REAL ||
                type2 == TYPE_INTERGER && type1 == TYPE_REAL);
        setType(TYPE_BOOLEAN);
        return flag;
    } else {
        std::cout << "行" << m_lineno << "语法树出错" << endl;
        return false;
    }
}

bool Simple_Expression::error_detect(string symbol_sheet_name) {
    if (mp_Addop) {
        bool flag = mp_Addop->error_detect(symbol_sheet_name);
        setType(mp_Addop->func_checkAddopType());
		rangeVal = -1;
		rangeValid = false;
        return flag;
    } else if (mp_Term) {
        bool flag = mp_Term->error_detect(symbol_sheet_name);
        setType(mp_Term->getType());
		rangeVal = mp_Term->getRangeVal();
		rangeValid = mp_Term->getRangeValid();
        return flag;
	}
	else
	{
		rangeVal = -1;
		rangeValid = false;
        std::cout << "行" << m_lineno << "语法树出错" << endl;
        return false;
    }
}

//判断Addop的正确性
bool Addop::error_detect(string symbol_sheet_name) {
    bool flag1 = mp_Simple_Expression->error_detect(symbol_sheet_name);
    bool flag2 = mp_Term->error_detect(symbol_sheet_name);
    bool flag3 = true;
    int type1 = mp_Simple_Expression->getType();
    int type2 = mp_Term->getType();
    if (m_addopType == ADDOP_ADD || m_addopType == ADDOP_SUB) {
        flag3 = ((type1 == TYPE_INTERGER || type1 == TYPE_REAL) && (type2 == TYPE_INTERGER || type2 == TYPE_REAL));
        //即使类型不对也会附一个正确类型，出错以后不会再继续执行代码翻译
        if (type1 == TYPE_REAL || type2 == TYPE_REAL)
            setType(TYPE_REAL);
        else
            setType(TYPE_INTERGER);
    } else {
        flag3 = (type1 == type2 && type1 == TYPE_BOOLEAN);
        setType(TYPE_BOOLEAN);
    }
    return flag1 && flag1 && flag3;
}

bool Term::error_detect(string symbol_sheet_name) {
    if (mp_Mulop) {
        bool flag = mp_Mulop->error_detect(symbol_sheet_name);
        setType(mp_Mulop->func_checkMulopType());
		rangeVal = -1;
		rangeValid = false;
        return flag;
    } else if (mp_Factor) {
        bool flag = mp_Factor->error_detect(symbol_sheet_name);
        setType(mp_Factor->func_checkFactorType());
		rangeVal = mp_Factor->getRangeVal();
		rangeValid = mp_Factor->getRangeValid();
        return flag;
	}
	else
	{
		rangeVal = -1;
		rangeValid = false;
        std::cout << "行" << m_lineno << "语法树出错" << endl;
        return false;
    }
}

bool Mulop::error_detect(string symbol_sheet_name) {
    if (mp_Term && mp_Factor) {
        bool flag1 = mp_Term->error_detect(symbol_sheet_name);
        bool flag2 = mp_Factor->error_detect(symbol_sheet_name);
        int type1 = mp_Term->getType();
        int type2 = mp_Factor->getType();
        int opType = this->func_checkMulopType();
        bool flag3 = true;
        if (opType == MULOP_MULTIPLY || opType == MULOP_INT_DIV || opType == MULOP_REAL_DIV) {
            flag3 = ((type1 == TYPE_INTERGER || type1 == TYPE_REAL) && (type2 == TYPE_INTERGER || type2 == TYPE_REAL));
            if (type1 == TYPE_REAL || type2 == TYPE_REAL)
                setType(TYPE_REAL);
            else
                setType(TYPE_INTERGER);
        } else if (opType == MULOP_MOD) {
            flag3 = (type1 == type2) && (type1 = TYPE_INTERGER);
            setType(TYPE_INTERGER);
        } else {
            flag3 = (type1 == type2 && type1 == TYPE_BOOLEAN);
            setType(TYPE_BOOLEAN);
        }
        if (!(flag1 && flag2 && flag3)) {
            std::cout << "行" << m_lineno << ": 类型不匹配." << endl;
            return false;
        }
        return true;

    } else {
        std::cout << "行" << m_lineno << "语法树出错" << endl;
        return false;
    }
}

//注意，Factor的错误检测,factor里的值没修改
bool Factor::error_detect(string symbol_sheet_name) {
    bool flag = true;
    switch (m_factorType) {
		case FACTOR_vALUE_BOOL:
		{
			rangeVal = -1;
			rangeValid = false;
            setType(TYPE_BOOLEAN);
            break;
        }
		case FACTOR_VALUE_INT:
		{

			rangeVal = m_int;
			rangeValid = true;
            setType(TYPE_INTERGER);
            break;
        }
		case FACTOR_VALUE_CHAR:
		{
			rangeVal = -1;
			rangeValid = false;
            setType(TYPE_CHAR);
            break;
        }
		case FACTOR_VALUE_REAL:
		{
			rangeVal = -1;
			rangeValid = false;
            setType(TYPE_REAL);
            break;
        }
		case FACTOR_VAR:
		{
			rangeVal = -1;
			rangeValid = false;
            flag = mp_Variable->error_detect(symbol_sheet_name);
            setType(mp_Variable->getType());
            break;
        }
		case FACTOR_FUNCCALL:
		{
			rangeVal = -1;
			rangeValid = false;
            flag = mp_Function_Call->error_detect(symbol_sheet_name);
            setType(get_func_return_type(mp_Function_Call->mp_Id->func_getName()));
            break;
        }
		case FACTOR_BRACKETS:
		{
			rangeVal = -1;
			rangeValid = false;
            flag = mp_Expression->error_detect(symbol_sheet_name);
            setType(mp_Expression->getType());
            break;
        }
		case FACTOR_NOT:
		{
			rangeVal = -1;
			rangeValid = false;
            flag = mp_Not->error_detect(symbol_sheet_name);
            setType(TYPE_BOOLEAN);
            break;
        }
		case FACTOR_UMINUS:
		{
			int typeTemp = mp_Uminus->getType();
            flag = mp_Uminus->error_detect(symbol_sheet_name);
            setType(mp_Uminus->getType());
			if (typeTemp != TYPE_INTERGER)
			{
				rangeVal = -1;
				rangeValid = false;
			}
			else
			{
				rangeVal = mp_Uminus->getRangeVal();
				rangeValid = true;
			}
            break;
        }

		default:
		{
			rangeVal = -1;
			rangeValid = false;
            std::cout << "行" << m_lineno << "语法树出错" << endl;
            return false;
        }
    }
    return flag;
}

bool Not::error_detect(string symbol_sheet_name) {
    if (mp_Factor) {
        bool flag = true;
        flag = mp_Factor->error_detect(symbol_sheet_name);
        int typeTemp = mp_Factor->getType();
        if (typeTemp != TYPE_BOOLEAN) {
            flag = false;
            std::cout << "行" << m_lineno << ": 非boolean类型不能not" << endl;
        }
        return flag;
    } else {
        std::cout << "行" << m_lineno << "语法树出错" << endl;
        return false;
    }
}

bool Uminus::error_detect(string symbol_sheet_name) {
    if (mp_Factor) {
        bool flag = mp_Factor->error_detect(symbol_sheet_name);
        int typeTemp = mp_Factor->getType();
        if (typeTemp != TYPE_INTERGER && typeTemp != TYPE_REAL) {
            flag = false;
            std::cout << "行" << m_lineno << ": 类型不匹配" << endl;
        }
		rangeVal = mp_Factor->getRangeVal();
		rangeVal = m_unimusType == 0 ? rangeVal : rangeValid;
		rangeValid = mp_Factor->getRangeValid();
        setType(typeTemp);
        return flag;
	}
	else
	{
		setType(TYPE_INTERGER);
        std::cout << "行" << m_lineno << ": 语法树出错" << endl;
        return false;
    }
}

bool lookup_symbol(string symbolSheet_name, string symbol_name) {
    symbolSheet global_sheet = symbolSheet_list["0"];
    symbolSheet sheet;
    if (symbolSheet_name == "0") {
        // global symbol sheet
        sheet = global_sheet;
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return true;
        }
    } else if (symbolSheet_list.find(symbolSheet_name) != symbolSheet_list.end()) {
        // subprgrm symbol sheet, first lookup in the global sheet
        sheet = symbolSheet_list[symbolSheet_name];
        if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end() ||
            sheet.symbols.find(symbol_name) != sheet.symbols.find(symbol_name)) {
            return true;
        }
    }
    return false;
}

int get_symbol_type(string symbolSheet_name, string symbol_name) {
    symbolSheet global_sheet = symbolSheet_list["0"];
    symbolSheet sheet;
    if (symbolSheet_name == "0") {
        // global symbol sheet
        sheet = global_sheet;
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            if (sheet.symbols[symbol_name].array_ranges.empty()) {
                return sheet.symbols[symbol_name].type;  // not array
            } else {
                return TYPE_NULL;  // in fact this is the array type
            }
        }
    } else if (symbolSheet_list.find(symbolSheet_name) != symbolSheet_list.end()) {
        // subprgrm symbol sheet, first lookup in the local sheet, if dont exist then lookup in the global sheet
        sheet = symbolSheet_list[symbolSheet_name];
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            if (sheet.symbols[symbol_name].array_ranges.empty()) {
                return sheet.symbols[symbol_name].type;  // not array
            } else {
                return TYPE_NULL;  // in fact this is the array type
            }
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.find(symbol_name)) {
            if (global_sheet.symbols[symbol_name].array_ranges.empty()) {
                return global_sheet.symbols[symbol_name].type;  // not array
            } else {
                return TYPE_NULL;  // in fact this is the array type
            }
        }
    }
    return VOID;
}

ranges get_symbol_range(string symbolSheet_name, string symbol_name) {
    symbolSheet global_sheet = symbolSheet_list["0"];
    symbolSheet sheet;
    if (symbolSheet_name == "0") {
        // global symbol sheet
        sheet = global_sheet;
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return sheet.symbols[symbol_name].array_ranges;
        }
    } else if (symbolSheet_list.find(symbolSheet_name) != symbolSheet_list.end()) {
        // subprgrm symbol sheet, first lookup in the local sheet, if dont exist then lookup in the global sheet
        sheet = symbolSheet_list[symbolSheet_name];
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return sheet.symbols[symbol_name].array_ranges;
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.find(symbol_name)) {
            return global_sheet.symbols[symbol_name].array_ranges;
        }
    }
}

int get_array_type(string symbolSheet_name, string symbol_name) {
    symbolSheet global_sheet = symbolSheet_list["0"];
    symbolSheet sheet;
    if (symbolSheet_name == "0") {
        // global symbol sheet
        sheet = global_sheet;
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return sheet.symbols[symbol_name].type;
        }
    } else if (symbolSheet_list.find(symbolSheet_name) != symbolSheet_list.end()) {
        // subprgrm symbol sheet, first lookup in the local sheet, if dont exist then lookup in the global sheet
        sheet = symbolSheet_list[symbolSheet_name];
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return sheet.symbols[symbol_name].type;
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.find(symbol_name)) {
            return global_sheet.symbols[symbol_name].type;
        }
    }
}

int get_func_return_type(string symbol_name) {
    symbolSheet global_sheet = symbolSheet_list["0"];
    if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end() &&
        global_sheet.symbols[symbol_name].subprgrm_type == FUNC) {
        return global_sheet.symbols[symbol_name].type;
    }
    return NONE;
}

bool lookup_func(string symbol_name) {
    symbolSheet global_sheet = symbolSheet_list["0"];
    return global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end() &&
           global_sheet.symbols[symbol_name].subprgrm_type == FUNC;
}

bool lookup_procedure(string symbol_name) {
    symbolSheet global_sheet = symbolSheet_list["0"];
    return global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end() &&
           global_sheet.symbols[symbol_name].subprgrm_type == PROC;
}

int get_symbol_narg(string symbolSheet_name, string symbol_name) {
    symbolSheet global_sheet = symbolSheet_list["0"];
    symbolSheet sheet;
    if (symbolSheet_name == "0") {
        // global symbol sheet
        sheet = global_sheet;
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return sheet.symbols[symbol_name].subprgrm_nargs;
        }
    } else if (symbolSheet_list.find(symbolSheet_name) != symbolSheet_list.end()) {
        // subprgrm symbol sheet, first lookup in the local sheet, if dont exist then lookup in the global sheet
        sheet = symbolSheet_list[symbolSheet_name];
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return sheet.symbols[symbol_name].subprgrm_nargs;
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.find(symbol_name)) {
            return global_sheet.symbols[symbol_name].subprgrm_nargs;
        }
    }
}

vector<int> get_symbol_narg_type(string symbolSheet_name, string symbol_name) {
    symbolSheet global_sheet = symbolSheet_list["0"];
    symbolSheet sheet;
    if (symbolSheet_name == "0") {
        // global symbol sheet
        sheet = global_sheet;
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return sheet.symbols[symbol_name].nargs_types;
        }
    } else if (symbolSheet_list.find(symbolSheet_name) != symbolSheet_list.end()) {
        // subprgrm symbol sheet, first lookup in the local sheet, if dont exist then lookup in the global sheet
        sheet = symbolSheet_list[symbolSheet_name];
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return sheet.symbols[symbol_name].nargs_types;
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.find(symbol_name)) {
            return global_sheet.symbols[symbol_name].nargs_types;
        }
    }
}
