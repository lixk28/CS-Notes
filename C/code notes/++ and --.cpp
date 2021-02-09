#include <stdio.h>

int main()
{
	char a = 'a';
	int x = (a % 10)++;
	printf("%d\n", x);
}
//自增自减运算符是单目运算符  只能作用于变量  常量和表达式都不能这么写 
