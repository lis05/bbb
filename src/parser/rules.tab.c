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
  YYSYMBOL_ROB = 57,                       /* ROB  */
  YYSYMBOL_58_ = 58,                       /* '('  */
  YYSYMBOL_RCB = 59,                       /* RCB  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_SOB = 61,                       /* SOB  */
  YYSYMBOL_62_ = 62,                       /* '['  */
  YYSYMBOL_SCB = 63,                       /* SCB  */
  YYSYMBOL_64_ = 64,                       /* ']'  */
  YYSYMBOL_COB = 65,                       /* COB  */
  YYSYMBOL_66_ = 66,                       /* '{'  */
  YYSYMBOL_CCB = 67,                       /* CCB  */
  YYSYMBOL_68_ = 68,                       /* '}'  */
  YYSYMBOL_ARROW = 69,                     /* ARROW  */
  YYSYMBOL_COLON = 70,                     /* COLON  */
  YYSYMBOL_71_ = 71,                       /* ':'  */
  YYSYMBOL_SEMICOLON = 72,                 /* SEMICOLON  */
  YYSYMBOL_73_ = 73,                       /* ';'  */
  YYSYMBOL_COMMA = 74,                     /* COMMA  */
  YYSYMBOL_75_ = 75,                       /* ','  */
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
  YYSYMBOL_body_list = 90,                 /* body_list  */
  YYSYMBOL_body = 91,                      /* body  */
  YYSYMBOL_statement = 92,                 /* statement  */
  YYSYMBOL_variable_declaration = 93,      /* variable_declaration  */
  YYSYMBOL_register_alias = 94,            /* register_alias  */
  YYSYMBOL_if_statement = 95,              /* if_statement  */
  YYSYMBOL_label_declaration = 96,         /* label_declaration  */
  YYSYMBOL_goto_statement = 97,            /* goto_statement  */
  YYSYMBOL_loop_statement = 98,            /* loop_statement  */
  YYSYMBOL_break_statement = 99,           /* break_statement  */
  YYSYMBOL_ret_statement = 100,            /* ret_statement  */
  YYSYMBOL_avoid_block_regs = 101,         /* avoid_block_regs  */
  YYSYMBOL_avoid_block = 102,              /* avoid_block  */
  YYSYMBOL_expression = 103,               /* expression  */
  YYSYMBOL_logical_or = 104,               /* logical_or  */
  YYSYMBOL_logical_and = 105,              /* logical_and  */
  YYSYMBOL_bitwise_or = 106,               /* bitwise_or  */
  YYSYMBOL_bitwise_xor = 107,              /* bitwise_xor  */
  YYSYMBOL_bitwise_and = 108,              /* bitwise_and  */
  YYSYMBOL_equality = 109,                 /* equality  */
  YYSYMBOL_relational = 110,               /* relational  */
  YYSYMBOL_additive = 111,                 /* additive  */
  YYSYMBOL_multiplicative = 112,           /* multiplicative  */
  YYSYMBOL_prefix_op = 113,                /* prefix_op  */
  YYSYMBOL_cast_op = 114,                  /* cast_op  */
  YYSYMBOL_address_op = 115,               /* address_op  */
  YYSYMBOL_sizeof_op = 116,                /* sizeof_op  */
  YYSYMBOL_tetriary = 117,                 /* tetriary  */
  YYSYMBOL_suffix_op = 118,                /* suffix_op  */
  YYSYMBOL_dereference_op = 119,           /* dereference_op  */
  YYSYMBOL_layout_access_op = 120,         /* layout_access_op  */
  YYSYMBOL_secondary = 121,                /* secondary  */
  YYSYMBOL_primary = 122,                  /* primary  */
  YYSYMBOL_literal = 123                   /* literal  */
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
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
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
      58,    60,     2,     2,    75,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    73,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,    68,     2,     2,     2,     2,
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
      55,    56,    57,    59,    61,    63,    65,    67,    69,    70,
      72,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   234,   234,   240,   246,   252,   258,   264,   270,   274,
     275,   279,   283,   290,   298,   306,   318,   319,   320,   324,
     325,   329,   337,   347,   357,   368,   383,   389,   398,   403,
     410,   417,   424,   432,   440,   448,   460,   467,   475,   486,
     499,   512,   526,   538,   552,   566,   585,   591,   597,   607,
     612,   617,   622,   627,   632,   637,   642,   647,   652,   657,
     663,   671,   672,   676,   677,   681,   682,   686,   690,   694,
     698,   699,   703,   707,   708,   712,   716,   717,   721,   722,
     726,   727,   731,   732,   736,   737,   741,   742,   746,   747,
     748,   752,   753,   754,   755,   756,   760,   761,   762,   766,
     767,   768,   769,   773,   774,   775,   776,   780,   784,   785,
     789,   793,   794,   795,   796,   797,   801,   802,   806,   807,
     811,   815,   816,   817,   818,   822,   823,   827,   828,   829,
     830,   831
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
  "NOT_EQUALS", "CAST", "ACCESS", "ROB", "'('", "RCB", "')'", "SOB", "'['",
  "SCB", "']'", "COB", "'{'", "CCB", "'}'", "ARROW", "COLON", "':'",
  "SEMICOLON", "';'", "COMMA", "','", "$accept", "program", "visibility",
  "memory_length", "alignment", "global_variable_declaration",
  "chunk_class", "abi_class", "layout_declaration_items",
  "layout_declaration", "extern_declaration", "function_declaration_arg",
  "function_declaration_args", "function_declaration", "body_list", "body",
  "statement", "variable_declaration", "register_alias", "if_statement",
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
     -84,    27,   -84,   -59,    13,    29,   -84,   -84,   -84,   -84,
     -84,   120,   -84,   -84,   -84,   -84,   -84,    45,     1,   160,
      79,   -84,   -84,   -84,   104,    49,   115,    75,    79,   -84,
     -84,   -29,    12,   104,    65,    68,   -84,   -27,   115,   -84,
      77,    78,   -84,    20,   104,   209,    21,   115,    -6,   -84,
      77,   -84,    36,   -84,   161,   172,   -84,   -84,   -84,   216,
     -84,   -84,    66,   -84,   -84,   172,   -84,   -84,    72,    39,
      70,   216,   -84,   -84,    96,   -84,   -84,   -84,   -84,   -84,
     154,   167,    70,   114,   124,   154,   182,   154,   154,   197,
     154,   154,   154,   118,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   131,    33,   177,   168,
     169,   162,    59,   144,    87,   121,   -84,   -84,   -84,   -84,
     159,   -84,   -84,   -84,   -18,   -84,   -84,    70,   -84,   -84,
      39,    70,    32,   -84,    70,   153,   -84,   -84,   -84,   158,
     -84,   -30,   159,   159,   -84,   159,   159,   173,   154,   170,
     -84,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   -84,   -84,
     -84,   229,   141,   -84,    70,   -84,   -84,    -4,    79,   211,
     -84,   -84,   220,   -84,   -84,   159,   154,   177,   -84,   168,
     169,   162,    59,   144,   144,    87,    87,    87,    87,   121,
     121,   159,   159,   159,   -84,   -84,   174,   -84,   -84,   -84,
     -84,    70,   -84,   159,   -84,   -84
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
     -84,   -84,   -84,   -16,   -28,   -84,    47,   -34,    73,   -84,
     171,   190,   202,   -84,   -84,   -60,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -79,   -84,    90,
      89,    91,    88,    92,   -15,    48,   -11,   -84,   -84,   -84,
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
     129,   208,    11,   147,   149,    41,    12,    55,   169,   170,
      66,    67,   136,    41,    49,    70,    65,     2,   209,    54,
       3,    73,    13,    46,    63,   127,    58,   131,   171,    41,
      14,    15,    40,    69,   172,   182,     4,     5,    47,     6,
      21,    22,    23,    53,    62,   130,    21,    22,    23,    26,
      21,    22,    23,   177,    25,   185,   151,   173,   152,    47,
     175,   176,    34,   188,   179,    74,    75,    76,    77,    78,
      42,   183,   201,   202,   203,    14,    15,    58,    51,    29,
      59,     4,     5,   206,    79,    80,   174,    81,    82,    83,
      84,    85,    86,   213,    64,    58,    43,    31,    87,    88,
      89,    24,   157,   158,   207,    33,   178,    52,    35,    90,
      91,   133,    75,    76,    77,    78,   163,   164,    14,    15,
      92,    44,    58,    38,    93,    71,    58,    16,    17,    45,
      94,    18,   193,   194,   133,    75,    76,    77,    78,    50,
     210,   215,   199,   200,    87,    88,    89,   133,    75,    76,
      77,    78,   165,   166,   167,    90,    91,   132,    14,    15,
     135,    29,    21,    22,    23,    53,    92,    87,    88,    89,
      93,    27,   148,    21,    22,    23,    53,   137,    90,    91,
      87,    88,    89,   159,   160,   161,   162,   138,   140,    92,
     144,    90,    91,    93,   150,   205,   156,   195,   196,   197,
     198,   153,    92,   154,   168,   155,    93,    14,    15,    29,
      21,    22,    23,    53,    14,    15,   180,    21,    22,    23,
      53,   181,   204,   184,   186,   211,   212,    61,   214,    95,
      48,   187,   189,   191,     0,   190,     0,     0,   192
};

