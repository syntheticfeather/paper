#ifndef AST_H
#define AST_H

#include "node_type.h"
#include <stdbool.h>

typedef struct _ast ast;
typedef struct _ast *past;

struct _ast
{
    int ivalue;
    float fvalue;
    char *svalue;
    node_type nodeType;
    past left;
    past right;
    past if_cond;
    past next;
};

past new_ast_node(node_type nodeType);
void showToken(int Token);
void showAst(past node, int nest, bool use_blank);

#endif // AST_H