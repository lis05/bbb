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
    #include "parser.h"
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;

    void yyerror(const char *s);

    #define ALLOC(t) ({\
        t *res = (t*)malloc(sizeof(t));\
        log_assert(res != NULL);\
        *res = (t){0};\
        res;\
    })

    // please fix this mess if you know how to do it
    #define _TF_C(t1, t2, t3) tfrag_combine(&(t1)->frag, &(t2)->frag, &(t3)->frag)
    #define _TF_C1(dest) do {} while (0)
    #define _TF_C2(dest, t1) do { (dest)->frag = (t1)->frag; } while (0)
    #define _TF_C3(dest, t1, t2) _TF_C(dest, t1, t2)
    #define _TF_C4(dest, t1, t2, t3) do {\
        _TF_C3(dest, t1, t2);\
        _TF_C(dest, dest, t3);\
    } while(0);
    #define _TF_C5(dest, t1, t2, t3, t4) do {\
        _TF_C4(dest, t1, t2, t3);\
        _TF_C(dest, dest, t4);\
    } while(0);
    #define _TF_C6(dest, t1, t2, t3, t4, t5) do {\
        _TF_C5(dest, t1, t2, t3, t4);\
        _TF_C(dest, dest, t5);\
    } while(0);
    #define _TF_C7(dest, t1, t2, t3, t4, t5, t6) do {\
        _TF_C6(dest, t1, t2, t3, t4, t5);\
        _TF_C(dest, dest, t6);\
    } while(0);
    #define _TF_C8(dest, t1, t2, t3, t4, t5, t6, t7) do {\
        _TF_C7(dest, t1, t2, t3, t4, t5, t6);\
        _TF_C(dest, dest, t7);\
    } while(0);
    #define _TF_C9(dest, t1, t2, t3, t4, t5, t6, t7, t8) do {\
        _TF_C8(dest, t1, t2, t3, t4, t5, t6, t7);\
        _TF_C(dest, dest, t8);\
    } while(0);
    #define _TF_C10(dest, t1, t2, t3, t4, t5, t6, t7, t8, t9) do {\
        _TF_C9(dest, t1, t2, t3, t4, t5, t6, t7, t8);\
        _TF_C(dest, dest, t9);\
    } while(0);
    #define _TF_C11(dest, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) do {\
        _TF_C10(dest, t1, t2, t3, t4, t5, t6, t7, t8, t9);\
        _TF_C(dest, dest, t10);\
    } while(0);
    #define _TF_C12(dest, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) do {\
        _TF_C11(dest, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10);\
        _TF_C(dest, dest, t11);\
    } while(0);

    #define _GET_TF_C(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, NAME, ...)\
        NAME
    #define TFRAG_COMBINE(...) _GET_TF_C(__VA_ARGS__, _TF_C12, _TF_C11,\
        _TF_C10, _TF_C9, _TF_C8, _TF_C7, _TF_C6, _TF_C5, _TF_C4,\
        _TF_C3, _TF_C2, _TF_C1)(__VA_ARGS__)

