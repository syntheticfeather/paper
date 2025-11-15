#include "include/node_type.h"
#include "include/ast.h"
#include <stdlib.h>
#include <stdio.h>
#include "include/token.h"

// past树节点的构造函数
past newID(char *value)
{
    past p = (past)malloc(sizeof(ast));
    if (!p)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    p->ivalue = 0;
    p->fvalue = 0.0;
    p->svalue = value;
    p->nodeType = NodeID;
    p->left = NULL;
    p->right = NULL;
    p->next = NULL;

    return p;
}

past newInt(int value)
{
    past p = (past)malloc(sizeof(ast));
    if (!p)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    p->ivalue = value;
    p->fvalue = 0.0;
    p->svalue = NULL;
    p->nodeType = NodeInt;
    p->left = NULL;
    p->right = NULL;
    p->next = NULL;
    return p;
}

past newAstNode(NodeType type)
{
    past p = (past)malloc(sizeof(ast));
    if (!p)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    p->ivalue = 0;
    p->fvalue = 0.0;
    p->svalue = NULL;
    p->nodeType = type;
    p->left = NULL;
    p->right = NULL;
    p->next = NULL;
    return p;
}

// 辅助函数：打印 token 名称
const char *getTokenName(int token)
{
    switch (token)
    {
    case Y_INT:
        return "int";
    case Y_FLOAT:
        return "float";
    case Y_VOID:
        return "void";
    case Y_ADD:
        return "+";
    case Y_SUB:
        return "-";
    case Y_MUL:
        return "*";
    case Y_DIV:
        return "/";
    case Y_MODULO:
        return "%";
    case Y_LESS:
        return "<";
    case Y_GREAT:
        return ">";
    case Y_LESSEQ:
        return "<=";
    case Y_GREATEQ:
        return ">=";
    case Y_EQ:
        return "==";
    case Y_NOTEQ:
        return "!=";
    case Y_AND:
        return "&&";
    case Y_OR:
        return "||";
    case Y_NOT:
        return "!";
    default:
        return "unknown";
    }
}

