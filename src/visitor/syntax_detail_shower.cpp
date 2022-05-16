//
// Created by Administrator on 2022/5/1.
//
#include "syntax_detail_shower.h"
#include "utils.h"
#include <stdlib.h>
#include <helpers/graph_helper.h>
int no = 0;
std::string father_node="start";
graph dg = graph();
void syntax_detail_shower::visit(syntax_tree_node &node) {
}
void syntax_detail_shower::visit(tree_comp_unit &node) {
    no++;
    std::printf("here!\n");
    std::string this_node = "comp_unit_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.set("syntax_detail",graphType::LeiTu,"syntax_detail","describe attributes here");
    dg.begin();
    dg.LeiTu_add(father_node,"comp_unit_"+std::to_string(no));
    for(auto nd : node.definitions){
        father_node = this_node;
        nd->accept(*this);
    }
    for(auto nd : node.functions){
        father_node = this_node;
        nd->accept(*this);
    }
    dg.finish("result","give your description");
    dg.close();
}
void syntax_detail_shower::visit(tree_func_def &node) {
    no++;
    std::string this_node = "func_def_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"func_def_"+std::to_string(no));
    for(auto nd : node.block){
        father_node = this_node;
        nd->accept(*this);
    }
    father_node = this_node;
    if(node.funcfparams)node.funcfparams->accept(*this);
    father_node = this_node;
    if(node.type)node.type->accept(*this);
    dg.LeiTu_add_attr(father_node,node.id);
}
void syntax_detail_shower::visit(tree_block &node) {
    no++;
    std::string this_node = "block_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"block_"+std::to_string(no));
    father_node = this_node;
    if(node.block_item_list)node.block_item_list->accept(*this);
}
void syntax_detail_shower::visit(tree_const_decl &node) {
    no++;
    std::string this_node = "const_decl_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"const_decl_"+std::to_string(no));
    father_node = this_node;
    if(node.const_def_list)node.const_def_list->accept(*this);
    father_node = this_node;
    if(node.b_type)node.b_type->accept(*this);
}
void syntax_detail_shower::visit(tree_basic_type &node) {
    no++;
    std::string this_node = "basic_type_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"basic_type_"+std::to_string(no));
}
void syntax_detail_shower::visit(tree_const_def_list &node) {
    no++;
    std::string this_node = "const_def_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"const_def_"+std::to_string(no));
    for(auto nd : node.const_defs){
        father_node = this_node;
        nd->accept(*this);
    }
}
void syntax_detail_shower::visit(tree_const_init_val &node) {
    no++;
    std::string this_node = "const_init_val_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"const_init_val_"+std::to_string(no));
    father_node = this_node;
    std::printf("%s\n",this_node.c_str());
    if(node.const_exp)node.const_exp->accept(*this);
}
void syntax_detail_shower::visit(tree_const_exp &node) {
    no++;
    std::string this_node = "const_exp_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"const_exp_"+std::to_string(no));
    father_node = this_node;
    if(node.add_exp)node.add_exp->accept(*this);
}
void syntax_detail_shower::visit(tree_var_decl &node) {
    no++;
    std::string this_node = "var_decl_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"var_decl_"+std::to_string(no));
    father_node = this_node;
    if(node.b_type)node.b_type->accept(*this);
    father_node = this_node;
    if(node.var_def_list)node.var_def_list->accept(*this);
}
void syntax_detail_shower::visit(tree_exp &node) {
    no++;
    std::string this_node = "exp_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"exp_"+std::to_string(no));
    father_node = this_node;
    if(node.add_exp)node.add_exp->accept(*this);
}
void syntax_detail_shower::visit(tree_init_val &node) {
    no++;
    std::string this_node = "init_val_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"init_val_"+std::to_string(no));
    father_node = this_node;
    if(node.exp)node.exp->accept(*this);
}
void syntax_detail_shower::visit(tree_decl &node) {
    no++;
    std::string this_node = "decl_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"decl_"+std::to_string(no));
    father_node = this_node;
    if(node.const_decl)node.const_decl->accept(*this);
    father_node = this_node;
    if(node.var_decl)node.var_decl->accept(*this);
}
void syntax_detail_shower::visit(tree_const_def &node) {
    no++;
    std::string this_node = "const_def_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"const_def_"+std::to_string(no));
    father_node = this_node;
    if(node.const_exp_list)node.const_exp_list->accept(*this);
    father_node = this_node;
    if(node.const_init_val)node.const_init_val->accept(*this);
    father_node = this_node;
    dg.LeiTu_add_attr(father_node,node.id);
}
void syntax_detail_shower::visit(tree_var_def_list &node) {
    no++;
    std::string this_node = "var_def_list_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"var_def_list_"+std::to_string(no));
    for(auto nd : node.var_defs){
        father_node = this_node;
        nd->accept(*this);
    }
}
void syntax_detail_shower::visit(tree_var_def &node) {
    no++;
    std::string this_node = "var_def_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"var_def_"+std::to_string(no));
    father_node = this_node;
    if(node.array_def)node.array_def->accept(*this);
    father_node = this_node;
    if(node.init_val)node.init_val->accept(*this);
    father_node = this_node;
    if(node.init_val_array)node.init_val_array->accept(*this);
    dg.LeiTu_add_attr(father_node,node.id);
}
void syntax_detail_shower::visit(tree_block_item_list &node) {
    no++;
    std::string this_node = "block_item_list_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"block_item_list_"+std::to_string(no));
    for(auto nd : node.block_items){
        father_node = this_node;
        nd->accept(*this);
    }
}
void syntax_detail_shower::visit(tree_block_item &node) {
    no++;
    std::string this_node = "block_item_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"block_item_"+std::to_string(no));
    father_node = this_node;
    if(node.decl)node.decl->accept(*this);
    father_node = this_node;
    if(node.stmt)node.stmt->accept(*this);
}
void syntax_detail_shower::visit(tree_stmt &node) {
    no++;
    std::string this_node = "stmt_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"stmt_"+std::to_string(no));
    father_node = this_node;
    if(node.assigm_stmt)node.assigm_stmt->accept(*this);
    father_node = this_node;
    if(node.block)node.block->accept(*this);
    father_node = this_node;
    if(node.break_stmt)node.break_stmt->accept(*this);
    father_node = this_node;
    if(node.continue_stmt)node.continue_stmt->accept(*this);
    father_node = this_node;
    if(node.exp)node.exp->accept(*this);
    father_node = this_node;
    if(node.if_else_stmt)node.if_else_stmt->accept(*this);
    father_node = this_node;
    if(node.if_stmt)node.if_stmt->accept(*this);
    father_node = this_node;
    if(node.return_null_stmt)node.return_null_stmt->accept(*this);
    father_node = this_node;
    if(node.return_stmt)node.return_stmt->accept(*this);
    father_node = this_node;
    if(node.while_stmt)node.while_stmt->accept(*this);
}
void syntax_detail_shower::visit(tree_assign_stmt &node) {
    no++;
    std::string this_node = "assign_stmt_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"assign_stmt_"+std::to_string(no));
    father_node = this_node;
    if(node.l_val)node.l_val->accept(*this);
    father_node = this_node;
    if(node.exp)node.exp->accept(*this);
}
void syntax_detail_shower::visit(tree_return_stmt &node) {
    no++;
    std::string this_node = "return_stmt_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"return_stmt_"+std::to_string(no));
    father_node = this_node;
    if(node.exp)node.exp->accept(*this);
}
void syntax_detail_shower::visit(tree_return_null_stmt &node) {
    no++;
    std::string this_node = "return_null_stmt_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"return_null_stmt_"+std::to_string(no));
}
void syntax_detail_shower::visit(tree_l_val &node) {
    no++;
    std::string this_node = "l_val_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"l_val_"+std::to_string(no));
    father_node = this_node;
    if(node.array_ident)node.array_ident->accept(*this);
    dg.LeiTu_add_attr(father_node,node.id);
}
void syntax_detail_shower::visit(tree_number &node) {
    no++;
    std::string this_node = "number_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"number_"+std::to_string(no));
    dg.LeiTu_add_attr("number_"+std::to_string(no),"float "+std::to_string(int(node.float_value)));
    dg.LeiTu_add_attr("number_"+std::to_string(no),"int "+std::to_string(node.int_value));
}
void syntax_detail_shower::visit(tree_primary_exp &node) {
    no++;
    std::string this_node = "primary_exp"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"primary_exp"+std::to_string(no));
    father_node = this_node;
    if(node.exp)node.exp->accept(*this);
    father_node = this_node;
    if(node.number)node.number->accept(*this);
    father_node = this_node;
    if(node.l_val)node.l_val->accept(*this);
}
void syntax_detail_shower::visit(tree_unary_exp &node) {
    no++;
    std::string this_node = "unary_exp_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"unary_exp_"+std::to_string(no));
    father_node = this_node;
    if(node.func_call)node.func_call->accept(*this);
    father_node = this_node;
    if(node.primary_exp)node.primary_exp->accept(*this);
    father_node = this_node;
    if(node.unary_exp)node.unary_exp->accept(*this);
}
void syntax_detail_shower::visit(tree_mul_exp &node) {
    no++;
    std::string this_node = "mul_exp_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"mul_exp_"+std::to_string(no));
    father_node = this_node;
    if(node.mul_exp)node.mul_exp->accept(*this);
    father_node = this_node;
    if(node.unary_exp)node.unary_exp->accept(*this);
}
void syntax_detail_shower::visit(tree_add_exp &node) {
    no++;
    std::string this_node = "add_exp_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"add_exp_"+std::to_string(no));
    father_node = this_node;
    if(node.add_exp)node.add_exp->accept(*this);
    father_node = this_node;
    if(node.mul_exp)node.mul_exp->accept(*this);
}
void syntax_detail_shower::visit(tree_rel_exp &node) {
    no++;
    std::string this_node = "rel_exp_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"rel_exp_"+std::to_string(no));
    father_node = this_node;
    if(node.add_exp)node.add_exp->accept(*this);
    father_node = this_node;
    if(node.rel_exp)node.rel_exp->accept(*this);
}
void syntax_detail_shower::visit(tree_eq_exp &node) {
    no++;
    std::string this_node = "eq_exp_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"eq_exp_"+std::to_string(no));
    father_node = this_node;
    if(node.eq_exp)node.eq_exp->accept(*this);
    father_node = this_node;
    if(node.rel_exp)node.rel_exp->accept(*this);
}
void syntax_detail_shower::visit(tree_l_and_exp &node) {
    no++;
    std::string this_node = "l_and_exp_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"l_and_exp_"+std::to_string(no));
    father_node = this_node;
    if(node.eq_exp)node.eq_exp->accept(*this);
    father_node = this_node;
    if(node.l_and_exp)node.l_and_exp->accept(*this);
}
void syntax_detail_shower::visit(tree_l_or_exp &node) {
    no++;
    std::string this_node = "l_or_exp_"+std::to_string(no);
    std::printf("%s\n",this_node.c_str());
    dg.LeiTu_add(father_node,"l_or_exp_"+std::to_string(no));
    father_node = this_node;
    if(node.l_and_exp)node.l_and_exp->accept(*this);
    father_node = this_node;
    if(node.l_or_exp)node.l_or_exp->accept(*this);
    }
