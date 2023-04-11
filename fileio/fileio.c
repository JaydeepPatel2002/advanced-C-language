//
// Created by wangxi on 2023-01-18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "fileio.h"

int demoOpenClose(const char * filename, const char * mode)
{
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;

    f=fopen(filename,mode);
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        printf("Successed\n");
        fclose(f);
    }
}

int demofgets(const char * fn, const char * mode)
{
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;
    char cbuf[MAX_SIZE];
    char * pbuf=cbuf;

    f=fopen(fn,mode);
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        memset(cbuf,'\0',MAX_SIZE);
        char * rs=NULL;
        do {
            rs = fgets(pbuf,MAX_SIZE,f);
            if(!rs) break;
            pbuf+=strlen(rs);
        }while(pbuf-cbuf<MAX_SIZE && rs);
        printf(cbuf);
        fclose(f);
    }
}

int demofgetc(const char * fn, const char * mode)
{
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;
    char cbuf[MAX_SIZE];
    char * pbuf=cbuf;
    f=fopen(fn,mode);
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        memset(cbuf,'\0',MAX_SIZE);
        char c;
        do {
               c = fgetc(f);
               if(feof(f)) break;
                *(pbuf++)=c;
        }while(pbuf-cbuf<MAX_SIZE);
        printf(cbuf);
        fclose(f);
    }
}


int demoReadTextFile(const char * fn, const char * mode)
{
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;
    char cbuf[MAX_SIZE];
    char cbuf1[MAX_SIZE];
    f=fopen(fn,mode);
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        memset(cbuf,'\0',MAX_SIZE);
        memset(cbuf1,'\0',MAX_SIZE);
        int rs = 0;
        //1. fscanf return how many data (%s %d..) returned
        rs= fscanf(f,"%s %s",cbuf,cbuf1);
        //2. fgets return a line of the text file. It returns the buf of line.
        //If it return NULL, it means failed read
         //char * crs  = fgets(cbuf,MAX_SIZE,f);
         //crs = fgets(cbuf1,MAX_SIZE,f);
        if(rs>0)
        //if(crs)
        {
            printf("%d\n",rs);
            printf("%s\n",cbuf);
            printf("%s\n",cbuf1);

        } else{
            err = ferror(f);
            if(err)
            {
                printf("Error %d: %s\n",err, strerror(err));
            }
            else
            {
                printf("Unknown reason caused failed to read file\n");
            }
        }

        fclose(f);
    }
}

//Mode
//        Description
//r
//        Open a text file for reading. The file must exist.
//w
//        Create a text file for writing. If the given file exists, its contents are destroyed unless it is a logical file.
//a
//        Open a text file in append mode for writing at the end of the file. The fopen() function creates the file if it does not exist and is not a logical file.
//r+
//Open a text file for both reading and writing. The file must exist.
//w+
//Create a text file for both reading and writing. If the given file exists, its contents are cleared unless it is a logical file.
//a+
//Open a text file in append mode for reading or updating at the end of the file. The fopen() function creates the file if it does not exist.
//rb
//        Open a binary file for reading. The file must exist.
//wb
//        Create an empty binary file for writing. If the file exists, its contents are cleared unless it is a logical file.
//ab
//        Open a binary file in append mode for writing at the end of the file. The fopen function creates the file if it does not exist.
//r+b or rb+
//Open a binary file for both reading and writing. The file must exist.
//w+b or wb+
//Create an empty binary file for both reading and writing. If the file exists, its contents will be cleared unless it is a logical file.
//a+b or ab+
//Open a binary file in append mode for writing at the end of the file. The fopen() function creates the file if it does not exist.
void fileioerrorhandler(FILE * f)
{
    int err = ferror(f);
    if(err)
    {
        printf("Error %d: %s\n",err, strerror(err));
    }
    else
    {
        printf("Unknown reason caused failed to read/write file\n");
    }

}


int demoBinWrite(const char * fn)
{
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;
    f=fopen(fn,"wb");
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        int rs = 0;
        int n = 100;
        rs = fwrite(&n,sizeof(int),1,f);
        //fwrite return total records writen, NOT BYTES
        if(rs!=1) fileioerrorhandler(f);
        float d = 3.14;
        rs = fwrite(&d,sizeof(float ),1,f);
        int narray[] = {1,2,3,4,5,6,7,8};
        n = 8;
        //Before write the array write array size first
        rs = fwrite(&n,sizeof(int),1,f);
        rs = fwrite(narray,sizeof(int), 8,f);
//        char * name = "alex";
        char name[] = "alex";
        rs = fwrite(name,sizeof(char), strlen(name),f);
        fclose(f);
        return rs;
    }
}



int demoBinRead(const char * fn)
{
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;
    f=fopen(fn,"rb");
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        int rs = 0;
        int n = 0;
        rs = fread(&n,sizeof(int),1,f);
        // fread return The total number of elements successfully read is returned. Not BYTES!
        if(rs!=1) fileioerrorhandler(f);
        printf("%d\n",n);
        float d = 0;
        rs = fread(&d,sizeof(float ),1,f);
        if(rs!=1) fileioerrorhandler(f);
        printf("%f\n",d);

//        int narray[] = {0,0,0,0,0,0,0,0};
//        rs = fread(narray,sizeof(int), 8,f);

        //Read the array size
        rs = fread(&n,sizeof(int),1,f);
        int * narray = malloc(sizeof(int)*n);
        rs = fread(narray,sizeof(int), n,f);


        for(int i=0;i<8;i++) printf("%d ",narray[i]);
        printf("\n");
        char name[] = "DDDD";
        rs = fread(name,sizeof(char), 4,f);
        printf(name);
        fclose(f);
        return rs;
    }
}




int demoWriteTextPrintf(const char * fn, const char * mode, const char * str)
{
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;
    f=fopen(fn,mode);
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        int rs = 0;
        //fprintf will return the bytes write in
        rs = fprintf(f,"%s",str);
        if(rs==strlen(str))
        {
            printf("%d\n",rs);

        } else{
            err = ferror(f);
            if(err)
            {
                printf("Error %d: %s\n",err, strerror(err));
            }
            else
            {
                printf("Unknown reason caused failed to read file\n");
            }
        }
        fclose(f);
    }
}

int demoWriteTextfputs(const char * fn, const char * mode, const char * str)
{
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;
    f=fopen(fn,mode);
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        int rs = 0;
        //fputs will return the bytes write in
        rs = fputs(str,f);
        if(rs==strlen(str))
        {
            printf("%d\n",rs);

        } else{
            err = ferror(f);
            if(err)
            {
                printf("Error %d: %s\n",err, strerror(err));
            }
            else
            {
                printf("Unknown reason caused failed to read file\n");
            }
        }
        fclose(f);
    }
}

int demoWriteTextfputc(const char * fn, const char * mode, const char * str)
{
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;
    f=fopen(fn,mode);
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        while(*str && fputc(*str,f)==*str);
            str++;
        fclose(f);
    }
}

int execisefputs(const char * fn, const char * mode, const char * str)
{
    //Write str into fn but each letter should transform like:
    //a->z b->y ...
    //Assume str only contains lower case letter
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;
    f=fopen(fn,mode);
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        //while(*str && fputc(*str,f)==*str);
        int ch;
        while((ch=*str)!='\0')
        {
            ch = 'z'-(ch-'a');
            fputc(ch,f);
            str++;
        }
        fclose(f);
    }


}


void ExerciseBinWrite(const char * fn)
{
    //LEt user enter name,age,student loan and save them into fn as "wb"
}

void ExerciseBinRead(const char * fn)
{
    //Print all data your write
}

