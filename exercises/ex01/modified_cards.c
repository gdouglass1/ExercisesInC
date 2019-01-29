#include <stdio.h>
#include <stdlib.h>
void UpdateCount(int val);
int CheckInvalidCase(int val);
int UpdateValue(char card_name[3]);
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
  if((val < 1) || (val > 10)){
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
    val = atoi(card_name);
    break;
  }
  return val;
};
