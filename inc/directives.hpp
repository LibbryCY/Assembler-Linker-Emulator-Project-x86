#ifndef _directives_h
#define _directives_h

#include<string>
#include "asembler.hpp"

using namespace std;

void handle_label(string);
void handle_global(string);
void handle_extern(string);
void handle_word(string);
void handle_word(int);
void handle_end();
void handle_ascii(string);
void handle_skip(int);
void start_of_section(string);
void close_previous_section();
void patch_addres(int,int);

void handle_type(string,string);

#endif //_directives_h