#include "main.h"

void run(int16_t* program) {
	int16_t stack[65536];
	uint16_t programCounter = 0,
		stackPointer = 0,
		i = 0;
	char tempString[65536];
	int temp = 0;
	
	memset(stack, 0, 65536 * sizeof(int16_t));
	while(true) {
		if (program[programCounter] == ADD) {
			programCounter++;
			stack[stackPointer - 1] += program[programCounter];
		}
		else if (program[programCounter] == ADD_RAM) {
			programCounter++;
			stack[stackPointer - 1] += program[program[programCounter]];
		}
		else if (program[programCounter] == AFS) {
			if (stackPointer < 2) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			stackPointer--;
			temp = stack[stackPointer];
			stack[stackPointer] = 0;
			stack[stackPointer - 1] += temp;
		}
		else if (program[programCounter] == ASC) {
			printf("%lc", stack[stackPointer - 1]);
		}
		else if (program[programCounter] == BEQ) {
			if (stackPointer == 0) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			programCounter++;
			/* printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]); */
			if (stack[stackPointer - 1] == 0) {
				programCounter += program[programCounter] - 1;
				/* printf("Branching to %d\n", programCounter + 1); */
			}
		}
		else if (program[programCounter] == BNE) {
			if (stackPointer == 0) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			programCounter++;
			/* printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]); */
			if (stack[stackPointer - 1] != 0) {
				programCounter += program[programCounter] - 1;
				/* printf("Branching to %d\n", programCounter + 1); */
			}
		}
		else if (program[programCounter] == DFS) {
			if (stackPointer < 2) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			stackPointer--;
			temp = stack[stackPointer];
			stack[stackPointer] = 0;
			stack[stackPointer - 1] /= temp;
		}
		else if (program[programCounter] == DIV) {
			if (stackPointer == 0) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			programCounter++;
			if (program[programCounter] == 0) {
				printf("CAN'T DIVIDE BY ZERO.\n");
				return;
			}
			stack[stackPointer - 1] /= program[programCounter];
		}
		else if (program[programCounter] == DIV_RAM) {
			if (stack[stackPointer - 1] == 0) {
				printf("CAN'T DIVIDE BY ZERO.\n");
				return;
			}
			programCounter++;
			stack[stackPointer - 1] /= program[program[programCounter]];
		}
		else if (program[programCounter] == DONE) {
			/* printf("Done.\n"); */
			return;
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
		else if (program[programCounter] == MOD) {
			programCounter++;
			stack[stackPointer - 1] %= program[programCounter];
			/* printf("sum = %d\n", stack[stackPointer]); */
		}
		else if (program[programCounter] == MOD_RAM) {
			programCounter++;
			stack[stackPointer - 1] %= program[program[programCounter]];
			/* printf("sum = %d\n", stack[stackPointer]); */
		}
		else if (program[programCounter] == MFS) {
			if (stackPointer < 2) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			stackPointer--;
			temp = stack[stackPointer];
			stack[stackPointer] = 0;
			stack[stackPointer - 1] *= temp;
		}
		else if (program[programCounter] == MUL) {
			programCounter++;
			stack[stackPointer - 1] *= program[programCounter];
		}
		else if (program[programCounter] == MUL_RAM) {
			programCounter++;
			stack[stackPointer - 1] *= program[program[programCounter]];
		}
		else if (program[programCounter] == POP) {
			stackPointer--;	/* Because stackPointer actually points at the position AFTER the top of the stack */
			stack[stackPointer] = 0;
			/* printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]); */
		}
		else if (program[programCounter] == PRINT) {
			printf("%d\n", stack[stackPointer - 1]);
		}
		else if (program[programCounter] == PEEK) {
			programCounter++;
			stack[stackPointer] = program[program[programCounter]];
			/* printf("stack[%d] = %d\n", stackPointer, stack[stackPointer]); */
			stackPointer++;
			if (stackPointer == 0) {
				printf("STACK OVERFLOW\n");
				return;
			}
		}
		else if (program[programCounter] == POKE) {
			programCounter++;
			program[program[programCounter]] = stack[stackPointer - 1];
			stackPointer--;	/* Because stackPointer actually points at the position AFTER the top of the stack */
			stack[stackPointer] = 0;
		}
		else if (program[programCounter] == PUSH) {
			programCounter++;
			stack[stackPointer] = program[programCounter];
			stackPointer++;
			if (stackPointer == 0) {
				printf("STACK OVERFLOW\n");
				return;
			}
		}
		else if (program[programCounter] == RFS) {
			if (stackPointer < 2) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			stackPointer--;
			temp = stack[stackPointer];
			stack[stackPointer] = 0;
			stack[stackPointer - 1] %= temp;
		}
		else if (program[programCounter] == SFS) {
			if (stackPointer < 2) {
				printf("STACK UNDERFLOW\n");
				return;
			}
			stackPointer--;
			temp = stack[stackPointer];
			stack[stackPointer] = 0;
			stack[stackPointer - 1] -= temp;
		}
		else if (program[programCounter] == STACK) {
			printf("Stack size: %d\n", stackPointer);
			for (i=0; i<stackPointer; i++)
				printf("%d ", stack[i]);
			printf("\n");
		}
		else if (program[programCounter] == SUB) {
			programCounter++;
			stack[stackPointer - 1] -= program[programCounter];
			/* printf("sum = %d\n", stack[stackPointer]); */
		}
		else if (program[programCounter] == SUB_RAM) {
			programCounter++;
			stack[stackPointer - 1] -= program[program[programCounter]];
			/* printf("sum = %d\n", stack[stackPointer]); */
		}
		else if (program[programCounter] == SYS) {
			/* Save the program counter */
			programCounter++;
			temp = programCounter;
			
			/* Move to the address pointed to by program[programCounter] */
			programCounter = program[programCounter];
			
			/* Build tempString till it hits a zero (NULL terminator) or the last address */
			memset(tempString, 0, 65536);
			i = 0;
			while(program[programCounter] != 0 && programCounter < 65536) {
				tempString[i] = (char)program[programCounter];
				i++;
				programCounter++;
				if (program[programCounter] == 0) {
					programCounter++;
					break;
				}
			}
			
			/* Restore the program counter to where it was */
			programCounter = temp;
			
			/* Run the program and PUSh the result */
			programCounter++;
			stack[stackPointer] = (int16_t)system(tempString);
			stackPointer++;
			if (stackPointer == 0) {
				printf("STACK OVERFLOW\n");
				return;
			}
		}
		else {
			printf("UNKNOWN INSTRUCTION: %d\n", program[programCounter]);
			return;
		}
		programCounter++;
	}
}
