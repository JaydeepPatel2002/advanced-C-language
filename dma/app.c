//
// Created by wangxi on 2023-02-01.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "dma.h"
void printaddr(const char * hint, void * p)
{
    printf("%s: %p\n",hint,p);
}

/*
 * When we pass an arry to a function
 * the array will be point to the same addr as in main
 * When an array be pass into a function, a local var is created in the stack of test
 * then the local var will point to the same addr of the array in main
 * But the local var will have the different addr as the array in main
 *
 */

void test(int array[] , int * ptr)
{
    printaddr("Arr in test",array);
    printaddr("&arr in test",&array);
    printaddr("Ptr in test",ptr);
    printaddr("&ptr in test",&ptr);
    printaddr("Arr[0] in test",&array[0]);
}
/*In main
 * array is always point to the begining to the data
 * which is same addr of the first element
 * &array will still give you the same addr
 * array can  never to repoint to another addr like pointer
 *
 *
 *
 */
//int main(int argc, const char * argv[]) {
//    int arr[] = {1,2,3,4,5};
//    printaddr("Array in main",arr);
//    printaddr("&Array in main",&arr);
//    printaddr("Arr[0] in main",&arr[0]);
//    test(arr,arr);
//    int i = 10;
//    int * ptri = &i;
//    int * ptra = arr;
//    int * ptra = &arr;
//    int * ptra = &arr[0];
//    *ptri = 11;
//    printf("%d\n",i);
//    printf("%d\n",*ptri);
//    *ptra  = 100;
//    *(ptra+1)=101;
//}

//int main(int argc, const char * argv[]) {
//    printf("Please enter how many number you will enter:");
//    int count = 0;
//    scanf("%d",&count);
//    int * memblock = (int*)malloc(sizeof(int)*count);
//    int * ptr = memblock;
//    int totalNumbers = count;
//    while(count>0)
//    {
//        printf("Please enter a number(%d left)",count);
//        scanf("%d",ptr++);
//        count--;
//    }
//    for(int i=0;i<totalNumbers;i++)
//    {
//        printf("%d ",*(memblock+i);
//    }
//    free(memblock);
//}

int main(int argc, const char * argv[]) {
    printf("Please enter how many number you will enter:");
    int count = 0;
    scanf("%d",&count);
    int * memblock = getInts(count);

    printf("Please enter how many number you will enter:");
    int count1 = 0;
    scanf("%d",&count1);
    int * memblock1 = getInts(count1);
    int sizes[2];
    sizes[0]=count;
    sizes[1]=count1;

    //int * rs = addInts(memblock,memblock1,sizes);
    int * arrays[2];
    arrays[0]=memblock;
    arrays[1]=memblock1;
//    int * rs = addIntsv2(arrays,sizes);
    int * rs = addIntsv4(arrays,sizes,2);
    printInts(rs,count+count1);
    free(memblock);
    free(memblock1);
    free(rs);
}