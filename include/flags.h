#ifndef FlAGS_H
#define FLAGS_H

#define MAX_FILES 10
typedef struct {
	char* outFile;
	int flagB;
	char* inFile[MAX_FILES];
	int fileCount;
}def_flags;

void initializeFlags(def_flags* flags);
void parseFlags(int argc, char* argv[], def_flags* flags);
void printFlags(const def_flags* flags);

#endif
