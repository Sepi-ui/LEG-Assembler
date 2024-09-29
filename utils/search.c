#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "instructions.h"
#include "../utils/error.h"

#define MAX_LINE_LENGTH 64
int strindex(char* input, int hopper) {
int count = 0;
int i = hopper;

while (i<20){
	if (input[i] == 10 || input[i] == 32){
		//done with parsing
		return count;
		}else{
		count++;
		i++;
		};
	};
	//error handling for another day
}

int compare (def_Instruction* instruction, char* input, int strlength, int hopper){
int i = 0;
while (i<35){
	int result = memcmp(instruction[i].instruction, &input[hopper], strlength);

	if (result == 0){
		printf("found match");
		return i;
		};
	i++;
	};
	error_log("tried to compare: '%.*s' with '%s'\n", strlength, &input[hopper], instruction[i].instruction);
return -1;
}


void appendExtension(char* outputFile, char* outFile){
if (outFile == NULL || outputFile == NULL){
	error_log("[ERROR] NULL Pointer passed to appendExtension");
	return;
	};
int i = 0, j = 0;
while (outFile[i] != '\0') {
	outputFile[i] = outFile[i];
	i++;
	};
	printf("outfFile copied to outputFile");
char extension[] = ".bn";
while (extension[j] != '\0'){
	outputFile[i] = extension[j];
	i++;
	j++;
};
outputFile[i] = '\0';
}

char* readNextLine(FILE* file) {
static char line[MAX_LINE_LENGTH];

if (fgets(line, sizeof(line), file) != NULL) {
	//succesfull line read
	return line;
	}else{
	if (feof(file)) {
		printf("File reading finnished");
		return NULL; 
		}else{
			error_log("[ERROR] Failed reading the File");
			return NULL;
			};
	};
};
