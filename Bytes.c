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
#include "Bytes.h"

#define octet 		7 	//really 8 digits but starts at zero
#define nibble 		3 	//really 4 bits
#define offset 		1 	//C programming offset to fortran
#define word 		31 	//length of a word
//#define IMI

//This does ascii to hex to bin all in one. Only to view though
int IMI(unsigned char * textMsg,char Message[]){
	//NOTE: Currently limited to one char
	//char *textMsg = "ADS07-";
	char buff[100]=" ";
	//char *total_Buff;
	int msg_length = 0;
	int i,j,n,x;
	i = j = n = x = 0;	//set to zero
	//unsigned int ch = 0;
	char binary[3] = " ";
	//int textMsg_length = sizeof(textMsg);
	//int char_length = sizeof(textMsg[0]);
	//msg_length = (sizeof(textMsg)/sizeof(textMsg[0])-2);
	msg_length = strlen(textMsg)-offset;
	//printf("Msg_leg:%i TextMsg:%i Char:%i \n",msg_length,textMsg_length,char_length);
	for(i = 0; i<=msg_length; i++)
	{
		//printf("%i\n",i);
		//quick converstion to hex
		printf("Char %c: Hex: 0x\%x \n",textMsg[i],textMsg[i]);
		sprintf(binary, "0x\%x",textMsg[i]);
		int number = (int)strtol(binary,NULL,16);
		printf("Number: %i\n", number);
		//Now convert to binary
		for(j = 0; j<= 7; j++){
			if((number & 0x80)!= 0){
				printf("1");
				buff[j] = '1';
			}
			else{
				printf("0");
				buff[j] = '0';
			}
			if(j == nibble){
				printf(" ");
			}
			number = number << 1;
		}
		printf("\n%s",buff);
		//strcpy(Message, " ");
		strcat(Message,buff);
		printf("\n\n");
	}

	return 0; //tells the user its returning in IMI mode
}
//This method returns binary structure for math functions