// 更完善的 AST 打印函数（适配当前语法分析器）
void printAst(past node, int indent)
{
    if (!node)
        return;

    // 打印缩进
    for (int i = 0; i < indent; i++)
    {
        printf("  ");
    }

    // 打印节点类型
    printf("%s", nodeTypeToString(node->nodeType));

    // 根据节点类型打印额外信息
    switch (node->nodeType)
    {
    case NodeInt:
        printf(" (value=%d)", node->ivalue);
        break;
    case NodeFloat:
        printf(" (value=%f)", node->fvalue);
        break;
    case NodeID:
        if (node->svalue)
            printf(" (name=\"%s\")", node->svalue);
        break;
    case NodeTypeInt:
        printf(" (type=int)");
        break;
    case NodeTypeFloat:
        printf(" (type=float)");
        break;
    case NodeTypeVoid:
        printf(" (type=void)");
        break;
    case BinaryOp:
    case UnaryOp:
    {
        const char *op_str = getTokenName(node->ivalue);
        printf(" (op=%s)", op_str);
        break;
    }
    case VarDecl:
    case ConstDecl:
        // 这些节点的 left 是类型，right 是变量定义
        break;
    case FuncDef:
        if (node->svalue)
            printf(" (name=\"%s\")", node->svalue);
        break;
    case FuncParam:
        if (node->svalue)
            printf(" (name=\"%s\")", node->svalue);
        break;
    case ArrayDecl:
    case ArrayDef:
    case ConstArrayDef:
        printf(" (array)");
        break;
    case ArrayAccess:
        printf(" (array access)");
        break;
    case ArraySubscripts:
        printf(" (array subscripts)");
        break;
    case IfStmt:
        printf(" (if-then-else)");
        break;
    case WhileStmt:
        printf(" (while-loop)");
        break;
    case ReturnStmt:
        printf(" (return)");
        break;
    case BreakStmt:
        printf(" (break)");
        break;
    case ContinueStmt:
        printf(" (continue)");
        break;
    case AssignStmt:
        printf(" (assignment)");
        break;
    case EmptyStmt:
        printf(" (empty statement)");
        break;
    case EmptyBlock:
        printf(" (empty block)");
        break;
    case FunctionCall:
        printf(" (function call)");
        break;
    case ArrayInit:
        printf(" (array initialization)");
        break;
    case ConstDef:
        printf(" (constant definition)");
        break;
    case ConstArrayAccess:
        printf(" (const array access)");
        break;
    case VarDef:
        printf(" (variable definition)");
        break;
    case VarDecls:
        printf(" (variable declarations)");
        break;
    case ConstDefs:
        printf(" (constant definitions)");
        break;
    case FuncParams:
        printf(" (function parameters)");
        break;
    default:
        // 其他节点不额外打印
        break;
    }

    printf("\n");

    // ======================
    // 递归打印子结构（适配当前语法分析器的AST结构）
    // ======================

    // 对于不同节点类型，按其逻辑结构递归
    switch (node->nodeType)
    {
    case FuncDef:
    {
        // FuncDef: left = 返回类型, svalue = 函数名, right = 参数列表, next = 函数体
        if (node->left)
        {
            printf("%*s[Return Type]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->svalue)
        {
            printf("%*s[Function Name]: %s\n", (indent + 1) * 2, "", node->svalue);
        }
        if (node->right)
        {
            printf("%*s[Parameters]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        if (node->next)
        {
            printf("%*s[Body]:\n", (indent + 1) * 2, "");
            printAst(node->next, indent + 1);
        }
        break;
    }

    case VarDecl:
    case ConstDecl:
    {
        // VarDecl/ConstDecl: left = 类型, right = 变量定义
        if (node->left)
        {
            printf("%*s[Type]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[Definition]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        break;
    }

    case FuncParam:
    {
        // FuncParam: left = 类型, svalue = 参数名, right = 数组下标
        if (node->left)
        {
            printf("%*s[Type]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->svalue)
        {
            printf("%*s[Parameter Name]: %s\n", (indent + 1) * 2, "", node->svalue);
        }
        if (node->right)
        {
            printf("%*s[Array Subscripts]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        break;
    }

    case IfStmt:
    {
        // IfStmt: left = 条件, right = then分支, next = else分支
        if (node->left)
        {
            printf("%*s[Condition]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[Then Branch]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        if (node->next)
        {
            printf("%*s[Else Branch]:\n", (indent + 1) * 2, "");
            printAst(node->next, indent + 1);
        }
        break;
    }

    case WhileStmt:
    {
        // WhileStmt: left = 条件, right = 循环体
        if (node->left)
        {
            printf("%*s[Condition]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[Loop Body]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        break;
    }

    case ReturnStmt:
    {
        // ReturnStmt: left = 返回值表达式
        if (node->left)
        {
            printf("%*s[Return Value]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        break;
    }

    case AssignStmt:
    {
        // AssignStmt: left = 左值, right = 右值表达式
        if (node->left)
        {
            printf("%*s[LHS]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[RHS]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        break;
    }

    case FunctionCall:
    {
        // FunctionCall: left = 函数名, right = 参数列表
        if (node->left)
        {
            printf("%*s[Function]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[Arguments]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        break;
    }

    case ArrayAccess:
    case ConstArrayAccess:
    {
        // ArrayAccess: left = 数组名, right = 下标表达式
        if (node->left)
        {
            printf("%*s[Array]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[Subscript]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        break;
    }

    case ArraySubscripts:
    {
        // ArraySubscripts: left = 当前下标, right = 后续下标
        if (node->left)
        {
            printf("%*s[Current Subscript]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[Next Subscript]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        break;
    }

    case BinaryOp:
    {
        // BinaryOp: left = 左操作数, right = 右操作数, ivalue = 操作符
        if (node->left)
        {
            printf("%*s[Left Operand]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[Right Operand]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        break;
    }

    case UnaryOp:
    {
        // UnaryOp: left = 操作数, ivalue = 操作符
        if (node->left)
        {
            printf("%*s[Operand]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        break;
    }

    case ArrayInit:
    {
        // ArrayInit: left = 第一个元素, right = 后续元素
        if (node->left)
        {
            printf("%*s[First Element]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[Remaining Elements]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        break;
    }

    case VarDecls:
    case ConstDefs:
    case FuncParams:
    {
        // 链表结构: left = 当前元素, right = 后续元素
        if (node->left)
        {
            printf("%*s[Current]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[Next]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        break;
    }

    default:
    {
        // 通用回退：left -> right -> next
        if (node->left)
        {
            printf("%*s[Left]:\n", (indent + 1) * 2, "");
            printAst(node->left, indent + 1);
        }
        if (node->right)
        {
            printf("%*s[Right]:\n", (indent + 1) * 2, "");
            printAst(node->right, indent + 1);
        }
        if (node->next)
        {
            printf("%*s[Next]:\n", (indent + 1) * 2, "");
            printAst(node->next, indent + 1);
        }
        break;
    }
    }
}