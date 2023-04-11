//
// Created by wangxi on 2023-01-24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "db.h"
DB_HANDLE open_db(const char * fn)
{
    FILE * f  = NULL;
    int err = EXIT_SUCCESS;

    f=fopen(fn,"ab+");
    if(f==NULL)
    {
        err=errno;
        printf("got error.\n errno=%d\n errmsg=%s\n",err, strerror(err));
    }
    else
    {
        printf("Successed\n");
    }
    return (DB_HANDLE) f;
}
void close_db(DB_HANDLE db)
{
    fclose((FILE*)db);
}

void handle_rw_error(FILE * f)
{
    int err = ferror(f);
    if(err)
    {
        printf("Error %d: %s\n",err, strerror(err));
    }
    else
    {
        printf("Unknown reason caused failed to read file\n");
    }
}

int add(void * data, unsigned size, DB_HANDLE db){
    FILE * f = (FILE*)db;
    fseek(f, 0, SEEK_END);
    //ftell() returns the current file position of the
    // specified stream with respect to the starting of the file
    int loc = ftell(f);
    int bts = fwrite(&size,sizeof(unsigned),1,f);
    if(1== bts )
    {
        //Write the size of the record first
    }
    else handle_rw_error(f);
    bts = fwrite(data,size,1,f);
    if(1==bts)
    {
        fflush(f);
        return loc;
    }
    else handle_rw_error(f);
    return -1;
}
int read(void * buf, unsigned bufsize, DB_HANDLE db, int recid)
{
    FILE * f = (FILE*)db;
    fseek(f, recid, SEEK_SET);
    unsigned recsize = 0;
    int bts = fread(&recsize,sizeof(unsigned),1,f);
    if(1==bts)
    {
        return fread(buf,recsize<bufsize?recsize:bufsize,1,f);
    }
    else handle_rw_error(f);

}