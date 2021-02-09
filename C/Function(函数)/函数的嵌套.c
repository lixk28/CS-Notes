// 函数的嵌套 
#include<stdio.h>
int max4(int a,int b,int c,int d);
int max2(int x,int y);

int main()
{
	int a,b,c,d;
	printf("Input four integers:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	printf("max=%d",max4(a,b,c,d));
	
	return 0;
}

int max2(int x,int y) // max2函数放在max4后面也是可以的 顺序无所谓 
{
	return x>y? x:y;
}

int max4(int a,int b,int c,int d)
{
	int max2(int a,int b);  // 定义一个函数时如果要调用另一个函数 要事先声明 
	// 如果需要调用的函数在这个函数的前面，声明是可以省略的 
	int m;                 
	m=max2(a,b);  //甚至可以写成 return max2(max2(max2(a,b),c),d); 而不用到变量m 
	m=max2(m,c);
	m=max2(m,d);
	return m;
}

