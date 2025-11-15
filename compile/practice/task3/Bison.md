# 关于Bison直接生成语法分析器

```bash
cd compile/practice/task3

flex lexer.l

bison -d sysy.y

gcc sysy.tab.c lex.yy.c ast.c -o a
```

## 简单示例

```c
a = 5;
b = a + 3 * (2 - 1);
b;
```



```c
// .y文件
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 简单变量表：最多100个变量
#define MAX_VARS 100
char var_names[MAX_VARS][100];
int  var_values[MAX_VARS];
int  var_count = 0;

// 查找或添加变量
int get_var_index(const char* name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(var_names[i], name) == 0)
            return i;
    }
    // 未找到，新建变量（初始值为0）
    if (var_count < MAX_VARS) {
        strcpy(var_names[var_count], name);
        var_values[var_count] = 0;
        return var_count++;
    }
    fprintf(stderr, "Too many variables!\n");
    exit(1);
}

void yyerror(const char *s);
int yylex(void);  // 由 flex 提供
%}



/* Bison 不会警告未使用规则 */
%define parse.error verbose

/* 支持返回整数值和字符串（用于变量名） */
%union {
    int ival;
    char* sval;
}
/* Bison会生成一个 YYSTYPE 类型，用于存储 token 的值 */ 
/* 而 yylval就是这个类型的一个全局变量 */

/* 声明 token 类型 */
/* 定义后就可以在后面用$1 $2获取值了*/
%token <ival> T_NUMBER
%token <sval> T_ID
%token T_ASSIGN T_SEMICOLON

/* 运算符优先级和结合性 */
%left T_PLUS T_MINUS
%left T_MUL T_DIV
%nonassoc T_UMINUS  /* 一元负号 */

/* 表达式返回整数 */
%type <ival> expr primary factor term

%%
/* 语法规则 */

program:
    %empty
    | program statement
    ;

statement:
    T_ID T_ASSIGN expr T_SEMICOLON { 
        int idx = get_var_index($1);
        var_values[idx] = $3;
        printf("=> %d\n", $3);
        free($1);  // 如果 strdup 了，需要释放
    }
    | expr T_SEMICOLON {
        printf("=> %d\n", $1);
    }
    ;

expr:
    expr T_PLUS term { $$ = $1 + $3; }
    | expr T_MINUS term { $$ = $1 - $3; }
    | term { $$ = $1; }
    ;

term:
    term T_MUL factor { $$ = $1 * $3; }
    | term T_DIV factor { 
        if ($3 == 0) {
            fprintf(stderr, "Error: division by zero\n");
            exit(1);
        }
        $$ = $1 / $3;
    }
    | factor { $$ = $1; }
    ;

factor:
    T_NUMBER { $$ = $1; }
    | T_ID {
        int idx = get_var_index($1);
        $$ = var_values[idx];
        free($1);
    }
    | T_MINUS factor %prec T_UMINUS { $$ = -$2; }
    | T_LPAREN expr T_RPAREN { $$ = $2; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}

int main() {
    printf("Simple Calculator with Variables (type expressions ending with ';')\n");
    return yyparse();
}
```


```c
// .l文件
%{
#include "calc.tab.h"  // 由 bison 生成
#include <string.h>
%}

%option noyywrap

%%
[ \t]+              ;  /* 忽略空白 */
\n                  ;  /* 允许换行 */

";"                 { return T_SEMICOLON; }
"="                 { return T_ASSIGN; }
"+"                 { return T_PLUS; }
"-"                 { return T_MINUS; }
"*"                 { return T_MUL; }
"/"                 { return T_DIV; }
"("                 { return T_LPAREN; }
")"                 { return T_RPAREN; }

[0-9]+              { yylval.ival = atoi(yytext); return T_NUMBER; }

[a-zA-Z_][a-zA-Z0-9_]* {
                        yylval.sval = strdup(yytext);  // 注意：需在 .y 中 free
                        return T_ID;
                    }

.                   { fprintf(stderr, "Unknown character: %c\n", *yytext); }
```