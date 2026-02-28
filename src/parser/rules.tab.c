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
#line 1 "src/parser/rules.y"

    #include "../common/common.h"
    #include "ast.h"
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;

    void yyerror(const char *s);

#line 81 "src/parser/rules.tab.c"

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

#include "rules.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NAME = 3,                       /* NAME  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_UINT = 5,                       /* UINT  */
  YYSYMBOL_DOUBLE = 6,                     /* DOUBLE  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_MEMORY_LENGTH_SIMPLE = 8,       /* MEMORY_LENGTH_SIMPLE  */
  YYSYMBOL_MEMORY_LENGTH_PREFIX = 9,       /* MEMORY_LENGTH_PREFIX  */
  YYSYMBOL_ALIGNMENT_SIMPLE = 10,          /* ALIGNMENT_SIMPLE  */
  YYSYMBOL_CHUNK_CLASS_MEM = 11,           /* CHUNK_CLASS_MEM  */
  YYSYMBOL_CHUNK_CLASS_SSE = 12,           /* CHUNK_CLASS_SSE  */
  YYSYMBOL_CHUNK_CLASS_INT = 13,           /* CHUNK_CLASS_INT  */
  YYSYMBOL_CHUNK_CLASS_LAYOUT = 14,        /* CHUNK_CLASS_LAYOUT  */
  YYSYMBOL_GP_REGISTER = 15,               /* GP_REGISTER  */
  YYSYMBOL_REGISTER = 16,                  /* REGISTER  */
  YYSYMBOL_GLOBAL = 17,                    /* GLOBAL  */
  YYSYMBOL_LAYOUT = 18,                    /* LAYOUT  */
  YYSYMBOL_EXTERN = 19,                    /* EXTERN  */
  YYSYMBOL_NASM = 20,                      /* NASM  */
  YYSYMBOL_FN = 21,                        /* FN  */
  YYSYMBOL_NASM_BLOCK = 22,                /* NASM_BLOCK  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_GOTO = 25,                      /* GOTO  */
  YYSYMBOL_LOOP = 26,                      /* LOOP  */
  YYSYMBOL_BREAK = 27,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 28,                  /* CONTINUE  */
  YYSYMBOL_RET = 29,                       /* RET  */
  YYSYMBOL_AVOID = 30,                     /* AVOID  */
  YYSYMBOL_ALIAS = 31,                     /* ALIAS  */
  YYSYMBOL_REG = 32,                       /* REG  */
  YYSYMBOL_LOGICAL_OR = 33,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_AND = 34,               /* LOGICAL_AND  */
  YYSYMBOL_ASSIGN = 35,                    /* ASSIGN  */
  YYSYMBOL_INCREMENT = 36,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 37,                 /* DECREMENT  */
  YYSYMBOL_SIZEOF = 38,                    /* SIZEOF  */
  YYSYMBOL_PLUS = 39,                      /* PLUS  */
  YYSYMBOL_MINUS = 40,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 41,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 42,                    /* DIVIDE  */
  YYSYMBOL_REMAINDER = 43,                 /* REMAINDER  */
  YYSYMBOL_BITWISE_AND = 44,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 45,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 46,               /* BITWISE_XOR  */
  YYSYMBOL_LOGICAL_NOT = 47,               /* LOGICAL_NOT  */
  YYSYMBOL_BITWISE_NOT = 48,               /* BITWISE_NOT  */
  YYSYMBOL_LESS_THAN = 49,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 50,              /* GREATER_THAN  */
  YYSYMBOL_LESS_EQUAL = 51,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 52,             /* GREATER_EQUAL  */
  YYSYMBOL_EQUALS = 53,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 54,                /* NOT_EQUALS  */
  YYSYMBOL_CAST = 55,                      /* CAST  */
  YYSYMBOL_ACCESS = 56,                    /* ACCESS  */
  YYSYMBOL_ROB = 57,                       /* "("  */
  YYSYMBOL_RCB = 58,                       /* ")"  */
  YYSYMBOL_SOB = 59,                       /* "["  */
  YYSYMBOL_SCB = 60,                       /* "]"  */
  YYSYMBOL_COB = 61,                       /* "{"  */
  YYSYMBOL_CCB = 62,                       /* "}"  */
  YYSYMBOL_ARROW = 63,                     /* ARROW  */
  YYSYMBOL_COLON = 64,                     /* ":"  */
  YYSYMBOL_SEMICOLON = 65,                 /* ";"  */
  YYSYMBOL_COMMA = 66,                     /* ","  */
  YYSYMBOL_67_ = 67,                       /* '('  */
  YYSYMBOL_68_ = 68,                       /* ')'  */
  YYSYMBOL_69_ = 69,                       /* ':'  */
  YYSYMBOL_70_ = 70,                       /* '{'  */
  YYSYMBOL_71_ = 71,                       /* '}'  */
  YYSYMBOL_72_ = 72,                       /* ','  */
  YYSYMBOL_73_ = 73,                       /* ';'  */
  YYSYMBOL_74_ = 74,                       /* '['  */
  YYSYMBOL_75_ = 75,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 76,                  /* $accept  */
  YYSYMBOL_program = 77,                   /* program  */
  YYSYMBOL_visibility = 78,                /* visibility  */
  YYSYMBOL_memory_length = 79,             /* memory_length  */
  YYSYMBOL_alignment = 80,                 /* alignment  */
  YYSYMBOL_global_variable_declaration = 81, /* global_variable_declaration  */
  YYSYMBOL_chunk_class = 82,               /* chunk_class  */
  YYSYMBOL_abi_class = 83,                 /* abi_class  */
  YYSYMBOL_layout_declaration_items = 84,  /* layout_declaration_items  */
  YYSYMBOL_layout_declaration = 85,        /* layout_declaration  */
  YYSYMBOL_extern_declaration = 86,        /* extern_declaration  */
  YYSYMBOL_function_declaration_arg = 87,  /* function_declaration_arg  */
  YYSYMBOL_function_declaration_args = 88, /* function_declaration_args  */
  YYSYMBOL_function_declaration = 89,      /* function_declaration  */
  YYSYMBOL_nasm_block = 90,                /* nasm_block  */
  YYSYMBOL_body_list = 91,                 /* body_list  */
  YYSYMBOL_body = 92,                      /* body  */
  YYSYMBOL_statement = 93,                 /* statement  */
  YYSYMBOL_variable_declaration = 94,      /* variable_declaration  */
  YYSYMBOL_register_alias = 95,            /* register_alias  */
  YYSYMBOL_if_statement = 96,              /* if_statement  */
  YYSYMBOL_label_declaration = 97,         /* label_declaration  */
  YYSYMBOL_goto_statement = 98,            /* goto_statement  */
  YYSYMBOL_loop_statement = 99,            /* loop_statement  */
  YYSYMBOL_break_statement = 100,          /* break_statement  */
  YYSYMBOL_ret_statement = 101,            /* ret_statement  */
  YYSYMBOL_avoid_block_regs = 102,         /* avoid_block_regs  */
  YYSYMBOL_avoid_block = 103,              /* avoid_block  */
  YYSYMBOL_expression = 104,               /* expression  */
  YYSYMBOL_logical_or = 105,               /* logical_or  */
  YYSYMBOL_logical_and = 106,              /* logical_and  */
  YYSYMBOL_bitwise_or = 107,               /* bitwise_or  */
  YYSYMBOL_bitwise_xor = 108,              /* bitwise_xor  */
  YYSYMBOL_bitwise_and = 109,              /* bitwise_and  */
  YYSYMBOL_equality = 110,                 /* equality  */
  YYSYMBOL_relational = 111,               /* relational  */
  YYSYMBOL_additive = 112,                 /* additive  */
  YYSYMBOL_multiplicative = 113,           /* multiplicative  */
  YYSYMBOL_prefix_op = 114,                /* prefix_op  */
  YYSYMBOL_cast_op = 115,                  /* cast_op  */
  YYSYMBOL_address_op = 116,               /* address_op  */
  YYSYMBOL_sizeof_op = 117,                /* sizeof_op  */
  YYSYMBOL_tetriary = 118,                 /* tetriary  */
  YYSYMBOL_suffix_op = 119,                /* suffix_op  */
  YYSYMBOL_dereference_op = 120,           /* dereference_op  */
  YYSYMBOL_layout_access_op = 121,         /* layout_access_op  */
  YYSYMBOL_secondary = 122,                /* secondary  */
  YYSYMBOL_primary = 123,                  /* primary  */
  YYSYMBOL_literal = 124                   /* literal  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  221

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


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
      67,    68,     2,     2,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    73,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,    75,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,    71,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   166,   166,   167,   168,   169,   170,   171,   175,   179,
     180,   184,   188,   189,   190,   191,   195,   196,   197,   201,
     202,   206,   207,   211,   212,   213,   217,   218,   222,   223,
     224,   225,   226,   227,   228,   229,   233,   234,   238,   239,
     240,   241,   242,   243,   244,   245,   250,   254,   255,   259,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   278,   279,   283,   284,   288,   289,   293,   297,
     301,   305,   306,   310,   314,   315,   319,   323,   324,   328,
     329,   333,   334,   338,   339,   343,   344,   348,   349,   353,
     354,   355,   359,   360,   361,   362,   363,   367,   368,   369,
     373,   374,   375,   376,   380,   381,   382,   383,   387,   391,
     392,   396,   400,   401,   402,   403,   404,   408,   409,   413,
     414,   418,   422,   423,   424,   425,   429,   430,   434,   435,
     436,   437,   438
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
  "\"end of file\"", "error", "\"invalid token\"", "NAME", "INT", "UINT",
  "DOUBLE", "STRING", "MEMORY_LENGTH_SIMPLE", "MEMORY_LENGTH_PREFIX",
  "ALIGNMENT_SIMPLE", "CHUNK_CLASS_MEM", "CHUNK_CLASS_SSE",
  "CHUNK_CLASS_INT", "CHUNK_CLASS_LAYOUT", "GP_REGISTER", "REGISTER",
  "GLOBAL", "LAYOUT", "EXTERN", "NASM", "FN", "NASM_BLOCK", "IF", "ELSE",
  "GOTO", "LOOP", "BREAK", "CONTINUE", "RET", "AVOID", "ALIAS", "REG",
  "LOGICAL_OR", "LOGICAL_AND", "ASSIGN", "INCREMENT", "DECREMENT",
  "SIZEOF", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "REMAINDER",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "LOGICAL_NOT", "BITWISE_NOT",
  "LESS_THAN", "GREATER_THAN", "LESS_EQUAL", "GREATER_EQUAL", "EQUALS",
  "NOT_EQUALS", "CAST", "ACCESS", "\"(\"", "\")\"", "\"[\"", "\"]\"",
  "\"{\"", "\"}\"", "ARROW", "\":\"", "\";\"", "\",\"", "'('", "')'",
  "':'", "'{'", "'}'", "','", "';'", "'['", "']'", "$accept", "program",
  "visibility", "memory_length", "alignment",
  "global_variable_declaration", "chunk_class", "abi_class",
  "layout_declaration_items", "layout_declaration", "extern_declaration",
  "function_declaration_arg", "function_declaration_args",
  "function_declaration", "nasm_block", "body_list", "body", "statement",
  "variable_declaration", "register_alias", "if_statement",
  "label_declaration", "goto_statement", "loop_statement",
  "break_statement", "ret_statement", "avoid_block_regs", "avoid_block",
  "expression", "logical_or", "logical_and", "bitwise_or", "bitwise_xor",
  "bitwise_and", "equality", "relational", "additive", "multiplicative",
  "prefix_op", "cast_op", "address_op", "sizeof_op", "tetriary",
  "suffix_op", "dereference_op", "layout_access_op", "secondary",
  "primary", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -84,   102,   -84,   -63,    22,    35,   -84,   -84,   -84,   -84,
     -84,   -84,   117,   -84,   -84,   -84,   -17,   -84,    21,    19,
      57,    65,    68,   -84,   -84,   -84,   116,    42,   125,    98,
      65,   -84,   -84,   180,    77,     1,   116,   114,   120,   -84,
      -4,   125,   -84,   124,    92,   133,   -84,     2,   116,   131,
     -46,   125,     8,   -84,   -84,    92,   -84,     6,   -84,   150,
      84,   -84,   -84,   143,   -84,   -84,   -84,   -19,   -84,   -84,
      84,   -84,   -84,    29,   138,   168,   143,   -84,   -84,   138,
     -84,   -84,   134,   -84,   -84,   -84,   -84,   163,   209,   138,
     140,   141,   163,   205,   163,   163,   219,   163,   163,   163,
     -84,    56,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   151,    94,   189,   181,   179,   183,
      79,   130,    70,    41,   -84,   -84,   -84,   -84,   173,   -84,
     -84,   -84,    11,   -84,   -84,    29,   138,   -84,    48,   -84,
     138,   156,   -84,   -84,   -84,   158,   -84,   137,   173,   173,
     -84,   173,   173,   164,   163,   159,   -84,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   -84,   -84,   -84,   230,   111,   138,
     -84,   -84,   -12,    65,   212,   -84,   -84,   222,   -84,   -84,
     173,   163,   189,   -84,   181,   179,   183,    79,   130,   130,
      70,    70,    70,    70,    41,    41,   173,   173,   173,   -84,
     -84,   165,   -84,   -84,   -84,   -84,   138,   -84,   173,   -84,
     -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     1,     0,     0,     0,    46,     2,     3,     4,
       5,     6,     0,    26,    27,     9,     0,     8,     0,     0,
       0,    12,     0,    16,    17,    18,     0,     0,     0,     0,
      13,    11,    14,     0,     0,     0,     0,     0,    28,    37,
       0,     0,    15,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,    10,    22,     0,    24,     0,    20,    29,
      30,    19,    31,     0,    48,    38,    36,     0,    21,    25,
      32,    33,    34,     0,     0,     0,     0,    42,    35,     0,
      39,    40,   132,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,    52,    61,    47,    50,    51,    53,    54,    55,
      56,    57,    58,    59,     0,    78,    80,    82,    84,    86,
      88,    91,    96,    99,   112,   113,   114,   115,   103,   122,
     123,   124,   116,   125,   127,     0,     0,    41,    68,   132,
       0,     0,    70,    71,    72,     0,    75,     0,   104,   105,
     111,   106,   107,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   117,   118,     0,     0,     0,
      43,    44,     0,    62,    66,    69,    73,     0,    76,   126,
     110,     0,    79,    77,    81,    83,    85,    87,    89,    90,
      92,    93,    94,    95,    97,    98,   100,   101,   102,   121,
     120,     0,    45,    65,    64,    63,     0,    74,   109,   119,
      67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   -84,   -18,   -30,   -84,     0,   -24,   -26,   -84,
     166,   192,   203,   -84,   170,   -84,   -66,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -71,   -84,
      89,    88,    90,    87,    91,   -27,    52,     7,   -84,   -84,
     -84,   -84,   -83,   -84,   -84,   -84,   -84,   -84,   -84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    20,    21,    32,     7,    61,    62,    35,     8,
       9,    39,    40,    10,    11,    75,    65,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   147,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    77,    30,   213,    45,    45,    12,    80,    81,    45,
      47,   148,   149,   137,   151,   152,   140,    63,    27,    60,
     214,   145,    57,   142,    64,    13,    54,    37,   153,    70,
     155,    59,    23,    24,    25,    71,    72,    68,    14,    74,
      23,    24,    25,    58,    76,    73,    78,   175,   176,    79,
      22,    64,   136,    23,    24,    25,    15,    16,   135,   139,
      83,    84,    85,    86,    50,    15,    16,   177,    51,   180,
     181,   190,    46,    56,   184,    31,    67,    69,    29,   182,
      51,   188,   171,   172,   173,   178,    28,   193,   206,   207,
     208,    26,    94,    95,    96,    23,    24,    25,    58,    64,
      15,    16,     2,    97,    98,     3,    33,   211,   218,   169,
     170,   179,    36,   212,   139,    83,    84,    85,    86,    34,
     183,     4,     5,    99,     6,    15,    16,   157,    38,   158,
     101,   154,   163,   164,    17,    18,   198,   199,    19,    15,
      16,    31,    23,    24,    25,    58,    44,    94,    95,    96,
     220,    15,    16,   215,    23,    24,    25,    58,    97,    98,
      31,    23,    24,    25,    58,    41,   139,    83,    84,    85,
      86,    82,    83,    84,    85,    86,   204,   205,    99,   165,
     166,   167,   168,    43,    48,   101,   210,     4,     5,    49,
       6,    87,    53,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    55,   138,    94,    95,    96,    64,    64,   187,
      97,    98,   141,   143,   144,    97,    98,   200,   201,   202,
     203,   146,   150,   159,   156,   161,   160,   162,   174,   185,
      99,   186,   189,   209,   191,    99,   216,   101,   217,   100,
     219,   102,   101,    66,    52,   103,   192,   194,   196,     0,
     195,     0,     0,   197
};

static const yytype_int16 yycheck[] =
{
      30,    67,    20,    15,     3,     3,    69,    73,    74,     3,
      36,    94,    95,    79,    97,    98,    87,    63,    18,    49,
      32,    92,    48,    89,    70,     3,    44,    27,    99,    59,
     101,    49,    11,    12,    13,    59,    60,    55,     3,    63,
      11,    12,    13,    14,    63,    63,    70,    36,    37,    73,
      67,    70,    76,    11,    12,    13,     8,     9,    76,     3,
       4,     5,     6,     7,    68,     8,     9,    56,    72,   135,
     136,   154,    71,    71,   140,    10,    68,    71,    21,    31,
      72,   147,    41,    42,    43,    74,    67,   158,   171,   172,
     173,    70,    36,    37,    38,    11,    12,    13,    14,    70,
       8,     9,     0,    47,    48,     3,    38,   178,   191,    39,
      40,   135,    70,   179,     3,     4,     5,     6,     7,     3,
     138,    19,    20,    67,    22,     8,     9,    33,     3,    35,
      74,    75,    53,    54,    17,    18,   163,   164,    21,     8,
       9,    10,    11,    12,    13,    14,    69,    36,    37,    38,
     216,     8,     9,   183,    11,    12,    13,    14,    47,    48,
      10,    11,    12,    13,    14,    67,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,   169,   170,    67,    49,
      50,    51,    52,     3,    70,    74,    75,    19,    20,    69,
      22,    23,    68,    25,    26,    27,    28,    29,    30,    36,
      37,    38,    69,    69,    36,    37,    38,    70,    70,    72,
      47,    48,     3,    73,    73,    47,    48,   165,   166,   167,
     168,    16,     3,    34,    73,    46,    45,    44,    55,    73,
      67,    73,    68,     3,    75,    67,    24,    74,    16,    71,
      75,    75,    74,    51,    41,    75,   157,   159,   161,    -1,
     160,    -1,    -1,   162
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    77,     0,     3,    19,    20,    22,    81,    85,    86,
      89,    90,    69,     3,     3,     8,     9,    17,    18,    21,
      78,    79,    67,    11,    12,    13,    70,    82,    67,    21,
      79,    10,    80,    38,     3,    84,    70,    82,     3,    87,
      88,    67,    80,     3,    69,     3,    71,    84,    70,    69,
      68,    72,    88,    68,    79,    69,    71,    84,    14,    79,
      80,    82,    83,    63,    70,    92,    87,    68,    79,    71,
      80,    83,    83,    79,    83,    91,    63,    92,    83,    83,
      92,    92,     3,     4,     5,     6,     7,    23,    25,    26,
      27,    28,    29,    30,    36,    37,    38,    47,    48,    67,
      71,    74,    86,    90,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    79,    83,    92,    69,     3,
     104,     3,    92,    73,    73,   104,    16,   102,   118,   118,
       3,   118,   118,   104,    75,   104,    73,    33,    35,    34,
      45,    46,    44,    53,    54,    49,    50,    51,    52,    39,
      40,    41,    42,    43,    55,    36,    37,    56,    74,    83,
      92,    92,    31,    79,    92,    73,    73,    72,    92,    68,
     118,    75,   106,   104,   107,   108,   109,   110,   111,   111,
     112,   112,   112,   112,   113,   113,   118,   118,   118,     3,
      75,   104,    92,    15,    32,    80,    24,    16,   118,    75,
      92
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    76,    77,    77,    77,    77,    77,    77,    78,    79,
      79,    80,    81,    81,    81,    81,    82,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    86,    86,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    91,    91,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    98,
      99,   100,   100,   101,   102,   102,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   110,   111,   111,   111,   111,   111,   112,   112,   112,
     113,   113,   113,   113,   114,   114,   114,   114,   115,   116,
     116,   117,   118,   118,   118,   118,   118,   119,   119,   120,
     120,   121,   122,   122,   122,   122,   123,   123,   124,   124,
     124,   124,   124
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     0,     1,     1,
       5,     1,     3,     4,     4,     5,     1,     1,     1,     1,
       1,     4,     3,     6,     7,     8,     2,     2,     1,     3,
       3,     3,     4,     4,     4,     5,     3,     1,     7,     9,
       9,    10,     8,    10,    10,    11,     1,     2,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     4,     4,     4,     3,     5,     2,     3,
       2,     2,     2,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     2,     2,     4,
       3,     2,     1,     1,     1,     1,     1,     2,     2,     4,
       3,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1
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
  case 2: /* program: program global_variable_declaration  */
