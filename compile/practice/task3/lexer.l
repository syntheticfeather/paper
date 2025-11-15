%{
#include "sysy.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *yytext;

YYSTYPE yylval;

extern int yyparse(void);
// 全局变量定义

%}

%option noyywrap

DIGIT    [0-9]
ID       [a-zA-Z_][a-zA-Z0-9_]*

%%

"+"                { return Y_ADD; }
"-"                { return Y_SUB; }
"*"                { return Y_MUL; }
"/"                { return Y_DIV; }
"%"                { return Y_MODULO; }
"="                { return Y_ASSIGN; }
"=="               { return Y_EQ; }
"!="               { return Y_NOTEQ; }
"<"                { return Y_LESS; }
">"                { return Y_GREAT; }
"<="               { return Y_LESSEQ; }
">="               { return Y_GREATEQ; }
"!"                { return Y_NOT; }
"&&"               { return Y_AND; }
"||"               { return Y_OR; }

"("                { return Y_LPAR; }
")"                { return Y_RPAR; }
"{"                { return Y_LBRACKET; }
"}"                { return Y_RBRACKET; }
"["                { return Y_LSQUARE; }
"]"                { return Y_RSQUARE; }
";"                { return Y_SEMICOLON; }
","                { return Y_COMMA; }

"if"               { return Y_IF; }
"else"             { return Y_ELSE; }
"while"            { return Y_WHILE; }
"return"           { return Y_RETURN; }
"break"            { return Y_BREAK; }
"continue"         { return Y_CONTINUE; }
"int"              { return Y_INT; }
"void"             { return Y_VOID; }
"float"            { return Y_FLOAT; }
"const"            { return Y_CONST; }

{DIGIT}+           { yylval.ival = atoi(yytext); return num_INT; }
{DIGIT}+"."{DIGIT}* { 
    // 注意：这里需要将浮点数字符串转换为double
    yylval.fval = atof(yytext); // 使用atof函数将字符串转换为double类型
    return num_FLOAT; 
}

{ID}               { yylval.sval = strdup(yytext); return Y_ID; }

[ \t\n]            ; /* skip whitespace */
.                  { printf("Unknown character: %s\n", yytext); }

%%


int main(int argc, char **argv) {
    int result = yyparse();
    if (result == 0) {
        // printf("Parsing succeeded.\n");
    } else {
        // printf("Parsing failed.\n");
    }
    return result;
}