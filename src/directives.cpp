#include "../inc/directives.hpp"
#include "../inc/symboltable.hpp"
#include <iostream>

void patch_addres(int addr, int value)
{
    sections[current_section].content[addr + 0] = value & 0xff;
    sections[current_section].content[addr + 1] = (value >> 8) & 0x0f | sections[current_section].content[addr + 1] & 0xf0;
}

void close_previous_section()
{
    Asembler &asm1 = Asembler::getInstance();
    // literl pool
    for (auto [offset, lit] : sections[current_section].literal_pool)
    {
        patch_addres(offset, sections[current_section].counter - offset - 4);
        // printf("Patch %02x on offset %x , adresa u bazenu relativno: %x (line counter: %x)\n", lit, offset, sections[current_section].counter - offset - 4, sections[current_section].counter);
        uint8_t *bytes = (uint8_t *)(&lit);
        for (size_t i = 0; i < sizeof(lit); ++i)
        {
            sections[current_section].content.emplace_back(bytes[i]);
        }
        sections[current_section].counter += 4;
        sections[current_section].literal_pool.clear();
    }
    // symbol pool
    for (auto [offset, symbol] : sections[current_section].symbol_pool)
    {
        patch_addres(offset, sections[current_section].counter - offset - 4);
        sections[current_section].relocTable.addRelocation(sections[current_section].counter, symbol, current_section, ABSOLUTE);

        for (size_t i = 0; i < 4; ++i)
        {
            sections[current_section].content.emplace_back(0x66);
        }
        sections[current_section].counter += 4;
        sections[current_section].symbol_pool.clear();
    }

    asm1.fileCounter += sections[current_section].counter;
}

void start_of_section(string c)
{
    if (!sections.empty())
    {
        close_previous_section();
    }
    static int indexSec=0;
    Asembler &asm1 = Asembler::getInstance();

    Section sec;
    sec.start = asm1.fileCounter;
    sec.index = indexSec++;
    sec.section_name = c;
    sec.symbolTable = &symTable;
    sec.relocTable = RelocTable();
    sec.counter = 0;

    sections[c] = sec;
    symTable.addSymbol(c, 0, c, SECTION_FLAG);

    current_section = c;
}

// Funkcija za obradu labela
void handle_label(string label)
{
    SymbolTable *sym = &symTable;
    sym->addSymbol(label, sections[current_section].counter, current_section, DEFINED_FLAG);
    sym->resolveReferences(label);
}

// Funkcija za obradu globalnih varijabli
void handle_global(string global)
{
    SymbolTable *sym = &symTable;
    if (!sym->checkSymbol(global))
    {
        sym->addSymbol(global, 0, current_section, GLOBAL_FLAG);
    }
    else
    {
        sym->setGlobal(global);
    }
}

// Funkcija za obradu eksternih varijabli
void handle_extern(string ext)
{
    SymbolTable *sym = &symTable;

    {
        sym->addSymbol(ext, 0, "UND",EXTERN_FLAG );
    }
}

// Funkcija za obradu reči (string)
void handle_word(string word)
{
    SymbolTable *sym = &symTable;

    sym->addReference(word, current_section, sections[current_section].counter);

    sections[current_section].content.push_back(0x3d);
    sections[current_section].content.push_back(0x3d);
    sections[current_section].content.push_back(0x3d);
    sections[current_section].content.push_back(0x3d);
    sections[current_section].counter += 4;
}

// Funkcija za obradu reči (broj)
void handle_word(int word)
{
    sections[current_section].content.push_back(word & 0xff);
    sections[current_section].content.push_back((word >> 8) & 0xff);
    sections[current_section].content.push_back((word >> 16) & 0xff);
    sections[current_section].content.push_back((word >> 24) & 0xff);

    sections[current_section].counter += 4;
}

// Funkcija za obradu završetka
void handle_end()
{
    Asembler::getInstance().setIsFinished(1);
    close_previous_section();
    Asembler::resolveAllRealocs();
}

// Funkcija za obradu ASCII podataka
void handle_ascii(string ascii)
{
    // Implementacija obrade ASCII podataka
}

// Funkcija za obradu SKIP direktive
void handle_skip(int count)
{
    for (int i = 0; i < count; i++)
    {
        sections[current_section].content.emplace_back(0);
    }
    sections[current_section].counter += count;
}


void handle_type(string sym,string type){
    if(symTable.getSymbol(sym)){
        if(type=="FUNC"){
            symTable.getSymbol(sym)->type=FUNC;
        }
        if(type=="DATA"){
            symTable.getSymbol(sym)->type=DATA;
        }
    }else{
        symTable.addSymbol(sym,0,current_section,0,0);
         if(type=="FUNC"){
            symTable.getSymbol(sym)->type=FUNC;
        }
        if(type=="DATA"){
            symTable.getSymbol(sym)->type=DATA;
        }
    }
}