#ifndef _symboltable_hpp_
#define _symboltable_hpp_

#include <iomanip>
#include <vector>
#include <unordered_map>
#include <string>
#include <stdint.h>
#include <iostream>
#include "realoctable.hpp"

using namespace std;

const int DEFINED_FLAG = 1;
const int GLOBAL_FLAG = 2;
const int EXTERN_FLAG = 4;
const int SECTION_FLAG = 8;

class SymbolTable;

struct Section
{
    vector<uint8_t> content;

    SymbolTable *symbolTable;
    RelocTable relocTable;

    string section_name;
    uint16_t index;
    int counter = 0x0;
    //     pair  address,literal
    vector<pair<uint32_t, uint32_t>> literal_pool;
    vector<pair<uint32_t,string>> symbol_pool;

    int start;
};

extern string current_section ;
extern unordered_map<string, Section> sections;

struct ForwardReference
{   
    string section_name;
    uint16_t section;
    uint32_t addr;

    ForwardReference(uint16_t sec, uint32_t adr,string name)
    {
        section = sec;
        addr = adr;
        section_name = name;
    }
};

// Definicija tipova simbola
 enum symbolType:int{
    NOTYPE=1,FUNC=2,DATA=3
};

struct SymbolTableDesc
{
    std::string name; // Ime simbola
    uint32_t offset;  // Adresa simbola
    uint8_t flags = 0;
    symbolType type;

    uint16_t section_index;
    string section_name;

    std::vector<ForwardReference> references; // Lista adresa gde se simbol koristi pre nego što je definisan
};

class SymbolTable
{
private:
    std::vector<SymbolTableDesc> table;
    unordered_map<string, uint16_t> symIndex;

public:
    SymbolTable(){}
    SymbolTable(const SymbolTable&) = delete;
    SymbolTable& operator=(const SymbolTable&) = delete;

    // Dodavanje simbola u tabelu
    void addSymbol(const std::string name, uint32_t offs, string section, int flags,int sectionIndex = 0,symbolType symType=NOTYPE);

    // Dohvatanje simbola iz tabele
    SymbolTableDesc *getSymbol(const std::string &name)
    {
        if (symIndex.find(name) != symIndex.end())
        {
            return &table[symIndex[name]];
        }
        else
        {
            return nullptr;
        }
    }

    // Dodavanje reference za nedefinisan simbol
    void addReference(const std::string &name, string section, uint32_t referenceAddress);

    // Ažuriranje adresa za sve reference kada je simbol definisan
    void resolveReferences(const std::string &name);

    // Provera da li je simbol definisan
    int isDefined(const std::string &name)
    {
        if (symIndex.find(name) != symIndex.end())
        {
            return symIndex.find(name) != symIndex.end() && (table.at(symIndex[name]).flags | 0x1);
        }
        return 0;
    }

    void setGlobal(string symbol) { table[symIndex[symbol]].flags |= GLOBAL_FLAG; }

    int checkSymbol(string symbol);

    int symbolInSection(string symbol,string section){
        return table[symIndex[symbol]].section_index==sections[section].index;
    }
    
    vector<SymbolTableDesc> getTable(){ return table;}

    // Ispis tabele simbola (za debug)
    void printTable();
    void printToFile(FILE*);

    string retSymType(symbolType s);

};
extern SymbolTable symTable;

#endif // _symboltable_hpp_
