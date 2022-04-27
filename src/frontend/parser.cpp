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
#line 1 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"

    #include "node.h"
    #include "error.h"
    #include <vector>
    #include <typeinfo>
    extern NODE base_node;
    extern int yyline;
    extern int yylex();
    void yyerror(const char*s){printf("ERROR:Line:%d\n%s\n",yyline,s);}
    void insertVarible(std::string& type,std::string& id);
    void insertFunction(std::string& type,std::string& id);

#line 84 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"

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

#include "parser.h"
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
  YYSYMBOL_TRETURN = 9,                    /* "return"  */
  YYSYMBOL_TCONST = 10,                    /* "const"  */
  YYSYMBOL_TLBPAREN = 11,                  /* "{"  */
  YYSYMBOL_TRBPAREN = 12,                  /* "}"  */
  YYSYMBOL_TMINUS = 13,                    /* "-"  */
  YYSYMBOL_TNOT = 14,                      /* "!"  */
  YYSYMBOL_TWAVE = 15,                     /* "~"  */
  YYSYMBOL_TPLUS = 16,                     /* "+"  */
  YYSYMBOL_TDIV = 17,                      /* "/"  */
  YYSYMBOL_TMOD = 18,                      /* "%"  */
  YYSYMBOL_TMULTI = 19,                    /* "*"  */
  YYSYMBOL_TLPAREN = 20,                   /* "("  */
  YYSYMBOL_TRPAREN = 21,                   /* ")"  */
  YYSYMBOL_TLMPAREN = 22,                  /* "["  */
  YYSYMBOL_TRMPAREN = 23,                  /* "]"  */
  YYSYMBOL_TL = 24,                        /* "<"  */
  YYSYMBOL_TLE = 25,                       /* "<="  */
  YYSYMBOL_TG = 26,                        /* ">"  */
  YYSYMBOL_TGE = 27,                       /* ">="  */
  YYSYMBOL_TNE = 28,                       /* "!="  */
  YYSYMBOL_TE = 29,                        /* "=="  */
  YYSYMBOL_TLOGAND = 30,                   /* "&&"  */
  YYSYMBOL_TLOGOR = 31,                    /* "||"  */
  YYSYMBOL_TASSIGN = 32,                   /* "="  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_CompUnit = 34,                  /* CompUnit  */
  YYSYMBOL_Decl = 35,                      /* Decl  */
  YYSYMBOL_ConstDecl = 36,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 37,              /* ConstDefList  */
  YYSYMBOL_BType = 38,                     /* BType  */
  YYSYMBOL_ConstDef = 39,                  /* ConstDef  */
  YYSYMBOL_ConstInitVal = 40,              /* ConstInitVal  */
  YYSYMBOL_ConstExp = 41,                  /* ConstExp  */
  YYSYMBOL_VarDecl = 42,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 43,                /* VarDefList  */
  YYSYMBOL_VarDef = 44,                    /* VarDef  */
  YYSYMBOL_InitVal = 45,                   /* InitVal  */
  YYSYMBOL_FuncDef = 46,                   /* FuncDef  */
  YYSYMBOL_FuncType = 47,                  /* FuncType  */
  YYSYMBOL_Block = 48,                     /* Block  */
  YYSYMBOL_BlockItemList = 49,             /* BlockItemList  */
  YYSYMBOL_BlockItem = 50,                 /* BlockItem  */
  YYSYMBOL_Stmt = 51,                      /* Stmt  */
  YYSYMBOL_LVal = 52,                      /* LVal  */
  YYSYMBOL_Number = 53,                    /* Number  */
  YYSYMBOL_PrimaryExp = 54,                /* PrimaryExp  */
  YYSYMBOL_Exp = 55,                       /* Exp  */
  YYSYMBOL_UnaryExp = 56,                  /* UnaryExp  */
  YYSYMBOL_MulExp = 57,                    /* MulExp  */
  YYSYMBOL_AddExp = 58,                    /* AddExp  */
  YYSYMBOL_RelExp = 59,                    /* RelExp  */
  YYSYMBOL_EqExp = 60,                     /* EqExp  */
  YYSYMBOL_LAndExp = 61,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 62                     /* LOrExp  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   86

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    88,    94,    98,   104,   110,   114,   119,
     124,   131,   137,   143,   150,   154,   160,   164,   171,   178,
     186,   193,   199,   203,   209,   213,   219,   224,   227,   230,
     234,   237,   242,   248,   254,   258,   262,   268,   274,   278,
     283,   288,   295,   299,   305,   311,   319,   323,   329,   337,
     341,   347,   353,   359,   367,   371,   377,   385,   389,   397,
     401
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
  "TINTEGER", "\";\"", "\",\"", "\"main\"", "\"int\"", "\"return\"",
  "\"const\"", "\"{\"", "\"}\"", "\"-\"", "\"!\"", "\"~\"", "\"+\"",
  "\"/\"", "\"%\"", "\"*\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"<\"",
  "\"<=\"", "\">\"", "\">=\"", "\"!=\"", "\"==\"", "\"&&\"", "\"||\"",
  "\"=\"", "$accept", "CompUnit", "Decl", "ConstDecl", "ConstDefList",
  "BType", "ConstDef", "ConstInitVal", "ConstExp", "VarDecl", "VarDefList",
  "VarDef", "InitVal", "FuncDef", "FuncType", "Block", "BlockItemList",
  "BlockItem", "Stmt", "LVal", "Number", "PrimaryExp", "Exp", "UnaryExp",
  "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      36,   -40,    48,    36,    49,   -40,   -40,    33,    34,    50,
       3,   -40,   -40,   -40,   -40,   -40,    29,    46,    43,    43,
      43,    43,   -40,   -40,    57,   -40,   -40,    52,     3,   -40,
      30,   -40,   -40,    60,   -40,    18,     2,     0,   -19,    37,
      35,   -40,   -40,    63,    66,   -40,   -40,   -40,    51,    38,
      68,    65,   -40,   -40,    43,   -40,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,   -40,
      42,    71,    72,   -40,    43,   -40,    57,    74,   -40,   -40,
     -40,    18,    18,     2,     2,     2,     2,     0,     0,   -19,
      37,    43,   -40,    66,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    20,     0,     2,     0,     1,     3,     0,     0,     0,
       0,    19,    32,    33,    27,     9,     0,     0,     0,     0,
       0,     0,    24,     4,     0,     5,    29,     0,    22,    25,
      35,    36,    38,     0,    42,    46,    49,    54,    57,    59,
      37,    30,    35,     0,     0,    40,    41,    39,     0,    16,
       0,    14,    21,    23,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     7,    34,     0,    13,     0,     0,    44,    45,
      43,    48,    47,    50,    52,    51,    53,    56,    55,    58,
      60,     0,     6,     0,    17,    18,    15,    26,    10,    11,
      12,     8
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,    77,   -40,   -40,   -12,    67,   -40,   -40,   -40,   -40,
       1,   -40,   -40,   -40,   -40,    73,    55,   -40,   -40,    -6,
     -40,   -40,   -16,   -17,   -39,   -33,   -15,    19,    17,   -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    22,    23,    71,    24,    72,    98,    99,    25,
      50,    51,    94,     3,     4,    26,    27,    28,    29,    42,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      43,    45,    46,    47,    30,    48,    12,    13,    14,    65,
      66,    15,    16,    17,    10,    59,    18,    19,    60,    20,
      81,    82,    30,    21,    61,    62,    63,    64,    83,    84,
      85,    86,    12,    13,    41,    56,    57,    58,    77,    78,
      79,    80,    18,    19,     1,    20,    12,    13,     5,    21,
      87,    88,     7,     8,    15,     9,    18,    19,    95,    20,
      49,    10,    54,    21,    52,    55,    68,    67,    69,    70,
      74,    76,    73,    75,    91,   100,    92,    96,    93,    97,
       6,   101,    11,    53,    44,    90,    89
};

static const yytype_int8 yycheck[] =
{
      16,    18,    19,    20,    10,    21,     3,     4,     5,    28,
      29,     8,     9,    10,    11,    13,    13,    14,    16,    16,
      59,    60,    28,    20,    24,    25,    26,    27,    61,    62,
      63,    64,     3,     4,     5,    17,    18,    19,    54,    56,
      57,    58,    13,    14,     8,    16,     3,     4,     0,    20,
      65,    66,     3,    20,     8,    21,    13,    14,    74,    16,
       3,    11,    32,    20,    12,     5,    31,    30,     5,     3,
      32,     6,    21,     5,    32,    91,     5,    76,     6,     5,
       3,    93,     9,    28,    17,    68,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    34,    46,    47,     0,    34,     3,    20,    21,
      11,    48,     3,     4,     5,     8,     9,    10,    13,    14,
      16,    20,    35,    36,    38,    42,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     5,    52,    55,    38,    56,    56,    56,    55,     3,
      43,    44,    12,    49,    32,     5,    17,    18,    19,    13,
      16,    24,    25,    26,    27,    28,    29,    30,    31,     5,
       3,    37,    39,    21,    32,     5,     6,    55,    56,    56,
      56,    57,    57,    58,    58,    58,    58,    59,    59,    60,
      61,    32,     5,     6,    45,    55,    43,     5,    40,    41,
      55,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    36,    37,    37,    38,
      39,    40,    41,    42,    43,    43,    44,    44,    45,    46,
      47,    48,    49,    49,    50,    50,    51,    51,    51,    51,
      51,    51,    52,    53,    54,    54,    54,    55,    56,    56,
      56,    56,    57,    57,    57,    57,    58,    58,    58,    59,
      59,    59,    59,    59,    60,    60,    60,    61,    61,    62,
      62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     4,     1,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     2,     1,     1,     4,     1,     2,     1,
       2,     3,     1,     1,     3,     1,     1,     1,     1,     2,
       2,     2,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3
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
#line 86 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {base_node.add_child((yyvsp[0].node));
        WARNNING("CompUnit->FuncDef ");}
#line 1199 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 3: /* CompUnit: FuncDef CompUnit  */
#line 89 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {base_node.add_child((yyvsp[-1].node));
        WARNNING("CompUnit->FuncDef ");}
