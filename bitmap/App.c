//
// Created by wangxi on 2023-03-29.
//

#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"
void grayscaleAvg(PIXEL * p)
{
    BYTE gray = (p->bBlu+p->bGrn+p->bRed)/3;
    p->bGrn=gray;
    p->bRed=gray;
    p->bBlu=gray;
}

void grayscaleFormula(PIXEL* p)
{
    BYTE gray = (0.11*p->bBlu+0.59*p->bGrn+0.30*p->bRed);
    p->bGrn=gray;
    p->bRed=gray;
    p->bBlu=gray;
}

void nagative(PIXEL * p)
{
    p->bBlu=255-p->bBlu;
    p->bRed=~p->bRed;
    p->bGrn=~p->bGrn;
}

void swap(PIXEL * p){
    p->bBlu=(p->bBlu<<4)|(p->bBlu>>4);
    p->bRed=(p->bRed<<4)|(p->bRed>>4);
    p->bGrn=(p->bGrn<<4)|(p->bGrn>>4);
}

void blend(PIXEL * p1, PIXEL * p2)
{
    p1->bGrn=p1->bGrn/2+p2->bGrn/2;
    p1->bRed=p1->bRed/2+p2->bRed/2;
    p1->bBlu=p1->bBlu/2+p2->bBlu/2;
}

void mix(PIXEL * p1, PIXEL * p2){
    p1->bBlu=(p1->bBlu & 0XF0) | (p2->bBlu >> 4);
    p1->bRed=(p1->bRed & 0XF0) | (p2->bRed >> 4);
    p1->bGrn=(p1->bGrn & 0XF0) | (p2->bGrn >> 4);

}

int main(int argc, char ** argv) {
    FILE * in = fopen("bike.bmp","rb");
    FILE * in2 = fopen("face.bmp","rb");
    FILE * out = fopen("bikeface.bmp","wb");
    IMAGE * image = (IMAGE*)malloc(sizeof(IMAGE));
    readImage(image,in);
    printHeader(image);
    IMAGE * image2 = (IMAGE*)malloc(sizeof(IMAGE));
    readImage(image2,in2);
    printHeader(image2);

//    processTwoImages(image,image2,mix);
    processImage(image,swap);
    writeImage(image,out);
    freeImage(image);
    free(image);
    fclose(in);
    fclose(out);
}
