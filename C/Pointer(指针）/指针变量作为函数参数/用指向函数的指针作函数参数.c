#include<stdio.h>

// ָ������ָ�������һ����Ҫ��;�ǰѺ�������ڵ�ַ��Ϊ�������ݵ���������  
// �����ڸú����оͿ���ͨ����ڵ�ַ������������
// �������ĺô��ǿ��Խṹ��������ƣ����Ե���ͬһ���͵ĺ��� 

void fun(int a,int b,int (*p)(int,int));

int add(int a,int b);
int minus(int a,int b);
int product(int a,int b);
int divide(int a,int b);

int main()
{
	int a,b,n;
	printf("Please input two integers:\n");
	scanf("%d %d",&a,&b);
	printf("Please choose 1,2,3 or 4:\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:fun(a,b,add);break;
		case 2:fun(a,b,minus);break;
		case 3:fun(a,b,product);break;
		case 4:fun(a,b,divide);break;
		default:printf("Invalid input!\n");
	}
	
	return 0;
} 

void fun(int a,int b,int (*p)(int,int))
{
	int result;
	result=(*p)(a,b);
	printf("%d\n",result);
}

int add(int a,int b)
{
	printf("a+b=");
	return a+b;
}

int minus(int a,int b)
{
	printf("a-b=");
	return a-b;
}

int product(int a,int b)
{
	printf("axb=");
	return a*b;
}

int divide(int a,int b)
{
	printf("a/b=");
	return a/b;
}
