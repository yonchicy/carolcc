/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include "visitor/syntax_tree_builder.h"
    #include "helpers/type_helper.h"
    #include "syntax_tree.h"
    #include "string.h"
    #include "error.h"
    #include "runtime.h"
    #include <vector>
    #include <typeinfo>
    extern tree_comp_unit *root;

    extern int yyline;
    extern int yylex();
    void yyerror(char*s)
    {
        extern char *yytext;	// defined and maintained in lex
        int len=strlen(yytext);
        int i;
        char buf[512]={0};
        for (i=0;i<len;++i)
        {
            sprintf(buf,"%s%d ",buf,yytext[i]);
        }
        fprintf(stderr, "ERROR: text %s\n",yytext);
        fprintf(stderr, "ERROR: %s at symbol '%s' on line %d\n", s, buf, yyline);
    }
    void insertVarible(std::string& type,std::string& id);
    void insertFunction(std::string& type,std::string& id);

#line 101 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TIDENTIFIER = 258,             /* TIDENTIFIER  */
    TINTEGER = 259,                /* TINTEGER  */
    TSEMICOLOM = 260,              /* ";"  */
    TCOMMA = 261,                  /* ","  */
    TMAIN = 262,                   /* "main"  */
    TINT = 263,                    /* "int"  */
    TFLOAT = 264,                  /* "float"  */
    TVOID = 265,                   /* "void"  */
    TRETURN = 266,                 /* "return"  */
    TCONST = 267,                  /* "const"  */
    TBREAK = 268,                  /* "break"  */
    TCONTINUE = 269,               /* "continue"  */
    TIF = 270,                     /* "if"  */
    TELSE = 271,                   /* "else"  */
    TWHILE = 272,                  /* "while"  */
    TLBPAREN = 273,                /* "{"  */
    TRBPAREN = 274,                /* "}"  */
    TMINUS = 275,                  /* "-"  */
    TNOT = 276,                    /* "!"  */
    TWAVE = 277,                   /* "~"  */
    TPLUS = 278,                   /* "+"  */
    TDIV = 279,                    /* "/"  */
    TMOD = 280,                    /* "%"  */
    TMULTI = 281,                  /* "*"  */
    TLPAREN = 282,                 /* "("  */
    TRPAREN = 283,                 /* ")"  */
    TLMPAREN = 284,                /* "["  */
    TRMPAREN = 285,                /* "]"  */
    TL = 286,                      /* "<"  */
    TLE = 287,                     /* "<="  */
    TG = 288,                      /* ">"  */
    TGE = 289,                     /* ">="  */
    TNE = 290,                     /* "!="  */
    TE = 291,                      /* "=="  */
    TLOGAND = 292,                 /* "&&"  */
    TLOGOR = 293,                  /* "||"  */
    TASSIGN = 294                  /* "="  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"

std::string            *string;
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
tree_arrray_def        *array_def;
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


#line 242 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TIDENTIFIER = 3,                /* TIDENTIFIER  */
  YYSYMBOL_TINTEGER = 4,                   /* TINTEGER  */
  YYSYMBOL_TSEMICOLOM = 5,                 /* ";"  */
  YYSYMBOL_TCOMMA = 6,                     /* ","  */
  YYSYMBOL_TMAIN = 7,                      /* "main"  */
  YYSYMBOL_TINT = 8,                       /* "int"  */
  YYSYMBOL_TFLOAT = 9,                     /* "float"  */
  YYSYMBOL_TVOID = 10,                     /* "void"  */
  YYSYMBOL_TRETURN = 11,                   /* "return"  */
  YYSYMBOL_TCONST = 12,                    /* "const"  */
  YYSYMBOL_TBREAK = 13,                    /* "break"  */
  YYSYMBOL_TCONTINUE = 14,                 /* "continue"  */
  YYSYMBOL_TIF = 15,                       /* "if"  */
  YYSYMBOL_TELSE = 16,                     /* "else"  */
  YYSYMBOL_TWHILE = 17,                    /* "while"  */
  YYSYMBOL_TLBPAREN = 18,                  /* "{"  */
  YYSYMBOL_TRBPAREN = 19,                  /* "}"  */
  YYSYMBOL_TMINUS = 20,                    /* "-"  */
  YYSYMBOL_TNOT = 21,                      /* "!"  */
  YYSYMBOL_TWAVE = 22,                     /* "~"  */
  YYSYMBOL_TPLUS = 23,                     /* "+"  */
  YYSYMBOL_TDIV = 24,                      /* "/"  */
  YYSYMBOL_TMOD = 25,                      /* "%"  */
  YYSYMBOL_TMULTI = 26,                    /* "*"  */
  YYSYMBOL_TLPAREN = 27,                   /* "("  */
  YYSYMBOL_TRPAREN = 28,                   /* ")"  */
  YYSYMBOL_TLMPAREN = 29,                  /* "["  */
  YYSYMBOL_TRMPAREN = 30,                  /* "]"  */
  YYSYMBOL_TL = 31,                        /* "<"  */
  YYSYMBOL_TLE = 32,                       /* "<="  */
  YYSYMBOL_TG = 33,                        /* ">"  */
  YYSYMBOL_TGE = 34,                       /* ">="  */
  YYSYMBOL_TNE = 35,                       /* "!="  */
  YYSYMBOL_TE = 36,                        /* "=="  */
  YYSYMBOL_TLOGAND = 37,                   /* "&&"  */
  YYSYMBOL_TLOGOR = 38,                    /* "||"  */
  YYSYMBOL_TASSIGN = 39,                   /* "="  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_CompUnit = 41,                  /* CompUnit  */
  YYSYMBOL_Decl = 42,                      /* Decl  */
  YYSYMBOL_ConstDecl = 43,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 44,              /* ConstDefList  */
  YYSYMBOL_BType = 45,                     /* BType  */
  YYSYMBOL_ConstDef = 46,                  /* ConstDef  */
  YYSYMBOL_ConstExpArrayList = 47,         /* ConstExpArrayList  */
  YYSYMBOL_ConstInitVal = 48,              /* ConstInitVal  */
  YYSYMBOL_ConstInitVallist = 49,          /* ConstInitVallist  */
  YYSYMBOL_ConstExp = 50,                  /* ConstExp  */
  YYSYMBOL_VarDecl = 51,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 52,                /* VarDefList  */
  YYSYMBOL_VarDef = 53,                    /* VarDef  */
  YYSYMBOL_ArrayDef = 54,                  /* ArrayDef  */
  YYSYMBOL_InitVal = 55,                   /* InitVal  */
  YYSYMBOL_InitValArray = 56,              /* InitValArray  */
  YYSYMBOL_InitValArrayList = 57,          /* InitValArrayList  */
  YYSYMBOL_FuncDef = 58,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 59,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 60,                /* FuncFParam  */
  YYSYMBOL_FuncFParamOne = 61,             /* FuncFParamOne  */
  YYSYMBOL_FuncFParamArray = 62,           /* FuncFParamArray  */
  YYSYMBOL_Block = 63,                     /* Block  */
  YYSYMBOL_BlockItemList = 64,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 65,                 /* BlockItem  */
  YYSYMBOL_Stmt = 66,                      /* Stmt  */
  YYSYMBOL_Exp = 67,                       /* Exp  */
  YYSYMBOL_Cond = 68,                      /* Cond  */
  YYSYMBOL_LVal = 69,                      /* LVal  */
  YYSYMBOL_ArrayIdent = 70,                /* ArrayIdent  */
  YYSYMBOL_Number = 71,                    /* Number  */
  YYSYMBOL_PrimaryExp = 72,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 73,                  /* UnaryExp  */
  YYSYMBOL_FuncCall = 74,                  /* FuncCall  */
  YYSYMBOL_FuncRParamList = 75,            /* FuncRParamList  */
  YYSYMBOL_MulExp = 76,                    /* MulExp  */
  YYSYMBOL_AddExp = 77,                    /* AddExp  */
  YYSYMBOL_RelExp = 78,                    /* RelExp  */
  YYSYMBOL_EqExp = 79,                     /* EqExp  */
  YYSYMBOL_LAndExp = 80,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 81                     /* LOrExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   172,   172,   176,   180,   184,   191,   196,   204,   213,
     218,   226,   231,   236,   244,   251,   260,   265,   273,   278,
     282,   290,   295,   303,   311,   320,   325,   333,   338,   344,
     350,   360,   365,   374,   382,   386,   395,   400,   405,   410,
     419,   426,   438,   443,   451,   456,   464,   473,   479,   487,
     491,   499,   504,   512,   517,   526,   535,   539,   544,   550,
     558,   569,   577,   583,   590,   596,   607,   615,   623,   628,
     636,   642,   650,   659,   664,   669,   677,   682,   688,   694,
     701,   709,   714,   723,   728,   738,   743,   750,   757,   766,
     771,   778,   787,   792,   799,   806,   813,   822,   827,   834,
     843,   848,   856,   861
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TIDENTIFIER",
  "TINTEGER", "\";\"", "\",\"", "\"main\"", "\"int\"", "\"float\"",
  "\"void\"", "\"return\"", "\"const\"", "\"break\"", "\"continue\"",
  "\"if\"", "\"else\"", "\"while\"", "\"{\"", "\"}\"", "\"-\"", "\"!\"",
  "\"~\"", "\"+\"", "\"/\"", "\"%\"", "\"*\"", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"", "\"!=\"", "\"==\"",
  "\"&&\"", "\"||\"", "\"=\"", "$accept", "CompUnit", "Decl", "ConstDecl",
  "ConstDefList", "BType", "ConstDef", "ConstExpArrayList", "ConstInitVal",
  "ConstInitVallist", "ConstExp", "VarDecl", "VarDefList", "VarDef",
  "ArrayDef", "InitVal", "InitValArray", "InitValArrayList", "FuncDef",
  "FuncFParams", "FuncFParam", "FuncFParamOne", "FuncFParamArray", "Block",
  "BlockItemList", "BlockItem", "Stmt", "Exp", "Cond", "LVal",
  "ArrayIdent", "Number", "PrimaryExp", "UnaryExp", "FuncCall",
  "FuncRParamList", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp",
  "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     226,  -143,  -143,  -143,   147,   115,  -143,  -143,    12,  -143,
    -143,    27,  -143,  -143,  -143,    74,    60,  -143,     9,   206,
    -143,    88,   210,   210,    42,  -143,    43,   210,   197,    78,
    -143,    27,    44,    71,     8,  -143,  -143,    75,    56,  -143,
     210,   210,   210,   210,    49,  -143,  -143,    77,  -143,  -143,
    -143,  -143,   180,     4,  -143,  -143,   210,    82,    92,  -143,
      72,    57,  -143,  -143,   210,   197,  -143,   125,  -143,   103,
     147,    44,   210,     5,   210,  -143,  -143,  -143,   119,  -143,
     210,   210,   210,   210,   210,   210,   121,    91,  -143,  -143,
    -143,  -143,    23,   123,  -143,  -143,    14,   166,   172,   134,
     161,  -143,  -143,    43,  -143,   155,  -143,  -143,   187,   159,
     165,  -143,  -143,   177,  -143,  -143,    17,   189,  -143,   199,
    -143,  -143,  -143,   180,   180,  -143,  -143,  -143,  -143,    50,
     197,  -143,  -143,  -143,   211,  -143,  -143,   210,   210,  -143,
    -143,  -143,   210,  -143,  -143,   210,  -143,  -143,  -143,   205,
    -143,  -143,  -143,   174,     4,   152,   186,   173,   201,   216,
     222,  -143,  -143,  -143,   176,   210,   210,   210,   210,   210,
     210,   210,   210,   176,  -143,   229,     4,     4,     4,     4,
     152,   152,   186,   173,  -143,   176,  -143
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,    13,     0,     0,     4,     6,     0,     7,
       2,     0,     1,     5,     3,    27,     0,    25,     0,     0,
       9,     0,     0,     0,    29,    24,     0,     0,     0,     0,
       8,     0,     0,     0,     0,    42,    44,    45,    68,    72,
       0,     0,     0,     0,     0,    23,    74,    69,    75,    76,
      85,    80,    89,    66,    28,    33,     0,     0,    27,    26,
       0,     0,    15,    18,     0,     0,    10,     0,    40,    46,
       0,     0,     0,     0,     0,    78,    79,    77,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    16,
      19,    21,     0,     0,    14,    56,     0,     0,     0,     0,
       0,    49,    53,     0,    58,     0,    51,    54,     0,    74,
       0,    43,    41,     0,    81,    83,     0,     0,    73,     0,
      87,    88,    86,    91,    90,    32,    34,    38,    36,     0,
       0,    20,    17,    64,     0,    63,    62,     0,     0,    50,
      52,    57,     0,    47,    48,     0,    82,    70,    71,     0,
      35,    22,    65,     0,    92,    97,   100,   102,    67,     0,
       0,    84,    39,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    59,    93,    95,    94,    96,
      99,    98,   101,   103,    61,     0,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,   149,  -143,  -143,     0,   215,  -143,   -58,  -143,
     -17,  -143,  -143,   221,  -143,   -86,   -81,  -143,   243,  -143,
     179,  -143,  -143,   -16,  -143,   145,  -142,   -23,   113,   -65,
    -143,  -143,  -143,   -29,  -143,  -143,   156,   -79,    73,    81,
      83,  -143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,   102,     7,    19,     8,    20,    29,    62,    92,
      63,     9,    16,    17,    24,    54,    88,   129,    10,    34,
      35,    36,    37,   104,   105,   106,   107,    45,   153,    46,
      47,    48,    49,    50,    51,   116,    52,    53,   155,   156,
     157,   158
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,   127,   109,    91,    11,    44,   128,    94,    38,    39,
      60,    75,    76,    77,    70,    15,    68,    38,    39,   133,
      78,    33,   175,   145,    84,    40,    41,    85,    42,   130,
      18,   184,    43,   114,    40,    41,    71,    42,    27,    86,
     109,    43,   131,   186,   108,   146,    58,    93,    28,   113,
     115,   117,   120,   121,   122,   112,   149,   119,   154,   154,
      38,    39,    67,   162,    55,    25,    26,   103,   163,   150,
      33,    56,   151,   134,    69,    61,    90,    40,    41,    79,
      42,    57,   108,    73,    43,    74,   176,   177,   178,   179,
     154,   154,   154,   154,    38,    39,     1,     2,     3,   109,
      87,    21,    89,    22,    72,   103,    80,    64,   109,    87,
     126,    40,    41,    23,    42,    12,    32,    65,    43,   160,
     109,    22,   161,     1,     2,     3,    55,     4,    38,    39,
      95,    23,   110,     1,     2,     3,    96,     4,    97,    98,
      99,   108,   100,    67,   101,    40,    41,   118,    42,     6,
     108,   125,    43,   132,    13,     1,     2,     3,    38,    39,
      95,   137,   108,     1,     2,     3,    96,     4,    97,    98,
      99,   135,   100,    67,   139,    40,    41,   136,    42,    38,
      39,    95,    43,   165,   166,   167,   168,    96,   138,    97,
      98,    99,   141,   100,    67,   143,    40,    41,   142,    42,
      38,    39,   164,    43,    81,    82,    83,   144,    38,    39,
     171,    30,    31,    38,    39,    61,   152,    40,    41,   147,
      42,   169,   170,    87,    43,    40,    41,   174,    42,   148,
      40,    41,    43,    42,     1,     2,     3,    43,     4,   172,
     123,   124,   180,   181,   173,   185,    66,    59,    14,   111,
     140,   159,   182,     0,     0,   183
};

static const yytype_int16 yycheck[] =
{
      23,    87,    67,    61,     4,    22,    87,    65,     3,     4,
      27,    40,    41,    42,     6,     3,    32,     3,     4,     5,
      43,    21,   164,     6,    20,    20,    21,    23,    23,     6,
       3,   173,    27,    28,    20,    21,    28,    23,    29,    56,
     105,    27,    19,   185,    67,    28,     3,    64,    39,    72,
      73,    74,    81,    82,    83,    71,     6,    80,   137,   138,
       3,     4,    18,   149,    87,     5,     6,    67,   149,    19,
      70,    29,   130,    96,     3,    18,    19,    20,    21,    30,
      23,    39,   105,    27,    27,    29,   165,   166,   167,   168,
     169,   170,   171,   172,     3,     4,     8,     9,    10,   164,
      18,    27,    30,    29,    29,   105,    29,    29,   173,    18,
      19,    20,    21,    39,    23,     0,    28,    39,    27,   142,
     185,    29,   145,     8,     9,    10,   149,    12,     3,     4,
       5,    39,    29,     8,     9,    10,    11,    12,    13,    14,
      15,   164,    17,    18,    19,    20,    21,    28,    23,     0,
     173,    30,    27,    30,     5,     8,     9,    10,     3,     4,
       5,    27,   185,     8,     9,    10,    11,    12,    13,    14,
      15,     5,    17,    18,    19,    20,    21,     5,    23,     3,
       4,     5,    27,    31,    32,    33,    34,    11,    27,    13,
      14,    15,     5,    17,    18,    30,    20,    21,    39,    23,
       3,     4,    28,    27,    24,    25,    26,    30,     3,     4,
      37,     5,     6,     3,     4,    18,     5,    20,    21,    30,
      23,    35,    36,    18,    27,    20,    21,     5,    23,    30,
      20,    21,    27,    23,     8,     9,    10,    27,    12,    38,
      84,    85,   169,   170,    28,    16,    31,    26,     5,    70,
     105,   138,   171,    -1,    -1,   172
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    10,    12,    41,    42,    43,    45,    51,
      58,    45,     0,    42,    58,     3,    52,    53,     3,    44,
      46,    27,    29,    39,    54,     5,     6,    29,    39,    47,
       5,     6,    28,    45,    59,    60,    61,    62,     3,     4,
      20,    21,    23,    27,    50,    67,    69,    70,    71,    72,
      73,    74,    76,    77,    55,    67,    29,    39,     3,    53,
      50,    18,    48,    50,    29,    39,    46,    18,    63,     3,
       6,    28,    29,    27,    29,    73,    73,    73,    67,    30,
      29,    24,    25,    26,    20,    23,    50,    18,    56,    30,
      19,    48,    49,    50,    48,     5,    11,    13,    14,    15,
      17,    19,    42,    45,    63,    64,    65,    66,    67,    69,
      29,    60,    63,    67,    28,    67,    75,    67,    28,    67,
      73,    73,    73,    76,    76,    30,    19,    55,    56,    57,
       6,    19,    30,     5,    67,     5,     5,    27,    27,    19,
      65,     5,    39,    30,    30,     6,    28,    30,    30,     6,
      19,    48,     5,    68,    77,    78,    79,    80,    81,    68,
      67,    67,    55,    56,    28,    31,    32,    33,    34,    35,
      36,    37,    38,    28,     5,    66,    77,    77,    77,    77,
      78,    78,    79,    80,    66,    16,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    41,    41,    42,    42,    43,    44,
      44,    45,    45,    45,    46,    46,    47,    47,    48,    48,
      48,    49,    49,    50,    51,    52,    52,    53,    53,    53,
      53,    54,    54,    55,    56,    56,    57,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    68,    69,    69,
      70,    70,    71,    72,    72,    72,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    76,    76,    76,    76,    77,
      77,    77,    78,    78,    78,    78,    78,    79,    79,    79,
      80,    80,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     4,     1,
       3,     1,     1,     1,     4,     3,     3,     4,     1,     2,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     2,
       4,     3,     4,     1,     2,     3,     1,     3,     1,     3,
       5,     6,     1,     3,     1,     1,     2,     4,     4,     2,
       3,     1,     2,     1,     1,     4,     1,     2,     1,     5,
       7,     5,     2,     2,     2,     3,     1,     1,     1,     1,
       4,     4,     1,     3,     1,     1,     1,     2,     2,     2,
       1,     3,     4,     1,     3,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* CompUnit: FuncDef  */
