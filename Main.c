//Main.c
/*
 * This was created for Kalitta Air as an attempt
 * to figure out the CRC for LDU messages
 * NOTE: This only works if IMI is always true
 */
#include "Bytes.h"
#define CHAR2BITS 8
#define Maxchar 255

int main(void){
	unsigned char Message[CHAR2BITS*Maxchar]; 	//BIG NOTE: This is in binary
	unsigned char rtnMsg[32];					//MSG returned from CRC
	unsigned int msgSize = 0;
	unsigned char *function = "10001000000100001";
	int i = 0;
	msgSize = Maxchar*CHAR2BITS;
	//unsigned char *textMsg = ((unsigned char *)"ADS07-");
	//unsigned char *ones = ((unsigned char *)"FFFF");
	//unsigned char *textMsg = ((unsigned char *)"EXAMPLE CRC TEXT");
	//unsigned int HexVal = 0xFFFF;
	//unsigned int mask = 0x00FF;
	//unsigned int test = 0x0000;
	//unsigned long int poly = 0x11021;
	//poly = 10001000000100001
	//G''(x) = x^16 + x^12 + x^5 + x^0;
	//IMI(textMsg);
	//IMI_TO_BIN_CAP(*textMsg);
	//HEX_CHAR_TO_BIN(textMsg);
	//HEX_TO_BIN(0x00FF);
	//HEX_TO_BIN_WORD(0xffffffffffffffff);
	//full 32 bit word can't be done right now. So we'll stick to half words
	//int shift = ishft(HexVal,-8);
	//unsigned int result = HexVal >>8;
	//unsigned int endResult = 0x0000;
	//printf("orig: %i result: %i mask: %i\n", HexVal,result,mask);
	//endResult = result & mask;
	//printf("endResult: %u",endResult);
	clearMsg(msgSize,Message[CHAR2BITS*Maxchar]);

	int conversion = gppx(Message[CHAR2BITS*Maxchar]);
	if(conversion >= 0){
		printf("The first 2 octets have been converted");
	}
	else {
		printf("There may have been an issue with the conversion.");
		return -1;
	}


	/*
	 * now: G''(x) = Message
	 *      ______
	 *      F(x) = 10001000000100001
	 */
	return 0;
}

