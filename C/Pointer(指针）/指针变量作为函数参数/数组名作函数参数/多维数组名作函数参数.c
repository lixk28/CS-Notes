// �����ö�ά��������Ϊ�������βκ�ʵ��
// �ڱ����ú����ж��β����鶨��ʱ����ָ��ÿһά�Ĵ�С��Ҳ����ʡ�Ե�һά�Ĵ�С
//*** ����ע�⣺���ܰѵڶ�ά�Լ�������ά�Ĵ�Сʡ�ԣ�Ҳ���ǳ��˵�һά��С������ά��С������ʡ��

// �ڵڶ�ά��С��ͬ��ǰ���£��β�����ĵ�һά������ʵ�����鲻ͬ
// ��ΪC���Ա���ϵͳ��������һά�Ĵ�С��д��д��û��ϵ  

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


