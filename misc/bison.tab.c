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
#line 1 "./misc/bison.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int yyparse(void);
extern int yylex(void);
extern FILE *yyin;
void yyerror(const char *);

#line 83 "./misc/bison.tab.c"

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

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_LPAR = 3,                 /* TOKEN_LPAR  */
  YYSYMBOL_TOKEN_RPAR = 4,                 /* TOKEN_RPAR  */
  YYSYMBOL_TOKEN_LBRACKET = 5,             /* TOKEN_LBRACKET  */
  YYSYMBOL_TOKEN_RBRACKET = 6,             /* TOKEN_RBRACKET  */
  YYSYMBOL_TOKEN_LCBRACKET = 7,            /* TOKEN_LCBRACKET  */
  YYSYMBOL_TOKEN_RCBRACKET = 8,            /* TOKEN_RCBRACKET  */
  YYSYMBOL_TOKEN_PLUS = 9,                 /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 10,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_PERCENT = 11,             /* TOKEN_PERCENT  */
  YYSYMBOL_TOKEN_DOLLAR = 12,              /* TOKEN_DOLLAR  */
  YYSYMBOL_TOKEN_SEMI = 13,                /* TOKEN_SEMI  */
  YYSYMBOL_TOKEN_COLON = 14,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_COMMA = 15,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_SHL = 16,                 /* TOKEN_SHL  */
  YYSYMBOL_TOKEN_SHR = 17,                 /* TOKEN_SHR  */
  YYSYMBOL_TOKEN_COMMENT = 18,             /* TOKEN_COMMENT  */
  YYSYMBOL_TOKEN_GLOBAL = 19,              /* TOKEN_GLOBAL  */
  YYSYMBOL_TOKEN_EXTERN = 20,              /* TOKEN_EXTERN  */
  YYSYMBOL_TOKEN_SECTION = 21,             /* TOKEN_SECTION  */
  YYSYMBOL_TOKEN_WORD = 22,                /* TOKEN_WORD  */
  YYSYMBOL_TOKEN_SKIP = 23,                /* TOKEN_SKIP  */
  YYSYMBOL_TOKEN_ASCII = 24,               /* TOKEN_ASCII  */
  YYSYMBOL_TOKEN_TYPE = 25,                /* TOKEN_TYPE  */
  YYSYMBOL_TOKEN_END = 26,                 /* TOKEN_END  */
  YYSYMBOL_TOKEN_HALT = 27,                /* TOKEN_HALT  */
  YYSYMBOL_TOKEN_INT = 28,                 /* TOKEN_INT  */
  YYSYMBOL_TOKEN_IRET = 29,                /* TOKEN_IRET  */
  YYSYMBOL_TOKEN_CALL = 30,                /* TOKEN_CALL  */
  YYSYMBOL_TOKEN_RET = 31,                 /* TOKEN_RET  */
  YYSYMBOL_TOKEN_JMP = 32,                 /* TOKEN_JMP  */
  YYSYMBOL_TOKEN_BEQ = 33,                 /* TOKEN_BEQ  */
  YYSYMBOL_TOKEN_BNE = 34,                 /* TOKEN_BNE  */
  YYSYMBOL_TOKEN_BGT = 35,                 /* TOKEN_BGT  */
  YYSYMBOL_TOKEN_PUSH = 36,                /* TOKEN_PUSH  */
  YYSYMBOL_TOKEN_POP = 37,                 /* TOKEN_POP  */
  YYSYMBOL_TOKEN_XCHG = 38,                /* TOKEN_XCHG  */
  YYSYMBOL_TOKEN_ADD = 39,                 /* TOKEN_ADD  */
  YYSYMBOL_TOKEN_SUB = 40,                 /* TOKEN_SUB  */
  YYSYMBOL_TOKEN_MUL = 41,                 /* TOKEN_MUL  */
  YYSYMBOL_TOKEN_DIV = 42,                 /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_NOT = 43,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_AND = 44,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 45,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_XOR = 46,                 /* TOKEN_XOR  */
  YYSYMBOL_TOKEN_SHLL = 47,                /* TOKEN_SHLL  */
  YYSYMBOL_TOKEN_SHRR = 48,                /* TOKEN_SHRR  */
  YYSYMBOL_TOKEN_LD = 49,                  /* TOKEN_LD  */
  YYSYMBOL_TOKEN_ST = 50,                  /* TOKEN_ST  */
  YYSYMBOL_TOKEN_CSRRD = 51,               /* TOKEN_CSRRD  */
  YYSYMBOL_TOKEN_CSRWR = 52,               /* TOKEN_CSRWR  */
  YYSYMBOL_TOKEN_NUM = 53,                 /* TOKEN_NUM  */
  YYSYMBOL_TOKEN_IDENT = 54,               /* TOKEN_IDENT  */
  YYSYMBOL_TOKEN_STRING = 55,              /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_LABEL = 56,               /* TOKEN_LABEL  */
  YYSYMBOL_TOKEN_GPR = 57,                 /* TOKEN_GPR  */
  YYSYMBOL_TOKEN_STATUS = 58,              /* TOKEN_STATUS  */
  YYSYMBOL_TOKEN_HANDLER = 59,             /* TOKEN_HANDLER  */
  YYSYMBOL_TOKEN_CAUSE = 60,               /* TOKEN_CAUSE  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_prog = 62,                      /* prog  */
  YYSYMBOL_lines = 63,                     /* lines  */
  YYSYMBOL_line = 64,                      /* line  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_labela = 66,                    /* labela  */
  YYSYMBOL_directive = 67,                 /* directive  */
  YYSYMBOL_global_list = 68,               /* global_list  */
  YYSYMBOL_word_list = 69,                 /* word_list  */
  YYSYMBOL_word = 70,                      /* word  */
  YYSYMBOL_extern_list = 71,               /* extern_list  */
  YYSYMBOL_instr = 72,                     /* instr  */
  YYSYMBOL_reg_list = 73,                  /* reg_list  */
  YYSYMBOL_op = 74,                        /* op  */
  YYSYMBOL_jump_operand = 75,              /* jump_operand  */
  YYSYMBOL_csreg = 76                      /* csreg  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  89
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   113,   113,   118,   119,   123,   124,   125,   126,   127,
     128,   132,   133,   134,   135,   139,   145,   146,   147,   150,
     151,   154,   157,   160,   166,   169,   175,   176,   179,   182,
     187,   190,   196,   199,   202,   205,   208,   211,   214,   217,
     220,   223,   224,   225,   228,   231,   234,   237,   240,   243,
     246,   249,   252,   255,   258,   261,   264,   267,   270,   273,
     276,   282,   285,   291,   294,   297,   300,   303,   306,   309,
     312,   315,   324,   327,   333,   334,   335
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_LPAR",
  "TOKEN_RPAR", "TOKEN_LBRACKET", "TOKEN_RBRACKET", "TOKEN_LCBRACKET",
  "TOKEN_RCBRACKET", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_PERCENT",
  "TOKEN_DOLLAR", "TOKEN_SEMI", "TOKEN_COLON", "TOKEN_COMMA", "TOKEN_SHL",
  "TOKEN_SHR", "TOKEN_COMMENT", "TOKEN_GLOBAL", "TOKEN_EXTERN",
  "TOKEN_SECTION", "TOKEN_WORD", "TOKEN_SKIP", "TOKEN_ASCII", "TOKEN_TYPE",
  "TOKEN_END", "TOKEN_HALT", "TOKEN_INT", "TOKEN_IRET", "TOKEN_CALL",
  "TOKEN_RET", "TOKEN_JMP", "TOKEN_BEQ", "TOKEN_BNE", "TOKEN_BGT",
  "TOKEN_PUSH", "TOKEN_POP", "TOKEN_XCHG", "TOKEN_ADD", "TOKEN_SUB",
  "TOKEN_MUL", "TOKEN_DIV", "TOKEN_NOT", "TOKEN_AND", "TOKEN_OR",
  "TOKEN_XOR", "TOKEN_SHLL", "TOKEN_SHRR", "TOKEN_LD", "TOKEN_ST",
  "TOKEN_CSRRD", "TOKEN_CSRWR", "TOKEN_NUM", "TOKEN_IDENT", "TOKEN_STRING",
  "TOKEN_LABEL", "TOKEN_GPR", "TOKEN_STATUS", "TOKEN_HANDLER",
  "TOKEN_CAUSE", "$accept", "prog", "lines", "line", "statement", "labela",
  "directive", "global_list", "word_list", "word", "extern_list", "instr",
  "reg_list", "op", "jump_operand", "csreg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      38,   -16,   -11,   -51,    31,    41,    48,   -48,    50,    49,
      51,   -51,   -51,   -51,   -51,    43,   -51,    43,    29,    52,
      54,    -5,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -4,    65,    33,    66,   -51,   106,    38,   -51,
     -51,    -7,    89,    90,    95,   109,   -51,   110,   -51,   111,
     -51,   -51,   -51,   112,   -51,   -51,   -51,    77,   -51,   -51,
     -51,   -51,   117,   118,   119,    78,   -51,   -51,   121,   122,
     123,   124,   125,   -51,   126,   127,   128,    87,    45,   -51,
     -51,   -51,   130,   131,   -51,   -51,   -51,   132,   133,   -51,
     -51,   -51,   -51,   -51,   -51,    92,    93,    97,    98,   -48,
     -51,    96,    99,   100,   -51,    32,   101,   102,   103,   104,
     105,   107,   108,   113,    42,   -51,   -51,   114,    -4,   115,
      33,   -51,   -51,   -51,   -51,   -51,   139,   140,   148,   -51,
     116,   -51,   151,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -50,   -51,   -51,   -51,   -51,    43,    43,    43,   -51,    53,
     161,   162,   163,   -51,   -51,   -51,   129,   134,   -51,   -51,
     -51,   -51,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    23,    32,    33,    34,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     2,     3,
       7,     8,    13,    11,     0,     0,    24,    16,    30,    17,
      18,    28,    29,    19,    27,    20,    21,     0,    72,    73,
      35,    37,     0,     0,     0,     0,    42,    43,     0,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,    63,
      64,    67,     0,     0,    74,    75,    76,     0,     0,     1,
       4,     9,     6,    14,    12,     0,     0,     0,     0,     0,
      22,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    66,     0,     0,     0,
       0,    55,    56,    25,    31,    26,     0,     0,     0,    41,
       0,    44,    45,    48,    49,    50,    52,    53,    54,    68,
       0,    57,    58,    59,    60,     0,     0,     0,    61,     0,
       0,     0,     0,    38,    39,    40,     0,     0,    70,    71,
      69,    46,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,   -51,   136,   135,   -51,   -51,   -51,   -51,    76,
     -51,   -51,   -51,    67,   -17,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    37,    38,    39,    40,    41,    42,    47,    53,    54,
      49,    43,   105,    82,    60,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    77,    65,   150,   151,    51,    52,   152,    78,     1,
       2,    91,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
     129,    44,    32,    33,    34,    35,    45,   130,   139,    79,
      80,   140,    66,    81,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    46,    62,    32,    33,    34,
      35,    84,    85,    86,    36,    48,    58,    59,   115,   116,
     156,   157,    50,    55,    56,    57,    89,    93,    94,    63,
      95,    64,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    83,    88,    96,    97,    98,    99,   153,   154,
     155,   100,   101,   102,   103,   104,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   117,   118,   119,   120,   121,
     122,   123,   124,   126,   145,   146,   127,   128,   131,   132,
     133,   134,   135,   147,   136,   137,   149,   158,   159,   160,
     138,   141,   143,   148,    90,   125,    92,     0,     0,     0,
       0,     0,   161,     0,     0,   142,     0,   162,   144
};

static const yytype_int16 yycheck[] =
{
      17,     5,     7,    53,    54,    53,    54,    57,    12,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       8,    57,    49,    50,    51,    52,    57,    15,     6,    53,
      54,     9,    57,    57,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    54,    57,    49,    50,    51,
      52,    58,    59,    60,    56,    54,    53,    54,    53,    54,
      47,    48,    54,    53,    55,    54,     0,    18,    18,    57,
      15,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    15,    15,    15,    15,   145,   146,
     147,    54,    15,    15,    15,    57,    15,    15,    15,    15,
      15,    15,    15,    15,    57,    15,    15,    15,    15,    57,
      57,    54,    54,    57,    15,    15,    57,    57,    57,    57,
      57,    57,    57,    15,    57,    57,    15,     6,     6,     6,
      57,    57,    57,    57,    38,    99,    41,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,   118,    -1,    53,   120
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    49,    50,    51,    52,    56,    62,    63,    64,
      65,    66,    67,    72,    57,    57,    54,    68,    54,    71,
      54,    53,    54,    69,    70,    53,    55,    54,    53,    54,
      75,    75,    57,    57,    57,     7,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,     5,    12,    53,
      54,    57,    74,    57,    58,    59,    60,    76,    57,     0,
      64,    18,    65,    18,    18,    15,    15,    15,    15,    15,
      54,    15,    15,    15,    57,    73,    15,    15,    15,    15,
      15,    15,    15,    15,    57,    53,    54,    15,    15,    15,
      15,    57,    57,    54,    54,    70,    57,    57,    57,     8,
      15,    57,    57,    57,    57,    57,    57,    57,    57,     6,
       9,    57,    74,    57,    76,    15,    15,    15,    57,    15,
      53,    54,    57,    75,    75,    75,    47,    48,     6,     6,
       6,    53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    64,    64,    64,
      64,    65,    65,    65,    65,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    75,    75,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     2,     1,     1,     2,
       1,     1,     2,     1,     2,     1,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     3,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     2,     1,     2,     6,     6,
       6,     4,     2,     2,     4,     4,     7,     7,     4,     4,
       4,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     1,     1,     1,     2,     2,     1,     3,     5,
       5,     5,     1,     1,     1,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 15: /* labela: TOKEN_LABEL  */
