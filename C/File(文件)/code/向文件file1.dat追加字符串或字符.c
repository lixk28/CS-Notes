#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int main()
{
	char filename[MAX_SIZE]={'\0'};
	printf("Please input the filename:\n");
	gets(filename);
	FILE *fp;
	if( (fp=fopen(filename,"a")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	printf("Please input the string you want to add:\n"); //ÊäÈë£ºHello World 
	char *str=(char *)malloc(sizeof(char)*MAX_SIZE);
	gets(str);  
	fputs(str,fp);
	
//	printf("Please input the character you want to add:\n"); //×·¼Ó×Ö·û 
//	int ch=getchar();
//	fputc(ch,fp);

	fclose(fp);
	
	return 0;
}