#line 166 "src/parser/rules.y"
                                        {}
#line 1372 "src/parser/rules.tab.c"
    break;

  case 3: /* program: program layout_declaration  */
#line 167 "src/parser/rules.y"
                                 {}
#line 1378 "src/parser/rules.tab.c"
    break;

  case 4: /* program: program extern_declaration  */
#line 168 "src/parser/rules.y"
                                 {}
#line 1384 "src/parser/rules.tab.c"
    break;

  case 5: /* program: program function_declaration  */
#line 169 "src/parser/rules.y"
                                   {}
#line 1390 "src/parser/rules.tab.c"
    break;

  case 6: /* program: program nasm_block  */
#line 170 "src/parser/rules.y"
                         {}
#line 1396 "src/parser/rules.tab.c"
    break;

  case 7: /* program: %empty  */
#line 171 "src/parser/rules.y"
      {}
#line 1402 "src/parser/rules.tab.c"
    break;

  case 8: /* visibility: GLOBAL  */
#line 175 "src/parser/rules.y"
           {}
#line 1408 "src/parser/rules.tab.c"
    break;

  case 9: /* memory_length: MEMORY_LENGTH_SIMPLE  */
#line 179 "src/parser/rules.y"
                         {}
#line 1414 "src/parser/rules.tab.c"
    break;

  case 10: /* memory_length: MEMORY_LENGTH_PREFIX '(' SIZEOF NAME ')'  */