#line 173 "parser.y"
        {
		    //root->functions.push_back(std::shared_ptr<tree_func_def>($1));
        }
#line 1449 "parser.tab.c"
    break;

  case 3: /* CompUnit: CompUnit FuncDef  */
#line 177 "parser.y"
        {
		    //root->functions.push_back(std::shared_ptr<tree_func_def>($2));
        }
#line 1457 "parser.tab.c"
    break;

  case 4: /* CompUnit: Decl  */
#line 181 "parser.y"
        {
            //root->definitions.push_back(std::shared_ptr<tree_decl>($1));
        }
#line 1465 "parser.tab.c"
    break;

  case 5: /* CompUnit: CompUnit Decl  */
#line 185 "parser.y"
        {
            //root->definitions.push_back(std::shared_ptr<tree_decl>($2));
        }
#line 1473 "parser.tab.c"
    break;

  case 6: /* Decl: ConstDecl  */
#line 192 "parser.y"
        {
            (yyval.decl) = new tree_decl();
            (yyval.decl)->const_decl=std::shared_ptr<tree_const_decl>((yyvsp[0].const_decl));
        }
#line 1482 "parser.tab.c"
    break;

  case 7: /* Decl: VarDecl  */
#line 197 "parser.y"
        {
            (yyval.decl) = new tree_decl();
            (yyval.decl)->var_decl=std::shared_ptr<tree_var_decl>((yyvsp[0].var_decl));
        }
