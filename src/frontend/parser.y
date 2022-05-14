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
tree_const_val_list    *const_init_val_list;
tree_const_exp_list    *const_exp_list;
tree_const_exp         *const_exp;
tree_var_decl          *var_decl;
tree_exp               *exp;
tree_init_val          *init_val;
tree_init_val_array    *init_val_array;
tree_init_val_arraylist *init_val_arraylist;
tree_func_fparams      *func_fparams;
tree_func_fparam       *func_fparam;
tree_func_fparamone    *func_fparamone;
tree_func_fparamarray  *func_fparamarray;
tree_decl              *decl;
tree_const_def         *const_def;
tree_var_def_list      *var_def_list;
tree_var_def           *var_def;
tree_func_type         *func_type;
tree_block_item_list   *block_item_list;
tree_block_item        *block_item;
tree_stmt              *stmt;
tree_assign_stmt       *assign_stmt;
tree_if_stmt           *if_stmt;
tree_if_else_stmt      *if_else_stmt;
tree_while_stmt        *while_stmt;
tree_break_stmt        *break_stmt;
tree_continue_stmt     *continue_stmt;
tree_cond              *cond;
tree_return_stmt       *return_stmt;
tree_return_null_stmt  *return_null_stmt;
tree_l_val             *l_val;
tree_array_ident       *array_ident;
tree_number            *number;
tree_primary_exp       *primary_exp;
tree_unary_exp         *unary_exp;
tree_func_call         *func_call;
tree_funcr_paramlist   *funcr_paramlist;
tree_mul_exp           *mul_exp;
tree_add_exp           *add_exp;
tree_rel_exp           *rel_exp;
tree_eq_exp            *eq_exp;
tree_l_and_exp         *l_and_exp;
tree_l_or_exp          *l_or_exp;

}

%token <string>        TIDENTIFIER TINTEGER
%token TSEMICOLOM ";"
%token TCOMMA   ","
%token TMAIN    "main"
%token TINT     "int"
%token TFLOAT   "float"
%token TVOID    "void"
%token TRETURN  "return"
%token TCONST   "const"
%token TBREAK   "break"
%token TCONTINUE"continue"
%token TIF      "if"
%token TELSE    "else"
%token TWHILE   "while"
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


%type <comp_unit>        CompUnit
%type <decl>             Decl
%type <const_decl>       ConstDecl
%type <basic_type>       BType
%type <const_exp>        ConstExp
%type <const_def>        ConstDef
%type <const_def_list>   ConstDefList
%type <const_exp_list>   ConstExpArrayList
%type <const_init_val>   ConstInitVal
%type <const_init_val_list>   ConstInitVallist
%type <var_decl>         VarDecl
%type <var_def>          VarDef
%type <var_def_list>     VarDefList
%type <init_val>         InitVal
%type <init_val_array>   InitValArray
%type <init_val_arraylist>InitValArrayList
%type <func_def>         FuncDef
%type<func_fparams>      FuncFParams
%type<func_fparam>       FuncFParam
%type<func_fparamone>    FuncFParamOne
%type<func_fparamarray>  FuncFParamArray
%type <func_type>        FuncType
%type <block>            Block
%type <block_item>       BlockItem
%type <block_item_list>  BlockItemList
%type <stmt>             Stmt
%type <cond>             Cond
%type <number>           Number
%type <exp>              Exp
%type <l_val>            LVal
%type <array_ident>      ArrayIdent
%type <primary_exp>      PrimaryExp
%type <unary_exp>        UnaryExp
%type <func_call>        FuncCall
%type <funcr_paramlist>  FuncRParamList
%type <mul_exp>          MulExp
%type <add_exp>          AddExp
%type <rel_exp>          RelExp
%type <eq_exp>           EqExp
%type <l_and_exp>        LAndExp
%type <l_or_exp>         LOrExp


