//	File Name	: Public_define.h
//	Notes		: Define the Public define
//	Version		: 0.6
//	Author		: Yun Zhang 
//				: cbox

#pragma once

// the type define 
#define TYPE_INTERGER	0
#define TYPE_REAL		1
#define TYPE_BOOLEAN	2
#define TYPE_CHAR		3
#define TYPE_ID			4
#define TYPE_NULL       5  // array type
#define TYPE_NIL        (-1)

// the const postNeg Type
#define CONST_POSTNEG_NULL		0
#define CONST_POSTNEG_POSITIVE	1
#define	CONST_POSTNEG_NEGATIVE	2

// the procedure call type
#define	PROCECALL_NORMAL		0
#define PROCECALL_READ			1
#define	PROCECALL_READLN		2
#define	PROCECALL_WRITE			3
#define PROCECALL_WRITELN		4

// the Relop type
#define RELOP_EQUAL			0
#define	RELOP_NOT_EQUAL		1
#define	RELOP_LESS			2
#define	RELOP_LESS_EQUAL	3	
#define	RELOP_LARGE			4
#define	RELOP_LARGE_EQUAL	5

// the Addop type
#define ADDOP_ADD	0
#define ADDOP_SUB	1
#define ADDOP_OR	2

// the Mulop type
#define MULOP_MULTIPLY	0
#define MULOP_READ_DIV	1
#define MULOP_INT_DIV	2
#define MULOP_MOD		3
#define MULOP_AND		4

// the common type
#define COMMON_FUNCTION		0
#define COMMON_PROCEDURE	1

// the statement type
#define STATEMENT_ASSIGN		0
#define STATEMENT_PROCEDURE		1
#define STATEMENT_COMPOUND		2
#define STATEMENT_IF			3
#define STATEMENT_FOR			4

// the factor Type
#define FACTOR_VAR			0
#define FACTOR_FUNCCALL		1
#define FACTOR_BRACKETS		2
#define FACTOR_NOT			3
#define FACTOR_UMINUS		4
#define FACTOR_VALUE_INT	5
#define FACTOR_VALUE_REAL	6
#define FACTOR_VALUE_CHAR	7
#define FACTOR_vALUE_BOOL	8

// the uminus type
#define UMINUS_POSITIVE		0
#define UMINUS_NEGATIVE		1