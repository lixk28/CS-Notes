#include<stdio.h>

int main()
{
	int a=10;
	char str1[a];  // 编译时不报错 
	
	int b=10;
	char str2[b]={'\0'}; // 编译时报错 
	
	//***** 在C中，使用变量定义数组的长度时，不可在定义的同时进行初始化赋值，需要在之后进行赋值 
	
	char matrix[5][10];
	int i;
	for(i=0;i<5;i++)
	scanf("%s",matrix[i]); //对二维字符数组，可以按行输入字符串 
	for(i=0;i<5;i++)
	printf("%s",matrix[i]);  //对二维字符数组，可以按行输出 
	
	return 0;
}
