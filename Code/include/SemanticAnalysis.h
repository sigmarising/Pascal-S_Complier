//	File Name	: SemanticAnalysis.h
//	Notes		: Define the code semantic interface
//	Version		: 0.2
//	Author		: Yang Zhenghao, Chen Wentao

#pragma once
#ifndef SEMANTICANALYSIS_H_
#define SEMANTICANALYSIS_H_
#include "Syntax_Tree.h"
#include <map>
#include <set>
#include <utility>
#include <iostream>

enum TYPES {
    VOID = -1, INT, _REAL, _BOOLEAN, _CHAR, RESERVED
};  // VOID is for proc
enum SUBPRGRM_TYPE {
    NONE = -1, FUNC, PROC
};  // NONE -> var/const/array
typedef vector<pair<int, int>> ranges;  // not empty -> array
typedef string symbolsheet_name;
typedef string symbol_name;
typedef vector<int> subprgrm_nargs_types;
const set<symbol_name> keywords = {
        "program",
        "var", "const",
        "function", "procedure",
        "begin", "end",
        "array", "of",
        "integer", "real",
        "boolean", "char",
        "true", "false",
        "and", "or", "not",
        "div", "mod",
        "if", "then", "else",
        "for", "to", "do"
};
const set<symbol_name> builtin_functions = {
        "read", "readln",
        "write", "writeln"
};
struct Property {
    TYPES type;  // = INT;  // also indicate the array element's type
    SUBPRGRM_TYPE subprgrm_type;  // = NONE;
    bool is_const;  // = false;
    float const_val;  // = 0;
    bool is_Var;
    ranges array_ranges;  // not none -> array
    int subprgrm_nargs;  // = 0;
    vector<bool> nargs_var_or_not;
    subprgrm_nargs_types nargs_types;
    int dec_line;  // = 0;
    int ref_line;  // = -1;
};
typedef pair<symbol_name, Property> symbol_item;
typedef map <symbol_name, Property> symbol_items;

//	the interface to call code_genaration
//		input_Tree	: the syntax tree
//      output      : whether to continue
bool semantic_Error_Detect(Programstruct *input_Tree);

bool lookup_symbol(string symbolSheet_name, string symbol_name);

int get_symbol_type(string symbolSheet_name, string symbol_name);

ranges get_symbol_range(string symbolSheet_name, string symbol_name);

int get_array_type(string symbolSheet_name, string symbol_name);

int get_func_return_type(string symbol_name);

bool lookup_func(string symbol_name);                          //判断是否是函数

bool lookup_procedure(string symbol_name);

int get_symbol_narg(string symbolSheet_name, string symbol_name);  //返回参数个数

vector<bool> get_symbol_nargs_var_or_not(string symbolSheet_name, string symbol_name);  // return the subprogram's 'nargs_var_or_not' list

vector<int> get_symbol_narg_type(string symbolSheet_name, string symbol_name);

bool get_symbol_var_type(string symbolSheet_name, string symbol_name);

class symbolSheet;
static map <symbolsheet_name, symbolSheet> symbolSheet_list;

class symbolSheet {
public:
    string sheet_name;
    symbol_items symbols;

    bool add_reserved() {
        bool flag = true;
        for (auto keyword: keywords) {
            TYPES type = RESERVED;
            SUBPRGRM_TYPE subprgrm_type = NONE;
            bool is_const = false;
            float const_val = 0;
            bool is_Var = false;
            int func_nargs = 0;
            vector<bool> nargs_var_or_not = {false};
            subprgrm_nargs_types nargs_types;
            int dec_line = 0;
            int ref_line = -1;
            ranges array_ranges;
            Property p = {
                    type,
                    subprgrm_type,
                    is_const,
                    const_val,
                    is_Var,
                    array_ranges,
                    func_nargs,
                    nargs_var_or_not,
                    nargs_types,
                    dec_line,
                    ref_line
            };
            if (symbols.insert(symbol_item(keyword, p)).second) {
//                cout << keyword << " inserted into symbol sheet " << sheet_name << endl;
                continue;
            } else {
                cout << "error happens when adding keyword symbol " << keyword << " into the symbol sheet" << endl;
                flag = false;
                break;
            }
        }
        for (auto builtins: builtin_functions) {
            // read, readln, write, writeln
            TYPES type = RESERVED;
            SUBPRGRM_TYPE subprgrm_type = PROC;
            bool is_const = false;
            float const_val = 0;
            bool is_Var = false;
            int func_nargs = -1;  // -1 indicates the subprogram could have variable length of parameters
            vector<bool> nargs_var_or_not = {false};
            subprgrm_nargs_types nargs_types;
            int dec_line = 0;
            int ref_line = -1;
            ranges array_ranges;
            Property p = {
                    type,
                    subprgrm_type,
                    is_const,
                    const_val,
                    is_Var,
                    array_ranges,
                    func_nargs,
                    nargs_var_or_not,
                    nargs_types,
                    dec_line,
                    ref_line
            };
            if (symbols.insert(symbol_item(builtins, p)).second) {
//                cout << builtins << " inserted into symbol sheet " << sheet_name << endl;
                continue;
            } else {
                cout << "error happens when adding builtin symbol " << builtins << " into the symbol sheet" << endl;
                flag = false;
                break;
            }
        }
        return flag;
    }

