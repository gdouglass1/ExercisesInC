#include<stdio.h>

int main()
{

   char c;

    int flag=0;

printf("- ");

while (flag != EOF) {
    flag = scanf(" %c", &c);
    printf("%d\n",flag);
    printf("- ");

}
return 0;
}
