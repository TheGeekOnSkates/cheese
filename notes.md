# TO-DO'S

## On the "runner" side:

* Finish IF_EQUAL

## On the "compiler" side:

* Add some validation - I can just do "PRINT" by itself and it "compiles".

## When both compiler and runner are finished:

* Add a NEW instruction to clear the program counters/pointers/memory
* Add a command-line option, a file (maybe use the extension ".kso", lol).  That wasy I can just do i.e. "cheese my-test.kso" as I keep tinkering.
* Oh, and add some docs, just cuz :)

## Premature thoughts about version 1.1

Once ADD is working, some easy additions (cheesy pun definitely intended) would be:

* SUBTRACT
* MULTIPLY
* DIVIDE

Also, Forth (which this language is starting to remind me more and more of) has some other features I think would be helpful:

* SWAP
* ROTATE (or just "ROT" in Forth - sorry, that is a word, with a very different meaning lol)

## Pipe dreaming beyond 2.0

* It would be nice to have an array that points to screen coordinates.  Like let's say I do:
	PUSH 67		// Meaning the letter C
	SCREEN 0 0	// Put a C at 0, 0 on the screen
* Oh yeah, and comments would be nice too
* Also, having a separate compiler ("assembler" really) and machine.  Like 6502

Of course then we're bordering on something useful, so probably not gonna happen, but still cool to think about if it did... how about:

* A way to send data to / read data from files
* Maybe another set of instructions for sound?

Might make for some cheesy games. :D

----------------------------------------------------

# Misc. notes and random ramblings

There is currently a bug in LIST; if it hits a "DONE", it exits the loop.  This made sense last night, when DONE was the only end of the program, but now that I have JUMP working I'll need to geek-rig a fix.

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
It might be a good idea to add a "DUMP" command that would show the user's program code like this.

Interesting thought: This program, if I replaced all the 16-bit numbers with 8-bit numbers, could work really well on an 8-bit system.  It might be fun to try compiling for the C64, or even the Geek-Rig.

Another random thought: How could a machine like this (which is pretty much just a wanna-be Forth) handle line numbers, like BASIC?  Could it even do that?  I did have that random idea about taking what I'm learning here and using it in my BASIC... but the two languages are so ridiculously different that idk if it's possible.  But then again, the 6502 was a "stack-based" machine, and it ran BASICs like a champ... idk, this is one of those "random ramblings" I warned about. :)
