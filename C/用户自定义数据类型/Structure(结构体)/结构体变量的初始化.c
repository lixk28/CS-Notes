/* 结构体变量的初始化 */ 
#include<stdio.h>

int main()
{
	// 在定义结构体变量时，可以同时对它初始化 
	struct Student{
		char school[10];
		int num;
		char name[10];
		char sex;
		char major[10];
		char address[30];
	}me={"中山大学",19335109,"李雪堃",'M',"计算机","安徽省东至县东流中学"}; 

    // C99允许对某一成员初始化
	struct Student me={.school="Sun Yet-Sen University"}; 
	
	// 若有成员未被初始化，数值型成员被系统初始化为0，字符型成员初始化为'\0'，指针型成员初始化为NULL 
	
	return 0;
} 
