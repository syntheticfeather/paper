%{
#include<stdio.h>
#include<token.h>
%}

INT     [0-9]+
FLOAT   [0-9]*\.[0-9]+|[0-9]+\.
LETTER  [a-zA-Z]
ID      [a-zA-Z_][a-zA-Z0-9_]*
DIGIT16 0[xX][0-9a-fA-F]+

%%
"int"     { printf("<%d, %s>\n", Y_INT, "KEYWORD"); return Y_INT; }
"void"    { printf("<%d, %s>\n", Y_VOID, "KEYWORD"); }
"const"   { printf("<%d, %s>\n", Y_CONST, "KEYWORD"); }
"if"      { printf("<%d, %s>\n", Y_IF, "KEYWORD"); }
"else"    { printf("<%d, %s>\n", Y_ELSE, "KEYWORD"); }
"while"   { printf("<%d, %s>\n", Y_WHILE, "KEYWORD"); }
"break"   { printf("<%d, %s>\n", Y_BREAK, "KEYWORD"); }
"continue" { printf("<%d, %s>\n", Y_CONTINUE, "KEYWORD"); }
"return"  { printf("<%d, %s>\n", Y_RETURN, "KEYWORD"); }

"+"       { printf("<%d, %s>\n", Y_ADD, "OPERATOR"); }
"-"       { printf("<%d, %s>\n", Y_SUB, "OPERATOR"); }
"*"       { printf("<%d, %s>\n", Y_MUL, "OPERATOR"); }
"/"       { printf("<%d, %s>\n", Y_DIV, "OPERATOR"); }
"%"       { printf("<%d, %s>\n", Y_MODULO, "OPERATOR"); }
"<"       { printf("<%d, %s>\n", Y_LESS, "OPERATOR"); }
"<="      { printf("<%d, %s>\n", Y_LESSEQ, "OPERATOR"); }
">"       { printf("<%d, %s>\n", Y_GREAT, "OPERATOR"); }
">="      { printf("<%d, %s>\n", Y_GREATEQ, "OPERATOR"); }
"!="      { printf("<%d, %s>\n", Y_NOTEQ, "OPERATOR"); }
"=="      { printf("<%d, %s>\n", Y_EQ, "OPERATOR"); }
"!"       { printf("<%d, %s>\n", Y_NOT, "OPERATOR"); }
"&&"      { printf("<%d, %s>\n", Y_AND, "OPERATOR"); }
"||"      { printf("<%d, %s>\n", Y_OR, "OPERATOR"); }
"="       { printf("<%d, %s>\n", Y_ASSIGN, "OPERATOR"); }

"("       { printf("<%d, %s>\n", Y_LPAR, "SYMBOL"); }
")"       { printf("<%d, %s>\n", Y_RPAR, "SYMBOL"); }
"{"       { printf("<%d, %s>\n", Y_LBRACKET, "SYMBOL"); }
"}"       { printf("<%d, %s>\n", Y_RBRACKET, "SYMBOL"); }
"["       { printf("<%d, %s>\n", Y_LSQUARE, "SYMBOL"); }
"]"       { printf("<%d, %s>\n", Y_RSQUARE, "SYMBOL"); }
","       { printf("<%d, %s>\n", Y_COMMA, "SYMBOL"); }
";"       { printf("<%d, %s>\n", Y_SEMICOLON, "SYMBOL"); }
\.       { printf("<%d, %s>\n", Y_FLOAT, "SYMBOL"); }

[ \t\n]+  {}
"//"(.*)  { yywrap(); }


{FLOAT} {printf("<%d, %s>\n", num_FLOAT, yytext);}
{DIGIT16}   { printf("<%d, %s>\n", num_INT, yytext); }
{INT} { printf("<%d, %s>\n", num_INT, yytext); }
{ID} { printf("<%d, %s>\n", Y_ID, yytext); }

%%

int yywrap() {
    return 1;
}