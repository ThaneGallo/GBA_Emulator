## common.h
Contains some typedef calls to shorten the unsigned standard integers of different sizes to a new shorthand i.e. uint8_t --> u8, uint16_t --> u16 and so on and so forth.
Also has a couple macros for simplified bit manipulation as well as a macro to exit for unimplimented features.

## bus.h


## cpu.h
The CPU within the Gameboy is known as the Sharp SM83. It has a clock rate of 4.194304 MHz

Within this header exists a struct containing 8 8-bit registers for operations and the 2 16-bit registers for the stack pointer and the program counter.

The registers are then stored in a cpu_context struct which. 

## instructions.h
The [instruction set](https://gbdev.io/gb-opcodes/optables/) for the SM83 needs to first be broken down into struct named instruction containing addressing mode, register types, cond type, and parameters. 

Then a function is made which uses the instruction's opcode in the game file to eeference a lookup table which contains each instruction's specific information to allow the cpu to process it properly. 

## cartridge.h
So every "Cartridge"(.gb file) has a header from 0x0100 to 0x014F and contains miscillaneous info about each game individually such as its Title, Rom Size, Cartridge type, etc. More info can be found [here](https://gbdev.io/pandocs/The_Cartridge_Header.html) on the gdbdev pan docs.

All of this info is parsed and stepped through and stored in the rom_header struct to be used to intialize each different game file.