#line 180 "src/parser/rules.y"
                                               {}
#line 1420 "src/parser/rules.tab.c"
    break;

  case 11: /* alignment: ALIGNMENT_SIMPLE  */
#line 184 "src/parser/rules.y"
                     {}
#line 1426 "src/parser/rules.tab.c"
    break;

  case 12: /* global_variable_declaration: NAME ':' memory_length  */
#line 188 "src/parser/rules.y"
                           {}
#line 1432 "src/parser/rules.tab.c"
    break;

  case 13: /* global_variable_declaration: NAME ':' visibility memory_length  */
#line 189 "src/parser/rules.y"
                                        {}
#line 1438 "src/parser/rules.tab.c"
    break;

  case 14: /* global_variable_declaration: NAME ':' memory_length alignment  */
#line 190 "src/parser/rules.y"
                                       {}
#line 1444 "src/parser/rules.tab.c"
    break;

  case 15: /* global_variable_declaration: NAME ':' visibility memory_length alignment  */
#line 191 "src/parser/rules.y"
                                                  {}
#line 1450 "src/parser/rules.tab.c"
    break;

  case 16: /* chunk_class: CHUNK_CLASS_MEM  */
#line 195 "src/parser/rules.y"
                    {}
#line 1456 "src/parser/rules.tab.c"
    break;

  case 17: /* chunk_class: CHUNK_CLASS_SSE  */
