%{
    #include "node.h"
    #include "visitor/syntax_tree_builder.h"
    #include "helpers/type_helper.h"
    #include "syntax_tree.h"
    #include "error.h"
    #include <vector>
    #include <typeinfo>
    extern NODE base_node;
    extern tree_comp_unit *root;

    extern int yyline;
    extern int yylex();
    void yyerror(const char*s){printf("ERROR:Line:%d\n%s\n",yyline,s);}
    void insertVarible(std::string& type,std::string& id);
    void insertFunction(std::string& type,std::string& id);
%}

%union{
std::string            *string;
NODE                   *node;
int                    token;
tree_comp_unit         *comp_unit;
tree_func_def          *func_def;
tree_block             *block;
tree_const_decl        *const_decl;
tree_basic_type        *basic_type;
tree_const_def_list    *const_def_list;
tree_const_init_val    *const_init_val;
tree_const_exp         *const_exp;
tree_var_decl          *var_decl;
tree_exp               *exp;
tree_init_val          *init_val;
tree_decl              *decl;
tree_const_def         *const_def;
tree_var_def_list      *var_def_list;
tree_var_def           *var_def;
tree_func_type         *func_type;
tree_block_item_list   *block_item_list;
tree_block_item        *block_item;
tree_stmt              *stmt;
tree_assign_stmt       *assign_stmt;
tree_return_stmt       *return_stmt;
tree_return_null_stmt  *return_null_stmt;
tree_l_val             *l_val;
tree_number            *number;
tree_primary_exp       *primary_exp;
tree_unary_exp         *unary_exp;
tree_mul_exp           *mul_exp;
tree_add_exp           *add_exp;
tree_rel_exp           *rel_exp;
tree_eq_exp            *eq_exp;
tree_l_and_exp         *l_and_exp;
tree_l_or_exp          *l_or_exp;

}

%token <string>        TIDENTIFIER TINTEGER
%token TSEMICOLOM ";"
%token TCOMMA ","
%token TMAIN    "main"
%token TINT     "int"
%token TRETURN  "return" 
%token TCONST   "const"
%token TLBPAREN "{" 
%token TRBPAREN "}" 
%token TMINUS   "-" 
%token TNOT     "!" 
%token TWAVE    "~" 
%token TPLUS    "+" 
%token TDIV     "/" 
%token TMOD     "%" 
%token TMULTI   "*" 
%token TLPAREN  "("
%token TRPAREN  ")"
%token TLMPAREN "["
%token TRMPAREN "]"
%token TL       "<"
%token TLE      "<="
%token TG       ">"
%token TGE      ">="
%token TNE      "!="
%token TE       "=="
%token TLOGAND  "&&"
%token TLOGOR   "||"
%token TASSIGN  "="


%type <tree_comp_unit>        CompUnit
%type <decl>             Decl
%type <const_decl>       ConstDecl
%type <basic_type>           BType
%type <const_exp>        ConstExp
%type <const_def>        ConstDef
%type <const_def_list>   ConstDefList
%type <const_init_val>   ConstInitVal
%type <var_decl>         VarDecl
%type <var_def>          VarDef
%type <var_def_list>      VarDefList
%type <init_val>         InitVal
%type <func_def>         FuncDef
%type <func_type>        FuncType
%type <block>            Block
%type <block_item>       BlockItem
%type <block_item_list>  BlockItemList
%type <stmt>             Stmt
%type <number>           Number
%type <exp>              Exp
%type <l_val>            LVal
%type <primary_exp>      PrimaryExp
%type <unary_exp>        UnaryExp
%type <mul_exp>          MulExp
%type <add_exp>          AddExp
%type <rel_exp>          RelExp
%type <eq_exp>           EqExp
%type <l_and_exp>        LAndExp
%type <l_or_exp>         LOrExp


%start CompUnit
%%
CompUnit
    : FuncDef 
        {
		root->functions.push_back(std::shared_ptr<tree_func_def>($1));
        }
    | CompUnit FuncDef
        {
		root->functions.push_back(std::shared_ptr<tree_func_def>($2));
        }
    ;

