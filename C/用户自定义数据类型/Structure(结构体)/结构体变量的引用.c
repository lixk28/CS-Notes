/* 结构体变量的引用 */ 
#include<stdio.h>

int main()
{
	struct Student{
		char school[10];
		int num;
		char name[10];
		char sex;
		char major[10];
		char address[30];
	}me1={"中山大学",19335109,"李雪堃",'M',"计算机","安徽省东至县东流中学"};

    // 引用结构体变量的一般方式为: 结构体变量名.成员名 
	// 成员运算符 . 在所有的运算符中优先级最高 
	// 其实可以把  (结构体变量名.成员名) 当成一个整体来看，相当于一个变量 
	printf("学校：%s\n",me1.school);
	printf("学号：%d\n",me1.num);
	printf("姓名：%s\n",me1.name);
	printf("性别：%c\n",me1.sex);
	printf("专业：%s\n",me1.major);
	printf("家庭地址：%s\n",me1.address);
	
	//(1) 不能企图通过结构体变量名来输出结构体变量所有成员的值
	//    只能对结构体变量中的各个成员分别进行输入和输出 
	// printf("%s",me);  写法是错误的 
	 
	//(2) 如果成员本身又属于一个结构体类型，则要用若干个成员运算符，一级一级地找到最低一级的成员
	//    只能对最低级的成员进行赋值或存取以及运算
	struct Date{
		int month;
		int day;
		int year;
	};
    struct my_birthday{
    	struct Date birthday;
	}me2;
	me2.birthday.month=10;
	me2.birthday.day=25;
	me2.birthday.year=2001;
	printf("My birthday is %d %d %d\n",me2.birthday.month,me2.birthday.day,me2.birthday.year);
	
	//(3) 对结构体变量的成员可以像普通变量一样进行运算(根据其类型决定可以进行的运算) 
	
	//***(4) 同类型 的结构体变量可以相互赋值
	struct Student student1,student2;
	student1=student2; 
	
	//(5) 可以引用结构体变量成员的地址，也可以引用结构体变量的地址 
	printf("%d %d ",&me1,&me2);
	printf("%d",&me2.birthday);
	
	return 0;
} 