#line 137 "src/parser/rules.tab.c"

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
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_program = 68,                   /* program  */
  YYSYMBOL_visibility = 69,                /* visibility  */
  YYSYMBOL_memory_length = 70,             /* memory_length  */
  YYSYMBOL_alignment = 71,                 /* alignment  */
  YYSYMBOL_global_variable_declaration = 72, /* global_variable_declaration  */
  YYSYMBOL_chunk_class = 73,               /* chunk_class  */
  YYSYMBOL_abi_class = 74,                 /* abi_class  */
  YYSYMBOL_layout_declaration_items = 75,  /* layout_declaration_items  */
  YYSYMBOL_layout_declaration = 76,        /* layout_declaration  */
  YYSYMBOL_extern_declaration = 77,        /* extern_declaration  */
  YYSYMBOL_function_declaration_arg = 78,  /* function_declaration_arg  */
  YYSYMBOL_function_declaration_args = 79, /* function_declaration_args  */
  YYSYMBOL_function_declaration = 80,      /* function_declaration  */
  YYSYMBOL_body_list = 81,                 /* body_list  */
  YYSYMBOL_body = 82,                      /* body  */
  YYSYMBOL_statement = 83,                 /* statement  */
  YYSYMBOL_variable_declaration = 84,      /* variable_declaration  */
  YYSYMBOL_register_alias = 85,            /* register_alias  */
  YYSYMBOL_if_statement = 86,              /* if_statement  */
  YYSYMBOL_label_declaration = 87,         /* label_declaration  */
  YYSYMBOL_goto_statement = 88,            /* goto_statement  */
  YYSYMBOL_loop_statement = 89,            /* loop_statement  */
  YYSYMBOL_break_statement = 90,           /* break_statement  */
  YYSYMBOL_ret_statement = 91,             /* ret_statement  */
  YYSYMBOL_avoid_block_regs = 92,          /* avoid_block_regs  */
  YYSYMBOL_avoid_block = 93,               /* avoid_block  */
  YYSYMBOL_expression = 94,                /* expression  */
  YYSYMBOL_logical_or = 95,                /* logical_or  */
  YYSYMBOL_logical_and = 96,               /* logical_and  */
  YYSYMBOL_bitwise_or = 97,                /* bitwise_or  */
  YYSYMBOL_bitwise_xor = 98,               /* bitwise_xor  */
  YYSYMBOL_bitwise_and = 99,               /* bitwise_and  */
  YYSYMBOL_equality = 100,                 /* equality  */
  YYSYMBOL_relational = 101,               /* relational  */
  YYSYMBOL_additive = 102,                 /* additive  */
  YYSYMBOL_multiplicative = 103,           /* multiplicative  */
  YYSYMBOL_prefix_op = 104,                /* prefix_op  */
  YYSYMBOL_cast_op = 105,                  /* cast_op  */
  YYSYMBOL_address_op = 106,               /* address_op  */
  YYSYMBOL_sizeof_op = 107,                /* sizeof_op  */
  YYSYMBOL_tetriary = 108,                 /* tetriary  */
  YYSYMBOL_suffix_op = 109,                /* suffix_op  */
  YYSYMBOL_dereference_op = 110,           /* dereference_op  */
  YYSYMBOL_layout_access_op = 111,         /* layout_access_op  */
  YYSYMBOL_secondary = 112,                /* secondary  */
  YYSYMBOL_primary = 113,                  /* primary  */
  YYSYMBOL_literal = 114                   /* literal  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   236,   236,   243,   250,   257,   264,   271,   278,   282,
     283,   287,   291,   298,   306,   314,   326,   327,   328,   332,
     333,   337,   345,   355,   365,   376,   391,   397,   406,   411,
     418,   425,   432,   440,   448,   456,   468,   475,   483,   494,
     507,   520,   534,   546,   560,   574,   593,   599,   605,   615,
     620,   625,   630,   635,   640,   645,   650,   655,   660,   665,
     671,   679,   686,   697,   705,   716,   723,   735,   744,   754,
     763,   769,   778,   788,   795,   803,   813,   820,   828,   835,
     843,   850,   858,   865,   873,   880,   888,   895,   903,   910,
     917,   925,   932,   939,   946,   953,   961,   968,   975,   983,
     990,   997,  1004,  1012,  1018,  1024,  1030,  1039,  1048,  1056,
    1066,  1075,  1080,  1085,  1090,  1095,  1103,  1109,  1118,  1126,
    1136,  1146,  1151,  1156,  1161,  1169,  1176,  1184,  1185,  1186,
    1187,  1188
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
  "\"{\"", "\"}\"", "ARROW", "\":\"", "\";\"", "\",\"", "$accept",
  "program", "visibility", "memory_length", "alignment",
  "global_variable_declaration", "chunk_class", "abi_class",
  "layout_declaration_items", "layout_declaration", "extern_declaration",
  "function_declaration_arg", "function_declaration_args",
  "function_declaration", "body_list", "body", "statement",
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
     -84,    85,   -84,   -53,    46,    51,   -84,   -84,   -84,   -84,
     -84,   109,   -84,   -84,   -84,   -84,   -84,    29,   -39,    43,
     102,   -84,   -84,   -84,   125,    50,   137,   110,   102,   -84,
     -84,   112,    24,   125,   122,   139,   -84,   -13,   137,   -84,
     124,   142,   -84,    25,   125,   133,    52,   137,     2,   -84,
     124,   -84,    27,   -84,   186,   160,   -84,   -84,   -84,   173,
     -84,   -84,   127,   -84,   -84,   160,   -84,   -84,    72,    45,
     150,   173,   -84,   -84,   148,   -84,   -84,   -84,   -84,   -84,
     157,   210,   150,   156,   159,   157,   199,   157,   157,   219,
     157,   157,   157,   118,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   161,    15,   189,   180,
     181,   184,    95,   158,    -7,   116,   -84,   -84,   -84,   -84,
     174,   -84,   -84,   -84,    10,   -84,   -84,   150,   -84,   -84,
      45,   150,     7,   -84,   150,   165,   -84,   -84,   -84,   166,
     -84,   -22,   174,   174,   -84,   174,   174,   175,   157,   172,
     -84,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   -84,   -84,
     -84,   231,   132,   -84,   150,   -84,   -84,     4,   102,   211,
     -84,   -84,   220,   -84,   -84,   174,   157,   189,   -84,   180,
     181,   184,    95,   158,   158,    -7,    -7,    -7,    -7,   116,
     116,   174,   174,   174,   -84,   -84,   177,   -84,   -84,   -84,
     -84,   150,   -84,   174,   -84,   -84
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     1,     0,     0,     0,     6,     2,     3,     4,
       5,     0,    26,    27,     9,    10,     8,     0,     0,     0,
      12,    16,    17,    18,     0,     0,     0,     0,    13,    11,
      14,     0,     0,     0,     0,    28,    37,     0,     0,    15,
       0,     0,    23,     0,     0,     0,     0,     0,     0,    22,
       0,    24,     0,    20,    29,    30,    19,    31,    47,     0,
      38,    36,     0,    21,    25,    32,    33,    34,     0,     0,
       0,     0,    42,    35,   131,   127,   128,   129,   130,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    51,    46,    49,    50,    52,
      53,    54,    55,    56,    57,    58,     0,    77,    79,    81,
      83,    85,    87,    90,    95,    98,   111,   112,   113,   114,
     102,   121,   122,   123,   115,   124,   126,     0,    39,    40,
       0,     0,    67,   131,     0,     0,    69,    70,    71,     0,
      74,     0,   103,   104,   110,   105,   106,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   116,
     117,     0,     0,    41,     0,    43,    44,     0,    61,    65,
      68,    72,     0,    75,   125,   109,     0,    78,    76,    80,
      82,    84,    86,    88,    89,    91,    92,    93,    94,    96,
      97,    99,   100,   101,   120,   119,     0,    45,    64,    63,
      62,     0,    73,   108,   118,    66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   -84,   -16,   -28,   -84,    55,   -34,   -21,   -84,
     170,   192,   202,   -84,   -84,   -60,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -79,   -84,    90,
      89,    91,    88,    92,    -5,    58,    38,   -84,   -84,   -84,
     -84,   -83,   -84,   -84,   -84,   -84,   -84,   -84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    19,    20,    30,     7,    56,    57,    32,     8,
       9,    36,    37,    10,    68,    60,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   141,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,   134,    72,    28,   142,   143,   139,   145,   146,   128,
     129,    11,    43,   147,   149,    14,    15,    55,    26,   208,
      66,    67,   136,    52,    49,    70,    65,    41,    41,    54,
      41,    73,   163,   164,    63,   127,   209,   131,   177,    58,
      21,    22,    23,    69,   182,    46,   169,   170,   151,    12,
     152,    14,    15,    47,    13,   130,    21,    22,    23,    53,
      62,    21,    22,    23,    27,   185,   171,   173,    47,   172,
     175,   176,    25,   188,   179,    74,    75,    76,    77,    78,
      34,   183,   201,   202,   203,     2,    42,    51,     3,    64,
      24,     4,     5,   206,    79,    80,   174,    81,    82,    83,
      84,    85,    86,   213,     4,     5,    58,     6,    87,    88,
      89,    33,    29,    58,   207,    59,   178,    14,    15,    90,
      91,   133,    75,    76,    77,    78,    16,    17,    31,    92,
      18,    93,    14,    15,    94,   133,    75,    76,    77,    78,
      35,    14,    15,    29,    21,    22,    23,    53,   157,   158,
     210,   215,   193,   194,    87,    88,    89,   165,   166,   167,
     133,    75,    76,    77,    78,    90,    91,    38,    87,    88,
      89,    21,    22,    23,    53,    92,    40,    93,   148,    90,
      91,    14,    15,    44,    21,    22,    23,    53,    58,    92,
      71,    93,   205,    87,    88,    89,    29,    21,    22,    23,
      53,   199,   200,    45,    90,    91,    50,   159,   160,   161,
     162,    58,   132,   135,    92,   140,    93,   195,   196,   197,
     198,   137,   144,   153,   138,   154,   150,   155,   156,   168,
     180,   181,   186,   184,   204,   211,   212,   214,    95,    61,
      48,   187,   189,   191,     0,   190,     0,     0,   192
};

static const yytype_int16 yycheck[] =
{
      28,    80,    62,    19,    87,    88,    85,    90,    91,    69,
      70,    64,    33,    92,    93,     8,     9,    45,    57,    15,
      54,    55,    82,    44,    40,    59,    54,     3,     3,    45,
       3,    65,    39,    40,    50,    69,    32,    71,    31,    61,
      11,    12,    13,    59,    66,    58,    36,    37,    33,     3,
      35,     8,     9,    66,     3,    71,    11,    12,    13,    14,
      58,    11,    12,    13,    21,   148,    56,   127,    66,    59,
     130,   131,    17,   152,   134,     3,     4,     5,     6,     7,
      25,   141,   165,   166,   167,     0,    62,    62,     3,    62,
      61,    19,    20,   172,    22,    23,   130,    25,    26,    27,
      28,    29,    30,   186,    19,    20,    61,    22,    36,    37,
      38,    61,    10,    61,   174,    63,   132,     8,     9,    47,
      48,     3,     4,     5,     6,     7,    17,    18,     3,    57,
      21,    59,     8,     9,    62,     3,     4,     5,     6,     7,
       3,     8,     9,    10,    11,    12,    13,    14,    53,    54,
     178,   211,   157,   158,    36,    37,    38,    41,    42,    43,
       3,     4,     5,     6,     7,    47,    48,    57,    36,    37,
      38,    11,    12,    13,    14,    57,    64,    59,    60,    47,
      48,     8,     9,    61,    11,    12,    13,    14,    61,    57,
      63,    59,    60,    36,    37,    38,    10,    11,    12,    13,
      14,   163,   164,    64,    47,    48,    64,    49,    50,    51,
      52,    61,    64,     3,    57,    16,    59,   159,   160,   161,
     162,    65,     3,    34,    65,    45,    65,    46,    44,    55,
      65,    65,    60,    58,     3,    24,    16,    60,    68,    47,
      38,   151,   153,   155,    -1,   154,    -1,    -1,   156
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    68,     0,     3,    19,    20,    22,    72,    76,    77,
      80,    64,     3,     3,     8,     9,    17,    18,    21,    69,
      70,    11,    12,    13,    61,    73,    57,    21,    70,    10,
      71,     3,    75,    61,    73,     3,    78,    79,    57,    71,
      64,     3,    62,    75,    61,    64,    58,    66,    79,    70,
      64,    62,    75,    14,    70,    71,    73,    74,    61,    63,
      82,    78,    58,    70,    62,    71,    74,    74,    81,    70,
      74,    63,    82,    74,     3,     4,     5,     6,     7,    22,
      23,    25,    26,    27,    28,    29,    30,    36,    37,    38,
      47,    48,    57,    59,    62,    77,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    74,    82,    82,
      70,    74,    64,     3,    94,     3,    82,    65,    65,    94,
      16,    92,   108,   108,     3,   108,   108,    94,    60,    94,
      65,    33,    35,    34,    45,    46,    44,    53,    54,    49,
      50,    51,    52,    39,    40,    41,    42,    43,    55,    36,
      37,    56,    59,    82,    74,    82,    82,    31,    70,    82,
      65,    65,    66,    82,    58,   108,    60,    96,    94,    97,
      98,    99,   100,   101,   101,   102,   102,   102,   102,   103,
     103,   108,   108,   108,     3,    60,    94,    82,    15,    32,
      71,    24,    16,   108,    60,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    68,    68,    68,    68,    68,    69,    70,
      70,    71,    72,    72,    72,    72,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    88,    89,
      90,    90,    91,    92,    92,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     100,   101,   101,   101,   101,   101,   102,   102,   102,   103,
     103,   103,   103,   104,   104,   104,   104,   105,   106,   106,
     107,   108,   108,   108,   108,   108,   109,   109,   110,   110,
     111,   112,   112,   112,   112,   113,   113,   114,   114,   114,
     114,   114
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     0,     1,     1,
       1,     1,     3,     4,     4,     5,     1,     1,     1,     1,
       1,     4,     3,     6,     7,     8,     2,     2,     1,     3,
       3,     3,     4,     4,     4,     5,     3,     1,     7,     9,
       9,    10,     8,    10,    10,    11,     2,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     4,     4,     4,     3,     5,     2,     3,     2,
       2,     2,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     2,     2,     4,     3,
       2,     1,     1,     1,     1,     1,     2,     2,     4,     3,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1
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
  case 2: /* program: program global_variable_declaration  */
#line 236 "src/parser/rules.y"
                                        {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].global_variable_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->gvar_decl = (yyvsp[0].global_variable_declaration);
        parsing_result = (yyval.program);
    }
#line 1688 "src/parser/rules.tab.c"
    break;

  case 3: /* program: program layout_declaration  */
#line 243 "src/parser/rules.y"
                                 {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].layout_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->layout_decl = (yyvsp[0].layout_declaration);
        parsing_result = (yyval.program);
    }
#line 1700 "src/parser/rules.tab.c"
    break;

  case 4: /* program: program extern_declaration  */
#line 250 "src/parser/rules.y"
                                 {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].extern_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->ext_decl = (yyvsp[0].extern_declaration);
        parsing_result = (yyval.program);
    }
#line 1712 "src/parser/rules.tab.c"
    break;

  case 5: /* program: program function_declaration  */
#line 257 "src/parser/rules.y"
                                   {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].function_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->fn_decl = (yyvsp[0].function_declaration);
        parsing_result = (yyval.program);
    }
#line 1724 "src/parser/rules.tab.c"
    break;

  case 6: /* program: program NASM_BLOCK  */
