#include<stdio.h>

int main()
{
	int a[10];
	int i,j,m;
	
	printf("Please input 10 numbers:\n");
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	printf("\n");
	
	for(i=0;i<9;i++) // 进行9次循环，共跑9趟比较 
	{
		for(j=0;j<9-i;j++) // 每一趟中进行9-j次比较 
		{
			if(a[j]>a[j+1]) // 比较相邻的两个数 
			m=a[j],a[j]=a[j+1],a[j+1]=m; // 将这两个数的升序排列 
		}
	}
	
	printf("The sorted numbers (in ascending order):\n");
	for(i=0;i<10;i++)
    printf("%4d",a[i]);
    printf("\n");
	
	return 0;
}
