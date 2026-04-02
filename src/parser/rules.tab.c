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

    #define YYMALLOC(sz) calloc_safe(1, sz)
    #define YYFREE(p) free(p)

    #define ALLOC(t) ({\
        t *res = calloc_safe(1, sizeof(t));\
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

#line 140 "src/parser/rules.tab.c"

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
  YYSYMBOL_CALL = 33,                      /* CALL  */
  YYSYMBOL_LOGICAL_OR = 34,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_AND = 35,               /* LOGICAL_AND  */
  YYSYMBOL_ASSIGN = 36,                    /* ASSIGN  */
  YYSYMBOL_INCREMENT = 37,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 38,                 /* DECREMENT  */
  YYSYMBOL_SIZEOF = 39,                    /* SIZEOF  */
  YYSYMBOL_PLUS = 40,                      /* PLUS  */
  YYSYMBOL_MINUS = 41,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 42,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 43,                    /* DIVIDE  */
  YYSYMBOL_REMAINDER = 44,                 /* REMAINDER  */
  YYSYMBOL_BITWISE_AND = 45,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 46,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 47,               /* BITWISE_XOR  */
  YYSYMBOL_LOGICAL_NOT = 48,               /* LOGICAL_NOT  */
  YYSYMBOL_BITWISE_NOT = 49,               /* BITWISE_NOT  */
  YYSYMBOL_LESS_THAN = 50,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 51,              /* GREATER_THAN  */
  YYSYMBOL_LESS_EQUAL = 52,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 53,             /* GREATER_EQUAL  */
  YYSYMBOL_EQUALS = 54,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 55,                /* NOT_EQUALS  */
  YYSYMBOL_CAST = 56,                      /* CAST  */
  YYSYMBOL_ACCESS = 57,                    /* ACCESS  */
  YYSYMBOL_ROB = 58,                       /* "("  */
  YYSYMBOL_RCB = 59,                       /* ")"  */
  YYSYMBOL_SOB = 60,                       /* "["  */
  YYSYMBOL_SCB = 61,                       /* "]"  */
  YYSYMBOL_COB = 62,                       /* "{"  */
  YYSYMBOL_CCB = 63,                       /* "}"  */
  YYSYMBOL_ARROW = 64,                     /* ARROW  */
  YYSYMBOL_COLON = 65,                     /* ":"  */
  YYSYMBOL_SEMICOLON = 66,                 /* ";"  */
  YYSYMBOL_COMMA = 67,                     /* ","  */
  YYSYMBOL_YYACCEPT = 68,                  /* $accept  */
  YYSYMBOL_program = 69,                   /* program  */
  YYSYMBOL_visibility = 70,                /* visibility  */
  YYSYMBOL_memory_length = 71,             /* memory_length  */
  YYSYMBOL_alignment = 72,                 /* alignment  */
  YYSYMBOL_global_variable_declaration = 73, /* global_variable_declaration  */
  YYSYMBOL_chunk_class = 74,               /* chunk_class  */
  YYSYMBOL_abi_class = 75,                 /* abi_class  */
  YYSYMBOL_layout_declaration_items = 76,  /* layout_declaration_items  */
  YYSYMBOL_layout_declaration = 77,        /* layout_declaration  */
  YYSYMBOL_extern_declaration = 78,        /* extern_declaration  */
  YYSYMBOL_function_declaration_arg = 79,  /* function_declaration_arg  */
  YYSYMBOL_function_declaration_args = 80, /* function_declaration_args  */
  YYSYMBOL_function_declaration = 81,      /* function_declaration  */
  YYSYMBOL_body_list = 82,                 /* body_list  */
  YYSYMBOL_body = 83,                      /* body  */
  YYSYMBOL_statement = 84,                 /* statement  */
  YYSYMBOL_variable_declaration = 85,      /* variable_declaration  */
  YYSYMBOL_register_alias = 86,            /* register_alias  */
  YYSYMBOL_if_statement = 87,              /* if_statement  */
  YYSYMBOL_label_declaration = 88,         /* label_declaration  */
  YYSYMBOL_goto_statement = 89,            /* goto_statement  */
  YYSYMBOL_loop_statement = 90,            /* loop_statement  */
  YYSYMBOL_break_statement = 91,           /* break_statement  */
  YYSYMBOL_ret_statement = 92,             /* ret_statement  */
  YYSYMBOL_avoid_block_regs = 93,          /* avoid_block_regs  */
  YYSYMBOL_avoid_block = 94,               /* avoid_block  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_logical_or = 96,                /* logical_or  */
  YYSYMBOL_logical_and = 97,               /* logical_and  */
  YYSYMBOL_bitwise_or = 98,                /* bitwise_or  */
  YYSYMBOL_bitwise_xor = 99,               /* bitwise_xor  */
  YYSYMBOL_bitwise_and = 100,              /* bitwise_and  */
  YYSYMBOL_equality = 101,                 /* equality  */
  YYSYMBOL_relational = 102,               /* relational  */
  YYSYMBOL_additive = 103,                 /* additive  */
  YYSYMBOL_multiplicative = 104,           /* multiplicative  */
  YYSYMBOL_prefix_op = 105,                /* prefix_op  */
  YYSYMBOL_cast_op = 106,                  /* cast_op  */
  YYSYMBOL_address_op = 107,               /* address_op  */
  YYSYMBOL_sizeof_op = 108,                /* sizeof_op  */
  YYSYMBOL_tetriary = 109,                 /* tetriary  */
  YYSYMBOL_suffix_op = 110,                /* suffix_op  */
  YYSYMBOL_function_call_op_arg = 111,     /* function_call_op_arg  */
  YYSYMBOL_function_call_op_args = 112,    /* function_call_op_args  */
  YYSYMBOL_function_call_op = 113,         /* function_call_op  */
  YYSYMBOL_dereference_op = 114,           /* dereference_op  */
  YYSYMBOL_layout_access_op = 115,         /* layout_access_op  */
  YYSYMBOL_secondary = 116,                /* secondary  */
  YYSYMBOL_primary = 117,                  /* primary  */
  YYSYMBOL_literal = 118                   /* literal  */
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
#define YYLAST   339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   322


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
      65,    66,    67
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   247,   247,   254,   261,   268,   275,   282,   289,   293,
     294,   298,   302,   309,   317,   325,   337,   338,   339,   343,
     348,   354,   362,   370,   380,   390,   401,   416,   422,   431,
     436,   443,   450,   457,   465,   473,   481,   493,   500,   505,
     511,   522,   535,   548,   562,   574,   588,   602,   621,   627,
     633,   643,   648,   653,   658,   663,   668,   673,   678,   683,
     688,   693,   699,   707,   714,   725,   733,   744,   751,   763,
     772,   782,   791,   797,   806,   816,   823,   830,   835,   843,
     853,   860,   868,   875,   883,   890,   898,   905,   913,   920,
     928,   935,   943,   950,   957,   965,   972,   979,   986,   993,
    1001,  1008,  1015,  1023,  1030,  1037,  1044,  1052,  1058,  1064,
    1070,  1079,  1088,  1096,  1106,  1115,  1120,  1125,  1130,  1135,
    1143,  1149,  1158,  1163,  1170,  1177,  1184,  1192,  1200,  1208,
    1220,  1227,  1232,  1238,  1247,  1257,  1267,  1280,  1288,  1298,
    1308,  1313,  1318,  1323,  1328,  1336,  1343,  1351,  1352,  1353,
    1354,  1355
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
  "CALL", "LOGICAL_OR", "LOGICAL_AND", "ASSIGN", "INCREMENT", "DECREMENT",
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
  "suffix_op", "function_call_op_arg", "function_call_op_args",
  "function_call_op", "dereference_op", "layout_access_op", "secondary",
  "primary", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -163,   114,  -163,   -48,     9,    40,  -163,  -163,  -163,  -163,
    -163,   133,  -163,  -163,  -163,  -163,  -163,    39,   -12,    99,
      61,  -163,  -163,  -163,    84,    91,    94,    -9,    61,  -163,
    -163,    57,     0,    84,    78,    60,  -163,   -35,    94,  -163,
      83,   100,  -163,     3,    84,   234,    73,    94,    19,  -163,
      83,  -163,     4,  -163,   171,    48,   144,  -163,  -163,   280,
    -163,  -163,   111,  -163,  -163,    48,  -163,  -163,  -163,   141,
      68,    81,   280,  -163,  -163,   107,  -163,  -163,  -163,  -163,
    -163,   279,   146,    81,    93,   134,   279,   103,   216,   279,
     279,   212,   279,   279,   279,    51,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,   160,   152,
     182,   190,   191,   192,   122,   161,   151,   153,  -163,  -163,
    -163,  -163,   196,  -163,  -163,  -163,  -163,    38,  -163,  -163,
      81,  -163,  -163,    68,    81,     5,  -163,    81,   195,  -163,
    -163,  -163,   200,  -163,  -163,   -28,   266,   279,   209,   196,
     196,  -163,   196,   196,   222,   279,   207,  -163,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,  -163,  -163,  -163,   272,   202,
    -163,    81,  -163,  -163,    -7,    61,   263,  -163,  -163,   187,
    -163,   279,   232,   237,   279,  -163,   196,   279,   182,  -163,
     190,   191,   192,   122,   161,   161,   151,   151,   151,   151,
     153,   153,   196,   196,   196,  -163,  -163,   235,  -163,  -163,
    -163,  -163,    81,  -163,  -163,   239,   279,   279,   233,  -163,
      46,   196,  -163,  -163,   279,    56,    65,   234,  -163,   279,
      72,  -163,  -163,   171,    48,  -163,  -163,  -163,    48,  -163,
    -163,  -163
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     1,     0,     0,     0,     6,     2,     3,     4,
       5,     0,    27,    28,     9,    10,     8,     0,     0,     0,
      12,    16,    17,    18,     0,     0,    39,     0,    13,    11,
      14,     0,     0,     0,     0,    29,    38,     0,    39,    15,
       0,     0,    24,     0,     0,     0,     0,     0,     0,    23,
       0,    25,     0,    21,    30,    31,    19,    32,    49,     0,
      40,    37,     0,    22,    26,    33,    34,    35,    20,     0,
       0,     0,     0,    44,    36,   151,   147,   148,   149,   150,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    53,    48,    51,
      52,    54,    55,    56,    57,    58,    59,    60,     0,    81,
      83,    85,    87,    89,    91,    94,    99,   102,   115,   116,
     117,   118,   106,   140,   141,   142,   143,   119,   144,   146,
       0,    41,    42,     0,     0,    69,   151,     0,     0,    71,
      72,    73,     0,    78,    77,     0,     0,     0,     0,   107,
     108,   114,   109,   110,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   120,   121,     0,     0,
      43,     0,    45,    46,     0,    63,    67,    70,    74,     0,
      79,     0,     0,     0,   132,   145,   113,     0,    82,    80,
      84,    86,    88,    90,    92,    93,    95,    96,    97,    98,
     100,   101,   103,   104,   105,   139,   138,     0,    47,    66,
      65,    64,     0,    76,    75,     0,   132,   132,   122,   131,
       0,   112,   137,    68,   132,     0,     0,     0,   133,     0,
       0,   134,   135,   123,   124,   125,   130,   136,   126,   127,
     128,   129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,   -19,   -27,  -163,    12,   -50,   -14,  -163,
     231,   254,   264,  -163,  -163,   -60,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,   -53,  -163,   148,
     147,   149,   157,   145,    67,    90,    63,  -163,  -163,  -163,
    -163,   -45,  -163,    70,  -162,  -163,  -163,  -163,  -163,  -163,
    -163
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    19,    20,    30,     7,    56,    57,    32,     8,
       9,    36,    37,    10,    69,    60,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   145,   107,   228,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   229,   230,   124,   125,   126,   127,   128,
     129
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    39,    73,    41,    66,    67,    41,    41,   219,    71,
     131,   132,    12,    14,    15,    74,   108,    11,    55,    43,
     130,    49,   134,   139,    46,   220,    54,    65,   137,    25,
      52,    63,    47,   142,    58,   148,   184,    34,   147,   189,
      70,   154,   156,    13,   149,   150,    26,   152,   153,    38,
      21,    22,    23,   133,   136,    76,    77,    78,    79,    21,
      22,    23,    53,    42,   235,   236,    51,    64,    68,   146,
     180,    29,   240,   182,   183,   176,   177,   186,    62,    21,
      22,    23,    53,   181,    88,   190,    47,    31,    89,    90,
      91,    14,    15,   192,   193,   178,   191,    35,   179,    92,
      93,    24,    21,    22,    23,   238,   199,    14,    15,    94,
     196,    95,   155,   239,     2,   241,   185,     3,   143,   144,
      27,   218,    40,   239,   242,    45,   217,   212,   213,   214,
      58,   247,   239,     4,     5,    58,     6,    59,   225,   239,
      44,    14,    15,    58,    75,    76,    77,    78,    79,   138,
      16,    17,   231,    33,    18,    21,    22,    23,   221,   140,
       4,     5,   233,    80,    81,    50,    82,    83,    84,    85,
      86,    87,   135,    58,    88,    72,   164,   165,    89,    90,
      91,    29,    21,    22,    23,    53,   158,   245,   159,    92,
      93,   170,   171,   249,   250,   172,   173,   174,   251,    94,
     141,    95,   223,   224,    96,   136,    76,    77,    78,    79,
     244,   166,   167,   168,   169,   151,   248,   160,   243,   136,
      76,    77,    78,    79,    14,    15,   157,    21,    22,    23,
      53,   204,   205,   210,   211,    88,   161,   163,   162,    89,
      90,    91,    14,    15,    29,    21,    22,    23,    53,    88,
      92,    93,   175,    89,    90,    91,   206,   207,   208,   209,
      94,   187,    95,   216,    92,    93,   188,   194,   197,   136,
      76,    77,    78,    79,    94,   215,    95,    21,    22,    23,
      53,   195,   136,    76,    77,    78,    79,   222,    14,    15,
     226,    21,    22,    23,    53,   227,   232,   234,   237,    88,
      97,    61,    48,    89,    90,    91,   198,   200,   203,   246,
     201,     0,    88,     0,    92,    93,    89,    90,    91,   202,
       0,     0,     0,     0,    94,     0,    95,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,    95
};

