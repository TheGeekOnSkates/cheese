# TO-DO'S FOR 1.0

* Fix the bug in LIST (maybe pass programCounter as a parameter)
* Add some validation in the compile phase - I can just do "ADD" by itself
* WTFM :)
* Push to master and start playing with new features for 1.1



## Thoughts about version 1.1

Debating about using spaces (not just new lines) as a delimiter; Forth does that, after all.

Once ADD is working, some easy additions (cheesy pun definitely intended) would be:

* SUBTRACT
* MULTIPLY
* DIVIDE
* REMAINDER (sorry Sparticus, Modulus lost the battle) :)
Random thought: Should I use symbols for this?  Nah!  These will probably be "opcodes" in an assembly language (lol what's a "cheese assembler"? :D)

I'm also trying to figure out exactly how I want this system to work.

* In the SO post this project was inspired by, I think the guy was really trying to go by the strict definition of an "interpreter" - as in interactive.  You write it, and it runs.  No "compiling" stage.
* On the other hand, if I add a "compiler", converting Assembly files to .kso files, the things I could create would kinda be stand-alone programs, like in my 6502-based creations.  I kinda like that, cuz then you don't have to know the "language" to run the games.
* On the other hand, again, look at Forth - you can include a Forth file, it runs, and you don't need to know the language to use the end result.  Same goes for Python - how many Python-based apps do people run without knowing Python?  But then again Python is an interesting example; cuz then when the program is running, it has to handle both the interpreting and the running (vs. just run the darn thing).  Or maybe support both (again, Python and Forth support that).


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
