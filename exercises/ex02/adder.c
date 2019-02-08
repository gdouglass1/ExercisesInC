/**
 * File: adder.c
 * Author:Sherrie Shen
 * Date: Spring 2019
 * Course/Assignmen: Software System Exercise 2
 * Summary of File:
      This file contains a program that allows the user to enters
      integers and store the integers, one per linem, untill the user
      hits Control-D, which is the end of file character.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/* Get the user input of an integer.

   The function will ask the user to reenter the input if
   * The number exceeds the buffer length 8 byte.
   * The number is not an integer.

   integer: address of where the entered integer will be stored. (array)
   counter: keep track of how many numbers have been entered.
   bufferlen: maximum length the input integer can be.
*/
int GetInput(int *integers, int *counter, int *bufferlen);

/* Sum up all the integers user has entered.

   The function will sum up all the integers user entered that are stored in
   an array. After computing the sum, it calls ComputeMax() to check if the sum
   exceeds maximum length the number can be.

   integer: address of where the entered integer will be stored. (array)
   counter: keep track of how many numbers have been entered.
   bufferlen: maximum length the sum can be. (same as user input). This buffer
   length is treated as the maximum number that can be represented.
*/
void AddIntegers(int *integers, int *counter, int *bufferlen);

/* Compute the maximum integer can be represented given a buffer length and
   and check if the sum exceeds this max.

   bufferlen: maximum length the sum can be.
*/
int ComputeMax(int *bufferlen);


int main(){
  int counter = 0;
  int size = 21;
  int integers[size];
  int bufferlen = 8;
  int flag = 0;
  while (flag != EOF){
    if (counter > size - 1){ /* Stop asking for user input when integer*/
                            /* array is full*/
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
