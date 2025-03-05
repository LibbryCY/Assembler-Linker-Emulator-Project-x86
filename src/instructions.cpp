#include "../inc/instructions.hpp"
#include "../inc/symboltable.hpp"
#include <iostream>

void format_instr(int32_t opcode, reg_t regA, reg_t regB, reg_t regC, uint32_t disp)
{
    uint32_t instr = (opcode << 24) | ((0xf & regA) << 20) | ((0xf & regB) << 16) | ((0xf & regC) << 12) | (0xfff & disp);

    uint8_t *bytes = (uint8_t *)&instr;
    for (int i = 0; i < sizeof(instr); i++)
    {
        sections[current_section].content.emplace_back(bytes[i]);
    }

    sections[current_section].counter += 4;
}

void add_to_literalpool(uint32_t lit)
{
    sections[current_section].literal_pool.push_back({sections[current_section].counter, lit});
}

void add_to_symbolpool(string sym)
{
    sections[current_section].symbol_pool.push_back({sections[current_section].counter, sym});
}

void add_to_realoctable(string symbol, int offset, string section, RelocType a)
{
    sections[current_section].relocTable.addRelocation(offset, symbol, section, a);
}

// Funkcija za instrukciju HALT
void ins_halt()
{
    format_instr(0x00, 0, 0, 0, 0);
}

// Funkcija za instrukciju INT
void ins_int()
{
    format_instr(0x10, 0, 0, 0, 0);
}

// Funkcija za instrukciju IRET
void ins_iret()
{
    format_instr(0x97, STATUS_CODE, SP_CODE, ZERO_CODE, 0x4); // pop status(psw)
    format_instr(0x93, PC_CODE, SP_CODE, ZERO_CODE, 0x4);     // pop pc
}

// Funkcija za instrukciju CALL sa operandom
void ins_call(operand op)
{
    SymbolTable *sym = &symTable;
    if (op.type == IMM_LIT)
    {
        if (checkDisp(op.literal))
            format_instr(0x20, 0, 0, 0, op.literal);
        else
        {
            add_to_literalpool(op.literal);
            format_instr(0x21, PC_CODE, 0, 0, 0x666);
        }
    }
    else
    {
        if (sym->checkSymbol(op.symbol) && sym->isDefined(op.symbol))
        {
            if (sym->symbolInSection(op.symbol, current_section))
            {
                int offset = sym->getSymbol(op.symbol)->offset - sections[current_section].counter - 4;
                if (checkDisp(offset))
                {
                    format_instr(0x20, PC_CODE, ZERO_CODE, ZERO_CODE, offset);
                }
                else
                {
                    cout << "Error: Call offset > 0xfff" << endl;
                }
                return;
            }
            else
            {
                add_to_symbolpool(op.symbol);
                format_instr(0x21, PC_CODE, ZERO_CODE, ZERO_CODE, 0x666);
            }
        }
        else
        {
            sym->addSymbol(op.symbol, 0, "", 0);
            add_to_symbolpool(op.symbol);
            format_instr(0x21, PC_CODE, ZERO_CODE, ZERO_CODE, 0x666);
        }
    }
}

// Funkcija za instrukciju RET
void ins_ret()
{
    ins_pop(PC_CODE);
}

