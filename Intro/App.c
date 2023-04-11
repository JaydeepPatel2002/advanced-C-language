//
// Created by wangxi on 2023-01-04.
// This is single line comment
/*
 * Multiline comment
 *
 */

// import another lib use #include
//"" will look for you lib from your project folder first
//<> will look for your lib from the C compiler lib folder only
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//CONSTANT
#define PI 3.14259
#define TRUE 1
#define FALSE 0

//Data type
typedef int bool;
void primitiveTypes()
{
    char c = 'A';
    int x = 234324;
    float f = PI;
    double d = 1234.23123;
    bool b = TRUE;

    printf("the value of c is %c\n",c);
    printf("the value of c as an int is %d\n",c);
    printf("the value of x is %d\n",x);
    printf("the value of x as char is %c\n",x);
    printf("the value of x as HEX is %x\n",x);

    printf("the value of f is %f\n",f);
    printf("the value of d is %10.2f\n",d);

    printf("the size of a char is %d\n",sizeof(c));
    printf("the size of a int is %d\n",sizeof(int));
    printf("the size of a int is %d\n",sizeof(x));
    printf("the size of a float is %d\n",sizeof(f));
    printf("the size of a double is %d\n",sizeof(d));

}

void modifiers()
{
    //IN c, char is from -127-127
    unsigned char uc = 255;//unsigned char 0-255
    char c = 127;//Sign char -127-127
    //signed char cc = 127;
    char cc = 255;
    //11111111 signed -127 unsigned 255
    //01111111 signed 127 unsigned 127

    int x = 1234;
    unsigned int xx = 1234;

    short int s = 123;
    short ss = 123;//short is 2 bytes
    long int l = 345;
    long ll = 345;//long could be 8 bytes but not guaranteed.
    //WHat is guaranteed is long>=int>=short;

    int y  = 0;
    y++;
    y+=1;
    y--;
}

void cast()
{
    int x;//Uninit val will be filled with random value
    float y = 3.2f;
    double yy = 3.6f;
    float fahr = 115;//Cast from smaller num to bigger is auto
    float clec = 0;
    x = yy;
    printf("the value of x is %d\n",x);
    printf("the value of y is %f\n",y);
    printf("the value of fahr is %f\n",fahr);

    clec=((float)5/9)*(fahr-32);
    printf("the value of clec is %f\n",clec);
}

void constant()
{
    const float pi = 3.14159;

}

void string()
{
    char c = 'a';
    char s[]="Alex";
//    char t[];//This does not work
//    t="Alex";//this does not work
    char t[]="";//-->char c=0;
    printf("The value of s is %s\n",s);
    s[0]=c;
    s[strlen(s)-1]='X';
    printf("The value of s is %s\n",s);
    printf("Size of=%d len=%d\n",sizeof(s),strlen(s));


    //PLEASE NEVER DO THIS
    //WE ARE writing data the the memory which is not belong to us
    //C is so flex to allow us to do
    //This is very risky
    s[strlen(s)]=':';
    printf("The value of s is %s\n",s);
    s[5]='\0';
    printf("The value of s is %s\n",s);
}

void boolDemo()
{
    int a = 3;
    int i;
    char s[10]="test";
    printf("%d\n", a>3);
    printf("%d\n", a<=3);
    if(a<=3)
        printf("%d\n", a<=3);
    if(a>3)
        printf("%d\n", a>3);
    if(a)//if(a!=0)
    {
        printf("%d\n",a);
    }
    printf("Will I be printed?\n");
    if(i)
    {
        printf("i=%d\n",i);
    }
//    for(int j=0;j<strlen(s);j++)
//    {
//        s[j]=s[j]+10;
//    }
//    printf(s);
    for(int j=0;s[j]/*!=0*/;j++)
    {
        printf("%c(%d)\n",s[j],j);
    }
}

int main(int argc, const char * argv[])
{
//    primitiveTypes();
//    modifiers();
//    cast();
//    string();
    boolDemo();
}