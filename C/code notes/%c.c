#include<stdio.h>

int main()
{
	char a,b,c;
	scanf("%c%c%c",&a,&b,&c);
	printf("\n");
	
	printf("%c %c %c\n",a,b,c);
	
	printf("%d %d %d\n",a,b,c);
	
	return 0;
 } 
 /*  
   输入时 用两种方法：a b c（a、b、c之间有一个空格） 
                 以及 abc （a、b、c之间没有空格）
    分别运行程序查看结果           
                 
    对于字符变量 系统会把输入的字符包括空格字符和转义字符中的字符都作为有效字符输入  原封不动的送给声明的变量的地址中储存起来
	
	%d可以将字符变量对应的ASCII码输出
	%c可以将ASCII码对应的字符变量输出 
	
	如果将开始的 char a,b,c 改为 int a,b,c  输出结果是相同的 
	 
*/				  
