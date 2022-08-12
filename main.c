#include "main.h"

int main(int argc, const char** argv) {
	/* Declare variables */
	char buffer[80];
	uint16_t programCounter = 0;
	int16_t program[65536];
	
	/* Handle command-line options */
	if (argc > 1) {
		if (strcmp(argv[1], "pack") == 0) {
			if (argc == 4)
				assemble_file(argv[2], argv[3]);
			else if (argc == 3)
				assemble_file(argv[2], "STDOUT");
			else please();
		}
		else if (strcmp(argv[1], "unpack") == 0) {
			if (argc == 4)
				disassemble_file(argv[2], argv[3]);
			else if (argc == 3)
				disassemble_file(argv[2], "STDOUT");
			else please();
		}
		else if (strcmp(argv[1], "shred") == 0) {
			if (argc == 3)
				shred_file(argv[2]);
			else please();
		}
		else if (strcmp(argv[1], "please") == 0) {
			please();
		}
		else if (argc == 2)
			run_file(argv[1]);
		else please();
		return 0;
	}
	
	/* Clear the program memory */
	memset(program, 0, 65536 * sizeof(int16_t));
	
	/* Main event loop */
	printf("\nCHEESE 1.0\n");
	while(true) {
		
		/* Get the user's input (I love that prompt, lol) */
		printf("🧀");
		memset(buffer, 0, 80);
		fgets(buffer, 80, stdin);
		
		/* And do the actual interpreting. */
		if (STRING_STARTS_WITH(buffer, "LIST"))
			list(program, programCounter, false);
		else if (STRING_STARTS_WITH(buffer, "SHRED"))
			list(program, programCounter, true);
		else if (STRING_STARTS_WITH(buffer, "RUN"))
			run(program);
		else if (STRING_STARTS_WITH(buffer, "NEW")) {
			memset(program, 0, 65536 * sizeof(int16_t));
			programCounter = 0;
		}
		else if (STRING_STARTS_WITH(buffer, "EXIT"))
			break;
		else
			assemble_line(buffer, program, &programCounter);
	}
	return 0;
}
