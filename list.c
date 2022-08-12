#include "main.h"

void list(int16_t* program, uint16_t max, FILE* file, bool showAddresses) {
	uint16_t i;
	for (i=0; i<max; i++) {
		if (showAddresses)
			fprintf(file, " %d.", i);
		switch(program[i]) {
			case ADD:
				i++;
				fprintf(file, " ADD #");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case ADD_RAM:
				i++;
				fprintf(file, " ADD");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case AFS:
				fprintf(file, " AFS");
				break;
			case ASC:
				fprintf(file, " ASC\n");
				break;
			case BEQ:
				i++;
				fprintf(file, " BEQ");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case BNE:
				i++;
				fprintf(file, " BNE");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case DFS:
				fprintf(file, " DFS");
				break;
			case DIV:
				i++;
				fprintf(file, " DIV #");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case DIV_RAM:
				i++;
				fprintf(file, " DIV");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case DONE:
				fprintf(file, " DONE\n");
				break;
			case DUP:
				fprintf(file, " DUP\n");
				break;
			case JEQ:
				i++;
				fprintf(file, " JEQ");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case JNE:
				i++;
				fprintf(file, " JNE");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case JUMP:
				i++;
				fprintf(file, " JUMP");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case MFS:
				fprintf(file, " MFS");
				break;
			case MOD:
				i++;
				fprintf(file, " MOD #\n");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case MOD_RAM:
				i++;
				fprintf(file, " MOD\n");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case MUL:
				i++;
				fprintf(file, " MUL #");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case MUL_RAM:
				i++;
				fprintf(file, " MUL");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case PEEK:
				fprintf(file, " PEEK");
				i++;
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case POKE:
				fprintf(file, " POKE");
				i++;
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case POP:
				fprintf(file, " POP\n");
				break;
			case PRINT:
				fprintf(file, " PRINT\n");
				break;
			case PUSH:
				fprintf(file, " PUSH");
				i++;
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case RFS:
				fprintf(file, " RFS");
				break;
			case SFS:
				fprintf(file, " SFS");
				break;
			case SUB:
				i++;
				fprintf(file, " SUB #");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case SUB_RAM:
				i++;
				fprintf(file, " SUB");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
			case STACK:
				fprintf(file, " STACK\n");
				break;
			case SYS:
				i++;
				fprintf(file, " SYS");
				if (showAddresses)
					fprintf(file, "\n %d.", i);
				fprintf(file, " %d\n", program[i]);
				break;
		}
	}
}
