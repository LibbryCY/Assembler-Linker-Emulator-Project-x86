#include "../inc/linker.hpp"
#include <regex>

void Linker::processAssemblerOutput(const std::string &filename, int index)
{
    std::ifstream inputFile(filename);
    std::string line;

    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    bool readingSymbols = false;
    bool readingSections = false;
    bool readingRelocations = false;

    while (std::getline(inputFile, line))
    {
        static string section = "";
        if (line.find("Symbol") != std::string::npos && line.find("Value") != std::string::npos)
        {
            readingSymbols = true;
            readingSections = false;
            readingRelocations = false;
            std::getline(inputFile, line); // pokupi ---------...
            continue;
        }

        if (line.find("***** SECTIONS *****") != std::string::npos)
        {
            readingSymbols = false;
            readingSections = true;
            readingRelocations = false;
            continue;
        }

        if (line.find("***** REALOCATIONS *****") != std::string::npos)
        {
            readingSymbols = false;
            readingSections = false;
            readingRelocations = true;
            continue;
        }
        std::regex emptyLineRegex(R"(^\s*$)");

        // Citanje simbola
        if (readingSymbols)
        {
            if (regex_match(line, emptyLineRegex))
            {
                continue;
            }
            std::istringstream iss(line);
            SymbolTableDesc entry;
            string type = "";

            // Parsiranje linije u odgovarajuće delove
            iss >> entry.name >> std::hex >> entry.offset >> entry.flags >> type >> entry.section_index >> entry.section_name;
            //cout<< entry.name<<" | " << entry.offset<<" | " <<hex<< entry.flags <<" | "<< type <<" | "<< entry.section_index <<" | "<<entry.section_name<<endl;
            if (type == "FUNC")
            {
                entry.type = FUNC;
            }
            if (type == "DATA")
            {
                entry.type = DATA;
            }
            else
                entry.type = NOTYPE;
            fileblocks[index].symTable.addSymbol(entry.name, entry.offset, entry.section_name, entry.flags, entry.section_index);
            fileblocks[index].symTable.getSymbol(entry.name)->type=entry.type;
        }
        else if (readingSections)
        {
            if (regex_match(line, emptyLineRegex))
            {
                continue;
            }

            if (line[0] == '#')
            {
                std::istringstream iss(line);
                string b1, b2;
                iss >> b1 >> b2;
                section = b1.substr(1);
                fileblocks[index].sectionNames.push_back(b1.substr(1));
                fileblocks[index].sectionSizes.push_back(stoul(b2, nullptr, 16));
            }
            else
            {
                std::istringstream iss(line);
                string b1, b2, b3, b4;
                iss >> b1 >> b2 >> b3 >> b4;

                fileblocks[index].sectionContent[section].push_back(stoul(b1, nullptr, 16));
                fileblocks[index].sectionContent[section].push_back(stoul(b2, nullptr, 16));
                fileblocks[index].sectionContent[section].push_back(stoul(b3, nullptr, 16));
                fileblocks[index].sectionContent[section].push_back(stoul(b4, nullptr, 16));
            }
        }
        else if (readingRelocations)
        {
            if (regex_match(line, emptyLineRegex))
            {
                continue;
            }
            std::istringstream iss(line);
            RelocationDesc entry;

            string garbage;
            char c;
            // Parsiranje linije u odgovarajuće delove
            iss >> garbage >> entry.section >> entry.symbol >> std::hex >> entry.offset >> c;

            fileblocks[index].relTable.addRelocation(entry.offset, entry.symbol, entry.section, (c == 'A') ? (ABSOLUTE) : (RELATIVE));
        }
    }
    
    inputFile.close();
}

int Linker::run(int hex, string outF, vector<string> inputF, unordered_map<string, uint32_t> &placeArgs)
{
    filesToLink = inputF.size();
    FileBlock fbs[filesToLink];
    fileblocks = fbs;
    // Ucitaj fajlove
    for (int i = 0; i < filesToLink; i++)
    {
        processAssemblerOutput(inputF[i], i);
    }
    // Spoji sadrzaj
    for (int i = 0; i < filesToLink; i++)
    {
        int res = mergeFileBlocks(fileblocks[i]);
        if (res < 0)
            return res;
    }

    // Resi relokacione zapise
    int res = makeOutputFile(outF, placeArgs);

    return res;
}

