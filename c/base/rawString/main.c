#include <stdio.h>
#include <string.h>

int myStrlen(char *str);

char *myStrcat(char *dest, char *src);

char *myStrcpy(char *dest, char *src);

int myStrcmp(char *a, char *b);

char *myStrrstr(char const *s1, char const *s2);

int main()
{
    char *p = "china";
    char arr[] = "china";

    char *q = p;
    int count = 0;

    while (*q++) {
        count++;
    }
    printf("%d\n", count);
    // 将q指针的地址重新指向arr的首地址
    q = arr;
    for (count = 0; *q++; count++);

    printf("%d\n", count);

    // 传数组需要传数组名和范围  arr[10], 10
    int len = strlen(arr);
    printf("%d\n", len);

    char firstName[] = "micle";
    char middleName[] = " -- ";
    char lastName[] = "feng";

    char *pf, *pl;
    pf = firstName; pl = lastName;
    while (*pf) pf++; // 将pf的地址移向字符串末尾\0处

//    while (*pf = *pl) {
//        *pf++;
//        *pl++;
//    }

    while (*pf++ = *pl++);
    // strcat 被连接的串要有足够的空间，即 firstName 的范围 >= firstName + lastName
//    strcat(firstName, lastName);
    printf("%s\n", firstName);

    myStrcat(myStrcat(firstName, middleName), lastName);
    printf("%s\n", firstName);

    char name[200];
    char *pName = "china";
    // strcpy 被拷贝的区域需要有足够的空间容纳 拷贝的字符串空间
    strcpy(name, pName);
    printf("%s\n", name);

    char *s1 = "miclefengzss";
    char *s2 = "miclezss";
    printf("%d\n", myStrcmp(s2, s1));
    printf("_____________________\n");

    char msg[100] = "original message";
//    strcpy(msg, "different"); // dst, src 复制 different 到 msg，覆盖原值
    // 目标字符数组的空间必须足以容纳需要复制的字符串
//    strcpy(msg, "a different message");
//    printf("msg = %s\n", msg);

    strcpy(msg, "Hello ");
    printf("cpy -> msg = %s\n", msg);
    strcat(msg, "miclefengzss"); // dst src 将 src 连接到 msg 上
    // 目标字符数组的空间必须足以容纳需要连接的字符串
    strcat(msg, ", how are you?");
    printf("cat -> msg = %s\n", msg);

    char m[] = "zss";
    char n[] = "wxm";
    printf("cmp -> a & b = %d\n", strcmp(m, n));

    char strdst[12] = "Hello ";
    // 目标字符数组的空间必须足以容纳需要连接的字符串的长度(包含'\0')
    strncat(strdst, "world!", 5); // 自动在末尾填充 '\0'
    printf("ncat -> strdst = %s\n", strdst);

    char *soureStr = "Hello world! this is beautiful world!";
    char *findStr = "world";
    printf("strstr               = %p\n", soureStr);
    printf("strstr  -> pos       = %p\n", strstr(soureStr, findStr)); // strstr 查找字符串首次出现的位置，返回该位置的地址
    printf("strrstr -> pos       = %p\n", myStrrstr(soureStr, findStr)); // 查找字符串最后一次出现的位置，返回该位置的地址
    printf("sourceStr            = %s\n", soureStr);
    printf("strstr  -> sourceStr = %s\n", strstr(soureStr, findStr));
    printf("strrstr -> sourceStr = %s\n", myStrrstr(soureStr, findStr));

    return 0;
}

int myStrlen(char *str)
{
    int len;
    for (len = 0; *str++; len++);
    return len;
}

// 返回 char*, 是为了实现链式表达
char *myStrcat(char *dest, char *src)
{
    char *d = dest;
    while(*dest) dest++;
    while(*dest++ = *src++);
    return d;
}

char *myStrcpy(char *dest, char *src)
{
    char *d = dest;
    while (*dest++ = *src++);
    return d;
}

int myStrcmp(char *a, char *b)
{
    for (;*a && *b && *a == *b;a++, b++);
    return *a - *b;
}

char *myStrrstr(char const *s1, char const *s2)
{
    register char *last;
    register char *current;

    last = NULL;

    // 只有当第二个字符串不为空时才进行查找，如果s2位空，返回NULL
    if (*s2 != '\0') {
        // 查找s2在s1中的第一次出现的位置
        current = strstr(s1, s2);
        // 每次查找到字符串时，让指针指向它的起始位置，然后查找下一个匹配位置
        while (current != NULL) {
            last = current;
            // last+1 防止重复查找
            current = strstr(last+1, s2);
        }
    }
    return last;
}
