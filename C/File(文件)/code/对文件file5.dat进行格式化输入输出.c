#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int main()
{
	FILE *fp;
	printf("Please input the filename:\n");
	char filename[MAX_SIZE]={'\0'};
	gets(filename);
	
	if( (fp=fopen(filename,"w")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	
	int i1,i2;
	float f1,f2;
	char c1,c2;
	char str1[MAX_SIZE]={'\0'},str2[MAX_SIZE]={'\0'};
	
	printf("Please input an integer:\n");
	scanf("%d",&i1);
	getchar();
	printf("Please input a real number:\n");
	scanf("%f",&f1);
	getchar();
	printf("Please input a character:\n");
	scanf("%c",&c1);
	getchar();
	printf("Please input a string:\n");
	gets(str1);
	
	fprintf(fp,"%d,%.2f,%c,%s",i1,f1,c1,str1);
	
	rewind(fp);
	fscanf(fp,"%d,%f,%c,%s",&i2,&f2,&c2,str2);
	printf("%d %.2f %c   %s",i2,f2,c2,str2); 
	
	fclose(fp);
	
	return 0;
}
