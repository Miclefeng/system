#include <stdio.h>

int main()
{
	char name[30]; // 数组变量 
	printf("Enter your name:");
	scanf("%29s",name); // scanf()让用户从键盘输入字符串 读取30个字符，以及字符串终结符\0.
	
	int age;
	printf("Enter your age:");
	scanf("%i",&age);  // 用 & 运算符得到 age 的地址 
	
	char first_name[20];
	char last_name[20];
	printf("Enter first and last name:");
	scanf("%19s %19s",first_name,last_name);
	printf("First: %s Last: %s\n",first_name,last_name); 
}

