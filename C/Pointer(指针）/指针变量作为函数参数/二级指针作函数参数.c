/* ����ָ������������ */
#include<stdio.h>

//*** �����봫��һ��ʵ�ε�һ�������У������ı�������ʹ�õĻ�����Ҫ����: 
// (1) ��ı� int a ��ֵ��Ҫ���� a �ĵ�ַ &a��a��ָ�룩��ֵ
// (2) ��ı� int *a ָ������ݣ���Ҫ���� &a������ָ���ָ�룩

//*** Ҳ����˵�ں������㲻��ͨ���ı��βε�ֵ���ı�ʵ�ε�ֵ 
//*** ���ǿ��Լ�Ӵ���ʵ�εĵ�ַ��ͨ���õ�ַ�ں������ҵ�����ʵ�ε��ڴ浥Ԫ���޸��ڴ浥Ԫ�е�ֵ�������ı�ʵ�ε�ֵ

// ���ʵ����һ��ָ���������ô��������ָ�룬ͨ�����ָ���޸�ʵ��
// Ҳ���ǿ��Դﵽ�޸�ʵ�ε�ָ���Ŀ��
// ��������������������ݽṹ���кܹ㷺��Ӧ�� 

void change1(int *a,int value);
void change2(int **a,int value);

int main()
{
	int num,value;
	printf("Please input integer and the value you want to change to\n");
	printf("num:");
	scanf("%d",&num);
	printf("value:");
	scanf("%d",&value);
	
	int *p=&num; 
	
	change1(p,value);
	printf("num after change 1 = %d\n",*p);
	
	change2(&p,value);
	printf("num after change 2 = %d\n",*p);
	
	return 0;
} 

void change1(int *p, int value)
{
	p=&value; //�ı�����β�p��ֵ����û�иı�ʵ��p��ֵ 
}

void change2(int **p,int value)
{
	*p=&value; //ͨ������ָ�룬�ı���ָ��p��ָ�򣬴Ӷ��ı���p��ָ���ڴ浥Ԫ��ֵ 
}
