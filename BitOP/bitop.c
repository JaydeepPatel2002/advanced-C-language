//
// Created by XIN Wang on 2023-03-17.
//

#include <stdio.h>
#include <stdlib.h>

//255 -> 11111111
void showBits(int value, int bytes) {

    unsigned int filter = 1;
    int bit;
    char * bitString = (char*)malloc(33);
    for(bit = 0; bit < bytes*8; bit++)
    {
        if( value & filter )
        {
            bitString[31-bit]='1';
        }
        else
        {
            bitString[31-bit]='0';
        }
        filter *=2;
    }
    bitString[32]='\0';
    printf("The value %16u is \t%s\n", value, &bitString[32-bytes*8]);
    free(bitString);
}
//1110101 -> 1010111
unsigned int reverseBits(unsigned int d)
{
    //For each bit from right(lower) bit
        //get the bit by using & and mask
        //use or op (set bit to 1) to update rs
        unsigned char totalBits = 32;
        unsigned int rs  = 0; // 00000000 00000000 00000000 00000000
        unsigned int curBit = 0;
        for(int i =0;i<totalBits;i++)
        {
            curBit = d & (1 <<i); //use AND to get bit
            // if i=0 mask: 00000000 00000000 00000000 00000001
            // if i=1 mask: 00000000 00000000 00000000 00000010
            //if i =2 mask: 00000000 00000000 00000000 00000100
            if(curBit)
            {
                rs |= 1 << (totalBits-i-1);//use OR to set bit to 1
                //if i=0 mask: 10000000 00000000 00000000 00000000
                //if i=1 mask: 01000000 00000000 00000000 00000000
            }
        }
        return rs;
}

void bitAND()
{
    unsigned char a = 0x48;
    unsigned char b = 0x88;
    unsigned char rs = a & b;
//    printf("Bitwise AND of %d and %d is %d\n", a,b,rs);
//    showBits(a,1);
//    showBits(b,1);
//    showBits(rs,1);

    int x = 0x030B1A0F;
    int maskFindBit = 0x00000010;
    unsigned int maskSetBitToZero = 0xFFFFFFFE;

    showBits(x, sizeof(int));
    showBits(maskFindBit,sizeof(int));
    showBits(maskSetBitToZero,sizeof(int));

    showBits(x & maskFindBit, sizeof(int));
    showBits(x & maskSetBitToZero, sizeof(int));

}

void bitOR()
{
    unsigned char a = 0x48;
    unsigned char b = 0xB8;
    unsigned char rs = a | b;
//    printf("Bitwise OR of %d and %d is %d\n", a,b,rs);
//    showBits(a,1);
//    showBits(b,1);
//    showBits(rs,1);

    int x = 0x030B1A0F;
    int maskSetBitTo1 = 0xFFFF0000; //sets first 4 bytes to 1's and preserves other bits
    showBits(x,4);
    showBits(maskSetBitTo1,4);
    showBits(x | maskSetBitTo1, 4);
}

//encryption C = plaintext^key, then P = ciphertext^key
void bitXOR()
{
    unsigned char a = 0x48;
    unsigned char b = 0xB8;
    unsigned char rs = a ^ b;
    printf("Bitwise XOR of %d and %d is %d\n", a,b,rs);
    showBits(a,1);
    showBits(b,1);
    showBits(rs,1);

    //Flip every bit same as NOT
    showBits(a ^ 0xff, 1);

    //No change
    showBits(a ^ 0x0, 1);
}

void bitNOT()
{
    unsigned char a = 0x48;
    unsigned char rs = ~a;
    printf("Bitwise NOT of %d is %d\n", a,rs);
    showBits(a,1);
    showBits(rs,1);
}

