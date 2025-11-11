/*
 ============================================================================
 Name        : rdparser.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : 实现icoding的语法分析器
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header1.h"
#include "ast.h"
#include "token.h"

extern int yylval;
extern char *yytext;

// 语法分析函数声明
past rd_l_val();
past rd_primary_exp();
past rd_unary_exp();
past rd_mul_exp();
past rd_add_exp();
past rd_exp();
past rd_call_paras();
past rd_relexp();
past rd_eq_exp();
past rd_land_exp();
past rd_lor_exp();
past rd_stmt();
past rd_block();
past rd_block_items();
past rd_block_item();
past rd_decl();
past rd_array_subscripts();
past rd_type();
past rd_init_vals();
past rd_const_init_vals();

// match函数声明
void match(enum yytokentype t);

/*
61 LVal: Y_ID
62     | Y_ID ArraySubscripts
*/
past rd_l_val()
{
	printf("rd_l_val begin");
	// 复制当前标识符
	char *c = NULL;
	if (cur_token.attr.svalue != NULL)
	{
		c = strdup(cur_token.attr.svalue);
	}
	match(Y_ID); // 用掉 ID
	past p = newID(c);
	if (cur_token.token == Y_LSQUARE)
	{
		past pr = rd_array_subscripts();
		past p_node = newAstNode(ArrayAccess);
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
63 ArraySubscripts: Y_LSQUARE Exp Y_RSQUARE
64                | Y_LSQUARE Exp Y_RSQUARE ArraySubscripts
*/
past rd_array_subscripts()
{
	printf("rd_array_subscripts begin");
	match(Y_LSQUARE);
	past p = rd_exp();
	match(Y_RSQUARE);
	if (cur_token.token == Y_LSQUARE)
	{
		past pr = rd_array_subscripts();
		past p_node = newAstNode(ArraySubscripts);
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
65 PrimaryExp: Y_LPAR Exp Y_RPAR
66           | LVal
67           | num_INT
68           | num_FLOAT
*/
past rd_primary_exp()
{
	printf("rd_primary_exp() Begin");
	past p;
	switch (cur_token.token)
	{
	case Y_LPAR:
		match(Y_LPAR);
		p = rd_exp();
		match(Y_RPAR);
		return p;
	case Y_ID:
		return rd_l_val(); // rd_l_val() 已 match(Y_ID)，无需再 match
	case num_INT:		   // 整型常量
		p = newInt(yylval);
		match(num_INT);
		return p;
	case num_FLOAT: // 浮点型常量
		p = newAstNode(NodeFloat);
		p->fvalue = yylval;
		match(num_FLOAT);
		return p;
	default:
		printf("error: expect primary expression, but get %s\n", yytext);
		exit(1);
	}
}

/*
69 UnaryExp: PrimaryExp
70         | Y_ID Y_LPAR Y_RPAR
71         | Y_ID Y_LPAR CallParams Y_RPAR
72         | Y_ADD UnaryExp
73         | Y_SUB UnaryExp
74         | Y_NOT UnaryExp
*/
past rd_unary_exp()
{
	printf("rd_unary_exp() Begin");
	past p;
	switch (cur_token.token)
	{
	case Y_ID:
	{
		char *c = NULL;
		if (cur_token.attr.svalue != NULL)
		{
			c = strdup(cur_token.attr.svalue);
		}
		match(Y_ID);
		if (cur_token.token == Y_LPAR)
		{
			match(Y_LPAR);
			if (cur_token.token == Y_RPAR)
			{
				p = newAstNode(FunctionCall);
				p->left = newID(c);
				match(Y_RPAR);
				return p; // 无参函数调用
			}
			else
			{
				past params = rd_call_paras(); // 函数的参数
				p = newAstNode(FunctionCall);
				p->left = newID(c);
				p->right = params;
				match(Y_RPAR);
				return p; // 有参函数调用
			}
		}
		else
		{
			p = newID(c);
			return p; // 变量
		}
	}
	case Y_ADD:
	case Y_SUB:
	case Y_NOT:
	{
		int op = cur_token.token;
		match(op);
		past pr = rd_unary_exp();
		p = newAstNode(UnaryOp);
		p->ivalue = op;
		p->left = pr;
		return p;
	}
	default:
		p = rd_primary_exp();
		return p;
	}
}
/*
77 MulExp: UnaryExp
78       | MulExp Y_MUL UnaryExp
79       | MulExp Y_DIV UnaryExp
80       | MulExp Y_MODULO UnaryExp
*/
past rd_mul_exp()
{
	printf("rd_mul_exp() Begin");
	past p = rd_unary_exp();
	while (cur_token.token == Y_MUL || cur_token.token == Y_DIV || cur_token.token == Y_MODULO)
	{
		int op = cur_token.token;
		match(op);
		past pr = rd_unary_exp();
		past p_node = newAstNode(BinaryOp);
		p_node->ivalue = op;
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
81 AddExp: MulExp
82       | AddExp Y_ADD MulExp
83       | AddExp Y_SUB MulExp
*/
past rd_add_exp()
{
	printf("rd_add_exp() Begin");
	past p = rd_mul_exp();
	while (cur_token.token == Y_ADD || cur_token.token == Y_SUB)
	{
		int op = cur_token.token;
		match(op);
		past pr = rd_mul_exp();
		past p_node = newAstNode(BinaryOp);
		p_node->ivalue = op;
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
60 Exp: AddExp
*/
past rd_exp()
{
	printf("rd_exp() Begin");
	return rd_add_exp();
}

/*
75 CallParams: Exp
76           | Exp Y_COMMA CallParams
*/
past rd_call_paras()
{
	printf("rd_call_paras() Begin");
	past p = rd_exp();
	if (cur_token.token == Y_COMMA)
	{
		match(Y_COMMA);
		past pr = rd_call_paras();
		p->next = pr;
	}
	return p;
}

/*
84 RelExp: AddExp
85       | AddExp Y_LESS RelExp
86       | AddExp Y_GREAT RelExp
87       | AddExp Y_LESSEQ RelExp
88       | AddExp Y_GREATEQ RelExp
*/
past rd_relexp()
{
	printf("rd_rel_exp() Begin");
	past p = rd_add_exp();
	while (cur_token.token == Y_LESS ||
		   cur_token.token == Y_GREAT ||
		   cur_token.token == Y_LESSEQ ||
		   cur_token.token == Y_GREATEQ)
	{
		int op = cur_token.token;
		match(op);
		past pr = rd_add_exp();
		past p_node = newAstNode(BinaryOp);
		p_node->ivalue = op;
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
89 EqExp: RelExp
90      | RelExp Y_EQ EqExp
91      | RelExp Y_NOTEQ EqExp
*/
past rd_eq_exp()
{
	printf("rd_eq_exp() Begin");
	past p = rd_relexp();
	while (cur_token.token == Y_EQ ||
		   cur_token.token == Y_NOTEQ)
	{
		int op = cur_token.token;
		match(op);
		past pr = rd_relexp();
		past p_node = newAstNode(BinaryOp);
		p_node->ivalue = op;
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
92 LAndExp: EqExp
93        | EqExp Y_AND LAndExp
*/
past rd_land_exp()
{
	printf("rd_land_exp() Begin");
	past p = rd_eq_exp();
	while (cur_token.token == Y_AND)
	{
		match(Y_AND);
		past pr = rd_eq_exp();
		past p_node = newAstNode(BinaryOp);
		p_node->ivalue = Y_AND;
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
94 LOrExp: LAndExp
95       | LAndExp Y_OR LOrExp
*/
past rd_lor_exp()
{
	printf("rd_lor_exp() Begin");
	past p = rd_land_exp();
	while (cur_token.token == Y_OR)
	{
		match(Y_OR);
		past pr = rd_land_exp();
		past p_node = newAstNode(BinaryOp);
		p_node->ivalue = Y_OR;
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
49 Stmt: LVal Y_ASSIGN Exp Y_SEMICOLON
50     | Y_SEMICOLON
51     | Exp Y_SEMICOLON
52     | Block
53     | Y_WHILE Y_LPAR LOrExp Y_RPAR Stmt
54     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt
55     | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Stmt
56     | Y_BREAK Y_SEMICOLON
57     | Y_CONTINUE Y_SEMICOLON
58     | Y_RETURN Exp Y_SEMICOLON
59     | Y_RETURN Y_SEMICOLON
*/
past rd_stmt()
{
	printf("rd_stmt() Begin");
	past p;
	past cond;
	switch (cur_token.token)
	{
	case Y_ID:
	{
		past lval = rd_l_val();
		match(Y_ASSIGN);
		past expr = rd_exp();
		p = newAstNode(AssignStmt);
		p->left = lval;
		p->right = expr;
		match(Y_SEMICOLON);
		return p;
	}
	case Y_SEMICOLON:
		match(Y_SEMICOLON);
		return newAstNode(EmptyStmt);
	case Y_LBRACKET:
		return rd_block();
	case Y_WHILE:
		match(Y_WHILE);
		match(Y_LPAR);
		cond = rd_lor_exp();
		match(Y_RPAR);
		past body = rd_stmt();
		p = newAstNode(WhileStmt);
		p->left = cond;
		p->right = body;
		return p;
	case Y_IF:
		match(Y_IF);
		match(Y_LPAR);
		cond = rd_lor_exp();
		match(Y_RPAR);
		past then_branch = rd_stmt();
		past else_branch = NULL;
		if (cur_token.token == Y_ELSE)
		{
			match(Y_ELSE);
			else_branch = rd_stmt();
		}
		p = newAstNode(IfStmt);
		p->left = cond;
		p->right = then_branch;
		p->next = else_branch;
		return p;
	case Y_BREAK:
		match(Y_BREAK);
		p = newAstNode(BreakStmt);
		match(Y_SEMICOLON);
		return p;
	case Y_CONTINUE:
		match(Y_CONTINUE);
		p = newAstNode(ContinueStmt);
		match(Y_SEMICOLON);
		return p;
	case Y_RETURN:
		match(Y_RETURN);
		past ret_expr = NULL;
		if (cur_token.token != Y_SEMICOLON)
		{
			ret_expr = rd_exp();
		}
		match(Y_SEMICOLON);
		p = newAstNode(ReturnStmt);
		p->left = ret_expr;
		return p;
	default:
		p = rd_exp();
		match(Y_SEMICOLON);
		return p;
	}
}

/*
29 InitVal: Exp
30        | Y_LBRACKET Y_RBRACKET
31        | Y_LBRACKET InitVal Y_RBRACKET
32        | Y_LBRACKET InitVal InitVals Y_RBRACKET
*/
past rd_init_val()
{
	printf("rd_init_val() Begin");
	past p;
	switch (cur_token.token)
	{
	case Y_LBRACKET:
		match(Y_LBRACKET);
		p = newAstNode(ArrayInit);
		if (cur_token.token == Y_RBRACKET)
		{
			match(Y_RBRACKET);
		}
		else
		{
			p->left = rd_init_val();
			if (cur_token.token == Y_RBRACKET)
			{
				match(Y_RBRACKET);
			}
			else
			{
				p->right = rd_init_vals();
				match(Y_RBRACKET);
			}
		}
		return p;
	default:
		p = rd_exp();
		return p;
	}
}

/*
33 InitVals: Y_COMMA InitVal
34         | Y_COMMA InitVal InitVals
*/
past rd_init_vals()
{
	printf("rd_init_vals() Begin");
	match(Y_COMMA);
	past p = rd_init_val();
	if (cur_token.token == Y_COMMA)
	{
		past pr = rd_init_vals();
		past p_node = newAstNode(ArrayInit);
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
96 ConstExp: AddExp
*/
past rd_const_exp()
{
	printf("rd_const_exp() Begin");
	return rd_add_exp();
}

/*
13 ConstExps: Y_LSQUARE ConstExp Y_RSQUARE
14          | Y_LSQUARE ConstExp Y_RSQUARE ConstExps

某种意义上和ArraySubscripts是差不多的
ConstExps匹配[5][3][2],ArraySubscripts匹配[a][b][x + y]
*/
past rd_const_exps()
{
	printf("rd_const_exps() Begin");
	match(Y_LSQUARE);
	past p = rd_const_exp();
	match(Y_RSQUARE);
	if (cur_token.token == Y_LSQUARE)
	{
		past pr = rd_const_exps();
		past p_node = newAstNode(ArrayAccess);
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
25 VarDef: Y_ID
26       | Y_ID Y_ASSIGN InitVal
27       | Y_ID ConstExps
28       | Y_ID ConstExps Y_ASSIGN InitVal
*/
past rd_var_def()
{
	printf("rd_var_def() Begin");
	char *c = strdup(cur_token.attr.svalue);
	match(Y_ID);
	past p = newID(c);
	past p_node = newAstNode(VarDecl); // 变量声明
	p_node->left = p;
	if (cur_token.token == Y_ASSIGN)
	{
		past pr = rd_init_val();
		p_node->nodeType = VarDef; // 变量定义
		p_node->right = pr;
		p = p_node;
	}
	else if (cur_token.token == Y_LSQUARE)
	{
		past pr = rd_const_exps();
		past p_node1 = newAstNode(ArrayDecl); // 数组声明
		p_node1->left = p;
		p_node1->right = pr;
		p = p_node1;
		if (cur_token.token == Y_ASSIGN)
		{
			past init_val = rd_init_val();
			p_node = newAstNode(ArrayDef); // 数组定义
			p_node->left = p;
			p_node->right = init_val;
			p = p_node;
		}
	}
	return p;
}

/*
97 Type: Y_INT
98     | Y_FLOAT
99     | Y_VOID
*/
past rd_type()
{
	printf("rd_type() Begin");
	switch (cur_token.token)
	{
	case Y_INT:
		match(cur_token.token);
		return newAstNode(NodeTypeInt);
	case Y_FLOAT:
		match(cur_token.token);
		return newAstNode(NodeTypeFloat);
	case Y_VOID:
		match(cur_token.token);
		return newAstNode(NodeTypeVoid);
	}
}

/*
23 VarDecls: Y_COMMA VarDef
24         | Y_COMMA VarDef VarDecls
*/
past rd_var_decls()
{
	printf("rd_var_decls() Begin");
	match(Y_COMMA);
	past p = rd_var_def();
	if (cur_token.token == Y_COMMA)
	{
		past pr = rd_var_decls();
		past p_node = newAstNode(VarDecls);
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
21 VarDecl: Type VarDef Y_SEMICOLON
22        | Type VarDef VarDecls Y_SEMICOLON
*/
past rd_var_decl()
{
	printf("rd_var_decl() Begin");
	past p_node = newAstNode(VarDecl);
	p_node->left = rd_type(); // VarDecl的左子树为Type
	past p = rd_var_def();
	p_node->right = p; // VarDecls的右子树为VarDef
	if (cur_token.token == Y_COMMA)
	{
		past pr = rd_var_decls();
		past p_node1 = newAstNode(VarDecls);
		p_node1->left = p; // 把第一个VarDef整合进VarDecls
		p_node1->right = pr;
		p_node->right = p_node1; // 右子树为VarDecls
	}
	return p_node;
}

/*
15 ConstInitVal: ConstExp
16             | Y_LBRACKET Y_RBRACKET
17             | Y_LBRACKET ConstInitVal Y_RBRACKET
18             | Y_LBRACKET ConstInitVal ConstInitVals Y_RBRACKET
*/
past rd_const_init_val()
{
	printf("rd_const_init_val() Begin");
	past p;
	switch (cur_token.token)
	{
	case Y_LBRACKET:
		match(Y_LBRACKET);
		p = newAstNode(ArrayInit);
		if (cur_token.token == Y_RBRACKET)
		{
			match(Y_RBRACKET);
		}
		else
		{
			p->left = rd_const_init_val();
			if (cur_token.token == Y_RBRACKET)
			{
				match(Y_RBRACKET);
			}
			else
			{
				p->right = rd_const_init_vals();
				match(Y_RBRACKET);
			}
		}
		return p;
	default:
		p = rd_const_exp();
		return p;
	}
}

/*
19 ConstInitVals: Y_COMMA ConstInitVal
20              | Y_COMMA ConstInitVal ConstInitVals
*/
past rd_const_init_vals()
{
	printf("rd_const_init_vals() Begin");
	match(Y_COMMA);
	past p = rd_const_init_val();
	if (cur_token.token == Y_COMMA)
	{
		past pr = rd_const_init_vals();
		past p_node = newAstNode(ArrayInit);
		p_node->left = p;
		p_node->right = pr;
		p = p_node;
	}
	return p;
}

/*
11 ConstDef: Y_ID Y_ASSIGN ConstInitVal
12         | Y_ID ConstExps Y_ASSIGN ConstInitVal
*/
past rd_const_def()
{
	printf("rd_const_def() Begin");
	char *c = strdup(cur_token.attr.svalue);
	past p = newID(c);
	match(Y_ID);
	if (cur_token.token == Y_ASSIGN)
	{
		match(Y_ASSIGN);
		past pr = rd_const_init_val();
		past p_node = newAstNode(ConstDef);
		p_node->left = p;
		p_node->right = pr;
		return p_node;
	}
	else if (cur_token.token == Y_LSQUARE)
	{
		past pr = rd_const_exps();
		past p_arrayNode = newAstNode(ConstArrayAccess);
		p_arrayNode->left = p;
		p_arrayNode->right = pr;
		match(Y_ASSIGN);
		past init_val = rd_const_init_val();
		past p_node = newAstNode(ConstArrayDef);
		p_node->left = p_arrayNode;
		p_node->right = init_val;
		return p_node;
	}
}

/*
9 ConstDefs: ConstDef Y_COMMA ConstDef
10          | ConstDefs Y_COMMA ConstDef
*/
past rd_const_defs()
{
	printf("rd_const_defs() Begin");
	past p = rd_const_def();
	match(Y_COMMA);
	past pr = rd_const_defs();
	past p_node = newAstNode(ConstDefs);
	p_node->left = p;
	p_node->right = pr;
	return p_node;
}

/*
7 ConstDecl: Y_CONST Type ConstDef Y_SEMICOLON
8          | Y_CONST Type ConstDefs Y_SEMICOLON
*/
past rd_const_decl()
{
	printf("rd_const_decl() Begin");
	match(Y_CONST);
	past p_node = newAstNode(ConstDecl);
	p_node->left = rd_type();
	past p = rd_const_def();
	p_node->right = p;
	if (cur_token.token == Y_COMMA)
	{
		past pr = rd_const_defs();
		past p_node1 = newAstNode(ConstDefs);
		p_node1->left = p;
		p_node1->right = pr;
		p_node->right = p_node1;
	}
	match(Y_SEMICOLON);
	return p_node;
}

/*
5 Decl: ConstDecl
6     | VarDecl
*/
past rd_decl()
{
	printf("rd_decl() Begin");
	switch (cur_token.token)
	{
	case Y_CONST:
		return rd_const_decl();
	default:
		return rd_var_decl();
	}
}

/*
47 BlockItem: Decl
48          | Stmt
*/
past rd_block_item()
{
	printf("rd_block_item() Begin");
	past p;
	switch (cur_token.token)
	{
	case Y_CONST:
	case Y_INT:
	case Y_FLOAT:
		return rd_decl();
	default:
		return rd_stmt();
	}
}

/*
45 BlockItems: BlockItem
46           | BlockItem BlockItems
*/
past rd_block_items()
{
	printf("rd_block_items() Begin");
	past p = rd_block_item();
	if (cur_token.token != Y_RBRACKET)
	{
		past pr = rd_block_items();
		p->next = pr;
	}
	return p;
}

/*
43 Block: Y_LBRACKET BlockItems Y_RBRACKET
44      | Y_LBRACKET Y_RBRACKET
*/
past rd_block()
{
	printf("rd_block() Begin");
	match(Y_LBRACKET);
	if (cur_token.token != Y_RBRACKET)
	{
		past p = rd_block_items();
		match(Y_RBRACKET);
		return p;
	}
	else
	{
		match(Y_RBRACKET);
		return newAstNode(EmptyBlock);
	}
}

/*
39 FuncParam: Type Y_ID
40          | Type Y_ID Y_LSQUARE Y_RSQUARE
41          | Type Y_ID ArraySubscripts
42          | Type Y_ID Y_LSQUARE Y_RSQUARE ArraySubscripts
*/
past rd_func_param()
{
	printf("rd_func_param() Begin");
	// 1. 解析类型
	past type = rd_type(); // 返回 NodeInt 等

	// 2. 解析标识符
	char *name = strdup(cur_token.attr.svalue);
	match(Y_ID);
	past p_ID = newID(name);
	past p_node = newAstNode(FuncParam);
	p_node->left = type;
	p_node->svalue = name;

	// 3. 检查是否为数组参数
	past Subscripts = NULL;
	if (cur_token.token == Y_LSQUARE)
	{
		match(Y_LSQUARE);
		if (cur_token.token != Y_RSQUARE)
		{ // 带下表数组
			past exp = rd_exp();
			match(Y_RSQUARE);
			Subscripts = newAstNode(ArraySubscripts);
			Subscripts->left = exp;
			if (cur_token.token == Y_LSQUARE)
			{
				past p_Subscript = rd_array_subscripts();
				Subscripts->right = p_Subscript;
			}
		}
		else
		{ // 空数组
			match(Y_RSQUARE);
			Subscripts = newAstNode(ArraySubscripts);
			if (cur_token.token == Y_LSQUARE)
			{
				past p_Subscript = rd_array_subscripts();
				Subscripts->right = p_Subscript;
			}
		}
	}
	p_node->right = Subscripts;
	return p_node;
}

/*
37 FuncParams: FuncParam
38           | FuncParams Y_COMMA FuncParam
*/
past rd_func_params()
{
	printf("rd_func_params() Begin");
	past p = rd_func_param();
	past p_node = newAstNode(FuncParams);
	if (cur_token.token == Y_COMMA)
	{
		past pr = rd_func_params();
		p_node->left = p;
		p_node->right = pr;
	}
	return p_node;
}

/*
35 FuncDef: Type Y_ID Y_LPAR Y_RPAR Block
36        | Type Y_ID Y_LPAR FuncParams Y_RPAR Block
*/
past rd_func_def()
{
	printf("rd_func_def() Begin");
	past type = rd_type();
	char *name = strdup(cur_token.attr.svalue);
	match(Y_ID);
	match(Y_LPAR);
	past params = NULL;
	if (cur_token.token != Y_RPAR)
	{
		params = rd_func_params();
	}
	match(Y_RPAR);
	past block = rd_block();
	past p_node = newAstNode(FuncDef);
	p_node->left = type;
	p_node->svalue = name;
	p_node->right = params;
	p_node->next = block;
	return p_node;
}

/*
1 CompUnit: Decl CompUnit
2         | FuncDef CompUnit
3         | Decl
4         | FuncDef

5 Decl: ConstDecl
6     | VarDecl

35 FuncDef: Type Y_ID Y_LPAR Y_RPAR Block
36        | Type Y_ID Y_LPAR FuncParams Y_RPAR Block

21 VarDecl: Type VarDef Y_SEMICOLON
22        | Type VarDef VarDecls Y_SEMICOLON

25 VarDef: Y_ID
26       | Y_ID Y_ASSIGN InitVal
27       | Y_ID ConstExps
28       | Y_ID ConstExps Y_ASSIGN InitVal

13 ConstExps: Y_LSQUARE ConstExp Y_RSQUARE
14          | Y_LSQUARE ConstExp Y_RSQUARE ConstExps

7 ConstDecl: Y_CONST Type ConstDef Y_SEMICOLON
8          | Y_CONST Type ConstDefs Y_SEMICOLON
*/
past rd_comp_unit()
{
	printf("rd_comp_unit() Begin");
	past head = NULL;
	past *p_next = &head;

	while (1)
	{
		// 检查是否到达输入结束（根据你的 lexer 行为）
		if (cur_token.token == 0) // 假设 0 表示 EOF
			break;

		past node = NULL;

		if (cur_token.token == Y_CONST)
		{
			node = rd_const_decl();
		}
		else if (cur_token.token == Y_INT ||
				 cur_token.token == Y_FLOAT ||
				 cur_token.token == Y_VOID)
		{
			// 先保存类型
			past type = rd_type();

			// 必须紧跟 Y_ID
			if (cur_token.token != Y_ID)
			{
				fprintf(stderr, "Error: expected identifier after type\n");
				exit(1);
			}

			char *name = strdup(cur_token.attr.svalue);
			match(Y_ID); // consume ID

			// 关键判断：ID 后是不是 '(' ？
			if (cur_token.token == Y_LPAR)
			{
				// ========== 解析函数定义 ==========
				match(Y_LPAR);
				past params = NULL;
				if (cur_token.token != Y_RPAR)
				{
					params = rd_func_params();
				}
				match(Y_RPAR);
				past block = rd_block();

				node = newAstNode(FuncDef);
				node->svalue = name;
				node->left = type;	  // 参数列表（链表）
				node->right = params; // 函数参数（链表）
				node->next = block;	  // 函数体
			}
			else
			{
				// ========== 解析变量声明 ==========
				past p = newID(name);
				past p_node = newAstNode(VarDecl); // 变量声明
				p_node->left = p;
				if (cur_token.token == Y_ASSIGN)
				{
					past pr = rd_init_val();
					p_node->nodeType = VarDef; // 变量定义
					p_node->right = pr;
					p = p_node;
				}
				else if (cur_token.token == Y_LSQUARE)
				{
					past pr = rd_const_exps();
					past p_node1 = newAstNode(ArrayDecl); // 数组声明
					p_node1->left = p;
					p_node1->right = pr;
					p = p_node1;
					if (cur_token.token == Y_ASSIGN)
					{
						past init_val = rd_init_val();
						p_node = newAstNode(ArrayDef); // 数组定义
						p_node->left = p;
						p_node->right = init_val;
						p = p_node;
					}
				}
				past current = p;

				// 处理后续变量：, b, c...
				while (cur_token.token == Y_COMMA)
				{
					match(Y_COMMA);
					// 后续的 VarDef 仍以 Y_ID 开头，可直接调用 rd_var_def()
					past next_def = rd_var_def();
					current->next = next_def;
					current = next_def;
				}

				match(Y_SEMICOLON);

				// 创建 VarDecl 节点
				node = newAstNode(VarDecl);
				node->left = type;
				node->right = p; // 变量定义链表
			}
		}
		else
		{
			// 遇到无法识别的顶层 token，认为 CompUnit 结束
			// 例如：可能是 }、非法符号、或文件结束
			break;
		}

		// 链接到结果链表
		*p_next = node;
		p_next = &(node->next);
	}

	return head;
}

void match(enum yytokentype t)
{
	if (cur_token.token != t)
	{
		printf("error: expect %s, but get %s\n", yytext, cur_token.token);
		exit(1);
	}
	else
	{
		printf("match %s\n", yytext);
	}
	advance();
}

// 修正main函数
int main(int argc, char **argv)
{
	init_token();
	// 初始化cur_token
	memset(&cur_token, 0, sizeof(cur_token));

	printf("Parser started. Input your code:\n");

	// 读取第一个token
	advance();

	// 测试：解析语句
	past result = rd_comp_unit();
	printAst(result, 2);

	printf("Parse completed successfully!\n");

	// 这里可以添加AST显示代码
	// showAst(result, 0);

	return 0;
}