#line 139 "./misc/bison.y"
                               {
			 handle_label((yyvsp[0].ident));
		}
#line 1531 "./misc/bison.tab.c"
    break;

  case 18: /* directive: TOKEN_SECTION TOKEN_IDENT  */
#line 147 "./misc/bison.y"
                                            { 
			 start_of_section((yyvsp[0].ident)); 
		}
#line 1539 "./misc/bison.tab.c"
    break;

  case 20: /* directive: TOKEN_SKIP TOKEN_NUM  */
#line 151 "./misc/bison.y"
                                       {
			 handle_skip((yyvsp[0].num));
		}
#line 1547 "./misc/bison.tab.c"
    break;

  case 21: /* directive: TOKEN_ASCII TOKEN_STRING  */
#line 154 "./misc/bison.y"
                                           { 
			 handle_ascii((yyvsp[0].ident));
		}
#line 1555 "./misc/bison.tab.c"
    break;

  case 22: /* directive: TOKEN_TYPE TOKEN_IDENT TOKEN_IDENT  */
#line 157 "./misc/bison.y"
                                                    { 
			 handle_type((yyvsp[-1].ident),(yyvsp[0].ident)); 
		}
#line 1563 "./misc/bison.tab.c"
    break;

  case 23: /* directive: TOKEN_END  */
