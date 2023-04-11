//
// Created by wangxi on 2023-03-15.
//
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// 255->11111111
void showBits(int value,int bytes)
{
    unsigned int filter = 1;
    int bit;
    char * bitString = (char*) malloc(33);
    for(bit = 0;bit<bytes*8;bit++)
    {
        if( value & filter)
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
    printf("The value %16u is \t%s\n",value,&bitString[32-bytes*8]);
    free(bitString);
}

void bitAND()
{
    unsigned char a = 0x48;
    unsigned char b = 0xB8;
    unsigned char rs = a & b;
//    printf("Bitwise AND of %d and %d is %d\n",a,b,rs);
//    showBits(a,1);
//    showBits(b,1);
//    showBits(rs,1);

    int x = 0x030B1A0F;
    int maskFindBit = 0x00000010;
    unsigned int maskSetBitToZero = 0xFFFFFFFE;

    showBits(x,sizeof(int));
    showBits(maskFindBit,sizeof(int));
    showBits(maskSetBitToZero,sizeof(int));

    showBits(x & maskFindBit,sizeof(int));
    showBits(x & maskSetBitToZero,sizeof(int));

}

void bitOR()
{
    unsigned char a = 0x48;
    unsigned char b = 0xB8;
    unsigned char rs = a | b;
    printf("Bitwise OR of %d and %d is %d\n",a,b,rs);
    showBits(a,1);
    showBits(b,1);
    showBits(rs,1);

    int x = 0x030B1A0F;
    int maskSetBitto1 = 0xFFFF0000; // sets first 4 bytes to 1's and preserves other bits
    showBits(x,4);
    showBits(maskSetBitto1,4);
    showBits(x | maskSetBitto1,4);


}

// encryption C = plaintext^key, then P = ciphertext^key
void bitXOR()
{
    unsigned char a = 0x48;
    unsigned char b = 0xB8;
    unsigned char rs = a ^ b;
    printf("Bitwise XOR of %d and %d is %d\n",a,b,rs);
    showBits(a,1);
    showBits(b,1);
    showBits(rs,1);

    //flip every bit same as NOT
    showBits(a ^ 0xff,1);

    //No change
    showBits(a ^ 0x0,1);
}

void bitNOT()
{
    unsigned char a = 0x48;
    unsigned char rs = ~a;
    printf("Bitwise NOT of %d is %d\n",a,rs);
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
//    printf("shift 1 bit to left in x:\n");
//    showBits(x<<1,2);
//
//    printf("shift 2 bits to right in x:\n");
//    showBits(x>>2,2);
//
//    printf("No shift in z:\n");
//    showBits(z,4);
//    printf("Shift z 30 bits to left:\n");
//    showBits(z<<30,4);
//    printf("Shift z 1 bits to right:\n");
//    showBits(z>>1,4);

//
//    x = -100;
//    printf("No shift in x:\n");
//    showBits(x,2);
//
//    printf("shift 2 bits to right in x:\n");
//    showBits(x>>2,2);

//    unsigned short s = 1;
//    showBits(s,2);
//    for(int i=0;i<5;i++)
//    {
//        s = s<<1;
//        showBits(s,2);
//    }
//
//    s = 1024;
//    showBits(s,2);
//    for(int i=0;i<5;i++)
//    {
//        s = s>>1;
//        showBits(s,2);
//    }

    unsigned char uc = 0b11010011;
    showBits(uc,1);
    unsigned char upper_uc;//00001101
    unsigned char lower_uc;//00000011

}


int main(int argc,char ** argv)
{
    bitSHIFT();
//    bitNOT();
//    bitXOR();
//    bitOR();
//    bitAND();
//    showBits(123444,4);
//    showBits(255,1);
//    showBits(32845,2);
}