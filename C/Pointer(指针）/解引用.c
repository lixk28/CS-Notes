#include<stdio.h>

int main()
{
	int i=1;
	int *p;
	*p=i;  
	printf("%d",*p); // 没有给指针变量 p 初始化，即不知道 p 的指向 
	
	return 0;
}
// 如果要使用指针变量的解引用运算的时候，一定要给指针变量赋值 
// * 解引用运算符运算过程： 先取出指针变量存储的地址值，在根据这个地址值取出该地址对应的内存单元中的值 
