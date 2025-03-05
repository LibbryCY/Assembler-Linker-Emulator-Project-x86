#ifndef _definition_h_
#define _definition_h_

#include<stdint.h>

typedef uint8_t reg_t;

// Definicija registra
enum regType: reg_t {
	ZERO_CODE = 0,
	SP_CODE = 14,
	PC_CODE = 15,
	STATUS_CODE = 0,
	HANDLER_CODE = 1,
	CAUSE_CODE = 2
};
	

// Definicija direktiva
 enum directiveType{
    DIR_GLOBAL, DIR_EXTERN, DIR_SECTION, DIR_WORD,
    DIR_SKIP, DIR_ASCII, DIR_END
};


enum type_operand {
	IMM_LIT,			// neposredno literal
	IMM_SYM,			// neposredno symbol
	MEM_LIT,			// memorijsko literal
	MEM_SYM,            // memorijsko symbol
	IMM_REG,			// neposredno registar
	MEM_REG,			// memorijsko registar
	MEM_REG_LIT,		// memorijsko registar+literal
	MEM_REG_SYM,		// memorijsko registar+symbol
	MEM_REG_REG			// memorijsko registar+registar
};


// Definicija operanda
struct operand {
    type_operand type;  // Tip operanda (neposredna vrednost, registar, memorijska adresa, itd.)
    int literal;        // Vrednost operanda (ako je neposredna vrednost ili offset)
	char *symbol;       // Simbol (ako je operand simbol)
    reg_t reg;          // Registar (ako je operand registar)
	reg_t reg2;

	operand() = default;
    operand(type_operand op, int l, char *s, reg_t r,reg_t r2=0)
        : type(op), literal(l), symbol(s), reg(r) ,reg2(r2){}
};


#endif //!_definition_h_