static const yytype_int16 yycheck[] =
{
      19,    28,    62,     3,    54,    55,     3,     3,    15,    59,
      70,    71,     3,     8,     9,    65,    69,    65,    45,    33,
      70,    40,    72,    83,    59,    32,    45,    54,    81,    17,
      44,    50,    67,    86,    62,    88,    31,    25,    88,    67,
      59,    94,    95,     3,    89,    90,    58,    92,    93,    58,
      11,    12,    13,    72,     3,     4,     5,     6,     7,    11,
      12,    13,    14,    63,   226,   227,    63,    63,    56,    88,
     130,    10,   234,   133,   134,    37,    38,   137,    59,    11,
      12,    13,    14,   133,    33,   145,    67,     3,    37,    38,
      39,     8,     9,   146,   147,    57,   146,     3,    60,    48,
      49,    62,    11,    12,    13,    59,   159,     8,     9,    58,
     155,    60,    61,    67,     0,    59,   135,     3,    15,    16,
      21,   181,    65,    67,    59,    65,   179,   172,   173,   174,
      62,    59,    67,    19,    20,    62,    22,    64,   191,    67,
      62,     8,     9,    62,     3,     4,     5,     6,     7,     3,
      17,    18,   197,    62,    21,    11,    12,    13,   185,    66,
      19,    20,   222,    22,    23,    65,    25,    26,    27,    28,
      29,    30,    65,    62,    33,    64,    54,    55,    37,    38,
      39,    10,    11,    12,    13,    14,    34,   237,    36,    48,
      49,    40,    41,   243,   244,    42,    43,    44,   248,    58,
      66,    60,    15,    16,    63,     3,     4,     5,     6,     7,
     237,    50,    51,    52,    53,     3,   243,    35,   237,     3,
       4,     5,     6,     7,     8,     9,    66,    11,    12,    13,
      14,   164,   165,   170,   171,    33,    46,    45,    47,    37,
      38,    39,     8,     9,    10,    11,    12,    13,    14,    33,
      48,    49,    56,    37,    38,    39,   166,   167,   168,   169,
      58,    66,    60,    61,    48,    49,    66,    58,    61,     3,
       4,     5,     6,     7,    58,     3,    60,    11,    12,    13,
      14,    59,     3,     4,     5,     6,     7,    24,     8,     9,
      58,    11,    12,    13,    14,    58,    61,    58,    65,    33,
      69,    47,    38,    37,    38,    39,   158,   160,   163,   239,
     161,    -1,    33,    -1,    48,    49,    37,    38,    39,   162,
      -1,    -1,    -1,    -1,    58,    -1,    60,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    69,     0,     3,    19,    20,    22,    73,    77,    78,
      81,    65,     3,     3,     8,     9,    17,    18,    21,    70,
      71,    11,    12,    13,    62,    74,    58,    21,    71,    10,
      72,     3,    76,    62,    74,     3,    79,    80,    58,    72,
      65,     3,    63,    76,    62,    65,    59,    67,    80,    71,
      65,    63,    76,    14,    71,    72,    74,    75,    62,    64,
      83,    79,    59,    71,    63,    72,    75,    75,    74,    82,
      71,    75,    64,    83,    75,     3,     4,     5,     6,     7,
      22,    23,    25,    26,    27,    28,    29,    30,    33,    37,
      38,    39,    48,    49,    58,    60,    63,    78,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   113,   114,   115,   116,   117,   118,
      75,    83,    83,    71,    75,    65,     3,    95,     3,    83,
      66,    66,    95,    15,    16,    93,    71,    75,    95,   109,
     109,     3,   109,   109,    95,    61,    95,    66,    34,    36,
      35,    46,    47,    45,    54,    55,    50,    51,    52,    53,
      40,    41,    42,    43,    44,    56,    37,    38,    57,    60,
      83,    75,    83,    83,    31,    71,    83,    66,    66,    67,
      83,    75,    95,    95,    58,    59,   109,    61,    97,    95,
      98,    99,   100,   101,   102,   102,   103,   103,   103,   103,
     104,   104,   109,   109,   109,     3,    61,    95,    83,    15,
      32,    72,    24,    15,    16,    95,    58,    58,    95,   111,
     112,   109,    61,    83,    58,   112,   112,    65,    59,    67,
     112,    59,    59,    71,    72,    75,   111,    59,    72,    75,
      75,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    69,    69,    69,    69,    69,    70,    71,
      71,    72,    73,    73,    73,    73,    74,    74,    74,    75,
      75,    75,    76,    76,    77,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      89,    90,    91,    91,    92,    93,    93,    93,    93,    94,
      95,    95,    96,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   102,   102,   102,   102,   102,
     103,   103,   103,   104,   104,   104,   104,   105,   105,   105,
     105,   106,   107,   107,   108,   109,   109,   109,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   112,   113,   113,   113,   113,   114,   114,   115,
     116,   116,   116,   116,   116,   117,   117,   118,   118,   118,
     118,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     0,     1,     1,
       1,     1,     3,     4,     4,     5,     1,     1,     1,     1,
       2,     1,     4,     3,     6,     7,     8,     2,     2,     1,
       3,     3,     3,     4,     4,     4,     5,     3,     1,     0,
       7,     9,     9,    10,     8,    10,    10,    11,     2,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     4,     4,     4,     3,     5,     2,
       3,     2,     2,     2,     3,     3,     3,     1,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     2,     2,
       2,     2,     4,     3,     2,     1,     1,     1,     1,     1,
       2,     2,     1,     3,     3,     3,     4,     4,     4,     5,
       3,     1,     0,     5,     6,     6,     7,     4,     3,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
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
#line 247 "src/parser/rules.y"
                                        {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].global_variable_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->gvar_decl = (yyvsp[0].global_variable_declaration);
        parsing_result = (yyval.program);
    }
#line 1734 "src/parser/rules.tab.c"
    break;

  case 3: /* program: program layout_declaration  */
#line 254 "src/parser/rules.y"
                                 {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].layout_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->layout_decl = (yyvsp[0].layout_declaration);
        parsing_result = (yyval.program);
    }
#line 1746 "src/parser/rules.tab.c"
    break;

  case 4: /* program: program extern_declaration  */
#line 261 "src/parser/rules.y"
                                 {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].extern_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->ext_decl = (yyvsp[0].extern_declaration);
        parsing_result = (yyval.program);
    }
#line 1758 "src/parser/rules.tab.c"
    break;

  case 5: /* program: program function_declaration  */
#line 268 "src/parser/rules.y"
                                   {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].function_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->fn_decl = (yyvsp[0].function_declaration);
        parsing_result = (yyval.program);
    }
#line 1770 "src/parser/rules.tab.c"
    break;

  case 6: /* program: program NASM_BLOCK  */
#line 275 "src/parser/rules.y"
                         {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].name));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->nasm_b = (yyvsp[0].name);
        parsing_result = (yyval.program);
    }
#line 1782 "src/parser/rules.tab.c"
    break;

  case 7: /* program: %empty  */
#line 282 "src/parser/rules.y"
      {
        (yyval.program) = ALLOC(struct program_node_t);
        parsing_result = (yyval.program);
    }
#line 1791 "src/parser/rules.tab.c"
    break;

  case 8: /* visibility: GLOBAL  */
#line 289 "src/parser/rules.y"
           { (yyval.name) = (yyvsp[0].name); }
#line 1797 "src/parser/rules.tab.c"
    break;

  case 9: /* memory_length: MEMORY_LENGTH_SIMPLE  */
#line 293 "src/parser/rules.y"
                         { (yyval.name) = (yyvsp[0].name); }
