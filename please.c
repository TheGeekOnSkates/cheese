#include "main.h"

void please() {
	printf("COMMAND-LINE OPTIONS:\n");
	printf("    cheese programfile\n");
	printf("    cheese pack inputfile [outputfile]\n");
	printf("    cheese unpack inputfile\n");
	printf("    cheese shred inputfile\n");
	printf("    cheese please\n\n");
	printf("MORE INFO\n");
	printf("    The \"pack\" command compiles/assembled a Cheese file.\n");
	printf("        Once compiled, you can just run cheese <your file>\n");
	printf("    The \"unpack\" command tries to reverse \"pack\".\n");
	printf("    The \"shred\" command is similar to unpacking, except\n");
	printf("        that it shows you the memory address of each block.\n");
	printf("    The \"please\" command shows this cheesy manual. :)\n\n");
	printf("COMMAND-LINE OPTIONS BY NAME\n");
	printf("    programfile = file to run (pack first)\n");
	printf("    inputfile = the filed to be packed/unpacked/shredded\n");
	printf("    outputfile = where to save the packed/unpacked/shredded data\n\n");
	printf("FOR MORE INFO:\n    TO-DO: Set up (and link to) a GitHub wiki :)\n");
}
