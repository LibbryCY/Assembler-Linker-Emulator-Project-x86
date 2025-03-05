#ifndef LINKER_HPP
#define LINKER_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "symboltable.hpp"
#include "realoctable.hpp"
using namespace std;

struct FileBlock
{
  unordered_map<string, vector<uint8_t>> sectionContent;
  vector<string> sectionNames;
  vector<int> sectionSizes;
  RelocTable relTable;
  SymbolTable symTable;
};

class Linker
{

public:
  int filesToLink = 0;

  SymbolTable linkerSymbolTable;
  RelocTable linkerRelocTable;

  unordered_map<string, vector<uint8_t>> sectionContent;
  vector<string> sectionNames;
  vector<int> sectionSizes;

  FileBlock *fileblocks;
  vector<pair<string,uint64_t>> sectionOnAddr;

  int mergeFileBlocks(FileBlock &);

  void printSectionContents();
  void printRelocTable();

  int makeOutputFile(string outF, unordered_map<string, uint32_t> &placeSections);
  void processAssemblerOutput(const std::string &filename, int);

public:
  static Linker &getInstance()
  {
    static Linker instance;
    return instance;
  }

  int run(int hex, string outF, vector<string> inputF, unordered_map<string, uint32_t> &placeArgs);

  ~Linker() {}

  void printFileRelocTable(int i);
  void printSectionContents(int j);
  int getSectionOffset(const std::string &sectionName);


  int sectionExists( std::vector<std::pair<std::string,uint64_t>> &sectionOnAddr,  std::string &sectionName);
  int findSectionBaseAddr( std::string& sectionName);
  void patch32(string section,int offset,uint32_t value);
  void patch12(string section,int offset,uint32_t value);
};

#endif