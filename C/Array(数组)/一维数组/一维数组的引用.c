/* 一维数组的引用 */ 
#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);   
	int a[n]; // C语言不允许对数组的大小做动态定义 
	printf("%d",a[8]);  // ????????????
	int b[1+2],c[2*3]; // 方括号中能够使用常量表达式 包括常量、符号常量、算式 
	
	return 0;
}
