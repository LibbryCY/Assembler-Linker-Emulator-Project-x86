#include <iostream>
#include <cstdio>  
#include "../inc/emulator.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "Invalid number of arguments.." << endl;
        return -1;
    }

    char* filename = argv[1];
  
    FILE* inputFile = fopen(filename, "rb");
    if (!inputFile) {
        cout << "Failed to open file: " << filename << endl;
        return -1;
    }

    Emulator& emulator = Emulator::getInstance();

    int ret = emulator.emulation(inputFile);

    fclose(inputFile);  

    if (ret) {
        cout << "Error: Failed to emulate.." << ret << endl;
        return -1;
    }

    return 0;
}
