/* Gia Douglass
Program that counts the value of cards entered
*/
#include <stdio.h>
#include <stdlib.h>
/* Prompts the user for input of a card and puts the reply in the given buffer.
       User input is truncated to the first two characters, char size 3 for buffer. 
       Returns card_name.
       card_name: buffer where result is stored
*/
char * getCard(){
  char *card_name = (char *) malloc(sizeof(char) * 3);
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
  return card_name;
}

/* Evaluates card that user input (card_name) to determine the value if it's a letter. 
       Returns int value of card if a valid card (1-10, J, Q, K, A).
       If user inputs 'X', program will stop.
       cn: card that user input
       val: value of the letter of the card

*/
int checkLetters(char * cn){
  int val = 0;
  switch(cn[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 1;
      break;
    case 'A':
      val = 1;
      break;
    case 'X':
      break;
    default:
      val=0;
      break;
  }
  return val;
}

/* Evaluates card that user input (card_name) to determine the value if it's a number. 
       Returns int value of card if a valid card (1-10, J, Q, K, A).
       Prints "I don't understand value" if input isn't valid card.
       val: value of the letter of the card
*/
int checkNumbers(char * cn){
  int val= 0;
  val = atoi(cn);
  if((val<1) || (val >10)){
    puts("I don't understand that value!");
    val=0;  
    return val;
  }
  else if((val>=1) || (val <=10)){
    val=1;
    return val;   
  }
  return 0;
}

/* Main function will call on getCard() to ask the user to input card then call on checkLetters() and checkNumbers() to evaluate card value. Will output current count of all the cards the user has entered. 
       Program will run as long as user does not input 'X'.
       Calls on functions getCard() and check().
*/
int main(){
  int count = 0;
  char * cardName= getCard();

  while (cardName[0] != 'X'){
    int v = 0;
    v= checkLetters(cardName);
    count+= v;
    if(v!=1){
    v= checkNumbers(cardName);
    count+= v;
    }
    printf("Current count: %i\n", count);
    cardName= getCard();

  }
return 0;
}
