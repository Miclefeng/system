# include <stdio.h>

int main(void)
{
	char word[10];
	int i = 0;
	while(scanf("%9s",word) == 1){
		i = i + 1;
		if(i % 2){
			// > 将标准out流重定向到文件
			// stdout,将数据放入标准out流中
			fprintf(stdout,"%s\n",word);
		}else{
			// 2> 将错误信息重定向到文件
			// stderr,将错误放入标准out流中
			fprintf(stderr,"%s\n",word);
		}
	}

	return 0;
}