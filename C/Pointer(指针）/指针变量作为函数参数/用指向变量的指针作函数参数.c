#include<stdio.h>
void swap1(int *p1,int *p2); //注意 这三个都是空函数 没有返回值 
void swap2(int *p1,int *p2);
void swap3(int a,int b);

int main()
{ 
	int a,b;
	int *p1,*p2;
	printf("Please input two integers:");
	scanf("%d %d",&a,&b);
	p1=&a,p2=&b;
	printf("\n");
	
	if(a<b) swap3(a,b);
	{
	  printf("The result under the execution of function swap3: ");
	  printf("max=%d min=%d\n",a,b);
    }
	
	if(a<b) swap2(p1,p2);
	{
	  printf("The result under the execution of function swap2: ");
	  printf("max=%d min=%d\n",*p1,*p2);
    }
	if(a<b) swap1(p1,p2);
	{
	  printf("The result under the execution of function swap1: ");
	  printf("max=%d min=%d\n",*p1,*p2);
    }
    
	return 0;
}

void swap1(int *p1,int *p2) //*** 不可能通过执行调用函数来改变实参指针变量的值 *** 
{                           //*** 但是可以在函数中改变实参指针变量所指变量的值 *** 
	int temp;               // 也就是说 * 指针运算符是沟通用户自定义函数与main函数之间的桥梁 
	temp=*p1;               // p1、p2是形参，但是*p1、*p2不是形参！！！ *p1、*p2直接指向a、b 
	*p1=*p2;                // pass-by-reference  通过地址来传递 
	*p2=temp;
}

void swap2(int *p1,int *p2) 
{
	int *temp;  // 企图通过交换p1、p2的指向来交换a、b的值 
	temp=p1;    
	p1=p2;
	p2=temp;    // 改变的仅仅是形参的值，函数没有return value，实际上实参的值p1、p2并没有改变 
}

void swap3(int a,int b)
{
	int temp; // 与swap1相似 
	temp=a;   // pass-by-value
	a=b;
	b=temp;
}