%start CompUnit
%%
//jyx
CompUnit
    : FuncDef
        {
		    root->functions.push_back(std::shared_ptr<tree_func_def>($1));
        }
    | CompUnit FuncDef
        {
		    root->functions.push_back(std::shared_ptr<tree_func_def>($2));
        }
    | Decl
        {
            root->functions.push_back(std::shared_ptr<tree_decl>($1));
        }
    | CompUnit Decl
        {
            root->functions.push_back(std::shared_ptr<tree_decl>($2));
        }
    ;

Decl
    : ConstDecl 
        {
            $$ = new tree_decl();
            $$->const_decl=std::shared_ptr<tree_const_decl>($1);
        }
    | VarDecl 
        {
            $$ = new tree_decl();
            $$->var_decl=std::shared_ptr<tree_var_decl>($1);
        }
    ;

ConstDecl
    : "const" BType ConstDefList ";" 
        {
            $$ = new tree_const_decl();
            $$->b_type=std::shared_ptr<tree_basic_type>($2);
            $$->const_def_list=std::shared_ptr<tree_const_def_list>($3);
        }
    ;

ConstDefList
    : ConstDef
        {
            $$ = new tree_const_def_list();
            $$->const_defs.push_back(std::shared_ptr<tree_const_def>($1));
        }
    | ConstDefList "," ConstDef
        {
            $1->const_defs.push_back(std::shared_ptr<tree_const_def>($3));
            $$ = $1;
        }
    ;

BType
    : "int"
        {
            $$ = new tree_basic_type();
            $$->type=type_helper::INT;
        }
    | "float"
        {
            $$ = new tree_basic_type();
            $$->type=type_helper::FLOAT;
        }
    ;

ConstDef
    : TIDENTIFIER ConstExpArrayList "=" ConstInitVal
        {
            $$ = new tree_const_def();
            $$->id=*$1;
            $$->const_exp_list=std::shared_ptr<tree_const_exp_list>($2);
            $$->const_init_val=std::shared_ptr<tree_const_init_val>($4);
        }
    | TIDENTIFIER "=" ConstInitVal
        {
            $$ = new tree_const_def();
            $$->id=*$1;
            $$->const_init_val=std::shared_ptr<tree_const_init_val>($3);
        }
    ;

ConstExpArrayList
    : "[" ConstExp "]"
        {
            $$ = new tree_const_exp_list();
            $$->const_exp.push_back(std::shared_ptr<tree_const_exp>($2));
        }
    | ConstExpArrayList "[" ConstExp "]"
        {
            $1->const_exp.push_back(std::shared_ptr<tree_const_exp>($3));
            $$ = $1;
        }
    ;

ConstInitVal
    : ConstExp
        {
            $$ = new tree_const_init_val();
            $$->const_exp= std::shared_ptr<tree_const_exp>($1) ;
        }
    | "{" ConstInitVallist "}"
        {
            $$ = new tree_const_init_val();
            $$->const_exp_list= std::shared_ptr<tree_const_val_list>($2) ;
        }
    | "{"  "}"
        {
            $$ = new tree_const_init_val();
        }
    ;

ConstInitVallist
    : ConstInitVal
        {
            $$ = new tree_const_exp_list();
            $$->const_exp.push_back(std::shared_ptr<tree_const_exp>($1));
        }
    | ConstInitVallist "," ConstInitVal
        {
            $1->const_exp.push_back(std::shared_ptr<tree_const_exp>($3));
            $$ = $1;
        }
    ;

ConstExp
    : AddExp
        {
            $$ = new tree_exp();
            $$->add_exp = std::shared_ptr<tree_add_exp>($1);
        }
    ;

VarDecl
    : BType VarDefList ";"
        {    
            $$ = new tree_var_decl();
            $$->b_type=std::shared_ptr<tree_basic_type>($1);
            $$->var_def_list=std::shared_ptr<tree_var_def_list>($2);
        }
    ;

