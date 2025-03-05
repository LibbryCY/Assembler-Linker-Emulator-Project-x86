#include <iostream>
#include <vector>
#include <unordered_map>
#include "../inc/linker.hpp"
#include <regex>
using namespace std;

int main(int argc, char* argv[]){

  Linker& linker = Linker::getInstance();

  vector<string> input_files;
  string out_file = "output.hex";
  int hex = 0;
  unordered_map<string, uint32_t> placeAddrs;

  for(int i = 1 ; i < argc ; i++){
    string arg = argv[i];

    if(arg == "-hex"){
      hex = 1;
    }
    else if(arg == "-o"){
      if(i + 1 < argc){
        out_file = argv[i+1];
        i++;
      }
      else{
        cout << "Error: No output file specified.." << endl;
        return -1;
      }
    }
    else if (regex_match(arg, regex("^-place=([a-zA-Z._][a-zA-Z._0-9]*)@(0x[0-9a-fA-F]+)$"))) {
        smatch groups;
        regex_search(arg, groups, regex("^-place=([a-zA-Z._][a-zA-Z._0-9]*)@(0x[0-9a-fA-F]+)$"));
        string section = groups[1];
        string addr = groups[2];
        placeAddrs[section] = stoul(addr, nullptr, 16);
    }
    else{
      input_files.push_back(arg);
    }

  }
  linker.filesToLink=input_files.size();

  if(!hex){
    cout << "Error: Not specified -hex or -realocatable option.." << endl;
    return -1;
  }


  int ret = linker.run(1,out_file,input_files,placeAddrs);

  if(ret){
    cout << "Error while linking.."<< endl;
  }

  
}