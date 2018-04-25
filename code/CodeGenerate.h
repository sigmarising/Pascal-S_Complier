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
void Code_Generate(Programstruct *input_Tree, string output_File);