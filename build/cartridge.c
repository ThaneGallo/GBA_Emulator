#include "cartridge.h"
#include "common.h"

FILE *fp;
char cart_head[0x4F];
struct rom_header rHead;

fp = fopen("","r");

fgets(cart_head, 0x4F, fp);

// for transferring the file contents into the struct for easier usage later

for(int i = 0; i < 4, i++){
rHead.entry[i] = cart_head[i]
}

for(int i = 0; i < 0x30; i++){
rHead.logo[i] = cart_head[0x4 + i];
}

for(int i = 0; i < 16; i++){
rHead.title[i] = cart_head[0x34 + i];
}

rHead.cgb_flag = cart_head[0x43];

rHead.new_lic_code = (cart_head[0x44] << 8) | cart_head[0x45];

rHead.sgb_flag = cart_head[0x46];

rHead.cart_type = cart_head[0x47];

rHead.rom_size = cart_head[0x48];

rHead.ram_size = cart_head[0x49];

rHead.dest_code = cart_head[0x4A];

//check later it says byte on pandocs but uses 2 bytes
rHead.old_lic_code = cart_head[0x4B];

rHead.version = cart_head[0x4C];

rHead.checksum = ;

rHead.global_checksum;



