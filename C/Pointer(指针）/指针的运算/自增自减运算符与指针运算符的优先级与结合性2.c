#include<stdio.h>

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int *p[] = {a+2, a+4, a, a+1, a+3};
	int **pp = p; //使二级指针pp指向指针数组p的首元素 
	printf("%d ", **pp++); //等价于 **(pp++) 
	printf("%d ", ++**pp); //等价于 ++(**pp) 
	printf("%d ", **++pp); //等价于**(++pp) 
 
	return 0;
} 
