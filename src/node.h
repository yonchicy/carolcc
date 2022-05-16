#ifndef _NODE_H_
#define _NODE_H_
#include "runtime.h"
#include "utils.h"
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
enum TYPE_SET{
  CompUnit,
  FuncDef,
  FuncType,
  Block,
  Stmt,
  Number,
  Exp,
  PrimaryExp,
  UnaryExp,
  MulExp,
  AddExp,
  RelExp,
  EqExp,
  LAndExp,
  LOrExp,
  Decl,
  ConstDecl,
  BType,
  ConstExp,
  ConstDef,
  ConstDefList,
  ConstInitVal,
  VarDecl,
  VarDef,
  VarDefList,
  InitVal,
  BlockItem,
  BlockItemList,
  LVal
};
class op_v{
  public:
  std::string op="";
  int v=0;
  std::string lval="";
};
class NODE{
  public:
  TYPE_SET node_type=CompUnit;
  std::vector<const NODE*> node_list;
  std::vector<NODE*> IRnode_list;
  NODE* new_node(TYPE_SET node_type);
  void add_child(const NODE* const node);
  void add_child_(TYPE_SET node_type);
  /*CompUnit*/
  
  /*FuncDef*/
  std::string func_name;

  /*FuncType*/
  std::string func_type;

  /*Block*/

  /*Stmt*/

  /*Number*/
  int intv=0;
  /*Exp*/
  std::vector<op_v> exp_stream;
  /*PrimaryExp*/

  /*UnaryExp*/
  std::string op="";
  bool check_op()const;
  /*MulExp*/

  /*AddExp*/

  /*RelExp*/

  /*EqExp*/

  /*LAndExp*/

  /*LOrExp*/

  /*Decl*/

  /*ConstDecl*/

  /*BType*/
  std::string b_type;

  /*ConstExp*/

  /*ConstDef*/

  /*ConstDefList*/

  /*ConstInitVal*/

  /*VarDecl*/

  /*VarDef*/
  /*std::string def_name;*/
  
  /*VarDefList*/

  /*InitVal*/

  /*BlockItem*/

  /*BlockItemList*/

  /*LVal*/
  std::string LVal="";

};
void show_ast(const NODE* base_node,int dp);
void ast_to_ir(const NODE* base_node,int dp);
void IR_exp(NODE* exp_node,const NODE* base_node,int dp);
std::string get_detail(const NODE* const node);
op_v cal(NODE* base_node,std::vector<std::string> &cal_stream);
void exp_ir_show(NODE* base_node);
void show_ir(NODE* base_node,int dp);
#endif