#line 1491 "parser.tab.c"
    break;

  case 8: /* ConstDecl: "const" BType ConstDefList ";"  */
#line 205 "parser.y"
        {
            (yyval.const_decl) = new tree_const_decl();
            (yyval.const_decl)->b_type=std::shared_ptr<tree_basic_type>((yyvsp[-2].basic_type));
            (yyval.const_decl)->const_def_list=std::shared_ptr<tree_const_def_list>((yyvsp[-1].const_def_list));
        }
#line 1501 "parser.tab.c"
    break;

  case 9: /* ConstDefList: ConstDef  */
#line 214 "parser.y"
        {
            (yyval.const_def_list) = new tree_const_def_list();
            (yyval.const_def_list)->const_defs.push_back(std::shared_ptr<tree_const_def>((yyvsp[0].const_def)));
        }
#line 1510 "parser.tab.c"
    break;

  case 10: /* ConstDefList: ConstDefList "," ConstDef  */
#line 219 "parser.y"
        {
            (yyvsp[-2].const_def_list)->const_defs.push_back(std::shared_ptr<tree_const_def>((yyvsp[0].const_def)));
            (yyval.const_def_list) = (yyvsp[-2].const_def_list);
        }
#line 1519 "parser.tab.c"
    break;

  case 11: /* BType: "int"  */
