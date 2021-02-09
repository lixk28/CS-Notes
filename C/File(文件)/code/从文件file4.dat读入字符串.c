#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int main()
{
	char filename[MAX_SIZE]={'\0'};
	printf("Please input the filename:\n");
	gets(filename);
	
	FILE *fp;
	if( (fp=fopen(filename,"r")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	
	printf("Please input the number of the strings you want to read:\n");
	int n,i;
	scanf("%d",&n);
	getchar(); //消化回车符
	
	char str[n][MAX_SIZE];
	for(i=0;i<n;i++)
		fgets(str[i],MAX_SIZE,fp);
	
	for(i=0;i<n;i++)
		puts(str[i]); // 屏幕上每个字符串相隔一行的原因是 '\n'也读入到字符数组中了 
		
	fclose(fp);
	
	return 0;
}
