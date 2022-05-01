//
// Created by yonchicy on 22-5-1.
//

#include "visitor_base.h"
#include "syntax_tree.h"
#include "utils.h"
void visitor_base::visit(syntax_tree_node &node) {
  TRACE("visiting base node");
}
void visitor_base::visit(compile_unit &node) {
  TRACE("visiting compile unit node");
}
