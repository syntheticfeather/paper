#ifndef NODETYPE_H
#define NODETYPE_H

typedef enum
{
    // 语法规则名称
    // 有注释的才是真正使用了的
    CompUnit,
    Decl,
    ConstDecl,        // 常量声明
    ConstDefs,        // 多常量定义
    ConstDef,         // 常量定义
    ConstArrayDef,    // 常量数组定义
    ConstArrayAccess, // 常量数组a[0]
    VarDecls,         // 多变量声明
    ArrayDecl,        // 数组声明
    ArrayDef,         // 数组定义
    VarDecl,          // 变量声明
    VarDef,           // 变量定义
    ConstExps,
    ConstInitVal,
    ConstInitVals,
    FuncDef,
    FuncParams,
    FuncParam,
    Block,
    EmptyBlock, // 空块
    BlockItems,
    BlockItem,
    Stmt,
    AssignStmt,   // 赋值语句
    EmptyStmt,    // 空语句
    WhileStmt,    // 循环语句
    IfStmt,       // if语句
    ReturnStmt,   // 返回语句
    BreakStmt,    // 跳出语句
    ContinueStmt, // 继续语句
    InitVal,
    ArrayInit, // 数组值初始化值
    InitVals,
    LVal,
    ArrayAccess,     // 数组索引类型a[i]
    ArraySubscripts, // 存粹的一个下表[i]
    PrimaryExp,
    UnaryExp,
    FunctionCall, // 函数调用
    UnaryOp,      // 一元运算
    CallParams,
    MulExp,
    BinaryOp, // 二元运算
    AddExp,
    RelExp,
    EqExp,
    LAndExp,
    LOrExp,
    ConstExp,
    NodeFloat,     // 单独存浮点
    NodeInt,       // 单独存整数
    NodeVoid,      // 单独存void
    NodeID,        // 单独存标识符
    NodeTypeInt,   // 存类型
    NodeTypeFloat, // 存类型
    NodeTypeVoid,  // 存类型
} NodeType;

const char *nodeTypeToString(NodeType type);

#endif // NODETYPE_H
