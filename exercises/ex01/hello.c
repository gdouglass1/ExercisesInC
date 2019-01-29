#include <stdio.h>
void add(int x, int y);
int main() {
    printf("Hello, World!\n");
    add(2,4);
    int a = 3;
    int b = 4;
    int c = a + b;
    printf("c is %d\n", c);
    return 0;
}

void add(int x, int y){
  int z = x + y;
  printf("The answer is %d\n",z);
}
