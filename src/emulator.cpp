#include "../inc/emulator.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

void Emulator::reset()
{
    for (int i = 0; i < 15; ++i)
    {
        cpu.regs[i] = 0;
    }
    cpu.regs[15] = address_of_start;
    for (int i = 0; i < 3; ++i)
    {
        cpu.sregs[i] = 0;
    }
    // memory.clear(); // Čišćenje memorije
}

int Emulator::emulation(FILE *inputF)
{
    reset();
    loadInstructions(inputF);

    while (!finished)
    {
        int instruction = fetchInstrFromMemory(cpu.regs[15]);
        // cout<<" Instruction: 0x"<<hex<<instruction<<" PC: 0x"<<hex<<cpu.regs[15]<<endl;
        cpu.regs[15] += 4;

        int opCode = parseOpCode(instruction);

        if (opCode > 0x97 || opCode < 0x00)
        {
            cout << "Error: Cannot handle operation with opCode=0x" << hex << opCode << endl;
            return -1;
        }
        int justOpCode = (opCode >> 4) & 0xF;

        switch (justOpCode)
        {
        case 0:
            handler_ins_halt(instruction);
            break;
        case 1:
            handler_ins_int(instruction);
            break;
        case 2:
            handler_ins_call(instruction);
            break;
        case 3:
            handler_ins_jumps(instruction);
            break;
        case 4:
            handler_ins_xchng(instruction);
            break;
        case 5:
            handler_ins_aritm(instruction);
            break;
        case 6:
            handler_ins_log(instruction);
            break;
        case 7:
            handler_ins_shrl(instruction);
            break;
        case 8:
            handler_ins_st(instruction);
            break;
        case 9:
            handler_ins_ld(instruction);
            break;
        }
    }
    printMachineState();

    return 0;
}

void Emulator::writeValueToAddress(uint32_t address, int value)
{
    memory[address] = value & 0xFF;
    memory[address + 1] = (value >> 8) & 0xFF;
    memory[address + 2] = (value >> 16) & 0xFF;
    memory[address + 3] = (value >> 24) & 0xFF;
}

void Emulator::writeValueToReg(uint32_t reg, int value, int sregs)
{
    if (!sregs)
    {
        if (reg > 0 && reg < 16)
            cpu.regs[reg] = value;
    }
    else
    {
        cpu.sregs[reg] = value;
    }
}

int Emulator::fetchFourBytesMemory(uint32_t address)
{
    if (memory.find(address) != memory.end())
    {
        int32_t value = 0;
        value |= (int32_t)memory[address + 3] << 24;
        value |= (int32_t)memory[address + 2] << 16;
        value |= (int32_t)memory[address + 1] << 8;
        value |= (int32_t)memory[address];
        return value;
    }
    else
    {
        return 0;
    }
}

uint8_t Emulator::parseRegA(int instr)
{
    return (instr >> 20) & 0xF;
}

uint8_t Emulator::parseRegB(int instr)
{
    return (instr >> 16) & 0xF;
}

uint8_t Emulator::parseRegC(int instr)
{
    return (instr >> 12) & 0xF;
}

int16_t Emulator::parseDisp(int instr)
{
    int16_t disp = (instr) & 0xFFF;
    if (disp & 0x800)
    {
        disp |= 0xF000; // Proširivanje znaka na 16-bitni broj
    }

    return disp;
}

uint8_t Emulator::parseOpCode(int instr)
{

    return (instr >> 24) & 0xFF;
}

void Emulator::loadInstructions(FILE *inputFile)
{
    char line[256];
    while (fgets(line, sizeof(line), inputFile))
    {
        uint32_t address;
        char instructionBytes[256];

        // Parse the address and the instruction bytes from the line
        sscanf(line, "%x: %[^\n]", &address, instructionBytes);

        std::stringstream ss(instructionBytes);
        std::string byteStr;
        uint32_t offset = 0;

        while (ss >> byteStr)
        {
            uint8_t byte = static_cast<uint8_t>(std::stoul(byteStr, nullptr, 16));
            memory[address + offset] = byte;
            offset++;
        }
    }
}

uint32_t Emulator::fetchInstrFromMemory(uint32_t address)
{
    uint32_t value = 0;
    value |= memory[address + 0];
    value |= memory[address + 1] << 8;
    value |= memory[address + 2] << 16;
    value |= memory[address + 3] << 24;
    return value;
}

void Emulator::printMemory()
{
    for (const auto &entry : memory)
    {
        uint32_t address = entry.first;
        uint8_t value = entry.second;
        std::cout << std::hex << std::setw(8) << std::setfill('0') << address << ": ";
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(value) << std::endl;
    }
}

