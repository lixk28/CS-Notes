#include<stdio.h>
#include<string.h>

int main()
{
	// first in first 
	// strlen�Ǻ�������sizeof�������������
	 
	char str[]="I am Groot";
	
	printf("%d %d\n",strlen(str),sizeof(str)/sizeof(char));
	
	// strlen�������ص����ַ�����ʵ�ʳ��ȣ�������'\0'��
	// sizeof��������ص��������ڱ��ʽ������������������ռ�õ��ֽ�����'\0'Ҳռ���ֽڣ� 
	
	return 0;
}
