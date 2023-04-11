//
// Created by wangxi on 2023-01-11.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readString(char * cPtr, char * cLengthPtr);//Forward declaration
void readStringEx(char * cPtr, int len);
void readNumbers(int * nPtr,int nSize);
void printNumbers(int * nPtr,int nSize);
char * readString1();
int main(int argc, const char * argv[])
{
    int nRs =0;
    char cArray[10];
    char * cPtr0 = cArray;
//    char * cPtr = &cArray[1];
//    char * cPtr1 = &cArray[0];
//    cPtr1++;
//    unsigned int temp = 0xffffffff;
//    temp = 0b1111111111111111111111111111;
//    printf("%ud\n",temp);
//    nRs = scanf("%9s",cArray);
////    nRs= scanf_s("%s",cArray, strlen(cArray));?
//    printf("%s\n",cArray);
//    printf("%ud\n",temp);
//    readStringEx(cPtr0,5);
//    printf("%s\n",cArray);
//    //Convert an int to string
//    sprintf(cArray,"%d",10);
//    sprintf(cArray,"%3.1f",3.14159);
//    //Convert a string to int
//    nRs=atoi("1234");
    //atol atof

//    int nArray[4];
//    readNumbers(nArray,4);
//    printNumbers(nArray,4);
//    printf("Please enter a string and a number(Str(num)):");
//    int a,b;
//    scanf("%d+%d=%d",&nRs,&a,&b);
//    printf("%d+%d=%d",nRs,a,b);

    cArray[0]='\0';
//    do {
//        printf("%s\n",cArray);
//    }while(scanf("%s",cArray));

//    do {
//        printf("%s\n",cArray);
//    }while(gets(cArray));
      //cArray = readString1();
      //cArray is a var always point to a array of chars
      //You can not point cArray to anywhere else after the alloc
      //cPtr0 is a point to a char mem block
      //It can point to cArray or anywhere in the memory(Stack or heap)
//      cPtr0 = readString1();
//        printf("2.Got %s\n",cPtr0);
//      //You can copy string to cArray char by char using strcpy
//      strcpy(cArray,cPtr0);
//        printf("3.Got %s\n",cArray);

        //Write a small application
        //Ask user enter an amount number<10
        //Then ask user enter the amount of number and same them in a int array
        //If user enter "e", exit the loop early
        //Print out the sum/avg/min/max values in the array.
        //2:40
        int naVals[10];
        int nNums2Enter=0;
        int nNumsEntered=0;
        while(nNums2Enter==0)
        {
            printf("Please enter how many num do you plan to enter:");
            scanf("%d",&nNums2Enter);
            if(nNums2Enter<1 || nNums2Enter>10) nNums2Enter=0;
        }
        while(nNumsEntered<nNums2Enter)
        {
            printf("Please enter a num:");
            char sTemp[20];
            scanf("%s",sTemp);
            if(sTemp[0]=='e') break;
            naVals[nNumsEntered++]=atoi(sTemp);
        }
        if(nNumsEntered>0)
        {
            int sum=0;
            int min=naVals[0];
            int max=naVals[1];
            for(int i=0;i<nNumsEntered;i++)
            {
                sum+=naVals[i];
                if(naVals[i]<min) min=naVals[i];
                if(naVals[i]>max) max=naVals[i];
            }
            printf("Sum: %d Avg: %3.3f Min: %d Max %d\n",
                   sum,(double)sum/(double)nNumsEntered,
                   min,max);
        }
        else
            printf("You did not enter any numbers");
}

char * readString1()
{
    //char buf[10]; It will not work becasue the buf is in local stack
    //It will be freed after the func is exited along with the local stack
    char * buf= malloc(10);
    gets(buf);
    printf("1.Got %s\n",buf);
    return buf;//Never return the memory in stack
}

void readNumbers(int * nPtr,int nSize)
{
    printf("Enter %d numbers:",nSize);
    while(scanf("%d",nPtr++) && --nSize);
//    {
//        nPtr++;
//    }
}
void printNumbers(int * nPtr,int nSize)
{
    for(int i=0;i<nSize;i++)
    {
        printf("%d\n",nPtr[i]);
    }
}


void readStringEx(char * cPtr, int len)
{
    char cFmt[4];//Allocate a string
    //Init string
    cFmt[0]='\0';
    sprintf(cFmt,"%%%ds",len);//%4s
    printf("Enter a string:");
    scanf(cFmt,cPtr);
}


void readString(char * cPtr, char * cLengthPtr)
{
    char cFmt[4];//Allocate a string
    //Init string
    cFmt[0]='\0';
//    strcat(cFmt,"%");
//    strcat(cFmt,cLengthPtr);
//    strcat(cFmt,"s");
    sprintf(cFmt,"%%%ss",cLengthPtr);
    printf("Enter a string:");
    scanf(cFmt,cPtr);
}