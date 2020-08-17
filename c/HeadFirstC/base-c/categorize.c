# include <stdio.h>
# include <stdlib.h>
# include <string.h>


// ./categorize UFO ufos.csv Disappearance disappearances.csv other.csv
// argc the param number
// argv the param offset
int main(int argc,char *argv[])
{
	char line[80];

	if(argc != 6){
		fprintf(stderr,"You need to give 5 arguments\n");
		return 1;
	}
	FILE *in;
	if(!(in = fopen("spooky.csv","r"))){
		fprintf(stderr,"can`t open the file\n");
		return 1;
	}
	FILE *file1;
	if(!(file1 = fopen(argv[2],"w"))){
		fprintf(stderr,"can`t open the file\n");
		return 1;
	}
	FILE *file2;
	if(!(file2 = fopen(argv[4],"w"))){
		fprintf(stderr,"can`t open the file\n");
		return 1;
	}
	FILE *file3;
	if(!(file3 = fopen(argv[5],"w"))){
		fprintf(stderr,"can`t open the file\n");
		return 1;
	}
	// [^\n] 读取输入流中匹配到\n前的所有字符
	while(fscanf(in,"%79[^\n]\n",line) == 1){
		if(strstr(line,argv[1])){
			fprintf(file1,"%s\n",line);
		}else if(strstr(line,argv[3])){
			fprintf(file2,"%s\n",line);
		}else{
			fprintf(file3,"%s\n",line);
		}
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);

	return 0;
}