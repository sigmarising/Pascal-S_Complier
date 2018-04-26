#include "../include/SemanticAnalysis.h"
#include <iostream>
#include <map>
#include <cassert>
#include <utility>

typedef map<symbolsheet_name, symbolSheet>::value_type symbolsheet_list_item;
map <symbolsheet_name, symbolSheet> symbolSheet_list;
typedef pair<bool, symbolsheet_name> symbolSheet_create_result;
//const string globalsheet_name = "0";

//注意 Programstruct的错误检测，还不是特别完善
bool Programstruct::error_detect() {
    bool flag = true;
    if (this->mp_Program_Body)
        flag = mp_Program_Body->error_detect();

    cout << "program struct finished"<< endl;
    return flag;
}

//声明部分已经解决
bool Program_Body::error_detect() {
    bool flag = true;
    if (mp_SubProgram_Declarations) {
        //cout<<"Program_body subgram"<<endl;
        flag = mp_SubProgram_Declarations->definition_error_detect();

    }
    cout << "definition finished" << endl;
    if (mp_Statement_List) {
        //cout<<" Program_Body Statement_list "<<endl;
        flag = mp_Statement_List->error_detect("0") && flag;
    }
    cout << "program body finished" << endl;
    return flag;                                  //此处需要为flag&&另一个bool值
}

bool Const_Declarations::error_detect(string symbolSheet_name) {
    set <string> id_set;
    bool flag = true;
    for (auto const_symbol: mv_Const) {
        if (symbolSheet_name != "0" && const_symbol.first->m_name == symbolSheet_name) {
            cout << "子程序\"" << symbolSheet_name << "\"声明的常量\"" << const_symbol.first->m_name
                 << "\"不能与子程序名相同" << endl;
            flag = false;
            break;
        }
        auto result = id_set.insert(const_symbol.first->m_name);
        if (!result.second) {
            if (symbolSheet_name == "0") {
                cout << "全局常量声明中存在重复声明错误" << endl;
            } else {
                cout << "子程序\"" << symbolSheet_name << "\"常量声明中存在重复声明错误";
            }
            flag = false;
            break;
        }
    }
    return flag;
}

bool Var_Declarations::error_detect(string symbolSheet_name) {
    set <string> id_set;
    symbolSheet sheet;
    bool flag = true;
    for (auto type_group: mv_Var) {
        for (auto id: type_group.first->mv_Id) {
            string id_name = id->m_name;
            if (symbolSheet_name != "0" && id_name == symbolSheet_name) {
                cout << "子程序\"" << symbolSheet_name << "\"声明的变量\"" << id_name
                     << "\"不能与子程序名相同" << endl;
                flag = false;
                break;
            }
            auto result = id_set.insert(id_name);
            if (!result.second) {
                if (symbolSheet_name == "0") {
                    cout << "全局变量声明行中存在重复声明错误" << endl;
                } else {
                    cout << "子程序\"" << symbolSheet_name << "\"变量声明行中存在重复声明错误";
                }
                flag = false;
                break;
            }
        }
    }
    return flag;
}

bool SubProgram_Declarations::error_detect(string symbolSheet_name) {
    set <string> id_set;
    bool flag = true;
    for (auto subprgrm: mv_Common) {
        string id_name = subprgrm->get_func_id()->m_name;
        auto result = id_set.insert(id_name);
        if (!result.second) {
            cout << "子程序\"" << id_name << "\"重复声明错误" << endl;
            flag = false;
            break;
        }
    }
    return flag;
}

bool SubProgram_Declarations::definition_error_detect() {
    bool flag = true;
    for (auto subprgrm: mv_Common) {
        flag = subprgrm->error_detect()&&flag;
        /*if (!flag) {    尽量一次检测所有的错误
        //    break;
        }*/
    }
    return flag;
}

