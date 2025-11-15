// .y文件
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/ast.h"
#include "include/node_type.h"

void yyerror(const char *s);
int yylex(void);  // 由 flex 提供
%}

/*  关键：让 sysy.tab.h 知道 past 是什么 */
%code requires {
#include "include/ast.h"
}

/* 支持返回整数值和字符串（用于变量名） */
%union {
      /* 需拓展 */
    int ival;
    char* sval;
    double fval;
    past pval;
}
/* Bison会生成一个 YYSTYPE 类型，用于存储 token 的值 */ 
/* 而 yylval就是这个类型的一个全局变量 */

/* 声明 token 类型 */
/* 定义后就可以在后面用$1 $2获取值了*/
%token <ival> num_INT Y_INT Y_VOID Y_CONST Y_IF Y_ELSE Y_WHILE Y_BREAK Y_CONTINUE Y_FLOAT Y_RETURN
%token <ival> Y_ADD Y_COMMA Y_DIV  Y_LPAR Y_SUB Y_LSQUARE Y_MODULO Y_MUL Y_NOT Y_RPAR Y_RSQUARE Y_RBRACKET
%token <ival> Y_LESS Y_LESSEQ Y_GREAT Y_GREATEQ Y_NOTEQ Y_EQ Y_AND Y_OR Y_ASSIGN Y_LBRACKET Y_SEMICOLON
%token <fval> num_FLOAT
%token <sval> Y_ID 
%token YYEOF
%type  <pval>	program Exp AddExp MulExp UnaryExp CallParams PrimaryExp LVal ArraySubscripts
%type  <pval>	Block BlockItem BlockItems Stmt RelExp EqExp LAndExp LOrExp  
%type  <pval>	FuncDef FuncParam FuncParams Type 
%type  <pval>  CompUnit Decl ConstDecl ConstDefs ConstDef ConstExps ConstInitVal ConstInitVals 
%type  <pval>  VarDecl VarDecls VarDef InitVal InitVals ConstExp



%%

program: CompUnit {
            showAst($1, 0, 1);
            $$ = $1;
      }
      ;

CompUnit: Decl CompUnit {
            $$ = new_ast_node(TRANSLATION_UNIT);
            $$->left = $1;
            $$->right = $2;
      }
        | FuncDef CompUnit {
            $$ = new_ast_node(TRANSLATION_UNIT);
            $$->left = $1;
            $$->right = $2;
      }        
        | Decl {
            $$ = new_ast_node(TRANSLATION_UNIT);
            $$->left = $1;
        }
        | FuncDef {
            $$ = new_ast_node(TRANSLATION_UNIT);
            $$->left = $1;
        }

Decl: ConstDecl {
      $$ = $1;
}
    | VarDecl {
      $$ = $1;
    }

ConstDecl: Y_CONST Type ConstDef Y_SEMICOLON {
            $$ = new_ast_node(VAR_DECL);
            $$->left = $2;
            $$->right = $3;
      }
         | Y_CONST Type ConstDefs Y_SEMICOLON {
            $$ = new_ast_node(VAR_DECL);
            $$->left = $2;
            $$->right = $3;
         }

ConstDefs: ConstDef Y_COMMA ConstDef {
            $$ = new_ast_node(VAR_DECL);
            $$->left = $1;            
            $$->right = $3;      
      }
         | ConstDefs Y_COMMA ConstDef {
            $$ = new_ast_node(VAR_DECL);
            $$->left = $1;
            $$->right = $3;            
         }

ConstDef: Y_ID Y_ASSIGN ConstInitVal {
            $$ = new_ast_node(VAR_DECL);
            $$->svalue = $1;            
            $$->right = $3;      
      }
        | Y_ID ConstExps Y_ASSIGN ConstInitVal {
            $$ = new_ast_node(VAR_DECL);
            $$->svalue = $1;
            $$->left = $2;
            $$->right = $4;      
        }

ConstExps: Y_LSQUARE ConstExp Y_RSQUARE {
            $$ = $2;
      }
         | Y_LSQUARE ConstExp Y_RSQUARE ConstExps {
            $$ = new_ast_node(INIT_LIST_EXPR);
            $$->left = $2;
            $$->right = $4;
         }

ConstInitVal: ConstExp {
                  $$ = $1;
            }
            | Y_LBRACKET Y_RBRACKET {      
                  $$ = NULL;
            }
            | Y_LBRACKET ConstInitVal Y_RBRACKET {
                  $$ = $2
            }
            | Y_LBRACKET ConstInitVal ConstInitVals Y_RBRACKET {
                  $$ = new_ast_node(INIT_LIST_EXPR);
                  $$->left = $2;
                  $$->right = $3;
            }

ConstInitVals: Y_COMMA ConstInitVal {
                  $$ = new_ast_node(INIT_LIST_EXPR);
                  $$->left = $2;
            }
             | Y_COMMA ConstInitVal ConstInitVals {
                  $$ = new_ast_node(INIT_LIST_EXPR);
                  $$->left = $2;
                  $$->right = $3;
             }

