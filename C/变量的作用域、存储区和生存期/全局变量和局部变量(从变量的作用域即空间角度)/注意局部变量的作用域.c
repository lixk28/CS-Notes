#include<stdio.h>

int main()
{
    int i;
    for(i=0;i<10;i++)
    {
    	int j;
    	for(j=0;j<5;j++)
    	  j=j+2;
	}
    printf("%d\n",j);  // ���뱨����Ϊj��forѭ�����еľֲ����� 
	
	return 0;
} 