#line 264 "src/parser/rules.y"
                         {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].name));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->nasm_b = (yyvsp[0].name);
        parsing_result = (yyval.program);
    }
#line 1736 "src/parser/rules.tab.c"
    break;

  case 7: /* program: %empty  */
#line 271 "src/parser/rules.y"
      {
        (yyval.program) = ALLOC(struct program_node_t);
        parsing_result = (yyval.program);
    }
#line 1745 "src/parser/rules.tab.c"
    break;

  case 8: /* visibility: GLOBAL  */
#line 278 "src/parser/rules.y"
           { (yyval.name) = (yyvsp[0].name); }
#line 1751 "src/parser/rules.tab.c"
    break;

  case 9: /* memory_length: MEMORY_LENGTH_SIMPLE  */
#line 282 "src/parser/rules.y"
                         { (yyval.name) = (yyvsp[0].name); }
#line 1757 "src/parser/rules.tab.c"
    break;

  case 10: /* memory_length: MEMORY_LENGTH_PREFIX  */
#line 283 "src/parser/rules.y"
                           { (yyval.name) = (yyvsp[0].name); }
#line 1763 "src/parser/rules.tab.c"
    break;

  case 11: /* alignment: ALIGNMENT_SIMPLE  */
#line 287 "src/parser/rules.y"
                     { (yyval.name) = (yyvsp[0].name); }
#line 1769 "src/parser/rules.tab.c"
    break;

  case 12: /* global_variable_declaration: NAME ":" memory_length  */
#line 291 "src/parser/rules.y"
                           {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[0].name);
    }
#line 1781 "src/parser/rules.tab.c"
    break;

  case 13: /* global_variable_declaration: NAME ":" visibility memory_length  */
#line 298 "src/parser/rules.y"
                                        {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-3].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->vis = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[0].name);
    }
#line 1794 "src/parser/rules.tab.c"
    break;

  case 14: /* global_variable_declaration: NAME ":" memory_length alignment  */
#line 306 "src/parser/rules.y"
                                       {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-3].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->align = (yyvsp[0].name);
    }
#line 1807 "src/parser/rules.tab.c"
    break;

  case 15: /* global_variable_declaration: NAME ":" visibility memory_length alignment  */
#line 314 "src/parser/rules.y"
                                                  {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-4].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-3].name);
        (yyval.global_variable_declaration)->vis = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->align = (yyvsp[0].name);
    }
#line 1821 "src/parser/rules.tab.c"
    break;

  case 16: /* chunk_class: CHUNK_CLASS_MEM  */
#line 326 "src/parser/rules.y"
                    { (yyval.name) = (yyvsp[0].name); }
#line 1827 "src/parser/rules.tab.c"
    break;

  case 17: /* chunk_class: CHUNK_CLASS_SSE  */
#line 327 "src/parser/rules.y"
                      { (yyval.name) = (yyvsp[0].name); }
#line 1833 "src/parser/rules.tab.c"
    break;

  case 18: /* chunk_class: CHUNK_CLASS_INT  */
#line 328 "src/parser/rules.y"
                      { (yyval.name) = (yyvsp[0].name); }
#line 1839 "src/parser/rules.tab.c"
    break;

  case 19: /* abi_class: chunk_class  */
#line 332 "src/parser/rules.y"
                { (yyval.name) = (yyvsp[0].name); }
#line 1845 "src/parser/rules.tab.c"
    break;

  case 20: /* abi_class: CHUNK_CLASS_LAYOUT  */
#line 333 "src/parser/rules.y"
                         { (yyval.name) = (yyvsp[0].name); }
#line 1851 "src/parser/rules.tab.c"
    break;

  case 21: /* layout_declaration_items: layout_declaration_items NAME ":" memory_length  */
#line 337 "src/parser/rules.y"
                                                    {
        (yyval.layout_declaration_items) = ALLOC(struct layout_declaration_items_node_t);
        TFRAG_COMBINE((yyval.layout_declaration_items), (yyvsp[-3].layout_declaration_items), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.layout_declaration_items)->rest = (yyvsp[-3].layout_declaration_items);
        (yyval.layout_declaration_items)->name = (yyvsp[-2].name);
        (yyval.layout_declaration_items)->colon = (yyvsp[-1].name);
        (yyval.layout_declaration_items)->mem_len = (yyvsp[0].name);
    }
#line 1864 "src/parser/rules.tab.c"
    break;

  case 22: /* layout_declaration_items: NAME ":" memory_length  */
#line 345 "src/parser/rules.y"
                             {
        (yyval.layout_declaration_items) = ALLOC(struct layout_declaration_items_node_t);
        TFRAG_COMBINE((yyval.layout_declaration_items), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.layout_declaration_items)->name = (yyvsp[-2].name);
        (yyval.layout_declaration_items)->colon = (yyvsp[-1].name);
        (yyval.layout_declaration_items)->mem_len = (yyvsp[0].name);
    }
#line 1876 "src/parser/rules.tab.c"
    break;

  case 23: /* layout_declaration: NAME ":" LAYOUT "{" layout_declaration_items "}"  */
#line 355 "src/parser/rules.y"
                                                     {
        (yyval.layout_declaration) = ALLOC(struct layout_declaration_node_t);
        TFRAG_COMBINE((yyval.layout_declaration), (yyvsp[-5].name), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].layout_declaration_items), (yyvsp[0].name));
        (yyval.layout_declaration)->name = (yyvsp[-5].name);
        (yyval.layout_declaration)->colon = (yyvsp[-4].name);
        (yyval.layout_declaration)->layout = (yyvsp[-3].name);
        (yyval.layout_declaration)->open_brace = (yyvsp[-2].name);
        (yyval.layout_declaration)->items = (yyvsp[-1].layout_declaration_items);
        (yyval.layout_declaration)->closed_brace = (yyvsp[0].name);
    }
#line 1891 "src/parser/rules.tab.c"
    break;

  case 24: /* layout_declaration: NAME ":" LAYOUT chunk_class "{" layout_declaration_items "}"  */
#line 365 "src/parser/rules.y"
                                                                   {
        (yyval.layout_declaration) = ALLOC(struct layout_declaration_node_t);
        TFRAG_COMBINE((yyval.layout_declaration), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].layout_declaration_items), (yyvsp[0].name));
        (yyval.layout_declaration)->name = (yyvsp[-6].name);
        (yyval.layout_declaration)->colon = (yyvsp[-5].name);
        (yyval.layout_declaration)->layout = (yyvsp[-4].name);
        (yyval.layout_declaration)->chunk1 = (yyvsp[-3].name);
        (yyval.layout_declaration)->open_brace = (yyvsp[-2].name);
        (yyval.layout_declaration)->items = (yyvsp[-1].layout_declaration_items);
        (yyval.layout_declaration)->closed_brace = (yyvsp[0].name);
    }
#line 1907 "src/parser/rules.tab.c"
    break;

  case 25: /* layout_declaration: NAME ":" LAYOUT chunk_class chunk_class "{" layout_declaration_items "}"  */
#line 376 "src/parser/rules.y"
                                                                               {
        (yyval.layout_declaration) = ALLOC(struct layout_declaration_node_t);
        TFRAG_COMBINE((yyval.layout_declaration), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].layout_declaration_items), (yyvsp[0].name));
        (yyval.layout_declaration)->name = (yyvsp[-7].name);
        (yyval.layout_declaration)->colon = (yyvsp[-6].name);
        (yyval.layout_declaration)->layout = (yyvsp[-5].name);
        (yyval.layout_declaration)->chunk1 = (yyvsp[-4].name);
        (yyval.layout_declaration)->chunk2 = (yyvsp[-3].name);
        (yyval.layout_declaration)->open_brace = (yyvsp[-2].name);
        (yyval.layout_declaration)->items = (yyvsp[-1].layout_declaration_items);
        (yyval.layout_declaration)->closed_brace = (yyvsp[0].name);
    }
#line 1924 "src/parser/rules.tab.c"
    break;

  case 26: /* extern_declaration: EXTERN NAME  */
#line 391 "src/parser/rules.y"
                {
        (yyval.extern_declaration) = ALLOC(struct extern_declaration_node_t);
        TFRAG_COMBINE((yyval.extern_declaration), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.extern_declaration)->kw = (yyvsp[-1].name);
        (yyval.extern_declaration)->name = (yyvsp[0].name);
    }
#line 1935 "src/parser/rules.tab.c"
    break;

  case 27: /* extern_declaration: NASM NAME  */
#line 397 "src/parser/rules.y"
                {
        (yyval.extern_declaration) = ALLOC(struct extern_declaration_node_t);
        TFRAG_COMBINE((yyval.extern_declaration), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.extern_declaration)->kw = (yyvsp[-1].name);
        (yyval.extern_declaration)->name = (yyvsp[0].name);
    }
#line 1946 "src/parser/rules.tab.c"
    break;

  case 28: /* function_declaration_arg: NAME  */
#line 406 "src/parser/rules.y"
         {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[0].name);
    }
#line 1956 "src/parser/rules.tab.c"
    break;

  case 29: /* function_declaration_arg: NAME ":" memory_length  */
#line 411 "src/parser/rules.y"
                             {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[0].name);
    }
#line 1968 "src/parser/rules.tab.c"
    break;

  case 30: /* function_declaration_arg: NAME ":" alignment  */
#line 418 "src/parser/rules.y"
                         {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->align = (yyvsp[0].name);
    }
#line 1980 "src/parser/rules.tab.c"
    break;

  case 31: /* function_declaration_arg: NAME ":" abi_class  */
