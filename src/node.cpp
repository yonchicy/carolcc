#include  "node.h"
#include  "error.h"
#include  "runtime.h"
#include <cstdio>

NODE* NODE::new_node(TYPE_SET node_type){
  NODE* node = new NODE();
  node->node_type = node_type;
  printf( "\nnew node %d  ",node_type);
  return node;
}
void NODE::add_child(const NODE* const node){
  NODE::node_list.push_back(node);
  printf( "\nadd child  ");
}
void NODE::add_child_(TYPE_SET node_type){
  NODE *IRnode = new NODE();
  NODE::IRnode_list.push_back(IRnode);
  ERROR( "add child %d\n",node_type);
}
std::string get_detail(const NODE* const node){
  std::string detial= "";
  

  switch (node->node_type)
  {
    case CompUnit: detial.append( "CompUnit ");break;
    case FuncDef: detial.append( "FuncDef ");detial.append(node->func_name);break;
    case FuncType: detial.append( "FuncType ");detial.append(node->func_type);break;
    case Block: detial.append( "Block ");break;
    case Stmt: detial.append( "Stmt ");break;
    case Number: detial.append( "Number ");detial.append(std::to_string(node->intv));break;
    case Exp: detial.append( "Exp ");break;
    case PrimaryExp: detial.append( "PrimaryExp ");break;
    case UnaryExp: detial.append( "UnaryExp ");detial.append(node->op);break;
    case MulExp: detial.append( "MulExp ");detial.append(node->op);break;
    case AddExp: detial.append( "AddExp ");detial.append(node->op);break;
    case RelExp: detial.append( "RelExp ");detial.append(node->op);break;
    case EqExp: detial.append( "EqExp ");detial.append(node->op);break;
    case LAndExp: detial.append( "LAndExp ");detial.append(node->op);break;
    case LOrExp: detial.append( "LOrExp ");detial.append(node->op);break;

    case Decl:detial.append("Decl ");break;
    case ConstDecl:detial.append("ConstDecl ");break;
    case BType:detial.append("BType ");break;
    case ConstExp:detial.append("ConstExp ");break;
    case ConstDef:detial.append("ConstDef ");detial.append(node->LVal);break;
    case ConstDefList:detial.append("ConstDefList ");break;
    case ConstInitVal:detial.append("ConstInitVal ");break;
    case VarDecl:detial.append("VarDecl ");break;
    case VarDef:detial.append("VarDef ");detial.append(node->LVal);break;
    case VarDefList:detial.append("VarDefList ");break;
    case InitVal:detial.append("InitVal ");break;
    case BlockItem:detial.append("BlockItem ");break;
    case BlockItemList:detial.append("BlockItemList ");break;
    case LVal:detial.append("LVal ");detial.append(node->LVal);break;
    default:detial.append( "error! ");break;
  }
return detial;

}

bool NODE::check_op()const{
  return NODE::op.compare("")!=0;
}
