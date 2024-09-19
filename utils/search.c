#include <string.h>

int strindex(char* input, int hopper) {
int base = 0;
//check immediate designator
if (hopper[base] == '#') {
	base++;
	};
int count = 0;
int i = base;

while (i<20){
	if (hopper[i] == 10 || hopper[i] == 32){
		//done with parsing
		return count;
		}else{
		count++;
		i++;
		};
	};
}

int compare (char* instruction, char* input, int strlength, int hopper, int base){
int i = 0;
while (i<35){
	int result = memcmp(instruction[i].instruction, &input[hopper + base], strlength);
	if (result == 0){
		return i;
		};
	};
return -1;
}
