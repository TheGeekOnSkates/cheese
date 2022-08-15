#include "main.h"

void disassemble_file(const char* input, const char* output, bool showAddresses) {
	/* Declare variables */
	FILE* in = NULL, * out = NULL;
	int16_t program[65536];
	bool isSTDOUT = strcmp(output, "STDOUT") == 0;
	
	/* Open the input file */
	in = fopen(input, "r");
	if (in == NULL) {
		perror("Error opening input file");
		return;
	}
	
	/* Read the file into memory */
	fread(program, 65535, 1, in);
	if (ferror(in)) {
		perror("Error reading file");
		return;
	}
	fclose(in);
	
	if (isSTDOUT)
		out = stdout;
	else {
		out = fopen(output, "w");
		if (out == NULL) {
			perror("Error opening output file");
			return;
		}
	}
	
	/* And run LIST on it */
	list(program, 65535, out, showAddresses);
	fclose(out);
}

