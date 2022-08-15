## Features for future 1.x releases

* SWAP
* ROTATE (sorry Forth, ROT is a word and using it doesn't make sense here :D)
* RANDOM (or RND - idk, 6 chars is not bad, and we already have STACK)
* A way to move the program counter (similar to "* = <number>" in 6502)
* Compile-time constants for things like max size of buffer, max stack size, etc.  That way, if I want to port Cheese to some other OS, changing those limits is, well, easy cheesy. :)
* At first I wanted CLEAR, but now I'm kind of thinking maybe ESC (like in my basic); this way it wouldn't require ncurses or knowledge of every single terminal out there lol; I'd like to keep this in standard C as much as possible).
* Have SYS work like other instructions: don't run immediately; only run when RUN is called; then, put the end result (the return value of system()) on the stack.
	Unfortunately, this turned out to be tougher than it looks.  Why?  Because I haven't come up with a way for Cheese to handle strings yet. :D
* INCLUDE "file.asm"
* Variables.  Forth has "words" which are awesome and fun and different, but I'm kind of thinking simpler: I can run LET CHEDDAR = 42 and the program will replace all occurrences of CHEDDAR with 42 when compiling.
* Labels, like other assemblers have.

Of course then we're bordering on something that's actually useful, so...

## Pipe dreaming about a version 2.0

* A way to send data to / read data from files
* Input!  How could I have forgotten that!  (Thank you, Johnny 5) :D
* And while we're at it, what about printing strings?  Right now, Cheese can only print numbers.
* While we're at it, what about floats?  Forth uses a lot of fixed-point (which really does make a lot of sense) but why make users math that hard? :D
* Maybe another set of instructions for sound?  Reading joysticks?

Might make for some cheesy games. :D




------------------------------------------------------------------------------------------------------------------------------------------------------------

# Misc. notes



------------------------------------------------------------------------------------------------------------------------------------------------------------

# Random ramblings

Interesting thought: This program, if I replaced all the 16-bit numbers with 8-bit numbers, could work really well on an 8-bit system.  It might be fun to try compiling for the C64, or even the Geek-Rig.

Another random thought: How could a machine like this (which is pretty much just a wanna-be Forth) handle line numbers, like BASIC?  Could it even do that?  I did have that random idea about taking what I'm learning here and using it in my BASIC... but the two languages are so ridiculously different that idk if it's possible.  But then again, the 6502 was a "stack-based" machine, and it ran BASICs like a champ... idk, this is one of those "random ramblings" I warned about. :)

And another random thought: "The Stack" is very much a thing in C.  And Forth.  And the 6502 processor.  How do C compilers work?  Wouldn't it be insane - stupid, random, and hilarious - to write a C compiler for the "Cheese VM"? :D
