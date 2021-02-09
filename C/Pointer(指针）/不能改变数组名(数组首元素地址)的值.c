#include<stdio.h>

int main()
{
	int a[10];
	int i;
	for(i=0;i<10;i++)
	a[i]=i+1;
	for(i=0;i<10;i++)
	printf("%d ",*a++); // 编译时报错，因为a是数组的初始地址，不能改变它的值 ！！！ 
	
	return 0;
}
