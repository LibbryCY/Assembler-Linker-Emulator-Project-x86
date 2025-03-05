%{
#include "bison.tab.h"
#include <stdlib.h>
#include <string.h>


int current_line=1;
%}

%option noyywrap


%%

"#".*$                       {  yylval.ident = strdup(yytext); yylval.ident[strlen(yylval.ident) - 1] = '\0'; return TOKEN_COMMENT; }

".global"                    { return TOKEN_GLOBAL; }
".extern"                    { return TOKEN_EXTERN; }
".section"                   { return TOKEN_SECTION; }
".word"                      { return TOKEN_WORD; }
".skip"                      { return TOKEN_SKIP; }
".ascii"                     { return TOKEN_ASCII; }
".type"                      { return TOKEN_TYPE; }
".end"                       { return TOKEN_END; }

"halt"                      { return TOKEN_HALT; }
"int"                       { return TOKEN_INT; }
"iret"                      { return TOKEN_IRET; }
"call"                      { return TOKEN_CALL; }
"ret"                       { return TOKEN_RET; }
"jmp"                       { return TOKEN_JMP; }
"beq"                       { return TOKEN_BEQ; }
"bne"                       { return TOKEN_BNE; }
"bgt"                       { return TOKEN_BGT; }
"push"[ \t]+                { return TOKEN_PUSH; }
"pop"                       { return TOKEN_POP; }
"xchg"                      { return TOKEN_XCHG; }
"add"                       { return TOKEN_ADD; }
"sub"                       { return TOKEN_SUB; }
"mul"                       { return TOKEN_MUL; }
"div"                       { return TOKEN_DIV; }
"not"                       { return TOKEN_NOT; }
"and"                       { return TOKEN_AND; }
"or"                        { return TOKEN_OR; }
"xor"                       { return TOKEN_XOR; }
"shl"                       { return TOKEN_SHL; }
"shr"                       { return TOKEN_SHR; }
"ld"                        { return TOKEN_LD; }
"st"                        { return TOKEN_ST; }
"csrrd"                     { return TOKEN_CSRRD; }
"csrwr"                     { return TOKEN_CSRWR; }

"%r"([0-9]|1[0-5])           { yylval.reg = atoi(yytext + 2); return TOKEN_GPR; }
"%sp"                        { yylval.reg = 14; return TOKEN_GPR; }
"%pc"                        { yylval.reg = 15; return TOKEN_GPR; }
"%status"                    { yylval.reg = 16; return TOKEN_STATUS; }
"%handler"                   { yylval.reg = 17; return TOKEN_HANDLER; }
"%cause"                     { yylval.reg = 18; return TOKEN_CAUSE; }


"("                         { return TOKEN_LPAR; }
")"                         { return TOKEN_RPAR; }
"["                         { return TOKEN_LBRACKET; }
"]"                         { return TOKEN_RBRACKET; }
"{"                         { return TOKEN_LCBRACKET; }
"}"                         { return TOKEN_RCBRACKET; }
"+"                         { return TOKEN_PLUS; }
"-"                         { return TOKEN_MINUS; }
"%"                         { return TOKEN_PERCENT; }
"$"                         { return TOKEN_DOLLAR; }
";"                         { return TOKEN_SEMI; }
":"                         { return TOKEN_COLON; }
","                         { return TOKEN_COMMA; }
"<<"                         { return TOKEN_SHLL; }
">>"                         { return TOKEN_SHRR; }


\n                        { current_line++; }
\s*                       { }



-?[0-9]+                      { yylval.num = atoi(yytext); return TOKEN_NUM; }
\"[^\"\n]*\"                  { yylval.ident = strdup(yytext + 1); yylval.ident[strlen(yylval.ident) - 1] = '\0'; return TOKEN_STRING; }
[a-zA-Z_][a-zA-Z0-9_]*        { yylval.ident = strdup(yytext); return TOKEN_IDENT; }
0[Xx][0-9A-Fa-f]+             { yylval.num = strtol(yytext, NULL, 16); return TOKEN_NUM; }
[A-Za-z_][A-Za-z0-9_]*[\t]*:  { yylval.ident = strdup(yytext); yylval.ident[strlen(yylval.ident) - 1] = '\0'; return TOKEN_LABEL; }

%%