#line 160 "./misc/bison.y"
                            { 
			 handle_end(); 
		}
#line 1571 "./misc/bison.tab.c"
    break;

  case 24: /* global_list: TOKEN_IDENT  */
#line 166 "./misc/bison.y"
                              {
			 handle_global((yyvsp[0].ident));
		}
#line 1579 "./misc/bison.tab.c"
    break;

  case 25: /* global_list: global_list TOKEN_COMMA TOKEN_IDENT  */
#line 169 "./misc/bison.y"
                                                      {
			 handle_global((yyvsp[0].ident));
		}
#line 1587 "./misc/bison.tab.c"
    break;

  case 28: /* word: TOKEN_NUM  */
#line 179 "./misc/bison.y"
                          {
			 handle_word((yyvsp[0].num)); 
		}
#line 1595 "./misc/bison.tab.c"
    break;

  case 29: /* word: TOKEN_IDENT  */
#line 182 "./misc/bison.y"
                             {
			 handle_word((yyvsp[0].ident)); 
		}
#line 1603 "./misc/bison.tab.c"
    break;

  case 30: /* extern_list: TOKEN_IDENT  */
#line 187 "./misc/bison.y"
                          {
			 handle_extern((yyvsp[0].ident)); 
		}
#line 1611 "./misc/bison.tab.c"
    break;

  case 31: /* extern_list: extern_list TOKEN_COMMA TOKEN_IDENT  */
