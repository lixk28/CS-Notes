/* �ַ������Ӻ��� strcat // (STRing CATenate) */ 

// strcat���������ǰ������ַ���1���ַ���2���������������ŵ��ַ���1��
// һ����ʽΪ��strcat(�ַ�����1,�ַ�����2) 
#include<stdio.h>
#include<string.h> 

int main()
{	 
	char str1[15]={"I am "}; // ע�⣺�ַ�����1Ҫ�㹻�󣬿����������Ӻ�����ַ��� 
	char str2[10]={"Groot"};
	
	printf("%s",strcat(str1,str2)); // ���Ӻ��ַ���1�����\0ȡ�� ֻ���´������0 
	printf("\n");
	
	return 0;
}
