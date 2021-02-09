#include<stdio.h>
void Selection_Sort(int array[],int n);

int main()
{
	int i,n;
	printf("Please input the length of the array:\n"); //�������鳤�� 
	scanf("%d",&n);
	int a[n];
	printf("Please input the elements of the array:\n"); //��������Ԫ�� 
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	printf("\n");
	  
	printf("The original array:\n"); //���δ��������� 
	for(i=0;i<n;i++)
	  printf("%d ",a[i]);
	printf("\n");
	  
	Selection_Sort(a,n);
	printf("The sorted array(in ascending order):\n"); //������������� 
	for(i=0;i<n;i++)
	  printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}

void Selection_Sort(int array[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++) // ��flag����i�� 
      for(j=i+1;j<n;j++) //����flag����� 
	    if(array[j]<array[i]) // ���б�array[i]С��Ԫ����array[i]��array[j]����λ�� 
	      temp=array[i],array[i]=array[j],array[j]=temp; 
}
