/*DONE LIST*/
/*警告:关键字begin的识别token为BEGIN_L.因为BEGIN在y.tab.c为定义过的关键字，因此要避开*/

/*TO DO LIST*/
/*注释函数未处理*/
/*错误处理，可以处理如：1&，此类的错误*/
/*但是不能处理如：1.2a3，此识别结果为1.2 number和a3 identifier*/

/*语法程序可能遇到的接口*/
/*yytext存储了当前识别的字符串*/
/*yylineno存储了行数，(yyrowno-yyleng) - (yyrowno-1)为列数范围*/
%{
#include<stdio.h>
#include "y.tab.h"
#include<string.h>
extern YYSTYPE yylval;
extern char* yytext;
int yyrowno = 1;
%}

%option yylineno
space [' ']
digit [0-9] 
digits {digit}+
letter [a-zA-Z]
E [E][+-]?{digit}+

id {letter}({letter}|{digit})*
num {digit}+("."{digit}+)?({E})?

character [\']({letter}|[' '])[\']



%%


"and"			{ printf("%s\tmulop\n",yytext); yyrowno+=yyleng;  return AND; }
"array"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return ARRAY; }
"begin"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return BEGIN_L; }
"boolean"		{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return BOOLEAN; }
"case"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return CASE; }
"char"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return CHAR; }
"const"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return CONST; }
"div"			{ printf("%s\tmulop\n",yytext); yyrowno+=yyleng;  return DIV; }
"do"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return DO; }
"downto"		{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return DOWNTO; }
"else"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return ELSE; }
"end"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return END; }
"for"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return FOR; }
"function"		{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return FUNCTION; }
"if"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return IF; }
"integer"		{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return INTEGER; }
"mod"			{ printf("%s\tmulop\n",yytext); yyrowno+=yyleng;  return MOD; }
"not"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return NOT; }
"of"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return OF; }
"or"			{ printf("%s\taddop\n",yytext); yyrowno+=yyleng;  return OR; }
"procedure"		{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return PROCEDURE; }
"program"		{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return PROGRAM; }
"real"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return REAL; }
"record"		{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return RECORD; }
"repeat"		{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return REPEAT; }
"then"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return THEN; }
"type"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return TYPE; }
"until"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return UNTIL; }
"var"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return VAR; }
"while"			{ printf("%s\tkeyword\n",yytext); yyrowno+=yyleng;  return WHILE; }

{space}         { yyrowno += 1; }
{character}     { printf("%s\tletter\n",yytext); yyrowno+=yyleng;  return LETTER; }
{id}            { printf("%s\tidentifier\n",yytext); yyrowno+=yyleng;  return IDENTIFIER; }
{digits} 		{printf("%s\tdigits\n",yytext); yyrowno+=yyleng;  return DIGITS;}
{num}           { printf("%s\tnumber\n",yytext); yyrowno+=yyleng;  return NUMBER; }
".."			{ printf("%s\tsubboundary\n",yytext); yyrowno+=yyleng;  return SUBBOUNDARY; }
":="            { printf("%s\tassignop\n",yytext); yyrowno+=yyleng;  return ASSIGNOP; }


"<="			{ printf("%s\trelop\n",yytext); yyrowno+=yyleng;  return LE_OP; }
">="			{ printf("%s\trelop\n",yytext); yyrowno+=yyleng;  return GE_OP; }
"<>"			{ printf("%s\trelop\n",yytext); yyrowno+=yyleng;  return NE_OP; }
"="				{ printf("%s\trelop\n",yytext); yyrowno+=yyleng;  return '='; }
"<"				{ printf("%s\trelop\n",yytext); yyrowno+=yyleng;  return '<'; }
">"				{ printf("%s\trelop\n",yytext); yyrowno+=yyleng;  return '>'; }

","				{ printf(",\n"); yyrowno+=yyleng;  return ','; }
":"				{ printf(":\n"); yyrowno+=yyleng;  return ':'; }
";"				{ printf(";\n"); yyrowno+=yyleng;  return ';'; }
"."				{ printf(".\n"); yyrowno+=yyleng;  return '.'; }
"("				{ printf("(\n"); yyrowno+=yyleng;  return '('; }
")"				{ printf(")\n"); yyrowno+=yyleng;  return ')'; }
"["				{ printf("[\n"); yyrowno+=yyleng;  return '['; }
"]"				{ printf("]\n"); yyrowno+=yyleng;  return ']'; }
"{"				{ printf("{\n"); yyrowno+=yyleng;  return '{'; }
"}"				{ printf("}\n"); yyrowno+=yyleng;  return '}'; }

"*"				{ printf("%s\tmulop\n",yytext); yyrowno+=yyleng;  return '*'; }
"/"				{ printf("%s\tmulop\n",yytext); yyrowno+=yyleng;  return '/'; }
"-"				{ printf("%s\taddop\n",yytext); yyrowno+=yyleng;  return '-'; }
"+"				{ printf("%s\taddop\n",yytext); yyrowno+=yyleng;  return '+'; }



[\n]            { yyrowno = 1; }
[\t]		    { yyrowno += 4; }
.				{ printf("Error:lexical error : %s happens on Row : %d, Line : %d - %d\n",yytext,yylineno,yyrowno-yyleng+1,yyrowno); }
%%
int yywrap(){
    return 1;
}