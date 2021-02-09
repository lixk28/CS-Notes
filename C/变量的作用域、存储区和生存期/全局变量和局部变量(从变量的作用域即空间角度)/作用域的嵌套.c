#include<stdio.h>

// 当多个作用域互相嵌套时，编译器会优先在内层查找变量，内层查找不到再往外层查找
// 因此，内层的同名变量会隐藏掉（或者遮挡掉）外层的同名变量 

int x = 1;

int main()
{
    int x = 2;
    {
    	int x = 3;
    	printf("%d\n", x);
	}
	printf("%d\n", x);
	
	return 0;
} 
