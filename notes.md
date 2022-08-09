# TO-DO'S

## On the "runner" side:

* Finish ADD - I'm too tired to math. :P
* Add all the other instructions
* Reset the program counter and stack pointer when running is done - currently, NEW is automatic. :D

## On the "compiler" side:

* Add some validation - I can just do "PRINT" by itself and it "compiles".
* Add the DONE instruction to the LIST command's output

## When both compiler and runner are finished:

* Add a NEW instruction to clear the program counters/pointers/memory
* Add a command-line option, a file (maybe use the extension ".kso", lol).  That wasy I can just do i.e. "cheese my-test.kso" as I keep tinkering.
* Oh, and add some docs, just cuz :)

## Pipe dreaming beyond 1.0

* It would be nice to have an array that points to screen coordinates.  Like let's say I do:
	PUSH 67		// Meaning the letter C
	SCREEN 0 0	// Put a C at 0, 0 on the screen
* Oh yeah, and comments would be nice too
* Also, having a separate compiler ("assembler" really) and machine.  Like 6502

Of course then we're bordering on something useful, so probably not gonna happen, but still cool to think about if it did... how about:

* A way to send data to / read data from files
* Maybe another set of instructions for sound?

Might make for some cheesy games. :D
