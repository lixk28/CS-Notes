#include<stdio.h>
struct student{
	char name[10];
	float score[3];
	float average;
};
void aver(struct student stu[],int n);

int main()
{
	// <1> 结构体变量的成员作函数参数
	// 用法和普通变量作实参是一样的，属于值传递的形式
	
	// <2> 结构体变量作实参（很少用，因为需要占用的内存空间较大） 
	// 用结构体变量作实参时，采取的也是值传递的方式
	// 将结构体变量所占的内存单元的内容全部按顺序传递给形参，形参也必须是同类型的结构体变量 
     
    // <3> 指向 结构体变量(或数组元素) 的指针作实参 (也可以用结构体类型的数组名)
	int n,i,j;
	printf("Please input the number of the students:\n");
	scanf("%d",&n);
	struct student stu[n];
	printf("Please input the name and the scores of the students:\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",stu[i].name);
		scanf("%f %f %f",&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
	}
	aver(stu,n);
	
	struct student temp;
	for(i=0;i<n-1;i++)
	  for(j=i+1;j<n;j++)
	  {
	  	if(stu[i].average<stu[j].average)
	  	temp=stu[j],stu[j]=stu[i],stu[i]=temp;
	  }
    
    printf("name        score1      score2      score3      average\n");
    for(i=0;i<n;i++)
    printf("%-6s%12.2f%12.2f%12.2f%12.2f\n",stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].average);
    
	return 0;
}

void aver(struct student stu[],int n)
{
	struct student *p=stu;
	int i;
	for(i=0;i<n;i++)
	(p++)->average=(p->score[0]+p->score[1]+p->score[2])/3;
}