#line 425 "src/parser/rules.y"
                         {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].name);
    }
#line 1992 "src/parser/rules.tab.c"
    break;

  case 32: /* function_declaration_arg: NAME ":" memory_length alignment  */
#line 432 "src/parser/rules.y"
                                       {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->align = (yyvsp[0].name);
    }
#line 2005 "src/parser/rules.tab.c"
    break;

  case 33: /* function_declaration_arg: NAME ":" memory_length abi_class  */
#line 440 "src/parser/rules.y"
                                       {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].name);
    }
#line 2018 "src/parser/rules.tab.c"
    break;

  case 34: /* function_declaration_arg: NAME ":" alignment abi_class  */
#line 448 "src/parser/rules.y"
                                   {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->align = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].name);
    }
#line 2031 "src/parser/rules.tab.c"
    break;

  case 35: /* function_declaration_arg: NAME ":" memory_length alignment abi_class  */
#line 456 "src/parser/rules.y"
                                                 {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-4].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->align = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].name);
    }
#line 2045 "src/parser/rules.tab.c"
    break;

  case 36: /* function_declaration_args: function_declaration_args "," function_declaration_arg  */
#line 468 "src/parser/rules.y"
                                                           {
        (yyval.function_declaration_args) = ALLOC(struct function_declaration_args_node_t);
        TFRAG_COMBINE((yyval.function_declaration_args), (yyvsp[-2].function_declaration_args), (yyvsp[-1].name), (yyvsp[0].function_declaration_arg));
        (yyval.function_declaration_args)->rest = (yyvsp[-2].function_declaration_args);
        (yyval.function_declaration_args)->comma = (yyvsp[-1].name);
        (yyval.function_declaration_args)->arg = (yyvsp[0].function_declaration_arg);
    }
#line 2057 "src/parser/rules.tab.c"
    break;

  case 37: /* function_declaration_args: function_declaration_arg  */
#line 475 "src/parser/rules.y"
                               {
        (yyval.function_declaration_args) = ALLOC(struct function_declaration_args_node_t);
        TFRAG_COMBINE((yyval.function_declaration_args), (yyvsp[0].function_declaration_arg));
        (yyval.function_declaration_args)->arg = (yyvsp[0].function_declaration_arg);
    }
#line 2067 "src/parser/rules.tab.c"
    break;

  case 38: /* function_declaration: NAME ":" FN "(" function_declaration_args ")" body  */
#line 483 "src/parser/rules.y"
                                                       {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].function_declaration_args), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-6].name);
        (yyval.function_declaration)->colon = (yyvsp[-5].name);
        (yyval.function_declaration)->fn = (yyvsp[-4].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-3].name);
        (yyval.function_declaration)->args = (yyvsp[-2].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-1].name);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2083 "src/parser/rules.tab.c"
    break;

  case 39: /* function_declaration: NAME ":" FN "(" function_declaration_args ")" ARROW memory_length body  */
#line 494 "src/parser/rules.y"
                                                                             {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-8].name), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].function_declaration_args), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-8].name);
        (yyval.function_declaration)->colon = (yyvsp[-7].name);
        (yyval.function_declaration)->fn = (yyvsp[-6].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-5].name);
        (yyval.function_declaration)->args = (yyvsp[-4].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-3].name);
        (yyval.function_declaration)->arrow = (yyvsp[-2].name);
        (yyval.function_declaration)->mem_len = (yyvsp[-1].name);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2101 "src/parser/rules.tab.c"
    break;

  case 40: /* function_declaration: NAME ":" FN "(" function_declaration_args ")" ARROW abi_class body  */
#line 507 "src/parser/rules.y"
                                                                         {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-8].name), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].function_declaration_args), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-8].name);
        (yyval.function_declaration)->colon = (yyvsp[-7].name);
        (yyval.function_declaration)->fn = (yyvsp[-6].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-5].name);
        (yyval.function_declaration)->args = (yyvsp[-4].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-3].name);
        (yyval.function_declaration)->arrow = (yyvsp[-2].name);
        (yyval.function_declaration)->abi_class = (yyvsp[-1].name);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2119 "src/parser/rules.tab.c"
    break;

  case 41: /* function_declaration: NAME ":" FN "(" function_declaration_args ")" ARROW memory_length abi_class body  */
#line 520 "src/parser/rules.y"
                                                                                       {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-9].name), (yyvsp[-8].name), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].function_declaration_args), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-9].name);
        (yyval.function_declaration)->colon = (yyvsp[-8].name);
        (yyval.function_declaration)->fn = (yyvsp[-7].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-6].name);
        (yyval.function_declaration)->args = (yyvsp[-5].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-4].name);
        (yyval.function_declaration)->arrow = (yyvsp[-3].name);
        (yyval.function_declaration)->mem_len = (yyvsp[-2].name);
        (yyval.function_declaration)->abi_class = (yyvsp[-1].name);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2138 "src/parser/rules.tab.c"
    break;

  case 42: /* function_declaration: NAME ":" visibility FN "(" function_declaration_args ")" body  */
#line 534 "src/parser/rules.y"
                                                                    {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].function_declaration_args), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-7].name);
        (yyval.function_declaration)->colon = (yyvsp[-6].name);
        (yyval.function_declaration)->vis = (yyvsp[-5].name);
        (yyval.function_declaration)->fn = (yyvsp[-4].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-3].name);
        (yyval.function_declaration)->args = (yyvsp[-2].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-1].name);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2155 "src/parser/rules.tab.c"
    break;

  case 43: /* function_declaration: NAME ":" visibility FN "(" function_declaration_args ")" ARROW memory_length body  */
#line 546 "src/parser/rules.y"
                                                                                        {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-9].name), (yyvsp[-8].name), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].function_declaration_args), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-9].name);
        (yyval.function_declaration)->colon = (yyvsp[-8].name);
        (yyval.function_declaration)->vis = (yyvsp[-7].name);
        (yyval.function_declaration)->fn = (yyvsp[-6].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-5].name);
        (yyval.function_declaration)->args = (yyvsp[-4].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-3].name);
        (yyval.function_declaration)->arrow = (yyvsp[-2].name);
        (yyval.function_declaration)->mem_len = (yyvsp[-1].name);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2174 "src/parser/rules.tab.c"
    break;

  case 44: /* function_declaration: NAME ":" visibility FN "(" function_declaration_args ")" ARROW abi_class body  */
#line 560 "src/parser/rules.y"
                                                                                    {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-9].name), (yyvsp[-8].name), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].function_declaration_args), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-9].name);
        (yyval.function_declaration)->colon = (yyvsp[-8].name);
        (yyval.function_declaration)->vis = (yyvsp[-7].name);
        (yyval.function_declaration)->fn = (yyvsp[-6].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-5].name);
        (yyval.function_declaration)->args = (yyvsp[-4].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-3].name);
        (yyval.function_declaration)->arrow = (yyvsp[-2].name);
        (yyval.function_declaration)->abi_class = (yyvsp[-1].name);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2193 "src/parser/rules.tab.c"
    break;

  case 45: /* function_declaration: NAME ":" visibility FN "(" function_declaration_args ")" ARROW memory_length abi_class body  */
#line 575 "src/parser/rules.y"
               {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-10].name), (yyvsp[-9].name), (yyvsp[-8].name), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].function_declaration_args), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-10].name);
        (yyval.function_declaration)->colon = (yyvsp[-9].name);
        (yyval.function_declaration)->vis = (yyvsp[-8].name);
        (yyval.function_declaration)->fn = (yyvsp[-7].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-6].name);
        (yyval.function_declaration)->args = (yyvsp[-5].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-4].name);
        (yyval.function_declaration)->arrow = (yyvsp[-3].name);
        (yyval.function_declaration)->mem_len = (yyvsp[-2].name);
        (yyval.function_declaration)->abi_class = (yyvsp[-1].name);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2213 "src/parser/rules.tab.c"
    break;

  case 46: /* body_list: body_list statement  */
#line 593 "src/parser/rules.y"
                        {
        (yyval.body_list) = ALLOC(struct body_list_node_t);
        TFRAG_COMBINE((yyval.body_list), (yyvsp[-1].body_list), (yyvsp[0].statement));
        (yyval.body_list)->rest = (yyvsp[-1].body_list);
        (yyval.body_list)->s = (yyvsp[0].statement);
    }
#line 2224 "src/parser/rules.tab.c"
    break;

  case 47: /* body_list: %empty  */
#line 599 "src/parser/rules.y"
      {
        (yyval.body_list) = ALLOC(struct body_list_node_t);
    }
#line 2232 "src/parser/rules.tab.c"
    break;

  case 48: /* body: "{" body_list "}"  */
#line 605 "src/parser/rules.y"
                      {
        (yyval.body) = ALLOC(struct body_node_t);
        TFRAG_COMBINE((yyval.body), (yyvsp[-2].name), (yyvsp[-1].body_list), (yyvsp[0].name));
        (yyval.body)->open_brace = (yyvsp[-2].name);
        (yyval.body)->list = (yyvsp[-1].body_list);
        (yyval.body)->closed_brace = (yyvsp[0].name);
    }
#line 2244 "src/parser/rules.tab.c"
    break;

  case 49: /* statement: variable_declaration  */
#line 615 "src/parser/rules.y"
                         {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].variable_declaration));
        (yyval.statement)->vdecl = (yyvsp[0].variable_declaration);
    }
