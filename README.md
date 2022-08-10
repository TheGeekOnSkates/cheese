# 🧀 CHEESE

A fun "virtual machine" I built in a few days

## Background

This project arose out of an increased curiosity about building low-level programming/scripting languages.  Of course my BASIC has 2 practical uses - games and shell scripts.  But at the time of this writing it was a crashy mess I didn't feel like debugging.  I wanted something that was fun, and could never feel like work.  Not only that, I wanted to know how "real" BASICs (particularly the 8-bit ones) could be so stable and robust and fit into ~8K of memory.

So, one night I stumbled acros [this little Stack Overflow post](https://stackoverflow.com/questions/6887471/how-would-i-go-about-writing-an-interpreter-in-c) where the "accepted" answer was sort of a mini-challenge: Build a program with a stack (like Forth has) and 6-7 instructions to do stuff with it.  He called it a "very simple stack based virtual machine".  Challenge accepted!


## How to use the program

As of version 1.0, Cheese doesn't take any command-line options; you just run it.  All you have to do is type (or paste) in your code, then use the RUN instruction to see what it does.


## Instruction set reference

### PUSH <number>

Pushes a number onto the stack (I'm assuming you're at least a little familiar with stacks, so I won't go into detail here - at least for now)

### POP

"Pops" (removes) the number at the top of the stack

### DUP

Duplicates (makes a copy of) the top number on the stack, and pushes that on the stack

### ADD <number>

Adds a number to the number at the top of the stack

### JUMP <number>

Moves the program to a specific location in memory; the number here needs to be between 0 and 65535.

### IF_EQUAL <number>

Does a JUMP if the number at the top of the stack is zero

### PRINT

Prints the number at the top of the stack, then does a POP (removes it from the stack)

### RUN

Runs your current program

### LIST

Lists your current program

### DUMP

Same as LIST except that it also says which code (or number) is at which address in memory

### NEW

Deletes your current program and clears the stack

### SYS <string>

Runs a system command.  For example, running `SYS clear` on Linux clears the screen).

### EXIT

Exits Cheese