void bitSHIFT()
{
    short x = 37;
    int z = 1;
    signed char y = -128;
    char value = 0xD3;
    char mask = 0x0F;

//    printf("No shift in x:\n");
//    showBits(x,2);
//
//    printf("Shift 1 bit to left in x:\n");
//    showBits(x<<1,2);
//
//    printf("Shift 2 bits to right in x:\n");
//    showBits(x>>2,2);
//
//    printf("No shift in z:\n");
//    showBits(z,4);
//    printf("Shift z 30 bits to the left:\n");
//    showBits(z<<30,4);
//    printf("Shift z 1 bits to the right:\n");
//    showBits(z>>1,4);


//    x = -100;
//    printf("No shift in x:\n");
//    showBits(x,2);
//
//    printf("Shift 2 bits to right in x:\n");
//    showBits(x>>2,2);

//    unsigned short s = 1;
//    showBits(s,2);
//    for(int i = 0; i < 5; i++)
//    {
//        s = s<<1;
//        showBits(s,2);
//    }
//
//    s = 1024;
//    showBits(s,2);
//    for(int i = 0; i < 5; i++)
//    {
//        s = s>>1;
//        showBits(s,2);
//    }

    unsigned char uc = 0b11010011;
    showBits(uc,1);
    unsigned char upper_uc;//00001101
    unsigned char lower_uc;//00000011
    //nibble means half of a byte. high nibble and low nibble
    upper_uc = uc >> 4;
    showBits(upper_uc,1);

//    lower_uc = uc << 4;
//    lower_uc = lower_uc >>4;
    lower_uc = uc & 0x0f;
    showBits(lower_uc,1);

}

unsigned char swapNibbles(unsigned  char c)
{
    // c = 0b11010011;
    //return 0b00111101
    //c<<4 00110000
    //c>>4 00001101
    //|    00111101
    return (c<<4) | (c>>4);
}

unsigned char blendNibbles(unsigned char a, unsigned char b)
{
    // a = 0b11010011
    // b = 0b00101111
    //return 0b11011111
    //a & oxf0 = 11010000
    //11010011 a
    //11110000 mask 0xf0
    //11010000

    //00101111 b
    //00001111 mask ox0f
    //00001111
    //b & 0x0f = 00001111
    return (a & 0xf0) | (b & 0x0f);
}
#define	ENGLISH_SIGNAL	0x01
#define	FRENCH_SIGNAL	0x02
#define	CREE_SIGNAL		0x04

#define	ANSWER_SIZE		5


//boolean[3] --> 1byte
unsigned char languageQuestions()
{
    unsigned char languages=0;//00000000
    char answer[ANSWER_SIZE];

    printf("Do you speak English(y/n)? ");
    fgets(answer,ANSWER_SIZE,stdin);
    if(answer[0]=='y') languages|=ENGLISH_SIGNAL;//00000001

    printf("Do you speak French(y/n)? ");
    fgets(answer,ANSWER_SIZE,stdin);
    if(answer[0]=='y') languages|=FRENCH_SIGNAL;//00000010

    printf("Do you speak Plains Cree(y/n)? ");
    fgets(answer,ANSWER_SIZE,stdin);
    if(answer[0]=='y') languages|=CREE_SIGNAL;//00000100

    return languages;

}

void printGreeting(unsigned char languages)
{
    if(languages & ENGLISH_SIGNAL) printf("Hello!\n");
    if(languages & FRENCH_SIGNAL) printf("Bonjour!\n");
    if(languages & CREE_SIGNAL) printf("Tan'si!!\n");// https://apihtawikosisan.com/2011/04/tansi/
}

// When done, create a new C file(and update CMAKE) (or write functions within this project)
// that will ask for an input filename and an output filename,
// then read each byte from the input filename (use fgetc), combine that byte with
// a byte from the file "random.pad" (in the Exercises folder) using XOR, and write
// the combined byte to the output filename (use fputc).
// That will create an encrypted file (using random pad or one-time pad encryption)
// which can be unencrypted by using the encrypted file as the input filename.




int main(int argc, char ** argv) {
    unsigned char lang = languageQuestions();
    showBits(lang,1);
    printGreeting(lang);
//    showBits(12345,4);
//    showBits(reverseBits(12345),4);
//    showBits(1 | 1, 4);
//    showBits(1 << 1,4);
//    showBits(1 | 1 << 1,4);

//    showBits(swapNibbles(0b11010011),1);//Should disp 0b00111101
//    showBits(blendNibbles(0b11010011,0b00101111),1);//Should disp 0b11011111
//    bitSHIFT();
//    bitNOT();
//    bitXOR();
//    bitOR();
//    bitAND();
//    showBits(123444, 4);
//    showBits(255,1);
//    showBits(32845,2);

}