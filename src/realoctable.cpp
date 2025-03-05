#include "../inc/realoctable.hpp"
#include "../inc/symboltable.hpp"

RelocTable relTable;

void patch_addres(int addr, int value, string section)
{
    sections[section].content[addr + 0] = value & 0xff;
    sections[section].content[addr + 1] = (value >> 8) & 0x0f | sections[section].content[addr + 1] & 0xf0;
}

void RelocTable::printTable()
{
    cout << "***** RELOCATION TABLE *****" << endl;
    for (const RelocationDesc &entry : table)
    {
        cout << "Offset: 0x" << hex << entry.offset
             << " Symbol: " << entry.symbol
             << " Section: " << entry.section
             << endl;
    }
    cout << endl;
}
void RelocTable::resolveRealocations()
{
    SymbolTable *sym = &symTable;
    RelocTable *rel = &relTable;

    if (table.empty())
        return;

    for (RelocationDesc &entry : table)
    {
        if (entry.type == RELATIVE)
        {
            rel->addRelocation(entry.offset, entry.symbol, entry.section, RELATIVE);
            continue;
        }

        // isAbsolute or global
        rel->addRelocation(entry.offset, entry.symbol, entry.section, ABSOLUTE);
    }
}