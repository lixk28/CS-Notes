#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE1 100
#define MAX_SIZE2 25

int main()
{
	FILE *fp;
	char filename[MAX_SIZE1]={'\0'};
	char str[MAX_SIZE2]={'\0'};
	printf("Please input the filename:\n");
	gets(filename);
	printf("Please input the string that should be stored:\n");
	gets(str);
	
	if( (fp=fopen(filename,"w")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	
	fputs(str,fp);
	fclose(fp);
	
	return 0;
}
