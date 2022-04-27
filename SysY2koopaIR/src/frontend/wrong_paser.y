%{
    #include "../../include/node.h"
    #include "../../include/error.h"
    #include <vector>
    NProgram *programBlock;
    extern int yyline;
    extern int yylex();
    void yyerror(const char*s){printf("ERROR:Line:%d\n%s\n",yyline,s);}
    void insertVarible(std::string& type,std::string& id);
    void insertFunction(std::string& type,std::string& id);
%}

%union{
std::string               *string;
int                       token;
}

%token <string>        TIDENTIFIER TINTEGER
%token TSEMICOLOM ";"
%token TMAIN    "main"
%token TINT     "int"
%token TRETURN  "return" 
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
%token TLMPAREN  "["
%token TRMPAREN  "]"
%token TL       "<"
%token TLE      "<="
%token TG       ">"
%token TGE      ">="
%token TNE      "!="
%token TE       "=="
%token TLOGAND  "&&"
%token TLOGOR   "||"
%token TASSIGN  "="


%type <CompUnit>         CompUnit
%type <Decl>             Decl
%type <ConstDecl>        ConstDecl
%type <BType>            BType
%type <ConstDef>         ConstDef
%type <ConstDefs>        ConstDefs
%type <ConstInitVal>     ConstInitVal
%type <ConstInitVals>    ConstInitVals
%type <VarDecl>          VarDecl
%type <VarDef>           VarDef
%type <InitVal>          InitVal
%type <FuncDef>          FuncDef
%type <FuncType>         FuncType
%type <FuncFParams>      FuncFParams
%type <FuncFParam>       FuncFParam
%type <Block>            Block
%type <BlockItem>        BlockItem
%type <Stmt>             Stmt
%type <Exp>              Exp
%type <Exps>             Exps
%type <ExpSs>            ExpSs
%type <LVal>             LVal
%type <PrimaryExp>       PrimaryExp
%type <Number>           Number
%type <UnaryExp>         UnaryExp
%type <FuncRParams>      FuncRParams
%type <MulExp>           MulExp
%type <AddExp>           AddExp
%type <RelExp>           RelExp
%type <EqExp>            EqExp
%type <LAndExp>          LAndExp
%type <LOrExp>           LOrExp
%type <ConstExp>         ConstExp
%type <ConstExps>        ConstExps


%start CompUnit
%%
CompUnit
    : Decl 
    | FuncDef
    | CompUnit Decl
    | CompUnit FuncDef
    ;

Decl          
    : ConstDecl | VarDecl;
ConstDecl     
    : "const" BType ConstDefs ";";
ConstDefs
    : ConstDef
    | ConstDefs "," ConstDef;
BType         
    : "int";
ConstDef      
    : TIDENTIFIER ConstExps "=" ConstInitVal;
ConstExp
    : Exp;
ConstExps
    : "[" ConstExp "]"
    | ConstExps "[" ConstExp "]";
ConstInitVal  
    : ConstExp 
    | "{" "}"
    | "{" ConstInitVals "}";
ConstInitVals
    : ConstInitVal
    | ConstInitVals "," ConstInitVal;
VarDecl       
    : BType VarDefs ";";
VarDefs
    : VarDef
    | VarDefs "," VarDef;
VarDef        
    : TIDENTIFIER ConstExps
    | TIDENTIFIER ConstExps "=" InitVal;
InitVal       
    : Exp | "{" "}"
    | Exp | "{" InitVals "}";
InitVals
    : InitVal
    | InitVals "," InitVal;
FuncDef
    : FuncType TIDENTIFIER "(" ")" Block
    | FuncType TIDENTIFIER "(" FuncFParams ")" Block;
FuncType
    : "void" | "int";
FuncFParams   
    : FuncFParam
    | FuncFParams "," FuncFParam;
FuncFParam    
    : BType TIDENTIFIER  
    | BType TIDENTIFIER "[" "]" ConstExps;    

Block
    : "{" BlockItems "}";
BlockItems
    : BlockItem
    | BlockItems BlockItem;
BlockItem     
    : Decl | Stmt;

Stmt
    : LVal "=" Exp ";"
    | ";"
    | Exp ";"
    | Block
    | "if" "(" Exp ")" Stmt "else" Stmt
    | "if" "(" Exp ")" Stmt
    | "while" "(" Exp ")" Stmt
    | "break" ";"
    | "continue" ";"
    |"return" Exp ";"
    ; 
Number
    : TINTEGER ;
PrimaryExp
    : "(" Exp ")" 
    | Number {printf("PrimaryExp ");} 
    | LVal
    ;
LVal          
    : TIDENTIFIER Exps;
Exps
    : "[" Exp "]"
    | Exps "[" Exp "]"
Exp
    : LOrExp {printf("Exp \n");} ;
UnaryExp
    : PrimaryExp  {printf("UnaryExp ");} 
    | "+" UnaryExp 
    | "-" UnaryExp 
    | "!" UnaryExp  
    | TIDENTIFIER "(" ")"
    | TIDENTIFIER "(" FuncRParams ")"
    ;
FuncRParams   
    : ExpSs ;
ExpSs
    : Exp
    | ExpSs "," Exp;
MulExp
    : UnaryExp {printf("MulExp ");} 
    | MulExp "*" UnaryExp {printf("MulExp ");} 
    | MulExp "/" UnaryExp {printf("MulExp ");} 
    | MulExp "%" UnaryExp {printf("MulExp ");} 
    ;
AddExp
    : MulExp {printf("AddExp ");} 
    | AddExp "+" MulExp {printf("AddExp ");} 
    | AddExp "-" MulExp {printf("AddExp ");} 
    ;
RelExp
    : AddExp  {printf("RelExp ");} 
    | RelExp "<" AddExp {printf("RelExp ");} 
    | RelExp ">" AddExp {printf("RelExp ");} 
    | RelExp "<=" AddExp {printf("RelExp ");} 
    | RelExp ">=" AddExp {printf("RelExp ");} 
    ;
EqExp
    : RelExp  {printf("EqExp ");} 
    | EqExp "==" RelExp {printf("EqExp ");} 
    | EqExp "!=" RelExp {printf("EqExp ");} 
    ;
LAndExp
    : EqExp {printf("LAndExp ");} 
    | LAndExp "&&" EqExp {printf("LAndExp ");} 
    ;
LOrExp
    : LAndExp {printf("LOrExp ");} 
    | LOrExp "||" LAndExp {printf("LOrExp ");} 
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
