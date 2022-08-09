#include "main.h"

void run(int16_t* program) {
	int16_t stack[65536];
	uint16_t programCounter = 0,
		stackPointer = 0;
	
	memset(stack, 0, 65536 * sizeof(int16_t));
	while(true) {
		printf("\n\nprogramCounter = %d, stackPointer = %d\n", programCounter, stackPointer);
		if (program[programCounter] == DONE) {
			printf("Done.\n");
			return;
		}
		if (program[programCounter] == PUSH) {
			programCounter++;
			stack[stackPointer] = program[programCounter];
			printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]);
			stackPointer++;
		}
		else if (program[programCounter] == POP) {
			stackPointer--;	/* Because stackPointer actually points at the position AFTER the top of the stack */
			stack[stackPointer] = 0;
			/* What to do with program[programCounter]; ? */
		}
		else if (program[programCounter] == DUP) {
			printf("DUP (TO-DO)");
		}
		else if (program[programCounter] == ADD) {
			printf("ADD (TO-DO)");
		}
		else if (program[programCounter] == IF_EQUAL) {
			printf("IF_EQUAL (TO-DO)");
		}
		else if (program[programCounter] == JUMP) {
			printf("JUMP (TO-DO)");
		}
		else if (program[programCounter] == PRINT) {
			stackPointer--;	/* Because stackPointer actually points at the position AFTER the top of the stack */
			printf("%d\n", stack[stackPointer]);
			stack[stackPointer] = 0;
			stackPointer--;
		}
		programCounter++;
	}
}

int main() {
	char buffer[80];
	uint16_t i = 0, programCounter = 0;
	int16_t program[65536];
	
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
			run(program);
			continue;
		}
	}
	return 0;
}
