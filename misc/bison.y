%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int yyparse(void);
extern int yylex(void);
extern FILE *yyin;
void yyerror(const char *);
%}

%code requires {
	#include "../inc/directives.hpp"
	#include "../inc/instructions.hpp"
	#include "../inc/definitions.hpp"
}

%union {
    int num;          // Za numeričke vrednosti (brojevi)
    char *ident;      // Za identifikatore (imena promenljivih, etiketa)
    reg_t reg;        // Tip za registre (treba definisati struct ili enum za registre)
    operand oper;     // Tip za operande (treba definisati struct za operande)
}

%define parse.error verbose



// tokens
%token TOKEN_LPAR
%token TOKEN_RPAR
%token TOKEN_LBRACKET
%token TOKEN_RBRACKET
%token TOKEN_LCBRACKET
%token TOKEN_RCBRACKET
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_PERCENT
%token TOKEN_DOLLAR
%token TOKEN_SEMI
%token TOKEN_COLON
%token TOKEN_COMMA
%token TOKEN_SHL
%token TOKEN_SHR
%token <ident> TOKEN_COMMENT

%token <ident> TOKEN_GLOBAL
%token <ident> TOKEN_EXTERN
%token <ident> TOKEN_SECTION
%token <ident> TOKEN_WORD
%token <ident> TOKEN_SKIP
%token <ident> TOKEN_ASCII
%token <ident> TOKEN_TYPE
%token <ident> TOKEN_END

%token <ident> TOKEN_HALT
%token <ident> TOKEN_INT
%token <ident> TOKEN_IRET
%token <ident> TOKEN_CALL
%token <ident> TOKEN_RET
%token <ident> TOKEN_JMP
%token <ident> TOKEN_BEQ
%token <ident> TOKEN_BNE
%token <ident> TOKEN_BGT
%token <ident> TOKEN_PUSH
%token <ident> TOKEN_POP
%token <ident> TOKEN_XCHG
%token <ident> TOKEN_ADD
%token <ident> TOKEN_SUB
%token <ident> TOKEN_MUL
%token <ident> TOKEN_DIV
%token <ident> TOKEN_NOT
%token <ident> TOKEN_AND
%token <ident> TOKEN_OR
%token <ident> TOKEN_XOR
%token <ident> TOKEN_SHLL
%token <ident> TOKEN_SHRR
%token <ident> TOKEN_LD
%token <ident> TOKEN_ST
%token <ident> TOKEN_CSRRD
%token <ident> TOKEN_CSRWR

%token <num> TOKEN_NUM
%token <ident> TOKEN_IDENT
%token <ident> TOKEN_STRING
%token <ident> TOKEN_LABEL

%token <reg> TOKEN_GPR
%token <reg> TOKEN_STATUS
%token <reg> TOKEN_HANDLER
%token <reg> TOKEN_CAUSE


%type <ident> global_list
%type <ident> extern_list
%type <ident> directive
%type <reg> csreg
%type <oper> op
%type <oper> jump_operand
%type <ident> word
%type <ident> word_list
%type <ident> instr
%type <ident> labela

%type <reg> reg_list


