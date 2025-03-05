#include "../inc/asembler.hpp"
#include "../inc/symboltable.hpp"


void Asembler::run()
{
    
}
void Asembler::resolveAllRealocs()
{
    for (auto &section : sections)
    {
        string name = section.first;
        Section sec = section.second;

        sec.relocTable.resolveRealocations();

        
    }
}