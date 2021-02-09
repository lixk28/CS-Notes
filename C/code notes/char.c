#include<stdio.h>

int main()
{
	char a,b,c;
	int d;
	
	a=getchar();
	b=getchar();
	c=getchar();
	
	d=a+b+c;
	
	printf("%d",d);
	
	return 0;
} 
/*  字符变量也可直接用来做加减乘除运算
    运算的时候是以它们的ASCII码形式进行的
 
    char类型变量即字符变量是  不可以 将字符串赋值给它的  只能用单个字符或者是整数或者是字符常量
	例如 a=65 或 a=‘A’  
*/	  
