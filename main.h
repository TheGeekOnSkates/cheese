#ifndef _MAIN_H

/************************************************************************/
/**** DEPENDENCIES                                                   ****/
/************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/************************************************************************/
/**** ENUMERATIONS                                                   ****/
/************************************************************************/

enum Instructions {
	DONE,		/* End of program */
	PUSH,		/* push a number on to the stack */
	POP,		/* pop off the first number on the stack */
	ADD,		/* Add a number to the top number on the stack, and put the result on the stack */
	SUB,		/* Subtract a number from the top number on the stack, and put the result on the stack */
	MUL,		/* Multiply a number by the top number on the stack, and put the result on the stack */
	DIV,		/* Divide a number by the top number on the stack, and put the result on the stack */
	JUMP,		/* Jump to a memory address */
	JEQ,		/* Jump to <address> if the number at the top of the stack == 0 */
	JNE,		/* Jump to <address> if the number at the top of the stack != 0 */
	PRINT,		/* print the value at the top of the stack */
	DUP		/* push a copy of what's at the top of the stack back onto the stack */
};



/************************************************************************/
/**** PRE-PROCESSOR MACROS                                           ****/
/************************************************************************/

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



/************************************************************************/
/**** FUNCTIONS (each one defined in its own .c file for now)        ****/
/************************************************************************/

/**
 * Checks if the string starts with a number
 * @param[in] The string to be tested
 * @returns True if atoi() would (or at least should) work, false if not
 */
bool atoi_would_work(char* line);

/**
 * Lists the current program (similar to BASICs)
 * @param[in] A compiled Cheese program
 * @param[in] The program counter / size of the program
 * @param[in] If true, print the memory addresses (position in the array)
 * for debugging.  If false, what you get is more like disassembly, where you
 * get code that could be copied/pasted and run again.
 */
void list(int16_t* program, uint16_t max, bool showAddresses);

/**
 * Runs the current program
 * @param[in] The compiled program
 */
void run(int16_t* program);

#endif