bool Procedure::error_detect() {
    string proc_name = mp_Id->m_name;
    //cout<<"Proc_name "<< proc_name<<endl;
    symbolSheet sheet = symbolSheet_list[proc_name];
    bool flag = true;
    if (mp_Parameter_List)
        flag = mp_Parameter_List->error_detect(proc_name);
    if (mp_Const_Declarations)
        flag = flag && mp_Const_Declarations->error_detect(proc_name);
    if (mp_Var_Declarations)
        flag = flag && mp_Var_Declarations->error_detect(proc_name);
    if (mp_Statement_List)
        flag = flag && mp_Statement_List->error_detect(proc_name);
    return flag;
}

bool Function::error_detect() {
    string func_name = mp_Id->m_name;
    //cout<<"Proc_name "<< func_name<<endl;
    symbolSheet sheet = symbolSheet_list[func_name];
    bool flag = true;
    if (mp_Parameter_List)
        flag = mp_Parameter_List->error_detect(func_name);
    if (mp_Const_Declarations)
        flag = flag && mp_Const_Declarations->error_detect(func_name);
    if (mp_Var_Declarations)
        flag = flag && mp_Var_Declarations->error_detect(func_name);
    if (mp_Statement_List)
        flag = flag && mp_Statement_List->error_detect(func_name);
    return flag;
}

bool Parameter_List::error_detect(string symbolSheet_name) {
    set <string> id_set;
    bool flag = true;
    for (auto parameter: mv_Patameter) {
        vector < Id * > parameter_symbols = parameter->func_get_mv_id();
        for (auto id: parameter_symbols) {
            string id_name = id->m_name;
            if (id_name == symbolSheet_name) {
                cout << "子程序\"" << symbolSheet_name << "\"声明的形式参数\"" << id_name
                     << "\"不能与子程序名相同" << endl;
                flag = false;
                break;
            }
            auto result = id_set.insert(id_name);
            if (!result.second) {
                cout << "子程序\"" << symbolSheet_name << "\"声明行中形式参数\"" << id_name
                     << "\"存在重复声明错误" << endl;
                flag = false;
                break;
            }
        }
    }
    return flag;
}

// Statement_List的语义错误检测
bool Statement_List::error_detect(string symbol_sheet_name) {
    bool flag = true;
    cout << "Statement_size "<<mv_Statement.size() << endl;
    for (int i=0;i<mv_Statement.size();i++) {
        if (mv_Statement[i]) {

            bool flag1=true;
            flag1 = mv_Statement[i]->error_detect(symbol_sheet_name);
            flag =flag &&flag1;
        }
        else
            cout << "null"<< endl;

    }
    cout << "statement list finished" << endl;
    return flag;
}


bool Statement::error_detect(string symbol_sheet_name) {
    cout << "processing line " << m_lineno << " statement" << endl;
    bool flag = true;
    if (mp_Assignop)
    {
        //cout<<"fuzhi"<<endl;
        flag = mp_Assignop->error_detect(symbol_sheet_name);
    }
    else if (mp_Procedure_call) {
        //cout<<"Procedure_call"<<endl;
        flag = mp_Procedure_call->error_detect(symbol_sheet_name);

    }
    else if (mp_Statement_List) {
        //cout<<"statement_list"<<endl;
        flag = mp_Statement_List->error_detect(symbol_sheet_name);

    }
    else if (mp_If_Then_Else) {
        //cout<<"If_Then_Else"<<endl;
        flag = mp_If_Then_Else->error_detect(symbol_sheet_name);
    }
    else if (mp_For) {
        //cout<<"For"<<endl;
        flag = mp_For->error_detect(symbol_sheet_name);
    }
    else
        cout << "null" << endl;
    cout<<flag<<" return Statement"<<endl;
    return flag;
}

