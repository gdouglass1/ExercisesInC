#include <stdio.h>
#include <stdlib.h>

char * getCard(){
  char *card_name = (char *) malloc(sizeof(char) * 3);
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
  return card_name;
}

int checkLetters(char * cn){
  int val = 0;
  switch(cn[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      break;
    default:
      val = atoi(cn);
      if((val<1) || (val >10)){
        puts("I don't understand that value!");
        val=0;
        break;
      }
  }
  return val;
}

int main(){
  int count = 0;
  char * cardName= getCard();

  while (cardName[0] != 'X'){
    int v = 0;
    v= checkLetters(cardName);
    count+= v;
    printf("Current count: %i\n", count);
    cardName= getCard();

  }
return 0;
}