#line 190 "./misc/bison.y"
                                                      {
			handle_extern((yyvsp[0].ident)); 
		}
#line 1619 "./misc/bison.tab.c"
    break;

  case 32: /* instr: TOKEN_HALT  */
#line 196 "./misc/bison.y"
                             { 
			 ins_halt();
		}
#line 1627 "./misc/bison.tab.c"
    break;

  case 33: /* instr: TOKEN_INT  */
#line 199 "./misc/bison.y"
                            { 
			 ins_int();
		}
#line 1635 "./misc/bison.tab.c"
    break;

  case 34: /* instr: TOKEN_IRET  */
#line 202 "./misc/bison.y"
                             { 
			 ins_iret();
		}
#line 1643 "./misc/bison.tab.c"
    break;

  case 35: /* instr: TOKEN_CALL jump_operand  */
#line 205 "./misc/bison.y"
                                         { 
			ins_call((yyvsp[0].oper)); 
		}
#line 1651 "./misc/bison.tab.c"
    break;

  case 36: /* instr: TOKEN_RET  */
#line 208 "./misc/bison.y"
                            { 
			ins_ret();
		}
#line 1659 "./misc/bison.tab.c"
    break;

  case 37: /* instr: TOKEN_JMP jump_operand  */
#line 211 "./misc/bison.y"
                                         { 
			 ins_jmp((yyvsp[0].oper)); 
		}