#line 196 "src/parser/rules.y"
                      {}
#line 1462 "src/parser/rules.tab.c"
    break;

  case 18: /* chunk_class: CHUNK_CLASS_INT  */
#line 197 "src/parser/rules.y"
                      {}
#line 1468 "src/parser/rules.tab.c"
    break;

  case 19: /* abi_class: chunk_class  */
#line 201 "src/parser/rules.y"
                {}
#line 1474 "src/parser/rules.tab.c"
    break;

  case 20: /* abi_class: CHUNK_CLASS_LAYOUT  */
#line 202 "src/parser/rules.y"
                         {}
#line 1480 "src/parser/rules.tab.c"
    break;

  case 21: /* layout_declaration_items: layout_declaration_items NAME ':' memory_length  */
#line 206 "src/parser/rules.y"
                                                    {}
#line 1486 "src/parser/rules.tab.c"
    break;

  case 22: /* layout_declaration_items: NAME ':' memory_length  */
#line 207 "src/parser/rules.y"
                             {}
#line 1492 "src/parser/rules.tab.c"
    break;

  case 23: /* layout_declaration: NAME ':' LAYOUT '{' layout_declaration_items '}'  */
#line 211 "src/parser/rules.y"
                                                     {}
#line 1498 "src/parser/rules.tab.c"
    break;

  case 24: /* layout_declaration: NAME ':' LAYOUT chunk_class '{' layout_declaration_items '}'  */