#line 1206 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 4: /* Decl: ConstDecl  */
#line 95 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Decl);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("Decl->ConstDecl ");}
#line 1214 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 5: /* Decl: VarDecl  */
#line 99 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Decl);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("Decl->VarDecl ");}
#line 1222 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 6: /* ConstDecl: "const" BType ConstDefList ";"  */
#line 105 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(ConstDecl);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->add_child((yyvsp[-1].node));
        WARNNING("ConstDecl->const BType ConstDefList ");}
#line 1231 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 7: /* ConstDefList: ConstDef  */
#line 111 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(ConstDefList);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("ConstDefList->ConstDef ");}
#line 1239 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 8: /* ConstDefList: ConstDef "," ConstDefList  */
#line 115 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyvsp[0].node)->add_child((yyvsp[-2].node));
        (yyval.node) = (yyvsp[0].node);
        WARNNING("ConstDefList->ConstDef , ConstDefList ");}
#line 1247 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 9: /* BType: "int"  */
#line 120 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(BType);
        (yyval.node)->b_type = std::string("int");
        WARNNING("BType->int ");}
#line 1255 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 10: /* ConstDef: TIDENTIFIER "=" ConstInitVal  */
#line 125 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(ConstDef);
        (yyval.node)->LVal = *(yyvsp[-2].string);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("ConstDef->TIDENTIFIER = ConstInitVal ");}
