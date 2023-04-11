//
// Created by wangxi on 2023-01-04.
//
#include <stdio.h>
#include "pingpong.h"
#include "autopingpong.h"
int main(int argc, const char * argv[])
{
    printf("Hello world in header!\n");
    ping();
    pong();
    printf("Now Auto!\n");
    autoping();
}