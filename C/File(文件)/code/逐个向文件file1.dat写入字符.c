#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
	FILE *fp;
	char *filename=(char *)malloc(sizeof(char)*SIZE); //也可以用字符数组，这样就不用malloc 
	printf("Please input the filename you want to use：\n");
	gets(filename);
	
//	scanf("%s", filename); // 注意:scanf输入字符串时 遇到空格字符串会被截断 
// 因此输入的文件路径及文件名中不能含有空格！ 

	if((fp = fopen(filename, "w")) == NULL) //打开文件 
	{
		printf("Cannot open this file!\n");
		exit(0);
	} 
	
	printf("Please input the string you want to store:\n"); //输入 I am Groot 
	int ch;
	ch = getchar(); //接收从键盘输入的第一个字符 
	while(ch != '\n')
	{
		fputc(ch,fp);
		ch = getchar();
	} 
	fclose(fp); //关闭文件 
	
	return 0;
} 
