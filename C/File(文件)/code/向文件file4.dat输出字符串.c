#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int main()
{
	char filename[MAX_SIZE]={'\0'};
	printf("Please input the filename:\n");
	gets(filename);
	
	FILE *fp;
	if( (fp=fopen(filename,"w")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	
	printf("Please input the number of the strings:\n");
	int n,i;
	scanf("%d",&n); // 3
	getchar(); // 消化回车符 
	
	char str[n][MAX_SIZE];
	printf("Please input the strings:\n");
	for(i=0;i<n;i++)
		gets(str[i]); 
	//I am Groot
	//Hello World
	//Surprise Motherfucker
	
	for(i=0;i<n;i++)
	{
		fputs(str[i],fp);
		fputc('\n',fp); 
		//注意：在向文件写数据时，只输出字符串中的有效字符，并不包括字符串结束标志 '\0' 
		//在每次输出字符串后，手动添加换行符 '\n'，这样就防止了字符串连成一片 ，无法分隔 
	}
	
	fclose(fp);
	
	return 0;
}
