/*
 * creating external for bytes here. I was hoping I would
 * have to dig this deep to do this
 *
 */
#ifndef BYTES_H_
#define BYTES_H_

//extern void run8hz(void);
//extern int ASCII_CHAR_TO(unsigned char *textMsg);
extern int IMI(unsigned char *textMsg);
extern int HEX_CHAR_TO_BIN(unsigned char *textMsg);
extern void HEX_TO_BIN(unsigned int Hex_val);
extern void HEX_TO_BIN_WORD(unsigned int long number);
#endif
