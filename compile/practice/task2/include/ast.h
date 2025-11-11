#include "node_type.h"

typedef struct _ast ast;
typedef struct _ast *past;

struct _ast
{
    int ivalue;
    float fvalue;
    char *svalue;
    NodeType nodeType;
    // node_type nodeType;
    past left;
    past right;
    past next;
};

past newAstNode(NodeType type);
past newID(char *value);
past newInt(int value);
void printAst(past node, int indent);