#line 2254 "src/parser/rules.tab.c"
    break;

  case 50: /* statement: register_alias  */
#line 620 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].register_alias));
        (yyval.statement)->alias = (yyvsp[0].register_alias);
    }
#line 2264 "src/parser/rules.tab.c"
    break;

  case 51: /* statement: extern_declaration  */
#line 625 "src/parser/rules.y"
                         {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].extern_declaration));
        (yyval.statement)->ext_decl = (yyvsp[0].extern_declaration);
    }
#line 2274 "src/parser/rules.tab.c"
    break;

  case 52: /* statement: if_statement  */
#line 630 "src/parser/rules.y"
                   {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].if_statement));
        (yyval.statement)->if_s = (yyvsp[0].if_statement);
    }
#line 2284 "src/parser/rules.tab.c"
    break;

  case 53: /* statement: label_declaration  */
#line 635 "src/parser/rules.y"
                        {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].label_declaration));
        (yyval.statement)->label = (yyvsp[0].label_declaration);
    }
#line 2294 "src/parser/rules.tab.c"
    break;

  case 54: /* statement: goto_statement  */
#line 640 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].goto_statement));
        (yyval.statement)->goto_s = (yyvsp[0].goto_statement);
    }
#line 2304 "src/parser/rules.tab.c"
    break;

  case 55: /* statement: loop_statement  */
#line 645 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].loop_statement));
        (yyval.statement)->loop_s = (yyvsp[0].loop_statement);
    }
#line 2314 "src/parser/rules.tab.c"
    break;

  case 56: /* statement: break_statement  */
#line 650 "src/parser/rules.y"
                      {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].break_statement));
        (yyval.statement)->break_s = (yyvsp[0].break_statement);
    }
#line 2324 "src/parser/rules.tab.c"
    break;

  case 57: /* statement: ret_statement  */
#line 655 "src/parser/rules.y"
                    {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].ret_statement));
        (yyval.statement)->ret_s = (yyvsp[0].ret_statement);
    }
#line 2334 "src/parser/rules.tab.c"
    break;

  case 58: /* statement: avoid_block  */
#line 660 "src/parser/rules.y"
                  {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].avoid_block));
        (yyval.statement)->avoid = (yyvsp[0].avoid_block);
    }
#line 2344 "src/parser/rules.tab.c"
    break;

  case 59: /* statement: expression ";"  */
#line 665 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[-1].expression), (yyvsp[0].name));
        (yyval.statement)->expr = (yyvsp[-1].expression);
        (yyval.statement)->semicolon = (yyvsp[0].name);
    }
#line 2355 "src/parser/rules.tab.c"
    break;

  case 60: /* statement: NASM_BLOCK  */
#line 671 "src/parser/rules.y"
                 {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].name));
        (yyval.statement)->nasm = (yyvsp[0].name);
    }
#line 2365 "src/parser/rules.tab.c"
    break;

  case 61: /* variable_declaration: NAME ":" memory_length  */
#line 679 "src/parser/rules.y"
                           {
        (yyval.variable_declaration) = ALLOC(struct variable_declaration_node_t);
        TFRAG_COMBINE((yyval.variable_declaration), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.variable_declaration)->name = (yyvsp[-2].name);
        (yyval.variable_declaration)->colon = (yyvsp[-1].name);
        (yyval.variable_declaration)->mem_len = (yyvsp[0].name);
    }
#line 2377 "src/parser/rules.tab.c"
    break;

  case 62: /* variable_declaration: NAME ":" memory_length alignment  */
#line 686 "src/parser/rules.y"
                                       {
        (yyval.variable_declaration) = ALLOC(struct variable_declaration_node_t);
        TFRAG_COMBINE((yyval.variable_declaration), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.variable_declaration)->name = (yyvsp[-3].name);
        (yyval.variable_declaration)->colon = (yyvsp[-2].name);
        (yyval.variable_declaration)->mem_len = (yyvsp[-1].name);
        (yyval.variable_declaration)->align = (yyvsp[0].name);
    }
#line 2390 "src/parser/rules.tab.c"
    break;

  case 63: /* register_alias: NAME ":" ALIAS REG  */
#line 697 "src/parser/rules.y"
                       {
        (yyval.register_alias) = ALLOC(struct register_alias_node_t);
        TFRAG_COMBINE((yyval.register_alias), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.register_alias)->name = (yyvsp[-3].name);
        (yyval.register_alias)->colon = (yyvsp[-2].name);
        (yyval.register_alias)->alias = (yyvsp[-1].name);
        (yyval.register_alias)->reg = (yyvsp[0].name);
    }
#line 2403 "src/parser/rules.tab.c"
    break;

  case 64: /* register_alias: NAME ":" ALIAS GP_REGISTER  */
#line 705 "src/parser/rules.y"
                                 {
        (yyval.register_alias) = ALLOC(struct register_alias_node_t);
        TFRAG_COMBINE((yyval.register_alias), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.register_alias)->name = (yyvsp[-3].name);
        (yyval.register_alias)->colon = (yyvsp[-2].name);
        (yyval.register_alias)->alias = (yyvsp[-1].name);
        (yyval.register_alias)->reg = (yyvsp[0].name);
    }
#line 2416 "src/parser/rules.tab.c"
    break;

  case 65: /* if_statement: IF expression body  */
#line 716 "src/parser/rules.y"
                       {
        (yyval.if_statement) = ALLOC(struct if_statement_node_t);
        TFRAG_COMBINE((yyval.if_statement), (yyvsp[-2].name), (yyvsp[-1].expression), (yyvsp[0].body));
        (yyval.if_statement)->kw = (yyvsp[-2].name);
        (yyval.if_statement)->expr = (yyvsp[-1].expression);
        (yyval.if_statement)->body = (yyvsp[0].body);
    }
#line 2428 "src/parser/rules.tab.c"
    break;

  case 66: /* if_statement: IF expression body ELSE body  */
#line 723 "src/parser/rules.y"
                                   {
        (yyval.if_statement) = ALLOC(struct if_statement_node_t);
        TFRAG_COMBINE((yyval.if_statement), (yyvsp[-4].name), (yyvsp[-3].expression), (yyvsp[-2].body), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.if_statement)->kw = (yyvsp[-4].name);
        (yyval.if_statement)->expr = (yyvsp[-3].expression);
        (yyval.if_statement)->body = (yyvsp[-2].body);
        (yyval.if_statement)->else_kw = (yyvsp[-1].name);
        (yyval.if_statement)->else_body = (yyvsp[0].body);
    }
#line 2442 "src/parser/rules.tab.c"
    break;

  case 67: /* label_declaration: NAME ":"  */
#line 735 "src/parser/rules.y"
             {
        (yyval.label_declaration) = ALLOC(struct label_declaration_node_t);
        TFRAG_COMBINE((yyval.label_declaration), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.label_declaration)->name = (yyvsp[-1].name);
        (yyval.label_declaration)->colon = (yyvsp[0].name);
    }
#line 2453 "src/parser/rules.tab.c"
    break;

  case 68: /* goto_statement: GOTO NAME ";"  */
#line 744 "src/parser/rules.y"
                  {
        (yyval.goto_statement) = ALLOC(struct goto_statement_node_t);
        TFRAG_COMBINE((yyval.goto_statement), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.goto_statement)->kw = (yyvsp[-2].name);
        (yyval.goto_statement)->name = (yyvsp[-1].name);
        (yyval.goto_statement)->semicolon = (yyvsp[0].name);
    }
#line 2465 "src/parser/rules.tab.c"
    break;

  case 69: /* loop_statement: LOOP body  */
#line 754 "src/parser/rules.y"
              {
        (yyval.loop_statement) = ALLOC(struct loop_statement_node_t);
        TFRAG_COMBINE((yyval.loop_statement), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.loop_statement)->kw = (yyvsp[-1].name);
        (yyval.loop_statement)->body = (yyvsp[0].body);
    }
#line 2476 "src/parser/rules.tab.c"
    break;

  case 70: /* break_statement: BREAK ";"  */
#line 763 "src/parser/rules.y"
              {
        (yyval.break_statement) = ALLOC(struct break_statement_node_t);
        TFRAG_COMBINE((yyval.break_statement), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.break_statement)->kw = (yyvsp[-1].name);
        (yyval.break_statement)->semicolon = (yyvsp[0].name);
    }
#line 2487 "src/parser/rules.tab.c"
    break;

  case 71: /* break_statement: CONTINUE ";"  */
#line 769 "src/parser/rules.y"
                   {
        (yyval.break_statement) = ALLOC(struct break_statement_node_t);
        TFRAG_COMBINE((yyval.break_statement), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.break_statement)->kw = (yyvsp[-1].name);
        (yyval.break_statement)->semicolon = (yyvsp[0].name);
    }
#line 2498 "src/parser/rules.tab.c"
    break;

  case 72: /* ret_statement: RET expression ";"  */
#line 778 "src/parser/rules.y"
                       {
        (yyval.ret_statement) = ALLOC(struct ret_statement_node_t);
        TFRAG_COMBINE((yyval.ret_statement), (yyvsp[-2].name), (yyvsp[-1].expression), (yyvsp[0].name));
        (yyval.ret_statement)->kw = (yyvsp[-2].name);
        (yyval.ret_statement)->expr = (yyvsp[-1].expression);
        (yyval.ret_statement)->semicolon = (yyvsp[0].name);
    }
#line 2510 "src/parser/rules.tab.c"
    break;

  case 73: /* avoid_block_regs: avoid_block_regs "," REGISTER  */