static const yytype_int16 yycheck[] =
{
      28,    80,    62,    19,    87,    88,    85,    90,    91,    69,
      70,    15,    71,    92,    93,     3,     3,    45,    36,    37,
      54,    55,    82,     3,    40,    59,    54,     0,    32,    45,
       3,    65,     3,    60,    50,    69,    66,    71,    56,     3,
       8,     9,    71,    59,    62,    75,    19,    20,    75,    22,
      11,    12,    13,    14,    60,    71,    11,    12,    13,    58,
      11,    12,    13,    31,    17,   148,    33,   127,    35,    75,
     130,   131,    25,   152,   134,     3,     4,     5,     6,     7,
      68,   141,   165,   166,   167,     8,     9,    66,    68,    10,
      69,    19,    20,   172,    22,    23,   130,    25,    26,    27,
      28,    29,    30,   186,    68,    66,    33,     3,    36,    37,
      38,    66,    53,    54,   174,    66,   132,    44,     3,    47,
      48,     3,     4,     5,     6,     7,    39,    40,     8,     9,
      58,    66,    66,    58,    62,    69,    66,    17,    18,    71,
      68,    21,   157,   158,     3,     4,     5,     6,     7,    71,
     178,   211,   163,   164,    36,    37,    38,     3,     4,     5,
       6,     7,    41,    42,    43,    47,    48,    71,     8,     9,
       3,    10,    11,    12,    13,    14,    58,    36,    37,    38,
      62,    21,    64,    11,    12,    13,    14,    73,    47,    48,
      36,    37,    38,    49,    50,    51,    52,    73,    16,    58,
       3,    47,    48,    62,    73,    64,    44,   159,   160,   161,
     162,    34,    58,    45,    55,    46,    62,     8,     9,    10,
      11,    12,    13,    14,     8,     9,    73,    11,    12,    13,
      14,    73,     3,    60,    64,    24,    16,    47,    64,    68,
      38,   151,   153,   155,    -1,   154,    -1,    -1,   156
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    77,     0,     3,    19,    20,    22,    81,    85,    86,
      89,    71,     3,     3,     8,     9,    17,    18,    21,    78,
      79,    11,    12,    13,    66,    82,    58,    21,    79,    10,
      80,     3,    84,    66,    82,     3,    87,    88,    58,    80,
      71,     3,    68,    84,    66,    71,    60,    75,    88,    79,
      71,    68,    84,    14,    79,    80,    82,    83,    66,    69,
      91,    87,    60,    79,    68,    80,    83,    83,    90,    79,
      83,    69,    91,    83,     3,     4,     5,     6,     7,    22,
      23,    25,    26,    27,    28,    29,    30,    36,    37,    38,
      47,    48,    58,    62,    68,    86,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    83,    91,    91,
      79,    83,    71,     3,   103,     3,    91,    73,    73,   103,
      16,   101,   117,   117,     3,   117,   117,   103,    64,   103,
      73,    33,    35,    34,    45,    46,    44,    53,    54,    49,
      50,    51,    52,    39,    40,    41,    42,    43,    55,    36,
      37,    56,    62,    91,    83,    91,    91,    31,    79,    91,
      73,    73,    75,    91,    60,   117,    64,   105,   103,   106,
     107,   108,   109,   110,   110,   111,   111,   111,   111,   112,
     112,   117,   117,   117,     3,    64,   103,    91,    15,    32,
      80,    24,    16,   117,    64,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    76,    77,    77,    77,    77,    77,    77,    78,    79,
      79,    80,    81,    81,    81,    81,    82,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    86,    86,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90,    91,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    97,    98,
      99,    99,   100,   101,   101,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     109,   110,   110,   110,   110,   110,   111,   111,   111,   112,
     112,   112,   112,   113,   113,   113,   113,   114,   115,   115,
     116,   117,   117,   117,   117,   117,   118,   118,   119,   119,
     120,   121,   121,   121,   121,   122,   122,   123,   123,   123,
     123,   123
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
#line 234 "src/parser/rules.y"
                                        {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].global_variable_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->gvar_decl = (yyvsp[0].global_variable_declaration);
    }
