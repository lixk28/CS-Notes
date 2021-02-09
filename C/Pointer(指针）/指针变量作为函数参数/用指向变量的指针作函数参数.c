#include<stdio.h>
void swap1(int *p1,int *p2); //ע�� ���������ǿպ��� û�з���ֵ 
void swap2(int *p1,int *p2);
void swap3(int a,int b);

int main()
{ 
	int a,b;
	int *p1,*p2;
	printf("Please input two integers:");
	scanf("%d %d",&a,&b);
	p1=&a,p2=&b;
	printf("\n");
	
	if(a<b) swap3(a,b);
	{
	  printf("The result under the execution of function swap3: ");
	  printf("max=%d min=%d\n",a,b);
    }
	
	if(a<b) swap2(p1,p2);
	{
	  printf("The result under the execution of function swap2: ");
	  printf("max=%d min=%d\n",*p1,*p2);
    }
	if(a<b) swap1(p1,p2);
	{
	  printf("The result under the execution of function swap1: ");
	  printf("max=%d min=%d\n",*p1,*p2);
    }
    
	return 0;
}

void swap1(int *p1,int *p2) //*** ������ͨ��ִ�е��ú������ı�ʵ��ָ�������ֵ *** 
{                           //*** ���ǿ����ں����иı�ʵ��ָ�������ָ������ֵ *** 
	int temp;               // Ҳ����˵ * ָ��������ǹ�ͨ�û��Զ��庯����main����֮������� 
	temp=*p1;               // p1��p2���βΣ�����*p1��*p2�����βΣ����� *p1��*p2ֱ��ָ��a��b 
	*p1=*p2;                // pass-by-reference  ͨ����ַ������ 
	*p2=temp;
}

void swap2(int *p1,int *p2) 
{
	int *temp;  // ��ͼͨ������p1��p2��ָ��������a��b��ֵ 
	temp=p1;    
	p1=p2;
	p2=temp;    // �ı�Ľ������βε�ֵ������û��return value��ʵ����ʵ�ε�ֵp1��p2��û�иı� 
}

void swap3(int a,int b)
{
	int temp; // ��swap1���� 
	temp=a;   // pass-by-value
	a=b;
	b=temp;
}