#line 788 "src/parser/rules.y"
                                  {
        (yyval.avoid_block_regs) = ALLOC(struct avoid_block_regs_node_t);
        TFRAG_COMBINE((yyval.avoid_block_regs), (yyvsp[-2].avoid_block_regs), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.avoid_block_regs)->rest = (yyvsp[-2].avoid_block_regs);
        (yyval.avoid_block_regs)->comma = (yyvsp[-1].name);
        (yyval.avoid_block_regs)->reg = (yyvsp[0].name);
    }
#line 2522 "src/parser/rules.tab.c"
    break;

  case 74: /* avoid_block_regs: REGISTER  */
#line 795 "src/parser/rules.y"
               {
        (yyval.avoid_block_regs) = ALLOC(struct avoid_block_regs_node_t);
        TFRAG_COMBINE((yyval.avoid_block_regs), (yyvsp[0].name));
        (yyval.avoid_block_regs)->reg = (yyvsp[0].name);
    }
#line 2532 "src/parser/rules.tab.c"
    break;

  case 75: /* avoid_block: AVOID avoid_block_regs body  */
#line 803 "src/parser/rules.y"
                                {
        (yyval.avoid_block) = ALLOC(struct avoid_block_node_t);
        TFRAG_COMBINE((yyval.avoid_block), (yyvsp[-2].name), (yyvsp[-1].avoid_block_regs), (yyvsp[0].body));
        (yyval.avoid_block)->kw = (yyvsp[-2].name);
        (yyval.avoid_block)->regs = (yyvsp[-1].avoid_block_regs);
        (yyval.avoid_block)->body = (yyvsp[0].body);
    }
#line 2544 "src/parser/rules.tab.c"
    break;

  case 76: /* expression: logical_or ASSIGN expression  */
#line 813 "src/parser/rules.y"
                                 {
        (yyval.expression) = ALLOC(struct expression_node_t);
        TFRAG_COMBINE((yyval.expression), (yyvsp[-2].logical_or), (yyvsp[-1].name), (yyvsp[0].expression));
        (yyval.expression)->arg1 = (yyvsp[-2].logical_or);
        (yyval.expression)->op = (yyvsp[-1].name);
        (yyval.expression)->arg2 = (yyvsp[0].expression);
    }
#line 2556 "src/parser/rules.tab.c"
    break;

  case 77: /* expression: logical_or  */
#line 820 "src/parser/rules.y"
                 {
        (yyval.expression) = ALLOC(struct expression_node_t);
        TFRAG_COMBINE((yyval.expression), (yyvsp[0].logical_or));
        (yyval.expression)->other = (yyvsp[0].logical_or);
    }
#line 2566 "src/parser/rules.tab.c"
    break;

  case 78: /* logical_or: logical_or LOGICAL_OR logical_and  */
#line 828 "src/parser/rules.y"
                                      {
        (yyval.logical_or) = ALLOC(struct logical_or_node_t);
        TFRAG_COMBINE((yyval.logical_or), (yyvsp[-2].logical_or), (yyvsp[-1].name), (yyvsp[0].logical_and));
        (yyval.logical_or)->arg1 = (yyvsp[-2].logical_or);
        (yyval.logical_or)->op = (yyvsp[-1].name);
        (yyval.logical_or)->arg2 = (yyvsp[0].logical_and);
    }
#line 2578 "src/parser/rules.tab.c"
    break;

  case 79: /* logical_or: logical_and  */
#line 835 "src/parser/rules.y"
                  {
        (yyval.logical_or) = ALLOC(struct logical_or_node_t);
        TFRAG_COMBINE((yyval.logical_or), (yyvsp[0].logical_and));
        (yyval.logical_or)->other = (yyvsp[0].logical_and);
    }
#line 2588 "src/parser/rules.tab.c"
    break;

  case 80: /* logical_and: logical_and LOGICAL_AND bitwise_or  */
#line 843 "src/parser/rules.y"
                                       {
        (yyval.logical_and) = ALLOC(struct logical_and_node_t);
        TFRAG_COMBINE((yyval.logical_and), (yyvsp[-2].logical_and), (yyvsp[-1].name), (yyvsp[0].bitwise_or));
        (yyval.logical_and)->arg1 = (yyvsp[-2].logical_and);
        (yyval.logical_and)->op = (yyvsp[-1].name);
        (yyval.logical_and)->arg2 = (yyvsp[0].bitwise_or);
    }
#line 2600 "src/parser/rules.tab.c"
    break;

  case 81: /* logical_and: bitwise_or  */
#line 850 "src/parser/rules.y"
                 {
        (yyval.logical_and) = ALLOC(struct logical_and_node_t);
        TFRAG_COMBINE((yyval.logical_and), (yyvsp[0].bitwise_or));
        (yyval.logical_and)->other = (yyvsp[0].bitwise_or);
    }
#line 2610 "src/parser/rules.tab.c"
    break;

  case 82: /* bitwise_or: bitwise_or BITWISE_OR bitwise_xor  */
#line 858 "src/parser/rules.y"
                                      {
        (yyval.bitwise_or) = ALLOC(struct bitwise_or_node_t);
        TFRAG_COMBINE((yyval.bitwise_or), (yyvsp[-2].bitwise_or), (yyvsp[-1].name), (yyvsp[0].bitwise_xor));
        (yyval.bitwise_or)->arg1 = (yyvsp[-2].bitwise_or);
        (yyval.bitwise_or)->op = (yyvsp[-1].name);
        (yyval.bitwise_or)->arg2 = (yyvsp[0].bitwise_xor);
    }
#line 2622 "src/parser/rules.tab.c"
    break;

  case 83: /* bitwise_or: bitwise_xor  */
#line 865 "src/parser/rules.y"
                  {
        (yyval.bitwise_or) = ALLOC(struct bitwise_or_node_t);
        TFRAG_COMBINE((yyval.bitwise_or), (yyvsp[0].bitwise_xor));
        (yyval.bitwise_or)->other = (yyvsp[0].bitwise_xor);
    }
#line 2632 "src/parser/rules.tab.c"
    break;

  case 84: /* bitwise_xor: bitwise_xor BITWISE_XOR bitwise_and  */
#line 873 "src/parser/rules.y"
                                        {
        (yyval.bitwise_xor) = ALLOC(struct bitwise_xor_node_t);
        TFRAG_COMBINE((yyval.bitwise_xor), (yyvsp[-2].bitwise_xor), (yyvsp[-1].name), (yyvsp[0].bitwise_and));
        (yyval.bitwise_xor)->arg1 = (yyvsp[-2].bitwise_xor);
        (yyval.bitwise_xor)->op = (yyvsp[-1].name);
        (yyval.bitwise_xor)->arg2 = (yyvsp[0].bitwise_and);
    }
#line 2644 "src/parser/rules.tab.c"
    break;

  case 85: /* bitwise_xor: bitwise_and  */
#line 880 "src/parser/rules.y"
                  {
        (yyval.bitwise_xor) = ALLOC(struct bitwise_xor_node_t);
        TFRAG_COMBINE((yyval.bitwise_xor), (yyvsp[0].bitwise_and));
        (yyval.bitwise_xor)->other = (yyvsp[0].bitwise_and);
    }
#line 2654 "src/parser/rules.tab.c"
    break;

  case 86: /* bitwise_and: bitwise_and BITWISE_AND equality  */
#line 888 "src/parser/rules.y"
                                     {
        (yyval.bitwise_and) = ALLOC(struct bitwise_and_node_t);
        TFRAG_COMBINE((yyval.bitwise_and), (yyvsp[-2].bitwise_and), (yyvsp[-1].name), (yyvsp[0].equality));
        (yyval.bitwise_and)->arg1 = (yyvsp[-2].bitwise_and);
        (yyval.bitwise_and)->op = (yyvsp[-1].name);
        (yyval.bitwise_and)->arg2 = (yyvsp[0].equality);
    }
#line 2666 "src/parser/rules.tab.c"
    break;

  case 87: /* bitwise_and: equality  */
#line 895 "src/parser/rules.y"
               {
        (yyval.bitwise_and) = ALLOC(struct bitwise_and_node_t);
        TFRAG_COMBINE((yyval.bitwise_and), (yyvsp[0].equality));
        (yyval.bitwise_and)->other = (yyvsp[0].equality);
    }
#line 2676 "src/parser/rules.tab.c"
    break;

  case 88: /* equality: equality EQUALS relational  */
#line 903 "src/parser/rules.y"
                               {
        (yyval.equality) = ALLOC(struct equality_node_t);
        TFRAG_COMBINE((yyval.equality), (yyvsp[-2].equality), (yyvsp[-1].name), (yyvsp[0].relational));
        (yyval.equality)->arg1 = (yyvsp[-2].equality);
        (yyval.equality)->op = (yyvsp[-1].name);
        (yyval.equality)->arg2 = (yyvsp[0].relational);
    }
#line 2688 "src/parser/rules.tab.c"
    break;

  case 89: /* equality: equality NOT_EQUALS relational  */
#line 910 "src/parser/rules.y"
                                     {
        (yyval.equality) = ALLOC(struct equality_node_t);
        TFRAG_COMBINE((yyval.equality), (yyvsp[-2].equality), (yyvsp[-1].name), (yyvsp[0].relational));
        (yyval.equality)->arg1 = (yyvsp[-2].equality);
        (yyval.equality)->op = (yyvsp[-1].name);
        (yyval.equality)->arg2 = (yyvsp[0].relational);
    }
