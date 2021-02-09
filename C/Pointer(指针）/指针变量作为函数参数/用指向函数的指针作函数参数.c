#include<stdio.h>

// 指向函数的指针变量的一个重要用途是把函数的入口地址作为参数传递到其他函数  
// 这样在该函数中就可以通过入口地址调用其他函数
// 这样做的好处是可以结构化程序设计，可以调用同一类型的函数 

void fun(int a,int b,int (*p)(int,int));

int add(int a,int b);
int minus(int a,int b);
int product(int a,int b);
int divide(int a,int b);

int main()
{
	int a,b,n;
	printf("Please input two integers:\n");
	scanf("%d %d",&a,&b);
	printf("Please choose 1,2,3 or 4:\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:fun(a,b,add);break;
		case 2:fun(a,b,minus);break;
		case 3:fun(a,b,product);break;
		case 4:fun(a,b,divide);break;
		default:printf("Invalid input!\n");
	}
	
	return 0;
} 

void fun(int a,int b,int (*p)(int,int))
{
	int result;
	result=(*p)(a,b);
	printf("%d\n",result);
}

int add(int a,int b)
{
	printf("a+b=");
	return a+b;
}

int minus(int a,int b)
{
	printf("a-b=");
	return a-b;
}

int product(int a,int b)
{
	printf("axb=");
	return a*b;
}

int divide(int a,int b)
{
	printf("a/b=");
	return a/b;
}
