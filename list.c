#include "main.h"

void list(int16_t* program, uint16_t max, bool showAddresses) {
	uint16_t i;
	for (i=0; i<max; i++) {
		if (showAddresses)
			printf(" %d.", i);
		switch(program[i]) {
			case ADD:
				i++;
				printf(" ADD");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case ASC:
				printf(" ASC\n");
				break;
			case BEQ:
				i++;
				printf(" BEQ");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case BNE:
				i++;
				printf(" BNE");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case DIV:
				i++;
				printf(" DIV");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case DONE:
				printf(" DONE\n");
				break;
			case DUP:
				printf(" DUP\n");
				break;
			case JEQ:
				i++;
				printf(" JEQ");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case JNE:
				i++;
				printf(" JNE");
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
			case MOD:
				i++;
				printf(" MOD\n");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
				break;
			case MUL:
				i++;
				printf(" MUL");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case PEEK:
				printf(" PEEK");
				i++;
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case POKE:
				printf(" POKE");
				i++;
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case POP:
				printf(" POP\n");
				break;
			case PRINT:
				printf(" PRINT\n");
				break;
			case PUSH:
				printf(" PUSH");
				i++;
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case SUB:
				i++;
				printf(" SUB");
				if (showAddresses)
					printf("\n %d.", i);
				printf(" %d\n", program[i]);
				break;
			case STACK:
				printf(" STACK\n");
				break;
		}
	}
}
