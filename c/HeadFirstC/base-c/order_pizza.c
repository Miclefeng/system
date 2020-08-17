# include <stdio.h>
# include <unistd.h>

// ./order_pizza -d now -t Anchovies Pineapple

int main(int argc,char *argv[])
{
	char *delivery = "";
	int thick = 0;
	int count = 0;
	char ch;

	// d:  ':' 指d后面有一个参数
	// getopt() 处理命令行中的选项, 也就是以"-"开头的命令行参数
	while((ch = getopt(argc,argv,"d:t")) != EOF){
		switch(ch){
			// optarg记录getopt()的选项参数
			case 'd': delivery = optarg;
				break;
			case 't': thick = 1;
				break;
			default:
				fprintf(stderr,"Unknow option: '%s'\n",optarg);
				return 1;
		}
	}

	// optind 跳过选项参数,读取其他参数
	argc -= optind;
	argv += optind;
	if(thick){
		puts("Thick crust.");
	}

	if(delivery[0]){
		printf("To be delivered %s.\n",delivery);
	}
	puts("Ingredients:");

	for(count;count < argc;count++){
		puts(argv[count]);
	}

	return 0;
}

// Thick crust.
// To be delivered now.
// Ingredients:
// Anchovies
// Pineapple
