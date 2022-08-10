# TO-DO'S FOR 1.0

* Add some validation in the compile phase - I can just do "ADD" by itself
* Push to master
* Post on GitHub
* Play with ideas below for 1.1

## Thoughts about version 1.1

Now that ADD is working, some easy additions (cheesy pun definitely intended) are:

* SUBTRACT
* MULTIPLY
* DIVIDE
* REMAINDER (sorry Sparticus, Modulus lost the battle) :)

Other, not-as-easy but just-as-useful instructions would be:

* SWAP
* ROTATE

## Thoughts about version 1.2

* Cheese would also benefit from:

* A CLEAR instruction (rather than SYS clear)
* Having SYS work like other instructions: don't run immediately; only run when RUN is called; then, put the end result (the return value of system()) on the stack.
* A command to print the contents of the stack (like .S in Forth)

## Thoughts about version 1.3

A way to edit specific blocks of memory.  Like let's say I have:
	PUSH 7
	IF_EQUAL 100
And I want to change that 7 to a zero.  It would be nice to just do:
	1 [the memory address] 0 [the new value]
Or maybe I want to change the IF_EQUAL to a JUMP; I could do:
	2 [meaning the address] JUMP [the new value]

But what if I could go further than that?  What if I did:

EDIT 0-2

0: You type in some text or leave blank to keep as-is
1: Same as 0
2: Same as 1



## Premature thoughts about version 2.0

I think 2.0 is where this program becomes more like a virtual machine.  And I guess "virtual machine" is the right term for what I like to build - "emulators of computers that never existed" is too wordy (lol).  But okay seriously, what I mean is:

1. One program (or command-line option) to compile Cheese assembly into .kso files (LOL can't type this with a straight face!)
2. Another program / option to disassemble .kso files
3. The main program might be something like Python, Forth, or Node - either an interactive thing for one-liners or a program to run code files.


## Pipe dreaming beyond 2.0

* Not to mention, variables.  Forth has "words" which are awesome and fun and different, but I'm kind of thinking simpler: I can run LET CHEDDAR = 42 and the program will replace all occurrences of CHEDDAR with 42 when compiling.
* It would be nice to have an array that points to screen coordinates.  Like let's say I do:
	PUSH 67		// Meaning the letter C
	SCREEN 0 0	// Put a C at 0, 0 on the screen
* Oh yeah, and comments would be nice too

Of course then we're bordering on something useful, so probably not gonna happen, but still cool to think about if it did... how about:

* A way to send data to / read data from files
* Input!  How could I have forgotten that!  (Thank you, Johnny 5) :D
* And while we're at it, what about printing strings?  Right now, Cheese can only print numbers.
* While we're at it, what about floats?  Forth uses a lot of fixed-point (which really does make a lot of sense) but why make users math that hard? :D
* Maybe another set of instructions for sound?  Reading joysticks?

Might make for some cheesy games. :D

----------------------------------------------------

# Misc. notes and random ramblings

For JUMP, I was able to test it (and get it working) with this program:
	JUMP 3
	DONE
	PUSH 7
	PRINT
If you look at this program, the memory is:
	[0] JUMP
	[1] 3
	[2] DONE
	[3] PUSH
	[4] 7
	[5] PRINT
So my program sees "JUMP 3" and skips over position 2.

Now for IF_EQUAL, how about...
	PUSH 5
	ADD -5
	IF_EQUAL 7
	DONE
	PUSH 42
	PRINT
Again, let's look at this:
	[0] PUSH
	[1] 5
	[2] ADD
	[3] -5
	[4] IF_EQUAL
	[5] 7
	[6] DONE
	[7] PUSH 42
	[8] PRINT

Interesting thought: This program, if I replaced all the 16-bit numbers with 8-bit numbers, could work really well on an 8-bit system.  It might be fun to try compiling for the C64, or even the Geek-Rig.

Another random thought: How could a machine like this (which is pretty much just a wanna-be Forth) handle line numbers, like BASIC?  Could it even do that?  I did have that random idea about taking what I'm learning here and using it in my BASIC... but the two languages are so ridiculously different that idk if it's possible.  But then again, the 6502 was a "stack-based" machine, and it ran BASICs like a champ... idk, this is one of those "random ramblings" I warned about. :)

And another random thought: "The Stack" is very much a thing in C.  And Forth.  And the 6502 processor.  How do C compilers work?  Wouldn't it be insane - stupid, random, and hilarious - to write a C compiler for the "Cheese VM"? :D
