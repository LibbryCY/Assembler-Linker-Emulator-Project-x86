#ifndef _RELOC_TABLE_HPP_
#define _RELOC_TABLE_HPP_

#include <vector>
#include <unordered_map>
#include <string>
#include <stdint.h>
#include <iostream>
//#include "directives.hpp"

//#include "asembler.hpp"

using namespace std;

enum RelocType {
	ABSOLUTE,
    RELATIVE
};

class RelocTable;


// Struktura koja predstavlja unos u tabeli realokacija
struct RelocationDesc {
    uint32_t offset;      // Offset u sekciji gde je potrebno realokacija
    RelocType type;
    string symbol; // Indeks simbola u tabeli simbola
    string section; // Ime sekcije
    int adend;
};

class RelocTable {
private:
    vector<RelocationDesc> table; // Tabela realokacija

public:
    // Dodavanje unosa u tabelu realokacija
    void addRelocation(uint32_t offset, string sym, string sec,RelocType type,int adend=0) {
        RelocationDesc entry;
        entry.offset = offset;
        entry.symbol = sym;
        entry.section = sec;
        entry.type = type;
        table.push_back(entry);
    }

    // Ispisivanje tabele realokacija za debug
    void printTable() ;

    // Dohvatanje tabele realokacija
    vector<RelocationDesc>& getTable() {
        return table;
    }

    void resolveRealocations();
};
extern RelocTable relTable;


#endif // _RELOC_TABLE_HPP_