#line 1426 "src/parser/rules.tab.c"
    break;

  case 3: /* program: program layout_declaration  */
#line 240 "src/parser/rules.y"
                                 {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].layout_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->layout_decl = (yyvsp[0].layout_declaration);
    }
#line 1437 "src/parser/rules.tab.c"
    break;

  case 4: /* program: program extern_declaration  */
#line 246 "src/parser/rules.y"
                                 {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].extern_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->ext_decl = (yyvsp[0].extern_declaration);
    }
#line 1448 "src/parser/rules.tab.c"
    break;

  case 5: /* program: program function_declaration  */
#line 252 "src/parser/rules.y"
                                   {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].function_declaration));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->fn_decl = (yyvsp[0].function_declaration);
    }
#line 1459 "src/parser/rules.tab.c"
    break;

  case 6: /* program: program NASM_BLOCK  */
#line 258 "src/parser/rules.y"
                         {
        (yyval.program) = ALLOC(struct program_node_t);
        TFRAG_COMBINE((yyval.program), (yyvsp[-1].program), (yyvsp[0].name));
        (yyval.program)->rest = (yyvsp[-1].program);
        (yyval.program)->nasm_b = (yyvsp[0].name);
    }
#line 1470 "src/parser/rules.tab.c"
    break;

  case 7: /* program: %empty  */
#line 264 "src/parser/rules.y"
      {
        (yyval.program) = ALLOC(struct program_node_t);
    }
#line 1478 "src/parser/rules.tab.c"
    break;

  case 8: /* visibility: GLOBAL  */
#line 270 "src/parser/rules.y"
           { (yyval.name) = (yyvsp[0].name); }
#line 1484 "src/parser/rules.tab.c"
    break;

  case 9: /* memory_length: MEMORY_LENGTH_SIMPLE  */
#line 274 "src/parser/rules.y"
                         { (yyval.name) = (yyvsp[0].name); }
#line 1490 "src/parser/rules.tab.c"
    break;

  case 10: /* memory_length: MEMORY_LENGTH_PREFIX  */
#line 275 "src/parser/rules.y"
                           { (yyval.name) = (yyvsp[0].name); }
#line 1496 "src/parser/rules.tab.c"
    break;

  case 11: /* alignment: ALIGNMENT_SIMPLE  */
#line 279 "src/parser/rules.y"
                     { (yyval.name) = (yyvsp[0].name); }
#line 1502 "src/parser/rules.tab.c"
    break;

  case 12: /* global_variable_declaration: NAME ':' memory_length  */
#line 283 "src/parser/rules.y"
                           {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[0].name);
    }
#line 1514 "src/parser/rules.tab.c"
    break;

  case 13: /* global_variable_declaration: NAME ':' visibility memory_length  */
#line 290 "src/parser/rules.y"
                                        {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-3].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->vis = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[0].name);
    }
