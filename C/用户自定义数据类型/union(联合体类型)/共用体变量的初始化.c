#include<stdio.h>

int main()
{ 
	union data
	{
    	int n;
    	char ch;
    	float f;
	}a={1,'A',1.0};  //����ͬʱ�Զ����Ա��ʼ������Ϊ����ռ��ͬһ���ڴ浥Ԫ

	union data b={1}; //��ȷ���Ե�һ����Ա��ʼ��

	union data c={.ch='A'}; //C99�����ָ����һ����Ա��ʼ��
	
	return 0;
}
