#include "main.h"

void assemble_line(char* line, int16_t* program, uint16_t *programCounter) {
	uint16_t pc = *programCounter, temp = 0;
	char* comment = NULL;
	
	/* Strip out comments */
	comment = strstr(line, "//");
	if (comment != NULL) {
		comment[0] = '\0';
		comment = NULL;
	}
	
	
	if (STRING_STARTS_WITH(line, "ADD #")) {
		if (!atoi_would_work(line + 5)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = ADD;
		pc++;
		program[pc] = atoi(line + 5);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "ADD")) {
		if (!atoi_would_work(line + 3)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = ADD_RAM;
		pc++;
		temp = atoi(line + 3);
		if (temp < 0 || temp > 65536) {
			printf("ADDRESS OUT OF RANGE\n");
			return;
		}
		program[pc] = temp;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "AFS")) {
		program[pc] = AFS;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "ASC")) {
		program[pc] = ASC;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "BEQ")) {
		if (!atoi_would_work(line + 3)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = BEQ;
		pc++;
		program[pc] = atoi(line + 3);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "BNE")) {
		if (!atoi_would_work(line + 3)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = BNE;
		pc++;
		program[pc] = atoi(line + 3);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "DFS")) {
		program[pc] = DFS;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "DIV #")) {
		if (!atoi_would_work(line + 5)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = DIV;
		pc++;
		program[pc] = atoi(line + 5);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "DIV")) {
		if (!atoi_would_work(line + 3)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = DIV_RAM;
		pc++;
		temp = atoi(line + 3);
		if (temp < 0 || temp > 65536) {
			printf("ADDRESS OUT OF RANGE\n");
			return;
		}
		program[pc] = temp;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "DONE")) {
		program[pc] = DONE;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "DUP")) {
		program[pc] = DUP;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "JEQ")) {
		if (!atoi_would_work(line + 3)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = JEQ;
		pc++;
		program[pc] = atoi(line + 3);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "JNE")) {
		if (!atoi_would_work(line + 3)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = JNE;
		pc++;
		program[pc] = atoi(line + 3);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "JUMP")) {
		if (!atoi_would_work(line + 4)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = JUMP;
		pc++;
		program[pc] = atoi(line + 4);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "MFS")) {
		program[pc] = MFS;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "MOD #")) {
		if (!atoi_would_work(line + 5)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = MOD;
		pc++;
		program[pc] = atoi(line + 5);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "MOD")) {
		if (!atoi_would_work(line + 3)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = MOD_RAM;
		pc++;
		temp = atoi(line + 3);
		if (temp < 0 || temp > 65536) {
			printf("ADDRESS OUT OF RANGE\n");
			return;
		}
		program[pc] = temp;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "MUL #")) {
		if (!atoi_would_work(line + 5)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = MUL;
		pc++;
		program[pc] = atoi(line + 5);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "MUL")) {
		if (!atoi_would_work(line + 3)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = MUL_RAM;
		pc++;
		temp = atoi(line + 3);
		if (temp < 0 || temp > 65536) {
			printf("ADDRESS OUT OF RANGE\n");
			return;
		}
		program[pc] = temp;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "PEEK")) {
		if (!atoi_would_work(line + 4)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = PEEK;
		pc++;
		if (pc == 0) {
			printf("PROGRAM MAX REACHED\n");
			return;
		}
		program[pc] = atoi(line + 4);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "POKE")) {
		if (!atoi_would_work(line + 4)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = POKE;
		pc++;
		if (pc == 0) {
			printf("PROGRAM MAX REACHED\n");
			return;
		}
		program[pc] = atoi(line + 4);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "POP")) {
		program[pc] = POP;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "PRINT")) {
		program[pc] = PRINT;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "PUSH")) {
		if (!atoi_would_work(line + 4)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = PUSH;
		pc++;
		if (pc == 0) {
			printf("PROGRAM MAX REACHED\n");
			return;
		}
		program[pc] = atoi(line + 5);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "RFS")) {
		program[pc] = RFS;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "SFS")) {
		program[pc] = SFS;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "STACK")) {
		program[pc] = STACK;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "SUB #")) {
		if (!atoi_would_work(line + 5)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = SUB;
		pc++;
		program[pc] = atoi(line + 5);
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "SUB")) {
		if (!atoi_would_work(line + 3)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = SUB_RAM;
		pc++;
		temp = atoi(line + 3);
		if (temp < 0 || temp > 65536) {
			printf("ADDRESS OUT OF RANGE\n");
			return;
		}
		program[pc] = temp;
		pc++;
		*programCounter = pc;
		return;
	}
	if (STRING_STARTS_WITH(line, "SYS")) {
		if (!atoi_would_work(line + 3)) {
			printf("NUMBER REQUIRED\n");
			return;
		}
		program[pc] = SYS;
		pc++;
		program[pc] = atoi(line + 3);
		pc++;
		*programCounter = pc;
		return;
	}
}