#line 1527 "src/parser/rules.tab.c"
    break;

  case 14: /* global_variable_declaration: NAME ':' memory_length alignment  */
#line 298 "src/parser/rules.y"
                                       {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-3].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->align = (yyvsp[0].name);
    }
#line 1540 "src/parser/rules.tab.c"
    break;

  case 15: /* global_variable_declaration: NAME ':' visibility memory_length alignment  */
#line 306 "src/parser/rules.y"
                                                  {
        (yyval.global_variable_declaration) = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE((yyval.global_variable_declaration), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.global_variable_declaration)->name = (yyvsp[-4].name);
        (yyval.global_variable_declaration)->colon = (yyvsp[-3].name);
        (yyval.global_variable_declaration)->vis = (yyvsp[-2].name);
        (yyval.global_variable_declaration)->mem_len = (yyvsp[-1].name);
        (yyval.global_variable_declaration)->align = (yyvsp[0].name);
    }
#line 1554 "src/parser/rules.tab.c"
    break;

  case 16: /* chunk_class: CHUNK_CLASS_MEM  */
#line 318 "src/parser/rules.y"
                    { (yyval.name) = (yyvsp[0].name); }
#line 1560 "src/parser/rules.tab.c"
    break;

  case 17: /* chunk_class: CHUNK_CLASS_SSE  */
#line 319 "src/parser/rules.y"
                      { (yyval.name) = (yyvsp[0].name); }
#line 1566 "src/parser/rules.tab.c"
    break;

  case 18: /* chunk_class: CHUNK_CLASS_INT  */
#line 320 "src/parser/rules.y"
                      { (yyval.name) = (yyvsp[0].name); }
#line 1572 "src/parser/rules.tab.c"
    break;

  case 19: /* abi_class: chunk_class  */
#line 324 "src/parser/rules.y"
                { (yyval.name) = (yyvsp[0].name); }
#line 1578 "src/parser/rules.tab.c"
    break;

  case 20: /* abi_class: CHUNK_CLASS_LAYOUT  */
#line 325 "src/parser/rules.y"
                         { (yyval.name) = (yyvsp[0].name); }
#line 1584 "src/parser/rules.tab.c"
    break;

  case 21: /* layout_declaration_items: layout_declaration_items NAME ':' memory_length  */
#line 329 "src/parser/rules.y"
                                                    {
        (yyval.layout_declaration_items) = ALLOC(struct layout_declaration_items_node_t);
        TFRAG_COMBINE((yyval.layout_declaration_items), (yyvsp[-3].layout_declaration_items), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.layout_declaration_items)->rest = (yyvsp[-3].layout_declaration_items);
        (yyval.layout_declaration_items)->name = (yyvsp[-2].name);
        (yyval.layout_declaration_items)->colon = (yyvsp[-1].name);
        (yyval.layout_declaration_items)->mem_len = (yyvsp[0].name);
    }
#line 1597 "src/parser/rules.tab.c"
    break;

  case 22: /* layout_declaration_items: NAME ':' memory_length  */
#line 337 "src/parser/rules.y"
                             {
        (yyval.layout_declaration_items) = ALLOC(struct layout_declaration_items_node_t);
        TFRAG_COMBINE((yyval.layout_declaration_items), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.layout_declaration_items)->name = (yyvsp[-2].name);
        (yyval.layout_declaration_items)->colon = (yyvsp[-1].name);
        (yyval.layout_declaration_items)->mem_len = (yyvsp[0].name);
    }
#line 1609 "src/parser/rules.tab.c"
    break;

  case 23: /* layout_declaration: NAME ':' LAYOUT '{' layout_declaration_items '}'  */
#line 347 "src/parser/rules.y"
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
#line 1624 "src/parser/rules.tab.c"
    break;

  case 24: /* layout_declaration: NAME ':' LAYOUT chunk_class '{' layout_declaration_items '}'  */
#line 357 "src/parser/rules.y"
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
#line 1640 "src/parser/rules.tab.c"
    break;

  case 25: /* layout_declaration: NAME ':' LAYOUT chunk_class chunk_class '{' layout_declaration_items '}'  */
#line 368 "src/parser/rules.y"
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
#line 1657 "src/parser/rules.tab.c"
    break;

  case 26: /* extern_declaration: EXTERN NAME  */
#line 383 "src/parser/rules.y"
                {
        (yyval.extern_declaration) = ALLOC(struct extern_declaration_node_t);
        TFRAG_COMBINE((yyval.extern_declaration), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.extern_declaration)->kw = (yyvsp[-1].name);
        (yyval.extern_declaration)->name = (yyvsp[0].name);
    }
#line 1668 "src/parser/rules.tab.c"
    break;

  case 27: /* extern_declaration: NASM NAME  */
#line 389 "src/parser/rules.y"
                {
        (yyval.extern_declaration) = ALLOC(struct extern_declaration_node_t);
        TFRAG_COMBINE((yyval.extern_declaration), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.extern_declaration)->kw = (yyvsp[-1].name);
        (yyval.extern_declaration)->name = (yyvsp[0].name);
    }
#line 1679 "src/parser/rules.tab.c"
    break;

  case 28: /* function_declaration_arg: NAME  */
#line 398 "src/parser/rules.y"
         {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[0].name);
    }
#line 1689 "src/parser/rules.tab.c"
    break;

  case 29: /* function_declaration_arg: NAME ':' memory_length  */
#line 403 "src/parser/rules.y"
                             {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[0].name);
    }
