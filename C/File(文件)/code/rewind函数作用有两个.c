#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int main()
{
	/* 将一个字符串输出到file7.dat */ 
	FILE *fp1, *fp2;
	if( (fp1=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(文件)\\test_file\\file7.dat","r+")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);	
	} 
	printf("Plesae input a string:\n");
	char str[MAX_SIZE]={'\0'};
	gets(str);
	
	fputs(str,fp1);
	
//	rewind(fp1); //这一句不能省略，file7.dat写入字符串后读写位置标记已经指向最后一个字符的后面 

	/*  将file7.dat的内容复制到file8.dat */ 
	if( (fp2=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(文件)\\test_file\\file8.dat","w")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	} 
	int ch;
	ch=fgetc(fp1);
	while(!feof(fp1)) //也可以写成 while(ch!=EOF) 
	{
		fputc(ch,fp2);
		ch=fgetc(fp1);
	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
