#include<stdio.h>

// ����ڳ����ж�����һ���������ڱ���ʱ��ɺ�����Դ����ת��Ϊ��ִ�д��벢�洢�ڴ�����
// ����ڴ�ռ���һ����ʼ��ַ��Ҳ��Ϊ��������ڵ�ַ
//*** ����������������ʼ��ַ�����Ǻ�����ָ�� 
int max(int a, int b, int c);
int assist(int a, int b);

int main()
{
	// ָ������ָ�����
	// һ�㶨����ʽ�� ��������ֵ���� (*ָ�������)(�����βε�����);
	// ��ʾ������һ��ָ�����  ָ�� ��������ֵ���ͼ��β����ͣ��βθ���ҲҪ��ͬ���ĺ��� 
	int (*p)(int, int, int);
	
	// ��������һ�����������˿���ͨ���������������⣬������ͨ��ָ������ָ�������ӵ���
	int a,b,c;
	p=max; // Ҫ�Ѻ�����ָ�루��ڵ�ַ��������������ָ����� 
	printf("Please input three integers:\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("the max of a,b,c is %d\n",(*p)(a,b,c)); // ע������ *p ���溯����������д�� p(a,b,c) 
	printf("the max of a,b,c is %d\n",max(a,b,c));
	
	// ע�⣺��ָ������ָ��������ܽ����������㣬��Ϊ�������� 
	
	return 0;
} 

int assist(int a, int b)
{
	return a>b? a: b;
}

int max(int a, int b, int c)
{
	int assist(int a, int b);
	return assist(a,b)>c? assist(a,b): c;
}