#line 1667 "./misc/bison.tab.c"
    break;

  case 38: /* instr: TOKEN_BEQ TOKEN_GPR TOKEN_COMMA TOKEN_GPR TOKEN_COMMA jump_operand  */
#line 214 "./misc/bison.y"
                                                                                     { 
			ins_beq_bne_bgt(1,(yyvsp[-4].reg),(yyvsp[-2].reg),(yyvsp[0].oper)); 
		}
#line 1675 "./misc/bison.tab.c"
    break;

  case 39: /* instr: TOKEN_BNE TOKEN_GPR TOKEN_COMMA TOKEN_GPR TOKEN_COMMA jump_operand  */
#line 217 "./misc/bison.y"
                                                                                     {  
			ins_beq_bne_bgt(2,(yyvsp[-4].reg),(yyvsp[-2].reg),(yyvsp[0].oper)); 
		}
#line 1683 "./misc/bison.tab.c"
    break;

  case 40: /* instr: TOKEN_BGT TOKEN_GPR TOKEN_COMMA TOKEN_GPR TOKEN_COMMA jump_operand  */
#line 220 "./misc/bison.y"
                                                                                     { 
			ins_beq_bne_bgt(3,(yyvsp[-4].reg),(yyvsp[-2].reg),(yyvsp[0].oper)); 
		}
