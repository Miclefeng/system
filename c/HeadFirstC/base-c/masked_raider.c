#include <stdio.h>

int main()
{
	char masked_raider[] = "Alive";
	char *Jimmy = masked_raider; // masked_raider && jimmy 都指向了 Alive 同一个地址 
	printf("Masked raider is %s,Jimmy is %s\n",masked_raider,Jimmy);
	masked_raider[0] = 'D';
	masked_raider[1] = 'E';
	masked_raider[2] = 'A';
	masked_raider[3] = 'D';
	masked_raider[4] = '!';
	printf("Masked raider is %s,Jimmy is %s\n",masked_raider,Jimmy);
	return 0;
}
