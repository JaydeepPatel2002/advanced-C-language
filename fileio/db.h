//
// Created by wangxi on 2023-01-24.
//

#ifndef CODE_DB_H
#define CODE_DB_H
#define DB_HANDLE void *
DB_HANDLE open_db(const char * fn);
void close_db(DB_HANDLE db);
int add(void * data, unsigned size, DB_HANDLE db);
int read(void * buf, unsigned bufsize, DB_HANDLE db, int recid);

#endif //CODE_DB_H
