//
// Created by yonchicy on 22-5-1.
//

#include "syntax_tree.h"
#include "visitor/visitor_base.h"
void syntax_tree_node::accept(visitor_base &v) {
    v.visit(*this);
}
void compile_unit::accept(visitor_base &v) {
    v.visit(*this);
}