#line 1701 "src/parser/rules.tab.c"
    break;

  case 30: /* function_declaration_arg: NAME ':' alignment  */
#line 410 "src/parser/rules.y"
                         {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->align = (yyvsp[0].name);
    }
#line 1713 "src/parser/rules.tab.c"
    break;

  case 31: /* function_declaration_arg: NAME ':' abi_class  */
#line 417 "src/parser/rules.y"
                         {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].name);
    }
#line 1725 "src/parser/rules.tab.c"
    break;

  case 32: /* function_declaration_arg: NAME ':' memory_length alignment  */
#line 424 "src/parser/rules.y"
                                       {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->align = (yyvsp[0].name);
    }
#line 1738 "src/parser/rules.tab.c"
    break;

  case 33: /* function_declaration_arg: NAME ':' memory_length abi_class  */
#line 432 "src/parser/rules.y"
                                       {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].name);
    }
#line 1751 "src/parser/rules.tab.c"
    break;

  case 34: /* function_declaration_arg: NAME ':' alignment abi_class  */
#line 440 "src/parser/rules.y"
                                   {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->align = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].name);
    }
#line 1764 "src/parser/rules.tab.c"
    break;

  case 35: /* function_declaration_arg: NAME ':' memory_length alignment abi_class  */
#line 448 "src/parser/rules.y"
                                                 {
        (yyval.function_declaration_arg) = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE((yyval.function_declaration_arg), (yyvsp[-4].name), (yyvsp[-3].name), (yyvsp[-2].name), (yyvsp[-1].name), (yyvsp[0].name));
        (yyval.function_declaration_arg)->name = (yyvsp[-4].name);
        (yyval.function_declaration_arg)->colon = (yyvsp[-3].name);
        (yyval.function_declaration_arg)->mem_len = (yyvsp[-2].name);
        (yyval.function_declaration_arg)->align = (yyvsp[-1].name);
        (yyval.function_declaration_arg)->abi_class = (yyvsp[0].name);
    }
#line 1778 "src/parser/rules.tab.c"
    break;

  case 36: /* function_declaration_args: function_declaration_args ',' function_declaration_arg  */
#line 460 "src/parser/rules.y"
                                                           {
        (yyval.function_declaration_args) = ALLOC(struct function_declaration_args_node_t);
        TFRAG_COMBINE((yyval.function_declaration_args), (yyvsp[-2].function_declaration_args), (yyvsp[-1].name), (yyvsp[0].function_declaration_arg));
        (yyval.function_declaration_args)->rest = (yyvsp[-2].function_declaration_args);
        (yyval.function_declaration_args)->comma = (yyvsp[-1].name);
        (yyval.function_declaration_args)->arg = (yyvsp[0].function_declaration_arg);
    }
#line 1790 "src/parser/rules.tab.c"
    break;

  case 37: /* function_declaration_args: function_declaration_arg  */
#line 467 "src/parser/rules.y"
                               {
        (yyval.function_declaration_args) = ALLOC(struct function_declaration_args_node_t);
        TFRAG_COMBINE((yyval.function_declaration_args), (yyvsp[0].function_declaration_arg));
        (yyval.function_declaration_args)->arg = (yyvsp[0].function_declaration_arg);
    }
#line 1800 "src/parser/rules.tab.c"
    break;

  case 38: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' body  */
#line 475 "src/parser/rules.y"
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
#line 1816 "src/parser/rules.tab.c"
    break;

  case 39: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' ARROW memory_length body  */
#line 486 "src/parser/rules.y"
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
#line 1834 "src/parser/rules.tab.c"
    break;

  case 40: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' ARROW abi_class body  */
#line 499 "src/parser/rules.y"
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
#line 1852 "src/parser/rules.tab.c"
    break;

  case 41: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' ARROW memory_length abi_class body  */
#line 512 "src/parser/rules.y"
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
#line 1871 "src/parser/rules.tab.c"
    break;

  case 42: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' body  */
#line 526 "src/parser/rules.y"
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
#line 1888 "src/parser/rules.tab.c"
    break;

  case 43: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' ARROW memory_length body  */
#line 538 "src/parser/rules.y"
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
#line 1907 "src/parser/rules.tab.c"
    break;

  case 44: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' ARROW abi_class body  */
#line 552 "src/parser/rules.y"
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
#line 1926 "src/parser/rules.tab.c"
    break;

  case 45: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' ARROW memory_length abi_class body  */
#line 567 "src/parser/rules.y"
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
#line 1946 "src/parser/rules.tab.c"
    break;

  case 46: /* body_list: body_list statement  */
#line 585 "src/parser/rules.y"
                        {
        (yyval.body_list) = ALLOC(struct body_list_node_t);
        TFRAG_COMBINE((yyval.body_list), (yyvsp[-1].body_list), (yyvsp[0].statement));
        (yyval.body_list)->rest = (yyvsp[-1].body_list);
        (yyval.body_list)->s = (yyvsp[0].statement);
    }
#line 1957 "src/parser/rules.tab.c"
    break;

  case 47: /* body_list: %empty  */
#line 591 "src/parser/rules.y"
      {
        (yyval.body_list) = ALLOC(struct body_list_node_t);
    }
#line 1965 "src/parser/rules.tab.c"
    break;

  case 48: /* body: '{' body_list '}'  */
