/*DONE LIST*/
/*警告:关键字begin的识别token为BEGIN_L.因为BEGIN在y.tab.c为定义过的关键字，因此要避开*/

/*TO DO LIST*/
/*注释函数未处理*/
/*错误处理，可以处理如：1&，此类的错误*/
/*但是不能处理如：1.2a3，此识别结果为1.2 number和a3 identifier*/

/*语法程序可能遇到的接口*/
/*new std::string(yytext)存储了当前识别的字符串*/
/*yylineno存储了行数，(yyrowno-yyleng) - (yyrowno-1)为列数范围*/
%{
#include<stdio.h>
#include "pasc.tab.h"
#include<string.h>
extern YYSTYPE yylval;
extern char* yytext;
int yyrowno = 1;
%}

%option yylineno

comments1  \{[^\}]*\}
comments2  \(\*([^\*^\)]*|[\*^\)*]*|[^\**\)]*)*\*\)
comments3  \/\/[^\n]*

space [' '] 
digit [0-9]
digits {digit}+
letter [a-zA-Z]
E [E][+-]?{digit}+

id {letter}({letter}|{digit})*
num {digit}+("."{digit}+)?({E})?

character [\']({letter}|[' '])[\']
 
%%
{comments3}     {yyrowno+=yyleng;}
{comments2}     {yyrowno+=yyleng;}
{comments1}     {yyrowno+=yyleng;}


"and"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return AND; }
"array"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return ARRAY; }
"begin"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return BEGIN_L; }
"boolean"		{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return BOOLEAN; }
"case"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return CASE; }
"char"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return CHAR; }
"const"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return CONST; }
"div"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return DIV; }
"do"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return DO; }
"downto"		{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return DOWNTO; }
"else"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return ELSE; }
"end"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return END; }
"for"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return FOR; }
"function"		{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return FUNCTION; }
"if"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return IF; }
"integer"		{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return INTEGER; }
"mod"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return MOD; }
"not"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return NOT; }
"of"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return OF; }
"or"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return OR; }
"procedure"		{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return PROCEDURE; }
"program"		{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return PROGRAM; }
"real"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return REAL; }
"record"		{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return RECORD; }
"repeat"		{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return REPEAT; }
"then"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return THEN; }
"type"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return TYPE; }
"until"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return UNTIL; }
"var"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return VAR; }
"while"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return WHILE; }

{space}         { yyrowno += 1; }
{character}     { yylval.m_char=yytext[1]; yyrowno+=yyleng;  return LETTER; }
{id}            { yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return IDENTIFIER; }
{digits}        { yylval.m_int=atoi(yytext); yyrowno+=yyleng;  return DIGITS; }
{num}           { yylval.m_float=atof(yytext); yyrowno+=yyleng; printf("num: %f\n", atof(yytext));  return NUMBER; }
".."			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return SUBBOUNDARY; }
":="            { yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return ASSIGNOP; }


"<="			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return LE_OP; }
">="			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return GE_OP; }
"<>"			{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return NE_OP; }
"="				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '='; }
"<"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '<'; }
">"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '>'; }

","				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return ','; }
":"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return ':'; }
";"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return ';'; }
"."				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '.'; }
"("				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '('; }
")"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return ')'; }
"["				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '['; }
"]"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return ']'; }
"{"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '{'; }
"}"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '}'; }

"*"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '*'; }
"/"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '/'; }
"-"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '-'; }
"+"				{ yylval.m_str=new std::string(yytext); yyrowno+=yyleng;  return '+'; }



[\n]            { yyrowno = 1; }
[\t]		    { yyrowno += 4; }
.				{ printf("Error:lexical error : %s happens on Row : %d, Line : %d - %d\n",yytext,yylineno,yyrowno-yyleng+1,yyrowno); }
%%
int yywrap(){
    return 1;
}