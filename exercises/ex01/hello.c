#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("Hello, World!\n");
    printf("y is %d\n",y);
    return 0;
}

/*
1.  subq $16, %rsp 
    movl $5, -8(%rbp)
2. The lines disappear when you turn on optimization using the flag -02. 
3. %es and Movl $5 is added.
4. Optimization decreases the runtime because the code size gets smaller.  
 */
