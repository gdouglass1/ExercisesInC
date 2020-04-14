/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

When removing the exit after child_code(), the child process never terminates
and start running the rest of the code copied from parent process:

Creating child 0
Hello from the parent
Hello from child 0
child heap: 2
Hello from the parent
wait failed: No child processes
./fork: No child processes
Child 6928 exited with error code 1
parent: heap: 1
Elapsed time = 0.000755 seconds

The parent and child process don't share the heap, static, stack, or global. Copy on write is used so the parent
and child share a single copy of the process address space. 
A seperate copy is made when there is a try to write into the process address space. 
This is used because it prevents wasting copying large amounts of data as many times as the exec()
system call is used by the child process to create a different process. 

Creating child 0
Hello from the parent
Hello from child 0
child heap: 2
child global: 2
child stack: 2
Child 7723 exited with error code 0
parent: heap: 1
parent: global: 1
parent: stack: 1
Elapsed time = 0.000725 seconds

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>


// errno is an external global variable that contains
// error information
extern int errno;

int global_message = 1;
int* heap_message;


// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i)
{
    sleep(i);
    printf("Hello from child %d.\n", i);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;

    heap_message = (int*)malloc(1*sizeof(int));
    *heap_message = 1;
    int stack_message = 1;
    static int static_message = 1;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {

        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            child_code(i);
            (*heap_message)++;
            printf("child heap: %d\n", *heap_message);
            global_message++;
            printf("child global: %d\n", global_message);
            stack_message++;
            printf("child stack: %d\n", stack_message);
            static_message++;
            printf("child static: %d\n", static_message);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }

    printf("parent: heap: %d\n", *heap_message);
    printf("parent: global: %d\n", global_message);
    printf("parent: stack: %d\n", stack_message);
    printf("parent: static: %d\n", static_message);


    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}
