//	File Name	: CodeGenerate.h
//	Notes		: Define the code generation interface
//	Version		: 0.1
//	Author		: Yun Zhang

#pragma once

#include "Public_define.h"
#include "Syntax_Tree.h"

//	the interface to call code_genaration
//		input_Tree	: the syntax tree
//		output_File : the filename without suffix
void semantic_Error_Detect(Programstruct* input_Tree, string output_File);

bool lookup_symbol(string symbol_sheet, string symbol_name);
string get_symbol_type(string symbol_sheet, string symbol_name);
vector<pair<int, int> > get_symbol_range(string symbol_sheet, string symbol_name);