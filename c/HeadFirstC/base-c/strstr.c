#include <stdio.h>
#include <string.h>

char tracks[][80] = {
	 "I left my",
	 "Newark,Newark",
	 "nightwish",
	 "likenpark",
	 "fallout of the way"
};

void find_track(char search_for[])
{
 int i;
 for(i = 0;i < 5;i++){
 	if(strstr(tracks[i],search_for))
		printf("Track %i: '%s'\n",i,tracks[i]);
 }		
}

int main()
{
 char search_for[80];
 printf("Search for: ");
 fgets(search_for,80,stdin);
 printf("%i\n",strlen(search_for));
 search_for[strlen(search_for) - 1] = '\0';// 将 search_for 的最后一位设置为 '\0' 
 find_track(search_for);
 return 0; 
} 