#line 1691 "./misc/bison.tab.c"
    break;

  case 42: /* instr: TOKEN_PUSH TOKEN_GPR  */
#line 224 "./misc/bison.y"
                                      { ins_push((yyvsp[0].reg)); }
#line 1697 "./misc/bison.tab.c"
    break;

  case 43: /* instr: TOKEN_POP TOKEN_GPR  */
#line 225 "./misc/bison.y"
                                      { 
			ins_pop((yyvsp[0].reg));
		}
#line 1705 "./misc/bison.tab.c"
    break;

  case 44: /* instr: TOKEN_XCHG TOKEN_GPR TOKEN_COMMA TOKEN_GPR  */
#line 228 "./misc/bison.y"
                                                             {
			 ins_aritmlog(0x40,0,(yyvsp[-2].reg),(yyvsp[0].reg));
		}
#line 1713 "./misc/bison.tab.c"
    break;

  case 45: /* instr: TOKEN_ADD TOKEN_GPR TOKEN_COMMA TOKEN_GPR  */
#line 231 "./misc/bison.y"
                                                           {
			ins_aritmlog(0x50,(yyvsp[0].reg),(yyvsp[0].reg),(yyvsp[-2].reg));
		}
#line 1721 "./misc/bison.tab.c"
    break;

  case 46: /* instr: TOKEN_ADD TOKEN_GPR TOKEN_COMMA TOKEN_GPR TOKEN_COMMA TOKEN_SHLL TOKEN_NUM  */
#line 234 "./misc/bison.y"
                                                                                            {
			ins_aritm_shifted(0x50,(yyvsp[-3].reg),(yyvsp[-3].reg),(yyvsp[-5].reg),1,(yyvsp[0].num));
		}
#line 1729 "./misc/bison.tab.c"
    break;

  case 47: /* instr: TOKEN_ADD TOKEN_GPR TOKEN_COMMA TOKEN_GPR TOKEN_COMMA TOKEN_SHRR TOKEN_NUM  */
#line 237 "./misc/bison.y"
                                                                                            {
			ins_aritm_shifted(0x50,(yyvsp[-3].reg),(yyvsp[-3].reg),(yyvsp[-5].reg),0,(yyvsp[0].num));
		}
#line 1737 "./misc/bison.tab.c"
    break;

  case 48: /* instr: TOKEN_SUB TOKEN_GPR TOKEN_COMMA TOKEN_GPR  */
#line 240 "./misc/bison.y"
                                                           {
			ins_aritmlog(0x51,(yyvsp[0].reg),(yyvsp[0].reg),(yyvsp[-2].reg));
		}
#line 1745 "./misc/bison.tab.c"
    break;

  case 49: /* instr: TOKEN_MUL TOKEN_GPR TOKEN_COMMA TOKEN_GPR  */
#line 243 "./misc/bison.y"
                                                           {
			 ins_aritmlog(0x52,(yyvsp[0].reg),(yyvsp[0].reg),(yyvsp[-2].reg));
		}
#line 1753 "./misc/bison.tab.c"
    break;

  case 50: /* instr: TOKEN_DIV TOKEN_GPR TOKEN_COMMA TOKEN_GPR  */
#line 246 "./misc/bison.y"
                                                           {
			ins_aritmlog(0x53,(yyvsp[0].reg),(yyvsp[0].reg),(yyvsp[-2].reg));
		}
#line 1761 "./misc/bison.tab.c"
    break;

  case 51: /* instr: TOKEN_NOT TOKEN_GPR  */
#line 249 "./misc/bison.y"
                                     {
			ins_aritmlog(0x60,(yyvsp[0].reg),(yyvsp[0].reg),0);
		}
#line 1769 "./misc/bison.tab.c"
    break;

  case 52: /* instr: TOKEN_AND TOKEN_GPR TOKEN_COMMA TOKEN_GPR  */
#line 252 "./misc/bison.y"
                                                           {
			ins_aritmlog(0x61,(yyvsp[0].reg),(yyvsp[0].reg),(yyvsp[-2].reg));
		}