#line 212 "src/parser/rules.y"
                                                                   {}
#line 1504 "src/parser/rules.tab.c"
    break;

  case 25: /* layout_declaration: NAME ':' LAYOUT chunk_class chunk_class '{' layout_declaration_items '}'  */
#line 213 "src/parser/rules.y"
                                                                               {}
#line 1510 "src/parser/rules.tab.c"
    break;

  case 26: /* extern_declaration: EXTERN NAME  */
#line 217 "src/parser/rules.y"
                {}
#line 1516 "src/parser/rules.tab.c"
    break;

  case 27: /* extern_declaration: NASM NAME  */
#line 218 "src/parser/rules.y"
                {}
#line 1522 "src/parser/rules.tab.c"
    break;

  case 28: /* function_declaration_arg: NAME  */
#line 222 "src/parser/rules.y"
         {}
#line 1528 "src/parser/rules.tab.c"
    break;

  case 29: /* function_declaration_arg: NAME ':' memory_length  */
#line 223 "src/parser/rules.y"
                             {}
#line 1534 "src/parser/rules.tab.c"
    break;

  case 30: /* function_declaration_arg: NAME ':' alignment  */
#line 224 "src/parser/rules.y"
                         {}
#line 1540 "src/parser/rules.tab.c"
    break;

  case 31: /* function_declaration_arg: NAME ':' abi_class  */
#line 225 "src/parser/rules.y"
                         {}
#line 1546 "src/parser/rules.tab.c"
    break;

  case 32: /* function_declaration_arg: NAME ':' memory_length alignment  */
#line 226 "src/parser/rules.y"
                                       {}
#line 1552 "src/parser/rules.tab.c"
    break;

  case 33: /* function_declaration_arg: NAME ':' memory_length abi_class  */
#line 227 "src/parser/rules.y"
                                       {}
#line 1558 "src/parser/rules.tab.c"
    break;

  case 34: /* function_declaration_arg: NAME ':' alignment abi_class  */
#line 228 "src/parser/rules.y"
                                   {}
#line 1564 "src/parser/rules.tab.c"
    break;

  case 35: /* function_declaration_arg: NAME ':' memory_length alignment abi_class  */
#line 229 "src/parser/rules.y"
                                                 {}
#line 1570 "src/parser/rules.tab.c"
    break;

  case 36: /* function_declaration_args: function_declaration_args ',' function_declaration_arg  */