Decl          
    : ConstDecl {
        $$ = new tree_decl();
        $$->const_decl=std::shared_ptr<tree_const_decl>($1);
        }
    | VarDecl {
        $$ = new tree_decl();
        $$->var_decl=std::shared_ptr<tree_var_decl>($1);
        }
    ;
ConstDecl
    : "const" BType ConstDefList ";" {
        $$ = new tree_const_decl();
        $$->b_type=std::shared_ptr<tree_basic_type>($2);
        $$->const_def_list=std::shared_ptr<tree_const_def_list>($3);
        }
        ;
ConstDefList     
    : ConstDef
        {$$ = new tree_const_def_list();
        $$->const_defs.push_back(std::shared_ptr<tree_const_def>($1));
        }
    |   ConstDefList "," ConstDef
        {$1->const_defs.push_back(std::shared_ptr<tree_const_def>($3));
        $$ = $1;
        };
BType         
    : "int"
        {$$ = new tree_basic_type();
        $$->type=type_helper::INT;
        };
ConstDef      
    : TIDENTIFIER "=" ConstInitVal
        {$$ = new tree_const_def();
        $$->id=*$1;
        $$->const_init_val=std::shared_ptr<tree_const_init_val>($3);
        };

ConstInitVal  
    : ConstExp
        {$$ = new tree_const_init_val();
    $$->const_exp= std::shared_ptr<tree_const_exp>($1) ;
        };

ConstExp
    : Exp
        {$$ =new tree_const_exp();
    $$->exp=std::shared_ptr<tree_exp>($1) ;
        };

VarDecl       
    : BType VarDefList ";"
       {$$ = new tree_var_decl();
        $$->b_type=std::shared_ptr<tree_basic_type>($1);
        $$->var_def_list=std::shared_ptr<tree_var_def_list>($2);
        }; 

VarDefList
    : VarDef
        {$$ = new tree_var_def_list(); 
        $$->var_defs.push_back(std::shared_ptr<tree_var_def>($1));
        }
    |  VarDefList "," VarDef
        {$1->var_defs.push_back(std::shared_ptr<tree_var_def>($3));
        $$ = $1;
        };

VarDef        
    : TIDENTIFIER 
        {$$ = new tree_var_def();
        $$->id=*$1;
        }
    | TIDENTIFIER "=" InitVal
        {$$ = new tree_var_def();
        $$->id=*$1;
        $$->init_val=std::shared_ptr<tree_init_val>($3);
        };

InitVal       
    : Exp
        {$$ = new tree_init_val();
        $$->exp=std::shared_ptr<tree_exp>($1);
        }
    ;

FuncDef
    : FuncType TIDENTIFIER "(" ")" Block 
        {$$ = new tree_func_def();
        $$->type=type_helper::INT;
        $$->id=*$2;
        $$->block.push_back(std::shared_ptr<tree_block>($5));
        }
    ;
FuncType
    : "int" 
        {$$ = new tree_func_type();
        $$->type=type_helper::INT;
        }
    ;

Block
    : "{" BlockItemList "}"
        {$$ = new tree_block();
        $$->block_item_list=std::shared_ptr<tree_block_item_list>($2);
        }
    ;
BlockItemList
    : BlockItem
        {
        $$ = new tree_block_item_list();
        $$->block_items.push_back(std::shared_ptr<tree_block_item>($1));
        }
    |  BlockItemList BlockItem
        {
        $1->block_items.push_back(std::shared_ptr<tree_block_item>($2));
        $$=$1;}
    ;
BlockItem     
    : Decl 
        {
        $$ = new tree_block_item();
        $$->decl=std::shared_ptr<tree_decl>($1);
        }
    | Stmt
        {
        $$ = new tree_block_item();
        $$ = new tree_block_item();
        $$->stmt=std::shared_ptr<tree_stmt>($1);
        }
    ;
