//
// Created by wangxi on 2023-03-22.
//
#include "funcs.h"
void sortInts(int array[],int size, COMPARTOR comp)
{
    int i,key,j;
    for(int i=1;i<size;i++)
    {
        key = array[i];
        j=i-1;
        while(j>=0 && comp(array[j],key)>0)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void processDoubles(double array[],int size,MYROUNDUP rou,PROCESSIT pro)
{
    for(int i =0;i<size;i++)
    {
        array[i]=rou(array[i]);
        pro(array[i]);
    }
}