// Funkcija za instrukciju JMP sa operandom
void ins_jmp(operand op)
{
    SymbolTable *sym = &symTable;
    if (op.type == IMM_LIT)
    {
        if (checkDisp(op.literal))
            format_instr(0x30, PC_CODE, 0, 0, op.literal);
        else
        {
            add_to_literalpool(op.literal);
            format_instr(0x38, PC_CODE, ZERO_CODE, ZERO_CODE, 0x666);
        }
    }
    else
    {
        if (sym->isDefined(op.symbol) && sym->checkSymbol(op.symbol))
        {
            if (sym->symbolInSection(op.symbol, current_section))
            {
                int offset = sym->getSymbol(op.symbol)->offset - sections[current_section].counter - 4;
                if (checkDisp(offset))
                {
                    format_instr(0x30, PC_CODE, 0, 0, offset);
                }
                else
                {
                    cout << "Error: jmp offset > +-2048 0x" << offset << endl;
                }
            }
            else
            {
                add_to_symbolpool(op.symbol);
                format_instr(0x38, PC_CODE, 0, 0, 0x666);
            }
            return;
        } // JMP func1
        sym->addSymbol(op.symbol, 0, "", 0);
        add_to_symbolpool(op.symbol);
        format_instr(0x38, PC_CODE, 0, 0, 0x666);
    }
}

// Funkcija za instrukciju BEQ, BNE, BGT sa opcijom i registrima
void ins_beq_bne_bgt(int option, reg_t gpr1, reg_t gpr2, operand op)
{
    SymbolTable *sym = &symTable;
    if (op.type == IMM_LIT)
    {
        if (checkDisp(op.literal))
        {
            cout << "Op.literal je " << op.literal << endl;
            format_instr(0x30 + option, PC_CODE, gpr1, gpr2, op.literal);
        }
        else
        {
            add_to_literalpool(op.literal);
            format_instr(0x38 + option, PC_CODE, gpr1, gpr2, 0x666);
        }
    }
    else
    {
        if (sym->isDefined(op.symbol) && sym->symbolInSection(op.symbol, current_section))
        {
            if (sym->symbolInSection(op.symbol, current_section))
            {
                int offset = sym->getSymbol(op.symbol)->offset - sections[current_section].counter - 4;
                if (checkDisp(offset))
                {
                    format_instr(0x30 + option, PC_CODE, gpr1, gpr2, offset);
                }
                else
                {
                    cout << "Error: bne/beq/bgt offset > 0xfff" << endl;
                }
            }
            else
            {
                add_to_symbolpool(op.symbol);
                format_instr(0x38 + option, PC_CODE, gpr1, gpr2, 0x666);
            }
            return;
        }
        sym->addSymbol(op.symbol, 0, "", 0);
        add_to_symbolpool(op.symbol);
        format_instr(0x38 + option, PC_CODE, gpr1, gpr2, 0x666);
    }
}

// Funkcija za instrukciju PUSH sa registrom
void ins_push(reg_t gpr)
{
    format_instr(0x81, SP_CODE, 0, gpr, -4);
}

// Funkcija za instrukciju POP sa registrom
void ins_pop(reg_t gpr)
{
    format_instr(0x93, gpr, SP_CODE, ZERO_CODE, 0x4);
}

// Funkcija za aritmetičke i logičke instrukcije sa kodom i registrima
void ins_aritmlog(int code, reg_t regA, reg_t regB, reg_t regC)
{
    format_instr(code, regA, regB, regC, 0);
}

void ins_aritm_shifted(int code, reg_t regA, reg_t regB, reg_t regC, int left, int shiftent)
{                                             // r2 <= r2 + (r1 << shiftent)
    format_instr(0x81, SP_CODE, 0, regC, -4); // push regC = r1
    format_instr(0x81, SP_CODE, 0, regB, -4); // push regB = r2

    if (shiftent < 1 || shiftent > 32)
    {
        cout << "Error: Shiftent greather than 32 in ADD.." << endl;
        return;
    }
    format_instr(0x91, regB, 0, 0, shiftent); // regB <= shiftent

    if (left)
    {
        format_instr(0x70, regC, regC, regB, 0); // regC <= regC << regB
    }
    else
    {
        format_instr(0x71, regC, regC, regB, 0); // regC <= regC >> regB
    }

    format_instr(0x93, regB, SP_CODE, ZERO_CODE, 0x4); // pop regB

    format_instr(0x50, regA, regB, regC, 0);
    format_instr(0x93, regC, SP_CODE, ZERO_CODE, 0x4); // pop regC
}

