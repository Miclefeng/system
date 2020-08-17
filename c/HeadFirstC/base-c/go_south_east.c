#include <stdio.h>

void go_south_east(int *lat,int *lon)
{
	*lat = *lat - 1;
	*lon = *lon + 1;
}

int main()
{
	int x = 4;
	int latitude = 32;
	int longitude = -64;
	go_south_east(&latitude,&longitude);
	printf("x lives at %p\n",&x); // %p 将 &x 转换为16进制 
	printf("停！当前位置：[%i, %i]\n",latitude,longitude);
	return 0;
}