bool Assignop::error_detect(string symbol_sheet_name) {
    bool flag = true;
    if (mp_Variable)
        flag = flag && mp_Variable->error_detect(symbol_sheet_name);
    if (mp_Expression)
        flag = flag && mp_Expression->error_detect(symbol_sheet_name);
    int type1=mp_Variable->getType();
    int type2=mp_Expression->getType();
    bool flag1 = (type1 == type2 || type1 == TYPE_INTERGER&&type2 == TYPE_REAL ||
            type2 == TYPE_INTERGER&&type1 == TYPE_REAL);
    if(!flag1) {
        std::cout << "行" << m_lineno << ": 类型不能转化" << endl;
        flag=false;
    }
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
        flag = flag && mp_Statement_1->error_detect(symbol_sheet_name);
    if (mp_Statement_1 && mp_Statement_2)
        flag = flag && mp_Statement_2->error_detect(symbol_sheet_name);
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
            if ((type1 == TYPE_INTERGER || type1 == TYPE_CHAR) && type1 == type2 && type1 == type3){

            }
            else {
                flag = false;
                std::cout << "行" << m_lineno << ": 循环变量有问题" << endl;

            }
            flag = flag && mp_Statment->error_detect(symbol_sheet_name);
            return flag;
        } else {
            std::cout << "行" << m_lineno << ": 未声明变量\"" << mp_Id->func_getName() << "\"" << endl;
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
            cout<<"Variable "<<type1<<endl;
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
            } else if (mp_Expression_List) {
                flag = flag && mp_Expression_List->error_detect(symbol_sheet_name);
                this->type = get_array_type(symbol_sheet_name, mp_Id->func_getName());
                vector<int> rangeVal1 = mp_Expression_List->rangeVal;
                vector<bool> rangeValid1 = mp_Expression_List->rangeValid;
                vector <pair<int, int>> rangeTemp = get_symbol_range(symbol_sheet_name, mp_Id->func_getName());
                for (int i = 0; i < rangeTemp.size(); i++) {
                    if (rangeValid1[i]) {
                        if (rangeVal1[i] < rangeTemp[i].first || rangeVal1[i] > rangeTemp[i].second) {
                            std::cout << "行" << m_lineno << ": 数组越界" << endl;
                            flag = false;
                        }
                    }
                }
            } else {
                this->type = type1;
                m_isArray = false;
            }
            return flag;
        } else {
            std::cout << "行" << m_lineno << ": 未声明变量\"" << mp_Id->func_getName() << "\"" << endl;
            return false;
        }
    } else {
        std::cout << "行" << mp_Id->m_lineno << "语法树出错" << endl;
        return false;
    }

}

//注意，
//bool Function_Call::error_detect(string symbol_sheet_name) {
//    bool flag1 = lookup_func(mp_Id->func_getName());
//    if (!flag1) {
//        std::cout << "行" << m_lineno << ": 非函数" << endl;
//        return false;
//    }
//    int nrgs = get_symbol_narg(symbol_sheet_name, mp_Id->func_getName());
//    if (nrgs != mp_Expression_List->func_get_mv_type().size()) {
//        std::cout << "行" << m_lineno << ": 实参形参数量不匹配" << endl;
//        return false;
//    }
//    vector<int> types = mp_Expression_List->func_get_mv_type();
//    vector<int> arg_types = get_symbol_narg_type(symbol_sheet_name, mp_Id->func_getName());
//    for (int i = 0; i < types.size(); i++)
//        if (types[i] != arg_types[i]) {
//            std::cout << "行" << m_lineno << ": 第" << i << "个实参形参不匹配" << endl;
//            return false;
//        }
//    return true;
//
//}

