#include <stdio.h>
#include <stdlib.h>
#include "../misc/bison.tab.h"
#include "../inc/asembler.hpp"
#include "../inc//symboltable.hpp"

using namespace std;

extern FILE *yyin, *yyout;

int main(int argc, char *argv[])
{
  start_of_section("UND");

  if (argc != 2 && argc != 4)
  {
    cout << "Error,incorrect arguments!" << endl;
    return -1;
  }
  if (!(string(argv[1]) == "-o"))
  {
    cout << "Error,incorrect argument options!" << endl;
    return -1;
  }
  char out[32] = "out.o";
  char *output_file = out;
  char *input_file = argv[argc - 1];

  if (argc == 4)
  {
    output_file = argv[2];
  }

  // Otvori fajl za čitanje
  FILE *inputFile = fopen(input_file, "r");
  if (inputFile == nullptr)
  {
    perror("Error opening input file");
    return -1;
  }

  // Otvori pomocni text output fajl
  FILE *helpFile = fopen(output_file, "w");
  if (helpFile == nullptr)
  {
    perror("Error opening output file");
    fclose(inputFile);
    return -1;
  }

  char line[256];
  std::vector<uint32_t> binaryCode;
  yyin = inputFile;

  if (yyparse() != 0)
    {
      fprintf(stderr, "Parsing error\n");
      return -2;
    }

  for ( auto &section : sections)
  {

    //outputFile.write(reinterpret_cast<const char *>(&code), sizeof(code));
  }

  symTable.printToFile(helpFile);

  fclose(inputFile);
  fclose(helpFile);

  return 0;
}
