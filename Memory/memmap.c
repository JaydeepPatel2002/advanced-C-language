//
// Created by wangxi on 2023-01-06.
//
#include <stdio.h>
#include "memory.h"
int memoryMap(float x)
{
    static int i = 0;
    int a = 1235257896;
    double d = 9.0;
    float b = 3.2f;
    char c = 'a';
    short s = 10815;
    char cArray[] = "Hello";

    // Print the address of each variable
    // The "Address Of" operator is the overloaded &
    // Note that %p is used for printing addresses in hexadecimal
    printf("Sizes are: int: %d long %d short %d char %d float %d double %d\n",sizeof(int),sizeof(long),sizeof(short),sizeof(char),sizeof(float),sizeof(double));
    printf("The address of int i is \t%p\n", &i);
    printf("The address of int a is \t%p\n", &a);
    printf("The value of int a in hex is\t%x\n", a);
    printf("The value of a as a char is \t%c\n", a);

    printf("The address of double d is \t%p\n", &d);
    printf("The value of double d in hex is\t%llx\n", d);
    printf("The address of float b is \t%p\n", &b);
    printf("The value of float b in hex is\t%x\n", b);
    printf("The address of char c is \t%p\n", &c);
    printf("The value of c in hex is \t%x\n", c);
    printf("The address of short s is \t%p\n", &s);
    printf("The value of s in hex is \t%x\n", s);
    printf("The value of s as a char is \t%c\n", s);

    // Note that the name of an array IS its address. & is not required.
    printf("The address of cArray is \t%p\n", cArray);

    // Address of the parameter
    printf("The address of float x is \t%p\n", &x);

    // Print the address of the function itself.
    // Note that the name of the function stores its address.
    printf("The address of memoryMap is \t%p\n", memoryMap);
}

