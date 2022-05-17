#include "visitor/syntax_tree_builder.h"
#include "visitor/syntax_tree_shower.h"
#include "visitor/syntax_detail_shower.h"
#include "visitor/visitor_base.h"
#include <cstdio>
#include <cstring>
#include <getopt.h>
#include <iostream>
extern int yyparse();
extern int yyrestart(FILE *);
extern FILE *yyin;
int yyline;
tree_comp_unit *root;
//std::shared_ptr<tree_comp_unit> root(new tree_comp_unit());

FILE *output;
int main(int argc, char *argv[]) {
    //     处理input_file
    if (argc < 2) {
        yyparse();
        return 0;
    }
    char *input_file = nullptr, *output_file = nullptr;
    for (int ch; (ch = getopt(argc, argv, "O:So:")) != -1;) {
        switch (ch) {
            case 'S':
                break;// 啥也不干，为了测评机
            case 'o':
                output_file = strdup(optarg);
                break;
            case 'O':
                break;
            default:
                break;
        }
    }
    input_file = argv[argc - 1];
    yyin = fopen(input_file, "r");
    if (output_file != nullptr) {
        output = fopen(output_file, "w");
    } else {
        output = stdout;
    }
    if (!yyin)
        perror(input_file);
    yyparse();
    syntax_tree_shower *md_shower = new syntax_tree_shower();
    syntax_detail_shower *md_detail_shower = new syntax_detail_shower();
    md_shower->visit(*root);
    syntax_tree_builder* builder = new syntax_tree_builder();

    md_detail_shower->visit(*root);
    return 0;
}
