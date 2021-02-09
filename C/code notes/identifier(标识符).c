#include<stdio.h>

int main()
{
	// C语言规定表示赋只能由 字母、数字和下划线 3种字符组成，且第一个字符必须为字母或下划线
	// 标识符不能与关键字同名，且编译系统认为大写字母和小写字母是不同的字符 
	int num, sum, my_num;
	int Num, Sum;
	int _a;
	
	int int; //与关键字同名 
	int 3a; //首字符是数字
	int #a, Mr.Jhon; // # . 不能用 
	
	return 0;
}