#line 1803 "src/parser/rules.tab.c"
    break;

  case 10: /* memory_length: MEMORY_LENGTH_PREFIX  */
#line 294 "src/parser/rules.y"
                           { (yyval.name) = (yyvsp[0].name); }
#line 1809 "src/parser/rules.tab.c"
    break;

  case 11: /* alignment: ALIGNMENT_SIMPLE  */
#line 298 "src/parser/rules.y"
                     { (yyval.name) = (yyvsp[0].name); }
#line 1815 "src/parser/rules.tab.c"
    break;

  case 12: /* global_variable_declaration: NAME ":" memory_length  */
#line 302 "src/parser/rules.y"
                           {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[0].name);
    }
#line 1827 "src/parser/rules.tab.c"
    break;

  case 13: /* global_variable_declaration: NAME ":" visibility memory_length  */
#line 309 "src/parser/rules.y"
                                        {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-3].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->vis = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[0].name);
    }
#line 1840 "src/parser/rules.tab.c"
    break;

  case 14: /* global_variable_declaration: NAME ":" memory_length alignment  */
#line 317 "src/parser/rules.y"
                                       {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-3].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->align = (yyvsp[0].name);
    }
#line 1853 "src/parser/rules.tab.c"
    break;

  case 15: /* global_variable_declaration: NAME ":" visibility memory_length alignment  */
#line 325 "src/parser/rules.y"
                                                  {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-4].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-3].name);
        (yyval.global_variable_declaration)->vis = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->align = (yyvsp[0].name);
    }
#line 1867 "src/parser/rules.tab.c"
    break;

  case 16: /* chunk_class: CHUNK_CLASS_MEM  */
#line 337 "src/parser/rules.y"
                    { (yyval.name) = (yyvsp[0].name); }
#line 1873 "src/parser/rules.tab.c"
    break;

  case 17: /* chunk_class: CHUNK_CLASS_SSE  */
#line 338 "src/parser/rules.y"
                      { (yyval.name) = (yyvsp[0].name); }
#line 1879 "src/parser/rules.tab.c"
    break;

  case 18: /* chunk_class: CHUNK_CLASS_INT  */
#line 339 "src/parser/rules.y"
                      { (yyval.name) = (yyvsp[0].name); }
#line 1885 "src/parser/rules.tab.c"
    break;

  case 19: /* abi_class: chunk_class  */
#line 343 "src/parser/rules.y"
                {
        (yyval.abi_class) = ALLOC(struct abi_class_node_t);
        TFRAG_COMBINE((yyval.abi_class), (yyvsp[0].name));
        (yyval.abi_class)->chunk1 = (yyvsp[0].name);
    }
#line 1895 "src/parser/rules.tab.c"
    break;

  case 20: /* abi_class: chunk_class chunk_class  */
#line 348 "src/parser/rules.y"
                              {
        (yyval.abi_class) = ALLOC(struct abi_class_node_t);
        TFRAG_COMBINE((yyval.abi_class), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.abi_class)->chunk1 = (yyvsp[-1].name);
        (yyval.abi_class)->chunk2 = (yyvsp[0].name);
    }
#line 1906 "src/parser/rules.tab.c"
    break;

  case 21: /* abi_class: CHUNK_CLASS_LAYOUT  */
#line 354 "src/parser/rules.y"
                         {
        (yyval.abi_class) = ALLOC(struct abi_class_node_t);
        TFRAG_COMBINE((yyval.abi_class), (yyvsp[0].name));
        (yyval.abi_class)->layout = (yyvsp[0].name);
    }
#line 1916 "src/parser/rules.tab.c"
    break;

  case 22: /* layout_declaration_items: layout_declaration_items NAME ":" memory_length  */
#line 362 "src/parser/rules.y"
                                                    {
        (yyval.layout_declaration_items) = ALLOC(struct layout_declaration_items_node_t);
        TFRAG_COMBINE((yyval.layout_declaration_items), (yyvsp[-3].layout_declaration_items), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.layout_declaration_items)->rest = (yyvsp[-3].layout_declaration_items);
        (yyval.layout_declaration_items)->name = (yyvsp[-2].name);
        (yyval.layout_declaration_items)->colon = (yyvsp[-1].name);
        (yyval.layout_declaration_items)->mem_len = (yyvsp[0].name);
    }
#line 1929 "src/parser/rules.tab.c"
    break;

  case 23: /* layout_declaration_items: NAME ":" memory_length  */
#line 370 "src/parser/rules.y"
                             {
        (yyval.layout_declaration_items) = ALLOC(struct layout_declaration_items_node_t);
        TFRAG_COMBINE((yyval.layout_declaration_items), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.layout_declaration_items)->name = (yyvsp[-2].name);
        (yyval.layout_declaration_items)->colon = (yyvsp[-1].name);
        (yyval.layout_declaration_items)->mem_len = (yyvsp[0].name);
    }
#line 1941 "src/parser/rules.tab.c"
    break;

  case 24: /* layout_declaration: NAME ":" LAYOUT "{" layout_declaration_items "}"  */
#line 380 "src/parser/rules.y"
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
#line 1956 "src/parser/rules.tab.c"
    break;

  case 25: /* layout_declaration: NAME ":" LAYOUT chunk_class "{" layout_declaration_items "}"  */
#line 390 "src/parser/rules.y"
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
#line 1972 "src/parser/rules.tab.c"
    break;

  case 26: /* layout_declaration: NAME ":" LAYOUT chunk_class chunk_class "{" layout_declaration_items "}"  */
#line 401 "src/parser/rules.y"
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
#line 1989 "src/parser/rules.tab.c"
    break;

  case 27: /* extern_declaration: EXTERN NAME  */
#line 416 "src/parser/rules.y"
                {
        (yyval.extern_declaration) = ALLOC(struct extern_declaration_node_t);
        TFRAG_COMBINE((yyval.extern_declaration), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.extern_declaration)->kw = (yyvsp[-1].name);
        (yyval.extern_declaration)->name = (yyvsp[0].name);
    }
#line 2000 "src/parser/rules.tab.c"
    break;

  case 28: /* extern_declaration: NASM NAME  */
#line 422 "src/parser/rules.y"
                {
        (yyval.extern_declaration) = ALLOC(struct extern_declaration_node_t);
        TFRAG_COMBINE((yyval.extern_declaration), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.extern_declaration)->kw = (yyvsp[-1].name);
        (yyval.extern_declaration)->name = (yyvsp[0].name);
    }
#line 2011 "src/parser/rules.tab.c"
    break;

  case 29: /* function_declaration_arg: NAME  */
#line 431 "src/parser/rules.y"
         {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[0].name);
    }
#line 2021 "src/parser/rules.tab.c"
    break;

  case 30: /* function_declaration_arg: NAME ":" memory_length  */
#line 436 "src/parser/rules.y"
                             {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[0].name);
    }
#line 2033 "src/parser/rules.tab.c"
    break;

  case 31: /* function_declaration_arg: NAME ":" alignment  */
#line 443 "src/parser/rules.y"
                         {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->align = (yyvsp[0].name);
    }
#line 2045 "src/parser/rules.tab.c"
    break;

  case 32: /* function_declaration_arg: NAME ":" abi_class  */
#line 450 "src/parser/rules.y"
                         {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].abi_class));
        (yyval.function_declaration_arg)->name = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].abi_class);
    }
#line 2057 "src/parser/rules.tab.c"
    break;

  case 33: /* function_declaration_arg: NAME ":" memory_length alignment  */
#line 457 "src/parser/rules.y"
                                       {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->align = (yyvsp[0].name);
    }
#line 2070 "src/parser/rules.tab.c"
    break;

  case 34: /* function_declaration_arg: NAME ":" memory_length abi_class  */
#line 465 "src/parser/rules.y"
                                       {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].abi_class));
        (yyval.function_declaration_arg)->name = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].abi_class);
    }
#line 2083 "src/parser/rules.tab.c"
    break;

  case 35: /* function_declaration_arg: NAME ":" alignment abi_class  */
#line 473 "src/parser/rules.y"
                                   {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].abi_class));
        (yyval.function_declaration_arg)->name = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->align = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].abi_class);
    }
#line 2096 "src/parser/rules.tab.c"
    break;

  case 36: /* function_declaration_arg: NAME ":" memory_length alignment abi_class  */
#line 481 "src/parser/rules.y"
                                                 {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].abi_class));
        (yyval.function_declaration_arg)->name = (yyvsp[-4].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->align = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].abi_class);
    }
#line 2110 "src/parser/rules.tab.c"
    break;

  case 37: /* function_declaration_args: function_declaration_args "," function_declaration_arg  */
#line 493 "src/parser/rules.y"
                                                           {
        (yyval.function_declaration_args) = ALLOC(struct function_declaration_args_node_t);
        TFRAG_COMBINE((yyval.function_declaration_args), (yyvsp[-2].function_declaration_args), (yyvsp[-1].name), (yyvsp[0].function_declaration_arg));
        (yyval.function_declaration_args)->rest = (yyvsp[-2].function_declaration_args);
        (yyval.function_declaration_args)->comma = (yyvsp[-1].name);
        (yyval.function_declaration_args)->arg = (yyvsp[0].function_declaration_arg);
    }
#line 2122 "src/parser/rules.tab.c"
    break;

  case 38: /* function_declaration_args: function_declaration_arg  */
#line 500 "src/parser/rules.y"
                               {
        (yyval.function_declaration_args) = ALLOC(struct function_declaration_args_node_t);
        TFRAG_COMBINE((yyval.function_declaration_args), (yyvsp[0].function_declaration_arg));
        (yyval.function_declaration_args)->arg = (yyvsp[0].function_declaration_arg);
    }
#line 2132 "src/parser/rules.tab.c"
    break;

  case 39: /* function_declaration_args: %empty  */
#line 505 "src/parser/rules.y"
      {
        (yyval.function_declaration_args) = ALLOC(struct function_declaration_args_node_t);
    }
#line 2140 "src/parser/rules.tab.c"
    break;

  case 40: /* function_declaration: NAME ":" FN "(" function_declaration_args ")" body  */
#line 511 "src/parser/rules.y"
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
#line 2156 "src/parser/rules.tab.c"
    break;

  case 41: /* function_declaration: NAME ":" FN "(" function_declaration_args ")" ARROW memory_length body  */
#line 522 "src/parser/rules.y"
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
#line 2174 "src/parser/rules.tab.c"
    break;

  case 42: /* function_declaration: NAME ":" FN "(" function_declaration_args ")" ARROW abi_class body  */
#line 535 "src/parser/rules.y"
                                                                         {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-8].name), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].function_declaration_args), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].abi_class), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-8].name);
        (yyval.function_declaration)->colon = (yyvsp[-7].name);
        (yyval.function_declaration)->fn = (yyvsp[-6].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-5].name);
        (yyval.function_declaration)->args = (yyvsp[-4].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-3].name);
        (yyval.function_declaration)->arrow = (yyvsp[-2].name);
        (yyval.function_declaration)->abi_class = (yyvsp[-1].abi_class);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2192 "src/parser/rules.tab.c"
    break;

  case 43: /* function_declaration: NAME ":" FN "(" function_declaration_args ")" ARROW memory_length abi_class body  */