bool Function_Call::error_detect(string symbol_sheet_name)
{
    bool flag1 = lookup_func(mp_Id->func_getName());
    if (!flag1)
    {
        std::cout << "行" << m_lineno << ": 非函数" << endl;
        return false;
    }
    int nrgs = get_symbol_narg(symbol_sheet_name,mp_Id->func_getName());
    flag1 = mp_Expression_List->error_detect(symbol_sheet_name);
    if (nrgs == -1)
        return flag1;
    if (nrgs != mp_Expression_List->func_get_mv_type().size())
    {
        std::cout << "行" << m_lineno << ": 实参形参数量不匹配" << endl;
        return false;
    }
    vector<int> types = mp_Expression_List->func_get_mv_type();
    vector<int> arg_types = get_symbol_narg_type(symbol_sheet_name, mp_Id->func_getName());
    for (int i=0;i<types.size();i++) {
        if (types[i] != arg_types[i])
        {
            std::cout << "行" << m_lineno << ": 第"<<i<<"个实参形参不匹配" << endl;
            return false;
        }
    }
    vector<bool> nargs_var_or_not = get_symbol_nargs_var_or_not(symbol_sheet_name, mp_Id->func_getName());
    this->mp_Expression_List->mv_VarDefine = nargs_var_or_not;
    return flag1;

}

//bool Procedure_Call::error_detect(string symbol_sheet_name) {
//    bool flag1 = lookup_procedure(mp_Id->func_getName());
//    if (!flag1) {
//        std::cout << "行" << m_lineno << ": 非过程" << endl;
//        return false;
//    }
//    int nrgs = get_symbol_narg(symbol_sheet_name, mp_Id->func_getName());
//    if (nrgs != mp_Expression_List->func_get_mv_type().size()) {
//        std::cout << "行" << m_lineno << ": 实参形参数量不匹配" << endl;
//        return false;
//    }
//    vector<int> types = mp_Expression_List->func_get_mv_type();
//    vector<int> arg_types = get_symbol_narg_type(symbol_sheet_name, mp_Id->func_getName());
//    for (int i = 0; i < types.size(); i++)
//        if (types[i] != arg_types[i]) {
//            std::cout << "行" << m_lineno << ": 第" << i << "个实参形参不匹配" << endl;
//            return false;
//        }
//    return true;
//}

bool Procedure_Call::error_detect(string symbol_sheet_name)
{
    // set m_proCall_type
    if (mp_Id->func_getName() == "read") {
        m_proCall_Tpye = PROCECALL_READ;
    } else if (mp_Id->func_getName() == "readln") {
        m_proCall_Tpye = PROCECALL_READLN;
    } else if (mp_Id->func_getName() == "write") {
        m_proCall_Tpye = PROCECALL_WRITE;
    } else if (mp_Id->func_getName() == "writeln") {
        m_proCall_Tpye = PROCECALL_WRITELN;
    } else {
        m_proCall_Tpye = PROCECALL_NORMAL;
    }

//    cout << "beep" << endl;
    bool flag1 = lookup_procedure(mp_Id->func_getName())||lookup_func(mp_Id->func_getName());
    if (!flag1) {
        std::cout << "行" << m_lineno << ": 非过程或者函数" << endl;
        return false;
    }
    flag1 = mp_Expression_List->error_detect(symbol_sheet_name);
    int nrgs = get_symbol_narg(symbol_sheet_name, mp_Id->func_getName());
    if (nrgs == -1) {
        // nrgs == -1 -> the proc has variable length of parameters
        vector<bool> nargs_var_or_not(this->mp_Expression_List->mv_Expression.size(), false);
        this->mp_Expression_List->mv_VarDefine = nargs_var_or_not;
        return flag1;
    }
    if (nrgs != mp_Expression_List->func_get_mv_type().size()) {
        std::cout << "行" << m_lineno << ": 实参形参数量不匹配" << endl;
        return false;
    }
    vector<int> types = mp_Expression_List->func_get_mv_type();
    vector<int> arg_types = get_symbol_narg_type(symbol_sheet_name, mp_Id->func_getName());
    for (int i = 0; i<types.size(); i++) {
        if (types[i] != arg_types[i]) {
            std::cout << "行" << m_lineno << ": 第" << i+1 << "个实参形参不匹配" << endl;
            flag1=false;
        }
    }
    vector<bool> nargs_var_or_not = get_symbol_nargs_var_or_not(symbol_sheet_name, mp_Id->func_getName());
    this->mp_Expression_List->mv_VarDefine = nargs_var_or_not;
    cout << "finish " << mp_Id->func_getName() << endl;
    return flag1;
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
    } else {
        rangeVal = -1;
        rangeValid = false;
        std::cout << "行" << m_lineno << "语法树出错" << endl;
        return false;
    }

}


