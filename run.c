#include "main.h"

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
			if (stackPointer == 0) {
				printf("STACK OVERFLOW\n");
				return;
			}
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
			/* printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]); */
			stackPointer++;
		}
		else if (program[programCounter] == ADD) {
			programCounter++;
			stack[stackPointer - 1] += program[programCounter];
			/* printf("sum = %d\n", stack[stackPointer]); */
		}
		else if (program[programCounter] == SUB) {
			programCounter++;
			stack[stackPointer - 1] -= program[programCounter];
			/* printf("sum = %d\n", stack[stackPointer]); */
		}
		else if (program[programCounter] == MUL) {
			programCounter++;
			stack[stackPointer - 1] *= program[programCounter];
			/* printf("sum = %d\n", stack[stackPointer]); */
		}
		else if (program[programCounter] == DIV) {
			if (stack[stackPointer - 1] == 0) {
				printf("CAN'T DIVIDE BY ZERO.\n");
				return;
			}
			programCounter++;
			stack[stackPointer - 1] /= program[programCounter];
			/* printf("sum = %d\n", stack[stackPointer]); */
		}
		else if (program[programCounter] == JEQ) {
			if (stackPointer == 0) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			programCounter++;
			/* printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]); */
			if (stack[stackPointer - 1] == 0) {
				programCounter = program[programCounter] - 1;
				/* printf("Jumping to %d\n", programCounter + 1); */
			}
		}
		else if (program[programCounter] == JNE) {
			if (stackPointer == 0) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			programCounter++;
			/* printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]); */
			if (stack[stackPointer - 1] != 0) {
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
			printf("%d\n", stack[stackPointer - 1]);
		}
		programCounter++;
	}
}
