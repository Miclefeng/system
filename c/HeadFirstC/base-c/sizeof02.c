#include <stdio.h>

void skip(char *msg)
{
	puts(msg + 6);
 } 

int main()
{
	char s[] = "How big is it?";
	char *t = s;  // t 是 s 的指针 
	printf("s的指针是%p\n",&s);
	printf("t %p\n",t);
	char *msg_from_amy = "Don't call me";
	skip(msg_from_amy);
	return 0;	
 } 
