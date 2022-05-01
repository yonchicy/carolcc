//
// Created by yonchicy on 22-5-1.
//

#ifndef CAROLCC_SYNTAX_TREE_H
#define CAROLCC_SYNTAX_TREE_H

class visitor_base;

class syntax_tree_node {
public:
  virtual void accept(visitor_base& );

};
class compile_unit : public syntax_tree_node{
public:
    void accept(visitor_base& ) override;

};

#endif // CAROLCC_SYNTAX_TREE_H
