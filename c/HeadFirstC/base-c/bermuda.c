# include <stdio.h>

// '<' 会把文件内容发送到流水线中第一个进程的标准输入,'>' 会捕获流水线中最后一个进程的标准输出
// test shell :  (./bermuda | ./tojson) < spooky.csv > output.json 

int main(void)
{
	float latitude;
	float longitude;
	char info[80];
	while (scanf("%f,%f,%79s[^\n]",&latitude,&longitude,info) == 3){
		if((latitude > 26) && (latitude < 34)){
			if((longitude > -76) && (longitude < -64)){
				printf("%f,%f,%s\n",latitude,longitude,info);
			}
		}
	}

	return 0;
}