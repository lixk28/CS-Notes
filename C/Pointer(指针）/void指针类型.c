#include<stdio.h>
#include<stdlib.h>
 
// C99 允许使用基类型为void的指针类型，可以定义一个基类型为void的指针变量
//*** 注意：void类型指针变量不能理解为可以指向任何类型的数据
//***       void类型指针变量应理解为 指向空类型 或 不指向某一确定类型 的数据 
//***       void类型指针变量不指向任何一种具体类型的数据，只提供一个纯地址 

int main()
{
	//<1> 将void类型指针值赋给另一指针变量时由系统对它进行类型转换，使之适合于被赋值的变量的类型
	// 比如说malloc函数的返回值就是 void * 类型 
	int *p1=malloc(sizeof(int)*10);
	free(p1);
	
	int a=1;
	int *p2=&a;
	void *p3;
	int *p4;
	p3=(void *)p2; 
	p4=p3;  // 自动进行类型转换 
	printf("%d\n",*p4);
	
	//<2> 将其他类型的指针值赋给void类型指针变量时，必须要在指针值前加上强制类型转换符
	void *p5; 
	int *p6=&a;
	p5=(void *)p6;
	
	//<3> 不能对void型指针变量解引用，因为它是无指向的，只可以保存一个纯地址
	void *p7;
	p7=&a; 
//	p7++;  //不同编译器处理不同  因为void指针指向类型不确定 所以在做运算时 p+i 即 p+i*sizeof(?)不能确定字节数
           // GNU 把sizeof(void)当做sizeof(char)处理 
//	printf("%d\n",*p7); //compile error
	
	// 但可以先对其进行类型转换，再解引用
	void *p8;
	p8=&a;
	printf("%d\n",*(int *)p8); 
	
	return 0;
}