#line 1264 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 11: /* ConstInitVal: ConstExp  */
#line 132 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(ConstInitVal);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("ConstInitVal->ConstExp ");}
#line 1272 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 12: /* ConstExp: Exp  */
#line 138 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Exp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("ConstExp->Exp ");}
#line 1280 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 13: /* VarDecl: BType VarDefList ";"  */
#line 144 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
       {(yyval.node) = base_node.new_node(VarDecl);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->add_child((yyvsp[-1].node));
        WARNNING("VarDecl->BType VarDefList ; ");}
#line 1289 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 14: /* VarDefList: VarDef  */
#line 151 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(VarDefList);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("VarDefList->VarDef ");}
#line 1297 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 15: /* VarDefList: VarDef "," VarDefList  */
#line 155 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyvsp[0].node)->add_child((yyvsp[-2].node));
        (yyval.node) = (yyvsp[0].node);
        WARNNING("VarDefList->VarDef , VarDefList ");}
#line 1305 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 16: /* VarDef: TIDENTIFIER  */
#line 161 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(VarDef);
        (yyval.node)->LVal = *(yyvsp[0].string);
        WARNNING("VarDef->TIDENTIFIER ");}
#line 1313 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 17: /* VarDef: TIDENTIFIER "=" InitVal  */
#line 165 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(VarDef);
        (yyval.node)->LVal = *(yyvsp[-2].string);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("VarDef->TIDENTIFIER = InitVal ");}
