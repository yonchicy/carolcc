
#include "syntax_tree.h"
#include "visitor/visitor_base.h"
void syntax_tree_node::accept(visitor_base &v) {
    v.visit(*this);
}
void tree_comp_unit::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_func_def::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_block::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_const_decl::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_basic_type::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_const_def_list::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_const_init_val::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_const_exp::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_var_decl::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_exp::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_init_val::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_init_val_array::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_init_val_arraylist::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_func_fparams::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_func_fparam::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_func_fparamone::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_func_fparamarray::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_decl::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_const_def::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_var_def_list::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_var_def::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_func_type::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_block_item_list::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_block_item::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_stmt::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_assign_stmt::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_if_stmt::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_if_else_stmt::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_while_stmt::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_break_stmt::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_continue_stmt::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_cond::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_return_stmt::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_return_null_stmt::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_l_val::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_array_ident::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_number::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_primary_exp::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_unary_exp::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_func_call::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_funcr_paramlist::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_mul_exp::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_add_exp::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_rel_exp::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_eq_exp::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_l_and_exp::accept(visitor_base &v) {
        v.visit(*this);
}
void tree_l_or_exp::accept(visitor_base &v) {
        v.visit(*this);
}