VarDefList
    : VarDef
        {
            $$ = new tree_var_def_list();
            $$->var_defs.push_back(std::shared_ptr<tree_var_def>($1));
        }
    |  VarDefList "," VarDef
        {
            $1->var_defs.push_back(std::shared_ptr<tree_var_def>($3));
            $$ = $1;
        }
    ;

VarDef
    : TIDENTIFIER
        {
            $$ = new tree_var_def();
            $$->id=*$1;
        }
    | TIDENTIFIER "=" InitVal
        {
            $$ = new tree_var_def();
            $$->id=*$1;
            $$->init_val=std::shared_ptr<tree_init_val>($3);
        }
    ;
/* wq */
InitVal
    : Exp
        {
            $$ = new tree_init_val();
            $$->exp=std::shared_ptr<tree_exp>($1);
        }
    ;

InitValArray
    : "{" "}"
        {
            $$ = new tree_init_val_array();
        }
    | "{" InitValArrayList "}"
        {
            $$ = new tree_init_val_array();
            $$->init_val_arraylist = std::shared_ptr<tree_init_val_arraylist>($2)
        }
    ;

// InitValArrayList是InitVal(AddExp)和InitValArray的任意组合
InitValArrayList
    : InitValArray
        {
            $$ = new tree_init_val_array();
            $$->initvalarrays.push_back(std::shared_ptr<tree_init_val_array>($1));
        }
    | InitValArrayList "," InitValArray
        {
            $1->initvalarrays.push_back(std::shared_ptr<tree_init_val_array>($3));
            $$ = $1;
        }
    | InitVal
        {
            $$ = new tree_init_val_array();
            $$->initvals.push_back(std::shared_ptr<tree_init_val>($1));
        }
    | InitValArrayList "," InitVal
        {
            $1->initvals.push_back(std::shared_ptr<tree_init_val>($3));
            $$ = $1;
        }
    ;

/* 函数相关 */
FuncDef
    : FuncType TIDENTIFIER "("")" Block
        {
            $$ = new tree_func_def();
            $$->type = std::shared_ptr<tree_func_type>($1);
            $$->id = *$2;
            $$->block.push_back(std::shared_ptr<tree_block>($5));
        }
    | FuncType TIDENTIFIER "(" FuncFParams ")" Block
        {
            $$ = new tree_func_def();
            $$->type = std::shared_ptr<tree_func_type>($1);
            $$->id = *$2;
            $$->funcfparams = std::shared_ptr<tree_func_fparams>($4);

            $$->block.push_back(std::shared_ptr<tree_block>($6));
        }
    ;

FuncType
    : "int"
        {
            $$ = new tree_func_type();
            $$->type=type_helper::INT;
        }
    | "float"
        {
            $$ = new tree_func_type();
            $$->type=type_helper::FLOAT;
        }
    | "void"
        {
            $$ = new tree_func_type();
            $$->type=type_helper::VOID;
        }
    ;

FuncFParams
    : FuncFParam
        {
            $$ = new tree_func_fparams();
            $$->funcfparamlist.push_back(std::shared_ptr<tree_func_fparam>($1));
        }
    | FuncFParams "," FuncFParam
        {
            $1->funcfparamlist.push_back(std::shared_ptr<tree_func_fparam>($3));
            $$ = $1;
        }
    ;

FuncFParam
    : FuncFParamOne
        {
            $$ = new tree_func_fparam();
            $$->funcfparamone = std::shared_ptr<tree_func_fparamone>($1);
        }
    | FuncFParamArray
        {
            $$ = new tree_func_fparam();
            $$->funcfparamarray = std::shared_ptr<tree_func_fparamarray>($1);
        }
    ;

FuncFParamOne
    : BType TIDENTIFIER
        {
            $$ = new tree_func_fparamone();
            $$->b_type = std::shared_ptr<tree_basic_type>($1);
            $$->id = *$2;
        }
    ;

