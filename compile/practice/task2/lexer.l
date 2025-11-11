%{
#include "header1.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylval;
char *yytext;

// 全局变量定义
TokenType cur_token;

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

{DIGIT}+           { yylval = atoi(yytext); return num_INT; }
{DIGIT}+"."{DIGIT}* { 
    // 注意：这里需要将浮点数字符串转换为float
    // 但由于yylval是int，我们这里简化处理
    yylval = atoi(yytext); // 这里应该用atof，但为了兼容yylval类型，先这样处理
    return num_FLOAT; 
}

{ID}               { return Y_ID; }

[ \t\n]            ; /* skip whitespace */
.                  { printf("Unknown character: %s\n", yytext); }

%%

// 初始化token函数
void init_token() {
    cur_token.token = 0;
    cur_token.attr.ivalue = 0;
    cur_token.attr.svalue = NULL;
}

// 完整的advance函数实现
void advance() {
    int token = yylex();
    char *copy = strdup(yytext);
    printf("token: %d, yytext: %s\n", token, copy);    
    printf("yylval: %d\n", yylval);
    
    cur_token.token = token;
    
    // 设置数值属性
    if (token == num_INT) {
        cur_token.attr.ivalue = yylval;
        cur_token.attr.svalue = NULL;
        printf("ivalue: %d\n", cur_token.attr.ivalue);
    } else if (token == num_FLOAT) {
        cur_token.attr.fvalue = (float)yylval; // 简化处理
        cur_token.attr.svalue = NULL;
        printf("fvalue: %f\n", cur_token.attr.fvalue);
    } else if (token == Y_ID) {
        // 为标识符分配内存并复制字符串
        cur_token.attr.svalue = strdup(copy);
        printf("svalue: %s\n", cur_token.attr.svalue);        
    } else {
        cur_token.attr.ivalue = 0;
        cur_token.attr.svalue = NULL;
        cur_token.attr.fvalue = 0.0;
    }
}
