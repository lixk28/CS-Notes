#include<stdio.h>
#include<stdlib.h>

typedef struct Student{
	int num; //学号 
	char name[20]; //姓名 
	char sex; //性别 
	int age; //年龄 
}Student;

void save(int n,Student students[]);

void read(int n,Student students[]);

int main()
{
	int n; 
	printf("Please input the number of the students:\n");
	scanf("%d",&n);
	Student students[n];
	
	int i;
	printf("Please input the information of the students:\n");
	for(i=0;i<n;i++)
		scanf("%d %s %c %d",&students[i].num,students[i].name,&students[i].sex,&students[i].age);
	
	save(n,students);
	printf("The information has been saved in file students.dat\n\n");
	
	printf("The information in file students.dat is:\n");
	read(n,students);
	
	return 0;
}

void save(int n,Student students[])
{
	FILE *fp;
	if( (fp=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(文件)\\test_file\\students.dat","wb")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	
	int i;
	for(i=0;i<n;i++)
		fwrite(&students[i],sizeof(Student),1,fp);
	fclose(fp);
}

void read(int n,Student students[])
{
	FILE *fp;
	if( (fp=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(文件)\\test_file\\students.dat","rb")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	
	Student temp[n];
	int i;
	for(i=0;i<n;i++)
	{
		fread(&temp[i],sizeof(Student),1,fp);
		printf("%-10d %-10s %c %4d\n",temp[i].num,temp[i].name,temp[i].sex,temp[i].age);
	}
	fclose(fp);
}