int Linker::makeOutputFile(string outF, unordered_map<string, uint32_t> &placeSections)
{

    for (auto &place : placeSections)
    {
        sectionOnAddr.push_back(place);
    }

    // Sortiranje po int vrednosti
    std::sort(sectionOnAddr.begin(), sectionOnAddr.end(), [](const std::pair<std::string, uint64_t> &a, const std::pair<std::string, uint64_t> &b)
              { return a.second < b.second; });

    uint64_t address = 0;
    for (auto &sec : sectionOnAddr)
    {
        if (sec.second < address)
        {
            cout << "Error: Sections overlaping.. " << sec.second << " < " << address << endl;
            return -1;
        }
        if (!(linkerSymbolTable.getSymbol(sec.first)->flags & SECTION_FLAG))
        {
            cout << "Error: Section.." << endl;
            return -1;
        }
        address = sec.second + sectionContent[sec.first].size();
    }
    // Preostale sekcije
    for (int i = 0; i < sectionNames.size(); i++)
    {
        if (!sectionExists(sectionOnAddr, sectionNames[i]))
        {
            pair<string, uint64_t> a;
            a.first = sectionNames[i];
            a.second = address;
            sectionOnAddr.push_back(a);
            address += sectionContent[sectionNames[i]].size();
        }
    }

    // Resavanje relokacija
    for (auto &rel : linkerRelocTable.getTable())
    {
        SymbolTableDesc *symbol = linkerSymbolTable.getSymbol(rel.symbol);
        if (!symbol)
        {
            cout << "Error: Can't find symbol " << rel.symbol << " while resolving rels.." << endl;
            return -1;
        }

        if (rel.type == ABSOLUTE)
        {
            int symBaseAddr = findSectionBaseAddr(symbol->section_name);
            if (symBaseAddr == -1)
            {
                cout << "Error: Can't find section base address for section " << symbol->section_name << " while resolving rels.." << endl;
                return -1;
            }
            int newVal = symBaseAddr + symbol->offset;
            patch32(rel.section, rel.offset, newVal); // offset is adjusted in merge part
        }
        else
        {
            int symBaseAddr = findSectionBaseAddr(symbol->section_name);
            if (symBaseAddr == -1)
                return -1;
            int newVal = symBaseAddr + symbol->offset;
            patch12(rel.section, rel.offset, newVal);
        }
    }

    // Pravljenje i upis u sam fajl

    FILE *file = fopen(outF.c_str(), "w");
    if (!file)
    {
        perror("Error opening output file");
        return -1;
    }

    for (auto &section : sectionOnAddr)
    {
        std::string sectionName = section.first;
        int baseAddress = section.second;
        std::vector<uint8_t> content = sectionContent[sectionName];

        // fprintf(file, "Section: %s\n", sectionName.c_str());
        for (int i = 0; i < content.size(); i += 8)
        {
            fprintf(file, "%04x: ", baseAddress + i);
            for (int j = 0; j < 8 && (i + j) < content.size(); ++j)
            {
                fprintf(file, "%02x ", content[i + j]);
            }
            fprintf(file, "\n");
        }
    }

    fclose(file);

    return 0;
}

int Linker::mergeFileBlocks(FileBlock &fileBlock)
{

    // 1. Spajanje sadržaja sekcija
    for (const auto &sectionName : fileBlock.sectionNames)
    {
        if (sectionContent.find(sectionName) != sectionContent.end())
        {
            sectionContent[sectionName].insert(
                sectionContent[sectionName].end(),
                fileBlock.sectionContent[sectionName].begin(),
                fileBlock.sectionContent[sectionName].end());
        }
        else
        {
            // Ako sekcija ne postoji, dodaj novu sekciju
            sectionNames.push_back(sectionName);
            sectionContent[sectionName] = fileBlock.sectionContent[sectionName];
        }
    }

    // 2. Spajanje simbola
    for (auto &symbol : fileBlock.symTable.getTable())
    {
        if (!linkerSymbolTable.getSymbol(symbol.name))
        {
            int adjustedOffset = symbol.offset + getSectionOffset(symbol.section_name) - fileBlock.sectionContent[symbol.section_name].size();
            linkerSymbolTable.addSymbol(symbol.name, adjustedOffset, symbol.section_name, symbol.flags, symbol.section_index);
            linkerSymbolTable.getSymbol(symbol.name)->type=symbol.type;
        }
        else
        {
            auto existingSymbol = linkerSymbolTable.getSymbol(symbol.name);
            //cout << "SYM " << existingSymbol->name << ":" << existingSymbol->type << " vs " << "SYM " << symbol.name << ":" << symbol.type << endl;

            if (existingSymbol->flags & GLOBAL_FLAG && (symbol.flags & GLOBAL_FLAG))
            {
                std::cerr << "Error: Symbol conflict detected for " << symbol.name << std::endl;
                return -1;
            }
            else
            {
                if (existingSymbol->type != symbol.type)
                {
                    std::cerr << "Error: Symbol conflict type for " << symbol.name << std::endl;
                    return -1;
                }
                if (existingSymbol->flags & EXTERN_FLAG && symbol.flags & GLOBAL_FLAG)
                {
                    int adjustedOffset = symbol.offset + getSectionOffset(symbol.section_name) - fileBlock.sectionContent[symbol.section_name].size();
                    linkerSymbolTable.addSymbol(symbol.name, adjustedOffset, symbol.section_name, symbol.flags, symbol.section_index);
                }
                // ext i ext nista, glob i ext vec definisan
            }
        }
    }

    // 3. Spajanje relokacionih zapisa
    for (auto &rel : fileBlock.relTable.getTable())
    {
        // Prilagodi relokacione zapise za nove ofsete sekcija
        int adjustedOffset = rel.offset + getSectionOffset(rel.section) - fileBlock.sectionContent[rel.section].size();
        linkerRelocTable.addRelocation(adjustedOffset, rel.symbol, rel.section, rel.type, adjustedOffset);
    }

    // 4. Ažuriranje veličina sekcija
    sectionSizes.clear();
    for (const auto &sectionName : sectionNames)
    {
        sectionSizes.push_back(sectionContent[sectionName].size());
    }
    return 0;
}

