%{
    #include "../../include/node.h"
    #include "../../include/error.h"
    #include <vector>
    #include <typeinfo>
    extern NODE base_node;
    extern int yyline;
    extern int yylex();
    void yyerror(const char*s){printf("ERROR:Line:%d\n%s\n",yyline,s);}
    void insertVarible(std::string& type,std::string& id);
    void insertFunction(std::string& type,std::string& id);
%}

%union{
std::string               *string;
NODE                    *node;
int                       token;
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


%type <node>        CompUnit
%type <node>            Decl
%type <node>       ConstDecl
%type <node>           BType
%type <node>        ConstExp
%type <node>        ConstDef
%type <node>    ConstDefList
%type <node>    ConstInitVal
%type <node>         VarDecl
%type <node>          VarDef
%type <node>      VarDefList
%type <node>         InitVal
%type <node>         FuncDef
%type <node>        FuncType
%type <node>           Block
%type <node>       BlockItem
%type <node>   BlockItemList
%type <node>            Stmt
%type <node>          Number
%type <node>             Exp
%type <node>            LVal
%type <node>      PrimaryExp
%type <node>        UnaryExp
%type <node>          MulExp
%type <node>          AddExp
%type <node>          RelExp
%type <node>           EqExp
%type <node>         LAndExp
%type <node>          LOrExp


%start CompUnit
%%
CompUnit
    : FuncDef 
        {base_node.add_child($1);
        WARNNING("CompUnit->FuncDef ");}
    | FuncDef CompUnit
        {base_node.add_child($1);
        WARNNING("CompUnit->FuncDef ");}
    ;

Decl          
    : ConstDecl 
        {$$ = base_node.new_node(Decl);
        $$->add_child($1);
        WARNNING("Decl->ConstDecl ");}
    | VarDecl
        {$$ = base_node.new_node(Decl);
        $$->add_child($1);
        WARNNING("Decl->VarDecl ");}
    ;
ConstDecl     
    : "const" BType ConstDefList ";"
        {$$ = base_node.new_node(ConstDecl);
        $$->add_child($2);
        $$->add_child($3);
        WARNNING("ConstDecl->const BType ConstDefList ");};
ConstDefList     
    : ConstDef
        {$$ = base_node.new_node(ConstDefList);
        $$->add_child($1);
        WARNNING("ConstDefList->ConstDef ");};
    |   ConstDef "," ConstDefList
        {$3->add_child($1);
        $$ = $3;
        WARNNING("ConstDefList->ConstDef , ConstDefList ");};;
BType         
    : "int"
        {$$ = base_node.new_node(BType);
        $$->b_type = std::string("int");
        WARNNING("BType->int ");};
ConstDef      
    : TIDENTIFIER "=" ConstInitVal
        {$$ = base_node.new_node(ConstDef);
        $$->LVal = *$1;
        $$->add_child($3);
        WARNNING("ConstDef->TIDENTIFIER = ConstInitVal ");};
    ;
ConstInitVal  
    : ConstExp
        {$$ = base_node.new_node(ConstInitVal);
        $$->add_child($1);
        WARNNING("ConstInitVal->ConstExp ");};
    ;
ConstExp
    : Exp
        {$$ = base_node.new_node(Exp);
        $$->add_child($1);
        WARNNING("ConstExp->Exp ");};
    ;
VarDecl       
    : BType VarDefList ";"
       {$$ = base_node.new_node(VarDecl);
        $$->add_child($1);
        $$->add_child($2);
        WARNNING("VarDecl->BType VarDefList ; ");}; 
    ;
VarDefList
    : VarDef
        {$$ = base_node.new_node(VarDefList);
        $$->add_child($1);
        WARNNING("VarDefList->VarDef ");};
    | VarDef "," VarDefList
        {$3->add_child($1);
        $$ = $3;
        WARNNING("VarDefList->VarDef , VarDefList ");};
    ;
VarDef        
    : TIDENTIFIER 
        {$$ = base_node.new_node(VarDef);
        $$->LVal = *$1;
        WARNNING("VarDef->TIDENTIFIER ");};
    | TIDENTIFIER "=" InitVal
        {$$ = base_node.new_node(VarDef);
        $$->LVal = *$1;
        $$->add_child($3);
        WARNNING("VarDef->TIDENTIFIER = InitVal ");};
    ;
InitVal       
    : Exp
        {$$ = base_node.new_node(InitVal);
        $$->add_child($1);
        WARNNING("InitVal->exp ");}
    ;

FuncDef
    : FuncType TIDENTIFIER "(" ")" Block 
        {$$ = base_node.new_node(FuncDef);
        $$->add_child($1);
        $$->add_child($5);
        $$->func_name = *$2;
        WARNNING("FuncDef->ftype id () block ");}
    ;
FuncType
    : "int" 
        {$$ = base_node.new_node(FuncType);
        $$->func_type = std::string("int");
        WARNNING("FuncType->int ");}
    ;

Block
    : "{" BlockItemList "}"
        {$$ = base_node.new_node(Block);
        $$->add_child($2);
        WARNNING("Block->{BlockItemList} ");}
    ;
BlockItemList
    : BlockItem
        {$$ = base_node.new_node(BlockItemList);
        $$->add_child($1);
        WARNNING("BlockItemList->BlockItem ");}
    | BlockItem BlockItemList
        {$2->add_child($1);
        $$ = $2;
        WARNNING("BlockItemList->BlockItem BlockItemList");}
    ;
BlockItem     
    : Decl 
        {$$ = base_node.new_node(BlockItem);
        $$->add_child($1);
        WARNNING("BlockItem->Decl ");}
    | Stmt
        {$$ = base_node.new_node(BlockItem);
        $$->add_child($1);
        WARNNING("BlockItem->Stmt ");}
    ;
Stmt         
    : LVal "=" Exp ";"
        {$$ = base_node.new_node(Stmt);
        $$->add_child($1);
        $$->add_child($3);
        WARNNING("Stmt->return exp ");} 
    | ";"
        {$$ = base_node.new_node(Stmt);
        WARNNING("丢弃 Stmt->; ");}
    | Exp ";"
        {$$ = base_node.new_node(Stmt);
        WARNNING("丢弃 Stmt->Exp ; ");}
    | Block
        {$$ = base_node.new_node(Stmt);
        $$->add_child($1);
        WARNNING("Stmt->Block ");}
    | "return" ";"
        {$$ = base_node.new_node(Stmt);
        WARNNING("Stmt->return; ");}
    | "return" Exp ";"
        {$$ = base_node.new_node(Stmt);
        $$->add_child($2);
        WARNNING("Stmt->return exp ");} ;
LVal         
    : TIDENTIFIER
        {$$ = base_node.new_node(LVal);
        $$->LVal = *$1;
        WARNNING("LVal->TIDENTIFIER ");};
    ;
Number
    : TINTEGER 
        {$$ = base_node.new_node(Number);
        $$->intv = atoi($1->c_str());
        WARNNING("Number->integer ");} 
    ;
PrimaryExp
    : "(" Exp ")" 
        {$$ = base_node.new_node(PrimaryExp);
        $$->add_child($2);
        WARNNING("PrimaryExp->(exp) ");}
    | LVal 
        {$$ = base_node.new_node(PrimaryExp);
        $$->add_child($1);
        WARNNING("PrimaryExp->LVal ");} 
    | Number 
        {$$ = base_node.new_node(PrimaryExp);
        $$->add_child($1);
        WARNNING("PrimaryExp->(num) ");} 
    ;
Exp
    : LOrExp 
        {$$ = base_node.new_node(Exp);
        $$->add_child($1);
        WARNNING("Exp->lorexp ");} 
    ;
UnaryExp
    : PrimaryExp  
        {$$ = base_node.new_node(UnaryExp);
        $$->add_child($1);
        WARNNING("UnaryExp->PrimaryExp ");} 
    | "+" UnaryExp 
        {$$ = base_node.new_node(UnaryExp);
        $$->add_child($2);
        $$->op = "+";
        WARNNING("UnaryExp-> + UnaryExp ");}
    | "-" UnaryExp 
        {$$ = base_node.new_node(UnaryExp);
        $$->add_child($2);
        $$->op = "-";
        WARNNING("UnaryExp-> - UnaryExp ");}
    | "!" UnaryExp
        {$$ = base_node.new_node(UnaryExp);
        $$->add_child($2);
        $$->op = "!";
        WARNNING("UnaryExp-> ! UnaryExp ");} 
    ;
MulExp
    : UnaryExp 
        {$$ = base_node.new_node(MulExp);
        $$->add_child($1);
        WARNNING("MulExp->UnaryExp ");}
    | MulExp "*" UnaryExp 
        {$$ = base_node.new_node(MulExp);
        $$->add_child($1);
        $$->op = "*";
        $$->add_child($3);
        WARNNING("MulExp->MulExp * UnaryExp ");}
    | MulExp "/" UnaryExp 
        {$$ = base_node.new_node(MulExp);
        $$->add_child($1);
        $$->op = "/";
        $$->add_child($3);
        WARNNING("MulExp->MulExp / UnaryExp ");}
    | MulExp "%" UnaryExp 
        {$$ = base_node.new_node(MulExp);
        $$->add_child($1);
        $$->op = "%";
        $$->add_child($3);
        WARNNING("MulExp->MulExp %% UnaryExp ");}
    ;
AddExp
    : MulExp 
        {$$ = base_node.new_node(AddExp);
        $$->add_child($1);
        WARNNING("AddExp->MulExp ");} 
    | AddExp "+" MulExp 
        {$$ = base_node.new_node(AddExp);
        $$->add_child($1);
        $$->op = "+";
        $$->add_child($3);
        WARNNING("AddExp->AddExp + MulExp");} 
    | AddExp "-" MulExp 
        {$$ = base_node.new_node(AddExp);
        $$->add_child($1);
        $$->op = "-";
        $$->add_child($3);
        WARNNING("AddExp->AddExp - MulExp ");} 
    ;
RelExp
    : AddExp  
        {$$ = base_node.new_node(RelExp);
        $$->add_child($1);
        WARNNING("RelExp->AddExp ");} 
    | RelExp "<" AddExp 
        {$$ = base_node.new_node(RelExp);
        $$->add_child($1);
        $$->op = "<";
        $$->add_child($3);
        WARNNING("RelExp->RelExp < AddExp ");} 
    | RelExp ">" AddExp 
        {$$ = base_node.new_node(RelExp);
        $$->add_child($1);
        $$->op = ">";
        $$->add_child($3);
        WARNNING("RelExp->RelExp > AddExp ");} 
    | RelExp "<=" AddExp 
        {$$ = base_node.new_node(RelExp);
        $$->add_child($1);
        $$->op = "<=";
        $$->add_child($3);
        WARNNING("RelExp->RelExp <= AddExp ");} 
    | RelExp ">=" AddExp 
        {$$ = base_node.new_node(RelExp);
        $$->add_child($1);
        $$->op = ">=";
        $$->add_child($3);
        WARNNING("RelExp->RelExp >= AddExp ");} 
    ;
EqExp
    : RelExp  
        {$$ = base_node.new_node(EqExp);
        $$->add_child($1);
        WARNNING("EqExp->RelExp ");} 
    | EqExp "==" RelExp 
        {$$ = base_node.new_node(EqExp);
        $$->add_child($1);
        $$->op = "==";
        $$->add_child($3);
        WARNNING("EqExp->EqExp == RelExp ");} 
    | EqExp "!=" RelExp 
        {$$ = base_node.new_node(EqExp);
        $$->add_child($1);
        $$->op = "!=";
        $$->add_child($3);
        WARNNING("EqExp->EqExp != RelExp ");} 
    ;
LAndExp
    : EqExp 
        {$$ = base_node.new_node(LAndExp);
        $$->add_child($1);
        WARNNING("LAndExp->EqExp ");} 
    | LAndExp "&&" EqExp 
        {$$ = base_node.new_node(LAndExp);
        $$->add_child($1);
        $$->op = "&&";
        $$->add_child($3);
        WARNNING("LAndExp->LAndExp && EqExp ");} 
    ;
LOrExp
    : LAndExp 
        {$$ = base_node.new_node(LOrExp);
        $$->add_child($1);
        WARNNING("LOrExp->LAndExp ");} 
    | LOrExp "||" LAndExp
        {$$ = base_node.new_node(LOrExp);
        $$->add_child($1);
        $$->op = "||";
        $$->add_child($3);
        WARNNING("LOrExp->LOrExp || LAndExp ");}  
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
