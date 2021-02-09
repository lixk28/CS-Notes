// 可以用多维数组名作为函数的形参和实参
// 在被调用函数中对形参数组定义时可以指定每一维的大小，也可以省略第一维的大小
//*** 但是注意：不能把第二维以及其他高维的大小省略，也就是除了第一维大小，其他维大小都不能省略

// 在第二维大小相同的前提下，形参数组的第一维可以与实参数组不同
// 因为C语言编译系统并不检查第一维的大小，写不写都没关系  

#include<stdio.h>

int m,n;
int max(int matrix[][n]);

int main()
{
	int matrix[m][n];
	printf("Please input the rows and columns of the matrix:\n");
	scanf("%d %d",&m,&n);
	int i,j;
	printf("Please input the elements in matrix:\n");
	for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
	    scanf("%d",&matrix[i][j]);
	printf("Max value is %d\n",max(matrix));
	
	return 0;
}

int max(int matrix[][n])
{
	int i,j,max;
	max=matrix[0][0];
	for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
	    if(matrix[i][j] > max)
	      max=matrix[i][j];
	return max;
}


