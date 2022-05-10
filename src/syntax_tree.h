
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
class tree_init_val_array;
class tree_init_val_arraylist;
class tree_func_fparams;
class tree_func_fparam;
class tree_func_fparamone;
class tree_func_fparamarray;
class tree_decl;
class tree_const_def;
class tree_var_def_list;
class tree_var_def;
class tree_func_type;
class tree_block_item_list;
class tree_block_item;
class tree_stmt;
class tree_assign_stmt;
class tree_if_stmt;
class tree_if_else_stmt;
class tree_while_stmt ;
class tree_break_stmt;
class tree_continue_stmt;
class tree_cond;
class tree_return_stmt;
class tree_return_null_stmt;
class tree_l_val;
class tree_array_ident;
class tree_number;
class tree_primary_exp;
class tree_unary_exp;
class tree_func_call;
class tree_funcr_paramlist;
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

class tree_init_val_array : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_init_val_arraylist> init_val_arraylist;
};

class tree_init_val_arraylist : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::list<std::shared_ptr<tree_init_val_array>> initvalarrays;
    std::list<std::shared_ptr<tree_init_val>> initvals;
};

class tree_func_def : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_func_type> type;
    std::string id;
    std::shared_ptr<tree_func_fparams> funcfparams;
    std::list<std::shared_ptr<tree_block>> block;
};

class tree_func_type : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    type_helper type;
};

class tree_func_fparams : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::list<std::shared_ptr<tree_func_fparam>> funcfparamlist;
};

class tree_func_fparam : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_func_fparamone> funcfparamone;
    std::shared_ptr<tree_func_fparamarray> funcfparamarray;
};

class tree_func_fparamone : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_basic_type> b_type;
    std::string id;
};

class tree_func_fparamarray : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_basic_type> b_type;
    std::string id;
    std::list<std::shared_ptr<tree_exp>> exps;
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
    std::shared_ptr<tree_if_stmt> if_stmt;
    std::shared_ptr<tree_if_else_stmt> if_else_stmt;
    std::shared_ptr<tree_while_stmt> while_stmt;
    std::shared_ptr<tree_continue_stmt> continue_stmt;
    std::shared_ptr<tree_break_stmt> break_stmt;
    std::shared_ptr<tree_return_stmt> return_stmt;
    std::shared_ptr<tree_return_null_stmt> return_null_stmt;
};

class tree_assign_stmt : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_l_val> l_val;
    std::shared_ptr<tree_exp> exp;
};

class tree_if_stmt : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_cond> cond;
    std::shared_ptr<tree_stmt> stmt;
};

class tree_if_else_stmt : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_cond> cond;
    std::shared_ptr<tree_stmt> stmt1;
    std::shared_ptr<tree_stmt> stmt2;
};

class tree_while_stmt : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_cond> cond;
    std::shared_ptr<tree_stmt> stmt;
};

class tree_continue_stmt : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;
};

class tree_break_stmt : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;
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

class tree_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_add_exp> add_exp;
};

class tree_cond : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_l_or_exp> l_or_exp;
};

class tree_l_val : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::string id;
    std::shared_ptr<tree_array_ident> array_ident;
};

class tree_array_ident : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::string id;
    std::shared_ptr<tree_exp> exp;
};

class tree_number : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    int int_value;
    float float_value;
};

class tree_primary_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_exp> exp;
    std::shared_ptr<tree_l_val> l_val;
    std::shared_ptr<tree_number> number;
};

class tree_unary_exp : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::shared_ptr<tree_primary_exp> primary_exp;
    std::string oprt;
    std::shared_ptr<tree_unary_exp> unary_exp;
    std::shared_ptr<tree_func_call> func_call;
};

class tree_func_call : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::string id;
    std::shared_ptr<tree_funcr_paramlist> funcr_paramlist;
};

class tree_funcr_paramlist : public syntax_tree_node {
public:
    void accept(visitor_base &v) final;

    std::list<std::shared_ptr<tree_exp>> exps;
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
