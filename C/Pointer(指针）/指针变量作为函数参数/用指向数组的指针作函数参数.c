#include<stdio.h>
void search(float (*p)[4],int n);

int main()
{
	int n,i,j;
	printf("Please input the number of the students:\n");
	scanf("%d",&n);
	float score[n][4];
	printf("Please input the scores of the students:\n");
	for(i=0;i<n;i++)
	  for(j=0;j<4;j++)
	    scanf("%f",&score[i][j]);
	search(score,n);
	
	return 0;
} 

void search(float (*p)[4],int n)
{
	int i,j,counter;
	for(i=0;i<n;i++)
	{
		counter=0;
		for(j=0;j<4;j++)
		  if(*(*(p+i)+j) < 60) counter++;
		if(counter >= 1)
	   	{
		  printf("Student No.%d failed, his/her score are:\n",i+1);
		  for(j=0;j<4;j++)
		    printf("%5.1f",*(*(p+i)+j));
	      printf("\n");
	    }
	}
}
