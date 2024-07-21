#include <stdio.h>
#include <string.h>
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
	if ((fhInput = fopen(argv[1],"r")) == NULL){
	fprintf(stderr, "Error, No File could be opened");
	return 0;
	};

	//Open output File in Write Mode
	if ((fhOutput = fopen ("TcBinary.bn", "wb")) == NULL){
	fprintf(stderr, "Error, Binary file could not be Created");
	return 0;
	};
	
	int fhI_Index = 0;
	int fhO_Index = 0;
	//Input file Indexer, takes filepointer and current input index,Moves to next Whitespace and returns Token and new Index 
	int InputFile_Indexer (FILE* fhInput,int fhI_Index){
	int i = 0;
	if (fhInput[fhI_Index] !== " "){
		fprintf(stdout, "Not a Whitespace: %c",fhInput[fhI_Index]);
		};
	};

};
