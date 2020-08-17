#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main()
{
	int a = 1;
	int b = 2;
	int c = 0;
	c = func(a,b);
	printf("%d",c);
	system("pause");
	//	return 0;	
}

int func(int iParam1,int iParam2)
{
	return iParam1+iParam2;
}*/

int main()
{
	int decks;
	puts("输入有几副牌");
	scanf("%i",&decks);
	if(decks < 1){
		puts("无效的副数");
		return 1;
	}
	
	printf("一共有%i张牌\n",(decks * 52));
	system("pause");
	return 0;
}
