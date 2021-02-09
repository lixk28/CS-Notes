/* 结构体类型变量的定义 */ 
//建立结构体类型之后，系统并不会对其分配内存
//要在程序中使用结构体类型的数据，应当先定义结构体类型的变量，并在其中存放具体的数据 

#include<stdio.h>

int main()
{
	/*** <1> 先声明结构体类型，再定义该类型的变量 ***/
	// 一般形式为：结构体类型名 结构体变量名
	//*****注意：不是用结构体名!!!!! 
	struct Student{
		int num;
		char name[10];
		char sex;
		int age;
		float score;
	}; 
	struct Student student1,student2; //正确 
	// Student student1,student2; //错误 
	
	/*** <2> 在声明类型的同时定义变量 ***/
	// 一般形式为：
	//            struct 结构体名{ 
	//               成员表列 
	//              } 变量名表列;  
	
	//***** 注意：变量名可以是一个，也可以同时定义多个变量并用逗号分隔开
	//***** 注意：此时花括号后面不要再加分号，分号添在变量名表列的后面 
	struct Date{
		int month;
		int day;
		int year;
	} birthday; 
	
	/**** <3> 不指定结构体名而直接定义结构体类型变量 ***/
	struct{
		int num;
	}a;
	// 这个结构体类型没有名字，不能再以此结构体类型去定义其他变量 (用的极少) 
	
	//结构体类型中的成员名可以与程序中的变量名相同，但二者不代表同一对象，互不干扰
	struct num{
		int num;
	}num;

	return 0;
} 
