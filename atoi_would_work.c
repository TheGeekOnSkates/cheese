#include "main.h"

bool atoi_would_work(char* line) {
	/* Skip past spaces, if there are any */
	while (line[0] == ' ') line++;
	
	/* Skip past a negative or positive sign, if there is one */
	if (line[0] == '-' || line[0] == '+') line++;
	
	return line[0] >= '0' && line[0] <= '9';
}
