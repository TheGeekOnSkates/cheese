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
	ADD,		/* pop off the top 2 items on the stack and push their sum on to the stack */
	IF_EQUAL,	/* look at the top of the stack, if it's 0, continue, else, jump to <address> where <address> is a line number */
	JUMP,		/* jump to a line number */
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


#endif