//rules
%%

	prog
		: lines
		;


	lines
		: line
		| lines line
		;

	line
		:
		| labela statement
		| statement
		| labela
		| labela TOKEN_COMMENT  
		| TOKEN_COMMENT 
		;

	statement
		: instr
		| instr TOKEN_COMMENT 
		| directive
		| directive TOKEN_COMMENT 
		;
	
	labela
		: TOKEN_LABEL  {
			 handle_label($1);
		}
		;
	
	directive
		: TOKEN_GLOBAL global_list
		| TOKEN_EXTERN extern_list
		| TOKEN_SECTION TOKEN_IDENT { 
			 start_of_section($2); 
		}
		| TOKEN_WORD word_list
		| TOKEN_SKIP TOKEN_NUM {
			 handle_skip($2);
		}
		| TOKEN_ASCII TOKEN_STRING { 
			 handle_ascii($2);
		}
		| TOKEN_TYPE TOKEN_IDENT TOKEN_IDENT{ 
			 handle_type($2,$3); 
		}
		| TOKEN_END { 
			 handle_end(); 
		}
		;

	global_list
		: TOKEN_IDENT {
			 handle_global($1);
		}
		| global_list TOKEN_COMMA TOKEN_IDENT {
			 handle_global($3);
		}
		;
	
	word_list
		: word_list TOKEN_COMMA word
		| word
		;
	word
		:TOKEN_NUM{
			 handle_word($1); 
		}
		| TOKEN_IDENT{
			 handle_word($1); 
		}

	extern_list
	    : TOKEN_IDENT {
			 handle_extern($1); 
		}
		| extern_list TOKEN_COMMA TOKEN_IDENT {
			handle_extern($3); 
		}
		;
	
	instr
		: TOKEN_HALT { 
			 ins_halt();
		}
		| TOKEN_INT { 
			 ins_int();
		}
		| TOKEN_IRET { 
			 ins_iret();
		}
		| TOKEN_CALL jump_operand{ 
			ins_call($2); 
		}
		| TOKEN_RET { 
			ins_ret();
		}
		| TOKEN_JMP jump_operand { 
			 ins_jmp($2); 
		}
		| TOKEN_BEQ TOKEN_GPR TOKEN_COMMA TOKEN_GPR TOKEN_COMMA jump_operand { 
			ins_beq_bne_bgt(1,$2,$4,$6); 
		}
		| TOKEN_BNE TOKEN_GPR TOKEN_COMMA TOKEN_GPR TOKEN_COMMA jump_operand {  
			ins_beq_bne_bgt(2,$2,$4,$6); 
		}
		| TOKEN_BGT TOKEN_GPR TOKEN_COMMA TOKEN_GPR TOKEN_COMMA jump_operand { 
			ins_beq_bne_bgt(3,$2,$4,$6); 
		}
		| TOKEN_PUSH TOKEN_LCBRACKET reg_list TOKEN_RCBRACKET
		| TOKEN_PUSH TOKEN_GPR{ ins_push($2); }
		| TOKEN_POP TOKEN_GPR { 
			ins_pop($2);
		}
		| TOKEN_XCHG TOKEN_GPR TOKEN_COMMA TOKEN_GPR {
			 ins_aritmlog(0x40,0,$2,$4);
		}
		| TOKEN_ADD TOKEN_GPR TOKEN_COMMA TOKEN_GPR{
			ins_aritmlog(0x50,$4,$4,$2);
		}
		| TOKEN_ADD TOKEN_GPR TOKEN_COMMA TOKEN_GPR TOKEN_COMMA TOKEN_SHLL TOKEN_NUM{
			ins_aritm_shifted(0x50,$4,$4,$2,1,$7);
		}
		| TOKEN_ADD TOKEN_GPR TOKEN_COMMA TOKEN_GPR TOKEN_COMMA TOKEN_SHRR TOKEN_NUM{
			ins_aritm_shifted(0x50,$4,$4,$2,0,$7);
		}
		| TOKEN_SUB TOKEN_GPR TOKEN_COMMA TOKEN_GPR{
			ins_aritmlog(0x51,$4,$4,$2);
		}
		| TOKEN_MUL TOKEN_GPR TOKEN_COMMA TOKEN_GPR{
			 ins_aritmlog(0x52,$4,$4,$2);
		}
		| TOKEN_DIV TOKEN_GPR TOKEN_COMMA TOKEN_GPR{
			ins_aritmlog(0x53,$4,$4,$2);
		}
		| TOKEN_NOT TOKEN_GPR{
			ins_aritmlog(0x60,$2,$2,0);
		}
		| TOKEN_AND TOKEN_GPR TOKEN_COMMA TOKEN_GPR{
			ins_aritmlog(0x61,$4,$4,$2);
		}
		| TOKEN_OR TOKEN_GPR TOKEN_COMMA TOKEN_GPR{
			ins_aritmlog(0x62,$4,$4,$2);
		}
		| TOKEN_XOR TOKEN_GPR TOKEN_COMMA TOKEN_GPR{
			ins_aritmlog(0x63,$4,$4,$2);
		}
		| TOKEN_SHL TOKEN_GPR TOKEN_COMMA TOKEN_GPR{
			ins_aritmlog(0x70,$4,$4,$2);
		}
		| TOKEN_SHR TOKEN_GPR TOKEN_COMMA TOKEN_GPR{
			 ins_aritmlog(0x71,$4,$4,$2);
		}
		| TOKEN_LD op TOKEN_COMMA TOKEN_GPR { 
			ins_ld($2,$4); 
		}
		| TOKEN_ST TOKEN_GPR TOKEN_COMMA op { 
			 ins_st($2,$4); 
		}
		| TOKEN_CSRRD csreg TOKEN_COMMA TOKEN_GPR { 
			 ins_csrrd($2,$4); 
		}
		| TOKEN_CSRWR TOKEN_GPR TOKEN_COMMA csreg { 
			 ins_csrwr($2,$4); 
		}
		;

		reg_list
	    : reg_list TOKEN_COMMA TOKEN_GPR{
			ins_push($3); 
		}
		| TOKEN_GPR {
			ins_push($1); 
		}
		;	
		
	op
		: TOKEN_NUM {                          
			$$ = operand(MEM_LIT,$1,0,0);
		}
		| TOKEN_IDENT { 					   
			$$ = operand(MEM_SYM,0,$1,0);
		}
		| TOKEN_DOLLAR TOKEN_NUM {             
			$$ = operand(IMM_LIT,$2,0,0);
		}
		| TOKEN_DOLLAR TOKEN_IDENT {		   
			$$ = operand(IMM_SYM,0,$2,0);
		}
		| TOKEN_GPR { 
			$$ = operand(IMM_REG,0,0,$1);
		}
		| TOKEN_LBRACKET TOKEN_GPR TOKEN_RBRACKET {
			$$ = operand(MEM_REG,0,0,$2);
		}
		| TOKEN_LBRACKET TOKEN_GPR TOKEN_PLUS TOKEN_GPR TOKEN_RBRACKET { 
			$$ = operand(MEM_REG_REG,0,0,$2,$4);
		}
		| TOKEN_LBRACKET TOKEN_GPR TOKEN_PLUS TOKEN_NUM TOKEN_RBRACKET { 
			$$ = operand(MEM_REG_LIT,$4,0,$2);
		}
		| TOKEN_LBRACKET TOKEN_GPR TOKEN_PLUS TOKEN_IDENT TOKEN_RBRACKET { 
			$$ = operand(MEM_REG_SYM,0,$4,$2);
		}
		
		;



	jump_operand
		: TOKEN_NUM {
			$$ = operand(IMM_LIT, $1, 0, 0);
			}
		| TOKEN_IDENT {
			$$ = operand(IMM_SYM, 0, $1, 0);
			}
		;

	csreg
		: TOKEN_STATUS { $$ = STATUS_CODE; }
		| TOKEN_HANDLER { $$ = HANDLER_CODE; }
		| TOKEN_CAUSE { $$ = CAUSE_CODE; }
		;



%%



void yyerror(const char *sp){
  printf("%s", sp);
}