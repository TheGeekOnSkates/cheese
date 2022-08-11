## Whoa!  More features?

I figured, why not?  We're calling this a 1.0, why not do one more night's worth of fun tinkering before dropping this cheesy project on my friends?!  :)

Okay seriously, there are a few things I had noticed about my previous commit:

1. What I ended up with was not exactly what that SO post suggested (like that person wanted ADD to add the top 2 numbers on the stack, like Forth).  I could do that, but I'm not building a Forth.  I'm making CHEESE! :D
2. The other math functions are so, SO easy to implement that it was not a big deal to add.

------------------------------------------------------------------------------------------------------------------------------------------------------------

# TO-DO's before I REALLY release 1.0

* Add a MOD (Modulus / remainder) instruction
* Add an assemble_line function (remove a bunch of logic from main() - I'll be using main() for other stuff later)
* Organize list, run, and assemble_line alphabetically by instruction (currently done by unwritten categories like math functions, jumping functions etc.)
* Test, test, and test some more, just cuz :)
* Update the manual (also, don't forget to explain why there is a piece of cheese on their terminal :D ).



------------------------------------------------------------------------------------------------------------------------------------------------------------

## Features for future 1.x releases

* REMAINDER (sorry Sparticus, Modulus lost the battle) :)
* SWAP
* ROTATE (sorry Forth, ROT is a word and using it doesn't make sense here :D)
* A CLEAR instruction (rather than SYS clear)
* Having SYS work like other instructions: don't run immediately; only run when RUN is called; then, put the end result (the return value of system()) on the stack.
* A command to print the contents of the stack (like .S in Forth)
* POKE <address> - POP the top number on the stack to <address>
* PEEK <address> - PUSH the number at <address> to the top of the stack

* BNE and BEQ (like 6502 Assembly, where you "branch" by a relative number - like instead of:
	PUSH 1 [addresses 0-1]
	JNE 5 [addresses 2-3]
	DONE [address 4, which gets skipped]
  I could just do this:
	PUSH 1 [addresses 0-1, not changed]
	BNE 2 [If top of stack == 0, move forward 2 blocks _from here_]


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
