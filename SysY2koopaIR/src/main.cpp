
#include <getopt.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include "error.h"
#include "node.h"
#include "frontend/parser.h"

extern int yyparse();
extern int     yyrestart(FILE*);
extern FILE *yyin;
int yyline;
extern NODE base_node;
extern NODE base_ir;
FILE *output;
int main(int argc,char* argv[]){
    // 处理input_fil
    if (argc<2) {
        yyparse();
        return 0;
    }
    char *input_file = nullptr, *output_file = nullptr;
    for(int ch; (ch = getopt(argc, argv, "O:So:")) != -1;)
    {
        switch(ch)
        {
            case 'S':
                break; // 啥也不干，为了测评机
            case 'o':
                output_file = strdup(optarg);
                break;
            case 'O':
                break;
            default:
                break;
        }
    }
    input_file = argv[argc-1];
    yyin = fopen(input_file,"r");
    if(output_file!= nullptr){
        output = fopen(output_file,"w"); } else{
        output = stdout;
    }
    if(!yyin)
        perror(input_file);
    yyparse();
    std::cout<<std::endl;
    show_ast(&base_node,0);
    ast_to_ir(&base_node,0);
    show_ir(&base_ir,0);
    return 0;
}