bool Expression_List::error_detect(string symbol_sheet_name) {
    bool flag = true;
    for (auto &i : mv_Expression) {
        flag = i->error_detect(symbol_sheet_name)&&flag;
        mv_Type.push_back(i->getType());
        rangeVal.push_back(i->getRangeVal());
        rangeValid.push_back(i->getRangeValid());
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
        setType(mp_Addop->getType());
        rangeVal = -1;
        rangeValid = false;
        return flag;
    } else if (mp_Term) {
        bool flag = mp_Term->error_detect(symbol_sheet_name);
        setType(mp_Term->getType());
        rangeVal = mp_Term->getRangeVal();
        rangeValid = mp_Term->getRangeValid();
        return flag;
    } else {
        setType(-1);
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
    return flag1 && flag2 && flag3;
}

bool Term::error_detect(string symbol_sheet_name) {
    if (mp_Mulop) {
        bool flag = mp_Mulop->error_detect(symbol_sheet_name);
        setType(mp_Mulop->getType());
        rangeVal = -1;
        rangeValid = false;
        return flag;
    } else if (mp_Factor) {
        bool flag = mp_Factor->error_detect(symbol_sheet_name);
        setType(mp_Factor->getType());
        rangeVal = mp_Factor->getRangeVal();
        rangeValid = mp_Factor->getRangeValid();
        return flag;
    } else {
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
            flag3 = (type1 == type2) && (type1 == TYPE_INTERGER);
            setType(TYPE_INTERGER);
        } else {
            flag3 = (type1 == type2 && type1 == TYPE_BOOLEAN);
            setType(TYPE_BOOLEAN);
        }
        if (!(flag1 && flag2 && flag3)) {
            if(!flag3) {
            std::cout << "行" << m_lineno << ": 类型不匹配." << endl;
            }
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
        case FACTOR_VALUE_BOOL: {
            rangeVal = -1;
            rangeValid = false;
            setType(TYPE_BOOLEAN);
            break;
        }
        case FACTOR_VALUE_INT: {

            rangeVal = m_int;
            rangeValid = true;
            setType(TYPE_INTERGER);
            break;
        }
        case FACTOR_VALUE_CHAR: {
            rangeVal = -1;
            rangeValid = false;
            setType(TYPE_CHAR);
            break;
        }
        case FACTOR_VALUE_REAL: {
            rangeVal = -1;
            rangeValid = false;
            setType(TYPE_REAL);
            break;
        }
        case FACTOR_VAR: {
            rangeVal = -1;
            rangeValid = false;
            flag = mp_Variable->error_detect(symbol_sheet_name);
            setType(mp_Variable->getType());
            break;
        }
        case FACTOR_FUNCCALL: {
            rangeVal = -1;
            rangeValid = false;
            flag = mp_Function_Call->error_detect(symbol_sheet_name);
            setType(get_func_return_type(mp_Function_Call->mp_Id->func_getName()));
            break;
        }
        case FACTOR_BRACKETS: {
            rangeVal = -1;
            rangeValid = false;
            flag = mp_Expression->error_detect(symbol_sheet_name);
            setType(mp_Expression->getType());
            break;
        }
        case FACTOR_NOT: {
            rangeVal = -1;
            rangeValid = false;
            flag = mp_Not->error_detect(symbol_sheet_name);
            setType(TYPE_BOOLEAN);
            break;
        }
        case FACTOR_UMINUS: {
            int typeTemp = mp_Uminus->getType();
            flag = mp_Uminus->error_detect(symbol_sheet_name);
            setType(mp_Uminus->getType());
            if (typeTemp != TYPE_INTERGER) {
                rangeVal = -1;
                rangeValid = false;
            } else {
                rangeVal = mp_Uminus->getRangeVal();
                rangeValid = true;
            }
            break;
        }

        default: {
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
        flag = mp_Factor->error_detect(std::move(symbol_sheet_name));
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
        bool flag = mp_Factor->error_detect(std::move(symbol_sheet_name));
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
    } else {
        setType(TYPE_INTERGER);
        std::cout << "行" << m_lineno << ": 语法树出错" << endl;
        return false;
    }
}

bool lookup_symbol(string symbolSheet_name, string symbol_name) {
//    cout << "looking up symbol" << endl;
    bool flag = true;
    cout<<symbolSheet_name<<endl;
    symbolSheet global_sheet = symbolSheet_list.at("0");
    symbolSheet sheet;
    if (symbolSheet_name == "0") {
        // global symbol sheet
//        cout << "using global sheet" << endl;
        sheet = global_sheet;
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            cout << "found " << symbol_name << " in global symbol sheet" << endl;
            flag = true;
        } else {
            cout << "can't find " << symbol_name << " in global symbol sheet" << endl;
            flag = false;
        }
    } else if (symbolSheet_list.find(symbolSheet_name) != symbolSheet_list.end()) {
//        cout << "found the symbol sheet " << symbolSheet_name << endl;
        // subprgrm symbol sheet, first lookup in the global sheet
        //cout<<symbolSheet_name<<endl;
        sheet = symbolSheet_list[symbolSheet_name];
         if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            cout << "found " << symbol_name << " in the subsymbol sheet" << symbolSheet_name << endl;
            flag = true;
        }else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end()) {
            cout << "found " << symbol_name << " in global symbol sheet" << endl;
            flag = true;
        } else if (global_sheet.symbols.find(symbol_name) == global_sheet.symbols.end()) {
            cout << "can't find " << symbol_name << " in symbol sheet" << endl;
            flag = false;
        }

    } else {
        cout << "can't find symbolsheet \"" << symbolSheet_name << "\"" << endl;
    }
    return flag;
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
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end()) {
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
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end()) {
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
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end()) {
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
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end()) {
            return global_sheet.symbols[symbol_name].subprgrm_nargs;
        }
    }
    return -1;
}