Stmt         
    : LVal "=" Exp ";"
        {$$ = new tree_stmt();
        auto a_stmt = new tree_assign_stmt();
        a_stmt->l_val=std::shared_ptr<tree_l_val>($1);
        a_stmt->exp=std::shared_ptr<tree_exp>($3);
        $$->assigm_stmt=std::shared_ptr<tree_assign_stmt>(a_stmt) ;
        } 
    | ";"
        {$$ = new tree_stmt();
        } 
    | Exp ";"
        {$$ = new tree_stmt();
        $$->exp=std::shared_ptr<tree_exp>($1) ;
        } 
    | Block
        {$$ = new tree_stmt();
        $$->block=std::shared_ptr<tree_block>($1) ;
        } 
    | "return" ";"
        {$$ = new tree_stmt();
        auto a_stmt = new tree_return_null_stmt();
        $$->return_null_stmt=std::shared_ptr<tree_return_null_stmt>(a_stmt) ;
        } 
    | "return" Exp ";"
        {$$ = new tree_stmt();
        auto a_stmt = new tree_return_stmt();
        a_stmt->exp=std::shared_ptr<tree_exp>($2);
        $$->return_stmt=std::shared_ptr<tree_return_stmt>(a_stmt) ;
        }; 
LVal
    : TIDENTIFIER
        {$$ = new tree_l_val();
        $$->id = *$1;
        };

Number
    : TINTEGER 
        {$$ = new tree_number();
        $$->value = atoi($1->c_str());
        } 
    ;
PrimaryExp
    : "(" Exp ")" 
        {$$ = new tree_primary_exp();
        $$->exp=std::shared_ptr<tree_exp>($2);
        }
    | LVal 
        {$$ = new tree_primary_exp();
        $$->l_val=std::shared_ptr<tree_l_val>($1);
        }
    | Number 
        {$$ = new tree_primary_exp();
        $$->number=std::shared_ptr<tree_number>($1);
        }
    ;
Exp
    : LOrExp 
        {$$ = new tree_exp();
        $$->l_or_exp=std::shared_ptr<tree_l_or_exp>($1);
        } 
    ;
UnaryExp
    : PrimaryExp  
        {$$ = new tree_unary_exp();
        $$->primary_exp=std::shared_ptr<tree_primary_exp>($1);
        } 
    | "+" UnaryExp 
        {$$ = new tree_unary_exp();
        $$->unary_exp=std::shared_ptr<tree_unary_exp>($2);
        $$->oprt="+";
        } 
    | "-" UnaryExp 
        {$$ = new tree_unary_exp();
        $$->unary_exp=std::shared_ptr<tree_unary_exp>($2);
        $$->oprt="-";
        } 
    | "!" UnaryExp
        {$$ = new tree_unary_exp();
        $$->unary_exp=std::shared_ptr<tree_unary_exp>($2);
        $$->oprt="!";
        } 
    ;
MulExp
    : UnaryExp 
        {$$ = new tree_mul_exp();
        $$->unary_exp=std::shared_ptr<tree_unary_exp>($1);
        }
    | MulExp "*" UnaryExp 
        {$$ = new tree_mul_exp();
        $$->mul_exp=std::shared_ptr<tree_mul_exp>($1);
        $$->unary_exp=std::shared_ptr<tree_unary_exp>($3);
        $$->oprt="*";
        }
    | MulExp "/" UnaryExp 
        {$$ = new tree_mul_exp();
        $$->mul_exp=std::shared_ptr<tree_mul_exp>($1);
        $$->unary_exp=std::shared_ptr<tree_unary_exp>($3);
        $$->oprt="/";
        }
    | MulExp "%" UnaryExp 
        {$$ = new tree_mul_exp();
        $$->mul_exp=std::shared_ptr<tree_mul_exp>($1);
        $$->unary_exp=std::shared_ptr<tree_unary_exp>($3);
        $$->oprt="%";
        }
    ;