#line 227 "parser.y"
        {
            (yyval.basic_type) = new tree_basic_type();
            (yyval.basic_type)->type=type_helper::INT;
        }
#line 1528 "parser.tab.c"
    break;

  case 12: /* BType: "float"  */
#line 232 "parser.y"
        {
            (yyval.basic_type) = new tree_basic_type();
            (yyval.basic_type)->type=type_helper::FLOAT;
        }
#line 1537 "parser.tab.c"
    break;

  case 13: /* BType: "void"  */
#line 237 "parser.y"
        {
            (yyval.basic_type) = new tree_basic_type();
            (yyval.basic_type)->type=type_helper::VOID;
        }
#line 1546 "parser.tab.c"
    break;

  case 14: /* ConstDef: TIDENTIFIER ConstExpArrayList "=" ConstInitVal  */
#line 245 "parser.y"
        {
            (yyval.const_def) = new tree_const_def();
            (yyval.const_def)->id=*(yyvsp[-3].string);
            (yyval.const_def)->const_exp_list=std::shared_ptr<tree_const_exp_list>((yyvsp[-2].const_exp_list));
            (yyval.const_def)->const_init_val=std::shared_ptr<tree_const_init_val>((yyvsp[0].const_init_val));
        }
#line 1557 "parser.tab.c"
    break;

  case 15: /* ConstDef: TIDENTIFIER "=" ConstInitVal  */
#line 252 "parser.y"
        {
            (yyval.const_def) = new tree_const_def();
            (yyval.const_def)->id=*(yyvsp[-2].string);
            (yyval.const_def)->const_init_val=std::shared_ptr<tree_const_init_val>((yyvsp[0].const_init_val));
        }
#line 1567 "parser.tab.c"
    break;

  case 16: /* ConstExpArrayList: "[" ConstExp "]"  */
#line 261 "parser.y"
        {
            (yyval.const_exp_list) = new tree_const_exp_list();
            (yyval.const_exp_list)->const_exp.push_back(std::shared_ptr<tree_const_exp>((yyvsp[-1].const_exp)));
        }
#line 1576 "parser.tab.c"
    break;

  case 17: /* ConstExpArrayList: ConstExpArrayList "[" ConstExp "]"  */
#line 266 "parser.y"
        {
            (yyvsp[-3].const_exp_list)->const_exp.push_back(std::shared_ptr<tree_const_exp>((yyvsp[-1].const_exp)));
            (yyval.const_exp_list) = (yyvsp[-3].const_exp_list);
        }
#line 1585 "parser.tab.c"
    break;

  case 18: /* ConstInitVal: ConstExp  */
#line 274 "parser.y"
        {
            (yyval.const_init_val) = new tree_const_init_val();
            (yyval.const_init_val)->const_exp= std::shared_ptr<tree_const_exp>((yyvsp[0].const_exp)) ;
        }
#line 1594 "parser.tab.c"
    break;

  case 19: /* ConstInitVal: "{" "}"  */
#line 279 "parser.y"
        {
            (yyval.const_init_val) = new tree_const_init_val();
        }
#line 1602 "parser.tab.c"
    break;

  case 20: /* ConstInitVal: "{" ConstInitVallist "}"  */
#line 283 "parser.y"
        {
            (yyval.const_init_val) = new tree_const_init_val();
            (yyval.const_init_val)->const_val_list = std::shared_ptr<tree_const_val_list>((yyvsp[-1].const_init_val_list)) ;
        }
#line 1611 "parser.tab.c"
    break;

  case 21: /* ConstInitVallist: ConstInitVal  */
#line 291 "parser.y"
        {
            (yyval.const_init_val_list) = new tree_const_val_list();
            (yyval.const_init_val_list)->const_init_vals.push_back(std::shared_ptr<tree_const_init_val>((yyvsp[0].const_init_val)));
        }
#line 1620 "parser.tab.c"
    break;

  case 22: /* ConstInitVallist: ConstInitVallist "," ConstInitVal  */
#line 296 "parser.y"
        {
            (yyvsp[-2].const_init_val_list)->const_init_vals.push_back(std::shared_ptr<tree_const_init_val>((yyvsp[0].const_init_val)));
            (yyval.const_init_val_list) = (yyvsp[-2].const_init_val_list);
        }
#line 1629 "parser.tab.c"
    break;

  case 23: /* ConstExp: Exp  */
#line 304 "parser.y"
        {
            // $$ = new tree_const_exp();
            // $$->add_exp = std::shared_ptr<tree_add_exp>($1);
        }
#line 1638 "parser.tab.c"
    break;

  case 24: /* VarDecl: BType VarDefList ";"  */
#line 312 "parser.y"
        {
            (yyval.var_decl) = new tree_var_decl();
            (yyval.var_decl)->b_type=std::shared_ptr<tree_basic_type>((yyvsp[-2].basic_type));
            (yyval.var_decl)->var_def_list=std::shared_ptr<tree_var_def_list>((yyvsp[-1].var_def_list));
        }
#line 1648 "parser.tab.c"
    break;

  case 25: /* VarDefList: VarDef  */
#line 321 "parser.y"
        {
            (yyval.var_def_list) = new tree_var_def_list();
            (yyval.var_def_list)->var_defs.push_back(std::shared_ptr<tree_var_def>((yyvsp[0].var_def)));
        }
#line 1657 "parser.tab.c"
    break;

  case 26: /* VarDefList: VarDefList "," VarDef  */
#line 326 "parser.y"
        {
            (yyvsp[-2].var_def_list)->var_defs.push_back(std::shared_ptr<tree_var_def>((yyvsp[0].var_def)));
            (yyval.var_def_list) = (yyvsp[-2].var_def_list);
        }
#line 1666 "parser.tab.c"
    break;

  case 27: /* VarDef: TIDENTIFIER  */
#line 334 "parser.y"
        {
            (yyval.var_def) = new tree_var_def();
            (yyval.var_def)->id = *(yyvsp[0].string);
        }
#line 1675 "parser.tab.c"
    break;

  case 28: /* VarDef: TIDENTIFIER "=" InitVal  */
#line 339 "parser.y"
        {
            (yyval.var_def) = new tree_var_def();
            (yyval.var_def)->id = *(yyvsp[-2].string);
            (yyval.var_def)->init_val = std::shared_ptr<tree_init_val>((yyvsp[0].init_val));
        }
#line 1685 "parser.tab.c"
    break;

  case 29: /* VarDef: TIDENTIFIER ArrayDef  */
#line 345 "parser.y"
        {
            (yyval.var_def) = new tree_var_def();
            (yyval.var_def)->id = *(yyvsp[-1].string);
            (yyval.var_def)->array_def = std::shared_ptr<tree_arrray_def>((yyvsp[0].array_def));
        }