#line 2700 "src/parser/rules.tab.c"
    break;

  case 90: /* equality: relational  */
#line 917 "src/parser/rules.y"
                 {
        (yyval.equality) = ALLOC(struct equality_node_t);
        TFRAG_COMBINE((yyval.equality), (yyvsp[0].relational));
        (yyval.equality)->other = (yyvsp[0].relational);
    }
#line 2710 "src/parser/rules.tab.c"
    break;

  case 91: /* relational: relational LESS_THAN additive  */
#line 925 "src/parser/rules.y"
                                  {
        (yyval.relational) = ALLOC(struct relational_node_t);
        TFRAG_COMBINE((yyval.relational), (yyvsp[-2].relational), (yyvsp[-1].name), (yyvsp[0].additive));
        (yyval.relational)->arg1 = (yyvsp[-2].relational);
        (yyval.relational)->op = (yyvsp[-1].name);
        (yyval.relational)->arg2 = (yyvsp[0].additive);
    }
#line 2722 "src/parser/rules.tab.c"
    break;

  case 92: /* relational: relational GREATER_THAN additive  */
#line 932 "src/parser/rules.y"
                                       {
        (yyval.relational) = ALLOC(struct relational_node_t);
        TFRAG_COMBINE((yyval.relational), (yyvsp[-2].relational), (yyvsp[-1].name), (yyvsp[0].additive));
        (yyval.relational)->arg1 = (yyvsp[-2].relational);
        (yyval.relational)->op = (yyvsp[-1].name);
        (yyval.relational)->arg2 = (yyvsp[0].additive);
    }
#line 2734 "src/parser/rules.tab.c"
    break;

  case 93: /* relational: relational LESS_EQUAL additive  */
#line 939 "src/parser/rules.y"
                                     {
        (yyval.relational) = ALLOC(struct relational_node_t);
        TFRAG_COMBINE((yyval.relational), (yyvsp[-2].relational), (yyvsp[-1].name), (yyvsp[0].additive));
        (yyval.relational)->arg1 = (yyvsp[-2].relational);
        (yyval.relational)->op = (yyvsp[-1].name);
        (yyval.relational)->arg2 = (yyvsp[0].additive);
    }
#line 2746 "src/parser/rules.tab.c"
    break;

  case 94: /* relational: relational GREATER_EQUAL additive  */
#line 946 "src/parser/rules.y"
                                        {
        (yyval.relational) = ALLOC(struct relational_node_t);
        TFRAG_COMBINE((yyval.relational), (yyvsp[-2].relational), (yyvsp[-1].name), (yyvsp[0].additive));
        (yyval.relational)->arg1 = (yyvsp[-2].relational);
        (yyval.relational)->op = (yyvsp[-1].name);
        (yyval.relational)->arg2 = (yyvsp[0].additive);
    }
#line 2758 "src/parser/rules.tab.c"
    break;

  case 95: /* relational: additive  */
#line 953 "src/parser/rules.y"
               {
        (yyval.relational) = ALLOC(struct relational_node_t);
        TFRAG_COMBINE((yyval.relational), (yyvsp[0].additive));
        (yyval.relational)->other = (yyvsp[0].additive);
    }
#line 2768 "src/parser/rules.tab.c"
    break;

  case 96: /* additive: additive PLUS multiplicative  */
#line 961 "src/parser/rules.y"
                                 {
        (yyval.additive) = ALLOC(struct additive_node_t);
        TFRAG_COMBINE((yyval.additive), (yyvsp[-2].additive), (yyvsp[-1].name), (yyvsp[0].multiplicative));
        (yyval.additive)->arg1 = (yyvsp[-2].additive);
        (yyval.additive)->op = (yyvsp[-1].name);
        (yyval.additive)->arg2 = (yyvsp[0].multiplicative);
    }
#line 2780 "src/parser/rules.tab.c"
    break;

  case 97: /* additive: additive MINUS multiplicative  */
#line 968 "src/parser/rules.y"
                                    {
        (yyval.additive) = ALLOC(struct additive_node_t);
        TFRAG_COMBINE((yyval.additive), (yyvsp[-2].additive), (yyvsp[-1].name), (yyvsp[0].multiplicative));
        (yyval.additive)->arg1 = (yyvsp[-2].additive);
        (yyval.additive)->op = (yyvsp[-1].name);
        (yyval.additive)->arg2 = (yyvsp[0].multiplicative);
    }
#line 2792 "src/parser/rules.tab.c"
    break;

  case 98: /* additive: multiplicative  */
#line 975 "src/parser/rules.y"
                     {
        (yyval.additive) = ALLOC(struct additive_node_t);
        TFRAG_COMBINE((yyval.additive), (yyvsp[0].multiplicative));
        (yyval.additive)->other = (yyvsp[0].multiplicative);
    }
#line 2802 "src/parser/rules.tab.c"
    break;

  case 99: /* multiplicative: multiplicative MULTIPLY tetriary  */
#line 983 "src/parser/rules.y"
                                     {
        (yyval.multiplicative) = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE((yyval.multiplicative), (yyvsp[-2].multiplicative), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.multiplicative)->arg1 = (yyvsp[-2].multiplicative);
        (yyval.multiplicative)->op = (yyvsp[-1].name);
        (yyval.multiplicative)->arg2 = (yyvsp[0].tetriary);
    }
#line 2814 "src/parser/rules.tab.c"
    break;

  case 100: /* multiplicative: multiplicative DIVIDE tetriary  */
#line 990 "src/parser/rules.y"
                                     {
        (yyval.multiplicative) = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE((yyval.multiplicative), (yyvsp[-2].multiplicative), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.multiplicative)->arg1 = (yyvsp[-2].multiplicative);
        (yyval.multiplicative)->op = (yyvsp[-1].name);
        (yyval.multiplicative)->arg2 = (yyvsp[0].tetriary);
    }
#line 2826 "src/parser/rules.tab.c"
    break;

  case 101: /* multiplicative: multiplicative REMAINDER tetriary  */
#line 997 "src/parser/rules.y"
                                        {
        (yyval.multiplicative) = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE((yyval.multiplicative), (yyvsp[-2].multiplicative), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.multiplicative)->arg1 = (yyvsp[-2].multiplicative);
        (yyval.multiplicative)->op = (yyvsp[-1].name);
        (yyval.multiplicative)->arg2 = (yyvsp[0].tetriary);
    }
#line 2838 "src/parser/rules.tab.c"
    break;

  case 102: /* multiplicative: tetriary  */
#line 1004 "src/parser/rules.y"
               {
        (yyval.multiplicative) = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE((yyval.multiplicative), (yyvsp[0].tetriary));
        (yyval.multiplicative)->other = (yyvsp[0].tetriary);
    }
#line 2848 "src/parser/rules.tab.c"
    break;

  case 103: /* prefix_op: INCREMENT tetriary  */
#line 1012 "src/parser/rules.y"
                       {
        (yyval.prefix_op) = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE((yyval.prefix_op), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.prefix_op)->op = (yyvsp[-1].name);
        (yyval.prefix_op)->arg = (yyvsp[0].tetriary);
    }
#line 2859 "src/parser/rules.tab.c"
    break;

  case 104: /* prefix_op: DECREMENT tetriary  */
#line 1018 "src/parser/rules.y"
                         {
        (yyval.prefix_op) = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE((yyval.prefix_op), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.prefix_op)->op = (yyvsp[-1].name);
        (yyval.prefix_op)->arg = (yyvsp[0].tetriary);
    }
#line 2870 "src/parser/rules.tab.c"
    break;

  case 105: /* prefix_op: LOGICAL_NOT tetriary  */
#line 1024 "src/parser/rules.y"
                           {
        (yyval.prefix_op) = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE((yyval.prefix_op), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.prefix_op)->op = (yyvsp[-1].name);
        (yyval.prefix_op)->arg = (yyvsp[0].tetriary);
    }
#line 2881 "src/parser/rules.tab.c"
    break;

  case 106: /* prefix_op: BITWISE_NOT tetriary  */
#line 1030 "src/parser/rules.y"
                           {
        (yyval.prefix_op) = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE((yyval.prefix_op), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.prefix_op)->op = (yyvsp[-1].name);
        (yyval.prefix_op)->arg = (yyvsp[0].tetriary);
    }
#line 2892 "src/parser/rules.tab.c"
    break;

  case 107: /* cast_op: tetriary CAST  */
#line 1039 "src/parser/rules.y"
                  {
        (yyval.cast_op) = ALLOC(struct cast_op_node_t);
        TFRAG_COMBINE((yyval.cast_op), (yyvsp[-1].tetriary), (yyvsp[0].name));
        (yyval.cast_op)->arg = (yyvsp[-1].tetriary);
        (yyval.cast_op)->op = (yyvsp[0].name);
    }
#line 2903 "src/parser/rules.tab.c"
    break;

  case 108: /* address_op: "[" expression "]" tetriary  */
#line 1048 "src/parser/rules.y"
                                {
        (yyval.address_op) = ALLOC(struct address_op_node_t);
        TFRAG_COMBINE((yyval.address_op), (yyvsp[-3].name), (yyvsp[-2].expression), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.address_op)->open_brace = (yyvsp[-3].name);
        (yyval.address_op)->offset = (yyvsp[-2].expression);
        (yyval.address_op)->closed_brace = (yyvsp[-1].name);
        (yyval.address_op)->arg = (yyvsp[0].tetriary);
    }
