#include "../inc/symboltable.hpp"

string current_section = "";
unordered_map<string, Section> sections;
SymbolTable symTable;

void SymbolTable::addSymbol(const std::string name, uint32_t offs, string section, int flags, int sectionIndex, symbolType symType)
{
    if (symIndex.find(name) == symIndex.end())
    { // nije u tabeli
        SymbolTableDesc desc;
        desc.name = name;
        desc.offset = offs;
        desc.flags = flags;
        desc.section_index = ((sectionIndex == 0) ? (sections.size() - 1) : (sectionIndex));
        desc.section_name = section;

        symIndex[name] = table.size();
        table.push_back(desc);
    }
    else
    {                                                   // u tabeli
        if (table[symIndex[name]].flags & DEFINED_FLAG) // definisan
        {
            cout << "Error: Symbol " << name << " already defined" << endl;
        }
        else // nedefinisan
        {
            table[symIndex[name]].offset = offs;
            table[symIndex[name]].flags |= flags;
            table[symIndex[name]].section_index = sections[section].index;
            table[symIndex[name]].section_name = section;
        }
    }
}

void SymbolTable::addReference(const std::string &name, string section, uint32_t referenceAddress)
{
    if (symIndex.find(name) == symIndex.end())
    {
        SymbolTableDesc desc;
        desc.name = name;
        desc.flags = 0;
        symIndex[name] = table.size();
        table.push_back(desc);
    }

    table[symIndex[name]].references.push_back(ForwardReference(sections[section].index, referenceAddress, section));
}

void SymbolTable::resolveReferences(const std::string &name)
{
    for (ForwardReference ref : table[symIndex[name]].references)
    {
        sections[getSymbol(name)->section_name].relocTable.addRelocation(ref.addr, name, ref.section_name, ABSOLUTE);
        /*
        if(isDefined(name)){
            if(symbolInSection(name,ref.section_name)){
                int value = symTable.getSymbol(name)->offset -4 - ref.addr + 0x0d6d0000;
                sections[ref.section_name].content[ref.addr+0] = value & 0xff;
                sections[ref.section_name].content[ref.addr+1] = (value>>8 & 0xff);
                sections[ref.section_name].content[ref.addr+2] = (value>>16 & 0xff);
                sections[ref.section_name].content[ref.addr+3] = (value>>24 & 0xff);
            }else{
                sections[getSymbol(name)->section_name].relocTable.addRelocation(ref.addr,name,ref.section_name,ABSOLUTE);
            }
        }else{
            if(!(getSymbol(name)->flags & GLOBAL_FLAG)){
                cout<<"Error: Symbol not defined,not global..."<<endl;
            }else{
                sections[getSymbol(name)->section_name].relocTable.addRelocation(ref.addr,name,ref.section_name,ABSOLUTE);
            }
        }   */
    }
    table[symIndex[name]].references.clear();
}

int SymbolTable::checkSymbol(string symbol)
{
    if (symIndex.find(symbol) != symIndex.end())
        return 1;
    return 0;
}

void SymbolTable::printTable()
{
    std::cout << std::left << std::setw(16) << "Symbol"
              << std::setw(10) << "Value"
              << std::setw(10) << "Flags"
              << std::setw(10) << "Section"
              << std::setw(16) << "Section Name" << endl;
    // << "ForwardReference" << std::endl;

    std::cout << std::string(66, '-') << std::endl;

    for (SymbolTableDesc entry : table)
    {
        std::cout << std::left << std::setw(16) << entry.name
                  << std::setw(10) << std::hex << entry.offset
                  << std::setw(10) << std::hex << entry.flags
                  << std::setw(10) << std::hex << entry.section_index
                  << std::setw(16) << entry.section_name;
        std::cout << std::endl; // Nova linija za sledeći unos
    } /*
     if (!sections.empty())
     {
         cout << "\n***** SECTIONS *****" << endl;
         for (auto &pair : sections)
         {
             cout << "#" << pair.first << ":" << pair.second.index << endl;
             for (int i = 0; i < pair.second.content.size(); i += 4)
             {
                 printf("[%02x %02x %02x %02x]\n", pair.second.content[i + 0], pair.second.content[i + 1], pair.second.content[i + 2], pair.second.content[i + 3]);
             }
             // pair.second.relocTable.printTable();
         }
         cout << endl;
     }
     if (!sections.empty())
     {
         cout << "\n***** REALOCATIONS *****" << endl;
         for (auto &rel : relTable.getTable())
         {
             cout << "#rel" << rel.section << " : " << rel.symbol << " -> 0x" << std::hex << rel.offset << endl;
         }
         cout << endl;
     }*/
}
string SymbolTable::retSymType(symbolType s){
    if(s==FUNC)return "FUNC";
    if(s==DATA)return "DATA";
    return "NOTYPE";
}

void SymbolTable::printToFile(FILE *outputFile)
{
    // Zamenjuje std::cout sa fprintf za upis u FILE*
    fprintf(outputFile, "%-16s%-10s%-10s%-10s%-10s%s\n", "Symbol", "Value", "Flags","Type", "Section", "Section Name");
    fprintf(outputFile, "%s\n", std::string(68, '-').c_str());

    for (const SymbolTableDesc &entry : table)
    {
        fprintf(outputFile, "%-16s%-10x%-10x%-10s%-10x%-16s",
                entry.name.c_str(),
                entry.offset,
                (entry.flags),
                retSymType(entry.type).c_str(),
                entry.section_index,
                entry.section_name.c_str());
        fprintf(outputFile, "\n");
    }

    /* for (const SymbolTableDesc &entry : table)
     {
         if (!entry.references.empty())
         {
             fprintf(outputFile, "\n#flink.%s\n", entry.name.c_str());
             for (const auto &ref : entry.references)
             {
                 fprintf(outputFile, "%08x%-4s%-10s%-12s",
                         (ref.addr),"\t",
                         ref.section_name.c_str(),
                         entry.name.c_str());
                 fprintf(outputFile, "\n");
             }
         }

     }*/

    if (!sections.empty())
    {
        fprintf(outputFile, "\n***** SECTIONS *****\n");
        for (const auto &pair : sections)
        {
            fprintf(outputFile, "#%s %d\n", pair.first.c_str(), pair.second.counter);
            for (int i = 0; i < pair.second.content.size(); i += 4)
            {
                fprintf(outputFile, "%02x %02x %02x %02x\n", pair.second.content[i + 0], pair.second.content[i + 1], pair.second.content[i + 2], pair.second.content[i + 3]);
            }
        }
        fprintf(outputFile, "\n");
    }

    if (!sections.empty())
    {
        fprintf(outputFile, "***** REALOCATIONS *****\n");
        for (const auto &rel : relTable.getTable())
        {
            fprintf(outputFile, "#.rela %s %s  0x%x %c\n", rel.section.c_str(), rel.symbol.c_str(), rel.offset, (rel.type == ABSOLUTE) ? ('A') : ('R'));
        }
        // fprintf(outputFile, "\n");
    }
}