AddExp
    : MulExp 
        {$$ = new tree_add_exp();
        $$->mul_exp=std::shared_ptr<tree_mul_exp>($1);
        }
    | AddExp "+" MulExp 
        {$$ = new tree_add_exp();
        $$->add_exp=std::shared_ptr<tree_add_exp>($1);
        $$->oprt="+";
        $$->mul_exp=std::shared_ptr<tree_mul_exp>($3);
        }
    | AddExp "-" MulExp 
        {$$ = new tree_add_exp();
        $$->add_exp=std::shared_ptr<tree_add_exp>($1);
        $$->oprt="-";
        $$->mul_exp=std::shared_ptr<tree_mul_exp>($3);
        }
    ;
RelExp
    : AddExp  
        {$$ = new tree_rel_exp();
        $$->add_exp=std::shared_ptr<tree_add_exp>($1);
        }
    | RelExp "<" AddExp 
        {$$ = new tree_rel_exp();
        $$->rel_exp=std::shared_ptr<tree_rel_exp>($1);
        $$->oprt="<";
        $$->add_exp=std::shared_ptr<tree_add_exp>($3);
        }
    | RelExp ">" AddExp 
        {$$ = new tree_rel_exp();
        $$->rel_exp=std::shared_ptr<tree_rel_exp>($1);
        $$->oprt=">";
        $$->add_exp=std::shared_ptr<tree_add_exp>($3);
        }
    | RelExp "<=" AddExp 
        {$$ = new tree_rel_exp();
        $$->rel_exp=std::shared_ptr<tree_rel_exp>($1);
        $$->oprt="<=";
        $$->add_exp=std::shared_ptr<tree_add_exp>($3);
        }
    | RelExp ">=" AddExp 
        {$$ = new tree_rel_exp();
        $$->rel_exp=std::shared_ptr<tree_rel_exp>($1);
        $$->oprt=">=";
        $$->add_exp=std::shared_ptr<tree_add_exp>($3);
        }
    ;
EqExp
    : RelExp  
        {$$ = new tree_eq_exp();
        $$->rel_exp=std::shared_ptr<tree_rel_exp>($1);
        } 
    | EqExp "==" RelExp 
        {$$ = new tree_eq_exp();
        $$->eq_exp=std::shared_ptr<tree_eq_exp>($1);
        $$->oprt="==";
        $$->rel_exp=std::shared_ptr<tree_rel_exp>($3);
        }
    | EqExp "!=" RelExp 
        {$$ = new tree_eq_exp();
        $$->eq_exp=std::shared_ptr<tree_eq_exp>($1);
        $$->oprt="!=";
        $$->rel_exp=std::shared_ptr<tree_rel_exp>($3);
        }
    ;
LAndExp
    : EqExp 
        {$$ = new tree_l_and_exp();
        $$->eq_exp=std::shared_ptr<tree_eq_exp>($1);
        }
    | LAndExp "&&" EqExp 
        {$$ = new tree_l_and_exp();
        $$->l_and_exp=std::shared_ptr<tree_l_and_exp>($1);
        $$->eq_exp=std::shared_ptr<tree_eq_exp>($3);
        }
    ;
LOrExp
    : LAndExp 
        {$$ = new tree_l_or_exp();
        $$->l_and_exp=std::shared_ptr<tree_l_and_exp>($1);
        }
    | LOrExp "||" LAndExp
        {$$ = new tree_l_or_exp();
        $$->l_or_exp=std::shared_ptr<tree_l_or_exp>($1);
        $$->l_and_exp=std::shared_ptr<tree_l_and_exp>($3);
        }
    ;
%%
void insertVarible(std::string& type,std::string& id){
    VaribleTable.insert(std::make_pair<std::string, VaribleInfo>(std::string(id),VaribleInfo(type)));
}
void insertFunction(std::string& type,std::string& id){
    FunctionTable.insert(
        std::make_pair<std::string, FunctionInfo>
            (std::string(id),FunctionInfo(type,VaribleTable)));
    VaribleTable.clear();
}
