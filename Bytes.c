/*
 * This code was created for Kalitta Air and is no liscenced
 * for use elsewhere. References
 * [1] ARINC 622-4
 * [2] ARINC 429
 * [3] Notes from Carl
 */

//work in either linux or windows
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
//#define IMI

int main(void){
	/*
	 * This was created for Kalitta Air as an attempt
	 * to figure out the CRC for LDU messages
	 * NOTE: This only works if IMI is always true
	 */
	//TODO: Figure out why its always skipping #1 when its char []
	//char fx[16] = "10001000000100001"; 	//x^16 + x^12 + x^5 + x^0
#ifdef IMI
	char *textMsg = "ADS07-";
	//char *buff=" ";
	//char *total_Buff;
	int msg_length = 0;


	int i,j,n;
	i = j = n = 0;	//set to zero
	//unsigned int ch = 0;
	char binary[3] = " ";
	//int textMsg_length = sizeof(textMsg);
	//int char_length = sizeof(textMsg[0]);
	//msg_length = (sizeof(textMsg)/sizeof(textMsg[0])-2);
	msg_length = strlen(textMsg)-offset;
	//printf("Msg_leg:%i TextMsg:%i Char:%i \n",msg_length,textMsg_length,char_length);
	for(i = 0; i<=msg_length; i++)
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
		printf("\n\n");
		//now this needs to be put into a buffer for later
	}
	return 0; //tells the user its returning in IMI mode
#endif

#ifndef IMI
	//here the code will work under the assumption is straigh bit/hex format
	char *textMsg = "ADS07-";		//each one is looked at signularly
	int i,j;						//incrementor
	i = j = 0;
	int number = 0;
	//int msg_length = (sizeof(textMsg)/sizeof(textMsg[0])-2);
	int msg_length = strlen(textMsg)-1;
	//char binary = " ";
	//printf("Msg_length: %i \n",msg_length);
	for(i=0; i<=msg_length; i++){
		printf("increment: %i \n",i);
		//only need 1 char at a time
		printf("Char: %c \n",textMsg[i]);
		if((textMsg[i]>='0')&&(textMsg[i]<='9')){

			number = textMsg[i] - '0';
			//number = atoi(&textMsg[i]);
		}
		//if(isalpha(textMsg[i])){ //if is an alphabetic
		else{
			switch(textMsg[i]){
			case 'A':
				number = 10;
				break;
			case 'B':
				number = 11;
				break;
			case 'C':
				number = 12;
				break;
			case 'D':
				number = 13;
				break;
			case 'E':
				number = 14;
				break;
			case 'F':
				number = 15;
				break;
			default:
				puts("Something wicked happened");
				break;
			}
		}
		printf("Num: %i \n",number);
		for(j = 0; j<= nibble; j++){
			if((number & 0x30 )!= 0){
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
		printf("\n \n");
	}

	return 1;	//Tells user that we are in bit oriented mode
#endif


}


