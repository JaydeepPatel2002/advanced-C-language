//
// Created by wangxi on 2023-03-24.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "structs.h"
int main(int argc, char ** argv)
{
//    printf("%d\n",sizeof(char*));
//    printf("%d\n",sizeof(BirthDate));

    BirthDate birthDate={
            "Alex",
            'M',
            1,1,2000
    };
//    printf("%d\n",sizeof(birthDate));
    printf("%s\n",birthDate.cName);
    BirthDate b1;
    memcpy(&b1,&birthDate,sizeof(BirthDate));
    printf("%s\n",b1.cName);
    printf("%p\n",&birthDate.cName);
    printf("%p\n",&b1.cName);


//    printf("%d\n",sizeof(BirthDate1));
    BirthDate1 birthDate1={
            "AlexWang",
            'M',
            1,1,2000
    };
    printf("%s\n",birthDate1.cName);

    BirthDate1 b2;
    memcpy(&b2,&birthDate1,sizeof(BirthDate1));
    printf("%s\n",b2.cName);
//    printf("%d\n",sizeof(birthDate1));
//
//    printf("%p\n",&birthDate1);
    printf("%p\n",birthDate1.cName);// 1. It is not in Stack or Heap 2.Mostly it is in .DATA but it is decision of compiler
    printf("%p\n",b2.cName);// 1. It is not in Stack or Heap 2.Mostly it is in .DATA but it is decision of compiler


    char * name = malloc(120);
    sprintf(name,"%s","AlexWang");

    char name1[]="alex";
    BirthDate1 birthDate2={
            name1,
            'M',
            1,1,2000
    };


}