int Linker::getSectionOffset(const std::string &sectionName)
{
    return sectionContent[sectionName].size();
}

int Linker::sectionExists(std::vector<std::pair<std::string, uint64_t>> &sectionOnAddr, std::string &sectionName)
{
    for (const auto &section : sectionOnAddr)
    {
        if (section.first == sectionName)
        {
            return 1;
        }
    }
    return 0;
}

int Linker::findSectionBaseAddr(std::string &sectionName)
{
    for (auto &section : sectionOnAddr)
    {
        if (section.first == sectionName)
        {
            return section.second;
        }
    }
    return -1; // Ako sekcija ne postoji
}

void Linker::patch32(string section, int offset, uint32_t newValue)
{
    // Ažuriraj sekciju na odgovarajućem mestu
    sectionContent[section][offset] = newValue & 0xFF;
    sectionContent[section][offset + 1] = (newValue >> 8) & 0xFF;
    sectionContent[section][offset + 2] = (newValue >> 16) & 0xFF;
    sectionContent[section][offset + 3] = (newValue >> 24) & 0xFF;
}

void Linker::patch12(string section, int offset, uint32_t newValue)
{
    sectionContent[section][offset] = newValue & 0xFF;
    sectionContent[section][offset + 1] = (newValue >> 8) & 0x0F | sectionContent[section][offset + 1] & 0xf0;
    ;
}

void Linker::printRelocTable()
{
    cout << "\n***** REALOCATIONS *****" << endl;
    for (auto &rel : linkerRelocTable.getTable())
    {
        cout << "#rela " << rel.section << " " << rel.symbol << "  0x" << std::hex << rel.offset << endl;
    }
    cout << endl;
}

void Linker::printFileRelocTable(int i)
{
    cout << "\n***** REALOCATIONS *****" << endl;
    for (auto &rel : fileblocks[i].relTable.getTable())
    {
        cout << "#rela " << rel.section << " " << rel.symbol << "  0x" << std::hex << rel.offset << endl;
    }
    cout << endl;
}

void Linker::printSectionContents()
{
    cout << "\n***** SECTIONS *****" << endl;
    int k = 0;
    for (auto &section : sectionNames)
    {
        cout << "#" << section << " size: " << std::hex << sectionSizes[k++] << endl;
        for (int i = 0; i < sectionContent[section].size(); i += 4)
        {
            printf("%02x %02x %02x %02x\n", sectionContent[section][i + 0], sectionContent[section][i + 1], sectionContent[section][i + 2], sectionContent[section][i + 3]);
        }
    }
    cout << endl;
}

void Linker::printSectionContents(int j)
{
    cout << "\n***** SECTIONS *****" << endl;
    int k = 0;
    for (auto &section : fileblocks[j].sectionNames)
    {
        cout << "#" << section << " size: " << std::hex << fileblocks[j].sectionSizes[k++] << endl;
        for (int i = 0; i < fileblocks[j].sectionContent[section].size(); i += 4)
        {
            printf("%02x %02x %02x %02x\n", fileblocks[j].sectionContent[section][i + 0], fileblocks[j].sectionContent[section][i + 1], fileblocks[j].sectionContent[section][i + 2], fileblocks[j].sectionContent[section][i + 3]);
        }
    }
    cout << endl;
}