#line 597 "src/parser/rules.y"
                      {
        (yyval.body) = ALLOC(struct body_node_t);
        TFRAG_COMBINE((yyval.body), (yyvsp[-2].name), (yyvsp[-1].body_list), (yyvsp[0].name));
        (yyval.body)->open_brace = (yyvsp[-2].name);
        (yyval.body)->list = (yyvsp[-1].body_list);
        (yyval.body)->closed_brace = (yyvsp[0].name);
    }
#line 1977 "src/parser/rules.tab.c"
    break;

  case 49: /* statement: variable_declaration  */
#line 607 "src/parser/rules.y"
                         {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].variable_declaration));
        (yyval.statement)->vdecl = (yyvsp[0].variable_declaration);
    }
#line 1987 "src/parser/rules.tab.c"
    break;

  case 50: /* statement: register_alias  */
#line 612 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].register_alias));
        (yyval.statement)->alias = (yyvsp[0].register_alias);
    }
#line 1997 "src/parser/rules.tab.c"
    break;

  case 51: /* statement: extern_declaration  */
#line 617 "src/parser/rules.y"
                         {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].extern_declaration));
        (yyval.statement)->ext_decl = (yyvsp[0].extern_declaration);
    }
#line 2007 "src/parser/rules.tab.c"
    break;

  case 52: /* statement: if_statement  */
#line 622 "src/parser/rules.y"
                   {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].if_statement));
        (yyval.statement)->if_s = (yyvsp[0].if_statement);
    }
#line 2017 "src/parser/rules.tab.c"
    break;

  case 53: /* statement: label_declaration  */
#line 627 "src/parser/rules.y"
                        {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].label_declaration));
        (yyval.statement)->label = (yyvsp[0].label_declaration);
    }
#line 2027 "src/parser/rules.tab.c"
    break;

  case 54: /* statement: goto_statement  */
#line 632 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].goto_statement));
        (yyval.statement)->goto_s = (yyvsp[0].goto_statement);
    }
#line 2037 "src/parser/rules.tab.c"
    break;

  case 55: /* statement: loop_statement  */
#line 637 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].loop_statement));
        (yyval.statement)->loop_s = (yyvsp[0].loop_statement);
    }
#line 2047 "src/parser/rules.tab.c"
    break;

  case 56: /* statement: break_statement  */
#line 642 "src/parser/rules.y"
                      {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].break_statement));
        (yyval.statement)->break_s = (yyvsp[0].break_statement);
    }
#line 2057 "src/parser/rules.tab.c"
    break;

  case 57: /* statement: ret_statement  */
#line 647 "src/parser/rules.y"
                    {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].ret_statement));
        (yyval.statement)->ret_s = (yyvsp[0].ret_statement);
    }
#line 2067 "src/parser/rules.tab.c"
    break;

  case 58: /* statement: avoid_block  */
#line 652 "src/parser/rules.y"
                  {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].avoid_block));
        (yyval.statement)->avoid = (yyvsp[0].avoid_block);
    }
#line 2077 "src/parser/rules.tab.c"
    break;

  case 59: /* statement: expression ';'  */
#line 657 "src/parser/rules.y"
                     {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[-1].expression), (yyvsp[0].name));
        (yyval.statement)->expr = (yyvsp[-1].expression);
        (yyval.statement)->semicolon = (yyvsp[0].name);
    }
#line 2088 "src/parser/rules.tab.c"
    break;

  case 60: /* statement: NASM_BLOCK  */
#line 663 "src/parser/rules.y"
                 {
        (yyval.statement) = ALLOC(struct statement_node_t);
        TFRAG_COMBINE((yyval.statement), (yyvsp[0].name));
        (yyval.statement)->nasm = (yyvsp[0].name);
    }
#line 2098 "src/parser/rules.tab.c"
    break;

  case 61: /* variable_declaration: NAME ':' memory_length  */
#line 671 "src/parser/rules.y"
                           {}
#line 2104 "src/parser/rules.tab.c"
    break;

  case 62: /* variable_declaration: NAME ':' memory_length alignment  */
#line 672 "src/parser/rules.y"
                                       {}
#line 2110 "src/parser/rules.tab.c"
    break;

  case 63: /* register_alias: NAME ':' ALIAS REG  */
#line 676 "src/parser/rules.y"
                       {}
#line 2116 "src/parser/rules.tab.c"
    break;

  case 64: /* register_alias: NAME ':' ALIAS GP_REGISTER  */
#line 677 "src/parser/rules.y"
                                 {}
#line 2122 "src/parser/rules.tab.c"
    break;

  case 65: /* if_statement: IF expression body  */
#line 681 "src/parser/rules.y"
                       {}
#line 2128 "src/parser/rules.tab.c"
    break;

  case 66: /* if_statement: IF expression body ELSE body  */
#line 682 "src/parser/rules.y"
                                 {}
#line 2134 "src/parser/rules.tab.c"
    break;

  case 67: /* label_declaration: NAME ':'  */
#line 686 "src/parser/rules.y"
             {}
#line 2140 "src/parser/rules.tab.c"
    break;

  case 68: /* goto_statement: GOTO NAME ';'  */
#line 690 "src/parser/rules.y"
                  {}
#line 2146 "src/parser/rules.tab.c"
    break;

  case 69: /* loop_statement: LOOP body  */
#line 694 "src/parser/rules.y"
              {}
#line 2152 "src/parser/rules.tab.c"
    break;

  case 70: /* break_statement: BREAK ';'  */
#line 698 "src/parser/rules.y"
              {}
#line 2158 "src/parser/rules.tab.c"
    break;

  case 71: /* break_statement: CONTINUE ';'  */
