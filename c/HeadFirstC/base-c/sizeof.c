#include <stdio.h>

void fortune_cookie(char msg[])
{
	printf("Message reads: %s\n",msg);
	printf("msg occupies %i bytes\n",sizeof(msg));
}

int main()
{
	char quote[] = "Cookies make you fat";
	fortune_cookie(quote);
	printf("The quote 字符串保存在：%p\n",quote);
	
	int contestants[] = {1,2,3};
	int *choice = contestants; // choice 是 contestants数组的地址(指向数组的第一个元素) 
	contestants[0] = 2;
	contestants[1] = contestants[2];
	contestants[2] = *choice;  // *choice == contestants[0] == 2
	printf("我选 %i 号男嘉宾\n",contestants[2]);
	printf("%p\n",choice);
	
	int nums[] = {1,2,3};
	printf("nums 的地址是： %p\n",nums);
	printf("nums + 1 的地址是： %p\n",nums + 1); // 编译器地址 + 4，int占4字节 
	
	int doses[] = {1,3,2,1000};
	printf("%i\n",sizeof(doses));
	printf("服用 %i 毫克的药",3[doses]); 
	return 0;
}

