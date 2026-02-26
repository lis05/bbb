/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_RULES_TAB_H_INCLUDED
# define YY_YY_SRC_PARSER_RULES_TAB_H_INCLUDED
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
    NAME = 258,                    /* NAME  */
    INT = 259,                     /* INT  */
    UINT = 260,                    /* UINT  */
    DOUBLE = 261,                  /* DOUBLE  */
    STRING = 262,                  /* STRING  */
    MEMORY_LENGTH_SIMPLE = 263,    /* MEMORY_LENGTH_SIMPLE  */
    MEMORY_LENGTH_PREFIX = 264,    /* MEMORY_LENGTH_PREFIX  */
    ALIGNMENT_SIMPLE = 265,        /* ALIGNMENT_SIMPLE  */
    TYPE = 266,                    /* TYPE  */
    CHUNK_CLASS_MEM = 267,         /* CHUNK_CLASS_MEM  */
    CHUNK_CLASS_SSE = 268,         /* CHUNK_CLASS_SSE  */
    CHUNK_CLASS_INT = 269,         /* CHUNK_CLASS_INT  */
    CHUNK_CLASS_LAYOUT = 270,      /* CHUNK_CLASS_LAYOUT  */
    GP_REGISTER = 271,             /* GP_REGISTER  */
    REGISTER = 272,                /* REGISTER  */
    GLOBAL = 273,                  /* GLOBAL  */
    LAYOUT = 274,                  /* LAYOUT  */
    EXTERN = 275,                  /* EXTERN  */
    NASM = 276,                    /* NASM  */
    FN = 277,                      /* FN  */
    NASM_BLOCK = 278,              /* NASM_BLOCK  */
    IF = 279,                      /* IF  */
    ELSE = 280,                    /* ELSE  */
    GOTO = 281,                    /* GOTO  */
    LOOP = 282,                    /* LOOP  */
    BREAK = 283,                   /* BREAK  */
    CONTINUE = 284,                /* CONTINUE  */
    RET = 285,                     /* RET  */
    AVOID = 286,                   /* AVOID  */
    ALIAS = 287,                   /* ALIAS  */
    REG = 288,                     /* REG  */
    LOGICAL_OR = 289,              /* LOGICAL_OR  */
    LOGICAL_AND = 290,             /* LOGICAL_AND  */
    ASSIGN = 291,                  /* "="  */
    INCREMENT = 292,               /* INCREMENT  */
    DECREMENT = 293,               /* DECREMENT  */
    SIZEOF = 294,                  /* SIZEOF  */
    PLUS = 295,                    /* "+"  */
    MINUS = 296,                   /* "-"  */
    MULTIPLY = 297,                /* "*"  */
    DIVIDE = 298,                  /* "/"  */
    REMAINDER = 299,               /* "%"  */
    BITWISE_AND = 300,             /* "&"  */
    BITWISE_OR = 301,              /* "|"  */
    BITWISE_XOR = 302,             /* "^"  */
    LOGICAL_NOT = 303,             /* "!"  */
    BITWISE_NOT = 304,             /* "~"  */
    LESS_THEN = 305,               /* "<"  */
    GREATER_THEN = 306,            /* ">"  */
    LESS_EQUAL = 307,              /* LESS_EQUAL  */
    GREATER_EQUAL = 308,           /* GREATER_EQUAL  */
    EQUALS = 309,                  /* EQUALS  */
    NOT_EQUALS = 310,              /* NOT_EQUALS  */
    ROB = 311,                     /* "("  */
    RCB = 312,                     /* ")"  */
    SOB = 313,                     /* "["  */
    SCB = 314,                     /* "]"  */
    COB = 315,                     /* "{"  */
    CCB = 316,                     /* "}"  */
    ARROW = 317,                   /* ARROW  */
    COLON = 318,                   /* ":"  */
    SEMICOLON = 319,               /* ";"  */
    COMMA = 320,                   /* ","  */
    DOT = 321                      /* "."  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "src/parser/rules.y"

    ast_node_t *node;

#line 134 "src/parser/rules.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_RULES_TAB_H_INCLUDED  */
