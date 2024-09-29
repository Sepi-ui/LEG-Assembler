#include <stdio.h>
#include <string.h>
#include "flags.h"
#include "error.h"
void initializeFlags(def_flags* flags) {
	flags->outFile = NULL;
	flags->flagB = 0;
	flags->fileCount = 0;
	for (int i = 0; i < MAX_FILES; i++) {
		flags->inFile[i] = NULL;
		};
	}


void parseFlags(int argc, char* argv[], def_flags* flags) {
	for (int i = 1; i< argc; i++) {
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {

			//get outputfile Argument
			case 'o':
				if (i + 1 < argc){
					if (argv[i + 1] == NULL) {
						error_log("[ERROR] Output File name could not be recognized");
						return;
						};
					flags->outFile = argv[++i];
					}else{
						error_log("[ERROR] No Argument provided after -o Flag");
						return;
						};
				break;

			case 'b':
				flags->flagB = 1;
				break;

			default:
				error_log("Flag was not recoginzed:%s\n", argv[i]);
				break;
				};
			}else{
			
			if (flags->fileCount < MAX_FILES) {
				flags->inFile[flags->fileCount++] = argv[i];
				
				}else {
				error_log("Too many Input Files MAX:%d\n", MAX_FILES);
				return;
				};
			};
		}
	} 

void printFlags(const def_flags* flags){
if (flags->outFile) printf("Flag o is set:%s\n",flags->outFile);
if (flags->flagB) printf("Flag b is set\n");
for (int i = 0; i < flags->fileCount; i++) {
	printf("Files:%s\n", flags->inFile[i]);
	}; 
}