#line 2916 "src/parser/rules.tab.c"
    break;

  case 109: /* address_op: "[" "]" tetriary  */
#line 1056 "src/parser/rules.y"
                       {
        (yyval.address_op) = ALLOC(struct address_op_node_t);
        TFRAG_COMBINE((yyval.address_op), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.address_op)->open_brace = (yyvsp[-2].name);
        (yyval.address_op)->closed_brace = (yyvsp[-1].name);
        (yyval.address_op)->arg = (yyvsp[0].tetriary);
    }
#line 2928 "src/parser/rules.tab.c"
    break;

  case 110: /* sizeof_op: SIZEOF NAME  */
#line 1066 "src/parser/rules.y"
                {
        (yyval.sizeof_op) = ALLOC(struct sizeof_op_node_t);
        TFRAG_COMBINE((yyval.sizeof_op), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.sizeof_op)->kw = (yyvsp[-1].name);
        (yyval.sizeof_op)->name = (yyvsp[0].name);
    }
#line 2939 "src/parser/rules.tab.c"
    break;

  case 111: /* tetriary: prefix_op  */
#line 1075 "src/parser/rules.y"
              {
        (yyval.tetriary) = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE((yyval.tetriary), (yyvsp[0].prefix_op));
        (yyval.tetriary)->prefix = (yyvsp[0].prefix_op);
    }
#line 2949 "src/parser/rules.tab.c"
    break;

  case 112: /* tetriary: cast_op  */
#line 1080 "src/parser/rules.y"
              {
        (yyval.tetriary) = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE((yyval.tetriary), (yyvsp[0].cast_op));
        (yyval.tetriary)->cast = (yyvsp[0].cast_op);
    }
#line 2959 "src/parser/rules.tab.c"
    break;

  case 113: /* tetriary: address_op  */
#line 1085 "src/parser/rules.y"
                 {
        (yyval.tetriary) = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE((yyval.tetriary), (yyvsp[0].address_op));
        (yyval.tetriary)->address = (yyvsp[0].address_op);
    }
#line 2969 "src/parser/rules.tab.c"
    break;

  case 114: /* tetriary: sizeof_op  */
#line 1090 "src/parser/rules.y"
                {
        (yyval.tetriary) = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE((yyval.tetriary), (yyvsp[0].sizeof_op));
        (yyval.tetriary)->sizeof_op = (yyvsp[0].sizeof_op);
    }
#line 2979 "src/parser/rules.tab.c"
    break;

  case 115: /* tetriary: secondary  */
#line 1095 "src/parser/rules.y"
                {
        (yyval.tetriary) = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE((yyval.tetriary), (yyvsp[0].secondary));
        (yyval.tetriary)->secondary = (yyvsp[0].secondary);
    }
#line 2989 "src/parser/rules.tab.c"
    break;

  case 116: /* suffix_op: secondary INCREMENT  */
#line 1103 "src/parser/rules.y"
                        {
        (yyval.suffix_op) = ALLOC(struct suffix_op_node_t);
        TFRAG_COMBINE((yyval.suffix_op), (yyvsp[-1].secondary), (yyvsp[0].name));
        (yyval.suffix_op)->arg = (yyvsp[-1].secondary);
        (yyval.suffix_op)->op = (yyvsp[0].name);
    }
#line 3000 "src/parser/rules.tab.c"
    break;

  case 117: /* suffix_op: secondary DECREMENT  */
#line 1109 "src/parser/rules.y"
                          {
        (yyval.suffix_op) = ALLOC(struct suffix_op_node_t);
        TFRAG_COMBINE((yyval.suffix_op), (yyvsp[-1].secondary), (yyvsp[0].name));
        (yyval.suffix_op)->arg = (yyvsp[-1].secondary);
        (yyval.suffix_op)->op = (yyvsp[0].name);
    }
#line 3011 "src/parser/rules.tab.c"
    break;

  case 118: /* dereference_op: secondary "[" expression "]"  */
#line 1118 "src/parser/rules.y"
                                 {
        (yyval.dereference_op) = ALLOC(struct dereference_op_node_t);
        TFRAG_COMBINE((yyval.dereference_op), (yyvsp[-3].secondary), (yyvsp[-2].name), (yyvsp[-1].expression), (yyvsp[0].name));
        (yyval.dereference_op)->arg = (yyvsp[-3].secondary);
        (yyval.dereference_op)->open_brace = (yyvsp[-2].name);
        (yyval.dereference_op)->offset = (yyvsp[-1].expression);
        (yyval.dereference_op)->close_brace = (yyvsp[0].name);
    }
#line 3024 "src/parser/rules.tab.c"
    break;

  case 119: /* dereference_op: secondary "[" "]"  */
#line 1126 "src/parser/rules.y"
                        {
        (yyval.dereference_op) = ALLOC(struct dereference_op_node_t);
        TFRAG_COMBINE((yyval.dereference_op), (yyvsp[-2].secondary), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.dereference_op)->arg = (yyvsp[-2].secondary);
        (yyval.dereference_op)->open_brace = (yyvsp[-1].name);
        (yyval.dereference_op)->close_brace = (yyvsp[0].name);
    }
#line 3036 "src/parser/rules.tab.c"
    break;

  case 120: /* layout_access_op: secondary ACCESS NAME  */
#line 1136 "src/parser/rules.y"
                          {
        (yyval.layout_access_op) = ALLOC(struct layout_access_op_node_t);
        TFRAG_COMBINE((yyval.layout_access_op), (yyvsp[-2].secondary), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.layout_access_op)->arg = (yyvsp[-2].secondary);
        (yyval.layout_access_op)->op = (yyvsp[-1].name);
        (yyval.layout_access_op)->field = (yyvsp[0].name);
    }
#line 3048 "src/parser/rules.tab.c"
    break;

  case 121: /* secondary: suffix_op  */
#line 1146 "src/parser/rules.y"
              {
        (yyval.secondary) = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE((yyval.secondary), (yyvsp[0].suffix_op));
        (yyval.secondary)->suffix = (yyvsp[0].suffix_op);
    }
#line 3058 "src/parser/rules.tab.c"
    break;

  case 122: /* secondary: dereference_op  */
#line 1151 "src/parser/rules.y"
                     {
        (yyval.secondary) = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE((yyval.secondary), (yyvsp[0].dereference_op));
        (yyval.secondary)->deref = (yyvsp[0].dereference_op);
    }
#line 3068 "src/parser/rules.tab.c"
    break;

  case 123: /* secondary: layout_access_op  */
#line 1156 "src/parser/rules.y"
                       {
        (yyval.secondary) = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE((yyval.secondary), (yyvsp[0].layout_access_op));
        (yyval.secondary)->layout_access = (yyvsp[0].layout_access_op);
    }
#line 3078 "src/parser/rules.tab.c"
    break;

  case 124: /* secondary: primary  */
#line 1161 "src/parser/rules.y"
              {
        (yyval.secondary) = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE((yyval.secondary), (yyvsp[0].primary));
        (yyval.secondary)->primary = (yyvsp[0].primary);
    }
#line 3088 "src/parser/rules.tab.c"
    break;

  case 125: /* primary: "(" expression ")"  */
#line 1169 "src/parser/rules.y"
                       {
        (yyval.primary) = ALLOC(struct primary_node_t);
        TFRAG_COMBINE((yyval.primary), (yyvsp[-2].name), (yyvsp[-1].expression), (yyvsp[0].name));
        (yyval.primary)->open_brace = (yyvsp[-2].name);
        (yyval.primary)->expression = (yyvsp[-1].expression);
        (yyval.primary)->close_brace = (yyvsp[0].name);
    }
#line 3100 "src/parser/rules.tab.c"
    break;

  case 126: /* primary: literal  */
#line 1176 "src/parser/rules.y"
              {
        (yyval.primary) = ALLOC(struct primary_node_t);
        TFRAG_COMBINE((yyval.primary), (yyvsp[0].literal));
        (yyval.primary)->literal = (yyvsp[0].literal);
    }
#line 3110 "src/parser/rules.tab.c"
    break;

  case 127: /* literal: INT  */
#line 1184 "src/parser/rules.y"
        { (yyval.literal) = (yyvsp[0].literal); }
#line 3116 "src/parser/rules.tab.c"
    break;

  case 128: /* literal: UINT  */
#line 1185 "src/parser/rules.y"
           { (yyval.literal) = (yyvsp[0].literal); }
#line 3122 "src/parser/rules.tab.c"
    break;

  case 129: /* literal: DOUBLE  */
#line 1186 "src/parser/rules.y"
             { (yyval.literal) = (yyvsp[0].literal); }
#line 3128 "src/parser/rules.tab.c"
    break;

  case 130: /* literal: STRING  */
#line 1187 "src/parser/rules.y"
             { (yyval.literal) = (yyvsp[0].literal); }
#line 3134 "src/parser/rules.tab.c"
    break;

  case 131: /* literal: NAME  */
#line 1188 "src/parser/rules.y"
           {
        (yyval.literal) = ALLOC(struct literal_node_t);
        TFRAG_COMBINE((yyval.literal), (yyvsp[0].name));
        (yyval.literal)->type = LIT_NAME;
        (yyval.literal)->name_lit = (yyvsp[0].name);
    }
#line 3145 "src/parser/rules.tab.c"
    break;


#line 3149 "src/parser/rules.tab.c"

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

#line 1196 "src/parser/rules.y"

