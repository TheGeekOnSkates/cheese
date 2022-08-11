# TO-DO's before I REALLY release 1.0

* Add AFS (add from stack), SFS (subtract from stack) etc.
* Set up my current ADD to be ADD #, SUB to be SUB # etc. in assemble_line
* Re-add ADD/SUB/MUL/DIV/MOD to do those math things on memory addresses (kind of like how in 6502 you can do LDA #$FF [literal] or LDA $FF [address])
* I have an idea for how to handle strings: Write a function that returns a char*, by reading memory untill it hits a zero (like a C-style NULL terminator).
* If I do that (and that might wait for 1.1), then rework SYS to be like other functions
* Test, test, and test some more (play with it), just cuz :)
* Update the manual
	- Make sure to document which instructions are not available except when RUNning (maybe call it "direct mode" and "program mode" like BASIC)
	- Also, don't forget to explain why there is a piece of cheese on their terminal :D



------------------------------------------------------------------------------------------------------------------------------------------------------------

## Features for future 1.x releases

* REMAINDER (sorry Sparticus, Modulus lost the battle) :)
* SWAP
* ROTATE (sorry Forth, ROT is a word and using it doesn't make sense here :D)
* At first I wanted CLEAR, but now I'm kind of thinking maybe ESC (like in my basic); this way it wouldn't require ncurses or knowledge of every single terminal out there lol; I'd like to keep this in standard C as much as possible).
* Have SYS work like other instructions: don't run immediately; only run when RUN is called; then, put the end result (the return value of system()) on the stack.
	Unfortunately, this turned out to be tougher than it looks.  Why?  Because I haven't come up with a way for Cheese to handle strings yet. :D

## Random thoughts about version 2.0

I think 2.0 is where this program becomes more like just an interpreter.  What I mean is:

1. One program (or command-line option) to compile Cheese assembly into .kso files (LOL can't type this with a straight face!)
2. Another program / option to disassemble .kso files
3. The main program might be something like Python, Forth, or Node - either an interactive thing for one-liners or a program to run code files.

Apart from that, there'll probably be a bunch of other features that wouldn't make sense now:

* Comments
* INCLUDE "file.asm"
* Variables.  Forth has "words" which are awesome and fun and different, but I'm kind of thinking simpler: I can run LET CHEDDAR = 42 and the program will replace all occurrences of CHEDDAR with 42 when compiling.
* Labels, like other assemblers have.

Of course then we're bordering on something useful, so probably not gonna happen, but still cool to think about if it did... how about:

## Pipe dreaming beyond 2.0

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