VarDecl: Type VarDef Y_SEMICOLON {
            $$ = new_ast_node(VAR_DECL);
            $$->left = $1;
            $$->right = $2;
      }
       | Type VarDef VarDecls Y_SEMICOLON {
            $$ = new_ast_node(VAR_DECL);
            $$->left = $1;
            $$->right = $2;
            $$->next = $3;
       }

VarDecls: Y_COMMA VarDef {
            $$ = new_ast_node(VAR_DECL);
            $$->left = $2;
      }
        | Y_COMMA VarDef VarDecls {
            $$ = new_ast_node(VAR_DECL);
            $$->left = $2;
        }

VarDef: Y_ID {
            $$ = new_ast_node(VAR_DECL);
            $$->svalue = $1;
      }
      | Y_ID Y_ASSIGN InitVal {
            $$ = new_ast_node(VAR_DECL);
            $$->svalue = $1;
            $$->left = $3;
      }
      | Y_ID ConstExps {
            $$ = new_ast_node(VAR_DECL);
            $$->svalue = $1;
            $$->left = $2;      
      }
      | Y_ID ConstExps Y_ASSIGN InitVal {
            $$ = new_ast_node(VAR_DECL);
            $$->svalue = $1;
            $$->left = $2;
            $$->ivalue = $3;
            $$->right = $4;
      }

InitVal: Exp {
            $$ = $1;
      }
       | Y_LBRACKET Y_RBRACKET {
            $$ = new_ast_node(INIT_LIST_EXPR);
       }
       | Y_LBRACKET InitVal Y_RBRACKET {
            $$ = new_ast_node(INIT_LIST_EXPR);
            $$->left = $2;
       }
       | Y_LBRACKET InitVal InitVals Y_RBRACKET {
            $$ = new_ast_node(INIT_LIST_EXPR);
            $$->left = $2;
            $$->right = $3;
       }

InitVals: Y_COMMA InitVal {
            $$ = new_ast_node(INIT_LIST_EXPR);
            $$->left = $2;
      }
        | Y_COMMA InitVal InitVals {
            $$ = new_ast_node(INIT_LIST_EXPR);
            $$->left = $2;
            $$->right = $3;
        }

FuncDef: Type Y_ID Y_LPAR Y_RPAR Block {
      $$ = new_ast_node(FUNCTION_DECL);
      $$->left = $1;
      $$->svalue = $2;
      $$->next = $5;
}
       | Type Y_ID Y_LPAR FuncParams Y_RPAR Block {
            $$ = new_ast_node(FUNCTION_DECL);
            $$->left = $1;
            $$->svalue = $2;
            $$->right = $4;
            $$->next = $6;
       }

FuncParams: FuncParam {
      $$ = $1;
}
          | FuncParams Y_COMMA FuncParam {
            $$ = new_ast_node(PARM_DECL);
            $$->left = $1;
            $$->right = $3;
          }

FuncParam: Type Y_ID {
                  $$ = new_ast_node(PARM_DECL);
                  $$->left = $1;
                  $$->svalue = $2;
            }
         | Type Y_ID Y_LSQUARE Y_RSQUARE {
             $$ = new_ast_node(PARM_DECL);
             $$->left = $1;
             $$->svalue = $2;
         }
         | Type Y_ID ArraySubscripts {
             $$ = new_ast_node(PARM_DECL);
             $$->left = $1;
             $$->svalue = $2;
             $$->right = $3;
         }
         | Type Y_ID Y_LSQUARE Y_RSQUARE ArraySubscripts {
            $$ = new_ast_node(PARM_DECL);
            $$->left = $1;
            $$->svalue = $2;
            $$->right = $5;
         }

Block: Y_LBRACKET BlockItems Y_RBRACKET {
            $$ = new_ast_node(COMPOUND_STMT);
            $$->left = $2;
      }
     | Y_LBRACKET Y_RBRACKET {
      $$ = new_ast_node(NULL_STMT);      
     }

BlockItems: BlockItem {
            $$ = $1;
      }
          | BlockItem BlockItems {
            $$ = $1;
            $$->next = $2;
      }

BlockItem: Decl {
            $$ = $1;
      }
         | Stmt {
            $$ = $1;
      }

