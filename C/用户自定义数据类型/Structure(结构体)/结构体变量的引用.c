/* �ṹ����������� */ 
#include<stdio.h>

int main()
{
	struct Student{
		char school[10];
		int num;
		char name[10];
		char sex;
		char major[10];
		char address[30];
	}me1={"��ɽ��ѧ",19335109,"��ѩ��",'M',"�����","����ʡ�����ض�����ѧ"};

    // ���ýṹ�������һ�㷽ʽΪ: �ṹ�������.��Ա�� 
	// ��Ա����� . �����е�����������ȼ���� 
	// ��ʵ���԰�  (�ṹ�������.��Ա��) ����һ�������������൱��һ������ 
	printf("ѧУ��%s\n",me1.school);
	printf("ѧ�ţ�%d\n",me1.num);
	printf("������%s\n",me1.name);
	printf("�Ա�%c\n",me1.sex);
	printf("רҵ��%s\n",me1.major);
	printf("��ͥ��ַ��%s\n",me1.address);
	
	//(1) ������ͼͨ���ṹ�������������ṹ��������г�Ա��ֵ
	//    ֻ�ܶԽṹ������еĸ�����Ա�ֱ������������ 
	// printf("%s",me);  д���Ǵ���� 
	 
	//(2) �����Ա����������һ���ṹ�����ͣ���Ҫ�����ɸ���Ա�������һ��һ�����ҵ����һ���ĳ�Ա
	//    ֻ�ܶ���ͼ��ĳ�Ա���и�ֵ���ȡ�Լ�����
	struct Date{
		int month;
		int day;
		int year;
	};
    struct my_birthday{
    	struct Date birthday;
	}me2;
	me2.birthday.month=10;
	me2.birthday.day=25;
	me2.birthday.year=2001;
	printf("My birthday is %d %d %d\n",me2.birthday.month,me2.birthday.day,me2.birthday.year);
	
	//(3) �Խṹ������ĳ�Ա��������ͨ����һ����������(���������;������Խ��е�����) 
	
	//***(4) ͬ���� �Ľṹ����������໥��ֵ
	struct Student student1,student2;
	student1=student2; 
	
	//(5) �������ýṹ�������Ա�ĵ�ַ��Ҳ�������ýṹ������ĵ�ַ 
	printf("%d %d ",&me1,&me2);
	printf("%d",&me2.birthday);
	
	return 0;
} 
