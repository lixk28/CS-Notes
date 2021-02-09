#include<stdio.h>

// 一般在需要保留函数上一次调用结束时的值时，用到静态局部变量
 
// 求阶乘 
long long fac(int n);

int main()
{
	int i,n;
	printf("Please input an integer:\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	  printf("%d! = %lld\n",i,fac(i));
	  
	return 0;
}

long long fac(int n)
{
	static long long temp=1;
	temp=temp*n;
	return temp;
}


