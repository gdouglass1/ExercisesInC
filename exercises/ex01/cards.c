#include <stdio.h>
#include <stdlib.h>
char getCard(){
  char card_name[3];
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
  return card_name[0];
}
int checkLetters(char cn){
  int i= atoi(&cn);
  int v= 0;
  switch(cn) {
      case 'K':
      case 'Q':
      case 'J':
        v = 10;
        return v; 
        break;
      case 'A':
        v = 11;
        return v; 
        break;
      case 'X':
        break;
  }
  if( (i<1) || (i>10)){
    puts("I don't understand that value!");
    v= 0;
    return v;
  }
  return v;
}
int checkNumbers(char cn){
  int c=0; 
  if ((cn> 2) && (cn <11)){
    c++;
    return c;
  }
  return c; 
}
int main(){
  int count = 0;
  char cardName= getCard();

  while (cardName != 'X'){
    int val = 0;
    val= checkLetters(cardName);
    count+= val;
    if (val==0){
      count += checkNumbers(atoi(&cardName));
    }
    printf("Current count: %i\n", count);
    cardName= getCard();

  }
return 0;
}
