//
// Created by wangxi on 2023-03-24.
//

#ifndef CODE_STRUCTS_H
#define CODE_STRUCTS_H

#pragma pack(push)
#pragma pack(1)
typedef struct _BirthDate{
    char cName[5];//5 It is not a string it is a arry of 5 chars which can contain at most 4 chars str
    char cGender;//1
    int day;//4
    int month;//4
    int year;//4
} BirthDate;

typedef struct _BirthDate1{
    char * cName;//8 It is a char pointer which take 8 bytes
    char cGender;//1
    int day;//4
    int month;//4
    int year;//4
} BirthDate1;
#pragma pack(pop)

typedef struct _student{
    char * cNamePtr;
    int iStudentNum;
    int * iMarkPtr;
    int iMarksCount;
}Student;


typedef struct _classroom{
    unsigned short sNumStudents;
    //Student studentList[100] does not work because we do not know how many students in the class
    //Student * studentList;//It will point to a student array which each element is a student stuct
    Student ** sPtrPtr; //This is point to Student *[]
}Classroom;

Classroom * PopuateClassroom();
void displayClassroom(Classroom * c);
void freeClassroom(Classroom * c);


typedef struct _pixel
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
}Pixel;

typedef union
{
    unsigned int val;
    Pixel components;
}Color;

typedef union
{
    unsigned int dword_val;
    struct words{
        unsigned short high;
        unsigned short low;
    };
    struct nibbles{
        unsigned char four;
        unsigned char three;
        unsigned char two;
        unsigned char one;
    };
    unsigned char nibbie_arr[4];
    unsigned short words_arr[2];
}DWORD;

#endif //CODE_STRUCTS_H
