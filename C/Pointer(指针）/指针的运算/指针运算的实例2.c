#include<stdio.h>

int main()
{
	int a = 3;
	int *p = &a;
	
	printf("%d\n", ++*p * *p--); // 注意分析运算符的优先级和结合性 运算是如何进行的 
	
	return 0;
} 
