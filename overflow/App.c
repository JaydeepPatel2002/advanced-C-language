#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_bytes(void *ptr, int size)
{
    printf("%p(%d): ",ptr,size);
    unsigned char *p = ptr;
    int i;
    for (i=0; i<size; i++) {
        printf("%02hhX ", p[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int nRs = 0;
    char cArray[10];
    int nRs1 = 0;
    memset(cArray, 0, 10);
    print_bytes(&nRs, sizeof(int));
    print_bytes(cArray, 10);
    print_bytes(&nRs1, sizeof(int));
    print_bytes(&nRs1, 30);
    printf("%d %s \n", nRs, cArray);
    printf("\n");

    sprintf(cArray, "%s", "123456789");
    print_bytes(&nRs, sizeof(int));
    print_bytes(cArray, 10);
    print_bytes(&nRs1, sizeof(int));
    print_bytes(&nRs1, 30);
    printf("%d %s \n", nRs, cArray);
    printf("\n");

    sprintf(cArray, "%s", "1234567891");
    print_bytes(&nRs, sizeof(int));
    print_bytes(cArray, 10);
    print_bytes(&nRs1, sizeof(int));
    print_bytes(&nRs1, 30);
    printf("%d %s \n", nRs, cArray);
    printf("\n");

    sprintf(cArray, "%s", "12345678912");
    print_bytes(&nRs, sizeof(int));
    print_bytes(cArray, 10);
    print_bytes(&nRs1, sizeof(int));
    print_bytes(&nRs1, 30);
    printf("%d %s \n", nRs, cArray);
    printf("\n");

    sprintf(cArray, "%s", "123456789123");
    print_bytes(&nRs, sizeof(int));
    print_bytes(cArray, 10);
    print_bytes(&nRs1, sizeof(int));
    print_bytes(&nRs1, 30);
    printf("%d %s \n", nRs, cArray);
}