vector<bool> get_symbol_nargs_var_or_not(string symbolSheet_name, string symbol_name) {
    symbolSheet global_sheet = symbolSheet_list["0"];
    symbolSheet sheet;
    if (symbolSheet_name == "0") {
        // global symbol sheet
        sheet = global_sheet;
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return sheet.symbols[symbol_name].nargs_var_or_not;
        }
    } else if (symbolSheet_list.find(symbolSheet_name) != symbolSheet_list.end()) {
        // subprgrm symbol sheet, first lookup in the local sheet, if dont exist then lookup in the global sheet
        sheet = symbolSheet_list[symbolSheet_name];
        if (sheet.symbols.find(symbol_name) != sheet.symbols.end()) {
            return sheet.symbols[symbol_name].nargs_var_or_not;
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end()) {
            return global_sheet.symbols[symbol_name].nargs_var_or_not;
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
        } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end()) {
            return global_sheet.symbols[symbol_name].nargs_types;
        }
    }
}

symbolSheet_create_result Program_Body::create_symbolsheet() {
    symbolSheet global_sheet;
    global_sheet.sheet_name = "0";
    bool f0, f1 = false, f2 = false, f3 = false;
    f0 = global_sheet.add_reserved();
    if (!mp_Const_Declarations->mv_Const.empty() && f0) {
        if (mp_Const_Declarations->error_detect(global_sheet.sheet_name)) {
            f1 = global_sheet.add_const_symbols(mp_Const_Declarations);
            if (!f1) {
                cout << "error occurs when adding parameter symbols into global sheet" << endl;
            }
        }
    } else {
        cout << "no parameter symbols to be added into global sheet" << endl;
        f1 = true;
    }
    if (!mp_Var_Declarations->mv_Var.empty() && f1) {
        if (mp_Var_Declarations->error_detect(global_sheet.sheet_name)) {
            f2 = global_sheet.add_var_symbols(mp_Var_Declarations);
            if (!f2) {
                cout << "error occurs when adding const symbols into global sheet" << endl;
            }
        }
    } else {
        cout << "no const symbols to be added into global sheet" << endl;
        f2 = true;
    }
    if (!mp_SubProgram_Declarations->mv_Common.empty() && f2) {
        if (mp_SubProgram_Declarations->error_detect(global_sheet.sheet_name)) {
            f3 = global_sheet.add_subprgrm_symbols(mp_SubProgram_Declarations);
            if (!f3) {
                cout << "error occurs when adding variable symbols into global sheet" << endl;
            }
        }
    } else {
        cout << "no variable symbols to be added into global sheet" << endl;
        f3 = true;
    }
    if (f0 && f1 && f2 && f3) {
        auto re = symbolSheet_list.insert(symbolsheet_list_item(global_sheet.sheet_name, global_sheet));
        if (re.second) {
            cout << "these symbols have been added to global sheet:" << endl;
            for (auto i:global_sheet.symbols) {
                cout << i.first << " ";
            }
            cout << endl;
        } else {
            cout << "no symbols have been added to global sheet" << endl;
        }
    } else {
        cout << "error occurs when building global symbol sheets, pls check the above info." << endl;
    }
    return symbolSheet_create_result(!symbolSheet_list.empty(), global_sheet.sheet_name);
}