FuncFParamArray
    : BType TIDENTIFIER "[" "]"
        {
            $$ = new tree_func_fparamarray();
            $$->b_type = std::shared_ptr<tree_basic_type>($1);
            $$->id = *$2;
        }
    | FuncFParamArray "[" Exp "]"
        {
            $1->exps.push_back(std::shared_ptr<tree_exp>($3));
            $$ = $1;
        }
    ;

Block
    : "{" "}"
        {
            $$ = new tree_block();
        }
    | "{" BlockItemList "}"
        {
            $$ = new tree_block();
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
            $$=$1;
        }
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
            $$->stmt=std::shared_ptr<tree_stmt>($1);
        }
    ;

/* 语句相关 */
Stmt
    : LVal "=" Exp ";"
        /* assign statement */
        {
            $$ = new tree_stmt();
            auto a_stmt = new tree_assign_stmt();
            a_stmt->l_val=std::shared_ptr<tree_l_val>($1);
            a_stmt->exp=std::shared_ptr<tree_exp>($3);
            $$->assigm_stmt=std::shared_ptr<tree_assign_stmt>(a_stmt) ;
        }
    | ";"
        {
            $$ = new tree_stmt();
        }
    | Exp ";"
        {
            $$ = new tree_stmt();
            $$->exp=std::shared_ptr<tree_exp>($1) ;
        }
    | Block
        {
            $$ = new tree_stmt();
            $$->block=std::shared_ptr<tree_block>($1) ;
        }
    /* if statement */
    | "if" "(" Cond ")" Stmt
        {
            $$ = new tree_stmt();
            auto if_stmt = new tree_if_stmt();
            if_stmt->cond = std::shared_ptr<tree_cond>($3);
            if_stmt->stmt = std::shared_ptr<tree_stmt>($5);
            $$->if_stmt = std::shared_ptr<tree_if_stmt>(if_stmt) ;
        }
    | "if" "(" Cond ")" Stmt "else" Stmt
        {
            $$ = new tree_stmt();
            auto if_else_stmt = new tree_if_else_stmt();
            if_else_stmt->cond = std::shared_ptr<tree_cond>($3);
            if_else_stmt->stmt1 = std::shared_ptr<tree_stmt>($5);
            if_else_stmt->stmt2 = std::shared_ptr<tree_stmt>($7);
            $$->if_else_stmt = std::shared_ptr<tree_if_else_stmt>(if_else_stmt) ;

        }
    /* while statement */
    | "while" "(" Cond ")" Stmt
        {
            $$ = new tree_stmt();
            auto while_stmt = new tree_while_stmt();
            while_stmt->cond = std::shared_ptr<tree_cond>($3);
            while_stmt->stmt = std::shared_ptr<tree_stmt>($5);
            $$->while_stmt = std::shared_ptr<tree_while_stmt>(while_stmt) ;
        }
    | "continue" ";"
        {
            $$ = new tree_stmt();
            auto continue_stmt = new tree_continue_stmt();
            $$->continue_stmt = std::shared_ptr<tree_continue_stmt>(continue_stmt) ;
        }
    | "break" ";"
        {
            $$ = new tree_stmt();
            auto break_stmt = new tree_break_stmt();
            $$->break_stmt = std::shared_ptr<tree_break_stmt>(break_stmt) ;
        }
    /* return statement */
    | "return" ";"
        {
            $$ = new tree_stmt();
            auto a_stmt = new tree_return_null_stmt();
            $$->return_null_stmt=std::shared_ptr<tree_return_null_stmt>(a_stmt) ;
        }
    | "return" Exp ";"
        {
            $$ = new tree_stmt();
            auto a_stmt = new tree_return_stmt();
            a_stmt->exp=std::shared_ptr<tree_exp>($2);
            $$->return_stmt=std::shared_ptr<tree_return_stmt>(a_stmt) ;
        }
    ;

