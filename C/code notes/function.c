#include<stdio.h>
int print_star();
int print_message();

int main()
{
	print_star();
	print_message();
	print_star();
	
	return 0;
}
int print_star()
{
	printf("************\n");
}
int print_message()
{
	printf(" I'm Happy!\n");
}
/* 定义函数时指定函数值的类型，即函数返回值的类型
   写函数时要包括 声明 定义 使用 三个部分
 */ 
