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

#ifndef YY_YY_MISC_BISON_TAB_H_INCLUDED
# define YY_YY_MISC_BISON_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 13 "./misc/bison.y"

	#include "../inc/directives.hpp"
	#include "../inc/instructions.hpp"
	#include "../inc/definitions.hpp"

#line 55 "./misc/bison.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_LPAR = 258,              /* TOKEN_LPAR  */
    TOKEN_RPAR = 259,              /* TOKEN_RPAR  */
    TOKEN_LBRACKET = 260,          /* TOKEN_LBRACKET  */
    TOKEN_RBRACKET = 261,          /* TOKEN_RBRACKET  */
    TOKEN_LCBRACKET = 262,         /* TOKEN_LCBRACKET  */
    TOKEN_RCBRACKET = 263,         /* TOKEN_RCBRACKET  */
    TOKEN_PLUS = 264,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 265,             /* TOKEN_MINUS  */
    TOKEN_PERCENT = 266,           /* TOKEN_PERCENT  */
    TOKEN_DOLLAR = 267,            /* TOKEN_DOLLAR  */
    TOKEN_SEMI = 268,              /* TOKEN_SEMI  */
    TOKEN_COLON = 269,             /* TOKEN_COLON  */
    TOKEN_COMMA = 270,             /* TOKEN_COMMA  */
    TOKEN_SHL = 271,               /* TOKEN_SHL  */
    TOKEN_SHR = 272,               /* TOKEN_SHR  */
    TOKEN_COMMENT = 273,           /* TOKEN_COMMENT  */
    TOKEN_GLOBAL = 274,            /* TOKEN_GLOBAL  */
    TOKEN_EXTERN = 275,            /* TOKEN_EXTERN  */
    TOKEN_SECTION = 276,           /* TOKEN_SECTION  */
    TOKEN_WORD = 277,              /* TOKEN_WORD  */
    TOKEN_SKIP = 278,              /* TOKEN_SKIP  */
    TOKEN_ASCII = 279,             /* TOKEN_ASCII  */
    TOKEN_TYPE = 280,              /* TOKEN_TYPE  */
    TOKEN_END = 281,               /* TOKEN_END  */
    TOKEN_HALT = 282,              /* TOKEN_HALT  */
    TOKEN_INT = 283,               /* TOKEN_INT  */
    TOKEN_IRET = 284,              /* TOKEN_IRET  */
    TOKEN_CALL = 285,              /* TOKEN_CALL  */
    TOKEN_RET = 286,               /* TOKEN_RET  */
    TOKEN_JMP = 287,               /* TOKEN_JMP  */
    TOKEN_BEQ = 288,               /* TOKEN_BEQ  */
    TOKEN_BNE = 289,               /* TOKEN_BNE  */
    TOKEN_BGT = 290,               /* TOKEN_BGT  */
    TOKEN_PUSH = 291,              /* TOKEN_PUSH  */
    TOKEN_POP = 292,               /* TOKEN_POP  */
    TOKEN_XCHG = 293,              /* TOKEN_XCHG  */
    TOKEN_ADD = 294,               /* TOKEN_ADD  */
    TOKEN_SUB = 295,               /* TOKEN_SUB  */
    TOKEN_MUL = 296,               /* TOKEN_MUL  */
    TOKEN_DIV = 297,               /* TOKEN_DIV  */
    TOKEN_NOT = 298,               /* TOKEN_NOT  */
    TOKEN_AND = 299,               /* TOKEN_AND  */
    TOKEN_OR = 300,                /* TOKEN_OR  */
    TOKEN_XOR = 301,               /* TOKEN_XOR  */
    TOKEN_SHLL = 302,              /* TOKEN_SHLL  */
    TOKEN_SHRR = 303,              /* TOKEN_SHRR  */
    TOKEN_LD = 304,                /* TOKEN_LD  */
    TOKEN_ST = 305,                /* TOKEN_ST  */
    TOKEN_CSRRD = 306,             /* TOKEN_CSRRD  */
    TOKEN_CSRWR = 307,             /* TOKEN_CSRWR  */
    TOKEN_NUM = 308,               /* TOKEN_NUM  */
    TOKEN_IDENT = 309,             /* TOKEN_IDENT  */
    TOKEN_STRING = 310,            /* TOKEN_STRING  */
    TOKEN_LABEL = 311,             /* TOKEN_LABEL  */
    TOKEN_GPR = 312,               /* TOKEN_GPR  */
    TOKEN_STATUS = 313,            /* TOKEN_STATUS  */
    TOKEN_HANDLER = 314,           /* TOKEN_HANDLER  */
    TOKEN_CAUSE = 315              /* TOKEN_CAUSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "./misc/bison.y"

    int num;          // Za numeričke vrednosti (brojevi)
    char *ident;      // Za identifikatore (imena promenljivih, etiketa)
    reg_t reg;        // Tip za registre (treba definisati struct ili enum za registre)
    operand oper;     // Tip za operande (treba definisati struct za operande)

#line 139 "./misc/bison.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MISC_BISON_TAB_H_INCLUDED  */
