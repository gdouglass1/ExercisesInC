/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void foo(int *array) { /*Instead of returning pointers to stack allocated data
                          pass the pointer to the function as a parameter*/
    int i;
    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int array[SIZE]; /*Initialize array before foo and pass it as
                     a pointer input parameter */
    foo(array);
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

/*
Question 1: it will print the address of the local variable array in both foo()
and bar() and print 42 5 times if the program worked as expected.

Question 2: The warning I got is function returns address of local variable.
This means that that in foo(), it is trying to return a pointer to a local
array that will be taken off the stack after the function ends.

Question 3: A segmentation fault appears.This is because array in the main
function is pointing to the address of a stack allocated data. This data
disappears after the stack for the function call is removed. The print
statements in foo and bar show that the local variable array for each has the
same address. Therefore, The address array in the main function is illegally
editing that same memory address and therefore yields segmentation fault.

QUestion 4: WHen the print statements are commented out, I got additional
warning from the compiler saying the local variable array in bar function is
set but not used.

*/
