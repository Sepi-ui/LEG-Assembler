#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "instructions.h"
#include "../utils/error.h"
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
