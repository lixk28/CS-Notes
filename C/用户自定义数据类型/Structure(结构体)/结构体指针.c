/* �ṹ��ָ�� */
// ��ν�ṹ��ָ�����ָ��ṹ�������ָ��
// һ���ṹ���������ʼ��ַ���Ǹýṹ�������ָ��
 
#include<stdio.h>
#include<string.h>

struct Student
{
	int num;
	char name[10];
	char sex;
	float score;
}me;
 
int main()
{
	// ָ��ṹ������ָ������ȿ�ָ��ṹ��������ֿ�ָ��ṹ�������е�Ԫ��
	// ָ������Ļ����ͱ�����ṹ�������������ͬ 
	
	/*** <1> ָ��ṹ�������ָ�� ***/ 
	struct Student *p1=&me;
	(*p1).num=19335109;
	strcpy((*p1).name,"��ѩ��");
	(*p1).sex='M';
	(*p1).score=100.00;
	printf("No:%d\n",(*p1).num);
	printf("name:%s\n",(*p1).name);
	printf("sex:%c\n",(*p1).sex);
	printf("score:%.2f\n\n",(*p1).score);
	//***** ע�⣺(*p).member �����Ų���ʡ������
	//***** ��Ϊ��Ա����� . �����ȼ����� *  ���ȥ���Ļ����͵ȼ��� *(p.num) ��
	
	// Ϊ��ʹ�÷����ֱ�ۣ�C��������� (*p).member �� p->member ����
	// ->����һ����ͷ��p->member��ʾ p��ָ��Ľṹ������е�member��Ա
	// ->��Ϊָ������� 
	
	// �� p=&structure_name�������ߵȼۣ� (structure_name�ǽṹ���������member�ǳ�Ա��) 
	//(1) structure_name.member
	//(2) (*p).member
	//(3) p->member 
	printf("No:%d\n",p1->num);
	printf("name:%s\n",p1->name);
	printf("sex:%c\n",p1->sex);
	printf("score:%.2f\n\n",p1->score);
	
	/* <2> ָ��ṹ�������ָ�� */
	// ������ָ�����ָ��ṹ�������Ԫ�� ʵ���ϻ���ָ��ṹ����� 
	// ָ��ṹ�������ָ�������������ָ��ṹ���е�ĳһ��Ա 
	struct Student stu[3]={{19335109,"��ѩ��",'M',100},{19335110,"����ǫ",'M',100},{19335111,"������",'M',100}};
	struct Student *p2=stu;
	int i;
	for(i=0;i<3;i++)
	printf("No:%d\nname:%s\nsex:%c\nscore:%.2f\n\n",(p2+i)->num,(p2+i)->name,(p2+i)->sex,(p2+i)->score);
	// ע�⣺p2+iָ����ǽṹ������ĵ� i ��Ԫ�� 
	
	// (++p)->member : ��ʹp�Լ�1��Ȼ��õ�pָ���Ԫ���е�member��Ա��ֵ
	// (p++)->member : ��ʹ��p��ֵ����p->member���õ�member��ֵ������p�Լ�1
	
	return 0;
} 
