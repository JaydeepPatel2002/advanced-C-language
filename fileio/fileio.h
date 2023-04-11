//
// Created by wangxi on 2023-01-18.
//

#ifndef CODE_FILEIO_H
#define CODE_FILEIO_H
#define MAX_SIZE 1024
int demoOpenClose(const char * filename, const char * mode);
int demoReadTextFile(const char * fn, const char * mode);
int demofgetc(const char * fn, const char * mode);
int demofgets(const char * fn, const char * mode);
int demoWriteTextPrintf(const char * fn, const char * mode, const char * str);
int demoWriteTextfputs(const char * fn, const char * mode, const char * str);
int demoWriteTextfputc(const char * fn, const char * mode, const char * str);
int execisefputs(const char * fn, const char * mode, const char * str);
int demoBinRead(const char * fn);
int demoBinWrite(const char * fn);
void ExerciseBinWrite(const char * fn);
void ExerciseBinWrite(const char * fn);
#endif //CODE_FILEIO_H
