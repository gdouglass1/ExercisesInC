/**
 * File: cards.c
 * Author:Sherrie Shen
 * Date: Spring 2019
 * Course/Assignmen: Software System Exercise 1
 * Summary of File:
      This file contains code modified from the code on page 37 of Head First C.
      The original function is refactored and splitted into three functions.
*/

#include <stdio.h>
#include <stdlib.h>

/* Update numeric value of card name input by user and return the value.

   If the input card name is not a face card, converts string array into an
   integer.

   card_name: where the user input is stored
*/
int UpdateValue(char card_name[3]);


/* Check if the value of card name is valid.

   If the value is 0 which means the input is X or any letter that is not a
   face card value or if the value is greater than 11 (largest number assinged to a
   face card value), an invalid case rises.

   Return 1 for invalid value and 0 for valid value.

   card_name: where the user input is stored
*/
int CheckInvalidCase(int val);

/* Update count based on numeric card value.

   Increment count for values between 2 and 7 and decrease count when value
   equals 10.

   val: numeric value of the input card.
*/
void UpdateCount(int val);

int main()
{
    char card_name[3];
    do {
        puts("Enter the card_name: ");
        scanf("%2s", card_name);
        int val = UpdateValue(card_name);
        if (CheckInvalidCase(val)){
          continue;
        }
        UpdateCount(val);
    } while (card_name[0] != 'X');
    return 0;
}

void UpdateCount(int val){
    static int count = 0;
    if ((val > 2) && (val < 7)) {
        count++;
    } else if (val == 10) {
        count--;
    }
    printf("Current count: %i\n", count);
};

int CheckInvalidCase(int val){
  if((val < 1) || (val > 11)){
    puts("I don't understand that value!");
    return 1;
  }
  else {
    return 0;
  }
};

int UpdateValue(char card_name[3]){
  int val;
  switch(card_name[0]) {
  case 'K':
  case 'Q':
  case 'J':
    val = 10;
    break;
  case 'A':
    val = 11;
    break;
  default:
    val = atoi(card_name); /* val equals zero if card name are letters.*/
    break;
  }
  return val;
};