// Funkcija za instrukciju LD sa operandom i registrom
void ins_ld(operand op, reg_t gpr)
{
    SymbolTable *sym = &symTable;
    int code = 0x90;

    switch (op.type)
    {
    case IMM_LIT:
    //cout<<"Lieral u instrs "<< hex <<op.literal<<endl;
        if (!checkDisp(op.literal))
        {
            add_to_literalpool(op.literal);
            format_instr(code + 2, gpr, PC_CODE, ZERO_CODE, 0x666);
        }
        else
        {
            format_instr(code + 1, gpr, ZERO_CODE, ZERO_CODE, op.literal);
        }
        break;
    case IMM_SYM:
        if (sym->checkSymbol(op.symbol) && sym->isDefined(op.symbol))
        { // u sekciji???
            int value = sym->getSymbol(op.symbol)->offset - sections[current_section].counter - 4;
            if (sym->symbolInSection(op.symbol, current_section))
            {
                if (!checkDisp(value))
                {
                    cout << "Error: ld offset > 0xfff" << endl;
                }
                else
                {
                    format_instr(code + 1, gpr, PC_CODE, 0, value);
                }
                return;
            }
        }

        if (!sym->checkSymbol(op.symbol))
            sym->addSymbol(op.symbol, 0, "", 0);
        add_to_symbolpool(op.symbol);
        format_instr(code + 2, gpr, PC_CODE, 0, 0x666);

        break;
    case MEM_LIT:
        if (!checkDisp(op.literal))
        {
            add_to_literalpool(op.literal);
            format_instr(code + 2, gpr, PC_CODE, ZERO_CODE, 0x666);
            format_instr(code + 2, gpr, gpr, ZERO_CODE, 0);
        }
        else
        {
            format_instr(code + 2, gpr, ZERO_CODE, ZERO_CODE, op.literal);
        }
        break;
    case MEM_SYM:
        if (sym->checkSymbol(op.symbol) && sym->isDefined(op.symbol))
        {
            int value = sym->getSymbol(op.symbol)->offset - sections[current_section].counter - 4;
            if (sym->symbolInSection(op.symbol, current_section))
            {
                if (!checkDisp(value))
                {
                    cout << "Error: ld offset > 0xfff" << endl;
                }
                else
                {
                    format_instr(code + 1, gpr, PC_CODE, 0, value); // gpr<= PC + OFFS = ADDR
                    format_instr(code + 2, gpr, gpr, 0, 0);         // gpr<=mem[gpr]
                }
                return;
            }
        }

        if (sym->checkSymbol(op.symbol))
            sym->addSymbol(op.symbol, 0, "", 0);
        add_to_symbolpool(op.symbol);
        format_instr(code + 2, gpr, PC_CODE, 0, 0x666);
        format_instr(code + 2, gpr, gpr, 0, 0);

        break;
    case IMM_REG:
        format_instr(code + 1, gpr, op.reg, ZERO_CODE, 0);
        break;
    case MEM_REG:
        format_instr(code + 3, gpr, op.reg, ZERO_CODE, 0);
        break;
    case MEM_REG_LIT:
        if (!checkDisp(op.literal))
        {
            cout << "Error: Literal > 0xfff , ld with MEM_REG_LIT";
        }
        else
        {
            format_instr(code + 2, gpr, op.reg, ZERO_CODE, op.literal);
        }
        break;
    case MEM_REG_SYM:
        if (sym->checkSymbol(op.symbol) && sym->isDefined(op.symbol))
        { // simbol u tabeli i definisan
            int offset = sym->getSymbol(op.symbol)->offset - sections[current_section].counter - 4;
            if (sym->symbolInSection(op.symbol, current_section))
            {
                if (!checkDisp(offset))
                {
                    cout << "Error: ld offset > 2048 MEM_REG_SYM" << endl;
                }
                else
                {
                    format_instr(code + 1, gpr, PC_CODE, 0, offset); // gpr<= PC + OFFS = ADDR
                    format_instr(code + 2, gpr, gpr, op.reg, 0);     // gpr<=mem[gpr + op.reg]
                }
                return;
            }
        }

        if (sym->checkSymbol(op.symbol))
            sym->addSymbol(op.symbol, 0, "", 0);

        add_to_symbolpool(op.symbol);
        format_instr(code + 2, gpr, PC_CODE, 0, 0x666); // gpr <= mem[PC+rel.offs] = ADDR
        format_instr(code + 2, gpr, gpr, op.reg, 0);

        break;

    case MEM_REG_REG:
        format_instr(0x92, gpr, op.reg, op.reg2, 0); // reg <= reg + reg2
        break;
    }
}

