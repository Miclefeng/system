//
// Created by miclefengzss on 2020/12/15.
//

#include <io_utils.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER_COUNT 50

void SwapElement(int array[], int first, int second) {
  if (first == second) {
    return;
  }
  int temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}

void ShuffleArray(int array[], int length) {
  srand(time(NULL));
  for (int i = length; i > 0; --i) {
    int random_number = rand() % i;
    SwapElement(array, i, random_number);
  }
}

int main() {
  int players[PLAYER_COUNT];

  for (int i = 0; i < PLAYER_COUNT; i++) {
    players[i] = i;
  }

  PRINTLNF("Before shuffle:");
  PRINT_INT_ARRAY(players, PLAYER_COUNT);
  PRINTLNF("After shuffle:");
  ShuffleArray(players, PLAYER_COUNT);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);
}