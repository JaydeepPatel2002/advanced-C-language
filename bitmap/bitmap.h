//
// Created by wangxi on 2023-03-29.
//

#ifndef CODE_BITMAP_H
#define CODE_BITMAP_H
#include <stdio.h>
#define BOOL unsigned char
#define TRUE 1
#define FALSE 0

#define BYTE unsigned char
#define WORD unsigned short
#define DWORD unsigned int

#define PI 3.1415926535897932384626433832

#pragma pack(push) // Used to store the default byte alignment
#pragma pack(1) // Set the byte alignment to 1

typedef struct _bitmap_header
{
    WORD wType;
    DWORD dwFileSize;
    WORD wReserved1;
    WORD wReserved2;
    DWORD dwDataOffset;
    DWORD dwHeaderSize;
    DWORD dwWidth;
    DWORD dwHeight;
    WORD wPlanes;
    WORD wBitCount;
    DWORD dwCompression;
    DWORD dwImageSize;
    DWORD dwXPelsPerMeter;
    DWORD dwYPelsPerMeter;
    DWORD dwClrUsed;
    DWORD dwClrImportant;
} BITMAPHDR;

typedef struct _pixel
{
    // Strangely, blue comes first in the pixel...
    BYTE bBlu, bGrn, bRed;
} PIXEL;

// A struct that represents the entire image
typedef struct _image
{
    BITMAPHDR* bmHDR;
    PIXEL* bmData;
} IMAGE;

#pragma pack(pop) // Used to reset the default byte alignment

FILE * getFile(char * prompt,char * mode);
void readImage(IMAGE * image, FILE * f);
void readHeader(IMAGE * image, FILE * f);
void readData(IMAGE * image, FILE * f);
void printHeader(IMAGE* image);
void freeImage(IMAGE * image);
void writeImage(IMAGE * image, FILE * f);
void writeHeader(IMAGE * image, FILE * f);
void writeData(IMAGE * image, FILE * f);

typedef void(*BMP_FUN_PTR_ONE)(PIXEL*);
typedef void(*BMP_FUN_PTR_TWO)(PIXEL*,PIXEL*);
void processTwoImages(IMAGE* image1, IMAGE* image2, BMP_FUN_PTR_TWO func);
void processImage(IMAGE * image,BMP_FUN_PTR_ONE func);
PIXEL * getPixel(unsigned int row, unsigned int col, IMAGE * image);

#endif //CODE_BITMAP_H