#line 548 "src/parser/rules.y"
                                                                                       {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-9].name), (yyvsp[-8].name), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].function_declaration_args), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].abi_class), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-9].name);
        (yyval.function_declaration)->colon = (yyvsp[-8].name);
        (yyval.function_declaration)->fn = (yyvsp[-7].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-6].name);
        (yyval.function_declaration)->args = (yyvsp[-5].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-4].name);
        (yyval.function_declaration)->arrow = (yyvsp[-3].name);
        (yyval.function_declaration)->mem_len = (yyvsp[-2].name);
        (yyval.function_declaration)->abi_class = (yyvsp[-1].abi_class);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2211 "src/parser/rules.tab.c"
    break;

  case 44: /* function_declaration: NAME ":" visibility FN "(" function_declaration_args ")" body  */
#line 562 "src/parser/rules.y"
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
#line 2228 "src/parser/rules.tab.c"
    break;

  case 45: /* function_declaration: NAME ":" visibility FN "(" function_declaration_args ")" ARROW memory_length body  */
#line 574 "src/parser/rules.y"
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
#line 2247 "src/parser/rules.tab.c"
    break;

  case 46: /* function_declaration: NAME ":" visibility FN "(" function_declaration_args ")" ARROW abi_class body  */
#line 588 "src/parser/rules.y"
                                                                                    {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-9].name), (yyvsp[-8].name), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].function_declaration_args), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].abi_class), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-9].name);
        (yyval.function_declaration)->colon = (yyvsp[-8].name);
        (yyval.function_declaration)->vis = (yyvsp[-7].name);
        (yyval.function_declaration)->fn = (yyvsp[-6].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-5].name);
        (yyval.function_declaration)->args = (yyvsp[-4].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-3].name);
        (yyval.function_declaration)->arrow = (yyvsp[-2].name);
        (yyval.function_declaration)->abi_class = (yyvsp[-1].abi_class);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2266 "src/parser/rules.tab.c"
    break;

  case 47: /* function_declaration: NAME ":" visibility FN "(" function_declaration_args ")" ARROW memory_length abi_class body  */
#line 603 "src/parser/rules.y"
               {
        (yyval.function_declaration) = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE((yyval.function_declaration), (yyvsp[-10].name), (yyvsp[-9].name), (yyvsp[-8].name), (yyvsp[-7].name), (yyvsp[-6].name), (yyvsp[-5].function_declaration_args), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].abi_class), (yyvsp[0].body));
        (yyval.function_declaration)->name = (yyvsp[-10].name);
        (yyval.function_declaration)->colon = (yyvsp[-9].name);
        (yyval.function_declaration)->vis = (yyvsp[-8].name);
        (yyval.function_declaration)->fn = (yyvsp[-7].name);
        (yyval.function_declaration)->open_brace = (yyvsp[-6].name);
        (yyval.function_declaration)->args = (yyvsp[-5].function_declaration_args);
        (yyval.function_declaration)->closed_brace = (yyvsp[-4].name);
        (yyval.function_declaration)->arrow = (yyvsp[-3].name);
        (yyval.function_declaration)->mem_len = (yyvsp[-2].name);
        (yyval.function_declaration)->abi_class = (yyvsp[-1].abi_class);
        (yyval.function_declaration)->body = (yyvsp[0].body);
    }
#line 2286 "src/parser/rules.tab.c"
    break;

  case 48: /* body_list: body_list statement  */
#line 621 "src/parser/rules.y"
                        {
        (yyval.body_list) = ALLOC(struct body_list_node_t);
        TFRAG_COMBINE((yyval.body_list), (yyvsp[-1].body_list), (yyvsp[0].statement));
        (yyval.body_list)->rest = (yyvsp[-1].body_list);
        (yyval.body_list)->s = (yyvsp[0].statement);
    }
#line 2297 "src/parser/rules.tab.c"
    break;

  case 49: /* body_list: %empty  */
#line 627 "src/parser/rules.y"
      {
        (yyval.body_list) = ALLOC(struct body_list_node_t);
    }
#line 2305 "src/parser/rules.tab.c"
    break;

  case 50: /* body: "{" body_list "}"  */
#line 633 "src/parser/rules.y"
                      {
        (yyval.body) = ALLOC(struct body_node_t);
        TFRAG_COMBINE((yyval.body), (yyvsp[-2].name), (yyvsp[-1].body_list), (yyvsp[0].name));
        (yyval.body)->open_brace = (yyvsp[-2].name);
        (yyval.body)->list = (yyvsp[-1].body_list);
        (yyval.body)->closed_brace = (yyvsp[0].name);
    }
#line 2317 "src/parser/rules.tab.c"
    break;

  case 51: /* statement: variable_declaration  */
#line 643 "src/parser/rules.y"
                         {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].variable_declaration));
        (yyval.statement)->vdecl = (yyvsp[0].variable_declaration);
    }
#line 2327 "src/parser/rules.tab.c"
    break;

  case 52: /* statement: register_alias  */
#line 648 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].register_alias));
        (yyval.statement)->alias = (yyvsp[0].register_alias);
    }
#line 2337 "src/parser/rules.tab.c"
    break;

  case 53: /* statement: extern_declaration  */
#line 653 "src/parser/rules.y"
                         {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].extern_declaration));
        (yyval.statement)->ext_decl = (yyvsp[0].extern_declaration);
    }
#line 2347 "src/parser/rules.tab.c"
    break;

  case 54: /* statement: if_statement  */
#line 658 "src/parser/rules.y"
                   {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].if_statement));
        (yyval.statement)->if_s = (yyvsp[0].if_statement);
    }
#line 2357 "src/parser/rules.tab.c"
    break;

  case 55: /* statement: label_declaration  */
#line 663 "src/parser/rules.y"
                        {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].label_declaration));
        (yyval.statement)->label = (yyvsp[0].label_declaration);
    }
#line 2367 "src/parser/rules.tab.c"
    break;

  case 56: /* statement: goto_statement  */
#line 668 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].goto_statement));
        (yyval.statement)->goto_s = (yyvsp[0].goto_statement);
    }
#line 2377 "src/parser/rules.tab.c"
    break;

  case 57: /* statement: loop_statement  */
#line 673 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].loop_statement));
        (yyval.statement)->loop_s = (yyvsp[0].loop_statement);
    }
#line 2387 "src/parser/rules.tab.c"
    break;

  case 58: /* statement: break_statement  */
#line 678 "src/parser/rules.y"
                      {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].break_statement));
        (yyval.statement)->break_s = (yyvsp[0].break_statement);
    }
#line 2397 "src/parser/rules.tab.c"
    break;

  case 59: /* statement: ret_statement  */
#line 683 "src/parser/rules.y"
                    {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].ret_statement));
        (yyval.statement)->ret_s = (yyvsp[0].ret_statement);
    }
#line 2407 "src/parser/rules.tab.c"
    break;

  case 60: /* statement: avoid_block  */
#line 688 "src/parser/rules.y"
                  {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].avoid_block));
        (yyval.statement)->avoid = (yyvsp[0].avoid_block);
    }
#line 2417 "src/parser/rules.tab.c"
    break;

  case 61: /* statement: expression ";"  */
#line 693 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[-1].expression), (yyvsp[0].name));
        (yyval.statement)->expr = (yyvsp[-1].expression);
        (yyval.statement)->semicolon = (yyvsp[0].name);
    }
#line 2428 "src/parser/rules.tab.c"
    break;

  case 62: /* statement: NASM_BLOCK  */
#line 699 "src/parser/rules.y"
                 {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].name));
        (yyval.statement)->nasm = (yyvsp[0].name);
    }
#line 2438 "src/parser/rules.tab.c"
    break;

  case 63: /* variable_declaration: NAME ":" memory_length  */
#line 707 "src/parser/rules.y"
                           {
        (yyval.variable_declaration) = ALLOC(struct variable_declaration_node_t);
        TFRAG_COMBINE((yyval.variable_declaration), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.variable_declaration)->name = (yyvsp[-2].name);
        (yyval.variable_declaration)->colon = (yyvsp[-1].name);
        (yyval.variable_declaration)->mem_len = (yyvsp[0].name);
    }
#line 2450 "src/parser/rules.tab.c"
    break;

  case 64: /* variable_declaration: NAME ":" memory_length alignment  */
#line 714 "src/parser/rules.y"
                                       {
        (yyval.variable_declaration) = ALLOC(struct variable_declaration_node_t);
        TFRAG_COMBINE((yyval.variable_declaration), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.variable_declaration)->name = (yyvsp[-3].name);
        (yyval.variable_declaration)->colon = (yyvsp[-2].name);
        (yyval.variable_declaration)->mem_len = (yyvsp[-1].name);
        (yyval.variable_declaration)->align = (yyvsp[0].name);
    }
#line 2463 "src/parser/rules.tab.c"
    break;

  case 65: /* register_alias: NAME ":" ALIAS REG  */
#line 725 "src/parser/rules.y"
                       {
        (yyval.register_alias) = ALLOC(struct register_alias_node_t);
        TFRAG_COMBINE((yyval.register_alias), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.register_alias)->name = (yyvsp[-3].name);
        (yyval.register_alias)->colon = (yyvsp[-2].name);
        (yyval.register_alias)->alias = (yyvsp[-1].name);
        (yyval.register_alias)->reg = (yyvsp[0].name);
    }
#line 2476 "src/parser/rules.tab.c"
    break;

  case 66: /* register_alias: NAME ":" ALIAS GP_REGISTER  */
#line 733 "src/parser/rules.y"
                                 {
        (yyval.register_alias) = ALLOC(struct register_alias_node_t);
        TFRAG_COMBINE((yyval.register_alias), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.register_alias)->name = (yyvsp[-3].name);
        (yyval.register_alias)->colon = (yyvsp[-2].name);
        (yyval.register_alias)->alias = (yyvsp[-1].name);
        (yyval.register_alias)->reg = (yyvsp[0].name);
    }
#line 2489 "src/parser/rules.tab.c"
    break;

  case 67: /* if_statement: IF expression body  */
#line 744 "src/parser/rules.y"
                       {
        (yyval.if_statement) = ALLOC(struct if_statement_node_t);
        TFRAG_COMBINE((yyval.if_statement), (yyvsp[-2].name), (yyvsp[-1].expression), (yyvsp[0].body));
        (yyval.if_statement)->kw = (yyvsp[-2].name);
        (yyval.if_statement)->expr = (yyvsp[-1].expression);
        (yyval.if_statement)->body = (yyvsp[0].body);
    }
#line 2501 "src/parser/rules.tab.c"
    break;

  case 68: /* if_statement: IF expression body ELSE body  */