#line 699 "src/parser/rules.y"
                   {}
#line 2164 "src/parser/rules.tab.c"
    break;

  case 72: /* ret_statement: RET expression ';'  */
#line 703 "src/parser/rules.y"
                       {}
#line 2170 "src/parser/rules.tab.c"
    break;

  case 73: /* avoid_block_regs: avoid_block_regs ',' REGISTER  */
#line 707 "src/parser/rules.y"
                                  {}
#line 2176 "src/parser/rules.tab.c"
    break;

  case 74: /* avoid_block_regs: REGISTER  */
#line 708 "src/parser/rules.y"
               {}
#line 2182 "src/parser/rules.tab.c"
    break;

  case 75: /* avoid_block: AVOID avoid_block_regs body  */
#line 712 "src/parser/rules.y"
                                {}
#line 2188 "src/parser/rules.tab.c"
    break;

  case 76: /* expression: logical_or ASSIGN expression  */
#line 716 "src/parser/rules.y"
                                 {}
#line 2194 "src/parser/rules.tab.c"
    break;

  case 77: /* expression: logical_or  */
#line 717 "src/parser/rules.y"
                 {}
#line 2200 "src/parser/rules.tab.c"
    break;

  case 78: /* logical_or: logical_or LOGICAL_OR logical_and  */
#line 721 "src/parser/rules.y"
                                      {}
#line 2206 "src/parser/rules.tab.c"
    break;

  case 79: /* logical_or: logical_and  */
#line 722 "src/parser/rules.y"
                  {}
#line 2212 "src/parser/rules.tab.c"
    break;

  case 80: /* logical_and: logical_and LOGICAL_AND bitwise_or  */
#line 726 "src/parser/rules.y"
                                       {}
#line 2218 "src/parser/rules.tab.c"
    break;

  case 81: /* logical_and: bitwise_or  */
#line 727 "src/parser/rules.y"
                 {}
#line 2224 "src/parser/rules.tab.c"
    break;

  case 82: /* bitwise_or: bitwise_or BITWISE_OR bitwise_xor  */
#line 731 "src/parser/rules.y"
                                      {}
#line 2230 "src/parser/rules.tab.c"
    break;

  case 83: /* bitwise_or: bitwise_xor  */
#line 732 "src/parser/rules.y"
                  {}
#line 2236 "src/parser/rules.tab.c"
    break;

  case 84: /* bitwise_xor: bitwise_xor BITWISE_XOR bitwise_and  */
#line 736 "src/parser/rules.y"
                                        {}
#line 2242 "src/parser/rules.tab.c"
    break;

  case 85: /* bitwise_xor: bitwise_and  */
#line 737 "src/parser/rules.y"
                  {}
#line 2248 "src/parser/rules.tab.c"
    break;

  case 86: /* bitwise_and: bitwise_and BITWISE_AND equality  */
#line 741 "src/parser/rules.y"
                                     {}
#line 2254 "src/parser/rules.tab.c"
    break;

  case 87: /* bitwise_and: equality  */
#line 742 "src/parser/rules.y"
               {}
#line 2260 "src/parser/rules.tab.c"
    break;

  case 88: /* equality: equality EQUALS relational  */
#line 746 "src/parser/rules.y"
                               {}
#line 2266 "src/parser/rules.tab.c"
    break;

  case 89: /* equality: equality NOT_EQUALS relational  */
#line 747 "src/parser/rules.y"
                                     {}
#line 2272 "src/parser/rules.tab.c"
    break;

  case 90: /* equality: relational  */
#line 748 "src/parser/rules.y"
                 {}
#line 2278 "src/parser/rules.tab.c"
    break;

  case 91: /* relational: relational LESS_THAN additive  */
#line 752 "src/parser/rules.y"
                                  {}
#line 2284 "src/parser/rules.tab.c"
    break;

  case 92: /* relational: relational GREATER_THAN additive  */
#line 753 "src/parser/rules.y"
                                       {}
#line 2290 "src/parser/rules.tab.c"
    break;

  case 93: /* relational: relational LESS_EQUAL additive  */
#line 754 "src/parser/rules.y"
                                     {}
#line 2296 "src/parser/rules.tab.c"
    break;

  case 94: /* relational: relational GREATER_EQUAL additive  */
#line 755 "src/parser/rules.y"
                                        {}
#line 2302 "src/parser/rules.tab.c"
    break;

  case 95: /* relational: additive  */
#line 756 "src/parser/rules.y"
               {}
#line 2308 "src/parser/rules.tab.c"
    break;

  case 96: /* additive: additive PLUS multiplicative  */
#line 760 "src/parser/rules.y"
                                 {}
#line 2314 "src/parser/rules.tab.c"
    break;

  case 97: /* additive: additive MINUS multiplicative  */
#line 761 "src/parser/rules.y"
                                    {}
#line 2320 "src/parser/rules.tab.c"
    break;

  case 98: /* additive: multiplicative  */
#line 762 "src/parser/rules.y"
                     {}
#line 2326 "src/parser/rules.tab.c"
    break;

  case 99: /* multiplicative: multiplicative MULTIPLY tetriary  */
#line 766 "src/parser/rules.y"
                                     {}
#line 2332 "src/parser/rules.tab.c"
    break;

  case 100: /* multiplicative: multiplicative DIVIDE tetriary  */
#line 767 "src/parser/rules.y"
                                     {}
