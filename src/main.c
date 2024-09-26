#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include "../utils/search.h"
#include "../utils/instructions.h"
#include "../utils/error.h"
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
if (argc == 1) {
	error_log("no Arguments were given");
	return 0;
	};
//File Handle input
FILE* fhInput;
//File Handle Output
FILE* fhOutput;

	//open Input File in Read Mode RETURN if File could no be Opened
	
	fhInput = fopen(argv[1],"r");

	if (fhInput == NULL){
	error_log("Error, No File could be opened");
	return 0;
	};
	
	

	//open output file in write mode RETURN if failed
	if ((fhOutput = fopen ("tcbinary.bn", "wb")) == NULL){
	error_log("error, binary file could not be created");
	return 0;
	};
	
	int fhi_index = 0;
	int fho_index = 0;
	//Assembles one line at a time
	char buffer[30];
	//Get string until newline 
	fgets(buffer, 30, fhInput);
	char* assembly = &buffer[0];
	printf("line Contents:\n%s", buffer);

	//compare one line
	int lineloc = 0; 
	def_Instruction *instructionP = &instructions[0];

	//hopper = current word location
	int hopper = 0;
	//base = # skipped
	int base = 0;
	//Check for # and increment base if present
	if (buffer[hopper+base] == '#'){
	base++;	
	};
	hopper = base;
	while (lineloc < 4){
	int strlength = strindex(assembly,hopper);
	int result = compare(instructionP, assembly, strlength, hopper);

		if (result >= 0){
		printf("result found at index %d\n",result);
		hopper = hopper + strlength + 1;
		printf("hopper increased:%d\n",strlength);
		}else{
		return -1;
		};
	lineloc++;
	};

		//assemble OPCode






//Close Input File
fclose(fhInput);
//Close Output File
fclose(fhOutput);
};