#line 751 "src/parser/rules.y"
                                   {
        (yyval.if_statement) = ALLOC(struct if_statement_node_t);
        TFRAG_COMBINE((yyval.if_statement), (yyvsp[-4].name), (yyvsp[-3].expression), (yyvsp[-2].body), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.if_statement)->kw = (yyvsp[-4].name);
        (yyval.if_statement)->expr = (yyvsp[-3].expression);
        (yyval.if_statement)->body = (yyvsp[-2].body);
        (yyval.if_statement)->else_kw = (yyvsp[-1].name);
        (yyval.if_statement)->else_body = (yyvsp[0].body);
    }
#line 2515 "src/parser/rules.tab.c"
    break;

  case 69: /* label_declaration: NAME ":"  */
#line 763 "src/parser/rules.y"
             {
        (yyval.label_declaration) = ALLOC(struct label_declaration_node_t);
        TFRAG_COMBINE((yyval.label_declaration), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.label_declaration)->name = (yyvsp[-1].name);
        (yyval.label_declaration)->colon = (yyvsp[0].name);
    }
#line 2526 "src/parser/rules.tab.c"
    break;

  case 70: /* goto_statement: GOTO NAME ";"  */
#line 772 "src/parser/rules.y"
                  {
        (yyval.goto_statement) = ALLOC(struct goto_statement_node_t);
        TFRAG_COMBINE((yyval.goto_statement), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.goto_statement)->kw = (yyvsp[-2].name);
        (yyval.goto_statement)->name = (yyvsp[-1].name);
        (yyval.goto_statement)->semicolon = (yyvsp[0].name);
    }
#line 2538 "src/parser/rules.tab.c"
    break;

  case 71: /* loop_statement: LOOP body  */
#line 782 "src/parser/rules.y"
              {
        (yyval.loop_statement) = ALLOC(struct loop_statement_node_t);
        TFRAG_COMBINE((yyval.loop_statement), (yyvsp[-1].name), (yyvsp[0].body));
        (yyval.loop_statement)->kw = (yyvsp[-1].name);
        (yyval.loop_statement)->body = (yyvsp[0].body);
    }
#line 2549 "src/parser/rules.tab.c"
    break;

  case 72: /* break_statement: BREAK ";"  */
#line 791 "src/parser/rules.y"
              {
        (yyval.break_statement) = ALLOC(struct break_statement_node_t);
        TFRAG_COMBINE((yyval.break_statement), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.break_statement)->kw = (yyvsp[-1].name);
        (yyval.break_statement)->semicolon = (yyvsp[0].name);
    }
#line 2560 "src/parser/rules.tab.c"
    break;

  case 73: /* break_statement: CONTINUE ";"  */
#line 797 "src/parser/rules.y"
                   {
        (yyval.break_statement) = ALLOC(struct break_statement_node_t);
        TFRAG_COMBINE((yyval.break_statement), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.break_statement)->kw = (yyvsp[-1].name);
        (yyval.break_statement)->semicolon = (yyvsp[0].name);
    }
#line 2571 "src/parser/rules.tab.c"
    break;

  case 74: /* ret_statement: RET expression ";"  */
#line 806 "src/parser/rules.y"
                       {
        (yyval.ret_statement) = ALLOC(struct ret_statement_node_t);
        TFRAG_COMBINE((yyval.ret_statement), (yyvsp[-2].name), (yyvsp[-1].expression), (yyvsp[0].name));
        (yyval.ret_statement)->kw = (yyvsp[-2].name);
        (yyval.ret_statement)->expr = (yyvsp[-1].expression);
        (yyval.ret_statement)->semicolon = (yyvsp[0].name);
    }
#line 2583 "src/parser/rules.tab.c"
    break;

  case 75: /* avoid_block_regs: avoid_block_regs "," REGISTER  */
#line 816 "src/parser/rules.y"
                                  {
        (yyval.avoid_block_regs) = ALLOC(struct avoid_block_regs_node_t);
        TFRAG_COMBINE((yyval.avoid_block_regs), (yyvsp[-2].avoid_block_regs), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.avoid_block_regs)->rest = (yyvsp[-2].avoid_block_regs);
        (yyval.avoid_block_regs)->comma = (yyvsp[-1].name);
        (yyval.avoid_block_regs)->reg = (yyvsp[0].name);
    }
#line 2595 "src/parser/rules.tab.c"
    break;

  case 76: /* avoid_block_regs: avoid_block_regs "," GP_REGISTER  */
#line 823 "src/parser/rules.y"
                                       {
        (yyval.avoid_block_regs) = ALLOC(struct avoid_block_regs_node_t);
        TFRAG_COMBINE((yyval.avoid_block_regs), (yyvsp[-2].avoid_block_regs), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.avoid_block_regs)->rest = (yyvsp[-2].avoid_block_regs);
        (yyval.avoid_block_regs)->comma = (yyvsp[-1].name);
        (yyval.avoid_block_regs)->reg = (yyvsp[0].name);
    }
#line 2607 "src/parser/rules.tab.c"
    break;

  case 77: /* avoid_block_regs: REGISTER  */
#line 830 "src/parser/rules.y"
               {
        (yyval.avoid_block_regs) = ALLOC(struct avoid_block_regs_node_t);
        TFRAG_COMBINE((yyval.avoid_block_regs), (yyvsp[0].name));
        (yyval.avoid_block_regs)->reg = (yyvsp[0].name);
    }
#line 2617 "src/parser/rules.tab.c"
    break;

  case 78: /* avoid_block_regs: GP_REGISTER  */
#line 835 "src/parser/rules.y"
                  {
        (yyval.avoid_block_regs) = ALLOC(struct avoid_block_regs_node_t);
        TFRAG_COMBINE((yyval.avoid_block_regs), (yyvsp[0].name));
        (yyval.avoid_block_regs)->reg = (yyvsp[0].name);
    }
#line 2627 "src/parser/rules.tab.c"
    break;

  case 79: /* avoid_block: AVOID avoid_block_regs body  */
#line 843 "src/parser/rules.y"
                                {
        (yyval.avoid_block) = ALLOC(struct avoid_block_node_t);
        TFRAG_COMBINE((yyval.avoid_block), (yyvsp[-2].name), (yyvsp[-1].avoid_block_regs), (yyvsp[0].body));
        (yyval.avoid_block)->kw = (yyvsp[-2].name);
        (yyval.avoid_block)->regs = (yyvsp[-1].avoid_block_regs);
        (yyval.avoid_block)->body = (yyvsp[0].body);
    }
#line 2639 "src/parser/rules.tab.c"
    break;

  case 80: /* expression: logical_or ASSIGN expression  */
#line 853 "src/parser/rules.y"
                                 {
        (yyval.expression) = ALLOC(struct expression_node_t);
        TFRAG_COMBINE((yyval.expression), (yyvsp[-2].logical_or), (yyvsp[-1].name), (yyvsp[0].expression));
        (yyval.expression)->arg1 = (yyvsp[-2].logical_or);
        (yyval.expression)->op = (yyvsp[-1].name);
        (yyval.expression)->arg2 = (yyvsp[0].expression);
    }
#line 2651 "src/parser/rules.tab.c"
    break;

  case 81: /* expression: logical_or  */
#line 860 "src/parser/rules.y"
                 {
        (yyval.expression) = ALLOC(struct expression_node_t);
        TFRAG_COMBINE((yyval.expression), (yyvsp[0].logical_or));
        (yyval.expression)->other = (yyvsp[0].logical_or);
    }
#line 2661 "src/parser/rules.tab.c"
    break;

  case 82: /* logical_or: logical_or LOGICAL_OR logical_and  */
#line 868 "src/parser/rules.y"
                                      {
        (yyval.logical_or) = ALLOC(struct logical_or_node_t);
        TFRAG_COMBINE((yyval.logical_or), (yyvsp[-2].logical_or), (yyvsp[-1].name), (yyvsp[0].logical_and));
        (yyval.logical_or)->arg1 = (yyvsp[-2].logical_or);
        (yyval.logical_or)->op = (yyvsp[-1].name);
        (yyval.logical_or)->arg2 = (yyvsp[0].logical_and);
    }
#line 2673 "src/parser/rules.tab.c"
    break;

  case 83: /* logical_or: logical_and  */
#line 875 "src/parser/rules.y"
                  {
        (yyval.logical_or) = ALLOC(struct logical_or_node_t);
        TFRAG_COMBINE((yyval.logical_or), (yyvsp[0].logical_and));
        (yyval.logical_or)->other = (yyvsp[0].logical_and);
    }
#line 2683 "src/parser/rules.tab.c"
    break;

  case 84: /* logical_and: logical_and LOGICAL_AND bitwise_or  */
#line 883 "src/parser/rules.y"
                                       {
        (yyval.logical_and) = ALLOC(struct logical_and_node_t);
        TFRAG_COMBINE((yyval.logical_and), (yyvsp[-2].logical_and), (yyvsp[-1].name), (yyvsp[0].bitwise_or));
        (yyval.logical_and)->arg1 = (yyvsp[-2].logical_and);
        (yyval.logical_and)->op = (yyvsp[-1].name);
        (yyval.logical_and)->arg2 = (yyvsp[0].bitwise_or);
    }
#line 2695 "src/parser/rules.tab.c"
    break;

  case 85: /* logical_and: bitwise_or  */
#line 890 "src/parser/rules.y"
                 {
        (yyval.logical_and) = ALLOC(struct logical_and_node_t);
        TFRAG_COMBINE((yyval.logical_and), (yyvsp[0].bitwise_or));
        (yyval.logical_and)->other = (yyvsp[0].bitwise_or);
    }
#line 2705 "src/parser/rules.tab.c"
    break;

  case 86: /* bitwise_or: bitwise_or BITWISE_OR bitwise_xor  */
#line 898 "src/parser/rules.y"
                                      {
        (yyval.bitwise_or) = ALLOC(struct bitwise_or_node_t);
        TFRAG_COMBINE((yyval.bitwise_or), (yyvsp[-2].bitwise_or), (yyvsp[-1].name), (yyvsp[0].bitwise_xor));
        (yyval.bitwise_or)->arg1 = (yyvsp[-2].bitwise_or);
        (yyval.bitwise_or)->op = (yyvsp[-1].name);
        (yyval.bitwise_or)->arg2 = (yyvsp[0].bitwise_xor);
    }
#line 2717 "src/parser/rules.tab.c"
    break;

  case 87: /* bitwise_or: bitwise_xor  */
#line 905 "src/parser/rules.y"
                  {
        (yyval.bitwise_or) = ALLOC(struct bitwise_or_node_t);
        TFRAG_COMBINE((yyval.bitwise_or), (yyvsp[0].bitwise_xor));
        (yyval.bitwise_or)->other = (yyvsp[0].bitwise_xor);
    }
#line 2727 "src/parser/rules.tab.c"
    break;

  case 88: /* bitwise_xor: bitwise_xor BITWISE_XOR bitwise_and  */