/* 表达式相关 */
Exp
    : AddExp
        {
            $$ = new tree_exp();
            $$->add_exp = std::shared_ptr<tree_add_exp>($1);
        }
    ;

Cond
    : LOrExp
        {
            $$ = new tree_cond();
            $$->l_or_exp = std::shared_ptr<tree_l_or_exp>($1);
        }
    ;

LVal
    : TIDENTIFIER
        {
            $$ = new tree_l_val();
            $$->id = *$1;
        }
    | ArrayIdent
        {
            $$ = new tree_l_val();
            $$->array_ident = std::shared_ptr<tree_array_ident>($1);
        }
    ;

ArrayIdent
    : TIDENTIFIER "[" Exp "]"
        {
            $$ = new tree_array_ident();
            $$->id = *$1;
            $$->exp = std::shared_ptr<tree_exp>($3);
        }
    | ArrayIdent "[" Exp "]"
        {
            $1->exp = std::shared_ptr<tree_exp>($3);
            $$ = $1;
        }
    ;

Number
    : TINTEGER
        {
            $$ = new tree_number();
            $$->int_value = atoi($1->c_str());
            $$->float_value = (float)atof($1->c_str());
        }
    ;

PrimaryExp
    : "(" Exp ")"
        {
            $$ = new tree_primary_exp();
            $$->exp = std::shared_ptr<tree_exp>($2);
        }
    | LVal
        {
            $$ = new tree_primary_exp();
            $$->l_val = std::shared_ptr<tree_l_val>($1);
        }
    | Number
        {
            $$ = new tree_primary_exp();
            $$->number = std::shared_ptr<tree_number>($1);
        }
    ;

UnaryExp
    : PrimaryExp
        {
            $$ = new tree_unary_exp();
            $$->primary_exp = std::shared_ptr<tree_primary_exp>($1);
        }
    | "+" UnaryExp
        {
            $$ = new tree_unary_exp();
            $$->unary_exp=std::shared_ptr<tree_unary_exp>($2);
            $$->oprt="+";
        }
    | "-" UnaryExp
        {
            $$ = new tree_unary_exp();
            $$->unary_exp=std::shared_ptr<tree_unary_exp>($2);
            $$->oprt="-";
        }
    | "!" UnaryExp
        {
            $$ = new tree_unary_exp();
            $$->unary_exp=std::shared_ptr<tree_unary_exp>($2);
            $$->oprt="!";
        }
    /* FUNCTION CALL */
    | FuncCall
        {
            $$ = new tree_unary_exp();
            $$->func_call = std::shared_ptr<tree_func_call>($1);
        }
    ;

FuncCall
    : TIDENTIFIER "(" ")"
        {
            $$ = new tree_func_call();
            $$->id = *$1;
        }
    | TIDENTIFIER "(" FuncRParamList ")"
        {
            $$ = new tree_func_call();
            $$->id = *$1;
            $$->funcr_paramlist = std::shared_ptr<tree_funcr_paramlist>($3);
        }
    ;

FuncRParamList
    : Exp
        {
            $$ = new tree_funcr_paramlist();
            $$->exps.push_back(std::shared_ptr<tree_exp>($1));
        }
    | FuncRParamList "," Exp
        {
            $1->exps.push_back(std::shared_ptr<tree_exp>($3));
            $$ = $1;
        }
    ;
/* jyx */


MulExp
    : UnaryExp
        {
            $$ = new tree_mul_exp();
            $$->unary_exp=std::shared_ptr<tree_unary_exp>($1);
        }
    | MulExp "*" UnaryExp
        {
            $$ = new tree_mul_exp();
            $$->mul_exp=std::shared_ptr<tree_mul_exp>($1);
            $$->unary_exp=std::shared_ptr<tree_unary_exp>($3);
            $$->oprt="*";
        }
    | MulExp "/" UnaryExp
        {
            $$ = new tree_mul_exp();
            $$->mul_exp=std::shared_ptr<tree_mul_exp>($1);
            $$->unary_exp=std::shared_ptr<tree_unary_exp>($3);
            $$->oprt="/";
        }
    | MulExp "%" UnaryExp
        {
            $$ = new tree_mul_exp();
            $$->mul_exp=std::shared_ptr<tree_mul_exp>($1);
            $$->unary_exp=std::shared_ptr<tree_unary_exp>($3);
            $$->oprt="%";
        }
    ;
