#include<stdio.h>

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int *p[] = {a+2, a+4, a, a+1, a+3};
	int **pp = p; //ʹ����ָ��ppָ��ָ������p����Ԫ�� 
	printf("%d ", **pp++); //�ȼ��� **(pp++) 
	printf("%d ", ++**pp); //�ȼ��� ++(**pp) 
	printf("%d ", **++pp); //�ȼ���**(++pp) 
 
	return 0;
} 