symbolSheet_create_result Procedure::create_symbolsheet() {
    auto s = symbolSheet_list.size();
    symbolSheet proc_sheet;
    proc_sheet.sheet_name = mp_Id->m_name;  // uses proc name
    bool f0, f1 = false, f2 = false, f3 = false;
    f0 = proc_sheet.add_reserved();
    if (mp_Parameter_List && f0) {
        if (mp_Parameter_List->error_detect(proc_sheet.sheet_name)) {
            f1 = proc_sheet.add_parameter_symbols(mp_Parameter_List);
            if (!f1) {
                cout << "error occurs when adding parameter symbols into " << proc_sheet.sheet_name << endl;
            }
        }
    } else {
        cout << "no parameter symbols to be added into " << proc_sheet.sheet_name << endl;
        f1 = true;
    }
    if (mp_Const_Declarations && f1) {
        if (mp_Const_Declarations->error_detect(proc_sheet.sheet_name)) {
            f2 = proc_sheet.add_const_symbols(mp_Const_Declarations);
            if (!f2) {
                cout << "error occurs when adding const symbols into " << proc_sheet.sheet_name << endl;
            }
        }
    } else {
        cout << "no const symbols to be added into " << proc_sheet.sheet_name << endl;
        f2 = true;
    }
    if (mp_Var_Declarations && f2) {
        if (mp_Var_Declarations->error_detect(proc_sheet.sheet_name)) {
            f3 = proc_sheet.add_var_symbols(mp_Var_Declarations);
            if (!f3) {
                cout << "error occurs when adding variable symbols into " << proc_sheet.sheet_name << endl;
            }
        }
    } else {
        cout << "no variable symbols to be added into " << proc_sheet.sheet_name << endl;
        f3 = true;
    }

    if (f0 && f1 && f2 && f3) {
        auto re = symbolSheet_list.insert(symbolsheet_list_item(proc_sheet.sheet_name, proc_sheet));
        if (re.second) {
            cout << "these symbols have been added to " << proc_sheet.sheet_name << ":" << endl;
            for (auto i:proc_sheet.symbols) {
                cout << i.first << " ";
            }
            cout << endl;
        } else {
            cout << proc_sheet.sheet_name << "'s symbol sheet not added" << endl;
        }
    } else {
        cout << "error occurs when building " << proc_sheet.sheet_name << "'s symbol sheets, pls check the above info." << endl;
    }
    return symbolSheet_create_result(bool(symbolSheet_list.size() - s), proc_sheet.sheet_name);
}

