#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../include/search.h"
#include "../include/instructions.h"
#include "../include/log.h"
#include "../include/flags.h"

#define MAX_LINE_LENGTH 64
	def_Instruction instructions[] = {
	
	
	//OPCode
	//NEED TO ADD IMMEDIATE LOGIC
	{"add", 0},	{"sub", 1},
	{"and", 2},	{"or", 3},
	{"not", 4},	{"xor", 5},
	{"call", 8},	{"ret", 9},
	{"=", 32},	{"!=", 33},
	{"<", 34},	{"<=", 35},
	{">", 36},	{">=", 37},
	{"always", 38},
	
	//Arguments
	{"ra", 0},	{"rb", 1},
	{"rc", 2},	{"rd", 3},
	{"re", 4},	{"rf", 5},
	{"in", 7},	{"lram", 8},
	{"pop", 9},

	//Result
	{"ra", 0},	{"rb", 1},
	{"rc", 2},	{"rd", 3},
	{"re", 4},	{"rf", 5},
	{"counter", 6},	{"out", 7},
	{"sram", 8},	{"push", 9},
	};


int main (int argc,char* argv[]){ 

//File Handle input
FILE* fhInput;
//File Handle Output
FILE* fhOutput;
	
if (argc == 1) {
	error_log("no Arguments were given, specify a file to be assembled");
	return 0;
	};

	//Flags Handling


	def_flags flags;
	initializeFlags(&flags);
	parseFlags(argc, argv, &flags);
	printFlags(&flags);
	//allocate outputFile array
	char* outputFile;
	//Allocate 
	if (flags.outFile != NULL) {
	outputFile = malloc(strlen("output/") + strlen(flags.outFile) + strlen(".bn") + 1);
	
	if (outputFile == NULL) {
		error_log("[ERROR] Memory Allocation for outputFile Failed");
		return 0;
		};
	//copy outFile to outputFIle and add .bn
	appendExtension(outputFile, flags.outFile);
	}else{
	//copy Default to outputFile
		error_log("[Warning] No Output File Specified, using Default (out.bn)\n");
		outputFile = malloc(strlen("output/out.bn") + 1);
		if (outputFile == NULL) {
		error_log("[ERROR] Memory Allocation for outputFile Failed");
		return 0;
		};
		outputFile = "output/out.bn";
		};
	


	//open output file in write mode RETURN if failed
	if (outputFile != NULL) {
	fhOutput = fopen(outputFile, "wb");
	};
	if(fhOutput == NULL) {
	error_log("[ERROR] Output File could not be Opened");
	return 1;
	};


	//open Input File in Read Mode RETURN if File could no be Opened
	if (flags.inFile[0] != NULL) {
	fhInput = fopen(flags.inFile[0],"r");
	}else{
	error_log("no Input File was Specified");
	};
	//check if file was opened
	if (fhInput == NULL){
	error_log("Error, No File could be opened");
	return 0;
	};
	printf("file was opened");	


	int fhi_index = 0;
	int fho_index = 0;

	char* line;
	//Assemble one Line at a time
	while ((line = readNextLine(fhInput)) != NULL){

		//compare one line
		int lineloc = 0; 
		def_Instruction *instructionP = &instructions[0];

		//hopper = current word location
		int hopper = 0;
		while (lineloc < 4){
			int strlength = strindex(line,hopper);
			//Check if token starts with a number
			if (line[hopper] >=48 && line[hopper]  <= 57){
			//handle immediate Writing Here
				printf("immediate was Written\n");
				hopper = hopper + strlength + 1;
			}else{
				int result = compare(instructionP, line, strlength, hopper);

				if (result >= 0){
					printf("result found at index %d\n",result);

					//Writing Logic Here
					hopper = hopper + strlength + 1;
					printf("hopper increased:%d\n",strlength);
				}else{
				return -1;
				};
			};
		lineloc++;
		};
	};
	if (line = readNextLine(fhInput) == NULL) {
		printf("File is finnished reading");
		};
		//assemble OPCode





free(outputFile);

//Close Input File
fclose(fhInput);
//Close Output File
fclose(fhOutput);
};


