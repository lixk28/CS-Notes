/* 字符数组的定义 */
#include<stdio.h>

int main()
{
	char c1[10];
	int c2[10]; // 字符型数据是以ASCII码形式存放的，因此也可以用整型数组存放字符型数据 
	c1[0]='c'; 
	c2[0]='c';
	printf("%c\n",c1[0]); 
	printf("%c %d",c2[0],c2[0]); //输出时同char变量  可以以字符也可以以整型输出
	
	return 0;
} 
