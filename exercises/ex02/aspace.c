/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;
void printAddress(int var){
  printf("Address of local variable is %p\n", &var);
  return;
}
int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *e = malloc(128);
    /*Heap grows up towards larger addresses.*/

    void *a = malloc(10);
    void *b = malloc(10);
    printf ("a points to %p\n", a);
    printf ("b points to %p\n", b);
    /* The space between them is 0x20 or 20 bytes*/

    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);

    printAddress(var2);
    /*stack grows downwards toward lower addresses.*/
    return 0;
}
