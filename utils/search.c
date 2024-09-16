int strindex(char* input, int hopper) {

int base = 0;
//check immediate designator
if (buffer[base] == '#') {
	base++;
	};
int count = 0;
int i = base;

while (i<20){
	if (buffer[i] == 10 || buffer[i] == 32){
		//done with parsing
		return count;
		}else{
		count++;
		i++;
		};
	};
}

int compare (void* instruction, char* input, int strlength){
int i = 0;
while (i<35){
	int result = memcmp(p[i].instruction, &input[hopper + base], strlength)
	if (result == 0){
		return i;
		};
	};
}
