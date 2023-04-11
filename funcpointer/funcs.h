//
// Created by wangxi on 2023-03-22.
//

#ifndef CODE_FUNCS_H
#define CODE_FUNCS_H

typedef  int (*COMPARTOR)(int ,int );
typedef double(*MYROUNDUP)(double );
typedef void(*PROCESSIT)(double );

void sortInts(int array[],int size, COMPARTOR comp);
void processDoubles(double array[],int size,MYROUNDUP rou,PROCESSIT pro);
double round(double d);
void printit(double d);

#endif //CODE_FUNCS_H
