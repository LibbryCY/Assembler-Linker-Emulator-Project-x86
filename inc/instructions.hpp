#ifndef _instructions_h_
#define _instuctiions_h_

#include "definitions.hpp"

void ins_halt();
void ins_int();
void ins_iret();
void ins_call(operand op);
void ins_ret();
void ins_jmp(operand op);
void ins_beq_bne_bgt(int option,reg_t gpr1,reg_t gpr2,operand op);
void ins_push(reg_t gpr);
void ins_pop(reg_t gpr);
void ins_aritmlog(int code,reg_t regA,reg_t regB,reg_t regC);
void ins_aritm_shifted(int code,reg_t regA,reg_t regB,reg_t regC,int left,int shiftent);
void ins_ld(operand op,reg_t gpr);
void ins_st(reg_t gpr, operand op);
void ins_csrrd(reg_t csr,reg_t gpr);
void ins_csrwr(reg_t gpr,reg_t csr);

int checkDisp(int disp);


#endif //!_instuctiions_h_