//
//  main.c
//  createFile
//
//  Created by miclefengzss on 2020/9/24.
//

#include <stdio.h>

void create_file(char* file_name)
{
    FILE* f = fopen(file_name, "w");
    if (!f) {
        printf("Failed to create file: %s\n", file_name);
        return;
    }
    
    size_t len = fwrite("abcde", 1, 5, f);
    if (len!=5) {
        printf("Failed to write file: %zu\n", len);
        fclose(f);
        return;
    }
    printf("Successed to write file\n");
    fclose(f);
    printf("Successed to create file\n");
    return;
}

void read_file(char* file_name)
{
    char buffer[1024] = {0,};
    FILE* f = fopen(file_name, "r");
    if (!f) {
        printf("Failed to open file: %s\n", file_name);
        return;
    }
    size_t len = fread(buffer, 1, 10, f);
    if (len <= 0) {
        printf("Failed to read file\n");
        fclose(f);
        return;
    }
    printf("Successed to read file: %s\n", buffer);
    fclose(f);
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    create_file("/Users/miclefengzss/Downloads/1.txt");
    read_file("/Users/miclefengzss/Downloads/1.txt");
    return 0;
}
