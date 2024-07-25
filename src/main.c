#include <stdio.h>
#include <string.h>
#include <ctype.h>


int strindex(char* input){
	int base = 0;

	//check immediate designator "#" if yes skip it
	if(input[0] == '#'){
		printf("# was skipped and recognized");
	base++; };

	int i = 0;
	//increment i if current pointer is not a whitespace or newline
	while (input[base+i] != ' ' || input[base+i] != '\n'){
	i++;
	};
	//return i as index for the length
	return i;
};



int main (int argc,char* argv[]){

struct Instruction {
	char* instruction;
	int binary;
	};

// example: # instructions[i].instruction # takes instruction out of struct nr i
struct Instruction instructions[34] = {
	
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

//check if no Arguments were given
if (argc == 1){
	printf("Error: no Arguments Were given");
	return 0;
	};
//File Handle input
FILE* fhInput;
//File Handle Output
FILE* fhOutput;

	//open Input File in Read Mode RETURN if File could no be Opened
	
	fhInput = fopen("compileme.ass","r");

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
	char input[30];
	fgets(input, 30, fhInput);
	char* assembly = &input[0];
	printf("file Contents:\n%s", input);

	//loop and read one word per Loop
	int hopper = 0;
	int strlength = strindex(assembly[hopper]);
	






		//assemble OPCode
		int i;
		//Loop over every "Struct in Array"
		for (i = 0;i<34;i++){
		int index = 0;
		//compare Struct with input string
		//strcmp(instructions[index].instruction, )


	index++;
	};
		
		//assemble Args	
		
		if (input[0] == '#'){
	//skip Assembly for ARG1 and use direct binaries of input
	//memcpy()
	};




//Close Input File
fclose(fhInput);
//Close Output File
fclose(fhOutput);
};


