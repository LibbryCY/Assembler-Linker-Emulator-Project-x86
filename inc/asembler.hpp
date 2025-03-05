
#ifndef _asembler_h
#define _asembler_h
#include <string>

using namespace std;

class Asembler
{
private:

    int isFinished = 0;

public:
    int fileCounter = 0;
    static Asembler &getInstance()
    {
        static Asembler instance;
        return instance;
    }
    int getIsFinished() { return isFinished; }
    void setIsFinished(int i) { isFinished = i; }

    //SymbolTable *getSymbolTable() { return &symTable; }
    //RelocTable *getRealocTable() { return &relTable; }

    void run();
    static void resolveAllRealocs();
};

#endif //!_asembler_h