#line 913 "src/parser/rules.y"
                                        {
        (yyval.bitwise_xor) = ALLOC(struct bitwise_xor_node_t);
        TFRAG_COMBINE((yyval.bitwise_xor), (yyvsp[-2].bitwise_xor), (yyvsp[-1].name), (yyvsp[0].bitwise_and));
        (yyval.bitwise_xor)->arg1 = (yyvsp[-2].bitwise_xor);
        (yyval.bitwise_xor)->op = (yyvsp[-1].name);
        (yyval.bitwise_xor)->arg2 = (yyvsp[0].bitwise_and);
    }
#line 2739 "src/parser/rules.tab.c"
    break;

  case 89: /* bitwise_xor: bitwise_and  */
#line 920 "src/parser/rules.y"
                  {
        (yyval.bitwise_xor) = ALLOC(struct bitwise_xor_node_t);
        TFRAG_COMBINE((yyval.bitwise_xor), (yyvsp[0].bitwise_and));
        (yyval.bitwise_xor)->other = (yyvsp[0].bitwise_and);
    }
#line 2749 "src/parser/rules.tab.c"
    break;

  case 90: /* bitwise_and: bitwise_and BITWISE_AND equality  */
#line 928 "src/parser/rules.y"
                                     {
        (yyval.bitwise_and) = ALLOC(struct bitwise_and_node_t);
        TFRAG_COMBINE((yyval.bitwise_and), (yyvsp[-2].bitwise_and), (yyvsp[-1].name), (yyvsp[0].equality));
        (yyval.bitwise_and)->arg1 = (yyvsp[-2].bitwise_and);
        (yyval.bitwise_and)->op = (yyvsp[-1].name);
        (yyval.bitwise_and)->arg2 = (yyvsp[0].equality);
    }
#line 2761 "src/parser/rules.tab.c"
    break;

  case 91: /* bitwise_and: equality  */
#line 935 "src/parser/rules.y"
               {
        (yyval.bitwise_and) = ALLOC(struct bitwise_and_node_t);
        TFRAG_COMBINE((yyval.bitwise_and), (yyvsp[0].equality));
        (yyval.bitwise_and)->other = (yyvsp[0].equality);
    }
#line 2771 "src/parser/rules.tab.c"
    break;

  case 92: /* equality: equality EQUALS relational  */
#line 943 "src/parser/rules.y"
                               {
        (yyval.equality) = ALLOC(struct equality_node_t);
        TFRAG_COMBINE((yyval.equality), (yyvsp[-2].equality), (yyvsp[-1].name), (yyvsp[0].relational));
        (yyval.equality)->arg1 = (yyvsp[-2].equality);
        (yyval.equality)->op = (yyvsp[-1].name);
        (yyval.equality)->arg2 = (yyvsp[0].relational);
    }
#line 2783 "src/parser/rules.tab.c"
    break;

  case 93: /* equality: equality NOT_EQUALS relational  */
#line 950 "src/parser/rules.y"
                                     {
        (yyval.equality) = ALLOC(struct equality_node_t);
        TFRAG_COMBINE((yyval.equality), (yyvsp[-2].equality), (yyvsp[-1].name), (yyvsp[0].relational));
        (yyval.equality)->arg1 = (yyvsp[-2].equality);
        (yyval.equality)->op = (yyvsp[-1].name);
        (yyval.equality)->arg2 = (yyvsp[0].relational);
    }
#line 2795 "src/parser/rules.tab.c"
    break;

  case 94: /* equality: relational  */
#line 957 "src/parser/rules.y"
                 {
        (yyval.equality) = ALLOC(struct equality_node_t);
        TFRAG_COMBINE((yyval.equality), (yyvsp[0].relational));
        (yyval.equality)->other = (yyvsp[0].relational);
    }
#line 2805 "src/parser/rules.tab.c"
    break;

  case 95: /* relational: relational LESS_THAN additive  */
#line 965 "src/parser/rules.y"
                                  {
        (yyval.relational) = ALLOC(struct relational_node_t);
        TFRAG_COMBINE((yyval.relational), (yyvsp[-2].relational), (yyvsp[-1].name), (yyvsp[0].additive));
        (yyval.relational)->arg1 = (yyvsp[-2].relational);
        (yyval.relational)->op = (yyvsp[-1].name);
        (yyval.relational)->arg2 = (yyvsp[0].additive);
    }
#line 2817 "src/parser/rules.tab.c"
    break;

  case 96: /* relational: relational GREATER_THAN additive  */
#line 972 "src/parser/rules.y"
                                       {
        (yyval.relational) = ALLOC(struct relational_node_t);
        TFRAG_COMBINE((yyval.relational), (yyvsp[-2].relational), (yyvsp[-1].name), (yyvsp[0].additive));
        (yyval.relational)->arg1 = (yyvsp[-2].relational);
        (yyval.relational)->op = (yyvsp[-1].name);
        (yyval.relational)->arg2 = (yyvsp[0].additive);
    }
#line 2829 "src/parser/rules.tab.c"
    break;

  case 97: /* relational: relational LESS_EQUAL additive  */
#line 979 "src/parser/rules.y"
                                     {
        (yyval.relational) = ALLOC(struct relational_node_t);
        TFRAG_COMBINE((yyval.relational), (yyvsp[-2].relational), (yyvsp[-1].name), (yyvsp[0].additive));
        (yyval.relational)->arg1 = (yyvsp[-2].relational);
        (yyval.relational)->op = (yyvsp[-1].name);
        (yyval.relational)->arg2 = (yyvsp[0].additive);
    }
#line 2841 "src/parser/rules.tab.c"
    break;

  case 98: /* relational: relational GREATER_EQUAL additive  */
#line 986 "src/parser/rules.y"
                                        {
        (yyval.relational) = ALLOC(struct relational_node_t);
        TFRAG_COMBINE((yyval.relational), (yyvsp[-2].relational), (yyvsp[-1].name), (yyvsp[0].additive));
        (yyval.relational)->arg1 = (yyvsp[-2].relational);
        (yyval.relational)->op = (yyvsp[-1].name);
        (yyval.relational)->arg2 = (yyvsp[0].additive);
    }
#line 2853 "src/parser/rules.tab.c"
    break;

  case 99: /* relational: additive  */
#line 993 "src/parser/rules.y"
               {
        (yyval.relational) = ALLOC(struct relational_node_t);
        TFRAG_COMBINE((yyval.relational), (yyvsp[0].additive));
        (yyval.relational)->other = (yyvsp[0].additive);
    }
#line 2863 "src/parser/rules.tab.c"
    break;

  case 100: /* additive: additive PLUS multiplicative  */
#line 1001 "src/parser/rules.y"
                                 {
        (yyval.additive) = ALLOC(struct additive_node_t);
        TFRAG_COMBINE((yyval.additive), (yyvsp[-2].additive), (yyvsp[-1].name), (yyvsp[0].multiplicative));
        (yyval.additive)->arg1 = (yyvsp[-2].additive);
        (yyval.additive)->op = (yyvsp[-1].name);
        (yyval.additive)->arg2 = (yyvsp[0].multiplicative);
    }
#line 2875 "src/parser/rules.tab.c"
    break;

  case 101: /* additive: additive MINUS multiplicative  */
#line 1008 "src/parser/rules.y"
                                    {
        (yyval.additive) = ALLOC(struct additive_node_t);
        TFRAG_COMBINE((yyval.additive), (yyvsp[-2].additive), (yyvsp[-1].name), (yyvsp[0].multiplicative));
        (yyval.additive)->arg1 = (yyvsp[-2].additive);
        (yyval.additive)->op = (yyvsp[-1].name);
        (yyval.additive)->arg2 = (yyvsp[0].multiplicative);
    }
#line 2887 "src/parser/rules.tab.c"
    break;

  case 102: /* additive: multiplicative  */
#line 1015 "src/parser/rules.y"
                     {
        (yyval.additive) = ALLOC(struct additive_node_t);
        TFRAG_COMBINE((yyval.additive), (yyvsp[0].multiplicative));
        (yyval.additive)->other = (yyvsp[0].multiplicative);
    }
#line 2897 "src/parser/rules.tab.c"
    break;

  case 103: /* multiplicative: multiplicative MULTIPLY tetriary  */
#line 1023 "src/parser/rules.y"
                                     {
        (yyval.multiplicative) = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE((yyval.multiplicative), (yyvsp[-2].multiplicative), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.multiplicative)->arg1 = (yyvsp[-2].multiplicative);
        (yyval.multiplicative)->op = (yyvsp[-1].name);
        (yyval.multiplicative)->arg2 = (yyvsp[0].tetriary);
    }
#line 2909 "src/parser/rules.tab.c"
    break;

  case 104: /* multiplicative: multiplicative DIVIDE tetriary  */
#line 1030 "src/parser/rules.y"
                                     {
        (yyval.multiplicative) = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE((yyval.multiplicative), (yyvsp[-2].multiplicative), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.multiplicative)->arg1 = (yyvsp[-2].multiplicative);
        (yyval.multiplicative)->op = (yyvsp[-1].name);
        (yyval.multiplicative)->arg2 = (yyvsp[0].tetriary);
    }
#line 2921 "src/parser/rules.tab.c"
    break;

  case 105: /* multiplicative: multiplicative REMAINDER tetriary  */
#line 1037 "src/parser/rules.y"
                                        {
        (yyval.multiplicative) = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE((yyval.multiplicative), (yyvsp[-2].multiplicative), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.multiplicative)->arg1 = (yyvsp[-2].multiplicative);
        (yyval.multiplicative)->op = (yyvsp[-1].name);
        (yyval.multiplicative)->arg2 = (yyvsp[0].tetriary);
    }
#line 2933 "src/parser/rules.tab.c"
    break;

  case 106: /* multiplicative: tetriary  */
#line 1044 "src/parser/rules.y"
               {
        (yyval.multiplicative) = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE((yyval.multiplicative), (yyvsp[0].tetriary));
        (yyval.multiplicative)->other = (yyvsp[0].tetriary);
    }
#line 2943 "src/parser/rules.tab.c"
    break;

  case 107: /* prefix_op: INCREMENT tetriary  */
#line 1052 "src/parser/rules.y"
                       {
        (yyval.prefix_op) = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE((yyval.prefix_op), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.prefix_op)->op = (yyvsp[-1].name);
        (yyval.prefix_op)->arg = (yyvsp[0].tetriary);
    }
#line 2954 "src/parser/rules.tab.c"
    break;

  case 108: /* prefix_op: DECREMENT tetriary  */
#line 1058 "src/parser/rules.y"
                         {
        (yyval.prefix_op) = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE((yyval.prefix_op), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.prefix_op)->op = (yyvsp[-1].name);
        (yyval.prefix_op)->arg = (yyvsp[0].tetriary);
    }
#line 2965 "src/parser/rules.tab.c"
    break;

  case 109: /* prefix_op: LOGICAL_NOT tetriary  */
