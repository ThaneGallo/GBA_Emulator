#include "cartridge->h"
#include "common->h"
#include "stdio->h"

typedef struct {
	char title[1024];
	u32 rom_size;
	u8 rom_data;
	rom_header *header;
	
} ctx;


static ctx cart;

static const char *ROM_Type[] {
	"ROM ONLY",
	"MBC1",
	"MBC1+RAM",
	"0x4 ??",
	"MBC1+RAM+BATTERY",
	"MBC2",
	"0x7 ??",
	"MBC2+BATTERY",
	"ROM+RAM",
	"0xA ??",
	"ROM+RAM+BATTERY",
	"MMM01",
	"MMM01+RAM",
	"0xE ??"
	"MMM01+RAM+BATTERY",
	"MBC3+TIMER+BATTERY",
	"MBC3+TIMER+RAM+BATTERY",
	"MBC3",
	"MBC3+RAM+BATTERY",
	"0x14 ??",
	"0x15 ??",
	"0x16 ??",
	"0x17 ??",
	"0x18 ??",
	"MBC5",
	"MBC5+RAM",
	"MBC5+RAM+BATTERY",
	"MBC5+RUMBLE",
	"MBC5+RUMBLE+RAM",
	"MBC5+RUMBLE+RAM+BATTERY",
	"0x1F ??"
	"MBC6",
	"0x21 ??",
	"MBC7+SENSOR+RUMBLE+RAM+BATTERY",
}

static const char *LIC_Code[0xA5]{
	[0x00] = "None",
	[0x01] = "Nintendo R&D1",
	[0x08] = "Capcom",
	[0x13] = "Electronic Arts",
    [0x19] = "b-ai",
	[0x20] = "kss",
	[0x22] = "pow",
	[0x24] = "PCM complete",
	[0x25] = "san-x",
	[0x28] = "Kemco Japan",
	[0x29] = "seta",
	[0x30] = "Viacom",
	[0x31] = "Nintendo",
	[0x32] = "Bandai",
	[0x33] = "Ocean/Acclaim",
	[0x34] = "Konami",
	[0x35] = "Hector",
	[0x37] = "Taito",
	[0x38] = "Hudson",
	[0x39] = "Banpresto",
	[0x41] = "Ubisoft",
	[0x42] = "atlas",
	[0x44] = "Malibu",
	[0x46] = "angel",
	[0x47] = "Bullet-Proof",
	[0x49] = "irem",
	[0x50] = "Absolute",
	[0x51] = "acclaim",
	[0x52] = "Activision",
	[0x53] = "American Sammy",
	[0x54] = "Konami",
	[0x55] = "Hi tech entertainment",
	[0x56] = "LJN",
	[0x57] = "Matchbox",
	[0x58] = "Mattel",
	[0x59] = "Milton Bradley",
	[0x60] = "Titus",
	[0x61] = "Virgin",
	[0x64] = "LucasArts",
	[0x67] = "Ocean",
	[0x69] = "Electronic Arts",
	[0x70] = "Infogrames",
	[0x71] = "Interplay",
	[0x72] = "Broderbund",
	[0x73] = "sculpted",
	[0x75] = "sci",
	[0x78] = "THQ",
	[0x79] = "Accolade",
	[0x80] = "misawa",
	[0x83] = "Iozc",
	[0x86] = "Tokuma Shoten Intermedia",
	[0x87] = "Tsukuda Original",
	[0x91] = "Chunsoft",
	[0x92] = "Video system",
	[0x93] = "Ocean/Acclaim",
	[0x95] = "Varie",
	[0x96] = "Yonezawa/s'pal",
	[0x99] = "Pack in soft",
	[0xA4]= "Konami (Yu-Gi-Oh!)"
}


const char *cart_lic_name(){
	if(cart->header->old_lic_code <= 0xA4){
	return(LIC_Code(cart->header->old_lic_code));
	}

	return "UNKNOWN"
}

const char *cart_type_name(){
	if(cart->header->cart_type <= 0x22){
	return(ROM_Type(cart->header->cart_type));
	}
	return "UNKNOWN"
}



bool cart_load(char *cart){
	snprintf(char *cart->title, sizeof(cart->title), "%s", cart);

	FILE *fp = fopen(cart, "r");

	if (!fp){
	printf("Failed to open: %s\n", cart);
	return false;
	}

	printf("Opened: %s\n", cart->title);

	//goes thourgh file and goes to end
	fseek(fp, 0, SEEK_END);

	//writes end to romsize
	cart->rom_size = ftell(fp);

	//brings you back to the beginning of the file
	rewind(fp);

	//allocates the size of the rom for the data section
	cart->rom_data = malloc(cart->rom_size);
	
	// read data into rom size one byte at a time from file fp
	fread(cart->rom_data, cart->rom_size, 1, fp);
	fclose(fp);

	//typecast the data as a rom header and shift the rom data to the hardware specs
	cart->header = (rom_header *)(cart->rom_data + 0x100);
	
	//sets last value as terminating manually
	cart->header->title[15] = 0;

	//printing for debug
	printf("Cartridge Loaded:\n");
	printf("\t Title   : %s\n", cart->header->title);
	printf("\t Type    : %2.2X (%s)\n", cart->header->rom_type, cart_type_name());
	printf("\t ROM size: %d KB\n", 32 << cart->header->rom_size);
	printf("\t RAM size: %2.2X\n", cart->header->ram_size);
	printf("\t LIC code: %2.2X (%s)\n", cart->header->old_lic_code, cart_lic_name());
	printf("\t ROM Vers: %2.2X\n", cart->header->version);
 
	u16 checksum = 0;
	for(u16 i = 0x134, i<=0x014C; i++){
	checksum = checksum - cart->rom_data[i] - 1
	}
	
	printf("\t Checksum: %2.2X\n", cart->header->checksum, (checksum & 0xFF) ? "passed" : "fail");
	
	return true;

}

u8 cart_read(u16 address){
	//ROM ONLY type supported

return ctx->rom_data[address];

}


void cart_write(u16 address, u8 value){

value = ctx->rom_data[address]


}
