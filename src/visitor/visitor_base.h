//
// Created by yonchicy on 22-5-1.
//

#ifndef CAROLCC_VISITOR_BASE_H
#define CAROLCC_VISITOR_BASE_H

class syntax_tree_node;
class compile_unit;
class visitor_base{
public:
  virtual void  visit(syntax_tree_node&);
  virtual void  visit(compile_unit&);
};
#endif // CAROLCC_VISITOR_BASE_H
