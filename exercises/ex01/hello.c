#include <stdio.h>
void checkOddEven(int a, int b){
  int c = a + b;
    printf("c is %d\n", c);
    /* if (c%2 == 0) {
        printf("c is even\n");
    } 
    else {
        printf("c is odd\n");
    } */
    int z= c%2;
    switch(z){
      case 0:
        printf("c is even\n");
        break;
      default:
        printf("c is odd\n");
        break;
    }
}

int main() {
    printf("Hello, World!\n");
    int a = 3;
    int b = 4;

    checkOddEven(a, b);
    return 0;
}
