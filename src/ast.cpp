#include "node.h"
#include "utils.h"
#include <cstdio>
NODE base_node = NODE();
NODE base_ir = NODE();
void test() {
    base_node.node_type = CompUnit;
    base_node.new_node(CompUnit);
}
void show_ast(const NODE *base_node, int dp) {
    for (int i = 0; i < dp - 1; i++) std::cout << "| ";
    std::cout << "├";
    std::cout << get_detail(base_node) << std::endl;
    if (base_node->node_list.size() > 0) {
        for (const NODE *node: base_node->node_list) {
            show_ast(node, dp + 1);
        }
    }
}

void ast_to_ir(const NODE *base_node, int dp) {
    if (base_node->node_type == Exp) {
        base_ir.add_child_(Exp);
        IR_exp(base_ir.IRnode_list.back(), base_node, dp);
        return;
    }
    if (base_node->node_list.size() > 0) {
        for (const NODE *node: base_node->node_list) {
            ast_to_ir(node, dp + 1);
        }
    }
}

void IR_exp(NODE *exp_node, const NODE *base_node, int dp) {
    exp_node->node_type = Exp;
    if (base_node->check_op()) {
        op_v o_v = op_v();
        o_v.op = base_node->op;
        exp_node->exp_stream.push_back(o_v);
    }
    if (base_node->node_type == Number) {
        op_v o_v = op_v();
        o_v.v = base_node->intv;
        exp_node->exp_stream.push_back(o_v);
    }
    if (base_node->node_type == LVal) {
        op_v o_v = op_v();
        o_v.lval = base_node->LVal;
        exp_node->exp_stream.push_back(o_v);
    }
    if (base_node->node_list.size() > 0) {
        for (const NODE *node: base_node->node_list) {
            IR_exp(exp_node, node, dp + 1);
        }
    }
}
int exp_pt = 0;
int tmp = 0;
op_v cal(NODE *base_node, std::vector<std::string> &cal_stream) {
    op_v arg[3];
    std::string op;
    arg[0].op = "";
    arg[0].v = -1;
    arg[0].lval = "";
    if (exp_pt >= base_node->exp_stream.size()) return arg[0];
    if (base_node->exp_stream[exp_pt].op.compare("") == 0) {
        arg[0].v = base_node->exp_stream[exp_pt].v;
        arg[0].lval = base_node->exp_stream[exp_pt++].lval;
        return arg[0];
    }
    op = base_node->exp_stream[exp_pt++].op;
    arg[1] = cal(base_node, cal_stream);
    arg[2] = cal(base_node, cal_stream);
    arg[0].op = std::string("%").append(std::to_string(tmp++));
    if (arg[0].op.compare("") != 0) {
        WARNNING(" %s", arg[0].op.c_str());
    } else if (arg[0].lval.compare("") != 0) {
        WARNNING(" %s", arg[0].lval.c_str());
    } else {
        WARNNING(" %d", arg[0].v);
    }
    WARNNING(" = %s", op.c_str());
    if (arg[1].op.compare("") != 0) {
        WARNNING(" %s,", arg[1].op.c_str());
    } else if (arg[1].lval.compare("") != 0) {
        WARNNING(" %s", arg[1].lval.c_str());
    } else {
        WARNNING(" %d,", arg[1].v);
    }
    if (arg[2].op.compare("") != 0) {
        WARNNING(" %s\n", arg[2].op.c_str());
    } else if (arg[2].lval.compare("") != 0) {
        WARNNING(" %s\n", arg[2].lval.c_str());
    } else {
        WARNNING(" %d\n", arg[2].v);
    }

    return arg[0];
}
void exp_ir_show(NODE *base_node) {
    std::vector<std::string> cal_stream;
    exp_pt = 0;
    tmp = 0;
    cal(base_node, cal_stream);
}
void show_ir(NODE *base_node, int dp) {
    if (base_node->node_type == Exp) {
        exp_ir_show(base_node);
    }
    // for(op_v arg : base_node->exp_stream){
    //   if(arg.op.compare("")!=0){ WARNNING(" %s",arg.op.c_str());}
    //   else if(arg.lval.compare("")!=0){ WARNNING(" %s",arg.lval.c_str());}
    //   else{ WARNNING(" %d",arg.v);}
    // }
    if (base_node->IRnode_list.size() > 0) {
        for (NODE *node: base_node->IRnode_list) {
            show_ir(node, dp + 1);
        }
    }
}