#line 233 "src/parser/rules.y"
                                                           {}
#line 1576 "src/parser/rules.tab.c"
    break;

  case 37: /* function_declaration_args: function_declaration_arg  */
#line 234 "src/parser/rules.y"
                               {}
#line 1582 "src/parser/rules.tab.c"
    break;

  case 38: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' body  */
#line 238 "src/parser/rules.y"
                                                       {}
#line 1588 "src/parser/rules.tab.c"
    break;

  case 39: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' ARROW memory_length body  */
#line 239 "src/parser/rules.y"
                                                                             {}
#line 1594 "src/parser/rules.tab.c"
    break;

  case 40: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' ARROW abi_class body  */
#line 240 "src/parser/rules.y"
                                                                         {}
#line 1600 "src/parser/rules.tab.c"
    break;

  case 41: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' ARROW memory_length abi_class body  */
#line 241 "src/parser/rules.y"
                                                                                       {}
#line 1606 "src/parser/rules.tab.c"
    break;

  case 42: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' body  */
#line 242 "src/parser/rules.y"
                                                                    {}
#line 1612 "src/parser/rules.tab.c"
    break;

  case 43: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' ARROW memory_length body  */
#line 243 "src/parser/rules.y"
                                                                                        {}
#line 1618 "src/parser/rules.tab.c"
    break;

  case 44: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' ARROW abi_class body  */
#line 244 "src/parser/rules.y"
                                                                                    {}
#line 1624 "src/parser/rules.tab.c"
    break;

  case 45: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' ARROW memory_length abi_class body  */
#line 246 "src/parser/rules.y"
               {}
#line 1630 "src/parser/rules.tab.c"
    break;

  case 46: /* nasm_block: NASM_BLOCK  */
#line 250 "src/parser/rules.y"
               {}
#line 1636 "src/parser/rules.tab.c"
    break;

  case 47: /* body_list: body_list statement  */
#line 254 "src/parser/rules.y"
                        {}
#line 1642 "src/parser/rules.tab.c"
    break;

  case 48: /* body_list: %empty  */
#line 255 "src/parser/rules.y"
      {}
#line 1648 "src/parser/rules.tab.c"
    break;

  case 49: /* body: '{' body_list '}'  */
#line 259 "src/parser/rules.y"
                      {}
#line 1654 "src/parser/rules.tab.c"
    break;

  case 50: /* statement: variable_declaration  */
#line 263 "src/parser/rules.y"
                         {}
#line 1660 "src/parser/rules.tab.c"
    break;

  case 51: /* statement: register_alias  */
#line 264 "src/parser/rules.y"
                     {}
#line 1666 "src/parser/rules.tab.c"
    break;

  case 52: /* statement: extern_declaration  */
#line 265 "src/parser/rules.y"
                         {}
#line 1672 "src/parser/rules.tab.c"
    break;

  case 53: /* statement: if_statement  */
#line 266 "src/parser/rules.y"
                   {}
#line 1678 "src/parser/rules.tab.c"
    break;

  case 54: /* statement: label_declaration  */
#line 267 "src/parser/rules.y"
                        {}
#line 1684 "src/parser/rules.tab.c"
    break;

  case 55: /* statement: goto_statement  */
#line 268 "src/parser/rules.y"
                     {}
#line 1690 "src/parser/rules.tab.c"
    break;

  case 56: /* statement: loop_statement  */
#line 269 "src/parser/rules.y"
                     {}
#line 1696 "src/parser/rules.tab.c"
    break;

  case 57: /* statement: break_statement  */
#line 270 "src/parser/rules.y"
                      {}
#line 1702 "src/parser/rules.tab.c"
    break;

  case 58: /* statement: ret_statement  */
#line 271 "src/parser/rules.y"
                    {}
#line 1708 "src/parser/rules.tab.c"
    break;

  case 59: /* statement: avoid_block  */
#line 272 "src/parser/rules.y"
                  {}
#line 1714 "src/parser/rules.tab.c"
    break;

  case 60: /* statement: expression ';'  */
#line 273 "src/parser/rules.y"
                     {}
#line 1720 "src/parser/rules.tab.c"
    break;

  case 61: /* statement: nasm_block  */
#line 274 "src/parser/rules.y"
                 {}
#line 1726 "src/parser/rules.tab.c"
    break;

  case 62: /* variable_declaration: NAME ':' memory_length  */
#line 278 "src/parser/rules.y"
                           {}
#line 1732 "src/parser/rules.tab.c"
    break;

  case 63: /* variable_declaration: NAME ':' memory_length alignment  */
#line 279 "src/parser/rules.y"
                                       {}
#line 1738 "src/parser/rules.tab.c"
    break;

  case 64: /* register_alias: NAME ':' ALIAS REG  */
#line 283 "src/parser/rules.y"
                       {}
#line 1744 "src/parser/rules.tab.c"
    break;

  case 65: /* register_alias: NAME ':' ALIAS GP_REGISTER  */
#line 284 "src/parser/rules.y"
                                 {}
#line 1750 "src/parser/rules.tab.c"
    break;

  case 66: /* if_statement: IF expression body  */
#line 288 "src/parser/rules.y"
                       {}
#line 1756 "src/parser/rules.tab.c"
    break;

  case 67: /* if_statement: IF expression body ELSE body  */
#line 289 "src/parser/rules.y"
                                 {}
#line 1762 "src/parser/rules.tab.c"
    break;

  case 68: /* label_declaration: NAME ':'  */
#line 293 "src/parser/rules.y"
             {}
#line 1768 "src/parser/rules.tab.c"
    break;

  case 69: /* goto_statement: GOTO NAME ';'  */