#line 1322 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 18: /* InitVal: Exp  */
#line 172 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(InitVal);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("InitVal->exp ");}
#line 1330 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 19: /* FuncDef: FuncType TIDENTIFIER "(" ")" Block  */
#line 179 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(FuncDef);
        (yyval.node)->add_child((yyvsp[-4].node));
        (yyval.node)->add_child((yyvsp[0].node));
        (yyval.node)->func_name = *(yyvsp[-3].string);
        WARNNING("FuncDef->ftype id () block ");}
#line 1340 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 20: /* FuncType: "int"  */
#line 187 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(FuncType);
        (yyval.node)->func_type = std::string("int");
        WARNNING("FuncType->int ");}
#line 1348 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 21: /* Block: "{" BlockItemList "}"  */
#line 194 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Block);
        (yyval.node)->add_child((yyvsp[-1].node));
        WARNNING("Block->{BlockItemList} ");}
#line 1356 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 22: /* BlockItemList: BlockItem  */
#line 200 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(BlockItemList);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("BlockItemList->BlockItem ");}
#line 1364 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 23: /* BlockItemList: BlockItem BlockItemList  */
#line 204 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyvsp[0].node)->add_child((yyvsp[-1].node));
        (yyval.node) = (yyvsp[0].node);
        WARNNING("BlockItemList->BlockItem BlockItemList");}
#line 1372 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 24: /* BlockItem: Decl  */
#line 210 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(BlockItem);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("BlockItem->Decl ");}
#line 1380 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 25: /* BlockItem: Stmt  */
#line 214 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(BlockItem);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("BlockItem->Stmt ");}
#line 1388 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 26: /* Stmt: LVal "=" Exp ";"  */
#line 220 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Stmt);
        (yyval.node)->add_child((yyvsp[-3].node));
        (yyval.node)->add_child((yyvsp[-1].node));
        WARNNING("Stmt->return exp ");}
#line 1397 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 27: /* Stmt: ";"  */
#line 225 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Stmt);
        WARNNING("丢弃 Stmt->; ");}
#line 1404 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 28: /* Stmt: Exp ";"  */
#line 228 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Stmt);
        WARNNING("丢弃 Stmt->Exp ; ");}
#line 1411 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 29: /* Stmt: Block  */
#line 231 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Stmt);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("Stmt->Block ");}
#line 1419 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 30: /* Stmt: "return" ";"  */
#line 235 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Stmt);
        WARNNING("Stmt->return; ");}
#line 1426 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 31: /* Stmt: "return" Exp ";"  */
#line 238 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Stmt);
        (yyval.node)->add_child((yyvsp[-1].node));
        WARNNING("Stmt->return exp ");}
#line 1434 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 32: /* LVal: TIDENTIFIER  */
#line 243 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(LVal);
        (yyval.node)->LVal = *(yyvsp[0].string);
        WARNNING("LVal->TIDENTIFIER ");}
#line 1442 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 33: /* Number: TINTEGER  */
#line 249 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Number);
        (yyval.node)->intv = atoi((yyvsp[0].string)->c_str());
        WARNNING("Number->integer ");}
#line 1450 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 34: /* PrimaryExp: "(" Exp ")"  */
#line 255 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(PrimaryExp);
        (yyval.node)->add_child((yyvsp[-1].node));
        WARNNING("PrimaryExp->(exp) ");}
#line 1458 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 35: /* PrimaryExp: LVal  */
#line 259 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(PrimaryExp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("PrimaryExp->LVal ");}
#line 1466 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 36: /* PrimaryExp: Number  */
#line 263 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(PrimaryExp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("PrimaryExp->(num) ");}
#line 1474 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 37: /* Exp: LOrExp  */
#line 269 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(Exp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("Exp->lorexp ");}
#line 1482 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 38: /* UnaryExp: PrimaryExp  */
#line 275 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(UnaryExp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("UnaryExp->PrimaryExp ");}
#line 1490 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 39: /* UnaryExp: "+" UnaryExp  */
#line 279 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(UnaryExp);
        (yyval.node)->add_child((yyvsp[0].node));
        (yyval.node)->op = "+";
        WARNNING("UnaryExp-> + UnaryExp ");}