#line 1695 "parser.tab.c"
    break;

  case 30: /* VarDef: TIDENTIFIER ArrayDef "=" InitValArray  */
#line 351 "parser.y"
        {
            (yyval.var_def) = new tree_var_def();
            (yyval.var_def)->id = *(yyvsp[-3].string);
            (yyval.var_def)->array_def = std::shared_ptr<tree_arrray_def>((yyvsp[-2].array_def));
            (yyval.var_def)->init_val_array = std::shared_ptr<tree_init_val_array>((yyvsp[0].init_val_array));
        }
#line 1706 "parser.tab.c"
    break;

  case 31: /* ArrayDef: "[" ConstExp "]"  */
#line 361 "parser.y"
        {
            (yyval.array_def) = new tree_arrray_def();
            (yyval.array_def)->const_exps.push_back(std::shared_ptr<tree_const_exp>((yyvsp[-1].const_exp)));
        }
#line 1715 "parser.tab.c"
    break;

  case 32: /* ArrayDef: ArrayDef "[" ConstExp "]"  */
#line 366 "parser.y"
        {
            (yyval.array_def)->const_exps.push_back(std::shared_ptr<tree_const_exp>((yyvsp[-1].const_exp)));
            (yyval.array_def) = (yyvsp[-3].array_def);
        }
#line 1724 "parser.tab.c"
    break;

  case 33: /* InitVal: Exp  */
#line 375 "parser.y"
        {
            (yyval.init_val) = new tree_init_val();
            (yyval.init_val)->exp=std::shared_ptr<tree_exp>((yyvsp[0].exp));
        }
#line 1733 "parser.tab.c"
    break;

  case 34: /* InitValArray: "{" "}"  */
#line 383 "parser.y"
        {
            (yyval.init_val_array) = new tree_init_val_array();
        }
#line 1741 "parser.tab.c"
    break;

  case 35: /* InitValArray: "{" InitValArrayList "}"  */
#line 387 "parser.y"
        {
            (yyval.init_val_array) = new tree_init_val_array();
            (yyval.init_val_array)->init_val_arraylist = std::shared_ptr<tree_init_val_arraylist>((yyvsp[-1].init_val_arraylist));
        }
#line 1750 "parser.tab.c"
    break;

  case 36: /* InitValArrayList: InitValArray  */
#line 396 "parser.y"
        {
            (yyval.init_val_arraylist) = new tree_init_val_arraylist();
            (yyval.init_val_arraylist)->initvalarrays.push_back(std::shared_ptr<tree_init_val_array>((yyvsp[0].init_val_array)));
        }
#line 1759 "parser.tab.c"
    break;

  case 37: /* InitValArrayList: InitValArrayList "," InitValArray  */
#line 401 "parser.y"
        {
            (yyvsp[-2].init_val_arraylist)->initvalarrays.push_back(std::shared_ptr<tree_init_val_array>((yyvsp[0].init_val_array)));
            (yyval.init_val_arraylist) = (yyvsp[-2].init_val_arraylist);
        }
#line 1768 "parser.tab.c"
    break;

  case 38: /* InitValArrayList: InitVal  */
#line 406 "parser.y"
        {
            (yyval.init_val_arraylist) = new tree_init_val_arraylist();
            (yyval.init_val_arraylist)->initvals.push_back(std::shared_ptr<tree_init_val>((yyvsp[0].init_val)));
        }
#line 1777 "parser.tab.c"
    break;

  case 39: /* InitValArrayList: InitValArrayList "," InitVal  */
#line 411 "parser.y"
        {
            (yyvsp[-2].init_val_arraylist)->initvals.push_back(std::shared_ptr<tree_init_val>((yyvsp[0].init_val)));
            (yyval.init_val_arraylist) = (yyvsp[-2].init_val_arraylist);
        }
#line 1786 "parser.tab.c"
    break;

  case 40: /* FuncDef: BType TIDENTIFIER "(" ")" Block  */
#line 420 "parser.y"
        {
            (yyval.func_def) = new tree_func_def();
            (yyval.func_def)->type = std::shared_ptr<tree_basic_type>((yyvsp[-4].basic_type));
            (yyval.func_def)->id = *(yyvsp[-3].string);
            (yyval.func_def)->block.push_back(std::shared_ptr<tree_block>((yyvsp[0].block)));
        }
#line 1797 "parser.tab.c"
    break;

  case 41: /* FuncDef: BType TIDENTIFIER "(" FuncFParams ")" Block  */
#line 427 "parser.y"
        {
            (yyval.func_def) = new tree_func_def();
            (yyval.func_def)->type = std::shared_ptr<tree_basic_type>((yyvsp[-5].basic_type));
            (yyval.func_def)->id = *(yyvsp[-4].string);
            (yyval.func_def)->funcfparams = std::shared_ptr<tree_func_fparams>((yyvsp[-2].func_fparams));

            (yyval.func_def)->block.push_back(std::shared_ptr<tree_block>((yyvsp[0].block)));
        }
#line 1810 "parser.tab.c"
    break;

  case 42: /* FuncFParams: FuncFParam  */
#line 439 "parser.y"
        {
            (yyval.func_fparams) = new tree_func_fparams();
            (yyval.func_fparams)->funcfparamlist.push_back(std::shared_ptr<tree_func_fparam>((yyvsp[0].func_fparam)));
        }
#line 1819 "parser.tab.c"
    break;

  case 43: /* FuncFParams: FuncFParams "," FuncFParam  */
#line 444 "parser.y"
        {
            (yyvsp[-2].func_fparams)->funcfparamlist.push_back(std::shared_ptr<tree_func_fparam>((yyvsp[0].func_fparam)));
            (yyval.func_fparams) = (yyvsp[-2].func_fparams);
        }
#line 1828 "parser.tab.c"
    break;

  case 44: /* FuncFParam: FuncFParamOne  */
#line 452 "parser.y"
        {
            (yyval.func_fparam) = new tree_func_fparam();
            (yyval.func_fparam)->funcfparamone = std::shared_ptr<tree_func_fparamone>((yyvsp[0].func_fparamone));
        }
#line 1837 "parser.tab.c"
    break;

  case 45: /* FuncFParam: FuncFParamArray  */
#line 457 "parser.y"
        {
            (yyval.func_fparam) = new tree_func_fparam();
            (yyval.func_fparam)->funcfparamarray = std::shared_ptr<tree_func_fparamarray>((yyvsp[0].func_fparamarray));
        }
#line 1846 "parser.tab.c"
    break;

  case 46: /* FuncFParamOne: BType TIDENTIFIER  */
#line 465 "parser.y"
        {
            (yyval.func_fparamone) = new tree_func_fparamone();
            (yyval.func_fparamone)->b_type = std::shared_ptr<tree_basic_type>((yyvsp[-1].basic_type));
            (yyval.func_fparamone)->id = *(yyvsp[0].string);
        }
#line 1856 "parser.tab.c"
    break;

  case 47: /* FuncFParamArray: BType TIDENTIFIER "[" "]"  */
#line 474 "parser.y"
        {
            (yyval.func_fparamarray) = new tree_func_fparamarray();
            (yyval.func_fparamarray)->b_type = std::shared_ptr<tree_basic_type>((yyvsp[-3].basic_type));
            (yyval.func_fparamarray)->id = *(yyvsp[-2].string);
        }
#line 1866 "parser.tab.c"
    break;

  case 48: /* FuncFParamArray: FuncFParamArray "[" Exp "]"  */
