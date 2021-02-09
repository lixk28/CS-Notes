/* C语言允许用户自己建立由不同类型数据组成的组合型数据结构，称为 结构体 */ 
 
#include<stdio.h>

int main()
{
	// 声明一个结构体类型的一般形式:
	// struct 结构体名
	// {成员表列}; 
	struct my_structure{
		int a;
		float b;
		double c;
		char d;
	}; 
	//*** 注意：结构体类型名是由一个关键字struct和结构体名组合而成的
	//*** 结构体名是用户自定义的，又称 结构体标记(structure tag)，以区别于其他结构体类型 
	// 上面的结构体声明中的 my_structure 就是结构体名（结构体标记）
	// 花括号内是结构体所包含的子项，称为结构体成员(member)
	//*** 注意：花括号后要加分号！！！ 否则会编译错误 
	// 对各成员都应进行类型声明，即 类型名 成员名;（成员名命名规则与变量名相同） 
	// 成员表列(member list)也称为域表(field list)，每一个成员是结构体中的一个域 
	
	struct Date{
		int month; //月 
		int day; //日 
		int year; //年 
	};
	
	struct Student{ 
		int num; //学号 
		char name[10]; //姓名 
		char sex; //性别 
		int age; //年龄 
	    struct Date birthday; //出生日期  // 结构体成员可以是任意数据类型，当然包括结构体类型 
	    char address[25]; //地址 
	};
	 
	
	return 0;
}
