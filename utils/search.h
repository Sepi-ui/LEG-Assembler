#ifndef SEARCH_H
#define SEARCH_H

#include "instructions.h"
int strindex(char* input, int hopper);
int compare (def_Instruction* ,char* ,int, int);
void appendExtension(char* outputFile, char* outFile);
char* readNextLine(FILE* file);
#endif
