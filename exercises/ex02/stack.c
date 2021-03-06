/* Example code for Think OS.
Copyright 2014 Allen Downey
License: GNU GPLv3
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
/* 
1: This program will print the address of the local variable array in foo()
and bar(). If the program works as expected it prints 42 5 times.
2: The warning I get is that the function returns the address of stack memory associated with local variable array which means 
that that in foo()it is trying to return a pointer to a local array that will be taken off the stack after the function ends.
3: A segmentation fault occurs because the address array in the main function is illegally
editing that same memory address.
4: I get a warning saying the local variable array in bar function is set but not used.
*/

