#include<stdio.h>
int add(int a,int b);
int minus(int a,int b);
int product(int a,int b);
int print_star();

int main()
{
	int a,b;
	printf("Please enter two integers:");
	scanf("%d %d",&a,&b);
	printf("%d\n",add(a,b));  //����ֱ�ӵ�����Ϊ����   �Լ����ʽ����ʽ��һ���� 
	printf("%d\n",product(a,add(a,b)));   //��������Ϊ��һ����������ʱ��ʵ�� 
	printf("%d\n",minus(product(a,b),b));
	print_star();  //�������õ�����Ϊһ����䣬��Ҫ��������ֵ��ֻҪ�������һ���Ĳ��� 
	
	return 0;
}

int print_star()
{
	printf("************\n"); 
}
int add(int a,int b)
{
	int x;
	x=a+b;
	return x;
}
int minus(int a,int b)
{
	int x;
	x=a-b;
	return x;
}
int product(int a,int b)
{
	int x;
	x=a*b;
	return x;
}
 