AddExp
    : MulExp
        {
            $$ = new tree_add_exp();
            $$->mul_exp=std::shared_ptr<tree_mul_exp>($1);
        }
    | AddExp "+" MulExp
        {
            $$ = new tree_add_exp();
            $$->add_exp=std::shared_ptr<tree_add_exp>($1);
            $$->oprt="+";
            $$->mul_exp=std::shared_ptr<tree_mul_exp>($3);
        }
    | AddExp "-" MulExp
        {
            $$ = new tree_add_exp();
            $$->add_exp=std::shared_ptr<tree_add_exp>($1);
            $$->oprt="-";
            $$->mul_exp=std::shared_ptr<tree_mul_exp>($3);
        }
    ;
RelExp
    : AddExp
        {
            $$ = new tree_rel_exp();
            $$->add_exp=std::shared_ptr<tree_add_exp>($1);
        }
    | RelExp "<" AddExp
        {
            $$ = new tree_rel_exp();
            $$->rel_exp=std::shared_ptr<tree_rel_exp>($1);
            $$->oprt="<";
            $$->add_exp=std::shared_ptr<tree_add_exp>($3);
        }
    | RelExp ">" AddExp
        {
            $$ = new tree_rel_exp();
            $$->rel_exp=std::shared_ptr<tree_rel_exp>($1);
            $$->oprt=">";
            $$->add_exp=std::shared_ptr<tree_add_exp>($3);
        }
    | RelExp "<=" AddExp
        {
            $$ = new tree_rel_exp();
            $$->rel_exp=std::shared_ptr<tree_rel_exp>($1);
            $$->oprt="<=";
            $$->add_exp=std::shared_ptr<tree_add_exp>($3);
        }
    | RelExp ">=" AddExp
        {
            $$ = new tree_rel_exp();
            $$->rel_exp=std::shared_ptr<tree_rel_exp>($1);
            $$->oprt=">=";
            $$->add_exp=std::shared_ptr<tree_add_exp>($3);
        }
    ;
EqExp
    : RelExp
        {
            $$ = new tree_eq_exp();
            $$->rel_exp=std::shared_ptr<tree_rel_exp>($1);
        }
    | EqExp "==" RelExp
        {
            $$ = new tree_eq_exp();
            $$->eq_exp=std::shared_ptr<tree_eq_exp>($1);
            $$->oprt="==";
            $$->rel_exp=std::shared_ptr<tree_rel_exp>($3);
        }
    | EqExp "!=" RelExp
        {
            $$ = new tree_eq_exp();
            $$->eq_exp=std::shared_ptr<tree_eq_exp>($1);
            $$->oprt="!=";
            $$->rel_exp=std::shared_ptr<tree_rel_exp>($3);
        }
    ;
LAndExp
    : EqExp
        {
            $$ = new tree_l_and_exp();
            $$->eq_exp=std::shared_ptr<tree_eq_exp>($1);
        }
    | LAndExp "&&" EqExp
        {
            $$ = new tree_l_and_exp();
            $$->l_and_exp=std::shared_ptr<tree_l_and_exp>($1);
            $$->eq_exp=std::shared_ptr<tree_eq_exp>($3);
        }
    ;
LOrExp
    : LAndExp
        {
            $$ = new tree_l_or_exp();
            $$->l_and_exp=std::shared_ptr<tree_l_and_exp>($1);
        }
    | LOrExp "||" LAndExp
        {
            $$ = new tree_l_or_exp();
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
