#include<stdio.h>

int main()
{
	// 输入矩阵的行和列
	int m,n;
	printf("Please input row and column:\n");
	scanf("%d %d",&m,&n); 
	
	// 给矩阵中的各元素赋值 
	int matrix[m][n],counter=1,i,j;
	for(i=0;i<m;i++)
	  for(j=0;j<n;j++,counter++)    
		matrix[i][j]=counter;
	
	// 输出矩阵	
	int *p=matrix[0]; // 注意不能写成 int *p=matrix !!! 编译时会warning或者compile error 
	printf("%dx%d matrix:",m,n); 
	for(p;p<matrix[0]+m*n;p++)
	{
		if((p-matrix[0])%n == 0)
		printf("\n");
		printf("%5d",*p);
	}
	
	return 0;
} 
