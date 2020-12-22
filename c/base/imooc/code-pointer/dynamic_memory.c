//
// Created by miclefengzss on 2020/12/21.
//

#include <stdlib.h>
#include <io_utils.h>

#define PLAYER_COUNT 10

void InitPointer(int **ptr, int length, int default_value) {
  // malloc 分配多大(字节)的内存空间
  *ptr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; ++i) {
//    (*ptr)[i] = default_value;
    // 先进行解引用取到ptr地址起始位置，在进行解引用对其进行赋值
    *(*ptr + i) = default_value;
  }
}

int main() {
  int *players;
  // *pointer 进行传递是值拷贝,所有需要进行指针的地址传递，以达到改变原值的目的
//  InitPointer(&players, PLAYER_COUNT, 0);
//  PRINT_INT_ARRAY(players, PLAYER_COUNT);
  // calloc 进行内存空间分配(个数和每个所占字节数)，并对空间进行初始化
  players = calloc(PLAYER_COUNT, sizeof(int));
  for (int i = 0; i < PLAYER_COUNT; ++i) {
    PRINT_INT(players[i]);
    players[i] = i;
  }
  PRINT_INT_ARRAY(players, PLAYER_COUNT);
  // realloc 为已存在的内存空间重新分配大小，原始内存地址，需要分配的内存大小(字节数)，不会进行初始化
  players = realloc(players, PLAYER_COUNT * 2 * sizeof(int));
  PRINT_INT_ARRAY(players, PLAYER_COUNT * 2);

  if (players) {
    free(players);
  }
  return 0;
}