#line 480 "parser.y"
        {
            (yyvsp[-3].func_fparamarray)->exps.push_back(std::shared_ptr<tree_exp>((yyvsp[-1].exp)));
            (yyval.func_fparamarray) = (yyvsp[-3].func_fparamarray);
        }
#line 1875 "parser.tab.c"
    break;

  case 49: /* Block: "{" "}"  */
#line 488 "parser.y"
        {
            (yyval.block) = new tree_block();
        }
#line 1883 "parser.tab.c"
    break;

  case 50: /* Block: "{" BlockItemList "}"  */
#line 492 "parser.y"
        {
            (yyval.block) = new tree_block();
            (yyval.block)->block_item_list=std::shared_ptr<tree_block_item_list>((yyvsp[-1].block_item_list));
        }
#line 1892 "parser.tab.c"
    break;

  case 51: /* BlockItemList: BlockItem  */
#line 500 "parser.y"
        {
            (yyval.block_item_list) = new tree_block_item_list();
            (yyval.block_item_list)->block_items.push_back(std::shared_ptr<tree_block_item>((yyvsp[0].block_item)));
        }
#line 1901 "parser.tab.c"
    break;

  case 52: /* BlockItemList: BlockItemList BlockItem  */
#line 505 "parser.y"
        {
            (yyvsp[-1].block_item_list)->block_items.push_back(std::shared_ptr<tree_block_item>((yyvsp[0].block_item)));
            (yyval.block_item_list)=(yyvsp[-1].block_item_list);
        }
#line 1910 "parser.tab.c"
    break;

  case 53: /* BlockItem: Decl  */
#line 513 "parser.y"
        {
            (yyval.block_item) = new tree_block_item();
            (yyval.block_item)->decl=std::shared_ptr<tree_decl>((yyvsp[0].decl));
        }
#line 1919 "parser.tab.c"
    break;

  case 54: /* BlockItem: Stmt  */
#line 518 "parser.y"
        {
            (yyval.block_item) = new tree_block_item();
            (yyval.block_item)->stmt=std::shared_ptr<tree_stmt>((yyvsp[0].stmt));
        }
#line 1928 "parser.tab.c"
    break;

  case 55: /* Stmt: LVal "=" Exp ";"  */
#line 528 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
            auto a_stmt = new tree_assign_stmt();
            a_stmt->l_val=std::shared_ptr<tree_l_val>((yyvsp[-3].l_val));
            a_stmt->exp=std::shared_ptr<tree_exp>((yyvsp[-1].exp));
            (yyval.stmt)->assigm_stmt=std::shared_ptr<tree_assign_stmt>(a_stmt) ;
        }
#line 1940 "parser.tab.c"
    break;

  case 56: /* Stmt: ";"  */
#line 536 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
        }
#line 1948 "parser.tab.c"
    break;

  case 57: /* Stmt: Exp ";"  */
#line 540 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
            (yyval.stmt)->exp=std::shared_ptr<tree_exp>((yyvsp[-1].exp)) ;
        }
#line 1957 "parser.tab.c"
    break;

  case 58: /* Stmt: Block  */
#line 545 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
            (yyval.stmt)->block=std::shared_ptr<tree_block>((yyvsp[0].block)) ;
        }
#line 1966 "parser.tab.c"
    break;

  case 59: /* Stmt: "if" "(" Cond ")" Stmt  */
#line 551 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
            auto if_stmt = new tree_if_stmt();
            if_stmt->cond = std::shared_ptr<tree_cond>((yyvsp[-2].cond));
            if_stmt->stmt = std::shared_ptr<tree_stmt>((yyvsp[0].stmt));
            (yyval.stmt)->if_stmt = std::shared_ptr<tree_if_stmt>(if_stmt) ;
        }
#line 1978 "parser.tab.c"
    break;

  case 60: /* Stmt: "if" "(" Cond ")" Stmt "else" Stmt  */
#line 559 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
            auto if_else_stmt = new tree_if_else_stmt();
            if_else_stmt->cond = std::shared_ptr<tree_cond>((yyvsp[-4].cond));
            if_else_stmt->stmt1 = std::shared_ptr<tree_stmt>((yyvsp[-2].stmt));
            if_else_stmt->stmt2 = std::shared_ptr<tree_stmt>((yyvsp[0].stmt));
            (yyval.stmt)->if_else_stmt = std::shared_ptr<tree_if_else_stmt>(if_else_stmt) ;

        }
#line 1992 "parser.tab.c"
    break;

  case 61: /* Stmt: "while" "(" Cond ")" Stmt  */
#line 570 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
            auto while_stmt = new tree_while_stmt();
            while_stmt->cond = std::shared_ptr<tree_cond>((yyvsp[-2].cond));
            while_stmt->stmt = std::shared_ptr<tree_stmt>((yyvsp[0].stmt));
            (yyval.stmt)->while_stmt = std::shared_ptr<tree_while_stmt>(while_stmt) ;
        }
#line 2004 "parser.tab.c"
    break;

  case 62: /* Stmt: "continue" ";"  */
#line 578 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
            auto continue_stmt = new tree_continue_stmt();
            (yyval.stmt)->continue_stmt = std::shared_ptr<tree_continue_stmt>(continue_stmt) ;
        }
#line 2014 "parser.tab.c"
    break;

  case 63: /* Stmt: "break" ";"  */
#line 584 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
            auto break_stmt = new tree_break_stmt();
            (yyval.stmt)->break_stmt = std::shared_ptr<tree_break_stmt>(break_stmt) ;
        }
#line 2024 "parser.tab.c"
    break;

  case 64: /* Stmt: "return" ";"  */
#line 591 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
            auto a_stmt = new tree_return_null_stmt();
            (yyval.stmt)->return_null_stmt=std::shared_ptr<tree_return_null_stmt>(a_stmt) ;
        }
#line 2034 "parser.tab.c"
    break;

  case 65: /* Stmt: "return" Exp ";"  */
#line 597 "parser.y"
        {
            (yyval.stmt) = new tree_stmt();
            auto a_stmt = new tree_return_stmt();
            a_stmt->exp=std::shared_ptr<tree_exp>((yyvsp[-1].exp));
            (yyval.stmt)->return_stmt=std::shared_ptr<tree_return_stmt>(a_stmt) ;
        }
#line 2045 "parser.tab.c"
    break;

  case 66: /* Exp: AddExp  */
#line 608 "parser.y"
        {
            (yyval.exp) = new tree_exp();
            (yyval.exp)->add_exp = std::shared_ptr<tree_add_exp>((yyvsp[0].add_exp));
        }
#line 2054 "parser.tab.c"
    break;

  case 67: /* Cond: LOrExp  */
#line 616 "parser.y"
        {
            (yyval.cond) = new tree_cond();
            (yyval.cond)->l_or_exp = std::shared_ptr<tree_l_or_exp>((yyvsp[0].l_or_exp));
        }
#line 2063 "parser.tab.c"
    break;

  case 68: /* LVal: TIDENTIFIER  */
#line 624 "parser.y"
        {
            (yyval.l_val) = new tree_l_val();
            (yyval.l_val)->id = *(yyvsp[0].string);
        }
#line 2072 "parser.tab.c"
    break;

  case 69: /* LVal: ArrayIdent  */
#line 629 "parser.y"
        {
            (yyval.l_val) = new tree_l_val();
            (yyval.l_val)->array_ident = std::shared_ptr<tree_array_ident>((yyvsp[0].array_ident));
        }
