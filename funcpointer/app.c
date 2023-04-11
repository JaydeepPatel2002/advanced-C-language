//
// Created by wangxi on 2023-03-22.
//
#include "funcs.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int compareA(int a,int b)
{
    return a-b;
}


short compareSA(short a,short b)
{
    return a-b;
}

int compareD(int a,int b)
{
    return b-a;
}

double round(double d)
{
    return ceil(d * 100.0)/100.0;
}

void printit(double d)
{
    printf("%f ",d);
}



int main(int argc, char ** argv)
{
    int array[] = {45,56,4,62,23,2};
    int size = sizeof(array)/sizeof(int);
    sortInts(array, size,  compareA);
    for(int i=0;i<size;i++)
    {
        printf("%d ",array[i]);
    }

//    double array[] = {45.324234,56.254235,4.21334223,62.23,23.234232314,2.0};
//    int size = sizeof(array)/sizeof(double );
//    processDoubles(array,size, round, printit);
//    for(int i=0;i<size;i++)
//    {
//        printf("%f ",array[i]);
//    }


}