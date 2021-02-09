#include<stdio.h>
int add(int a,int b);
int minus(int a,int b);
int product(int a,int b);
int print_star();

int main()
{
	int a,b;
	printf("Please enter two integers:");
	scanf("%d %d",&a,&b);
	printf("%d\n",add(a,b));  //函数直接调用作为参数   以及表达式或表达式的一部分 
	printf("%d\n",product(a,add(a,b)));   //函数调用为另一个函数调用时的实参 
	printf("%d\n",minus(product(a,b),b));
	print_star();  //函数调用单独作为一个语句，不要求函数带回值，只要求函数完成一定的操作 
	
	return 0;
}

int print_star()
{
	printf("************\n"); 
}
int add(int a,int b)
{
	int x;
	x=a+b;
	return x;
}
int minus(int a,int b)
{
	int x;
	x=a-b;
	return x;
}
int product(int a,int b)
{
	int x;
	x=a*b;
	return x;
}
 