Stmt: LVal Y_ASSIGN Exp Y_SEMICOLON {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->left = $1;
            $$->ivalue = $2;
            $$->right = $3;
      }
    | Y_SEMICOLON {
      $$ = new_ast_node(NULL_STMT);
    }
    | Exp Y_SEMICOLON {
        $$ = $1;
    }
    | Block {
        $$ = new_ast_node(COMPOUND_STMT);
        $$->left = $1;
    }
    | Y_WHILE Y_LPAR LOrExp Y_RPAR Stmt {
      $$ = new_ast_node(WHILE_STMT);
      $$->left = $3;
      $$->right = $5;
    }
    | Y_IF Y_LPAR LOrExp Y_RPAR Stmt {
      $$ = new_ast_node(IF_STMT);
      $$->if_cond = $3;
      $$->left = $5;
    }
    | Y_IF Y_LPAR LOrExp Y_RPAR Stmt Y_ELSE Stmt {
      $$ = new_ast_node(IF_STMT);
      $$->if_cond = $3;
      $$->left = $5;
      $$->right = $7;
    }
    | Y_BREAK Y_SEMICOLON {
      $$ = new_ast_node(BREAK_STMT);      
    }
    | Y_CONTINUE Y_SEMICOLON {
      $$ = new_ast_node(CONTINUE_STMT);      
    }
    | Y_RETURN Exp Y_SEMICOLON {
            $$ = new_ast_node(RETURN_STMT);
            $$->left = $2;
    }
    | Y_RETURN Y_SEMICOLON {
            $$ = new_ast_node(RETURN_STMT);            
    }

Exp: AddExp

LVal: Y_ID {
            $$ = new_ast_node(DECL_REF_EXPR);
            $$->svalue = $1;
      }
    | Y_ID ArraySubscripts {
            $$ = new_ast_node(ARRAY_SUBSCRIPT_EXPR);
            $$->svalue = $1;
            $$->left = $2;
      }

ArraySubscripts: Y_LSQUARE Exp Y_RSQUARE {
            $$ = new_ast_node(ARRAY_SUBSCRIPT_EXPR);
            $$->left = $2;
      }
               | Y_LSQUARE Exp Y_RSQUARE ArraySubscripts {
            $$ = new_ast_node(ARRAY_SUBSCRIPT_EXPR);
            $$->left = $2;
            $$->right = $4;
      }

PrimaryExp: Y_LPAR Exp Y_RPAR {
            $$ = $2;    
      }
          | LVal {
            $$ = $1;    
      }
          | num_INT {
            $$  = new_ast_node(INTEGER_LITERAL);
            $$->ivalue = $1;
      }     
          | num_FLOAT {
            $$  = new_ast_node(FLOATING_LITERAL);
            $$->fvalue = $1;
      }

UnaryExp: PrimaryExp {
            $$ = $1;
      }
        | Y_ID Y_LPAR Y_RPAR {
            $$ = new_ast_node(CALL_EXPR);
            $$->svalue = $1;
      }
        | Y_ID Y_LPAR CallParams Y_RPAR {
            $$ = new_ast_node(CALL_EXPR);
            $$->svalue = $1;
            $$->left = $3;
      }
        | Y_ADD UnaryExp {
            $$ = new_ast_node(UNARY_OPERATOR);
            $$->ivalue = $1;
            $$->left = $2;
      }
        | Y_SUB UnaryExp {
            $$ = new_ast_node(UNARY_OPERATOR);
            $$->ivalue = $1;
            $$->left = $2;
      }
        | Y_NOT UnaryExp {
            $$ = new_ast_node(UNARY_OPERATOR);
            $$->ivalue = $1;
            $$->left = $2;
      }

CallParams: Exp {
            $$ = new_ast_node(PARM_DECL);
            $$->left = $1;
      }
          | Exp Y_COMMA CallParams {
            $$ = new_ast_node(PARM_DECL);
            $$->left = $1;
            $$->right = $3;
      }

MulExp: UnaryExp {
            $$ = $1;
      }
      | MulExp Y_MUL UnaryExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }     
      | MulExp Y_DIV UnaryExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }

      | MulExp Y_MODULO UnaryExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }

AddExp: MulExp {
            $$ = $1;
      }
      | AddExp Y_ADD MulExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }
      | AddExp Y_SUB MulExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }

RelExp: AddExp {
            $$ = $1;
      }
      | AddExp Y_LESS RelExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }
      | AddExp Y_GREAT RelExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }
      | AddExp Y_LESSEQ RelExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }
      | AddExp Y_GREATEQ RelExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }

EqExp: RelExp {
            $$ = $1;
      }
     | RelExp Y_EQ EqExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }
     | RelExp Y_NOTEQ EqExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }

LAndExp: EqExp {
            $$ = $1;
      }
       | EqExp Y_AND LAndExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }


LOrExp: LAndExp {
            $$ = $1;
      }
      | LAndExp Y_OR LOrExp {
            $$ = new_ast_node(BINARY_OPERATOR);
            $$->ivalue = $2;
            $$->left = $1;
            $$->right = $3;
      }

ConstExp: AddExp {
            $$ = $1;
      }     

Type: Y_INT {
            $$ = new_ast_node(UNEXPOSED_EXPR);
            $$->ivalue = $1;
      }
     | Y_FLOAT {
          $$ = new_ast_node(UNEXPOSED_EXPR);
          $$->ivalue = $1;
     }
     | Y_VOID {
          $$ = new_ast_node(UNEXPOSED_EXPR);
          $$->ivalue = $1;
     }

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}