#line 297 "src/parser/rules.y"
                  {}
#line 1774 "src/parser/rules.tab.c"
    break;

  case 70: /* loop_statement: LOOP body  */
#line 301 "src/parser/rules.y"
              {}
#line 1780 "src/parser/rules.tab.c"
    break;

  case 71: /* break_statement: BREAK ';'  */
#line 305 "src/parser/rules.y"
              {}
#line 1786 "src/parser/rules.tab.c"
    break;

  case 72: /* break_statement: CONTINUE ';'  */
#line 306 "src/parser/rules.y"
                   {}
#line 1792 "src/parser/rules.tab.c"
    break;

  case 73: /* ret_statement: RET expression ';'  */
#line 310 "src/parser/rules.y"
                       {}
#line 1798 "src/parser/rules.tab.c"
    break;

  case 74: /* avoid_block_regs: avoid_block_regs ',' REGISTER  */
#line 314 "src/parser/rules.y"
                                  {}
#line 1804 "src/parser/rules.tab.c"
    break;

  case 75: /* avoid_block_regs: REGISTER  */
#line 315 "src/parser/rules.y"
               {}
#line 1810 "src/parser/rules.tab.c"
    break;

  case 76: /* avoid_block: AVOID avoid_block_regs body  */
#line 319 "src/parser/rules.y"
                                {}
#line 1816 "src/parser/rules.tab.c"
    break;

  case 77: /* expression: logical_or ASSIGN expression  */
#line 323 "src/parser/rules.y"
                                 {}
#line 1822 "src/parser/rules.tab.c"
    break;

  case 78: /* expression: logical_or  */
#line 324 "src/parser/rules.y"
                 {}
#line 1828 "src/parser/rules.tab.c"
    break;

  case 79: /* logical_or: logical_or LOGICAL_OR logical_and  */
#line 328 "src/parser/rules.y"
                                      {}
#line 1834 "src/parser/rules.tab.c"
    break;

  case 80: /* logical_or: logical_and  */
#line 329 "src/parser/rules.y"
                  {}
#line 1840 "src/parser/rules.tab.c"
    break;

  case 81: /* logical_and: logical_and LOGICAL_AND bitwise_or  */
#line 333 "src/parser/rules.y"
                                       {}
#line 1846 "src/parser/rules.tab.c"
    break;

  case 82: /* logical_and: bitwise_or  */
#line 334 "src/parser/rules.y"
                 {}
#line 1852 "src/parser/rules.tab.c"
    break;

  case 83: /* bitwise_or: bitwise_or BITWISE_OR bitwise_xor  */
#line 338 "src/parser/rules.y"
                                      {}
#line 1858 "src/parser/rules.tab.c"
    break;

  case 84: /* bitwise_or: bitwise_xor  */
#line 339 "src/parser/rules.y"
                  {}
#line 1864 "src/parser/rules.tab.c"
    break;

  case 85: /* bitwise_xor: bitwise_xor BITWISE_XOR bitwise_and  */
#line 343 "src/parser/rules.y"
                                        {}
#line 1870 "src/parser/rules.tab.c"
    break;

  case 86: /* bitwise_xor: bitwise_and  */
#line 344 "src/parser/rules.y"
                  {}
#line 1876 "src/parser/rules.tab.c"
    break;

  case 87: /* bitwise_and: bitwise_and BITWISE_AND equality  */
#line 348 "src/parser/rules.y"
                                     {}
#line 1882 "src/parser/rules.tab.c"
    break;

  case 88: /* bitwise_and: equality  */
#line 349 "src/parser/rules.y"
               {}
#line 1888 "src/parser/rules.tab.c"
    break;

  case 89: /* equality: equality EQUALS relational  */
#line 353 "src/parser/rules.y"
                               {}
#line 1894 "src/parser/rules.tab.c"
    break;

  case 90: /* equality: equality NOT_EQUALS relational  */
#line 354 "src/parser/rules.y"
                                     {}
#line 1900 "src/parser/rules.tab.c"
    break;

  case 91: /* equality: relational  */
#line 355 "src/parser/rules.y"
                 {}
#line 1906 "src/parser/rules.tab.c"
    break;

  case 92: /* relational: relational LESS_THAN additive  */
#line 359 "src/parser/rules.y"
                                  {}
#line 1912 "src/parser/rules.tab.c"
    break;

  case 93: /* relational: relational GREATER_THAN additive  */
#line 360 "src/parser/rules.y"
                                       {}
#line 1918 "src/parser/rules.tab.c"
    break;

  case 94: /* relational: relational LESS_EQUAL additive  */
#line 361 "src/parser/rules.y"
                                     {}
#line 1924 "src/parser/rules.tab.c"
    break;

  case 95: /* relational: relational GREATER_EQUAL additive  */
#line 362 "src/parser/rules.y"
                                        {}
#line 1930 "src/parser/rules.tab.c"
    break;

  case 96: /* relational: additive  */
#line 363 "src/parser/rules.y"
               {}
#line 1936 "src/parser/rules.tab.c"
    break;

  case 97: /* additive: additive PLUS multiplicative  */
#line 367 "src/parser/rules.y"
                                 {}
#line 1942 "src/parser/rules.tab.c"
    break;

  case 98: /* additive: additive MINUS multiplicative  */
#line 368 "src/parser/rules.y"
                                    {}
#line 1948 "src/parser/rules.tab.c"
    break;

  case 99: /* additive: multiplicative  */
#line 369 "src/parser/rules.y"
                     {}
#line 1954 "src/parser/rules.tab.c"
    break;

  case 100: /* multiplicative: multiplicative MULTIPLY tetriary  */
#line 373 "src/parser/rules.y"
                                     {}
