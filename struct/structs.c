//
// Created by wangxi on 2023-03-24.
//
#include "structs.h"
#include <memory.h>
#include <mem.h>
#include <stdlib.h>
#include <stdio.h>
Student * createStudent(char * name, int num,int * marks,int markscount)
{
    Student * student = (Student*)malloc(sizeof(Student));
    if(student)
    {
        //(*student).cNamePtr looks bad
//        student->cNamePtr=(char*) malloc(strlen(name)+1);
//        strcpy(student->cNamePtr,name);
        student->cNamePtr=strdup(name);
        student->iStudentNum=num;
        student->iMarkPtr=(int*) malloc(sizeof(int)*markscount);
        memcpy(student->iMarkPtr,marks,sizeof(int)*markscount);
        student->iMarksCount=markscount;
    }
    return student;
}

void freeStudent(Student * student)
{
    free(student->cNamePtr);
    //student->cNamePtr=NULL;
    free(student->iMarkPtr);
    free(student);
}

void displayStudent(Student * student){
    printf("\nName: %s\n",student->cNamePtr);
    printf("Student num: %d",student->iStudentNum);
    printf("Marks:\n");
    for(int i=0;i<student->iMarksCount;i++)
        printf("%d ",student->iMarkPtr[i]);
    printf("\n\n");
}

Student * getStudent()
{
    char name[256];
    name[0]='\0';
    int studentNum=0;
    int marks[2];
    printf("Enter the name: ");
    getc(stdin);
    fgets(name,256,stdin);

    printf("Enter the student number:");
    scanf("%d",&studentNum);

    printf("Enter two marks:");
    scanf("%d %d",&marks[0],&marks[1]);
    return createStudent(name,studentNum,marks,2);

}

int foo(int k)
{
    return k+1;
}

Classroom * PopuateClassroom()
{
    Classroom * c = malloc(sizeof(Classroom));
    printf("Enter number of students:");
    scanf("%hu",&c->sNumStudents);
    c->sPtrPtr=(Student**) malloc(c->sNumStudents*sizeof(Student*));
    for(int i=0;i<c->sNumStudents;i++)
    {
        c->sPtrPtr[i]=getStudent();
//        *(c.sPtrPtr+i)=getStudent();
    }
    return c;
}

void displayClassroom(Classroom * c) {
    for (int i = 0; i < c->sNumStudents; i++) {
        displayStudent(c->sPtrPtr[i]);
    }
}

void freeClassroom(Classroom * c)
{
    for (int i = 0; i < c->sNumStudents; i++) {
        freeStudent(c->sPtrPtr[i]);
    }
    free(c->sPtrPtr);
    free(c);
}