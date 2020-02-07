#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int getInput(){
  char str[3];
  int number;
  puts("Enter a number: ");
  scanf("%2s", str);
  switch(str[0]) {
    case 'X':
    return -9;
    break;
  }
  number = atoi(str);
  if(number == 0){
    printf("ERROR: Plese enter a valid number \n");
    getInput();
    return number;
  } 
  return number;
}

int addArray(int *integers, int c){
  int sum = 0;
  for (int i = 0; i < (c); i++){
    sum += integers[i];
  }
  return sum;
}

int main(){
   printf("You can only enter 9 numbers and each number must be less than three digits and positive (1-99).\n");
  int total=0;
  int maxLength = 10;
  int integers[maxLength];
  int counter = 0;
  int numb;
  numb = getInput();

  while (numb!= 'X' && numb != -9){
    if (counter > maxLength - 1){ /* Stop asking for user input when integer array is full*/
      printf("You've entered more than the max of 9 numbers.\n");
      break;
    }
    else{
    integers[counter] = numb;
    counter++;
    numb = getInput();
    }
  }
  total= addArray(integers, counter);
  printf("The sum of every number you have entered is %i", total);
  
}
