#include <stdio.h>
#include <string.h>
int main (int argc,char* argv[]){


struct Ass_Lookup{

	





}
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

	m//open output file in write mode
	if ((fhoutput = fopen ("tcbinary.bn", "wb")) == null){
	fprintf(stderr, "error, binary file could not be created");
	return 0;
	};
	
	int fhi_index = 0;
	int fho_index = 0;
	//input file indexer, takes filepointer and current input index,moves to next whitespace and returns token and new index 
	int inputfile_indexer (file* fhinput,int fhi_index){
	int i = 0;
	int isnumber = isnum(fhinput[fhi_index])
	while (fhinput[fhi_index] )
	if (fhInput[fhI_Index] !== " "){
		fprintf(stdout, "Not a Whitespace!");
	};
};
