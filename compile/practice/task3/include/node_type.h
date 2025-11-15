//////
// 声明类型（Declaration Kinds）
#ifndef COMPILER_LAB_NODE_TYPE_H
#define COMPILER_LAB_NODE_TYPE_H

enum _node_type
{

	// 一种声明，其具体类型未通过此接口暴露
	//

	// C 或 C++ 中的 struct（结构体）
	STRUCT_DECL = 2,

	// C 或 C++ 中的 union（联合体）
	UNION_DECL = 3,

	// 枚举类型（enum）
	ENUM_DECL = 5,

	// C 中的字段，或 C++ 中结构体、联合体、类中的非静态数据成员
	FIELD_DECL = 6,

	// 枚举常量（enumerator constant）
	ENUM_CONSTANT_DECL = 7,

	// 函数声明
	FUNCTION_DECL = 8,

	// 变量声明
	VAR_DECL = 9,

	// 函数或方法的参数
	PARM_DECL = 10,

	// typedef 声明
	TYPEDEF_DECL = 20,

	// 类型别名声明（C++11 的 using alias）
	TYPE_ALIAS_DECL = 36,

	// 对结构体、联合体或类中某个成员的引用，出现在非表达式上下文中，
	// 例如：指定初始化器（designated initializer）中的成员引用
	MEMBER_REF = 47,

	// 对带标签语句（labeled statement）的引用
	LABEL_REF = 48,

	// 对一组重载函数或函数模板的引用，尚未解析为具体函数或模板
	OVERLOADED_DECL_REF = 49,

	// 对变量的引用，出现在非表达式上下文中，
	// 例如：C++ lambda 表达式的捕获列表
	VARIABLE_REF = 50,

	//////
	// 无效/错误类型

	INVALID_FILE = 70,	  // 无效文件
	NO_DECL_FOUND = 71,	  // 未找到声明
	NOT_IMPLEMENTED = 72, // 尚未实现
	INVALID_CODE = 73,	  // 无效代码

	//////
	// 表达式类型（Expression Kinds）

	// 一种表达式，其具体类型未通过此接口暴露
	//
	// 未暴露的表达式与其他表达式一样，可以获取其位置信息、拼写、子节点等，
	// 但不会报告其具体的表达式类型
	UNEXPOSED_EXPR = 100,

	// 引用某个值声明（如函数、变量或枚举常量）的表达式
	DECL_REF_EXPR = 101,

	// 引用结构体、联合体、类或 Objective-C 类中成员的表达式
	MEMBER_REF_EXPR = 102,

	// 调用函数的表达式
	CALL_EXPR = 103,

	// 表示块字面量（block literal）的表达式
	BLOCK_EXPR = 105,

	// 整数字面量
	INTEGER_LITERAL = 106,

	// 浮点数字面量
	FLOATING_LITERAL = 107,

	// 虚数（imaginary）字面量
	IMAGINARY_LITERAL = 108,

	// 字符串字面量
	STRING_LITERAL = 109,

	// 字符字面量
	CHARACTER_LITERAL = 110,

	// 带括号的表达式，例如 "(1)"
	//
	// 此 AST 节点仅在请求完整位置信息时生成
	PAREN_EXPR = 111,

	// 表示除 sizeof 和 alignof 外的一元表达式
	UNARY_OPERATOR = 112,

	// [C99 6.5.2.1] 数组下标表达式（如 a[i]）
	ARRAY_SUBSCRIPT_EXPR = 113,

	// 内置的二元运算表达式，如 "x + y" 或 "x <= y"
	BINARY_OPERATOR = 114,

	// 复合赋值运算符，如 "+="
	COMPOUND_ASSIGNMENT_OPERATOR = 115,

	// 三元条件运算符（?:）
	CONDITIONAL_OPERATOR = 116,

	// C 中的显式类型转换（C99 6.5.4），或 C++ 中的 C 风格类型转换（C++ [expr.cast]），
	// 语法形式为 (Type)expr
	//
	// 例如：(int)f
	CSTYLE_CAST_EXPR = 117,

	// [C99 6.5.2.5] 复合字面量表达式（compound literal）
	COMPOUND_LITERAL_EXPR = 118,

	// 描述 C 或 C++ 中的初始化列表（initializer list）
	INIT_LIST_EXPR = 119,

	// GNU 扩展：标签地址表达式，表示 &&label
	ADDR_LABEL_EXPR = 120,

	// 一种语句，其具体类型未通过此接口暴露
	//
	// 未暴露的语句与其他语句一样，可以获取其位置信息、拼写、子节点等，
	// 但不会报告其具体的语句类型
	UNEXPOSED_STMT = 200,

	// 函数中的带标签语句（如 label: statement）
	LABEL_STMT = 201,

	// 复合语句（即代码块，由 { } 包围）
	COMPOUND_STMT = 202,

	// switch 中的 case 语句
	CASE_STMT = 203,

	// switch 中的 default 语句
	DEFAULT_STMT = 204,

	// if 语句
	IF_STMT = 205,

	// switch 语句
	SWITCH_STMT = 206,

	// while 循环语句
	WHILE_STMT = 207,

	// do-while 循环语句
	DO_STMT = 208,

	// for 循环语句
	FOR_STMT = 209,

	// goto 语句
	GOTO_STMT = 210,

	// 间接 goto 语句（GNU 扩展）
	INDIRECT_GOTO_STMT = 211,

	// continue 语句
	CONTINUE_STMT = 212,

	// break 语句
	BREAK_STMT = 213,

	// return 语句
	RETURN_STMT = 214,

	// 空语句（null statement，即单独一个分号 ;）
	NULL_STMT = 230,

	// 用于混合声明与语句/表达式的适配器类（如 C++ 中允许在语句中声明变量）
	DECL_STMT = 231,

	//////
	// 其他类型

	// 表示整个翻译单元（translation unit）的游标（cursor）
	//
	// 翻译单元游标主要用于作为遍历整个源文件内容的根节点
	TRANSLATION_UNIT = 300,
};

typedef enum _node_type node_type;

#endif