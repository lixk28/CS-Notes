#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
	FILE *fp;
	char *filename=(char *)malloc(sizeof(char)*SIZE); //Ҳ�������ַ����飬�����Ͳ���malloc 
	printf("Please input the filename you want to use��\n");
	gets(filename);
	
//	scanf("%s", filename); // ע��:scanf�����ַ���ʱ �����ո��ַ����ᱻ�ض� 
// ���������ļ�·�����ļ����в��ܺ��пո� 

	if((fp = fopen(filename, "w")) == NULL) //���ļ� 
	{
		printf("Cannot open this file!\n");
		exit(0);
	} 
	
	printf("Please input the string you want to store:\n"); //���� I am Groot 
	int ch;
	ch = getchar(); //���մӼ�������ĵ�һ���ַ� 
	while(ch != '\n')
	{
		fputc(ch,fp);
		ch = getchar();
	} 
	fclose(fp); //�ر��ļ� 
	
	return 0;
} 
