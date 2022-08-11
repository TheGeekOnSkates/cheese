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
	PUSH,		/* Put a new number on top of the stack */
	POP,		/* Remove the number at the top of the stack */
	DUP,		/* Push a copy ("DUPlicate") of what's at the top of the stack back on top */
	ADD,		/* Add a number to the top number on the stack, and put the result on the stack */
	SUB,		/* Subtract a number from the top number on the stack, and put the result on the stack */
	MUL,		/* Multiply a number by the top number on the stack, and put the result on the stack */
	DIV,		/* Divide a number by the top number on the stack, and put the result on the stack */
	MOD,		/* Same as DIV except it puts the remainder ("Modulus" to my Ancient Roman friends) on the top of the stack */
	JUMP,		/* Jump to a memory address */
	JEQ,		/* Jump to <address> if the number at the top of the stack == 0 */
	JNE,		/* Jump to <address> if the number at the top of the stack != 0 */
	PRINT,		/* Print the number at the top of the stack */
	ASC		/* Print the ASCII character (well, probably Unicode) represented by the number at the top of the stack */
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

/**
 * Assembles a single line of code
 * @param[in] The code to be assembled
 * @param[in] The program memory
 * @param[in, out] Where to put the compiled code
 */
void assemble_line(char* line, int16_t* program, uint16_t *programCounter);



#endif
