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
		
		/* And do the actual interpreting.
		Eventually, I'd like to put all this in a function too. */
		if (STRING_STARTS_WITH(buffer, "PUSH")) {
			if (!atoi_would_work(buffer + 4)) {
				printf("NUMBER REQUIRED\n");
				continue;
			}
			program[programCounter] = PUSH;
			programCounter++;
			if (programCounter == 0) {
				printf("PROGRAM MAX REACHED\n");
				continue;
			}
			program[programCounter] = atoi(buffer + 5);
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "POP")) {
			program[programCounter] = POP;
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "DUP")) {
			program[programCounter] = DUP;
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "DONE")) {
			program[programCounter] = DONE;
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "JUMP")) {
			if (!atoi_would_work(buffer + 4)) {
				printf("NUMBER REQUIRED\n");
				continue;
			}
			program[programCounter] = JUMP;
			programCounter++;
			program[programCounter] = atoi(buffer + 4);
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "ADD")) {
			if (!atoi_would_work(buffer + 3)) {
				printf("NUMBER REQUIRED\n");
				continue;
			}
			program[programCounter] = ADD;
			programCounter++;
			program[programCounter] = atoi(buffer + 3);
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "SUB")) {
			if (!atoi_would_work(buffer + 3)) {
				printf("NUMBER REQUIRED\n");
				continue;
			}
			program[programCounter] = SUB;
			programCounter++;
			program[programCounter] = atoi(buffer + 3);
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "MUL")) {
			if (!atoi_would_work(buffer + 3)) {
				printf("NUMBER REQUIRED\n");
				continue;
			}
			program[programCounter] = MUL;
			programCounter++;
			program[programCounter] = atoi(buffer + 3);
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "DIV")) {
			if (!atoi_would_work(buffer + 3)) {
				printf("NUMBER REQUIRED\n");
				continue;
			}
			program[programCounter] = DIV;
			programCounter++;
			program[programCounter] = atoi(buffer + 3);
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "PRINT")) {
			program[programCounter] = PRINT;
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "JEQ")) {
			if (!atoi_would_work(buffer + 3)) {
				printf("NUMBER REQUIRED\n");
				continue;
			}
			program[programCounter] = JEQ;
			programCounter++;
			program[programCounter] = atoi(buffer + 3);
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "JNE")) {
			if (!atoi_would_work(buffer + 3)) {
				printf("NUMBER REQUIRED\n");
				continue;
			}
			program[programCounter] = JNE;
			programCounter++;
			program[programCounter] = atoi(buffer + 3);
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "LIST")) {
			list(program, programCounter, false);
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "DUMP")) {
			list(program, programCounter, true);
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "RUN")) {
			run(program);
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "NEW")) {
			memset(program, 0, 65536 * sizeof(int16_t));
			programCounter = 0;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "SYS ")) {
			system(buffer + 4);
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "EXIT")) {
			break;
		}
	}
	return 0;
}
