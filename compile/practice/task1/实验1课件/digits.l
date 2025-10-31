%{
#include <stdio.h>
#include <string.h>
%}

xyzfoo ([0-9])+(.[0-9]{1,3})?$

%%
{xyzfoo} {printf("111\n");}
%%
//这里输出多一个回车，还没搞清楚
void main()
{
	yylex();  //开始解析语句,内置函数
}
int yywrap()
{
	return 1;
}