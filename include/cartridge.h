#pragma once

#include "common.h"

typedef struct {
	//jumps to 0x0100 to begin boot
	u8 entry[4];
	//display nintendo logo
	u8 logo[0x30];

	//contains title of game in upper case ASCII
	char title[16];
	//color gameboy  mode flag
	u8 cgb_flag;
	//indicates the game publisher
	u16 new_lic_code;
	//super gameboy support
	u8 sgb_flag;
	//indicates hardware in cartridge 
	u8 cart_type;
	u8 rom_size;
	u8 ram_size;
	//shows where game was intended to be sold (japan vs elsewhere)
	u8 dest_code;
	//same as new but pre sgb
	u8 old_lic_code;
	//marks version number of game
	u8 version;
	//checks at end if everything was transmitted
	u8 checksum;
	//sum of all bytes except two checksum bytes
	u8 global_checksum

} rom_header;

bool cart_load(char *cart)
