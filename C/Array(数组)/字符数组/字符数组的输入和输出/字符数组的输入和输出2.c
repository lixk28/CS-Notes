#include<stdio.h>

int main()
{
	int a=10;
	char str1[a];  // ����ʱ������ 
	
	int b=10;
	char str2[b]={'\0'}; // ����ʱ���� 
	
	//***** ��C�У�ʹ�ñ�����������ĳ���ʱ�������ڶ����ͬʱ���г�ʼ����ֵ����Ҫ��֮����и�ֵ 
	
	char matrix[5][10];
	int i;
	for(i=0;i<5;i++)
	scanf("%s",matrix[i]); //�Զ�ά�ַ����飬���԰��������ַ��� 
	for(i=0;i<5;i++)
	printf("%s",matrix[i]);  //�Զ�ά�ַ����飬���԰������ 
	
	return 0;
}
