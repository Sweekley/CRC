//Main.c
/*
 * This was created for Kalitta Air as an attempt
 * to figure out the CRC for LDU messages
 * NOTE: This only works if IMI is always true
 */
#include "Bytes.h"

int main(void){
	unsigned char *textMsg = ((unsigned char *)"ADS07-");
	unsigned char *ones = ((unsigned char *)"0123456789ABCDEF");
	//IMI(textMsg);
	HEXAD(ones);

	return 0;
}

