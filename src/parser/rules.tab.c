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
  YYSYMBOL_10_m_ = 10,                     /* 'm'  */
  YYSYMBOL_ALIGNMENT_SIMPLE = 11,          /* ALIGNMENT_SIMPLE  */
  YYSYMBOL_TYPE = 12,                      /* TYPE  */
  YYSYMBOL_CHUNK_CLASS_MEM = 13,           /* CHUNK_CLASS_MEM  */
  YYSYMBOL_CHUNK_CLASS_SSE = 14,           /* CHUNK_CLASS_SSE  */
  YYSYMBOL_CHUNK_CLASS_INT = 15,           /* CHUNK_CLASS_INT  */
  YYSYMBOL_CHUNK_CLASS_LAYOUT = 16,        /* CHUNK_CLASS_LAYOUT  */
  YYSYMBOL_GP_REGISTER = 17,               /* GP_REGISTER  */
  YYSYMBOL_REGISTER = 18,                  /* REGISTER  */
  YYSYMBOL_GLOBAL = 19,                    /* GLOBAL  */
  YYSYMBOL_LAYOUT = 20,                    /* LAYOUT  */
  YYSYMBOL_EXTERN = 21,                    /* EXTERN  */
  YYSYMBOL_NASM = 22,                      /* NASM  */
  YYSYMBOL_FN = 23,                        /* FN  */
  YYSYMBOL_NASM_BLOCK = 24,                /* NASM_BLOCK  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_GOTO = 27,                      /* GOTO  */
  YYSYMBOL_LOOP = 28,                      /* LOOP  */
  YYSYMBOL_BREAK = 29,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 30,                  /* CONTINUE  */
  YYSYMBOL_RET = 31,                       /* RET  */
  YYSYMBOL_AVOID = 32,                     /* AVOID  */
  YYSYMBOL_ALIAS = 33,                     /* ALIAS  */
  YYSYMBOL_REG = 34,                       /* REG  */
  YYSYMBOL_LOGICAL_OR = 35,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_AND = 36,               /* LOGICAL_AND  */
  YYSYMBOL_ASSIGN = 37,                    /* "="  */
  YYSYMBOL_INCREMENT = 38,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 39,                 /* DECREMENT  */
  YYSYMBOL_SIZEOF = 40,                    /* SIZEOF  */
  YYSYMBOL_PLUS = 41,                      /* "+"  */
  YYSYMBOL_MINUS = 42,                     /* "-"  */
  YYSYMBOL_MULTIPLY = 43,                  /* "*"  */
  YYSYMBOL_DIVIDE = 44,                    /* "/"  */
  YYSYMBOL_REMAINDER = 45,                 /* "%"  */
  YYSYMBOL_BITWISE_AND = 46,               /* "&"  */
  YYSYMBOL_BITWISE_OR = 47,                /* "|"  */
  YYSYMBOL_BITWISE_XOR = 48,               /* "^"  */
  YYSYMBOL_LOGICAL_NOT = 49,               /* "!"  */
  YYSYMBOL_BITWISE_NOT = 50,               /* "~"  */
  YYSYMBOL_LESS_THEN = 51,                 /* "<"  */
  YYSYMBOL_GREATER_THEN = 52,              /* ">"  */
  YYSYMBOL_LESS_EQUAL = 53,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 54,             /* GREATER_EQUAL  */
  YYSYMBOL_EQUALS = 55,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 56,                /* NOT_EQUALS  */
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
  YYSYMBOL_DOT = 67,                       /* "."  */
  YYSYMBOL_68_ = 68,                       /* '('  */
  YYSYMBOL_69_ = 69,                       /* ')'  */
  YYSYMBOL_70_ = 70,                       /* ':'  */
  YYSYMBOL_71_ = 71,                       /* '{'  */
  YYSYMBOL_72_ = 72,                       /* '}'  */
  YYSYMBOL_73_ = 73,                       /* ','  */
  YYSYMBOL_74_ = 74,                       /* ';'  */
  YYSYMBOL_75_ = 75,                       /* '='  */
  YYSYMBOL_76_ = 76,                       /* '|'  */
  YYSYMBOL_77_ = 77,                       /* '^'  */
  YYSYMBOL_78_ = 78,                       /* '&'  */
  YYSYMBOL_79_ = 79,                       /* '<'  */
  YYSYMBOL_80_ = 80,                       /* '>'  */
  YYSYMBOL_81_ = 81,                       /* '+'  */
  YYSYMBOL_82_ = 82,                       /* '-'  */
  YYSYMBOL_83_ = 83,                       /* '*'  */
  YYSYMBOL_84_ = 84,                       /* '/'  */
  YYSYMBOL_85_ = 85,                       /* '%'  */
  YYSYMBOL_86_ = 86,                       /* '!'  */
  YYSYMBOL_87_ = 87,                       /* '~'  */
  YYSYMBOL_88_ = 88,                       /* '?'  */
  YYSYMBOL_89_ = 89,                       /* '['  */
  YYSYMBOL_90_ = 90,                       /* ']'  */
  YYSYMBOL_91_ = 91,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 92,                  /* $accept  */
  YYSYMBOL_program = 93,                   /* program  */
  YYSYMBOL_visibility = 94,                /* visibility  */
  YYSYMBOL_memory_length = 95,             /* memory_length  */
  YYSYMBOL_alignment = 96,                 /* alignment  */
  YYSYMBOL_global_variable_declaration = 97, /* global_variable_declaration  */
  YYSYMBOL_chunk_class = 98,               /* chunk_class  */
  YYSYMBOL_abi_class = 99,                 /* abi_class  */
  YYSYMBOL_layout_declaration_items = 100, /* layout_declaration_items  */
  YYSYMBOL_layout_declaration = 101,       /* layout_declaration  */
  YYSYMBOL_extern_declaration = 102,       /* extern_declaration  */
  YYSYMBOL_function_declaration_arg = 103, /* function_declaration_arg  */
  YYSYMBOL_function_declaration_args = 104, /* function_declaration_args  */
  YYSYMBOL_function_declaration = 105,     /* function_declaration  */
  YYSYMBOL_nasm_block = 106,               /* nasm_block  */
  YYSYMBOL_body_list = 107,                /* body_list  */
  YYSYMBOL_body = 108,                     /* body  */
  YYSYMBOL_statement = 109,                /* statement  */
  YYSYMBOL_variable_declaration = 110,     /* variable_declaration  */
  YYSYMBOL_register_alias = 111,           /* register_alias  */
  YYSYMBOL_if_statement = 112,             /* if_statement  */
  YYSYMBOL_label_declaration = 113,        /* label_declaration  */
  YYSYMBOL_goto_statement = 114,           /* goto_statement  */
  YYSYMBOL_loop_statement = 115,           /* loop_statement  */
  YYSYMBOL_break_statement = 116,          /* break_statement  */
  YYSYMBOL_ret_statement = 117,            /* ret_statement  */
  YYSYMBOL_avoid_block_regs = 118,         /* avoid_block_regs  */
  YYSYMBOL_avoid_block = 119,              /* avoid_block  */
  YYSYMBOL_operand_type = 120,             /* operand_type  */
  YYSYMBOL_expression = 121,               /* expression  */
  YYSYMBOL_logical_or = 122,               /* logical_or  */
  YYSYMBOL_logical_and = 123,              /* logical_and  */
  YYSYMBOL_bitwise_or = 124,               /* bitwise_or  */
  YYSYMBOL_bitwise_xor = 125,              /* bitwise_xor  */
  YYSYMBOL_bitwise_and = 126,              /* bitwise_and  */
  YYSYMBOL_equality = 127,                 /* equality  */
  YYSYMBOL_relational = 128,               /* relational  */
  YYSYMBOL_additive = 129,                 /* additive  */
  YYSYMBOL_multiplicative = 130,           /* multiplicative  */
  YYSYMBOL_prefix_op = 131,                /* prefix_op  */
  YYSYMBOL_cast_op = 132,                  /* cast_op  */
  YYSYMBOL_address_op = 133,               /* address_op  */
  YYSYMBOL_sizeof_op = 134,                /* sizeof_op  */
  YYSYMBOL_tetriary = 135,                 /* tetriary  */
  YYSYMBOL_suffix_op = 136,                /* suffix_op  */
  YYSYMBOL_dereference_op = 137,           /* dereference_op  */
  YYSYMBOL_layout_access_op = 138,         /* layout_access_op  */
  YYSYMBOL_secondary = 139,                /* secondary  */
  YYSYMBOL_primary = 140,                  /* primary  */
  YYSYMBOL_literal = 141                   /* literal  */
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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

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
       2,     2,     2,    86,     2,     2,     2,    85,    78,     2,
      68,    69,    83,    81,    73,    82,    91,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    70,    74,
      79,    75,    80,    88,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,    90,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    10,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    76,    72,    87,     2,     2,     2,
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
       5,     6,     7,     8,     9,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   181,   181,   182,   183,   184,   185,   186,   190,   194,
     195,   199,   203,   204,   205,   206,   210,   211,   212,   216,
     217,   221,   222,   226,   227,   228,   232,   233,   237,   238,
     239,   240,   241,   242,   243,   244,   248,   249,   253,   254,
     255,   256,   257,   258,   259,   260,   265,   269,   270,   274,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   293,   294,   298,   299,   303,   304,   308,   312,
     316,   320,   321,   325,   329,   330,   334,   338,   339,   343,
     344,   348,   349,   353,   354,   358,   359,   363,   364,   368,
     369,   373,   374,   375,   379,   380,   381,   382,   383,   387,
     388,   389,   393,   394,   395,   396,   400,   401,   402,   403,
     407,   411,   412,   416,   420,   421,   422,   423,   424,   428,
     429,   433,   434,   438,   442,   443,   444,   445,   449,   450,
     454,   455,   456,   457,   458
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
  "'m'", "ALIGNMENT_SIMPLE", "TYPE", "CHUNK_CLASS_MEM", "CHUNK_CLASS_SSE",
  "CHUNK_CLASS_INT", "CHUNK_CLASS_LAYOUT", "GP_REGISTER", "REGISTER",
  "GLOBAL", "LAYOUT", "EXTERN", "NASM", "FN", "NASM_BLOCK", "IF", "ELSE",
  "GOTO", "LOOP", "BREAK", "CONTINUE", "RET", "AVOID", "ALIAS", "REG",
  "LOGICAL_OR", "LOGICAL_AND", "\"=\"", "INCREMENT", "DECREMENT", "SIZEOF",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\"&\"", "\"|\"", "\"^\"",
  "\"!\"", "\"~\"", "\"<\"", "\">\"", "LESS_EQUAL", "GREATER_EQUAL",
  "EQUALS", "NOT_EQUALS", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"",
  "\"}\"", "ARROW", "\":\"", "\";\"", "\",\"", "\".\"", "'('", "')'",
  "':'", "'{'", "'}'", "','", "';'", "'='", "'|'", "'^'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "'?'", "'['",
  "']'", "'.'", "$accept", "program", "visibility", "memory_length",
  "alignment", "global_variable_declaration", "chunk_class", "abi_class",
  "layout_declaration_items", "layout_declaration", "extern_declaration",
  "function_declaration_arg", "function_declaration_args",
  "function_declaration", "nasm_block", "body_list", "body", "statement",
  "variable_declaration", "register_alias", "if_statement",
  "label_declaration", "goto_statement", "loop_statement",
  "break_statement", "ret_statement", "avoid_block_regs", "avoid_block",
  "operand_type", "expression", "logical_or", "logical_and", "bitwise_or",
  "bitwise_xor", "bitwise_and", "equality", "relational", "additive",
  "multiplicative", "prefix_op", "cast_op", "address_op", "sizeof_op",
  "tetriary", "suffix_op", "dereference_op", "layout_access_op",
  "secondary", "primary", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -95,   175,   -95,   -30,    42,    48,   -95,   -95,   -95,   -95,
     -95,   -95,   162,   -95,   -95,   -95,   -14,   -95,    -3,    12,
      10,    63,    47,   -95,   -95,   -95,    79,   129,   116,    57,
      63,   -95,   -95,   124,    75,    -1,    79,   106,   109,   -95,
       6,   116,   -95,   114,   154,   125,   -95,     1,    79,   260,
     -11,   116,   107,   -95,   -95,   154,   -95,     4,   -95,   173,
     177,   -95,   -95,   269,   -95,   -95,   -95,     7,   -95,   -95,
     177,   -95,   -95,    50,   127,   222,   269,   -95,   -95,   127,
     -95,   -95,   131,   -95,   -95,   -95,   -95,   227,   200,   127,
     140,   145,   227,   204,   105,   105,   238,   227,   -95,   105,
     105,   126,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   168,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   -95,   -95,   -95,   -95,   105,   -95,
     -95,   -95,    27,   -95,   -95,    50,   127,   -95,    39,   -95,
     127,   171,   -95,   -95,   -95,   174,   -95,   -57,   -95,   -95,
     227,   227,   -95,   186,   227,   227,   227,   166,   -95,   -26,
     221,   182,   187,   181,   150,   -22,   136,     9,   184,   172,
     134,   169,   127,   -95,   -95,     3,    63,   244,   -95,   -95,
     261,   -95,   105,   105,   -95,   105,   105,   105,   227,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   277,   -95,   191,
     -95,   -95,   -95,   -95,   -95,   -95,   127,   -95,   105,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   -95,   -95,   -95,   -95,
     105,   -95,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105
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
      39,    40,   134,   130,   131,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,    52,    61,    47,    50,    51,    53,    54,    55,
      56,    57,    58,    59,     0,    80,    82,    84,    86,    88,
      90,    93,    98,   101,   114,   115,   116,   117,   105,   124,
     125,   126,   118,   127,   129,     0,     0,    41,    68,   134,
       0,     0,    70,    71,    72,     0,    75,     0,    77,    78,
       0,     0,   113,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    44,     0,    62,    66,    69,    73,
       0,    76,   106,   107,   128,   108,   109,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
     119,   120,    45,    65,    64,    63,     0,    74,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   123,   121,    67,
      81,    79,    83,    85,    87,    89,    91,    92,    96,    97,
      94,    95,    99,   100,   102,   103,   104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,    71,   -15,   -95,    23,   -17,    33,   -95,
     211,   236,   247,   -95,   214,   -95,   -12,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -94,   -84,
     -95,    72,    76,    70,    73,    69,    14,     8,   -21,   -95,
     -95,   -95,   -95,   -66,   -95,   -95,   -95,   -95,   -95,   -95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    20,   149,    32,     7,    61,    62,    35,     8,
       9,    39,    40,    10,    11,    75,    65,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   147,   113,   168,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     150,   151,    45,   140,    45,   154,   155,    45,   145,   189,
      23,    24,    25,   153,    64,    42,   180,   157,    15,    16,
     213,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     169,   197,   198,    29,    60,    15,    16,   214,   171,   148,
      12,    27,    71,    72,    70,    13,    74,    15,    16,   190,
      37,    14,    63,    78,    22,    77,    79,   199,   200,   136,
      64,    80,    81,    23,    24,    25,    58,   137,    26,    47,
      76,    46,   175,    56,    31,    50,    69,   142,    64,    51,
      28,    57,    34,    21,   182,   183,   209,    33,   185,   186,
     187,    30,   203,   204,   205,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    15,    16,    54,   170,   148,   172,    38,
      59,    64,   218,   173,   174,    41,    68,    43,   177,   139,
      83,    84,    85,    86,    73,   181,   241,   139,    83,    84,
      85,    86,    23,    24,    25,    44,   160,   135,   161,   162,
     163,   164,   165,   165,   166,   166,   166,   166,   167,   167,
     212,   215,    15,    16,    94,    95,    96,   254,   255,   256,
      15,    16,    94,    95,    96,     2,    67,    48,     3,    49,
      51,    17,    18,    53,    31,    19,    23,    24,    25,    58,
      23,    24,    25,    58,    97,    55,     4,     5,    64,     6,
      36,   138,    97,   141,   239,   195,   196,   210,   211,   176,
     252,   253,    99,   100,   143,   101,   156,   201,   202,   144,
      99,   100,   146,   101,   208,    82,    83,    84,    85,    86,
     139,    83,    84,    85,    86,   248,   249,   250,   251,   246,
     247,   152,   158,     4,     5,   178,     6,    87,   179,    88,
      89,    90,    91,    92,    93,   184,   188,   191,   192,   194,
      94,    95,    96,   207,   193,    94,    95,    96,    15,    16,
     216,    31,   206,    23,    24,    25,    58,    15,    16,   217,
     237,   238,    23,    24,    25,    58,   102,    66,    52,   103,
      97,   240,   243,   245,    98,    97,   244,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
       0,   101,     0,    99,   100,     0,   101
};

