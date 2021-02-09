#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main()
{
	FILE *fp1, *fp2;
	char *filename1 = (char *)malloc(sizeof(char)*MAX_SIZE);
	char *filename2 = (char *)malloc(sizeof(char)*MAX_SIZE);
	printf("Please input the filename to read:\n");
	gets(filename1);
	printf("Please input the filename to copy:\n");
	gets(filename2);
	
	if( (fp1=fopen(filename1,"r")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	if( (fp2=fopen(filename2,"w")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	
	int ch;
	ch = fgetc(fp1);
	while(!feof(fp1))
	{
		fputc(ch,fp2);
		ch = fgetc(fp1);
	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