    bool add_parameter_symbols(Parameter_List *parameter_list) {
        bool flag = true;
        for (auto parameter: parameter_list->mv_Patameter) {
            vector<Id *> parameter_symbols = parameter->func_get_mv_id();
            auto type = (TYPES) parameter->func_get_m_type();
            SUBPRGRM_TYPE subprgrm_type = NONE;
            bool is_const = false;
            float const_val = 0;
            bool is_Var = parameter->m_isVal;
            int func_nargs = 0;
            vector<bool> nargs_var_or_not = {false};
            subprgrm_nargs_types nargs_types;
            int dec_line = parameter->get_lineno();
            int ref_line = -1;
            ranges array_ranges;
            for (auto parameter_id: parameter_symbols) {
                string name = parameter_id->m_name;
                if (check_is_reserved(name))  {
                    cout << "parameter identifier \"" << name << "\" conflicts with Pascal reserved word" << endl;
                    flag = false;
                    break;
                }
                Property p = {
                        type,
                        subprgrm_type,
                        is_const,
                        const_val,
                        is_Var,
                        array_ranges,
                        func_nargs,
                        nargs_var_or_not,
                        nargs_types,
                        dec_line,
                        ref_line
                };
                if (exists(name)) {
                    symbols[name] = p;
                } else {
                    if (symbols.insert(symbol_item(name, p)).second) {
//                        cout << name << " inserted into symbol sheet " << sheet_name << endl;
                        continue;
                    } else {
                        cout << "error happens when adding parameter symbol " << name << " into the symbol sheet" << endl;
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) {
                break;
            }
        }
        return flag;
    }

    bool add_const_symbols(Const_Declarations *const_declarations) {
        bool flag = true;
        for (auto const_symbol: const_declarations->mv_Const) {
            string name = const_symbol.first->m_name;
            if (check_is_reserved(name))  {
                cout << "const identifier \"" << name << "\" conflicts with Pascal reserved word" << endl;
                flag = false;
                break;
            }
            TYPES type;
            SUBPRGRM_TYPE subprgrm_type = NONE;
            float const_val = 0;
            bool is_const = true;
            if (!const_symbol.second->mp_Id) {
                type = (TYPES) const_symbol.second->m_valueType;
                if (type == INT) {
                    const_val = const_symbol.second->m_int;
                } else if (type == _REAL) {
                    const_val = const_symbol.second->m_real;
                } else if (type == _CHAR) {
                    const_val = const_symbol.second->m_char;
                } else if (type == _BOOLEAN) {
                    const_val = const_symbol.second->m_bool;
                } else {
                    std::cout << "行" << const_symbol.second->m_lineno << ": 常量声明的类型错误" << endl;
                    flag = false;
                    break;
                }
            } else {
                Id * that_symbol = const_symbol.second->mp_Id;
                type = (TYPES) that_symbol->m_idType;
                const_val = get_const_symbol_value(that_symbol->m_name);
                if (type != INT && type != _REAL && type != _CHAR && type != _BOOLEAN) {
                    std::cout << "行" << const_symbol.second->m_lineno << ": 常量声明的类型错误" << endl;
                    flag = false;
                    break;
                }
            }
            if (const_symbol.second->m_postNeg == 2)
                const_val = - const_val;
            bool is_Var = false;
            ranges array_ranges = {};
            int func_nargs = 0;
            vector<bool> nargs_var_or_not = {false};
            subprgrm_nargs_types nargs_types;
            int dec_line = const_symbol.second->m_lineno;
            int ref_line = -1;
            Property p = {
                    type,
                    subprgrm_type,
                    is_const,
                    const_val,
                    is_Var,
                    array_ranges,
                    func_nargs,
                    nargs_var_or_not,
                    nargs_types,
                    dec_line,
                    ref_line
            };
            if (exists(name)) {
                symbols[name] = p;
            } else {
                if (symbols.insert(symbol_item(name, p)).second) {
                    // cout << name << " inserted into symbol sheet " << sheet_name << endl;
                    continue;
                } else {
                    cout << "error happens when adding const symbol " << name << " into the symbol sheet" << endl;
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }

    bool add_var_symbols(Var_Declarations *var_declarations) {
        bool flag = true;
        for (auto vars: var_declarations->mv_Var) {
            vector<Id *> var_symbols = vars.first->mv_Id;
            auto type = (TYPES) vars.second->func_checkSimpleType();
            SUBPRGRM_TYPE subprgrm_type = NONE;
            bool is_const = false;
//            bool is_func = false;
            float const_val = 0;
            bool is_Var = false;
            ranges array_ranges;
            if (vars.second->func_check_isArray()) {
                array_ranges = vars.second->func_get_Period();
            }
            int func_nargs = 0;
            vector<bool> nargs_var_or_not = {false};
            subprgrm_nargs_types nargs_types;
            int dec_line = vars.second->get_lineno();
            int ref_line = -1;

            for (auto var_symbol: var_symbols) {
                string name = var_symbol->m_name;
                if (check_is_reserved(name))  {
                    cout << "var identifier \"" << name << "\" conflicts with Pascal reserved word" << endl;
                    flag = false;
                    break;
                }
                Property p = {
                        type,
                        subprgrm_type,
                        is_const,
                        const_val,
                        is_Var,
                        array_ranges,
                        func_nargs,
                        nargs_var_or_not,
                        nargs_types,
                        dec_line,
                        ref_line
                };
                if (exists(name)) {
                    symbols[name] = p;
                } else {
                    if (symbols.insert(symbol_item(name, p)).second) {
//                        cout << name << " inserted into symbol sheet " << sheet_name << endl;
                        continue;
                    } else {
                        cout << "error happens when adding variable symbol " << name << " into the symbol sheet" << endl;
//                        cout << "var type: " << vars.second->m_simpleType << endl;
//                        cout << "var symbol: " << name << type << subprgrm_type << is_const
//                             << const_val << func_nargs << dec_line << ref_line << endl;
                        flag = false;
                        break;
                    }
                }
            }
        }
        return flag;
    }

    bool add_subprgrm_symbols(SubProgram_Declarations *subProgram_declarations) {
        bool flag = true;
        for (auto subprgrm: subProgram_declarations->mv_Common) {
            string name = subprgrm->get_func_id()->m_name;
            if (check_is_reserved(name))  {
                cout << "subprogram identifier \"" << name << "\" conflicts with Pascal reserved word" << endl;
                flag = false;
                break;
            }
            auto type = (TYPES) subprgrm->func_checkReturnType();  // func: return type; proc: VOID
            auto subprgrm_type = (SUBPRGRM_TYPE) subprgrm->func_get_Common_Type();  // none-subprgrm | func | proc
            bool is_const = false;
            float const_val = 0;
            bool is_Var = false;
            ranges array_ranges;
            int subprgrm_nargs = 0;
            vector<bool> nargs_var_or_not;
            subprgrm_nargs_types nargs_types;
            if (subprgrm->get_param_list()) {
                vector<Parameter *> parameters = subprgrm->get_param_list()->mv_Patameter;
                for (auto ids: parameters) {
                    bool isVar = ids->m_isVal;
                    subprgrm_nargs += ids->get_idlist()->get_id_num();
                    Id_List *id_list = ids->get_idlist();
                    for (auto id: id_list->mv_Id) {
                        nargs_types.push_back(id->m_idType);
                        nargs_var_or_not.push_back(isVar);
                    }
                }
            }
            int dec_line = subprgrm->get_lineno();
            int ref_line = -1;
            Property p = {
                    type,  // return type
                    subprgrm_type,
                    is_const,
                    const_val,
                    is_Var,
                    array_ranges,
                    subprgrm_nargs,
                    nargs_var_or_not,
                    nargs_types,
                    dec_line,
                    ref_line
            };
            if (symbols.insert(symbol_item(name, p)).second) {
//                cout << name << " inserted into symbol sheet " << sheet_name << endl;
                continue;
            } else {
                cout << "error happens when adding subprogram symbol " << name << " into the symbol sheet" << endl;
                flag = false;
                break;
            }
        }
        return flag;
    }

    bool exists(const string &symbol_name) {
        symbol_items::iterator it;
        it = this->symbols.find(symbol_name);
        return it != this->symbols.end();
    }

    bool check_is_reserved(const string &symbol_name) {
        return keywords.find(symbol_name) != keywords.end() || builtin_functions.find(symbol_name) != builtin_functions.end();
    }

    float get_const_symbol_value(const string &symbol_name) {
//        symbolSheet global_sheet;
//        if (symbolSheet_list.find("0") != symbolSheet_list.end())
//            global_sheet = symbolSheet_list["0"];
        if (this->sheet_name == "0") {
            // global symbol sheet
            if (this->symbols.find(symbol_name) != this->symbols.end()) {
                return this->symbols[symbol_name].const_val;
            }
        } else {
            // subprgrm symbol sheet, first lookup in the local sheet, if dont exist then lookup in the global sheet
            symbolSheet global_sheet;
            if (symbolSheet_list.find("0") != symbolSheet_list.end())
                global_sheet = symbolSheet_list["0"];
            else {
                cout << "error: no global sheet found" << endl;
                exit(1);
            }
            if (this->symbols.find(symbol_name) != this->symbols.end()) {
                return this->symbols[symbol_name].const_val;
            } else if (global_sheet.symbols.find(symbol_name) != global_sheet.symbols.end()) {
                return global_sheet.symbols[symbol_name].const_val;
            }
        }
    }

};

#endif