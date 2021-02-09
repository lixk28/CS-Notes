// 指针变量的引用(1) //

// & 地址运算符。&a是变量a的地址(指针)
// * 指针运算符/解引用运算符。*p是p所指向的变量 
 
// <1> 给指针变量赋值 // 
/*
#include<stdio.h>

int main()
{
	int *pointer=1; //指针变量中只能存放指针，不能将一个整数赋给一个指针变量 
	// 在程序中是不能用一个数值代表地址的，地址只能用地址符 & 得到并付给一个指针变量 // 
	 
	int *p;
	int a=1;
	p=&a;  // 把p的地址赋给指针变量p 
	
	return 0;
} 
*/

// <2> 引用指针变量 和 指针变量指向的变量 // 

#include<stdio.h>

int main()
{
	int a,b;
	int *p1,*p2; // 这里的 * 只是表示p1、p2是指针变量 
	
    printf("Please input two integers:");
	scanf("%d %d",&a,&b);
	p1=&a,p2=&b; 
	printf("a,b的值分别为：%d %d\n",a,b);
	printf("a,b的值分别为：%d %d\n",*p1,*p2);// 这里的 * 是指针运算符，*p代表指针变量p指向的变量，所以 *p1=a、*p2=b 
	printf("a,b的地址分别为：%p %p\n",p1,p2);// 引用指针变量，输出的 p1、p2 就是变量a、b的地址 
	                                         // 地址要用格式符 %p 输出 (不要用 %x ) 
	                                         // 地址是以 16 进制输出的 
	int *p,num;
	p=&num;
	num=0; // 直接使用变量名  直接访问 
	*p=1; // 使用指针运算符  间接访问 
	printf("%d %d",num,*p);
	
	return 0;
} 

