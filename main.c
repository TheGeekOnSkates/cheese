#include "main.h"

int main() {
	/* Declare variables */
	char buffer[80];
	uint16_t programCounter = 0;
	int16_t program[65536];
	
	/* Clear the program memory */
	memset(program, 0, 65536 * sizeof(int16_t));
	
	/* Main event loop */
	while(true) {
		
		/* Get the user's input (I love that prompt, lol) */
		printf("🧀");
		memset(buffer, 0, 80);
		fgets(buffer, 80, stdin);
		
		/* And do the actual interpreting. */
		if (STRING_STARTS_WITH(buffer, "LIST"))
			list(program, programCounter, false);
		else if (STRING_STARTS_WITH(buffer, "DUMP"))
			list(program, programCounter, true);
		else if (STRING_STARTS_WITH(buffer, "RUN"))
			run(program);
		else if (STRING_STARTS_WITH(buffer, "NEW")) {
			memset(program, 0, 65536 * sizeof(int16_t));
			programCounter = 0;
		}
		else if (STRING_STARTS_WITH(buffer, "SYS "))
			system(buffer + 4);
		else if (STRING_STARTS_WITH(buffer, "EXIT"))
			break;
		else
			assemble_line(buffer, program, &programCounter);
	}
	return 0;
}
