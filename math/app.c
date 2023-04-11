//
// Created by wangxi on 2023-03-24.
//
#include "mathfunc.h"
#include <stdio.h>
int main(int argc, char ** argv)
{
    double data[]={12.1,13.6,12.4,10.9,100.1};
    int size = sizeof(data)/sizeof(double );
    double avg,dev;
    avg= average(data,size);
    dev = stDev(data,size);
    char buf[200];
    buf[0]='\0';
    format(buf,avg);
    printf("Average is %s\n", buf);
    printf("St. Dev. is %s\n", format(buf,dev));
}