#line 1064 "src/parser/rules.y"
                           {
        (yyval.prefix_op) = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE((yyval.prefix_op), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.prefix_op)->op = (yyvsp[-1].name);
        (yyval.prefix_op)->arg = (yyvsp[0].tetriary);
    }
#line 2976 "src/parser/rules.tab.c"
    break;

  case 110: /* prefix_op: BITWISE_NOT tetriary  */
#line 1070 "src/parser/rules.y"
                           {
        (yyval.prefix_op) = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE((yyval.prefix_op), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.prefix_op)->op = (yyvsp[-1].name);
        (yyval.prefix_op)->arg = (yyvsp[0].tetriary);
    }
#line 2987 "src/parser/rules.tab.c"
    break;

  case 111: /* cast_op: tetriary CAST  */
#line 1079 "src/parser/rules.y"
                  {
        (yyval.cast_op) = ALLOC(struct cast_op_node_t);
        TFRAG_COMBINE((yyval.cast_op), (yyvsp[-1].tetriary), (yyvsp[0].name));
        (yyval.cast_op)->arg = (yyvsp[-1].tetriary);
        (yyval.cast_op)->op = (yyvsp[0].name);
    }
#line 2998 "src/parser/rules.tab.c"
    break;

  case 112: /* address_op: "[" expression "]" tetriary  */
#line 1088 "src/parser/rules.y"
                                {
        (yyval.address_op) = ALLOC(struct address_op_node_t);
        TFRAG_COMBINE((yyval.address_op), (yyvsp[-3].name), (yyvsp[-2].expression), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.address_op)->open_brace = (yyvsp[-3].name);
        (yyval.address_op)->offset = (yyvsp[-2].expression);
        (yyval.address_op)->closed_brace = (yyvsp[-1].name);
        (yyval.address_op)->arg = (yyvsp[0].tetriary);
    }
#line 3011 "src/parser/rules.tab.c"
    break;

  case 113: /* address_op: "[" "]" tetriary  */
#line 1096 "src/parser/rules.y"
                       {
        (yyval.address_op) = ALLOC(struct address_op_node_t);
        TFRAG_COMBINE((yyval.address_op), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].tetriary));
        (yyval.address_op)->open_brace = (yyvsp[-2].name);
        (yyval.address_op)->closed_brace = (yyvsp[-1].name);
        (yyval.address_op)->arg = (yyvsp[0].tetriary);
    }
#line 3023 "src/parser/rules.tab.c"
    break;

  case 114: /* sizeof_op: SIZEOF NAME  */
#line 1106 "src/parser/rules.y"
                {
        (yyval.sizeof_op) = ALLOC(struct sizeof_op_node_t);
        TFRAG_COMBINE((yyval.sizeof_op), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.sizeof_op)->kw = (yyvsp[-1].name);
        (yyval.sizeof_op)->name = (yyvsp[0].name);
    }
#line 3034 "src/parser/rules.tab.c"
    break;

  case 115: /* tetriary: prefix_op  */
#line 1115 "src/parser/rules.y"
              {
        (yyval.tetriary) = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE((yyval.tetriary), (yyvsp[0].prefix_op));
        (yyval.tetriary)->prefix = (yyvsp[0].prefix_op);
    }
#line 3044 "src/parser/rules.tab.c"
    break;

  case 116: /* tetriary: cast_op  */
#line 1120 "src/parser/rules.y"
              {
        (yyval.tetriary) = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE((yyval.tetriary), (yyvsp[0].cast_op));
        (yyval.tetriary)->cast = (yyvsp[0].cast_op);
    }
#line 3054 "src/parser/rules.tab.c"
    break;

  case 117: /* tetriary: address_op  */
#line 1125 "src/parser/rules.y"
                 {
        (yyval.tetriary) = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE((yyval.tetriary), (yyvsp[0].address_op));
        (yyval.tetriary)->address = (yyvsp[0].address_op);
    }
#line 3064 "src/parser/rules.tab.c"
    break;

  case 118: /* tetriary: sizeof_op  */
#line 1130 "src/parser/rules.y"
                {
        (yyval.tetriary) = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE((yyval.tetriary), (yyvsp[0].sizeof_op));
        (yyval.tetriary)->sizeof_op = (yyvsp[0].sizeof_op);
    }
#line 3074 "src/parser/rules.tab.c"
    break;

  case 119: /* tetriary: secondary  */
#line 1135 "src/parser/rules.y"
                {
        (yyval.tetriary) = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE((yyval.tetriary), (yyvsp[0].secondary));
        (yyval.tetriary)->secondary = (yyvsp[0].secondary);
    }
#line 3084 "src/parser/rules.tab.c"
    break;

  case 120: /* suffix_op: secondary INCREMENT  */
#line 1143 "src/parser/rules.y"
                        {
        (yyval.suffix_op) = ALLOC(struct suffix_op_node_t);
        TFRAG_COMBINE((yyval.suffix_op), (yyvsp[-1].secondary), (yyvsp[0].name));
        (yyval.suffix_op)->arg = (yyvsp[-1].secondary);
        (yyval.suffix_op)->op = (yyvsp[0].name);
    }
#line 3095 "src/parser/rules.tab.c"
    break;

  case 121: /* suffix_op: secondary DECREMENT  */
#line 1149 "src/parser/rules.y"
                          {
        (yyval.suffix_op) = ALLOC(struct suffix_op_node_t);
        TFRAG_COMBINE((yyval.suffix_op), (yyvsp[-1].secondary), (yyvsp[0].name));
        (yyval.suffix_op)->arg = (yyvsp[-1].secondary);
        (yyval.suffix_op)->op = (yyvsp[0].name);
    }
#line 3106 "src/parser/rules.tab.c"
    break;

  case 122: /* function_call_op_arg: expression  */
#line 1158 "src/parser/rules.y"
               {
        (yyval.function_call_op_arg) = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE((yyval.function_call_op_arg), (yyvsp[0].expression));
        (yyval.function_call_op_arg)->arg = (yyvsp[0].expression);
    }
#line 3116 "src/parser/rules.tab.c"
    break;

  case 123: /* function_call_op_arg: expression ":" memory_length  */
#line 1163 "src/parser/rules.y"
                                   {
        (yyval.function_call_op_arg) = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE((yyval.function_call_op_arg), (yyvsp[-2].expression), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_call_op_arg)->arg = (yyvsp[-2].expression);
        (yyval.function_call_op_arg)->colon = (yyvsp[-1].name);
        (yyval.function_call_op_arg)->mem_len = (yyvsp[0].name);
    }
#line 3128 "src/parser/rules.tab.c"
    break;

  case 124: /* function_call_op_arg: expression ":" alignment  */
#line 1170 "src/parser/rules.y"
                               {
        (yyval.function_call_op_arg) = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE((yyval.function_call_op_arg), (yyvsp[-2].expression), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_call_op_arg)->arg = (yyvsp[-2].expression);
        (yyval.function_call_op_arg)->colon = (yyvsp[-1].name);
        (yyval.function_call_op_arg)->align = (yyvsp[0].name);
    }
#line 3140 "src/parser/rules.tab.c"
    break;

  case 125: /* function_call_op_arg: expression ":" abi_class  */
#line 1177 "src/parser/rules.y"
                               {
        (yyval.function_call_op_arg) = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE((yyval.function_call_op_arg), (yyvsp[-2].expression), (yyvsp[-1].name), (yyvsp[0].abi_class));
        (yyval.function_call_op_arg)->arg = (yyvsp[-2].expression);
        (yyval.function_call_op_arg)->colon = (yyvsp[-1].name);
        (yyval.function_call_op_arg)->abi_class = (yyvsp[0].abi_class);
    }
#line 3152 "src/parser/rules.tab.c"
    break;

  case 126: /* function_call_op_arg: expression ":" memory_length alignment  */
#line 1184 "src/parser/rules.y"
                                             {
        (yyval.function_call_op_arg) = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE((yyval.function_call_op_arg), (yyvsp[-3].expression), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_call_op_arg)->arg = (yyvsp[-3].expression);
        (yyval.function_call_op_arg)->colon = (yyvsp[-2].name);
        (yyval.function_call_op_arg)->mem_len = (yyvsp[-1].name);
        (yyval.function_call_op_arg)->align = (yyvsp[0].name);
    }
#line 3165 "src/parser/rules.tab.c"
    break;

  case 127: /* function_call_op_arg: expression ":" memory_length abi_class  */
#line 1192 "src/parser/rules.y"
                                             {
        (yyval.function_call_op_arg) = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE((yyval.function_call_op_arg), (yyvsp[-3].expression), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].abi_class));
        (yyval.function_call_op_arg)->arg = (yyvsp[-3].expression);
        (yyval.function_call_op_arg)->colon = (yyvsp[-2].name);
        (yyval.function_call_op_arg)->mem_len = (yyvsp[-1].name);
        (yyval.function_call_op_arg)->abi_class = (yyvsp[0].abi_class);
    }
#line 3178 "src/parser/rules.tab.c"
    break;

  case 128: /* function_call_op_arg: expression ":" alignment abi_class  */
#line 1200 "src/parser/rules.y"
                                         {
        (yyval.function_call_op_arg) = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE((yyval.function_call_op_arg), (yyvsp[-3].expression), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].abi_class));
        (yyval.function_call_op_arg)->arg = (yyvsp[-3].expression);
        (yyval.function_call_op_arg)->colon = (yyvsp[-2].name);
        (yyval.function_call_op_arg)->align = (yyvsp[-1].name);
        (yyval.function_call_op_arg)->abi_class = (yyvsp[0].abi_class);
    }
#line 3191 "src/parser/rules.tab.c"
    break;

  case 129: /* function_call_op_arg: expression ":" memory_length alignment abi_class  */
#line 1208 "src/parser/rules.y"
                                                       {
        (yyval.function_call_op_arg) = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE((yyval.function_call_op_arg), (yyvsp[-4].expression), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].abi_class));
        (yyval.function_call_op_arg)->arg = (yyvsp[-4].expression);
        (yyval.function_call_op_arg)->colon = (yyvsp[-3].name);
        (yyval.function_call_op_arg)->mem_len = (yyvsp[-2].name);
        (yyval.function_call_op_arg)->align = (yyvsp[-1].name);
        (yyval.function_call_op_arg)->abi_class = (yyvsp[0].abi_class);
    }
#line 3205 "src/parser/rules.tab.c"
    break;

  case 130: /* function_call_op_args: function_call_op_args "," function_call_op_arg  */
#line 1220 "src/parser/rules.y"
                                                   {
        (yyval.function_call_op_args) = ALLOC(struct function_call_op_args_node_t);
        TFRAG_COMBINE((yyval.function_call_op_args), (yyvsp[-2].function_call_op_args), (yyvsp[-1].name), (yyvsp[0].function_call_op_arg));
        (yyval.function_call_op_args)->rest = (yyvsp[-2].function_call_op_args);
        (yyval.function_call_op_args)->comma = (yyvsp[-1].name);
        (yyval.function_call_op_args)->arg = (yyvsp[0].function_call_op_arg);
    }
