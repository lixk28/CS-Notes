/* ȫ�ֱ��� (global)*/ 

// �ں����ڶ�����Ǿֲ��������ں����ⶨ�����ȫ�ֱ���
// ȫ�ֱ���Ҳ���ⲿ������ȫ�̱��� 

//*** ȫ�ֱ��������ڱ��ļ��б����к��������� 
//*** ȫ�ֱ����������򣺴Ӷ��������λ�õ���Դ�ļ�����

//��̵ĺ�ϰ��: ��ȫ�ֱ����ĵ�һ����ĸ��д��ʾ 
 
#include<stdio.h>

int a=1,b=2;

int fun1(int a, int b) //ע��:��fun1�в�������c1��c2����Ϊc1,c2��fun1֮ǰδ���� 
{
	return a+b;
}

char c1,c2;

char fun2(char c1, char c2)
{
	return c1>c2? c1:c2;
}
int main()
{
	int p=1,q=2;
	int sum;
	sum=a+b+fun1(p,q);
	printf("%d",sum);
	
	return 0;
} 
