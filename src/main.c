#include <stdio.h>
#include <string.h>
#include <ctype.h>

// example: # instructions[i].instruction # takes instruction out of struct nr i

struct Instruction {
	char* instruction;
	int binary;
	};



	struct Instruction instructions[] = {
	
	
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

int strindex(char* input,int hopper){
	int base = 0;
	char buffer[20];
	char* bufferP = buffer;
	memcpy(bufferP,input,20);
	printf("Copied line to strindex for parsing:\n%s\n",buffer);
	//check immediate designator "#" if yes skip it
	if(buffer[base] == '#'){
		printf("# was skipped and recognized\n");
	base++; };
	int count = 0;
	int i = base;
	//increment i if current pointer is not a whitespace or newline
	//
	//
	while (i<20){

	if (buffer[i] == 10 || buffer[i] == 32){

		printf("done with Parsing\n");
		//return i as index for the length
		return count;
	}else{
		printf("skipped Character:%c\n",buffer[i]);
		count++;
		i++;
		};
	};
};


int main (int argc,char* argv[]){



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

	int i = 0;
	//hopper shows current line location
	int hopper = 0;
	//returns word length 	
	int strlength = strindex((assembly+hopper),hopper);
	printf("string reader returned length of: %i\n", strlength);
	int arrsize = sizeof(struct Instruction);
	printf("Size of Array is %d\n",arrsize);	
	//Go through all instructions until match
	while (i<34){
	
	struct Instruction *p = &instructions[i];
	char* wordloc = (assembly);
	int compare = memcmp(*p,(assembly+hopper),strlenth);	
	if(compare == 0){
	printf("FOUND MATCH AT INDEX:%d\n",i);	
	return 0;
	}else{
	i++;
	
};

	



};	

		//assemble OPCode






//Close Input File
fclose(fhInput);
//Close Output File
fclose(fhOutput);
};