#line 1960 "src/parser/rules.tab.c"
    break;

  case 101: /* multiplicative: multiplicative DIVIDE tetriary  */
#line 374 "src/parser/rules.y"
                                     {}
#line 1966 "src/parser/rules.tab.c"
    break;

  case 102: /* multiplicative: multiplicative REMAINDER tetriary  */
#line 375 "src/parser/rules.y"
                                        {}
#line 1972 "src/parser/rules.tab.c"
    break;

  case 103: /* multiplicative: tetriary  */
#line 376 "src/parser/rules.y"
               {}
#line 1978 "src/parser/rules.tab.c"
    break;

  case 104: /* prefix_op: INCREMENT tetriary  */
#line 380 "src/parser/rules.y"
                       {}
#line 1984 "src/parser/rules.tab.c"
    break;

  case 105: /* prefix_op: DECREMENT tetriary  */
#line 381 "src/parser/rules.y"
                         {}
#line 1990 "src/parser/rules.tab.c"
    break;

  case 106: /* prefix_op: LOGICAL_NOT tetriary  */
#line 382 "src/parser/rules.y"
                           {}
#line 1996 "src/parser/rules.tab.c"
    break;

  case 107: /* prefix_op: BITWISE_NOT tetriary  */
#line 383 "src/parser/rules.y"
                           {}
#line 2002 "src/parser/rules.tab.c"
    break;

  case 108: /* cast_op: tetriary CAST  */
#line 387 "src/parser/rules.y"
                  {}
#line 2008 "src/parser/rules.tab.c"
    break;

  case 109: /* address_op: '[' expression ']' tetriary  */
#line 391 "src/parser/rules.y"
                                {}
#line 2014 "src/parser/rules.tab.c"
    break;

  case 110: /* address_op: '[' ']' tetriary  */
#line 392 "src/parser/rules.y"
                       {}
#line 2020 "src/parser/rules.tab.c"
    break;

  case 111: /* sizeof_op: SIZEOF NAME  */
#line 396 "src/parser/rules.y"
                {}
#line 2026 "src/parser/rules.tab.c"
    break;

  case 112: /* tetriary: prefix_op  */
#line 400 "src/parser/rules.y"
              {}
#line 2032 "src/parser/rules.tab.c"
    break;

  case 113: /* tetriary: cast_op  */
#line 401 "src/parser/rules.y"
              {}
#line 2038 "src/parser/rules.tab.c"
    break;

  case 114: /* tetriary: address_op  */
#line 402 "src/parser/rules.y"
                 {}
#line 2044 "src/parser/rules.tab.c"
    break;

  case 115: /* tetriary: sizeof_op  */
#line 403 "src/parser/rules.y"
                {}
#line 2050 "src/parser/rules.tab.c"
    break;

  case 116: /* tetriary: secondary  */
#line 404 "src/parser/rules.y"
                {}
#line 2056 "src/parser/rules.tab.c"
    break;

  case 117: /* suffix_op: secondary INCREMENT  */
#line 408 "src/parser/rules.y"
                        {}
#line 2062 "src/parser/rules.tab.c"
    break;

  case 118: /* suffix_op: secondary DECREMENT  */
#line 409 "src/parser/rules.y"
                          {}
#line 2068 "src/parser/rules.tab.c"
    break;

  case 119: /* dereference_op: secondary '[' expression ']'  */
#line 413 "src/parser/rules.y"
                                 {}
#line 2074 "src/parser/rules.tab.c"
    break;

  case 120: /* dereference_op: secondary '[' ']'  */
#line 414 "src/parser/rules.y"
                        {}
#line 2080 "src/parser/rules.tab.c"
    break;

  case 121: /* layout_access_op: secondary ACCESS NAME  */
#line 418 "src/parser/rules.y"
                          {}
#line 2086 "src/parser/rules.tab.c"
    break;

  case 122: /* secondary: suffix_op  */
#line 422 "src/parser/rules.y"
              {}
#line 2092 "src/parser/rules.tab.c"
    break;

  case 123: /* secondary: dereference_op  */
#line 423 "src/parser/rules.y"
                     {}
#line 2098 "src/parser/rules.tab.c"
    break;

  case 124: /* secondary: layout_access_op  */
#line 424 "src/parser/rules.y"
                       {}
#line 2104 "src/parser/rules.tab.c"
    break;

  case 125: /* secondary: primary  */
#line 425 "src/parser/rules.y"
              {}
#line 2110 "src/parser/rules.tab.c"
    break;

  case 126: /* primary: '(' expression ')'  */
#line 429 "src/parser/rules.y"
                       {}
#line 2116 "src/parser/rules.tab.c"
    break;

  case 127: /* primary: literal  */
#line 430 "src/parser/rules.y"
              {}
#line 2122 "src/parser/rules.tab.c"
    break;

  case 128: /* literal: INT  */
#line 434 "src/parser/rules.y"
        {}
#line 2128 "src/parser/rules.tab.c"
    break;

  case 129: /* literal: UINT  */
#line 435 "src/parser/rules.y"
           {}
#line 2134 "src/parser/rules.tab.c"
    break;

  case 130: /* literal: DOUBLE  */
#line 436 "src/parser/rules.y"
             {}
#line 2140 "src/parser/rules.tab.c"
    break;

  case 131: /* literal: STRING  */
#line 437 "src/parser/rules.y"
             {}
#line 2146 "src/parser/rules.tab.c"
    break;

  case 132: /* literal: NAME  */
#line 438 "src/parser/rules.y"
           {}
#line 2152 "src/parser/rules.tab.c"
    break;


#line 2156 "src/parser/rules.tab.c"

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

#line 447 "src/parser/rules.y"

