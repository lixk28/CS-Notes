
#include<stdio.h>

int main()
{
	/*** <1> 用一个新类型名代替原有的类型名(如int、float、double等) ***/
	// 一般形式为： typedef 原有类型名 新类型名;
	typedef int integer;
	typedef float real;
	typedef char character;
	
	integer i,j; // 等价于 int i,j;
	real a,b; // 等价于 float a,b;
	character ch1,ch2; // 等价于 char ch1,ch2;
	
	/*** <2> 命名一个简单的类型名代替复杂的类型表示方法 ***/
	/* (1) 命名一个新的类型名代表结构体类型 */ 
	// 一般形式为：typedef struct
	//            {
	//              成员表列
    //            } 新类型名； 
    // 进行完上面的操作后，新类型就代表该结构体类型 
	typedef struct
	{
		int month;
		int day;
		int year;
	} Date;
	
	// 也可以写成
	// typedef struct date
	// {
	//    int month;
	//    int day;
	//    int year;
	// } Date; 
    
	Date birthday; // 不要写成 struct Date birthday
	Date *p;
    
	/* <2> 命名一个新的类型名代表数组类型 */
	typedef int num[100]; // 声明num为整型数组名 
	num x; // 定义a为整型数组名，包含100个元素
	
	/* <3> 命名一个新的类型名代表指针类型 */
	typedef char *str; // 声明str为字符指针类型 
	str s[15]; // 定义s为字符指针数组
	
	/* <4> 命名一个新类型名代表指向函数的指针类型 */ 
	typedef int (* pointer)(); // 声明pointer为指向函数的指针类型，该函数返回整数值 
	pointer p1,p2; // p1,p2为pointer类型的指针变量 
	
	// 总结：就是按照定义变量的方式，把变量名换上新类型名，并且在最前面加上typedef,就声明了新类型名代表原来的类型 
	// 步骤：(严格按照此步骤执行) 
	// (1) 先按定义变量的方法写出定义体
	// (2) 将变量名换成新类型名
	// (3) 在在前面加上typedef
	// (4) 然后就可以用新类型名去定义变量 
	return 0;
}
