/* 求n名学生的平均成绩 */
#include<stdio.h>
float average(float array[],int n);

int main()
{
	int n,i;
	printf("Please input the number of the students:\n");
	scanf("%d",&n);
	float score[n],aver;
	printf("Please input the scores:\n");
	for(i=0;i<n;i++)
	  scanf("%f",&score[i]);
	aver=average(score,n);
	printf("The average grade of the class is:%5.2f",aver);
	
	return 0;
}
float average(float array[],int n)
{
	int i;
	float sum=0,average;
	for(i=0;i<n;i++)
	sum+=*array++;
	average=sum/n;
	return average;
} 
