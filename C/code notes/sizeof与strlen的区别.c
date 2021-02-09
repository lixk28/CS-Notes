#include<stdio.h>
#include<string.h>

int main()
{
	// first in first 
	// strlen是函数，而sizeof是运算符！！！
	 
	char str[]="I am Groot";
	
	printf("%d %d\n",strlen(str),sizeof(str)/sizeof(char));
	
	// strlen函数返回的是字符串的实际长度（不包含'\0'）
	// sizeof运算符返回的是括号内表达式、变量名或类型名所占用的字节数（'\0'也占用字节） 
	
	return 0;
}
