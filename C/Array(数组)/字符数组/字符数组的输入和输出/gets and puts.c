// puts and gets // << putstring and getstring >>

#include<stdio.h>  // puts �� gets ���������ڱ�׼������������ڵ� ����includeͷ�ļ�string.h

// puts������һ����ʽΪ puts(�ַ�������)
// gets������һ����ʽΪ gets(�ַ�������)  
  
int main()
{
	char str1[15]={"Hello world"};
	puts(str1);  // ����puts���ʱ���ַ���������־'\0'ת����'\n'����������ַ�������
	             // ��Ȼ��\0���𵽽����ַ��������� 
	             // Ҳ����˵puts����ַ������Զ����� 
	             
	char str2[15]={"Hello\0World"}; 
	puts(str2);    //world ���ᱻ��� 
	
	char str3[15];
	gets(str3);  // �����ַ��������ַ����͸��ַ����飬ע���͸����ַ��������Զ���ӵ�'\0'          
	             // gets �����з���ֵ������ ����ֵ���ַ��������ʼ��ַ������һ��Ԫ�صĵ�ַ 
	puts(str3);
	
	return 0;
}