// Funkcija za instrukciju ST sa registrom i operandom
void ins_st(reg_t gpr, operand op)
{
    SymbolTable *sym = &symTable;
    int code = 0x80;

    switch (op.type)
    {
    case IMM_LIT:
        printf("Error immediate addressing with ST! \n");
        break;
    case IMM_SYM:
        printf("Error immediate addressing with ST! \n");
        break;
    case MEM_LIT:
        if (!checkDisp(op.literal))
        {
            add_to_literalpool(op.literal);
            format_instr(code + 2, PC_CODE, ZERO_CODE, gpr, 0x666);
        }
        else
            format_instr(code + 0, 0, 0, gpr, op.literal);
        break;
    case MEM_SYM:
        if (sym->checkSymbol(op.symbol) && sym->isDefined(op.symbol))
        { // simbol u tabeli i definisan
            int offset = sym->getSymbol(op.symbol)->offset - sections[current_section].counter - 4;
            if (sym->symbolInSection(op.symbol, current_section))
            {
                if (!checkDisp(offset))
                {
                    cout << "Error: st offset > 0xfff" << endl;
                }
                else
                {
                    format_instr(code + 0, PC_CODE, 0, gpr, offset); //
                }
                return;
            }
            if (sym->checkSymbol(op.symbol))
                sym->addSymbol(op.symbol, 0, "", 0);
        }
        add_to_symbolpool(op.symbol);
        format_instr(code + 2, PC_CODE, ZERO_CODE, gpr, 0x666); // mem[mem[PC+OFFS=ADDR]]<=gpr

        break;
    case IMM_REG:
        format_instr(0x61, op.reg, gpr, gpr, 0); // gpr[A]<=gpr[B] & gpr[C]; ne treba ?
        break;
    case MEM_REG:
        format_instr(code + 0, op.reg, 0, gpr, 0);
        break;
    case MEM_REG_LIT:
        if (!checkDisp(op.literal))
        {
            cout << "Error: Literal > 0xfff , st with MEM_REG_LIT";
        }
        else
            format_instr(code + 0, op.reg, 0, gpr, op.literal);
        break;
    case MEM_REG_SYM:
        add_to_realoctable(op.symbol, sections[current_section].counter, current_section, RELATIVE);
        format_instr(code + 0, op.reg, 0, gpr, 0x666);
        break;
    }
}

// Funkcija za instrukciju CSR_RD sa CSR i registrom
void ins_csrrd(reg_t csr, reg_t gpr)
{
    format_instr(0x90, gpr, csr, ZERO_CODE, 0);
}

// Funkcija za instrukciju CSR_WR sa registrom i CSR
void ins_csrwr(reg_t gpr, reg_t csr)
{
    format_instr(0x94, csr, gpr, ZERO_CODE, 0);
}

int checkDisp(int disp)
{
    if((disp>>12)>0)return 0;

    if (disp & 0x800)
    {
        disp |= 0xFFFFF000; // Proširivanje znaka na 32-bitni broj
    }
    return (disp > -2048 && disp <= 2047);
}
