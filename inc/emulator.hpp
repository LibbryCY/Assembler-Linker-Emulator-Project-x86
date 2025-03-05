#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include <cstdint>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

enum StatusCode
{
    INTR=1,
    TERM=2,
    TIME=3
};

struct CPU
{
    int regs[16];
    int sregs[3];
};

const int address_of_start = 0x40000000;

class Emulator
{
private:
    CPU cpu;
    std::map<uint32_t, uint8_t> memory;
    int finished = 0;

public:
    Emulator()
    {
        reset();
    }
    static Emulator &getInstance()
    {
        static Emulator instance;
        return instance;
    }
    void writeValueToAddress(uint32_t address, int value);
    void writeValueToReg(uint32_t reg, int value, int sregs);

    int fetchFourBytesMemory(uint32_t address);

    uint8_t parseOpCode(int instr);
    uint8_t parseRegA(int instr);
    uint8_t parseRegB(int instr);
    uint8_t parseRegC(int instr);
    int16_t parseDisp(int instr);

    int emulation(FILE *);
    void reset();

    void loadInstructions(FILE *inputFile);
    uint32_t fetchInstrFromMemory(uint32_t address);

    void printMemory();
    void printMachineState();

    int handler_ins_halt(int insr);
    int handler_ins_int(int insr);
    int handler_ins_call(int insr);
    int handler_ins_jumps(int insr);
    int handler_ins_xchng(int insr);
    int handler_ins_aritm(int insr);
    int handler_ins_log(int insr);
    int handler_ins_shrl(int insr);
    int handler_ins_ld(int insr);
    int handler_ins_st(int insr);
};

#endif // EMULATOR_HPP
