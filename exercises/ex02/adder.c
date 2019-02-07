#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int GetInput(int *integers, int *counter, int *bufferlen);
void AddIntegers(int *integers, int *counter, int *bufferlen);
int ComputeMax(int *bufferlen);


int main(){
  int counter = 0;
  int size = 21;
  int integers[size];
  int bufferlen = 8;
  int flag = 0;
  while (flag != EOF){
    if (counter > size - 1){
      printf("Sorry.Storage limit reached!\n");
      break;
    }
    flag = GetInput(integers, &counter, &bufferlen);
  }
  AddIntegers(integers, &counter, &bufferlen);
  return 0;
}

int GetInput(int *integers, int *counter, int *bufferlen){
  char input[*bufferlen + 10];
  puts("Enter an integer:");
  int flag = scanf("%19s", input);
  if (flag == EOF){
    return flag;
  }
  else{
    int val = atoi(input);
    if (strlen(input) > *bufferlen - 1 ){
      printf("The number you entered is too big! \n");
    }
    else if(val == 0 && input[0] != '0'){
      printf("Invalid input! \n");
    }
    else{
      integers[*counter] = val;
      *counter += 1;
    }
    return flag;
  }

}

void AddIntegers(int *integers, int *counter, int *bufferlen){
  int sum = 0;
  int max = ComputeMax(bufferlen);
  for (int i = 0; i < (*counter); i++){
    sum += integers[i];
  }
  if (sum <= max){
    printf("The sum of all integers is %d \n", sum);
  }
  else{
    printf("Sum exceeds largest integer can be represented!\n");
  }
}

int ComputeMax(int *bufferlen){
  int max = 1;
  for (int i = 0; i < *bufferlen - 1; i++){
    max = max * 10;
    /*printf("max is %d.", max);*/
  }
  return max;
}
