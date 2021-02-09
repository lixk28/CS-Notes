#include<stdio.h>

// 定义返回指针值的函数的一般形式为：
// 类型名 *函数名(形参表列);
// 上面的类型名指的是函数返回的指针值所指向变量的类型
int *search(int a[][5],int n);

int main()
{
	int num[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	int n;
	scanf("%d",&n);
	printf("%d",*(search(num,n)));
		
	return 0;
}

int *search(int a[][5],int n)
{
	return *(a+(n-1)/5)+(n-1)%5;
}
