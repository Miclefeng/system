//
// Created by miclefengzss on 2021/2/26.
//

#include <stdio.h>
#include <string.h>
#include <io_utils.h>
#include <errno.h>

void Echo() {

#define BUFFER_SIZE 4
  int buffer[BUFFER_SIZE];
  while (1) {
    size_t bytes_read = fread(buffer, sizeof(buffer[0]), BUFFER_SIZE, stdin);
  }
}

int main() {
  Echo();
}