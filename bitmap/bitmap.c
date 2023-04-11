//
// Created by wangxi on 2023-03-29.
//
#include "bitmap.h"
#include <memory.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

FILE * getFile(char * prompt,char * mode)
{
    FILE * file = NULL;
    char fn[256];
    fn[0]='\0';
//    memset(fn,0,256);
    printf("%s",prompt);
    fgets(fn,255,stdin);
    file = fopen(fn,mode);
    return file;
}
//IMAGE * readImage( FILE * f)
//{
//   IMAGE * image = (IMAGE*)malloc(sizeof(IMAGE));
//
//   return image;
//}


void readImage(IMAGE * image, FILE * f)
{
    readHeader(image,f);
    if(image->bmHDR)
        readData(image,f);
}
void readHeader(IMAGE * image, FILE * f){
    BOOL bSuccess=FALSE;
    image->bmHDR=(BITMAPHDR*) malloc((sizeof(BITMAPHDR)));
    if(image->bmHDR){
        if(fread(image->bmHDR,sizeof(BITMAPHDR),1,f)==1)
        {
            bSuccess = TRUE;
        }
    }
    if(!bSuccess && image->bmHDR)
    {
        free(image->bmHDR);
        image->bmHDR=NULL;
        printf("Read header from file failed.");
    }
}
void readData(IMAGE * image, FILE * f){
    BOOL bSuccess = FALSE;
    unsigned int size = 0;
    // 3 pixels in a row
    // 9 bytes for a tow
    //padding 3 bytes so 12 bytes per row
    unsigned int padding = image->bmHDR->dwWidth % 4;
    size = (image->bmHDR->dwWidth*sizeof(PIXEL)+padding)*image->bmHDR->dwHeight;
    image->bmData=(PIXEL*) malloc(size);
    if(image->bmHDR)
    {
        if(fread(image->bmData,size,1,f)==1)
        {
            bSuccess=TRUE;
        }
    }
    if(!bSuccess && image->bmData)
    {
        free(image->bmData);
        image->bmData=NULL;
        printf("Failed to read image data.");
    }
}
void printHeader(IMAGE* image){
    BITMAPHDR * headerPtr = image->bmHDR;
    printf("First two characters: %x\n", headerPtr->wType);
    printf("File size: %d\n", headerPtr->dwFileSize);
    printf("Data offset: %d\n", headerPtr->dwDataOffset);
    printf("Dimensions: %d by %d\n", headerPtr->dwWidth, headerPtr->dwHeight);
    printf("Planes: %d\n", headerPtr->wPlanes);
    printf("Color depth: %d\n", headerPtr->wBitCount);
    printf("Compression: %d\n", headerPtr->dwCompression);
    printf("Image size: %d\n", headerPtr->dwImageSize);
    printf("Colors used: %d\n", headerPtr->dwClrUsed);
}
void freeImage(IMAGE * image){
    free(image->bmHDR);
    image->bmHDR=NULL;
    free(image->bmData);
    image->bmData=NULL;
//    free(image);
}
void writeImage(IMAGE * image, FILE * f){
    writeHeader(image,f);
    writeData(image,f);
}
void writeHeader(IMAGE * image, FILE * f){
    if(fwrite(image->bmHDR,sizeof(BITMAPHDR),1,f)!=1)
    {
        printf("Failed to write image header");
    }
}
void writeData(IMAGE * image, FILE * f){
    unsigned int size,padding;
    padding = image->bmHDR->dwWidth % 4;
    size = (image->bmHDR->dwWidth*sizeof(PIXEL)+padding)*image->bmHDR->dwHeight;
    if (fwrite(image->bmData,size,1,f)!=1)
    {
        printf("Failed to write image data");
    }
}

PIXEL * getPixel(unsigned int row, unsigned int col, IMAGE * image)
{
    unsigned int padding = image->bmHDR->dwWidth % 4;
    unsigned int offset =
            (image->bmHDR->dwWidth*sizeof(PIXEL)+padding)*row+
            col* sizeof(PIXEL);
    return (PIXEL*)(((BYTE*)image->bmData)+offset);
}

void processImage(IMAGE * image,BMP_FUN_PTR_ONE func)
{
    for(unsigned  int i = 0;i<image->bmHDR->dwHeight;i++)
        for(unsigned int j=0;j<image->bmHDR->dwWidth;j++)
            func(getPixel(i,j,image));
}
#define MIN(a,b) a<b?a:b
void processTwoImages(IMAGE* image1, IMAGE* image2, BMP_FUN_PTR_TWO func)
{
    unsigned int height = MIN(image1->bmHDR->dwHeight,
                              image2->bmHDR->dwHeight);
    unsigned int width = MIN(image1->bmHDR->dwWidth,
                             image2->bmHDR->dwWidth);
    for(unsigned  int i = 0;i<height;i++)
        for(unsigned int j=0;j<width;j++)
            func(getPixel(i,j,image1),
                 getPixel(i,j,image2));
}


