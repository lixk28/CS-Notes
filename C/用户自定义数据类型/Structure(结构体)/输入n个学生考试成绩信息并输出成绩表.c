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
	printf("Please input the number of the students:\n"); // 输入学生个数 
	scanf("%d",&n);
	struct student stu[n];
	printf("Please input the information of the students:\n");
	
	for(i=0;i<n;i++) //输入学生信息及考试成绩 
	{
		scanf("%d",&stu[i].num);
		scanf("%s",stu[i].name);
		scanf("%f",&stu[i].score);
	}
	
	for(i=0;i<n-1;i++)  // 将学生成绩进行排序（选择排序法） 
	  for(j=i+1;j<n;j++)
	  {
	  	struct student temp;
	  	if(stu[i].score<stu[j].score)
	  	temp=stu[i],stu[i]=stu[j],stu[j]=temp; // 同类型的结构体变量之间可以相互赋值 
	  }
	
	printf("\nThe order is:\n"); // 打印学生成绩表 
	for(i=0;i<n;i++)
	printf("%8d%8s%7.2f\n",stu[i].num,stu[i].name,stu[i].score);
	
	return 0;
}
