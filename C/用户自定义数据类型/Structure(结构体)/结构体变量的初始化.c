/* �ṹ������ĳ�ʼ�� */ 
#include<stdio.h>

int main()
{
	// �ڶ���ṹ�����ʱ������ͬʱ������ʼ�� 
	struct Student{
		char school[10];
		int num;
		char name[10];
		char sex;
		char major[10];
		char address[30];
	}me={"��ɽ��ѧ",19335109,"��ѩ��",'M',"�����","����ʡ�����ض�����ѧ"}; 

    // C99�����ĳһ��Ա��ʼ��
	struct Student me={.school="Sun Yet-Sen University"}; 
	
	// ���г�Աδ����ʼ������ֵ�ͳ�Ա��ϵͳ��ʼ��Ϊ0���ַ��ͳ�Ա��ʼ��Ϊ'\0'��ָ���ͳ�Ա��ʼ��ΪNULL 
	
	return 0;
} 
