#include<stdio.h>

int main()
{
	int num[]={1,2,3,4,5};
	char str[]="I am Groot";
	
	printf("%d\n",sizeof(num)/sizeof(int)); // 5
	printf("%d\n",sizeof(str)/sizeof(char));  // 11
	// ע�ⲻ�� 10 ����Ϊ�ַ�������ĩβ�Զ�����'\0' 
	// �����ʵ�ʳ����� 11
	// ʵ����ʹ���ַ�����ʱҲҪ���ǵ���㣬����������������Խ�� 
	
	return 0;
} 