void Emulator::printMachineState()
{
    std::cout << "\n-----------------------------------------------------------------" << std::endl;
    std::cout << "Emulated processor executed halt instruction" << std::endl;
    std::cout << "Emulated processor state:" << std::endl;

    for (int i = 0; i < 16; i += 4)
    {
        std::cout << "r" << dec << i << "=" << "0x"
                  << std::setw(8) << std::setfill('0')
                  << hex << cpu.regs[i] << std::setw(4) << std::setfill(' ') << "   ";
        std::cout << "r" << dec << i + 1 << "=" << "0x"
                  << std::setw(8) << std::setfill('0')
                  << hex << cpu.regs[i + 1] << std::setw(4) << std::setfill(' ') << "   ";
        std::cout << "r" << dec << i + 2 << "=" << "0x"
                  << std::setw(8) << std::setfill('0')
                  << hex << cpu.regs[i + 2] << std::setw(4) << std::setfill(' ') << "   ";
        std::cout << "r" << dec << i + 3 << "=" << "0x"
                  << std::setw(8) << std::setfill('0')
                  << hex << cpu.regs[i + 3] << endl;
    }
    /* for (int i = 0; i < 3; i++)
         std::cout << "sr" << dec << i << "=" << "0x"
                   << std::setw(8) << std::setfill('0')
                   << hex << cpu.sregs[i] << endl;*/
}

int Emulator::handler_ins_halt(int insr)
{
    // cout << " Instruction: HALT" << "PC: 0x" << hex << cpu.regs[15] << endl;

    finished = true;
    return 0;
}

int Emulator::handler_ins_int(int insr)
{
    cpu.regs[14] -= 4; // sp <= sp-4

    uint32_t pc = cpu.regs[15];
    writeValueToAddress(cpu.regs[14], pc); // pc na stek

    cpu.regs[14] -= 4; // sp <= sp-4

    uint32_t status = cpu.sregs[0];
    writeValueToAddress(cpu.regs[14], status); // status na stek

    writeValueToReg(2, 4, 1);
    writeValueToReg(0, status & (~0x1), 1);
    writeValueToReg(15, cpu.sregs[1], 0);
    // cout << " Instruction: INT" << "PC: 0x" << hex << cpu.regs[15] << endl;

    return 0;
}
int Emulator::handler_ins_call(int insr)
{
    cpu.regs[14] -= 4; // sp <= sp-4

    uint32_t pc = cpu.regs[15];
    writeValueToAddress(cpu.regs[14], pc);

    uint32_t addr;

    if (parseOpCode(insr) == 0x20)
    {
        cpu.regs[15] = cpu.regs[parseRegA(insr)] + cpu.regs[parseRegB(insr)] + parseDisp(insr);
    }
    else
    {
        addr = cpu.regs[parseRegA(insr)] + cpu.regs[parseRegB(insr)] + parseDisp(insr);
        cpu.regs[15] = fetchFourBytesMemory(addr);
    }
    // cout << " Instruction: CALL" << "PC: 0x" << hex << cpu.regs[15] << endl;

    return 0;
}
int Emulator::handler_ins_jumps(int insr)
{
    int regA = parseRegA(insr);
    int regB = parseRegB(insr);
    int regC = parseRegC(insr);
    int disp = parseDisp(insr);
    uint32_t addr = uint32_t(cpu.regs[regA] + disp);

    switch (parseOpCode(insr))
    {
    case 0x30:
        cpu.regs[15] = cpu.regs[regA] + disp;
        // cout << " Instruction: JMPI" << "PC: 0x" << hex << cpu.regs[15] << endl;
        break;
    case 0x31:
        if (cpu.regs[regC] == cpu.regs[regB])
            cpu.regs[15] = cpu.regs[regA] + disp;
        // cout << " Instruction: BEQ" << "PC: 0x" << hex << cpu.regs[15] << endl;
        break;
    case 0x32:
        if (cpu.regs[regC] != cpu.regs[regB])
            cpu.regs[15] = cpu.regs[regA] + disp;
        // cout << " Instruction: BNE" << "PC: 0x" << hex << cpu.regs[15] << endl;
        break;
    case 0x33:
        if (cpu.regs[regC] < cpu.regs[regB])
            cpu.regs[15] = cpu.regs[regA] + disp;
        // cout << " Instruction: BGR" << "PC: 0x" << hex << cpu.regs[15] << endl;
        break;
    case 0x38:
        cpu.regs[15] = fetchFourBytesMemory(addr);
        // cout << " Instruction: JMPM" << "PC: 0x" << hex << cpu.regs[15] << endl;
        break;
    case 0x39:
        if (cpu.regs[regC] == cpu.regs[regB])
            cpu.regs[15] = fetchFourBytesMemory(addr);
        // cout << " Instruction: BEQM" << "PC: 0x" << hex << cpu.regs[15] << endl;
        break;
    case 0x3a:
        if (cpu.regs[regC] != cpu.regs[regB])
            cpu.regs[15] = fetchFourBytesMemory(addr);
        // cout << " Instruction: BNEM" << "PC: 0x" << hex << cpu.regs[15] << endl;
        break;
    case 0x3b:
        if (cpu.regs[regC] < cpu.regs[regB])
            cpu.regs[15] = fetchFourBytesMemory(addr);
        // cout << " Instruction: BGRM" << "PC: 0x" << hex << cpu.regs[15] << endl;
        break;
    }

    return 0;
}