#line 1777 "./misc/bison.tab.c"
    break;

  case 53: /* instr: TOKEN_OR TOKEN_GPR TOKEN_COMMA TOKEN_GPR  */
#line 255 "./misc/bison.y"
                                                          {
			ins_aritmlog(0x62,(yyvsp[0].reg),(yyvsp[0].reg),(yyvsp[-2].reg));
		}
#line 1785 "./misc/bison.tab.c"
    break;

  case 54: /* instr: TOKEN_XOR TOKEN_GPR TOKEN_COMMA TOKEN_GPR  */
#line 258 "./misc/bison.y"
                                                           {
			ins_aritmlog(0x63,(yyvsp[0].reg),(yyvsp[0].reg),(yyvsp[-2].reg));
		}
#line 1793 "./misc/bison.tab.c"
    break;

  case 55: /* instr: TOKEN_SHL TOKEN_GPR TOKEN_COMMA TOKEN_GPR  */
#line 261 "./misc/bison.y"
                                                           {
			ins_aritmlog(0x70,(yyvsp[0].reg),(yyvsp[0].reg),(yyvsp[-2].reg));
		}
#line 1801 "./misc/bison.tab.c"
    break;

  case 56: /* instr: TOKEN_SHR TOKEN_GPR TOKEN_COMMA TOKEN_GPR  */
#line 264 "./misc/bison.y"
                                                           {
			 ins_aritmlog(0x71,(yyvsp[0].reg),(yyvsp[0].reg),(yyvsp[-2].reg));
		}
#line 1809 "./misc/bison.tab.c"
    break;

  case 57: /* instr: TOKEN_LD op TOKEN_COMMA TOKEN_GPR  */
#line 267 "./misc/bison.y"
                                                    { 
			ins_ld((yyvsp[-2].oper),(yyvsp[0].reg)); 
		}
#line 1817 "./misc/bison.tab.c"
    break;

  case 58: /* instr: TOKEN_ST TOKEN_GPR TOKEN_COMMA op  */
#line 270 "./misc/bison.y"
                                                    { 
			 ins_st((yyvsp[-2].reg),(yyvsp[0].oper)); 
		}
#line 1825 "./misc/bison.tab.c"
    break;

  case 59: /* instr: TOKEN_CSRRD csreg TOKEN_COMMA TOKEN_GPR  */
#line 273 "./misc/bison.y"
                                                          { 
			 ins_csrrd((yyvsp[-2].reg),(yyvsp[0].reg)); 
		}
#line 1833 "./misc/bison.tab.c"
    break;

  case 60: /* instr: TOKEN_CSRWR TOKEN_GPR TOKEN_COMMA csreg  */
#line 276 "./misc/bison.y"
                                                          { 
			 ins_csrwr((yyvsp[-2].reg),(yyvsp[0].reg)); 
		}
#line 1841 "./misc/bison.tab.c"
    break;

  case 61: /* reg_list: reg_list TOKEN_COMMA TOKEN_GPR  */
#line 282 "./misc/bison.y"
                                            {
			ins_push((yyvsp[0].reg)); 
		}
#line 1849 "./misc/bison.tab.c"
    break;

  case 62: /* reg_list: TOKEN_GPR  */
#line 285 "./misc/bison.y"
                            {
			ins_push((yyvsp[0].reg)); 
		}
#line 1857 "./misc/bison.tab.c"
    break;

  case 63: /* op: TOKEN_NUM  */
#line 291 "./misc/bison.y"
                            {                          
			(yyval.oper) = operand(MEM_LIT,(yyvsp[0].num),0,0);
		}
#line 1865 "./misc/bison.tab.c"
    break;

  case 64: /* op: TOKEN_IDENT  */
#line 294 "./misc/bison.y"
                              { 					   
			(yyval.oper) = operand(MEM_SYM,0,(yyvsp[0].ident),0);
		}
