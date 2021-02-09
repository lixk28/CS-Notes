#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

/* 利用stdin、stdout作为fgets、fputs函数参数来替代gets和puts */
 
int main()
{
	char str[MAX_SIZE]={'\0'};
	printf("Please input the string:\n");
	fgets(str,MAX_SIZE,stdin);  //从键盘读入字符串 
	printf("The string is:\n");
	fputs(str,stdout);  //向显示器输出字符串 
	
	return 0;
} 
