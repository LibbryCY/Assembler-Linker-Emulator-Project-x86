#!/bin/bash

# Nazivi ulaznih fajlova
LEX_FILE="./misc/flex.l"
YACC_FILE="./misc/bison.y"
MAIN_FILE="./src/main.cpp"
DEFINITIONS_FILE="./src/definitions.cpp"
INSTRUCTIONS_FILE="./src/instructions.cpp"
DIRECTIVES_FILE="./src/directives.cpp"
SYMBOLTABLE_FILE="./src/symboltable.cpp"
ASM_FILE="./src/asembler.cpp"
RELOCTABLE_FILE="./src/realoctable.cpp"

# Nazivi izlaznih fajlova
LEX_OUTPUT="./misc/lex.yy.c"
YACC_OUTPUT="./misc/bison.tab.c"
PARSER_HEADER="./misc/bison.tab.h"
OUTPUT_EXECUTABLE="asembler"

# Generisanje parsera
bison -d -o $YACC_OUTPUT $YACC_FILE 
if [ $? -ne 0 ]; then
    echo "Greska pri generisanju parsera (bison)"
    exit 1
fi

# Generisanje leksickog analizatora
flex -o $LEX_OUTPUT $LEX_FILE
if [ $? -ne 0 ]; then
    echo "Greska pri generisanju leksickog analizatora (flex)"
    exit 1
fi

# Kompajliranje svih izvora
g++ -o $OUTPUT_EXECUTABLE $LEX_OUTPUT $YACC_OUTPUT $MAIN_FILE $INSTRUCTIONS_FILE $DIRECTIVES_FILE $DEFINITIONS_FILE $SYMBOLTABLE_FILE $ASM_FILE $RELOCTABLE_FILE -lfl
if [ $? -ne 0 ]; then
    echo "Greska pri kompajliranju (g++),Asembler"
    exit 1
fi

# Nazivi ulaznih fajlova
LINK_FILE="./src/linker.cpp"
LMAIN_FILE="./src/linkermain.cpp"
OUTPUT_LINKER="linker"

# Kompajliranje svih izvora
g++ -o $OUTPUT_LINKER $LMAIN_FILE $LINK_FILE $RELOCTABLE_FILE $SYMBOLTABLE_FILE -lfl
if [ $? -ne 0 ]; then
    echo "Greska pri kompajliranju (g++),Linker"
    exit 1
fi

# Nazivi ulaznih fajlova
EMULATOR_FILE="./src/emulator.cpp"
EMAIN_FILE="./src/emumain.cpp"
OUTPUT_EMULATOR="emulator"

# Kompajliranje svih izvora
g++ -o $OUTPUT_EMULATOR $EMAIN_FILE $EMULATOR_FILE -lfl
if [ $? -ne 0 ]; then
    echo "Greska pri kompajliranju (g++),Emulator"
    exit 1
fi

echo "Uspesno kompajlirano! Izlazni fajlovi: $OUTPUT_EXECUTABLE,$OUTPUT_LINKER,$OUTPUT_EMULATOR"
