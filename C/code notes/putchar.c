#include<stdio.h>

int main()
{
	char a,b,c;
	a=getchar();
	b=getchar();
	c=getchar();
	
	putchar('\n');
	putchar(a);
	putchar(b);
	putchar(c);
	putchar('\n');
	
	printf("%c",getchar());
	
	return 0;
 } 
 /* 
    不要再输入一个字母后就按回车键  getchar也可以输出控制字符 如回车等 
    
    也可在printf函数红输出刚接收的字符
*/ 
