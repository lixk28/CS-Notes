#include<stdio.h>

int main()
{
	int a[10];
	int i,j,m;
	
	printf("Please input 10 numbers:\n");
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	printf("\n");
	
	for(i=0;i<9;i++) // ����9��ѭ��������9�˱Ƚ� 
	{
		for(j=0;j<9-i;j++) // ÿһ���н���9-j�αȽ� 
		{
			if(a[j]>a[j+1]) // �Ƚ����ڵ������� 
			m=a[j],a[j]=a[j+1],a[j+1]=m; // �������������������� 
		}
	}
	
	printf("The sorted numbers (in ascending order):\n");
	for(i=0;i<10;i++)
    printf("%4d",a[i]);
    printf("\n");
	
	return 0;
}
