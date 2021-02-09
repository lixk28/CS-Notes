#include<stdio.h>

// 如果在程序中定义了一个函数，在编译时会吧函数的源代码转换为可执行代码并存储在代码区
// 这段内存空间有一个起始地址，也称为函数的入口地址
//*** 函数名代表函数的起始地址，就是函数的指针 
int max(int a, int b, int c);
int assist(int a, int b);

int main()
{
	// 指向函数的指针变量
	// 一般定义形式： 函数返回值类型 (*指针变量名)(各个形参的类型);
	// 表示定义了一个指针变量  指向 上述返回值类型及形参类型（形参个数也要相同）的函数 
	int (*p)(int, int, int);
	
	// 如果想调用一个函数，除了可以通过函数名调用以外，还可以通过指向函数的指针变量间接调用
	int a,b,c;
	p=max; // 要把函数的指针（入口地址）即函数名赋给指针变量 
	printf("Please input three integers:\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("the max of a,b,c is %d\n",(*p)(a,b,c)); // 注意是用 *p 代替函数名，不能写成 p(a,b,c) 
	printf("the max of a,b,c is %d\n",max(a,b,c));
	
	// 注意：对指向函数的指针变量不能进行算术运算，因为毫无意义 
	
	return 0;
} 

int assist(int a, int b)
{
	return a>b? a: b;
}

int max(int a, int b, int c)
{
	int assist(int a, int b);
	return assist(a,b)>c? assist(a,b): c;
}

