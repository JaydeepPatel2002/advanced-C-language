//
// Created by wangxi on 2023-01-06.
//
#include <stdio.h>
#include "pingpong.h"
#include "autopingpong.h"
void autoping()
{
    ping();
    autopong();
}
//int count = 0;//global var WE DO OUR BEST TO AVOID USING GLOBAL VAR
void autopong()
{
    static int count =0;//Static var only available in the func
    count++;
    printf("%d",count);
    pong();
    if(count<10) autoping();
}