/****************************************************************************/
//TODO: test new method
int IMI2BINCAP(unsigned char * textMsg, unsigned int *bin){
	int msg_length = 0;
	int i,j,n;
	i = j = n = 0;	//set to zero
	char binary[3] = " ";
	msg_length = strlen(textMsg)-offset;
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
				bin[i] = 1;
			}
			else{
				printf("0");
				bin[i] = 0;
			}
			if(j == nibble){
				printf(" ");
				//bin doesnt due spaces
			}
			number = number << 1;
		}
		printf("\n\n");
		//now this needs to be put into a buffer for later
	}
	return 0; //tells the user its returning in IMI mode
}
//#endif
/****************************************************************************/
//#ifndef IMI
int HEX_CHAR_TO_BIN(unsigned char *textMsg){ //Best for one value
	//here the code will work under the assumption is straigh bit/hex format
	//char *textMsg = "ADS07-";		//each one is looked at signularly
	int i,j;						//incrementor
	i = j = 0;
	unsigned int number = 0;
	//int msg_length = (sizeof(textMsg)/sizeof(textMsg[0])-2);
	int msg_length = strlen((unsigned char *)textMsg)-1;
	//char binary = " ";
	//printf("Msg_length: %i \n",msg_length);
	for(i=0; i<=msg_length; i++){
		//printf("increment: %i \n",i);
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
			if((number & 0x08 )!= 0){
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
}
//#endif
/****************************************************************************/
void HEX_TO_BIN(unsigned int number){//big-endian
	/*
	 * This actually converts a hex value 0xFFFF to binary
	 *
	 */
	int j = 0;
	//int length = sizeof(Hex_val)/ sizeof(unsigned long int);
	//printf("Size: %i", length);
	//unsigned long int number = Hex_Val;
	printf("Num: %04X \n",number);
	for(j = 0; j<= word/2 ; j++){

		if((number & 0x8000)!= 0){
			printf("1");
		}
		else{
			printf("0");
		}
		if( j == 3  || j==7 || j ==11){
			printf(" ");
		}
		number = number << 1;
		//printf("%i",j);
	}
	printf("\n \n");

}
/****************************************************************************/
//adding overloaded HEX_TO_BIN for unsigned int long
void HEX_TO_BIN_WORD(unsigned long int number){//big-endian
	/*
	 * This actually converts a hex value 0xFFFF to binary
	 *
	 */
	int j = 0;
	//int length = sizeof(Hex_val)/ sizeof(unsigned long int);
	//printf("Size: %i", length);
	//unsigned long int number = Hex_Val;
	printf("Num: &08X \n",number);
	for(j = 0; j<= word; j++){

		if((number & 0x80000000)!= 0){
			printf("1");
		}
		else{
			printf("0");
		}
		//TODO: need to find a better way to spit up the word
		if(j==3||j==7||j==11||j==15||j==19||j==23||j==27){
			printf(" ");
		}
		number = number << 1;
		//printf("%i",j);
	}
	printf("\n \n");
}
/****************************************************************************/
int gppx(char message[]){
	int i;
	char buff=' '; //used to compare chars
	/*
	 * per arinc, in order to get G''(x) one needs to take the first 2
	 * octets and due a one's complement. (IE: 1->0 ; 0->1)
	 */

	for(i=0;i<=15;i++){
		//strncmp(buff,message[i],1);
		//printf("Char: %c \n",buff);
		//if(strcmp(&message[i],"0") != 0){
		if(message[i] == '0'){
			//printf("%c\n",message[i]);
			message[i] ='1';
			//printf("%c is Going to be a 1\n",message[i]);
		}
		//else if(strcmp(&message[i],"1") != 0){
		else if(message[i] == '1'){
			//printf("%c\n",message[i]);
			message[i] = '0';
			//printf("%i Going to be a 0\n",i);
		}
		else/*(message[i]!= '0' ||message[i]!= '1')*/{
			printf("Looks like part of your message is OoB\n");
			printf("Binary only please\n");
			return -8;
		}
	}
	return 0;
}
/****************************************************************************/
void clearMsg(int MsgSize, char Message[]){
	int i = 0;

	for(i=0;i<=MsgSize;i++){
		Message[i]=0;
	}
	printf("Message block cleared\n");
}
int CRCCALC(char Message[],char rtnMsg[],char Fx[]){
	int i,start;	//reused int counter
	int msgIndex = 0;
	int j = 0;
	/*
	 * 1* -> line up messages
	 * 1 -> pull variables into line up.
	 * 2 -> when there are enough variables
	 * 3 -> binary subtraction (modulo 2)
	 * 4 -> move to new zero point
	 * 5 -> rinse and repeat
	 * 6 -> if Polynomial reaches end
	 * 		-return the remainder
	 */
	if(strlen(Message)==0||strlen(rtnMsg)==0|| strlen(Fx)==0 ){
		printf("One of your message length = 0. Try again.");
		return -10;
	}
	//Assumption: F(x) starts with one(1).
	i = 0;
	while(Message[i] == '0'){
		i++;
	}
	start = i; //where to start line up of variables
	do{
		for(j = 0;j<=strlen(Fx);j++){
			if(Message[start+j] ==  Fx[j]){
				Message[start+j] = '0';
			}
			else Message[start+j] = '1';
		}
		i = 0;
		while(Message[i] != "1"){
			i++;
		}
		start = i;
	}while((start+j)<=strlen(Message)); //Continue while there's still somemessage to be read.

	return 0;
}
/****************************************************************************/
int ONESCOMP(unsigned char Message[],int MsgSize){
	//completes the operation of ones complement on the message
	int i;
	for(i=0;i<=MsgSize;i++){
		if(Message[i] == "0"){
			Message[i] = "1";
		}
		else if(Message[i] == "1"){
			Message[i] = "0";
			}
		else{
			printf("Message[%i] is Oob",i);
			return -8;
		}
	}
	return 0;
}



