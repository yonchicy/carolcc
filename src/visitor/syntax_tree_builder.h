//
// Created by Administrator on 2022/5/1.
//
#ifndef COMPILER_SYNTAX_TREE_BUILDER_H
#define COMPILER_SYNTAX_TREE_BUILDER_H
#include "visitor_base.h"
#include "passes/module.h"
#include "helpers/type_helper.h"
class module;


class syntax_tree_builder : public visitor_base {
public:
    void visit(syntax_tree_node &node) final;
    void visit(tree_comp_unit &node) final;
    void visit(tree_func_def &node) final;
    void visit(tree_block &node) final;
    void visit(tree_const_decl &node) final;
    void visit(tree_basic_type &node) final;
    void visit(tree_const_def_list &node) final;
    void visit(tree_const_init_val &node) final;
    void visit(tree_const_exp &node) final;
    void visit(tree_var_decl &node) final;
    void visit(tree_exp &node) final;
    void visit(tree_init_val &node) final;
    void visit(tree_decl &node) final;
    void visit(tree_const_def &node) final;
    void visit(tree_var_def_list &node) final;
    void visit(tree_var_def &node) final;
    void visit(tree_block_item_list &node) final;
    void visit(tree_block_item &node) final;
    void visit(tree_stmt &node) final;
    void visit(tree_assign_stmt &node) final;
    void visit(tree_return_stmt &node) final;
    void visit(tree_return_null_stmt &node) final;
    void visit(tree_l_val &node) final;
    void visit(tree_number &node) final;
    void visit(tree_primary_exp &node) final;
    void visit(tree_unary_exp &node) final;
    void visit(tree_mul_exp &node) final;
    void visit(tree_add_exp &node) final;
    void visit(tree_rel_exp &node) final;
    void visit(tree_eq_exp &node) final;
    void visit(tree_l_and_exp &node) final;
    void visit(tree_l_or_exp &node) final;
    syntax_tree_builder()= default;;
private :
    module* _module;
};


#endif//COMPILER_SYNTAX_TREE_BUILDER_H