//
// Created by wangxi on 2023-03-24.
//
#include "math.h"
#include "stdio.h"
#include "mathfunc.h"
double average(double data[],int size)
{
    double sum = 0.0;
    for(int i=0;i<size;i++) sum+=data[i];
    return sum/size;
}

double stDev(double data[],int size)
{
    double  avg = average(data,size);
    double sum = 0;
    for(int i=0;i<size;i++) sum+=square(data[i]-avg);
    return sqrt(sum/(size-1));
}

double square(double num)
{
    return num*num;
}

char * format(char * buf,double num)
{
    sprintf(buf,"%-10.21f",num);
    return  buf;
}