#line 2081 "parser.tab.c"
    break;

  case 70: /* ArrayIdent: TIDENTIFIER "[" Exp "]"  */
#line 637 "parser.y"
        {
            (yyval.array_ident) = new tree_array_ident();
            (yyval.array_ident)->id = *(yyvsp[-3].string);
            (yyval.array_ident)->exp = std::shared_ptr<tree_exp>((yyvsp[-1].exp));
        }
#line 2091 "parser.tab.c"
    break;

  case 71: /* ArrayIdent: ArrayIdent "[" Exp "]"  */
#line 643 "parser.y"
        {
            (yyvsp[-3].array_ident)->exp = std::shared_ptr<tree_exp>((yyvsp[-1].exp));
            (yyval.array_ident) = (yyvsp[-3].array_ident);
        }
#line 2100 "parser.tab.c"
    break;

  case 72: /* Number: TINTEGER  */
#line 651 "parser.y"
        {
            (yyval.number) = new tree_number();
            (yyval.number)->int_value = atoi((yyvsp[0].string)->c_str());
            (yyval.number)->float_value = (float)atof((yyvsp[0].string)->c_str());
        }
#line 2110 "parser.tab.c"
    break;

  case 73: /* PrimaryExp: "(" Exp ")"  */
#line 660 "parser.y"
        {
            (yyval.primary_exp) = new tree_primary_exp();
            (yyval.primary_exp)->exp = std::shared_ptr<tree_exp>((yyvsp[-1].exp));
        }
#line 2119 "parser.tab.c"
    break;

  case 74: /* PrimaryExp: LVal  */
#line 665 "parser.y"
        {
            (yyval.primary_exp) = new tree_primary_exp();
            (yyval.primary_exp)->l_val = std::shared_ptr<tree_l_val>((yyvsp[0].l_val));
        }
#line 2128 "parser.tab.c"
    break;

  case 75: /* PrimaryExp: Number  */
#line 670 "parser.y"
        {
            (yyval.primary_exp) = new tree_primary_exp();
            (yyval.primary_exp)->number = std::shared_ptr<tree_number>((yyvsp[0].number));
        }
#line 2137 "parser.tab.c"
    break;

  case 76: /* UnaryExp: PrimaryExp  */
#line 678 "parser.y"
        {
            (yyval.unary_exp) = new tree_unary_exp();
            (yyval.unary_exp)->primary_exp = std::shared_ptr<tree_primary_exp>((yyvsp[0].primary_exp));
        }
#line 2146 "parser.tab.c"
    break;

  case 77: /* UnaryExp: "+" UnaryExp  */
#line 683 "parser.y"
        {
            (yyval.unary_exp) = new tree_unary_exp();
            (yyval.unary_exp)->unary_exp=std::shared_ptr<tree_unary_exp>((yyvsp[0].unary_exp));
            (yyval.unary_exp)->oprt="+";
        }
#line 2156 "parser.tab.c"
    break;

  case 78: /* UnaryExp: "-" UnaryExp  */
#line 689 "parser.y"
        {
            (yyval.unary_exp) = new tree_unary_exp();
            (yyval.unary_exp)->unary_exp=std::shared_ptr<tree_unary_exp>((yyvsp[0].unary_exp));
            (yyval.unary_exp)->oprt="-";
        }
#line 2166 "parser.tab.c"
    break;

  case 79: /* UnaryExp: "!" UnaryExp  */
#line 695 "parser.y"
        {
            (yyval.unary_exp) = new tree_unary_exp();
            (yyval.unary_exp)->unary_exp=std::shared_ptr<tree_unary_exp>((yyvsp[0].unary_exp));
            (yyval.unary_exp)->oprt="!";
        }
#line 2176 "parser.tab.c"
    break;

  case 80: /* UnaryExp: FuncCall  */
#line 702 "parser.y"
        {
            (yyval.unary_exp) = new tree_unary_exp();
            (yyval.unary_exp)->func_call = std::shared_ptr<tree_func_call>((yyvsp[0].func_call));
        }
#line 2185 "parser.tab.c"
    break;

  case 81: /* FuncCall: TIDENTIFIER "(" ")"  */
#line 710 "parser.y"
        {
            (yyval.func_call) = new tree_func_call();
            (yyval.func_call)->id = *(yyvsp[-2].string);
        }
#line 2194 "parser.tab.c"
    break;

  case 82: /* FuncCall: TIDENTIFIER "(" FuncRParamList ")"  */
#line 715 "parser.y"
        {
            (yyval.func_call) = new tree_func_call();
            (yyval.func_call)->id = *(yyvsp[-3].string);
            (yyval.func_call)->funcr_paramlist = std::shared_ptr<tree_funcr_paramlist>((yyvsp[-1].funcr_paramlist));
        }
#line 2204 "parser.tab.c"
    break;

  case 83: /* FuncRParamList: Exp  */
#line 724 "parser.y"
        {
            (yyval.funcr_paramlist) = new tree_funcr_paramlist();
            (yyval.funcr_paramlist)->exps.push_back(std::shared_ptr<tree_exp>((yyvsp[0].exp)));
        }
#line 2213 "parser.tab.c"
    break;

  case 84: /* FuncRParamList: FuncRParamList "," Exp  */
#line 729 "parser.y"
        {
            (yyvsp[-2].funcr_paramlist)->exps.push_back(std::shared_ptr<tree_exp>((yyvsp[0].exp)));
            (yyval.funcr_paramlist) = (yyvsp[-2].funcr_paramlist);
        }
#line 2222 "parser.tab.c"
    break;

  case 85: /* MulExp: UnaryExp  */
#line 739 "parser.y"
        {
            (yyval.mul_exp) = new tree_mul_exp();
            (yyval.mul_exp)->unary_exp=std::shared_ptr<tree_unary_exp>((yyvsp[0].unary_exp));
        }
#line 2231 "parser.tab.c"
    break;

  case 86: /* MulExp: MulExp "*" UnaryExp  */
#line 744 "parser.y"
        {
            (yyval.mul_exp) = new tree_mul_exp();
            (yyval.mul_exp)->mul_exp=std::shared_ptr<tree_mul_exp>((yyvsp[-2].mul_exp));
            (yyval.mul_exp)->unary_exp=std::shared_ptr<tree_unary_exp>((yyvsp[0].unary_exp));
            (yyval.mul_exp)->oprt="*";
        }
#line 2242 "parser.tab.c"
    break;

  case 87: /* MulExp: MulExp "/" UnaryExp  */
#line 751 "parser.y"
        {
            (yyval.mul_exp) = new tree_mul_exp();
            (yyval.mul_exp)->mul_exp=std::shared_ptr<tree_mul_exp>((yyvsp[-2].mul_exp));
            (yyval.mul_exp)->unary_exp=std::shared_ptr<tree_unary_exp>((yyvsp[0].unary_exp));
            (yyval.mul_exp)->oprt="/";
        }
#line 2253 "parser.tab.c"
    break;

  case 88: /* MulExp: MulExp "%" UnaryExp  */
#line 758 "parser.y"
        {
            (yyval.mul_exp) = new tree_mul_exp();
            (yyval.mul_exp)->mul_exp=std::shared_ptr<tree_mul_exp>((yyvsp[-2].mul_exp));
            (yyval.mul_exp)->unary_exp=std::shared_ptr<tree_unary_exp>((yyvsp[0].unary_exp));
            (yyval.mul_exp)->oprt="%";
        }
