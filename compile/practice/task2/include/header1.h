// 单词类别
#include "token.h"

typedef struct _TokenType
{
    enum yytokentype token; // 单词类别
    union
    {
        int ivalue;   // 整数数值
        float fvalue; // 浮点数数值
        char *svalue; // 字符串数值
    } attr;           // 单词属性
} TokenType;

// 写在lexer.l中
extern TokenType cur_token; // 全局变量，表示当前的单词
void advance();             // 读取下一个单词，将其保存于 cur_token 中，同时返回该单词
void init_token();          // 初始化token

// 下面两个函数用于可能的回溯处理，即如果有多个分支需要尝试，在尝试语法分析前，可调用get_cur_tok_index获取当前单词的位置，
// 之后在分析时可能会调用若干次advance函数，如果分析失败，则可通过set_cur_tok_index函数重置当前单词的位置。
// int get_cur_tok_index();         // 所有单词已经读入单词数组中，该函数获取当前单词在数组中的下标
// void set_cur_tok_index(int ind); // 将 cur_token 设置为下标指定的token值