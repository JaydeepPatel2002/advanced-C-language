//
// Created by wangxi on 2023-02-01.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dma.h"
void printInts(int * ptr, int size)
{
    printf("The ints are: ");
    while(size-->0) printf("%d ",*(ptr++));

    printf("\n");
}

int * getInts(int size)
{
    int * mem = (int*) malloc(sizeof(int)*size);
    int i = 0;
//    while (size-->0)
//    {
//        printf("Enter a num:");
//        scanf("%d",mem+(i++));
//    }

    while (size>0)
    {
        size--;
        printf("Enter a num:");
        scanf("%d",mem+i);
        i++;
    }
    return mem;
}
//merge left and right
//size of left is sizes[0];
//size of right is sizes[1];
int * addInts(int * left, int * right,int * sizes)
{
    int * rs = (int*) malloc(sizeof(int)*(sizes[0]+sizes[1]));
//    int * rs = (int*) malloc(sizeof(int)*(*sizes+*(sizes+1)));
    memcpy(rs,left,sizeof(int)*sizes[0]);
    memcpy(rs+sizes[0],right,sizeof(int)*sizes[1]);
    return rs;
}


//int * addIntsv2(int * arrays[],int * sizes)
int * addIntsv2(INT_PTR arrays[],int * sizes)
{
    return addInts(arrays[0],arrays[1],sizes);
}

//int * addIntsv3(int ** arrays,int * sizes)
int * addIntsv3(INT_PTR * arrays,int * sizes)
{
    return addIntsv2(arrays,sizes);
}

int totalsize( INT_PTR sizes,int count)
{
    int total = 0;
    while(count-->0)total+=*(sizes++);
    return total;
}

int * addIntsv4(INT_PTR * arrays,INT_PTR sizes,int arraycount)
{
    INT_PTR rs = (INT_PTR) malloc(sizeof(int)* totalsize(sizes,arraycount));
    INT_PTR cur = rs;
    INT_PTR right = NULL;
    for(int i=0;i<arraycount;i++)
    {
        right = arrays[i];
        memcpy(cur,right,sizeof(int)*(sizes[i]));
        cur+=sizes[i];
    }
    return rs;
}
#define  MAX_STR_SIZE 500
char * getStringDMA(const char * msg)
{
    char * cTempPtr = (char*) malloc((MAX_STR_SIZE+1)*sizeof(char));
    char * cRs = NULL;
    if(cTempPtr)
    {
        printf("%s",msg);
        fgets(cTempPtr,MAX_STR_SIZE,stdin);
        //gets(cTempPtr);
        //Remove the \n at the end of string
        cTempPtr[strlen(cTempPtr)-1]='\0';
        cRs = (char*) malloc((strlen(cTempPtr)+1)*sizeof(char));
        if(cRs)
        {
            strcpy(cRs,cTempPtr);
            //The following two lines are doing the same work as the line above
//            memcpy(cRs,cTempPtr, strlen(cTempPtr));
//            cRs[strlen(cTempPtr)]='\0';
        }
    }
    free(cTempPtr);
    return cRs;
}

char * concat(const char * left, const char * right)
{
    int leftLen = strlen(left);
    int rightLen = strlen(right);
    char * rs = (char*) malloc((leftLen+rightLen+1)*sizeof(char));
    rs[0]='\0';
    stpcpy(rs,left);
    stpcpy(rs+leftLen,right);
    return rs;
}
//Try to enhance this func
// We alloc mem every char
//Can we alloc mem every 10 chars?
char * getStringDMANoLimit(const char * msg)
{
    char ch = 0;
    printf(msg);
    char * sRs = (char*) malloc(sizeof(char)*1);
    char * sTemp = sRs;
    int nLen = 0;
    sRs[0]='\0';
    while((ch=fgetc(stdin))!='\n')
    {
        nLen++;
        sRs = (char*) malloc(sizeof(char)* (nLen+1));
        strcpy(sRs,sTemp);
        free(sTemp);
        sTemp=sRs;
        sRs[nLen-1]=ch;
        sRs[nLen] = '\0';
    }

    return sRs;

}

#define MAX_NAME_SIZE 30
char * getNameandSIN()
{
    //35 bytes memory - 0-29 names 30 \0 31-34 int
    char * rs= (char*) malloc(sizeof(char)*MAX_NAME_SIZE+1+sizeof(int));
    printf("Please enter a name:");
    fgets(rs,MAX_NAME_SIZE,stdin);
    int nNameLen = strlen(rs);
    if(rs[nNameLen-1]=='\n') rs[nNameLen-1]='\0';
    printf("Enter a SIN:");
    scanf("%d",rs+MAX_NAME_SIZE+1);
    return rs;
}

void printNameandSIN(char * str)
{
    printf("Name: %s\n",str);
    printf("SIN: %d",*((int*)(str+MAX_NAME_SIZE+1)));
}
