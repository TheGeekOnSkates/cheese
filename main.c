#include "main.h"

int main() {
	char buffer[80];
	uint16_t i = 0,
		programCounter = 0,
		stackPointer = 0;
	int16_t stack[65536],
		program[65536];
	
	memset(stack, 0, 65536 * sizeof(int16_t));
	memset(program, 0, 65536 * sizeof(int16_t));
	
	while(true) {
		memset(buffer, 0, 80);
		fgets(buffer, 80, stdin);
		
		if (STRING_STARTS_WITH(buffer, "PUSH")) {
			program[programCounter] = PUSH;
			programCounter++;
			program[programCounter] = atoi(buffer + 4);
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
		if (STRING_STARTS_WITH(buffer, "JUMP")) {
			program[programCounter] = JUMP;
			programCounter++;
			program[programCounter] = atoi(buffer + 4);
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "ADD")) {
			program[programCounter] = ADD;
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
		if (STRING_STARTS_WITH(buffer, "IF_EQUAL")) {
			program[programCounter] = IF_EQUAL;
			programCounter++;
			program[programCounter] = atoi(buffer + 8);
			programCounter++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "LIST")) {
			for (i=0; i<programCounter; i++) {
				switch(program[i]) {
					case PUSH:
						i++;
						printf(" PUSH %d\n", program[i]);
						break;
					case POP:
						printf(" POP\n");
						break;
					case DUP:
						printf(" DUP\n");
						break;
					case ADD:
						i++;
						printf(" ADD %d\n", program[i]);
						break;
					case JUMP:
						i++;
						printf(" JUMP %d\n", program[i]);
						break;
					case PRINT:
						i++;
						printf(" PRINT %d\n", program[i]);
						break;
					case IF_EQUAL:
						i++;
						printf(" IF_EQUAL %d\n", program[i]);
						break;
				}
			}
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "RUN")) {
			
			
			
			
			
			
			continue;
		}
	}
	return 0;
}
