/* 数组元素的指针 */ 

// 所谓数组元素的指针就是数组元素的地址
 
#include<stdio.h>

int main()
{
	int a[5]={1,2,3,4,5};
	int *p1,*p2;
	
	//*** 在C语言中，一维数组名（不包括形参数组名）代表数组中 首元素 的地址 ***//
	// 数组名 == 数组首元素的地址 
 
    p1=&a[0];
    p2=a;  // 这两条语句是等价的 
    printf("%p\n",p1);
    printf("%p\n",p2);
    
	return 0;
} 
