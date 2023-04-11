//
// Created by wangxi on 2023-03-24.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "structs.h"
int main(int argc, char ** argv) {

    Classroom  * c = PopuateClassroom();
    displayClassroom(c);
    freeClassroom(c);

//    Color c;
//    printf("%d\n", sizeof(c));
//    printf("%d\n", sizeof(c.components));
//    printf("%d\n", sizeof(c.val));
//    c.val=0xeeeeeeee;
//    printf("%x\n",c.val);
//    printf("%x %x %x %x\n",
//           c.components.a,
//           c.components.b,
//           c.components.g,
//           c.components.r);
//    printf("%x\n",*(int*)&c);
//    printf("%p %p %p\n",&c,&c.components,&c.val);
}
