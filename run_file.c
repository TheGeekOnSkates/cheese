#include "main.h"

void run_file(const char* file) {
	/* Declare variables */
	FILE* f = NULL;
	int16_t program[65536];
	
	/* Open the input file */
	f = fopen(file, "r");
	if (f == NULL) {
		perror("Error opening input file");
		return;
	}
	
	/* Read and run the file */
	fread(program, 65536, 1, f);
	if (ferror(f)) {
		perror("Error reading file");
		return;
	}
	fclose(f);
	run(program);
}
