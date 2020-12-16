//
// Created by miclefengzss on 2020/12/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * c 中 func(void) 代表一个参数都没有
 */
void EmptyParamList(void);

int main(void) {
  srand(time(NULL));
  int magic_number = rand();
  printf("magic_number is: %d\n", magic_number);
  while (1) {
    int user_input;
    puts("Please input a number:");
    scanf("%d", &user_input);
    if (user_input > magic_number) {
      puts("Your number is bigger!");
    } else if (user_input < magic_number) {
      puts("Your number is smaller!");
    } else {
      puts("You got it!");
      break;
    }
  }
}