#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int main()
{
	/* ��һ���ַ��������file7.dat */ 
	FILE *fp1, *fp2;
	if( (fp1=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(�ļ�)\\test_file\\file7.dat","r+")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);	
	} 
	printf("Plesae input a string:\n");
	char str[MAX_SIZE]={'\0'};
	gets(str);
	
	fputs(str,fp1);
	
//	rewind(fp1); //��һ�䲻��ʡ�ԣ�file7.datд���ַ������дλ�ñ���Ѿ�ָ�����һ���ַ��ĺ��� 

	/*  ��file7.dat�����ݸ��Ƶ�file8.dat */ 
	if( (fp2=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(�ļ�)\\test_file\\file8.dat","w")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	} 
	int ch;
	ch=fgetc(fp1);
	while(!feof(fp1)) //Ҳ����д�� while(ch!=EOF) 
	{
		fputc(ch,fp2);
		ch=fgetc(fp1);
	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