static const yytype_int16 yycheck[] =
{
      94,    95,     3,    87,     3,    99,   100,     3,    92,    35,
      13,    14,    15,    97,    71,    30,    73,   101,     8,     9,
      17,   115,   116,   117,   118,   119,   120,   121,   122,   123,
       3,    53,    54,    23,    49,     8,     9,    34,   132,    12,
      70,    18,    59,    60,    59,     3,    63,     8,     9,    75,
      27,     3,    63,    70,    68,    67,    73,    79,    80,    76,
      71,    73,    74,    13,    14,    15,    16,    79,    71,    36,
      63,    72,    33,    72,    11,    69,    72,    89,    71,    73,
      68,    48,     3,    12,   150,   151,   170,    40,   154,   155,
     156,    20,    83,    84,    85,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,     8,     9,    44,    89,    12,   135,     3,
      49,    71,   188,   135,   136,    68,    55,     3,   140,     3,
       4,     5,     6,     7,    63,   147,   220,     3,     4,     5,
       6,     7,    13,    14,    15,    70,   240,    76,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     172,   176,     8,     9,    38,    39,    40,   233,   234,   235,
       8,     9,    38,    39,    40,     0,    69,    71,     3,    70,
      73,    19,    20,    69,    11,    23,    13,    14,    15,    16,
      13,    14,    15,    16,    68,    70,    21,    22,    71,    24,
      71,    70,    68,     3,   216,    55,    56,    38,    39,   138,
     231,   232,    86,    87,    74,    89,    90,    81,    82,    74,
      86,    87,    18,    89,    90,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,   227,   228,   229,   230,   225,
     226,     3,    74,    21,    22,    74,    24,    25,    74,    27,
      28,    29,    30,    31,    32,    69,    90,    36,    76,    78,
      38,    39,    40,    91,    77,    38,    39,    40,     8,     9,
      26,    11,    88,    13,    14,    15,    16,     8,     9,    18,
       3,    90,    13,    14,    15,    16,    75,    51,    41,    75,
      68,   219,   222,   224,    72,    68,   223,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    89,    -1,    86,    87,    -1,    89
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    93,     0,     3,    21,    22,    24,    97,   101,   102,
     105,   106,    70,     3,     3,     8,     9,    19,    20,    23,
      94,    95,    68,    13,    14,    15,    71,    98,    68,    23,
      95,    11,    96,    40,     3,   100,    71,    98,     3,   103,
     104,    68,    96,     3,    70,     3,    72,   100,    71,    70,
      69,    73,   104,    69,    95,    70,    72,   100,    16,    95,
      96,    98,    99,    63,    71,   108,   103,    69,    95,    72,
      96,    99,    99,    95,    99,   107,    63,   108,    99,    99,
     108,   108,     3,     4,     5,     6,     7,    25,    27,    28,
      29,    30,    31,    32,    38,    39,    40,    68,    72,    86,
      87,    89,   102,   106,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   119,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    95,    99,   108,    70,     3,
     121,     3,   108,    74,    74,   121,    18,   118,    12,    95,
     120,   120,     3,   121,   120,   120,    90,   121,    74,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,     3,
      89,   120,    99,   108,   108,    33,    95,   108,    74,    74,
      73,   108,   135,   135,    69,   135,   135,   135,    90,    35,
      75,    36,    76,    77,    78,    55,    56,    53,    54,    79,
      80,    81,    82,    83,    84,    85,    88,    91,    90,   121,
      38,    39,   108,    17,    34,    96,    26,    18,   135,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,     3,    90,   108,
     123,   121,   124,   125,   126,   127,   128,   128,   129,   129,
     129,   129,   130,   130,   135,   135,   135
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    93,    93,    93,    93,    94,    95,
      95,    96,    97,    97,    97,    97,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   102,   102,   103,   103,
     103,   103,   103,   103,   103,   103,   104,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   106,   107,   107,   108,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   114,
     115,   116,   116,   117,   118,   118,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   127,   128,   128,   128,   128,   128,   129,
     129,   129,   130,   130,   130,   130,   131,   131,   131,   131,
     132,   133,   133,   134,   135,   135,   135,   135,   135,   136,
     136,   137,   137,   138,   139,   139,   139,   139,   140,   140,
     141,   141,   141,   141,   141
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
       2,     2,     2,     3,     3,     1,     3,     1,     1,     5,
       1,     5,     1,     5,     1,     5,     1,     5,     1,     5,
       1,     5,     5,     1,     5,     5,     5,     5,     1,     5,
       5,     1,     5,     5,     5,     1,     3,     3,     3,     3,
       4,     4,     3,     2,     1,     1,     1,     1,     1,     3,
       3,     4,     3,     4,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1
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
#line 181 "src/parser/rules.y"
                                        {}
#line 1410 "src/parser/rules.tab.c"
    break;

  case 3: /* program: program layout_declaration  */
#line 182 "src/parser/rules.y"
                                 {}
#line 1416 "src/parser/rules.tab.c"
    break;

  case 4: /* program: program extern_declaration  */
#line 183 "src/parser/rules.y"
                                 {}
#line 1422 "src/parser/rules.tab.c"
    break;

  case 5: /* program: program function_declaration  */
#line 184 "src/parser/rules.y"
                                   {}
#line 1428 "src/parser/rules.tab.c"
    break;

  case 6: /* program: program nasm_block  */
#line 185 "src/parser/rules.y"
                         {}
#line 1434 "src/parser/rules.tab.c"
    break;

  case 7: /* program: %empty  */
#line 186 "src/parser/rules.y"
      {}
#line 1440 "src/parser/rules.tab.c"
    break;

  case 8: /* visibility: GLOBAL  */
#line 190 "src/parser/rules.y"
           {}
#line 1446 "src/parser/rules.tab.c"
    break;

  case 9: /* memory_length: MEMORY_LENGTH_SIMPLE  */
#line 194 "src/parser/rules.y"
                         {}
#line 1452 "src/parser/rules.tab.c"
    break;

  case 10: /* memory_length: MEMORY_LENGTH_PREFIX '(' SIZEOF NAME ')'  */
#line 195 "src/parser/rules.y"
                                               {}
#line 1458 "src/parser/rules.tab.c"
    break;

  case 11: /* alignment: ALIGNMENT_SIMPLE  */
#line 199 "src/parser/rules.y"
                     {}
#line 1464 "src/parser/rules.tab.c"
    break;

  case 12: /* global_variable_declaration: NAME ':' memory_length  */
#line 203 "src/parser/rules.y"
                           {}
#line 1470 "src/parser/rules.tab.c"
    break;

  case 13: /* global_variable_declaration: NAME ':' visibility memory_length  */
#line 204 "src/parser/rules.y"
                                        {}
#line 1476 "src/parser/rules.tab.c"
    break;

  case 14: /* global_variable_declaration: NAME ':' memory_length alignment  */
#line 205 "src/parser/rules.y"
                                       {}
#line 1482 "src/parser/rules.tab.c"
    break;

  case 15: /* global_variable_declaration: NAME ':' visibility memory_length alignment  */
#line 206 "src/parser/rules.y"
                                                  {}
#line 1488 "src/parser/rules.tab.c"
    break;

  case 16: /* chunk_class: CHUNK_CLASS_MEM  */
#line 210 "src/parser/rules.y"
                    {}
#line 1494 "src/parser/rules.tab.c"
    break;

  case 17: /* chunk_class: CHUNK_CLASS_SSE  */
#line 211 "src/parser/rules.y"
                      {}
#line 1500 "src/parser/rules.tab.c"
    break;

  case 18: /* chunk_class: CHUNK_CLASS_INT  */
#line 212 "src/parser/rules.y"
                      {}
#line 1506 "src/parser/rules.tab.c"
    break;

  case 19: /* abi_class: chunk_class  */
#line 216 "src/parser/rules.y"
                {}
#line 1512 "src/parser/rules.tab.c"
    break;

  case 20: /* abi_class: CHUNK_CLASS_LAYOUT  */
#line 217 "src/parser/rules.y"
                         {}
#line 1518 "src/parser/rules.tab.c"
    break;

  case 21: /* layout_declaration_items: layout_declaration_items NAME ':' memory_length  */
#line 221 "src/parser/rules.y"
                                                    {}
#line 1524 "src/parser/rules.tab.c"
    break;

  case 22: /* layout_declaration_items: NAME ':' memory_length  */
#line 222 "src/parser/rules.y"
                             {}
#line 1530 "src/parser/rules.tab.c"
    break;

  case 23: /* layout_declaration: NAME ':' LAYOUT '{' layout_declaration_items '}'  */
#line 226 "src/parser/rules.y"
                                                     {}
#line 1536 "src/parser/rules.tab.c"
    break;

  case 24: /* layout_declaration: NAME ':' LAYOUT chunk_class '{' layout_declaration_items '}'  */
#line 227 "src/parser/rules.y"
                                                                   {}
#line 1542 "src/parser/rules.tab.c"
    break;

  case 25: /* layout_declaration: NAME ':' LAYOUT chunk_class chunk_class '{' layout_declaration_items '}'  */
#line 228 "src/parser/rules.y"
                                                                               {}
#line 1548 "src/parser/rules.tab.c"
    break;

  case 26: /* extern_declaration: EXTERN NAME  */
#line 232 "src/parser/rules.y"
                {}
#line 1554 "src/parser/rules.tab.c"
    break;

  case 27: /* extern_declaration: NASM NAME  */
#line 233 "src/parser/rules.y"
                {}
#line 1560 "src/parser/rules.tab.c"
    break;

  case 28: /* function_declaration_arg: NAME  */
#line 237 "src/parser/rules.y"
         {}
#line 1566 "src/parser/rules.tab.c"
    break;

  case 29: /* function_declaration_arg: NAME ':' memory_length  */
#line 238 "src/parser/rules.y"
                             {}
#line 1572 "src/parser/rules.tab.c"
    break;

  case 30: /* function_declaration_arg: NAME ':' alignment  */
#line 239 "src/parser/rules.y"
                         {}
#line 1578 "src/parser/rules.tab.c"
    break;

  case 31: /* function_declaration_arg: NAME ':' abi_class  */
#line 240 "src/parser/rules.y"
                         {}
#line 1584 "src/parser/rules.tab.c"
    break;

  case 32: /* function_declaration_arg: NAME ':' memory_length alignment  */
#line 241 "src/parser/rules.y"
                                       {}
#line 1590 "src/parser/rules.tab.c"
    break;

  case 33: /* function_declaration_arg: NAME ':' memory_length abi_class  */
#line 242 "src/parser/rules.y"
                                       {}
#line 1596 "src/parser/rules.tab.c"
    break;

  case 34: /* function_declaration_arg: NAME ':' alignment abi_class  */
#line 243 "src/parser/rules.y"
                                   {}
#line 1602 "src/parser/rules.tab.c"
    break;

  case 35: /* function_declaration_arg: NAME ':' memory_length alignment abi_class  */
#line 244 "src/parser/rules.y"
                                                 {}
#line 1608 "src/parser/rules.tab.c"
    break;

  case 36: /* function_declaration_args: function_declaration_args ',' function_declaration_arg  */
#line 248 "src/parser/rules.y"
                                                           {}
#line 1614 "src/parser/rules.tab.c"
    break;

  case 37: /* function_declaration_args: function_declaration_arg  */
#line 249 "src/parser/rules.y"
                               {}
#line 1620 "src/parser/rules.tab.c"
    break;

  case 38: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' body  */
#line 253 "src/parser/rules.y"
                                                       {}
#line 1626 "src/parser/rules.tab.c"
    break;

  case 39: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' ARROW memory_length body  */
#line 254 "src/parser/rules.y"
                                                                             {}
#line 1632 "src/parser/rules.tab.c"
    break;

  case 40: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' ARROW abi_class body  */
#line 255 "src/parser/rules.y"
                                                                         {}
#line 1638 "src/parser/rules.tab.c"
    break;

  case 41: /* function_declaration: NAME ':' FN '(' function_declaration_args ')' ARROW memory_length abi_class body  */
#line 256 "src/parser/rules.y"
                                                                                       {}
#line 1644 "src/parser/rules.tab.c"
    break;

  case 42: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' body  */
#line 257 "src/parser/rules.y"
                                                                    {}
#line 1650 "src/parser/rules.tab.c"
    break;

  case 43: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' ARROW memory_length body  */
#line 258 "src/parser/rules.y"
                                                                                        {}
#line 1656 "src/parser/rules.tab.c"
    break;

  case 44: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' ARROW abi_class body  */
#line 259 "src/parser/rules.y"
                                                                                    {}
#line 1662 "src/parser/rules.tab.c"
    break;

  case 45: /* function_declaration: NAME ':' visibility FN '(' function_declaration_args ')' ARROW memory_length abi_class body  */
#line 261 "src/parser/rules.y"
               {}
#line 1668 "src/parser/rules.tab.c"
    break;

  case 46: /* nasm_block: NASM_BLOCK  */
#line 265 "src/parser/rules.y"
               {}
#line 1674 "src/parser/rules.tab.c"
    break;

  case 47: /* body_list: body_list statement  */
#line 269 "src/parser/rules.y"
                        {}
#line 1680 "src/parser/rules.tab.c"
    break;

  case 48: /* body_list: %empty  */
#line 270 "src/parser/rules.y"
      {}
#line 1686 "src/parser/rules.tab.c"
    break;

  case 49: /* body: '{' body_list '}'  */
#line 274 "src/parser/rules.y"
                      {}
#line 1692 "src/parser/rules.tab.c"
    break;

  case 50: /* statement: variable_declaration  */
#line 278 "src/parser/rules.y"
                         {}
#line 1698 "src/parser/rules.tab.c"
    break;

  case 51: /* statement: register_alias  */
#line 279 "src/parser/rules.y"
                     {}
#line 1704 "src/parser/rules.tab.c"
    break;

  case 52: /* statement: extern_declaration  */
#line 280 "src/parser/rules.y"
                         {}
#line 1710 "src/parser/rules.tab.c"
    break;

  case 53: /* statement: if_statement  */
#line 281 "src/parser/rules.y"
                   {}
#line 1716 "src/parser/rules.tab.c"
    break;

  case 54: /* statement: label_declaration  */
#line 282 "src/parser/rules.y"
                        {}
#line 1722 "src/parser/rules.tab.c"
    break;

  case 55: /* statement: goto_statement  */
#line 283 "src/parser/rules.y"
                     {}
#line 1728 "src/parser/rules.tab.c"
    break;

  case 56: /* statement: loop_statement  */
#line 284 "src/parser/rules.y"
                     {}
#line 1734 "src/parser/rules.tab.c"
    break;

  case 57: /* statement: break_statement  */
#line 285 "src/parser/rules.y"
                      {}
#line 1740 "src/parser/rules.tab.c"
    break;

  case 58: /* statement: ret_statement  */
#line 286 "src/parser/rules.y"
                    {}
#line 1746 "src/parser/rules.tab.c"
    break;

  case 59: /* statement: avoid_block  */
#line 287 "src/parser/rules.y"
                  {}
#line 1752 "src/parser/rules.tab.c"
    break;

  case 60: /* statement: expression ';'  */
#line 288 "src/parser/rules.y"
                     {}
#line 1758 "src/parser/rules.tab.c"
    break;

  case 61: /* statement: nasm_block  */
#line 289 "src/parser/rules.y"
                 {}
#line 1764 "src/parser/rules.tab.c"
    break;

  case 62: /* variable_declaration: NAME ':' memory_length  */
#line 293 "src/parser/rules.y"
                           {}
#line 1770 "src/parser/rules.tab.c"
    break;

  case 63: /* variable_declaration: NAME ':' memory_length alignment  */
#line 294 "src/parser/rules.y"
                                       {}
#line 1776 "src/parser/rules.tab.c"
    break;

  case 64: /* register_alias: NAME ':' ALIAS REG  */
#line 298 "src/parser/rules.y"
                       {}
#line 1782 "src/parser/rules.tab.c"
    break;

  case 65: /* register_alias: NAME ':' ALIAS GP_REGISTER  */
#line 299 "src/parser/rules.y"
                                 {}
#line 1788 "src/parser/rules.tab.c"
    break;

  case 66: /* if_statement: IF expression body  */
#line 303 "src/parser/rules.y"
                       {}
#line 1794 "src/parser/rules.tab.c"
    break;

  case 67: /* if_statement: IF expression body ELSE body  */
#line 304 "src/parser/rules.y"
                                 {}
#line 1800 "src/parser/rules.tab.c"
    break;

  case 68: /* label_declaration: NAME ':'  */
#line 308 "src/parser/rules.y"
             {}
#line 1806 "src/parser/rules.tab.c"
    break;

  case 69: /* goto_statement: GOTO NAME ';'  */
#line 312 "src/parser/rules.y"
                  {}
#line 1812 "src/parser/rules.tab.c"
    break;

  case 70: /* loop_statement: LOOP body  */
#line 316 "src/parser/rules.y"
              {}
#line 1818 "src/parser/rules.tab.c"
    break;

  case 71: /* break_statement: BREAK ';'  */
#line 320 "src/parser/rules.y"
              {}
#line 1824 "src/parser/rules.tab.c"
    break;

  case 72: /* break_statement: CONTINUE ';'  */
#line 321 "src/parser/rules.y"
                   {}
#line 1830 "src/parser/rules.tab.c"
    break;

  case 73: /* ret_statement: RET expression ';'  */
#line 325 "src/parser/rules.y"
                       {}
#line 1836 "src/parser/rules.tab.c"
    break;

  case 74: /* avoid_block_regs: avoid_block_regs ',' REGISTER  */
#line 329 "src/parser/rules.y"
                                  {}
#line 1842 "src/parser/rules.tab.c"
    break;

  case 75: /* avoid_block_regs: REGISTER  */
#line 330 "src/parser/rules.y"
               {}
#line 1848 "src/parser/rules.tab.c"
    break;

  case 76: /* avoid_block: AVOID avoid_block_regs body  */
#line 334 "src/parser/rules.y"
                                {}
#line 1854 "src/parser/rules.tab.c"
    break;

  case 77: /* operand_type: TYPE  */
#line 338 "src/parser/rules.y"
         {}
#line 1860 "src/parser/rules.tab.c"
    break;

  case 78: /* operand_type: memory_length  */
#line 339 "src/parser/rules.y"
                    {}
#line 1866 "src/parser/rules.tab.c"
    break;

  case 79: /* expression: logical_or operand_type '=' operand_type expression  */
#line 343 "src/parser/rules.y"
                                                        {}
#line 1872 "src/parser/rules.tab.c"
    break;

  case 80: /* expression: logical_or  */
#line 344 "src/parser/rules.y"
                 {}
#line 1878 "src/parser/rules.tab.c"
    break;

  case 81: /* logical_or: logical_or operand_type LOGICAL_OR operand_type logical_and  */
#line 348 "src/parser/rules.y"
                                                                {}
#line 1884 "src/parser/rules.tab.c"
    break;

  case 82: /* logical_or: logical_and  */
#line 349 "src/parser/rules.y"
                  {}
#line 1890 "src/parser/rules.tab.c"
    break;

  case 83: /* logical_and: logical_and operand_type LOGICAL_AND operand_type bitwise_or  */
#line 353 "src/parser/rules.y"
                                                                 {}
#line 1896 "src/parser/rules.tab.c"
    break;

  case 84: /* logical_and: bitwise_or  */
#line 354 "src/parser/rules.y"
                 {}
#line 1902 "src/parser/rules.tab.c"
    break;

  case 85: /* bitwise_or: bitwise_or operand_type '|' operand_type bitwise_xor  */
#line 358 "src/parser/rules.y"
                                                         {}
#line 1908 "src/parser/rules.tab.c"
    break;

  case 86: /* bitwise_or: bitwise_xor  */
#line 359 "src/parser/rules.y"
                  {}
#line 1914 "src/parser/rules.tab.c"
    break;

  case 87: /* bitwise_xor: bitwise_xor operand_type '^' operand_type bitwise_and  */
#line 363 "src/parser/rules.y"
                                                          {}
#line 1920 "src/parser/rules.tab.c"
    break;

  case 88: /* bitwise_xor: bitwise_and  */
#line 364 "src/parser/rules.y"
                  {}
#line 1926 "src/parser/rules.tab.c"
    break;

  case 89: /* bitwise_and: bitwise_and operand_type '&' operand_type equality  */
#line 368 "src/parser/rules.y"
                                                       {}
#line 1932 "src/parser/rules.tab.c"
    break;

  case 90: /* bitwise_and: equality  */
#line 369 "src/parser/rules.y"
               {}
#line 1938 "src/parser/rules.tab.c"
    break;

  case 91: /* equality: equality operand_type EQUALS operand_type relational  */
#line 373 "src/parser/rules.y"
                                                         {}
#line 1944 "src/parser/rules.tab.c"
    break;

  case 92: /* equality: equality operand_type NOT_EQUALS operand_type relational  */
#line 374 "src/parser/rules.y"
                                                               {}
#line 1950 "src/parser/rules.tab.c"
    break;

  case 93: /* equality: relational  */
#line 375 "src/parser/rules.y"
                 {}
#line 1956 "src/parser/rules.tab.c"
    break;

  case 94: /* relational: relational operand_type '<' operand_type additive  */
#line 379 "src/parser/rules.y"
                                                      {}
#line 1962 "src/parser/rules.tab.c"
    break;

  case 95: /* relational: relational operand_type '>' operand_type additive  */
#line 380 "src/parser/rules.y"
                                                        {}
#line 1968 "src/parser/rules.tab.c"
    break;

  case 96: /* relational: relational operand_type LESS_EQUAL operand_type additive  */
#line 381 "src/parser/rules.y"
                                                               {}
#line 1974 "src/parser/rules.tab.c"
    break;

  case 97: /* relational: relational operand_type GREATER_EQUAL operand_type additive  */
#line 382 "src/parser/rules.y"
                                                                  {}
#line 1980 "src/parser/rules.tab.c"
    break;

  case 98: /* relational: additive  */
#line 383 "src/parser/rules.y"
               {}
#line 1986 "src/parser/rules.tab.c"
    break;

  case 99: /* additive: additive operand_type '+' operand_type multiplicative  */
#line 387 "src/parser/rules.y"
                                                          {}
#line 1992 "src/parser/rules.tab.c"
    break;

  case 100: /* additive: additive operand_type '-' operand_type multiplicative  */
#line 388 "src/parser/rules.y"
                                                            {}
#line 1998 "src/parser/rules.tab.c"
    break;

  case 101: /* additive: multiplicative  */
#line 389 "src/parser/rules.y"
                     {}
#line 2004 "src/parser/rules.tab.c"
    break;

  case 102: /* multiplicative: multiplicative operand_type '*' operand_type tetriary  */
#line 393 "src/parser/rules.y"
                                                          {}
#line 2010 "src/parser/rules.tab.c"
    break;

  case 103: /* multiplicative: multiplicative operand_type '/' operand_type tetriary  */
#line 394 "src/parser/rules.y"
                                                            {}
#line 2016 "src/parser/rules.tab.c"
    break;

  case 104: /* multiplicative: multiplicative operand_type '%' operand_type tetriary  */
#line 395 "src/parser/rules.y"
                                                            {}
#line 2022 "src/parser/rules.tab.c"
    break;

  case 105: /* multiplicative: tetriary  */
#line 396 "src/parser/rules.y"
               {}
#line 2028 "src/parser/rules.tab.c"
    break;

  case 106: /* prefix_op: INCREMENT operand_type tetriary  */
#line 400 "src/parser/rules.y"
                                    {}
#line 2034 "src/parser/rules.tab.c"
    break;

  case 107: /* prefix_op: DECREMENT operand_type tetriary  */
#line 401 "src/parser/rules.y"
                                      {}
#line 2040 "src/parser/rules.tab.c"
    break;

  case 108: /* prefix_op: '!' operand_type tetriary  */
#line 402 "src/parser/rules.y"
                                {}
#line 2046 "src/parser/rules.tab.c"
    break;

  case 109: /* prefix_op: '~' operand_type tetriary  */
#line 403 "src/parser/rules.y"
                                {}
#line 2052 "src/parser/rules.tab.c"
    break;

  case 110: /* cast_op: tetriary operand_type '?' operand_type  */
#line 407 "src/parser/rules.y"
                                           {}
#line 2058 "src/parser/rules.tab.c"
    break;

  case 111: /* address_op: '[' expression ']' tetriary  */
#line 411 "src/parser/rules.y"
                                {}
#line 2064 "src/parser/rules.tab.c"
    break;

  case 112: /* address_op: '[' ']' tetriary  */
#line 412 "src/parser/rules.y"
                       {}
#line 2070 "src/parser/rules.tab.c"
    break;

  case 113: /* sizeof_op: SIZEOF NAME  */
#line 416 "src/parser/rules.y"
                {}
#line 2076 "src/parser/rules.tab.c"
    break;

  case 114: /* tetriary: prefix_op  */
#line 420 "src/parser/rules.y"
              {}
#line 2082 "src/parser/rules.tab.c"
    break;

  case 115: /* tetriary: cast_op  */
#line 421 "src/parser/rules.y"
              {}
#line 2088 "src/parser/rules.tab.c"
    break;

  case 116: /* tetriary: address_op  */
#line 422 "src/parser/rules.y"
                 {}
#line 2094 "src/parser/rules.tab.c"
    break;

  case 117: /* tetriary: sizeof_op  */
#line 423 "src/parser/rules.y"
                {}
#line 2100 "src/parser/rules.tab.c"
    break;

  case 118: /* tetriary: secondary  */
#line 424 "src/parser/rules.y"
                {}
#line 2106 "src/parser/rules.tab.c"
    break;

  case 119: /* suffix_op: secondary operand_type INCREMENT  */
#line 428 "src/parser/rules.y"
                                     {}
#line 2112 "src/parser/rules.tab.c"
    break;

  case 120: /* suffix_op: secondary operand_type DECREMENT  */
#line 429 "src/parser/rules.y"
                                       {}
#line 2118 "src/parser/rules.tab.c"
    break;

  case 121: /* dereference_op: secondary '[' expression ']'  */
#line 433 "src/parser/rules.y"
                                 {}
#line 2124 "src/parser/rules.tab.c"
    break;

  case 122: /* dereference_op: secondary '[' ']'  */
#line 434 "src/parser/rules.y"
                        {}
#line 2130 "src/parser/rules.tab.c"
    break;

  case 123: /* layout_access_op: secondary NAME '.' NAME  */
#line 438 "src/parser/rules.y"
                            {}
#line 2136 "src/parser/rules.tab.c"
    break;

  case 124: /* secondary: suffix_op  */
#line 442 "src/parser/rules.y"
              {}
#line 2142 "src/parser/rules.tab.c"
    break;

  case 125: /* secondary: dereference_op  */
#line 443 "src/parser/rules.y"
                     {}
#line 2148 "src/parser/rules.tab.c"
    break;

  case 126: /* secondary: layout_access_op  */
#line 444 "src/parser/rules.y"
                       {}
#line 2154 "src/parser/rules.tab.c"
    break;

  case 127: /* secondary: primary  */
#line 445 "src/parser/rules.y"
              {}
#line 2160 "src/parser/rules.tab.c"
    break;

  case 128: /* primary: '(' expression ')'  */
#line 449 "src/parser/rules.y"
                       {}
#line 2166 "src/parser/rules.tab.c"
    break;

  case 129: /* primary: literal  */
#line 450 "src/parser/rules.y"
              {}
#line 2172 "src/parser/rules.tab.c"
    break;

  case 130: /* literal: INT  */
#line 454 "src/parser/rules.y"
        {}
#line 2178 "src/parser/rules.tab.c"
    break;

  case 131: /* literal: UINT  */
#line 455 "src/parser/rules.y"
           {}
#line 2184 "src/parser/rules.tab.c"
    break;

  case 132: /* literal: DOUBLE  */
#line 456 "src/parser/rules.y"
             {}
#line 2190 "src/parser/rules.tab.c"
    break;

  case 133: /* literal: STRING  */
#line 457 "src/parser/rules.y"
             {}
#line 2196 "src/parser/rules.tab.c"
    break;

  case 134: /* literal: NAME  */
#line 458 "src/parser/rules.y"
           {}
#line 2202 "src/parser/rules.tab.c"
    break;


#line 2206 "src/parser/rules.tab.c"

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

#line 467 "src/parser/rules.y"

