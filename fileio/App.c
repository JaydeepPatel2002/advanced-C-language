//
// Created by wangxi on 2023-01-18.
//
#include "fileio.h"
#include "db.h"
#include <string.h>
#include <stdio.h>
int gen_rec(const char * name, int age,float loan, void * buf, int bufsize)
{
    char * cbuf = (char*)buf;
    char * cur_buf = cbuf;
    if(bufsize<strlen(name)+sizeof(int)+sizeof(float)+sizeof(int)) return -1;
    int str_len = strlen(name);
    memcpy(cur_buf,&str_len,sizeof(int));//Copy the size of str in bytes
    cur_buf+=sizeof(int);
    memcpy(cur_buf,name, str_len); //Copy the string
    cur_buf+= str_len;
    memcpy(cur_buf,&age,sizeof(int)); //Copy the age
    cur_buf+= sizeof(int );
    memcpy(cur_buf,&loan,sizeof(float)); //Copy the loan
    cur_buf+= sizeof(float );
    return  cur_buf-cbuf;
}

int degen_rec(char * name, int * age,float * loan, void * buf, int bufsize)
{
    char * cbuf = (char*)buf;
    char * cur_buf = cbuf;
    if(bufsize<strlen(name)+sizeof(int)+sizeof(float)+sizeof(int)) return -1;
    int str_len =0;
    memcpy(&str_len,cur_buf,sizeof(int));
    cur_buf+=sizeof(int);
    memcpy(name,cur_buf,str_len);
    name[str_len]=0;//Make it into null str
    cur_buf+=str_len;
    memcpy(age,cur_buf,sizeof(int));
    cur_buf+=sizeof(int);
    memcpy(loan,cur_buf,sizeof(float ));
    cur_buf+= sizeof(float );
    return  cur_buf-cbuf;
}

int main(int argc, const char * argv[]) {
    //demoOpenClose("CMakeCache.txt","r");
    //demoReadTextFile("..\\fileio\\foo.txt","r");
    //demofgetc("..\\fileio\\foo.txt","r");
    //demofgets("..\\fileio\\foo.txt","r");
    //demoWriteTextPrintf("..\\fileio\\foo1.txt","w","Alex");
    //demoWriteTextfputs("..\\fileio\\foo1.txt","w","Sask Polytech");
    //demoWriteTextfputc("..\\fileio\\foo1.txt","w","CST");
    //execisefputs("..\\fileio\\foo1.txt","w","alex");
    demoBinWrite("..\\fileio\\goo.bin");
    demoBinRead("..\\fileio\\goo.bin");
//    ExerciseBinWrite("..\\fileio\\foo.bin");
//    ExerciseBinWrite("..\\fileio\\foo.bin");

//    DB_HANDLE db = open_db("db.bin");
//
//    char buf[256];
//    int rec_size = gen_rec("Alex",19,1000.0,buf,256);
//    int rec_id = add(buf,rec_size,db);
//    memset(buf,0,256);
//
//    rec_size= read(buf,256,db,rec_id);
//    char name[]="     ";
//    int age = 0;
//    float loan = 0.0;
//    degen_rec(name,&age,&loan,buf,256);
//    printf("%s %d %f",name,age,loan);
//    close_db(db);
//

}