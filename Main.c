//Main.c
/*
 * This was created for Kalitta Air as an attempt
 * to figure out the CRC for LDU messages
 * NOTE: This only works if IMI is always true
 */




int main(void){
	char *textMsg = "ADS07-";

	IMI(textMsg);
	HEXAD(textMsg);


}