#line 2264 "parser.tab.c"
    break;

  case 89: /* AddExp: MulExp  */
#line 767 "parser.y"
        {
            (yyval.add_exp) = new tree_add_exp();
            (yyval.add_exp)->mul_exp=std::shared_ptr<tree_mul_exp>((yyvsp[0].mul_exp));
        }
#line 2273 "parser.tab.c"
    break;

  case 90: /* AddExp: AddExp "+" MulExp  */
#line 772 "parser.y"
        {
            (yyval.add_exp) = new tree_add_exp();
            (yyval.add_exp)->add_exp=std::shared_ptr<tree_add_exp>((yyvsp[-2].add_exp));
            (yyval.add_exp)->oprt="+";
            (yyval.add_exp)->mul_exp=std::shared_ptr<tree_mul_exp>((yyvsp[0].mul_exp));
        }
#line 2284 "parser.tab.c"
    break;

  case 91: /* AddExp: AddExp "-" MulExp  */
#line 779 "parser.y"
        {
            (yyval.add_exp) = new tree_add_exp();
            (yyval.add_exp)->add_exp=std::shared_ptr<tree_add_exp>((yyvsp[-2].add_exp));
            (yyval.add_exp)->oprt="-";
            (yyval.add_exp)->mul_exp=std::shared_ptr<tree_mul_exp>((yyvsp[0].mul_exp));
        }
#line 2295 "parser.tab.c"
    break;

  case 92: /* RelExp: AddExp  */
#line 788 "parser.y"
        {
            (yyval.rel_exp) = new tree_rel_exp();
            (yyval.rel_exp)->add_exp=std::shared_ptr<tree_add_exp>((yyvsp[0].add_exp));
        }
#line 2304 "parser.tab.c"
    break;

  case 93: /* RelExp: RelExp "<" AddExp  */
#line 793 "parser.y"
        {
            (yyval.rel_exp) = new tree_rel_exp();
            (yyval.rel_exp)->rel_exp=std::shared_ptr<tree_rel_exp>((yyvsp[-2].rel_exp));
            (yyval.rel_exp)->oprt="<";
            (yyval.rel_exp)->add_exp=std::shared_ptr<tree_add_exp>((yyvsp[0].add_exp));
        }
#line 2315 "parser.tab.c"
    break;

  case 94: /* RelExp: RelExp ">" AddExp  */
#line 800 "parser.y"
        {
            (yyval.rel_exp) = new tree_rel_exp();
            (yyval.rel_exp)->rel_exp=std::shared_ptr<tree_rel_exp>((yyvsp[-2].rel_exp));
            (yyval.rel_exp)->oprt=">";
            (yyval.rel_exp)->add_exp=std::shared_ptr<tree_add_exp>((yyvsp[0].add_exp));
        }
#line 2326 "parser.tab.c"
    break;

  case 95: /* RelExp: RelExp "<=" AddExp  */
#line 807 "parser.y"
        {
            (yyval.rel_exp) = new tree_rel_exp();
            (yyval.rel_exp)->rel_exp=std::shared_ptr<tree_rel_exp>((yyvsp[-2].rel_exp));
            (yyval.rel_exp)->oprt="<=";
            (yyval.rel_exp)->add_exp=std::shared_ptr<tree_add_exp>((yyvsp[0].add_exp));
        }
#line 2337 "parser.tab.c"
    break;

  case 96: /* RelExp: RelExp ">=" AddExp  */
#line 814 "parser.y"
        {
            (yyval.rel_exp) = new tree_rel_exp();
            (yyval.rel_exp)->rel_exp=std::shared_ptr<tree_rel_exp>((yyvsp[-2].rel_exp));
            (yyval.rel_exp)->oprt=">=";
            (yyval.rel_exp)->add_exp=std::shared_ptr<tree_add_exp>((yyvsp[0].add_exp));
        }
#line 2348 "parser.tab.c"
    break;

  case 97: /* EqExp: RelExp  */
#line 823 "parser.y"
        {
            (yyval.eq_exp) = new tree_eq_exp();
            (yyval.eq_exp)->rel_exp=std::shared_ptr<tree_rel_exp>((yyvsp[0].rel_exp));
        }
#line 2357 "parser.tab.c"
    break;

  case 98: /* EqExp: EqExp "==" RelExp  */
#line 828 "parser.y"
        {
            (yyval.eq_exp) = new tree_eq_exp();
            (yyval.eq_exp)->eq_exp=std::shared_ptr<tree_eq_exp>((yyvsp[-2].eq_exp));
            (yyval.eq_exp)->oprt="==";
            (yyval.eq_exp)->rel_exp=std::shared_ptr<tree_rel_exp>((yyvsp[0].rel_exp));
        }
#line 2368 "parser.tab.c"
    break;

  case 99: /* EqExp: EqExp "!=" RelExp  */
#line 835 "parser.y"
        {
            (yyval.eq_exp) = new tree_eq_exp();
            (yyval.eq_exp)->eq_exp=std::shared_ptr<tree_eq_exp>((yyvsp[-2].eq_exp));
            (yyval.eq_exp)->oprt="!=";
            (yyval.eq_exp)->rel_exp=std::shared_ptr<tree_rel_exp>((yyvsp[0].rel_exp));
        }
#line 2379 "parser.tab.c"
    break;

  case 100: /* LAndExp: EqExp  */
#line 844 "parser.y"
        {
            (yyval.l_and_exp) = new tree_l_and_exp();
            (yyval.l_and_exp)->eq_exp=std::shared_ptr<tree_eq_exp>((yyvsp[0].eq_exp));
        }
#line 2388 "parser.tab.c"
    break;

  case 101: /* LAndExp: LAndExp "&&" EqExp  */
#line 849 "parser.y"
        {
            (yyval.l_and_exp) = new tree_l_and_exp();
            (yyval.l_and_exp)->l_and_exp=std::shared_ptr<tree_l_and_exp>((yyvsp[-2].l_and_exp));
            (yyval.l_and_exp)->eq_exp=std::shared_ptr<tree_eq_exp>((yyvsp[0].eq_exp));
        }
#line 2398 "parser.tab.c"
    break;

  case 102: /* LOrExp: LAndExp  */
#line 857 "parser.y"
        {
            (yyval.l_or_exp) = new tree_l_or_exp();
            (yyval.l_or_exp)->l_and_exp=std::shared_ptr<tree_l_and_exp>((yyvsp[0].l_and_exp));
        }
#line 2407 "parser.tab.c"
    break;

  case 103: /* LOrExp: LOrExp "||" LAndExp  */
#line 862 "parser.y"
        {
            (yyval.l_or_exp) = new tree_l_or_exp();
            (yyval.l_or_exp)->l_or_exp=std::shared_ptr<tree_l_or_exp>((yyvsp[-2].l_or_exp));
            (yyval.l_or_exp)->l_and_exp=std::shared_ptr<tree_l_and_exp>((yyvsp[0].l_and_exp));
        }
#line 2417 "parser.tab.c"
    break;


#line 2421 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 868 "parser.y"

void insertVarible(std::string& type,std::string& id){
    VaribleTable.insert(std::make_pair<std::string, VaribleInfo>(std::string(id),VaribleInfo(type)));
}
void insertFunction(std::string& type,std::string& id){
    FunctionTable.insert(
        std::make_pair<std::string, FunctionInfo>
            (std::string(id),FunctionInfo(type,VaribleTable)));
    VaribleTable.clear();
}
