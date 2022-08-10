#include "main.h"

void list(int16_t* program, uint16_t max, bool showAddresses) {
	uint16_t i;
	for (i=0; i<max; i++) {
		if (showAddresses)
			printf(" %d.", i);
		switch(program[i]) {
			case DONE:
				printf(" DONE\n");
				break;
			case PUSH:
				printf(" PUSH");
				i++;
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case POP:
				printf(" POP\n");
				break;
			case DUP:
				printf(" DUP\n");
				break;
			case ADD:
				i++;
				printf(" ADD");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case JUMP:
				i++;
				printf(" JUMP");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case PRINT:
				printf(" PRINT\n");
				break;
			case IF_EQUAL:
				i++;
				printf(" IF_EQUAL");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
		}
	}

}

void run(int16_t* program) {
	int16_t stack[65536];
	uint16_t programCounter = 0,
		stackPointer = 0;
	
	memset(stack, 0, 65536 * sizeof(int16_t));
	while(true) {
		/* printf("\nprogramCounter = %d, stackPointer = %d\n", programCounter, stackPointer); */
		if (program[programCounter] == DONE) {
			/* printf("Done.\n"); */
			return;
		}
		if (program[programCounter] == PUSH) {
			programCounter++;
			stack[stackPointer] = program[programCounter];
			/* printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]); */
			stackPointer++;
		}
		else if (program[programCounter] == POP) {
			stackPointer--;	/* Because stackPointer actually points at the position AFTER the top of the stack */
			stack[stackPointer] = 0;
			/* printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]); */
		}
		else if (program[programCounter] == DUP) {
			if (stackPointer == 0) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			stack[stackPointer] = stack[stackPointer - 1];
			printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]);
			stackPointer++;
		}
		else if (program[programCounter] == ADD) {
			programCounter++;
			stack[stackPointer - 1] += program[programCounter];
			/* printf("sum = %d\n", stack[stackPointer]); */
		}
		else if (program[programCounter] == IF_EQUAL) {
			if (stackPointer == 0) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			programCounter++;
			stackPointer--;
			/* printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]); */
			if (stack[stackPointer] == 0) {
				programCounter = program[programCounter] - 1;
				/* printf("Jumping to %d\n", programCounter + 1); */
			}
		}
		else if (program[programCounter] == JUMP) {
			programCounter++;
			programCounter = program[programCounter] - 1; /* Because the loop adds 1 later */
			stackPointer--;
			/* printf("Jumping to %d\n", programCounter + 1); */
		}
		else if (program[programCounter] == PRINT) {
			stackPointer--;	/* Because stackPointer actually points at the position AFTER the top of the stack */
			printf("%d\n", stack[stackPointer]);
			stack[stackPointer] = 0;
		}
		programCounter++;
	}
}

int main() {
	char buffer[80];
	uint16_t programCounter = 0;
	int16_t program[65536];
	
	memset(program, 0, 65536 * sizeof(int16_t));
	
	while(true) {
		printf("🧀");
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
		if (STRING_STARTS_WITH(buffer, "DONE")) {
			program[programCounter] = DONE;
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
		if (STRING_STARTS_WITH(buffer, "IF_EQUAL ")) {
			program[programCounter] = IF_EQUAL;
			programCounter++;
			program[programCounter] = atoi(buffer + 9);
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
