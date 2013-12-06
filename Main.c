//Main.c
/*
 * This was created for Kalitta Air as an attempt
 * to figure out the CRC for LDU messages
 * NOTE: This only works if IMI is always true
 */
#include "Bytes.h"

int main(void){
	//unsigned char *textMsg = ((unsigned char *)"ADS07-");
	//unsigned char *ones = ((unsigned char *)"FFFF");
	unsigned int HexVal = 0xFFFF;
	unsigned int mask = 0x00FF;
	unsigned int test = 0x0000;
	unsigned long int poly = 0x11021;
	//poly = 10001000000100001
	//G''(x) = x^16 + x^12 + x^5 + x^0;
	//IMI(textMsg);
	//HEX_CHAR_TO_BIN(textMsg);
	//HEX_TO_BIN(0x00FF);
	//HEX_TO_BIN_WORD(0x00ffffff);
	//int shift = ishft(HexVal,-8);
	//unsigned int result = HexVal >>8;
	//unsigned int endResult = 0x0000;
	//printf("orig: %i result: %i mask: %i\n", HexVal,result,mask);
	//endResult = result & mask;

	//printf("endResult: %u",endResult);
	return 0;
}

