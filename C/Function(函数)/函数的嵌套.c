// ������Ƕ�� 
#include<stdio.h>
int max4(int a,int b,int c,int d);
int max2(int x,int y);

int main()
{
	int a,b,c,d;
	printf("Input four integers:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	printf("max=%d",max4(a,b,c,d));
	
	return 0;
}

int max2(int x,int y) // max2��������max4����Ҳ�ǿ��Ե� ˳������ν 
{
	return x>y? x:y;
}

int max4(int a,int b,int c,int d)
{
	int max2(int a,int b);  // ����һ������ʱ���Ҫ������һ������ Ҫ�������� 
	// �����Ҫ���õĺ��������������ǰ�棬�����ǿ���ʡ�Ե� 
	int m;                 
	m=max2(a,b);  //��������д�� return max2(max2(max2(a,b),c),d); �����õ�����m 
	m=max2(m,c);
	m=max2(m,d);
	return m;
}

