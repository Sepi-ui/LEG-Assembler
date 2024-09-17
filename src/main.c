#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../utils/search.h"
// example: # instructions[i].instruction # takes instruction out of struct nr i






























typedef struct Instruction {
	char* instruction;
	int binary;
	}def_Instruction;



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



//check if no Arguments were given !!!BETTER ERRORCHECKING!!!!
if (argc == 1){
	printf("Error: no Arguments Were given");
	return 0;
	};
//File Handle input
FILE* fhInput;
//File Handle Output
FILE* fhOutput;

	//open Input File in Read Mode RETURN if File could no be Opened
	
	fhInput = fopen(argv[1],"r");

	if (fhInput == NULL){
	fprintf(stderr, "Error, No File could be opened");
	return 0;
	};
	
	

	//open output file in write mode RETURN if failed
	if ((fhOutput = fopen ("tcbinary.bn", "wb")) == NULL){
	fprintf(stderr, "error, binary file could not be created");
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
	//index for while Loop, used to jump over structs	
	int i = 0;
	//base = # skipped
	int base = 0;
	//hopper = current word location
	int hopper = 0;
	//returns word length 	
	int strlength = strindex((assembly+hopper),hopper);
	printf("string reader returned length of: %i\n", strlength);

	//Check for # and increment base if present
	if (buffer[hopper+base] == '#'){
	base++;	
	printf("base:%d\n",base);
	};
	//Go through all instructions until match
	while (i<35){
	
	def_Instruction *p = &instructions[0];
	char* wordloc = (assembly);
	int compare = memcmp((void*)p[i].instruction,&assembly[hopper + base],(strlength));	
	printf("current Assembly Input:%s\ncurrent struct Location:%s\n",(assembly + hopper),p);
	if(compare == 0){
	printf("FOUND MATCH AT INDEX:%d\n",i);	
	return 0;
	}else{
	printf("No Match found! Index is: %d\n",i);
	i++;
	};



};	

		//assemble OPCode






//Close Input File
fclose(fhInput);
//Close Output File
fclose(fhOutput);
};