#line 1499 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 40: /* UnaryExp: "-" UnaryExp  */
#line 284 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(UnaryExp);
        (yyval.node)->add_child((yyvsp[0].node));
        (yyval.node)->op = "-";
        WARNNING("UnaryExp-> - UnaryExp ");}
#line 1508 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 41: /* UnaryExp: "!" UnaryExp  */
#line 289 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(UnaryExp);
        (yyval.node)->add_child((yyvsp[0].node));
        (yyval.node)->op = "!";
        WARNNING("UnaryExp-> ! UnaryExp ");}
#line 1517 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 42: /* MulExp: UnaryExp  */
#line 296 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(MulExp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("MulExp->UnaryExp ");}
#line 1525 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 43: /* MulExp: MulExp "*" UnaryExp  */
#line 300 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(MulExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "*";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("MulExp->MulExp * UnaryExp ");}
#line 1535 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 44: /* MulExp: MulExp "/" UnaryExp  */
#line 306 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(MulExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "/";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("MulExp->MulExp / UnaryExp ");}
#line 1545 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 45: /* MulExp: MulExp "%" UnaryExp  */
#line 312 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(MulExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "%";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("MulExp->MulExp %% UnaryExp ");}
#line 1555 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 46: /* AddExp: MulExp  */
#line 320 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(AddExp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("AddExp->MulExp ");}
#line 1563 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 47: /* AddExp: AddExp "+" MulExp  */
#line 324 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(AddExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "+";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("AddExp->AddExp + MulExp");}
#line 1573 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 48: /* AddExp: AddExp "-" MulExp  */
#line 330 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(AddExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "-";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("AddExp->AddExp - MulExp ");}
#line 1583 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 49: /* RelExp: AddExp  */
#line 338 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(RelExp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("RelExp->AddExp ");}
#line 1591 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 50: /* RelExp: RelExp "<" AddExp  */
#line 342 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(RelExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "<";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("RelExp->RelExp < AddExp ");}
#line 1601 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 51: /* RelExp: RelExp ">" AddExp  */
#line 348 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(RelExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = ">";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("RelExp->RelExp > AddExp ");}
#line 1611 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 52: /* RelExp: RelExp "<=" AddExp  */
#line 354 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(RelExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "<=";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("RelExp->RelExp <= AddExp ");}
#line 1621 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 53: /* RelExp: RelExp ">=" AddExp  */
#line 360 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(RelExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = ">=";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("RelExp->RelExp >= AddExp ");}
#line 1631 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 54: /* EqExp: RelExp  */
#line 368 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(EqExp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("EqExp->RelExp ");}
#line 1639 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 55: /* EqExp: EqExp "==" RelExp  */
#line 372 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(EqExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "==";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("EqExp->EqExp == RelExp ");}
#line 1649 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 56: /* EqExp: EqExp "!=" RelExp  */
#line 378 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(EqExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "!=";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("EqExp->EqExp != RelExp ");}
#line 1659 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 57: /* LAndExp: EqExp  */
#line 386 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(LAndExp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("LAndExp->EqExp ");}
#line 1667 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 58: /* LAndExp: LAndExp "&&" EqExp  */
#line 390 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(LAndExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "&&";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("LAndExp->LAndExp && EqExp ");}
#line 1677 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 59: /* LOrExp: LAndExp  */
#line 398 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(LOrExp);
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("LOrExp->LAndExp ");}
#line 1685 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;

  case 60: /* LOrExp: LOrExp "||" LAndExp  */
#line 402 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"
        {(yyval.node) = base_node.new_node(LOrExp);
        (yyval.node)->add_child((yyvsp[-2].node));
        (yyval.node)->op = "||";
        (yyval.node)->add_child((yyvsp[0].node));
        WARNNING("LOrExp->LOrExp || LAndExp ");}
#line 1695 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"
    break;


#line 1699 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.cpp"

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

#line 408 "/home/yonchicy/compiler/wlkl-compiler/src/frontend/parser.y"

void insertVarible(std::string& type,std::string& id){
    VaribleTable.insert(std::make_pair<std::string, VaribleInfo>(std::string(id),VaribleInfo(type)));
}
void insertFunction(std::string& type,std::string& id){
    FunctionTable.insert(
        std::make_pair<std::string, FunctionInfo>
            (std::string(id),FunctionInfo(type,VaribleTable)));
    VaribleTable.clear();
}
