#include<stdio.h>

int main()
{
	// ���������к���
	int m,n;
	printf("Please input row and column:\n");
	scanf("%d %d",&m,&n); 
	
	// �������еĸ�Ԫ�ظ�ֵ 
	int matrix[m][n],counter=1,i,j;
	for(i=0;i<m;i++)
	  for(j=0;j<n;j++,counter++)    
		matrix[i][j]=counter;
	
	// �������	
	int *p=matrix[0]; // ע�ⲻ��д�� int *p=matrix !!! ����ʱ��warning����compile error 
	printf("%dx%d matrix:",m,n); 
	for(p;p<matrix[0]+m*n;p++)
	{
		if((p-matrix[0])%n == 0)
		printf("\n");
		printf("%5d",*p);
	}
	
	return 0;
} 
