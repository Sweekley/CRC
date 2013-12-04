/*
 * This code was created for Kalitta Air and is no liscenced
 * for use elsewhere.
 */
#if !defined(WIN32) || !defined(_WIN32) || !defined(__WIN32)
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#endif

#include "ctype.h"
#include "string.h"

#define octet 		7 //really 8 digits but starts at zero
#define nibble 		3 //really 4 bits
#define offset 		1 //C programming offset to fortran
int main(void){
	/*
	 * This was created for Kalitta Air as an attempt
	 * to figure out the CRC for LDU messages
	 *
	 */
	//non-char approach
/*	char *textMsg = "ADS072D";			//Acutal message
	int fx[5],i=0; //= 0b10001000000100001;
	for(i = 0; i>=5;i++){
		fx[i] = 0b0000;
	};
	int test = 0b1101;	//0-8
	puts("\n");
	puts("Testing binary");
	printf("f(x): %i ",test);
*/
	//Hex version
	//char fx[16] = "10001000000100001"; 	//x^16 + x^12 + x^5 + x^0
	//char textMsg[] = "ADS7-";			//Test text Message from 622-4
	char *textMsg = "ADS7-";
	//char *buff=" ";
	int msg_length = 0;
	char convBin[9];
	//char textMsgHex[31] = " ";				//Test text Message in Hex
	//char
	//int test = 0x4B;
	//char test[0] = "A";
	//printf("f(x): %i \n",test);
 	//printf("Text Message: %02X\n", test);
	//printf("Text Message: %02X\n", &textMsg);
	//printf("Test Message: %s\n", textMsg);

	//Method above returns the location of the string me'thinks
	int i,j,n;
	i = j = n = 0;	//set to zero
	//unsigned int ch = 0;
	char binary[3] = " ";
	msg_length = (sizeof(textMsg)/sizeof(textMsg[0])+1);
	//printf("Msg length: %i\n",msg_length);
	for(i = 0; i<msg_length; i++)
	{
		printf("%i\n",i);
		//quick converstion to hex
		printf("Char %c: Hex: 0x\%x \n",textMsg[i],textMsg[i]);
		sprintf(binary, "0x\%x",textMsg[i]);
		int number = (int)strtol(binary,NULL,16);
		printf("Number: %i\n", number);
		//Now convert to binary
		for(j = 0; j<= 7; j++){
			if((number & 0x80 )!= 0){
				printf("1");
			}
			else{
				printf("0");
			}
			if(j == nibble){
				printf(" ");
			}
			number = number << 1;
		}
		printf("\n");
		//now this needs to be put into a buffer for later

		//printf("Buff: %s \n",binary);
		//printf("Buff: %s",buff);
		//printf("Buff: %s", buff);
		//sprintf(buff,"0x\%x",textMsg[i]);
		//binary = (int)strtol(textMsg,NULL,16);
		//printf("Binary: %i",binary);
		//printf("Buff: %s \n",buff);
		//printf("Binary: %i \n",ch);
		//printf("Hex: %02x\n",textMsg[i]);
		//binary = (int)strtol(&textMsg[i],NULL,16);
		//printf("Binary: %i\n",binary);

	}

	return 0;

}
