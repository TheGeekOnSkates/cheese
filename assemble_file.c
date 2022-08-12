#include "main.h"

void assemble_file(const char* input, const char* output) {
	/* Declare variables */
	FILE* in = NULL, * out = NULL;
	char buffer[80];
	uint16_t programCounter = 0;
	int16_t program[65536];
	bool isSTDOUT = strcmp(output, "STDOUT") == 0;
	
	/* Open the input file */
	in = fopen(input, "r");
	if (in == NULL) {
		perror("Error opening input file");
		return;
	}
	
	/* Read and assemble the file */
	while(true) {
		memset(buffer, 0, 80);
		fgets(buffer, 80, in);
		if (ferror(in)) {
			perror("Error reading from file");
			fclose(in);
			return;
		}
		assemble_line(buffer, program, &programCounter);
		if (feof(in)) break;
	}
	
	/* If it gets here, close the input file and open the output file */
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
	
	/* Write the compiled binary */
	fwrite(program, 65536, 1, out);
	if (ferror(out))
		perror("Error writing to file");
	
	/* Then if !stdout, close the file and we're done. */
	if (!isSTDOUT) fclose(out);
}