#line 1873 "./misc/bison.tab.c"
    break;

  case 65: /* op: TOKEN_DOLLAR TOKEN_NUM  */
#line 297 "./misc/bison.y"
                                         {             
			(yyval.oper) = operand(IMM_LIT,(yyvsp[0].num),0,0);
		}
#line 1881 "./misc/bison.tab.c"
    break;

  case 66: /* op: TOKEN_DOLLAR TOKEN_IDENT  */
#line 300 "./misc/bison.y"
                                           {		   
			(yyval.oper) = operand(IMM_SYM,0,(yyvsp[0].ident),0);
		}
#line 1889 "./misc/bison.tab.c"
    break;

  case 67: /* op: TOKEN_GPR  */
#line 303 "./misc/bison.y"
                            { 
			(yyval.oper) = operand(IMM_REG,0,0,(yyvsp[0].reg));
		}
#line 1897 "./misc/bison.tab.c"
    break;

  case 68: /* op: TOKEN_LBRACKET TOKEN_GPR TOKEN_RBRACKET  */
#line 306 "./misc/bison.y"
                                                          {
			(yyval.oper) = operand(MEM_REG,0,0,(yyvsp[-1].reg));
		}
#line 1905 "./misc/bison.tab.c"
    break;

  case 69: /* op: TOKEN_LBRACKET TOKEN_GPR TOKEN_PLUS TOKEN_GPR TOKEN_RBRACKET  */
#line 309 "./misc/bison.y"
                                                                               { 
			(yyval.oper) = operand(MEM_REG_REG,0,0,(yyvsp[-3].reg),(yyvsp[-1].reg));
		}
#line 1913 "./misc/bison.tab.c"
    break;

  case 70: /* op: TOKEN_LBRACKET TOKEN_GPR TOKEN_PLUS TOKEN_NUM TOKEN_RBRACKET  */
#line 312 "./misc/bison.y"
                                                                               { 
			(yyval.oper) = operand(MEM_REG_LIT,(yyvsp[-1].num),0,(yyvsp[-3].reg));
		}
#line 1921 "./misc/bison.tab.c"
    break;

  case 71: /* op: TOKEN_LBRACKET TOKEN_GPR TOKEN_PLUS TOKEN_IDENT TOKEN_RBRACKET  */
#line 315 "./misc/bison.y"
                                                                                 { 
			(yyval.oper) = operand(MEM_REG_SYM,0,(yyvsp[-1].ident),(yyvsp[-3].reg));
		}
#line 1929 "./misc/bison.tab.c"
    break;

  case 72: /* jump_operand: TOKEN_NUM  */
#line 324 "./misc/bison.y"
                            {
			(yyval.oper) = operand(IMM_LIT, (yyvsp[0].num), 0, 0);
			}
#line 1937 "./misc/bison.tab.c"
    break;

  case 73: /* jump_operand: TOKEN_IDENT  */
#line 327 "./misc/bison.y"
                              {
			(yyval.oper) = operand(IMM_SYM, 0, (yyvsp[0].ident), 0);
			}
#line 1945 "./misc/bison.tab.c"
    break;

  case 74: /* csreg: TOKEN_STATUS  */
#line 333 "./misc/bison.y"
                               { (yyval.reg) = STATUS_CODE; }
#line 1951 "./misc/bison.tab.c"
    break;

  case 75: /* csreg: TOKEN_HANDLER  */
#line 334 "./misc/bison.y"
                                { (yyval.reg) = HANDLER_CODE; }
#line 1957 "./misc/bison.tab.c"
    break;

  case 76: /* csreg: TOKEN_CAUSE  */
#line 335 "./misc/bison.y"
                              { (yyval.reg) = CAUSE_CODE; }
#line 1963 "./misc/bison.tab.c"
    break;


#line 1967 "./misc/bison.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 340 "./misc/bison.y"




void yyerror(const char *sp){
  printf("%s", sp);
}
