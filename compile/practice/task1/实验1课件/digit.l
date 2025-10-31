%{
#include <stdio.h>
#include <string.h>
int wordCount = 0;
int whiteCount = 0;
int numCount = 0;
%}
letter [a-zA-Z]
letters {letter}+
numbers ([0-9])+
xyzfoo ^[0-9]+(.[0-9]{1,3})?$ 
whitespaces ([\t\n ])+

%%
{letters} {wordCount++; printf("11111\n");return 111;}   //当匹配letters的正则表达式时执行的动作，一般动作都是结合yacc并返回给语法分析器一个词法单元和属性值，此处把lex作为一个独立的工具使用
{numbers} {numCount++;printf("22222\n");return 222;}
{whitespaces} {whiteCount++;printf("3333\n");return 333;}
{xyzfoo} {printf("ddd\n");}
%%

void main()
{
	yylex();  //开始解析语句,内置函数
	printf("单词数：%d\n",wordCount);
	printf("空白数：%d\n",whiteCount);
	printf("数字数：%d\n",numCount);
}
int yywrap()
{
	return 1;
}