int Emulator::handler_ins_xchng(int insr)
{
    int regB = parseRegB(insr);
    int regC = parseRegC(insr);

    int temp = cpu.regs[regB];
    cpu.regs[regB] = cpu.regs[regC];
    cpu.regs[regC] = temp;
    // cout << " Instruction: xchng" << "PC: 0x" << hex << cpu.regs[15] << endl;

    return 0;
}

int Emulator::handler_ins_aritm(int insr)
{
    int regA = parseRegA(insr);
    int regB = parseRegB(insr);
    int regC = parseRegC(insr);

    switch (parseOpCode(insr))
    {
    case 0x50:
        writeValueToReg(regA, cpu.regs[regB] + cpu.regs[regC], 0);
        break;
    case 0x51:
        writeValueToReg(regA, cpu.regs[regB] - cpu.regs[regC], 0);
        break;
    case 0x52:
        writeValueToReg(regA, cpu.regs[regB] * cpu.regs[regC], 0);
        break;
    case 0x53:
        writeValueToReg(regA, cpu.regs[regB] / cpu.regs[regC], 0);
        break;
    }
    // cout << " Instruction: ARTM" << "PC: 0x" << hex << cpu.regs[15] << endl;

    return 0;
}

int Emulator::handler_ins_log(int insr)
{
    int regA = parseRegA(insr);
    int regB = parseRegB(insr);
    int regC = parseRegC(insr);

    switch (parseOpCode(insr))
    {
    case 0x60:
        writeValueToReg(regA, ~cpu.regs[regB], 0);
        break;
    case 0x61:
        writeValueToReg(regA, cpu.regs[regB] & cpu.regs[regC], 0);
        break;
    case 0x62:
        writeValueToReg(regA, cpu.regs[regB] | cpu.regs[regC], 0);
        break;
    case 0x63:
        writeValueToReg(regA, cpu.regs[regB] ^ cpu.regs[regC], 0);
        break;
    }
    // cout << " Instruction: LOG" << "PC: 0x" << hex << cpu.regs[15] << endl;

    return 0;
}

int Emulator::handler_ins_shrl(int insr)
{
    int regA = parseRegA(insr);
    int regB = parseRegB(insr);
    int regC = parseRegC(insr);

    switch (parseOpCode(insr))
    {
    case 0x70:
        writeValueToReg(regA, (cpu.regs[regB] << cpu.regs[regC]), 0);
        break;
    case 0x71:
        writeValueToReg(regA, (cpu.regs[regB] >> cpu.regs[regC]), 0);
        break;
    }
    // cout << " Instruction: SHLR" << "PC: 0x" << hex << cpu.regs[15] << endl;

    return 0;
}

int Emulator::handler_ins_ld(int insr)
{
    int regA = parseRegA(insr);
    int regB = parseRegB(insr);
    int regC = parseRegC(insr);
    int disp = parseDisp(insr);
    uint32_t addr;

    switch (parseOpCode(insr))
    {
    case 0x90:
        writeValueToReg(regA, cpu.sregs[regB], 0);
        break;
    case 0x91:
        writeValueToReg(regA, cpu.regs[regB] + disp, 0);
        break;
    case 0x92:
        addr = uint32_t(cpu.regs[regC] + cpu.regs[regB] + disp);
        writeValueToReg(regA, fetchFourBytesMemory(addr), 0);
        break;
    case 0x93:
        writeValueToReg(regA, fetchFourBytesMemory(cpu.regs[regB]), 0);
        writeValueToReg(regB, cpu.regs[regB] + disp, 0);
        break;
    case 0x94:
        writeValueToReg(regA, cpu.regs[regB], 1);
        break;
    case 0x95:
        writeValueToReg(regA, cpu.sregs[regB] | disp, 1);
        break;
    case 0x96:
        addr = uint32_t(cpu.regs[regC] + cpu.regs[regB] + disp);
        writeValueToReg(regA, fetchFourBytesMemory(addr), 1);
        break;
    case 0x97:
        writeValueToReg(regA, fetchFourBytesMemory(cpu.regs[regB]), 1);
        writeValueToReg(regB, cpu.regs[regB] + disp, 0);
        break;
    }

    // cout << " Instruction: LD" << "PC: 0x" << hex << cpu.regs[15] << endl;

    return 0;
}

int Emulator::handler_ins_st(int insr)
{
    int regA = parseRegA(insr);
    int regB = parseRegB(insr);
    int regC = parseRegC(insr);
    int disp = parseDisp(insr);
    uint32_t addr = uint32_t(cpu.regs[regB] + cpu.regs[regA] + disp);

    switch (parseOpCode(insr))
    {
    case 0x80:
        writeValueToAddress(addr, cpu.regs[regC]);
        break;
    case 0x82:
        writeValueToAddress(fetchFourBytesMemory(addr), cpu.regs[regC]);
        break;
    case 0x81:
        writeValueToReg(regA, cpu.regs[regA] + disp, 0);
        writeValueToAddress(cpu.regs[regA], cpu.regs[regC]);
        break;
    }
    // cout << " Instruction: ST" << "PC: 0x" << hex << cpu.regs[15] << endl;

    return 0;
}
