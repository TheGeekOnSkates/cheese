#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

enum Instructions {
	PUSH,		/* push a number on to the stack */
	POP,		/* pop off the first number on the stack */
	ADD,		/* pop off the top 2 items on the stack and push their sum on to the stack */
	IF_EQUAL,	/* look at the top of the stack, if it's 0, continue, else, jump to <address> where <address> is a line number */
	JUMP,		/* jump to a line number */
	PRINT,		/* print the value at the top of the stack */
	DUP		/* push a copy of what's at the top of the stack back onto the stack */
};


/**
 * Checks if two strings contain the same text
 * @param[in] The first string
 * @param[in] The second string
 * @returns True if they do, false if they don't
 */
#define STRING_EQUALS(a, b) (strcmp(a, b) == 0)

/**
 * Checks if the first string starts with the second string
 * @param[in] The first string
 * @param[in] The second string
 * @returns True if it does, false if it doesn't
 */
#define STRING_STARTS_WITH(a, b) (strstr(a, b) == a)

/**
 * Checks if the first string contains the second string
 * @param[in] The first string
 * @param[in] The second string
 * @returns True if it does, false if it doesn't
 */
#define STRING_CONTAINS(a, b) (strstr(a, b) != NULL)


int main() {
	char buffer[80];
	uint16_t i, programCounter, stackPointer;
	int16_t stack[65536];
	while(true) {
		memset(buffer, 0, 80);
		fgets(buffer, 80, stdin);
		
		if (STRING_STARTS_WITH(buffer, "PUSH")) {
			stack[stackPointer] = PUSH;
			stackPointer++;
			stack[stackPointer] = atoi(buffer + 4);
			stackPointer++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "POP")) {
			stack[stackPointer] = POP;
			stackPointer++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "DUP")) {
			stack[stackPointer] = DUP;
			stackPointer++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "JUMP")) {
			stack[stackPointer] = JUMP;
			stackPointer++;
			stack[stackPointer] = atoi(buffer + 4);
			stackPointer++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "ADD")) {
			stack[stackPointer] = ADD;
			stackPointer++;
			stack[stackPointer] = atoi(buffer + 4);
			stackPointer++;
			continue;
		}
		if (STRING_STARTS_WITH(buffer, "LIST")) {
			for (i=0; i<stackPointer; i++) {
				switch(stack[i]) {
					case PUSH:
						i++;
						printf("PUSH %d\n", stack[i]);
						break;
					case POP:
						printf("POP\n");
						break;
					case DUP:
						printf("DUP\n");
						break;
					case ADD:
						i++;
						printf("ADD %d\n", stack[i]);
						break;
					case JUMP:
						i++;
						printf("JUMP %d\n", stack[i]);
						break;
				}
			}
			continue;
		}
		
		
		
		
	}
	return 0;
}
