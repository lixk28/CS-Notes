#include<stdio.h>

int main()
{
	int a = 3;
	int *p = &a;
	
	printf("%d\n", ++*p * *p--); // ע���������������ȼ��ͽ���� ��������ν��е� 
	
	return 0;
} 
