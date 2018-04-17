//	File Name	: CodeGenerate.h
//	Notes		: Define the code generation interface
//	Version		: 0.1
//	Author		: Yun Zhang

#pragma once

#include "Public_define.h"
#include "Syntax_Tree.h"
#include <map>
#include <utility>
#include <iostream>

enum TYPE {
    VOID = -1, INT, REAL, BOOLEAN, CHAR
};  // VOID is for proc
enum SUBPRGRM_TYPE {
    NONE = -1, FUNC, PROC
};  // NONE -> var/const/array
typedef vector<pair<int, int>> ranges;  // not empty -> array
typedef string symbolsheet_name;
typedef string symbol_name;
typedef vector<int> subprgrm_nargs_types;

struct Property {
    TYPE type;  // = INT;  // also indicate the array element's type
    SUBPRGRM_TYPE subprgrm_type;  // = NONE;
    bool is_const;  // = false;
    float const_val;  // = 0;
    ranges array_ranges;  // not none -> array
    int subprgrm_nargs;  // = 0;
    subprgrm_nargs_types nargs_types;
    int dec_line;  // = 0;
    int ref_line;  // = -1;
};
typedef pair<symbol_name, Property> symbol_item;
typedef map<symbol_name, Property> symbol_items;

class symbolSheet {
public:
    string sheet_name;
    symbol_items symbols;

    bool add_parameter_symbols(Parameter_List *parameter_list) {
        for (auto parameter: parameter_list->mv_Patameter) {
            vector<Id *> parameter_symbols = parameter->func_get_mv_id();
            auto type = (TYPE) parameter->func_get_m_type();
            SUBPRGRM_TYPE subprgrm_type = NONE;
            bool is_const = false;
            float const_val = 0;
            int func_nargs = 0;
            subprgrm_nargs_types nargs_types;
            int dec_line = parameter->get_lineno();
            int ref_line = -1;
            ranges array_ranges;
            for (auto parameter_id: parameter_symbols) {
                string name = parameter_id->m_name;
                Property p = {
                        type,
                        subprgrm_type,
                        is_const,
                        const_val,
                        array_ranges,
                        func_nargs,
                        nargs_types,
                        dec_line,
                        ref_line
                };
                if (exists(name)) {
                    symbols[name] = p;
                } else {
                    symbols.insert(symbol_item(name, p));
                }
            }
        }
    }

    bool add_const_symbols(Const_Declarations *const_declarations) {
        for (auto const_symbol: const_declarations->mv_Const) {
            string name = const_symbol.first->m_name;
            auto type = (TYPE) const_symbol.second->m_valueType;
            SUBPRGRM_TYPE subprgrm_type = NONE;
            bool is_const = true;
//            bool is_func = false;
            float const_val = 0;
            if (type == INT) {
                const_val = const_symbol.second->m_int;
            } else if (type == REAL) {
                const_val = const_symbol.second->m_int;
            } else if (type == CHAR) {
                const_val = const_symbol.second->m_int;
            } else if (type == BOOLEAN) {
                const_val = const_symbol.second->m_int;
            } else {
                std::cout << "行" << const_symbol.second->m_lineno << ": 常量声明的类型错误" << endl;
            }
            ranges array_ranges = {};
            int func_nargs = 0;
            subprgrm_nargs_types nargs_types;
            int dec_line = const_symbol.second->m_lineno;
            int ref_line = -1;
            Property p = {
                    type,
                    subprgrm_type,
                    is_const,
                    const_val,
                    array_ranges,
                    func_nargs,
                    nargs_types,
                    dec_line,
                    ref_line
            };
            if (exists(name)) {
                symbols[name] = p;
            } else {
                symbols.insert(symbol_item(name, p));
            }
        }
    }

    bool add_var_symbols(Var_Declarations *var_declarations) {
        for (auto vars: var_declarations->mv_Var) {
            vector<Id *> var_symbols = vars.first->mv_Id;
            auto type = (TYPE) vars.second->func_checkSimpleType();
            SUBPRGRM_TYPE subprgrm_type = NONE;
            bool is_const = false;
//            bool is_func = false;
            float const_val = 0;
            ranges array_ranges;
            if (vars.second->func_check_isArray()) {
                array_ranges = vars.second->func_get_Period();
            }
            int func_nargs = 0;
            subprgrm_nargs_types nargs_types;
            int dec_line = vars.second->get_lineno();
            int ref_fline = -1;

            for (auto var_symbol: var_symbols) {
                string name = var_symbol->m_name;
                Property p = {
                        type,
                        subprgrm_type,
                        is_const,
                        const_val,
                        array_ranges,
                        func_nargs,
                        nargs_types,
                        dec_line,
                        ref_fline
                };
                if (exists(name)) {
                    symbols[name] = p;
                } else {
                    symbols.insert(symbol_item(name, p));
                }
            }
        }
    }

    bool add_subprgrm_symbols(SubProgram_Declarations *subProgram_declarations) {
        for (auto subprgrm: subProgram_declarations->mv_Common) {
            string name = subprgrm->get_func_id()->m_name;
            auto type = (TYPE) subprgrm->func_checkReturnType();  // func: return type; proc: VOID
            auto subprgrm_type = (SUBPRGRM_TYPE) subprgrm->func_get_Common_Type();  // none-subprgrm | func | proc
            bool is_const = false;
            float const_val = 0;
            ranges array_ranges;
            vector<Parameter *> parameters = subprgrm->get_param_list()->mv_Patameter;
            int subprgrm_nargs = 0;
            subprgrm_nargs_types nargs_types;
            for (auto ids: parameters) {
                subprgrm_nargs += ids->get_idlist()->get_id_num();
                Id_List *id_list = ids->get_idlist();
                for (auto id: id_list->mv_Id) {
                    nargs_types.push_back(id->m_idType);
                }
            }
            int dec_line = subprgrm->get_lineno();
            int ref_line = -1;
            Property p = {
                    type,  // return type
                    subprgrm_type,
                    is_const,
                    const_val,
                    array_ranges,
                    subprgrm_nargs,
                    nargs_types,
                    dec_line,
                    ref_line
            };
            symbols.insert(symbol_item(name, p));
        }
    }

    bool exists(const string &symbol_name) {
        symbol_items::iterator it;
        it = this->symbols.find(symbol_name);
        return it != this->symbols.end();
    }

    Property get_symbol_property(const string &symbol_name) {
        if (exists(symbol_name))
            return symbols[symbol_name];
    }

};

map<symbolsheet_name, symbolSheet> symbolSheet_list;
typedef pair<symbolsheet_name, symbolSheet> symbolsheet_list_item;

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
vector<int> get_symbol_narg_type(string symbolSheet_name, string symbol_name);