symbolSheet_create_result Function::create_symbolsheet() {
    auto s = symbolSheet_list.size();
    symbolSheet func_sheet;
    func_sheet.sheet_name = mp_Id->m_name;  // uses proc name
    bool f0, f1 = false, f2 = false, f3 = false;
    f0 = func_sheet.add_reserved();
    if (mp_Parameter_List && f0) {
        if (mp_Parameter_List->error_detect(func_sheet.sheet_name)) {
            f1 = func_sheet.add_parameter_symbols(mp_Parameter_List);
            if (!f1) {
                cout << "error occurs when adding parameter symbols into " << func_sheet.sheet_name << endl;
            }
        }
    } else {
        cout << "no parameter symbols to be added into " << func_sheet.sheet_name << endl;
        f1 = true;
    }
    if (mp_Const_Declarations && f1) {
        if (mp_Const_Declarations->error_detect(func_sheet.sheet_name)) {
            f2 = func_sheet.add_const_symbols(mp_Const_Declarations);
            if (!f2) {
                cout << "error occurs when adding const symbols into " << func_sheet.sheet_name << endl;
            }
        }
    } else {
        cout << "no const symbols to be added into " << func_sheet.sheet_name << endl;
        f2 = true;
    }
    if (mp_Var_Declarations && f2) {
        if (mp_Var_Declarations->error_detect(func_sheet.sheet_name)) {
            f3 = func_sheet.add_var_symbols(mp_Var_Declarations);
            if (!f3) {
                cout << "error occurs when adding variable symbols into " << func_sheet.sheet_name << endl;
            }
        }
    } else {
        cout << "no variable symbols to be added into " << func_sheet.sheet_name << endl;
        f3 = true;
    }

    if (f0 && f1 && f2 && f3) {
        auto re = symbolSheet_list.insert(symbolsheet_list_item(func_sheet.sheet_name, func_sheet));
        if (re.second) {
            cout << "these symbols have been added to " << func_sheet.sheet_name << ":" << endl;
            for (auto i: func_sheet.symbols) {
                cout << i.first << " ";
            }
            cout << endl;
        } else {
            cout << func_sheet.sheet_name << "'s symbol sheet not added" << endl;
        }
    } else {
        cout << "error occurs when building " << func_sheet.sheet_name << "'s symbol sheets, pls check the above info." << endl;
    }
    return symbolSheet_create_result(bool(symbolSheet_list.size() - s), func_sheet.sheet_name);
}


bool semantic_Error_Detect(Programstruct *input_Tree) {
    bool flag = true;
    // first, build the symbol sheets
    if (input_Tree->mp_Program_Body)
        flag = input_Tree->mp_Program_Body->create_symbolsheet().first;
    assert(!symbolSheet_list.empty());
//    cout << "global sheet is added" << endl;
    cout << endl;
    if (!input_Tree->mp_Program_Body->mp_SubProgram_Declarations->mv_Common.empty()) {
        for (auto subprogram: input_Tree->mp_Program_Body->mp_SubProgram_Declarations->mv_Common) {
            cout << "processing " << subprogram->get_func_id()->m_name << endl;
            flag = flag && subprogram->create_symbolsheet().first;
            if (!flag) {
                break;
            } else {
//                cout << subprogram->get_func_id()->m_name << "'s sheet is added" << endl;
                cout << endl;
            }
        }
    }
    assert(symbolSheet_list.find("0") != symbolSheet_list.end());
    cout << "finish building symbol sheets, sheets added to the list:" << endl;
    for (auto i: symbolSheet_list) {
        cout << i.first << " ";
    }
    cout << endl << endl << "start checking semantic errors" << endl;
    // then, check semantic error
    if (flag) {
        flag = input_Tree->error_detect()&&flag;
    }
    return flag;
}
