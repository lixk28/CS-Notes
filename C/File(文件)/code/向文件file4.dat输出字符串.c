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
	getchar(); // �����س��� 
	
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
		//ע�⣺�����ļ�д����ʱ��ֻ����ַ����е���Ч�ַ������������ַ���������־ '\0' 
		//��ÿ������ַ������ֶ���ӻ��з� '\n'�������ͷ�ֹ���ַ�������һƬ ���޷��ָ� 
	}
	
	fclose(fp);
	
	return 0;
}
