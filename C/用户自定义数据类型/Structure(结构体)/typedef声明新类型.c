
#include<stdio.h>

int main()
{
	/*** <1> ��һ��������������ԭ�е�������(��int��float��double��) ***/
	// һ����ʽΪ�� typedef ԭ�������� ��������;
	typedef int integer;
	typedef float real;
	typedef char character;
	
	integer i,j; // �ȼ��� int i,j;
	real a,b; // �ȼ��� float a,b;
	character ch1,ch2; // �ȼ��� char ch1,ch2;
	
	/*** <2> ����һ���򵥵����������渴�ӵ����ͱ�ʾ���� ***/
	/* (1) ����һ���µ�����������ṹ������ */ 
	// һ����ʽΪ��typedef struct
	//            {
	//              ��Ա����
    //            } ���������� 
    // ����������Ĳ����������;ʹ���ýṹ������ 
	typedef struct
	{
		int month;
		int day;
		int year;
	} Date;
	
	// Ҳ����д��
	// typedef struct date
	// {
	//    int month;
	//    int day;
	//    int year;
	// } Date; 
    
	Date birthday; // ��Ҫд�� struct Date birthday
	Date *p;
    
	/* <2> ����һ���µ������������������� */
	typedef int num[100]; // ����numΪ���������� 
	num x; // ����aΪ����������������100��Ԫ��
	
	/* <3> ����һ���µ�����������ָ������ */
	typedef char *str; // ����strΪ�ַ�ָ������ 
	str s[15]; // ����sΪ�ַ�ָ������
	
	/* <4> ����һ��������������ָ������ָ������ */ 
	typedef int (* pointer)(); // ����pointerΪָ������ָ�����ͣ��ú�����������ֵ 
	pointer p1,p2; // p1,p2Ϊpointer���͵�ָ����� 
	
	// �ܽ᣺���ǰ��ն�������ķ�ʽ���ѱ���������������������������ǰ�����typedef,��������������������ԭ�������� 
	// ���裺(�ϸ��մ˲���ִ��) 
	// (1) �Ȱ���������ķ���д��������
	// (2) ��������������������
	// (3) ����ǰ�����typedef
	// (4) Ȼ��Ϳ�������������ȥ������� 
	return 0;
}
