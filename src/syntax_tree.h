//
// Created by yonchicy on 22-5-1.
//

#ifndef CAROLCC_SYNTAX_TREE_H
#define CAROLCC_SYNTAX_TREE_H
#include "helpers/type_helper.h"
#include <list>
#include <memory>
#include <string>


class visitor_base;
class tree_comp_unit;
class tree_func_def;
class tree_block;
class tree_const_decl;
class tree_basic_type;
class tree_const_def_list;
class tree_const_init_val;
class tree_const_exp;
class tree_var_decl;
class tree_exp;
class tree_init_val;
class tree_decl;
class tree_const_def;
class tree_var_def_list;
class tree_var_def;
class tree_func_type;
class tree_block_item_list;
class tree_block_item;
class tree_stmt;
class tree_assign_stmt;
class tree_return_stmt;
class tree_return_null_stmt;
class tree_l_val;
class tree_number;
class tree_primary_exp;
class tree_unary_exp;
class tree_mul_exp;
class tree_add_exp;
class tree_rel_exp;
class tree_eq_exp;
class tree_l_and_exp;
class tree_l_or_exp;


class syntax_tree_node {
public:
    virtual void accept(visitor_base &v);
};

class tree_comp_unit : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::list<std::shared_ptr<tree_func_def>> functions;
};

class tree_decl : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_const_decl> const_decl;
    std::shared_ptr<tree_var_decl> var_decl;
};
class tree_const_decl : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_basic_type> b_type;
    std::shared_ptr<tree_const_def_list> const_def_list;
};
class tree_const_def_list : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::list<std::shared_ptr<tree_const_def>> const_defs;
};
class tree_basic_type : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    type_helper type = type_helper::INT;
};
class tree_const_def : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::string id;
    std::shared_ptr<tree_const_init_val> const_init_val;
};
class tree_const_init_val : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_const_exp> const_exp;
};
class tree_const_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_exp> exp;
};
class tree_var_decl : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_basic_type> b_type;
    std::shared_ptr<tree_var_def_list> var_def_list;
};
class tree_var_def_list : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::list<std::shared_ptr<tree_var_def>> var_defs;
};
class tree_var_def : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::string id;
    std::shared_ptr<tree_init_val> init_val;
};
class tree_init_val : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_exp> exp;
};
class tree_func_def : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    type_helper type;
    std::string id;
    std::list<std::shared_ptr<tree_block>> block;
};
class tree_func_type : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    type_helper type;
};
class tree_block : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_block_item_list> block_item_list;
};
class tree_block_item_list : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::list<std::shared_ptr<tree_block_item>> block_items;
};
class tree_block_item : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_decl> decl;
    std::shared_ptr<tree_stmt> stmt;
};
class tree_stmt : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_assign_stmt> assigm_stmt;
    std::shared_ptr<tree_exp> exp;
    std::shared_ptr<tree_block> block;
    std::shared_ptr<tree_return_stmt> return_stmt;
    std::shared_ptr<tree_return_null_stmt> return_null_stmt;
};
class tree_return_null_stmt : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;
};
class tree_return_stmt : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_exp> exp;
};
class tree_assign_stmt : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_l_val> l_val;
    std::shared_ptr<tree_exp> exp;
};
class tree_l_val : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::string id;
};
class tree_number : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    long value;
};
class tree_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_l_or_exp> l_or_exp;
};

class tree_unary_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_primary_exp> primary_exp;
    std::string oprt;
    std::shared_ptr<tree_unary_exp> unary_exp;
};
class tree_primary_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_exp> exp;
    std::shared_ptr<tree_l_val> l_val;
    std::shared_ptr<tree_number> number;
};
class tree_mul_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_unary_exp> unary_exp;
    std::string oprt;
    std::shared_ptr<tree_mul_exp> mul_exp;
};
class tree_add_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_mul_exp> mul_exp;
    std::string oprt;
    std::shared_ptr<tree_add_exp> add_exp;
};
class tree_rel_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_add_exp> add_exp;
    std::string oprt;
    std::shared_ptr<tree_rel_exp> rel_exp;
};
class tree_eq_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_rel_exp> rel_exp;
    std::string oprt;
    std::shared_ptr<tree_eq_exp> eq_exp;
};
class tree_l_and_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_eq_exp> eq_exp;
    std::shared_ptr<tree_l_and_exp> l_and_exp;
};
class tree_l_or_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_l_and_exp> l_and_exp;
    std::shared_ptr<tree_l_or_exp> l_or_exp;
};

#endif// CAROLCC_SYNTAX_TREE_H
