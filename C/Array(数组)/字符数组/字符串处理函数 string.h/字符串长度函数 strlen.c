/* 字符串长度函数 strlen (STRing LENgth) */

// 一般形式为 strlen(字符数组) // 
#include<stdio.h>
#include<string.h>

int main()
{
	char str[15]={"I am Groot"};
	printf("%d\n",strlen(str));  //函数值为字符串的实际长度，不包括 '\0' !!! 
	
	printf("%d\n",strlen("Hello World")); // 也可以用来直接检测字符串常量的长度 
	
	char test_str[10]={'\0','a','b','c','d','e','f','g','h','\0'};
	printf("%d\n",strlen(test_str)); // strlen从第一个不为 \0 的字符开始计数，到第一个 \0 字符结束 
	
	return 0;
} 