#line 2338 "src/parser/rules.tab.c"
    break;

  case 101: /* multiplicative: multiplicative REMAINDER tetriary  */
#line 768 "src/parser/rules.y"
                                        {}
#line 2344 "src/parser/rules.tab.c"
    break;

  case 102: /* multiplicative: tetriary  */
#line 769 "src/parser/rules.y"
               {}
#line 2350 "src/parser/rules.tab.c"
    break;

  case 103: /* prefix_op: INCREMENT tetriary  */
#line 773 "src/parser/rules.y"
                       {}
#line 2356 "src/parser/rules.tab.c"
    break;

  case 104: /* prefix_op: DECREMENT tetriary  */
#line 774 "src/parser/rules.y"
                         {}
#line 2362 "src/parser/rules.tab.c"
    break;

  case 105: /* prefix_op: LOGICAL_NOT tetriary  */
#line 775 "src/parser/rules.y"
                           {}
#line 2368 "src/parser/rules.tab.c"
    break;

  case 106: /* prefix_op: BITWISE_NOT tetriary  */
#line 776 "src/parser/rules.y"
                           {}
#line 2374 "src/parser/rules.tab.c"
    break;

  case 107: /* cast_op: tetriary CAST  */
#line 780 "src/parser/rules.y"
                  {}
#line 2380 "src/parser/rules.tab.c"
    break;

  case 108: /* address_op: '[' expression ']' tetriary  */
#line 784 "src/parser/rules.y"
                                {}
#line 2386 "src/parser/rules.tab.c"
    break;

  case 109: /* address_op: '[' ']' tetriary  */
#line 785 "src/parser/rules.y"
                       {}
#line 2392 "src/parser/rules.tab.c"
    break;

  case 110: /* sizeof_op: SIZEOF NAME  */
#line 789 "src/parser/rules.y"
                {}
#line 2398 "src/parser/rules.tab.c"
    break;

  case 111: /* tetriary: prefix_op  */
#line 793 "src/parser/rules.y"
              {}
#line 2404 "src/parser/rules.tab.c"
    break;

  case 112: /* tetriary: cast_op  */
#line 794 "src/parser/rules.y"
              {}
#line 2410 "src/parser/rules.tab.c"
    break;

  case 113: /* tetriary: address_op  */
#line 795 "src/parser/rules.y"
                 {}
#line 2416 "src/parser/rules.tab.c"
    break;

  case 114: /* tetriary: sizeof_op  */
#line 796 "src/parser/rules.y"
                {}
#line 2422 "src/parser/rules.tab.c"
    break;

  case 115: /* tetriary: secondary  */
#line 797 "src/parser/rules.y"
                {}
#line 2428 "src/parser/rules.tab.c"
    break;

  case 116: /* suffix_op: secondary INCREMENT  */
#line 801 "src/parser/rules.y"
                        {}
#line 2434 "src/parser/rules.tab.c"
    break;

  case 117: /* suffix_op: secondary DECREMENT  */
#line 802 "src/parser/rules.y"
                          {}
#line 2440 "src/parser/rules.tab.c"
    break;

  case 118: /* dereference_op: secondary '[' expression ']'  */
#line 806 "src/parser/rules.y"
                                 {}
#line 2446 "src/parser/rules.tab.c"
    break;

  case 119: /* dereference_op: secondary '[' ']'  */
#line 807 "src/parser/rules.y"
                        {}
#line 2452 "src/parser/rules.tab.c"
    break;

  case 120: /* layout_access_op: secondary ACCESS NAME  */
#line 811 "src/parser/rules.y"
                          {}
#line 2458 "src/parser/rules.tab.c"
    break;

  case 121: /* secondary: suffix_op  */
#line 815 "src/parser/rules.y"
              {}
#line 2464 "src/parser/rules.tab.c"
    break;

  case 122: /* secondary: dereference_op  */
#line 816 "src/parser/rules.y"
                     {}
#line 2470 "src/parser/rules.tab.c"
    break;

  case 123: /* secondary: layout_access_op  */
#line 817 "src/parser/rules.y"
                       {}
#line 2476 "src/parser/rules.tab.c"
    break;

  case 124: /* secondary: primary  */
#line 818 "src/parser/rules.y"
              {}
#line 2482 "src/parser/rules.tab.c"
    break;

  case 125: /* primary: '(' expression ')'  */
#line 822 "src/parser/rules.y"
                       {}
#line 2488 "src/parser/rules.tab.c"
    break;

  case 126: /* primary: literal  */
#line 823 "src/parser/rules.y"
              {}
#line 2494 "src/parser/rules.tab.c"
    break;

  case 127: /* literal: INT  */
#line 827 "src/parser/rules.y"
        {}
#line 2500 "src/parser/rules.tab.c"
    break;

  case 128: /* literal: UINT  */
#line 828 "src/parser/rules.y"
           {}
#line 2506 "src/parser/rules.tab.c"
    break;

  case 129: /* literal: DOUBLE  */
#line 829 "src/parser/rules.y"
             {}
#line 2512 "src/parser/rules.tab.c"
    break;

  case 130: /* literal: STRING  */
#line 830 "src/parser/rules.y"
             {}
#line 2518 "src/parser/rules.tab.c"
    break;

  case 131: /* literal: NAME  */
#line 831 "src/parser/rules.y"
           {}
#line 2524 "src/parser/rules.tab.c"
    break;


#line 2528 "src/parser/rules.tab.c"

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

#line 840 "src/parser/rules.y"

