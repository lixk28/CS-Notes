/* �ַ������Ⱥ��� strlen (STRing LENgth) */

// һ����ʽΪ strlen(�ַ�����) // 
#include<stdio.h>
#include<string.h>

int main()
{
	char str[15]={"I am Groot"};
	printf("%d\n",strlen(str));  //����ֵΪ�ַ�����ʵ�ʳ��ȣ������� '\0' !!! 
	
	printf("%d\n",strlen("Hello World")); // Ҳ��������ֱ�Ӽ���ַ��������ĳ��� 
	
	char test_str[10]={'\0','a','b','c','d','e','f','g','h','\0'};
	printf("%d\n",strlen(test_str)); // strlen�ӵ�һ����Ϊ \0 ���ַ���ʼ����������һ�� \0 �ַ����� 
	
	return 0;
} 
