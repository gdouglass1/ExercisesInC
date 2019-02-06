/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;
void check_stack();

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *j = malloc(128);
    /*Heap grows up towards larger addresses. Address of j pointed to
     is high than the address p pointed to in heap*/
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    check_stack();

    printf ("p points to %p\n", p);
    printf ("j points to %p\n", j);
    printf ("s points to %p\n", s);

    /*stack grows downwards toward lower addresses. Address of local variable
    a is lower than the address of var2.*/

    void *m = malloc(10);
    void *n = malloc(10);
    printf ("m points to %p\n", m);
    printf ("n points to %p\n", n);
    /* The space between them is 0x20 which is 20 byte*/

    return 0;
}

void check_stack(){
  int a = 4;
  printf("Address of local var a is %p\n", &a);
}
