#include<stdio.h>

struct student
{
	int num;
	char name[10];
	float score;
}; 

int main()
{
	int n,i,j;
	printf("Please input the number of the students:\n"); // ����ѧ������ 
	scanf("%d",&n);
	struct student stu[n];
	printf("Please input the information of the students:\n");
	
	for(i=0;i<n;i++) //����ѧ����Ϣ�����Գɼ� 
	{
		scanf("%d",&stu[i].num);
		scanf("%s",stu[i].name);
		scanf("%f",&stu[i].score);
	}
	
	for(i=0;i<n-1;i++)  // ��ѧ���ɼ���������ѡ�����򷨣� 
	  for(j=i+1;j<n;j++)
	  {
	  	struct student temp;
	  	if(stu[i].score<stu[j].score)
	  	temp=stu[i],stu[i]=stu[j],stu[j]=temp; // ͬ���͵Ľṹ�����֮������໥��ֵ 
	  }
	
	printf("\nThe order is:\n"); // ��ӡѧ���ɼ��� 
	for(i=0;i<n;i++)
	printf("%8d%8s%7.2f\n",stu[i].num,stu[i].name,stu[i].score);
	
	return 0;
}