#line 3217 "src/parser/rules.tab.c"
    break;

  case 131: /* function_call_op_args: function_call_op_arg  */
#line 1227 "src/parser/rules.y"
                           {
        (yyval.function_call_op_args) = ALLOC(struct function_call_op_args_node_t);
        TFRAG_COMBINE((yyval.function_call_op_args), (yyvsp[0].function_call_op_arg));
        (yyval.function_call_op_args)->arg = (yyvsp[0].function_call_op_arg);
    }
#line 3227 "src/parser/rules.tab.c"
    break;

  case 132: /* function_call_op_args: %empty  */
#line 1232 "src/parser/rules.y"
      {
        (yyval.function_call_op_args) = ALLOC(struct function_call_op_args_node_t);
    }
#line 3235 "src/parser/rules.tab.c"
    break;

  case 133: /* function_call_op: CALL expression "(" function_call_op_args ")"  */
#line 1238 "src/parser/rules.y"
                                                  {
        (yyval.function_call_op) = ALLOC(struct function_call_op_node_t);
        TFRAG_COMBINE((yyval.function_call_op), (yyvsp[-4].name), (yyvsp[-3].expression), (yyvsp[-2].name), (yyvsp[-1].function_call_op_args), (yyvsp[0].name));
        (yyval.function_call_op)->kw = (yyvsp[-4].name);
        (yyval.function_call_op)->fn = (yyvsp[-3].expression);
        (yyval.function_call_op)->open_bracket = (yyvsp[-2].name);
        (yyval.function_call_op)->args = (yyvsp[-1].function_call_op_args);
        (yyval.function_call_op)->close_bracket = (yyvsp[0].name);
    }
#line 3249 "src/parser/rules.tab.c"
    break;

  case 134: /* function_call_op: CALL memory_length expression "(" function_call_op_args ")"  */
#line 1247 "src/parser/rules.y"
                                                                  {
        (yyval.function_call_op) = ALLOC(struct function_call_op_node_t);
        TFRAG_COMBINE((yyval.function_call_op), (yyvsp[-5].name), (yyvsp[-4].name), (yyvsp[-3].expression), (yyvsp[-2].name), (yyvsp[-1].function_call_op_args), (yyvsp[0].name));
        (yyval.function_call_op)->kw = (yyvsp[-5].name);
        (yyval.function_call_op)->mem_len = (yyvsp[-4].name);
        (yyval.function_call_op)->fn = (yyvsp[-3].expression);
        (yyval.function_call_op)->open_bracket = (yyvsp[-2].name);
        (yyval.function_call_op)->args = (yyvsp[-1].function_call_op_args);
        (yyval.function_call_op)->close_bracket = (yyvsp[0].name);
    }
#line 3264 "src/parser/rules.tab.c"
    break;

  case 135: /* function_call_op: CALL abi_class expression "(" function_call_op_args ")"  */
#line 1257 "src/parser/rules.y"
                                                              {
        (yyval.function_call_op) = ALLOC(struct function_call_op_node_t);
        TFRAG_COMBINE((yyval.function_call_op), (yyvsp[-5].name), (yyvsp[-4].abi_class), (yyvsp[-3].expression), (yyvsp[-2].name), (yyvsp[-1].function_call_op_args), (yyvsp[0].name));
        (yyval.function_call_op)->kw = (yyvsp[-5].name);
        (yyval.function_call_op)->abi_class = (yyvsp[-4].abi_class);
        (yyval.function_call_op)->fn = (yyvsp[-3].expression);
        (yyval.function_call_op)->open_bracket = (yyvsp[-2].name);
        (yyval.function_call_op)->args = (yyvsp[-1].function_call_op_args);
        (yyval.function_call_op)->close_bracket = (yyvsp[0].name);
    }
#line 3279 "src/parser/rules.tab.c"
    break;

  case 136: /* function_call_op: CALL memory_length abi_class expression "(" function_call_op_args ")"  */
#line 1267 "src/parser/rules.y"
                                                                            {
        (yyval.function_call_op) = ALLOC(struct function_call_op_node_t);
        TFRAG_COMBINE((yyval.function_call_op), (yyvsp[-6].name), (yyvsp[-5].name), (yyvsp[-4].abi_class), (yyvsp[-3].expression), (yyvsp[-2].name), (yyvsp[-1].function_call_op_args), (yyvsp[0].name));
        (yyval.function_call_op)->kw = (yyvsp[-6].name);
        (yyval.function_call_op)->mem_len = (yyvsp[-5].name);
        (yyval.function_call_op)->abi_class = (yyvsp[-4].abi_class);
        (yyval.function_call_op)->fn = (yyvsp[-3].expression);
        (yyval.function_call_op)->open_bracket = (yyvsp[-2].name);
        (yyval.function_call_op)->args = (yyvsp[-1].function_call_op_args);
        (yyval.function_call_op)->close_bracket = (yyvsp[0].name);
    }
#line 3295 "src/parser/rules.tab.c"
    break;

  case 137: /* dereference_op: secondary "[" expression "]"  */
#line 1280 "src/parser/rules.y"
                                 {
        (yyval.dereference_op) = ALLOC(struct dereference_op_node_t);
        TFRAG_COMBINE((yyval.dereference_op), (yyvsp[-3].secondary), (yyvsp[-2].name), (yyvsp[-1].expression), (yyvsp[0].name));
        (yyval.dereference_op)->arg = (yyvsp[-3].secondary);
        (yyval.dereference_op)->open_brace = (yyvsp[-2].name);
        (yyval.dereference_op)->offset = (yyvsp[-1].expression);
        (yyval.dereference_op)->close_brace = (yyvsp[0].name);
    }
#line 3308 "src/parser/rules.tab.c"
    break;

  case 138: /* dereference_op: secondary "[" "]"  */
#line 1288 "src/parser/rules.y"
                        {
        (yyval.dereference_op) = ALLOC(struct dereference_op_node_t);
        TFRAG_COMBINE((yyval.dereference_op), (yyvsp[-2].secondary), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.dereference_op)->arg = (yyvsp[-2].secondary);
        (yyval.dereference_op)->open_brace = (yyvsp[-1].name);
        (yyval.dereference_op)->close_brace = (yyvsp[0].name);
    }
#line 3320 "src/parser/rules.tab.c"
    break;

  case 139: /* layout_access_op: secondary ACCESS NAME  */
#line 1298 "src/parser/rules.y"
                          {
        (yyval.layout_access_op) = ALLOC(struct layout_access_op_node_t);
        TFRAG_COMBINE((yyval.layout_access_op), (yyvsp[-2].secondary), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.layout_access_op)->arg = (yyvsp[-2].secondary);
        (yyval.layout_access_op)->op = (yyvsp[-1].name);
        (yyval.layout_access_op)->field = (yyvsp[0].name);
    }
#line 3332 "src/parser/rules.tab.c"
    break;

  case 140: /* secondary: suffix_op  */
#line 1308 "src/parser/rules.y"
              {
        (yyval.secondary) = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE((yyval.secondary), (yyvsp[0].suffix_op));
        (yyval.secondary)->suffix = (yyvsp[0].suffix_op);
    }
#line 3342 "src/parser/rules.tab.c"
    break;

  case 141: /* secondary: function_call_op  */
#line 1313 "src/parser/rules.y"
                       {
        (yyval.secondary) = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE((yyval.secondary), (yyvsp[0].function_call_op));
        (yyval.secondary)->fn_call = (yyvsp[0].function_call_op);
    }
#line 3352 "src/parser/rules.tab.c"
    break;

  case 142: /* secondary: dereference_op  */
#line 1318 "src/parser/rules.y"
                     {
        (yyval.secondary) = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE((yyval.secondary), (yyvsp[0].dereference_op));
        (yyval.secondary)->deref = (yyvsp[0].dereference_op);
    }
#line 3362 "src/parser/rules.tab.c"
    break;

  case 143: /* secondary: layout_access_op  */
#line 1323 "src/parser/rules.y"
                       {
        (yyval.secondary) = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE((yyval.secondary), (yyvsp[0].layout_access_op));
        (yyval.secondary)->layout_access = (yyvsp[0].layout_access_op);
    }
#line 3372 "src/parser/rules.tab.c"
    break;

  case 144: /* secondary: primary  */
#line 1328 "src/parser/rules.y"
              {
        (yyval.secondary) = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE((yyval.secondary), (yyvsp[0].primary));
        (yyval.secondary)->primary = (yyvsp[0].primary);
    }
#line 3382 "src/parser/rules.tab.c"
    break;

  case 145: /* primary: "(" expression ")"  */
#line 1336 "src/parser/rules.y"
                       {
        (yyval.primary) = ALLOC(struct primary_node_t);
        TFRAG_COMBINE((yyval.primary), (yyvsp[-2].name), (yyvsp[-1].expression), (yyvsp[0].name));
        (yyval.primary)->open_brace = (yyvsp[-2].name);
        (yyval.primary)->expression = (yyvsp[-1].expression);
        (yyval.primary)->close_brace = (yyvsp[0].name);
    }
#line 3394 "src/parser/rules.tab.c"
    break;

  case 146: /* primary: literal  */
#line 1343 "src/parser/rules.y"
              {
        (yyval.primary) = ALLOC(struct primary_node_t);
        TFRAG_COMBINE((yyval.primary), (yyvsp[0].literal));
        (yyval.primary)->literal = (yyvsp[0].literal);
    }
#line 3404 "src/parser/rules.tab.c"
    break;

  case 147: /* literal: INT  */
#line 1351 "src/parser/rules.y"
        { (yyval.literal) = (yyvsp[0].literal); }
#line 3410 "src/parser/rules.tab.c"
    break;

  case 148: /* literal: UINT  */
#line 1352 "src/parser/rules.y"
           { (yyval.literal) = (yyvsp[0].literal); }
#line 3416 "src/parser/rules.tab.c"
    break;

  case 149: /* literal: DOUBLE  */
#line 1353 "src/parser/rules.y"
             { (yyval.literal) = (yyvsp[0].literal); }
#line 3422 "src/parser/rules.tab.c"
    break;

  case 150: /* literal: STRING  */
#line 1354 "src/parser/rules.y"
             { (yyval.literal) = (yyvsp[0].literal); }
#line 3428 "src/parser/rules.tab.c"
    break;

  case 151: /* literal: NAME  */
#line 1355 "src/parser/rules.y"
           {
        (yyval.literal) = ALLOC(struct literal_node_t);
        TFRAG_COMBINE((yyval.literal), (yyvsp[0].name));
        (yyval.literal)->type = LIT_NAME;
        (yyval.literal)->name_lit = (yyvsp[0].name);
    }
#line 3439 "src/parser/rules.tab.c"
    break;


#line 3443 "src/parser/rules.tab.c"

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

#line 1363 "src/parser/rules.y"

