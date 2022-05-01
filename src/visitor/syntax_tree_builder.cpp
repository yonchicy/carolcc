//
// Created by Administrator on 2022/5/1.
//
#include "syntax_tree_builder.h"
#include "utils.h"
void syntax_tree_builder::visit(syntax_tree_node &node) {
    ERROR("visiting syntax tree node!! ");
    exit(1);
}

void syntax_tree_builder::visit(comp_unit &node) {
    for (auto t: node.functions) {
        t->accept(*this);
    }
}
void syntax_tree_builder::visit(func_def &node) {

}
