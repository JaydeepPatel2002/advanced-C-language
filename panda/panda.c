//
// Created by XIN Wang on 2023-01-13.
//
#include <stdio.h>
#include <string.h>
#include "panda.h"

void printIntArray(int nArray[],int nSize)
{
    //In c there is not length information attached to an array
    printf("The address stored in printIntArray in the function is \t%p\n", nArray);
    printf("The address of printIntArray in the function is \t%p\n", &nArray);

    for(int i=0;i<nSize;i++)
        printf("The loop counter is %d and the array value is %d"
               " and the value's address is is %p\n", i, nArray[i], &nArray[i]);
}

void printIntPointer(int * nPtr,int nSize)
{
    printf("The address stored in printIntPointer in the function is \t%p\n", nPtr);
    printf("The address of printIntPointer in the function is \t%p\n", &nPtr);

    //* is dereference op which will return the value of the point pointing to
    //Increase ++ op to a point will increase the address of the point based on the data type of the pointer
    for(int i=0;i<nSize;i++)
//        printf("The loop counter is %d and the array value is %d and the value's address is is %p\n", i, nPtr[i], &nPtr[i]);
        printf("The loop counter is %d and the array value is %d and the value's address is is %p\n", i, *nPtr++, nPtr);//++ must right after the deref op
//    printf("The loop counter is %d and the array value is %d and the value's address is is %p\n", i, *(nPtr+i), nPtr+i);

}

void printStringasCharArray(char cArray[])
{
    //Assume we know it is string
//    char[] foo = "alex";
//    foo[4]='k'; //foo is not string anymore it is an arr of char which has a l e x k
    for(int i=0;i<strlen(cArray);i++) printf("%c",cArray[i]);
    for(int i=0; cArray[i]!='\0';i++) printf("%c",cArray[i]);

}

void printStringasPointer(char* cPtr)
{
    while(*cPtr!='\0')printf("%c",*cPtr++);
}

void printBytesOfInt(int n)
{
    char * s = (char*)&n;//s is not string becuase (char*) willnot force last byte be 0
    for(int i=0;i<sizeof(n);i++)printf("%x",*(s+i));

}
#define NAME_SIZE 5
#define AGE_SIZE 1

double encode()
{
    double x = 0.0;
    char * cPtr = (char*)&x;
    printf("Please enter the first 3 letter of your name:");
    scanf("%5s",cPtr);
    printf("Please enter your age<128:");
    scanf("%d",(int*)(cPtr+NAME_SIZE));
    printf("Please enter your student loan:");
    scanf("%hu",(short *)(cPtr+NAME_SIZE+AGE_SIZE));

    return x;
}

void decode(double x)
{
    char * cPtr = (char*)&x;
    unsigned char age = *(unsigned char*)(cPtr+NAME_SIZE);
    *(cPtr+NAME_SIZE)='\0';
    short loan = *(short *)(cPtr+NAME_SIZE+AGE_SIZE);
    printf("%s %d %d",cPtr,(int)age,loan);
}