#include<stdio.h>
struct student{
	char name[10];
	float score[3];
	float average;
};
void aver(struct student stu[],int n);

int main()
{
	// <1> �ṹ������ĳ�Ա����������
	// �÷�����ͨ������ʵ����һ���ģ�����ֵ���ݵ���ʽ
	
	// <2> �ṹ�������ʵ�Σ������ã���Ϊ��Ҫռ�õ��ڴ�ռ�ϴ� 
	// �ýṹ�������ʵ��ʱ����ȡ��Ҳ��ֵ���ݵķ�ʽ
	// ���ṹ�������ռ���ڴ浥Ԫ������ȫ����˳�򴫵ݸ��βΣ��β�Ҳ������ͬ���͵Ľṹ����� 
     
    // <3> ָ�� �ṹ�����(������Ԫ��) ��ָ����ʵ�� (Ҳ�����ýṹ�����͵�������)
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
