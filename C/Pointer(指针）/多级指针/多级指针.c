/* 多级指针 */
 
#include<stdio.h>

// 指向指针类型数据的指针变量，称为指向指针的指针，即多级指针 
// 定义一个指向指针数据的指针变量(二级指针)的一般形式：
//  类型名 **指针名;

// 也可以定义一个多级指针数组：
// 类型名 **数组名[数组长度]; 

int main()
{
	char *str[3]={"I am Groot","Hello World","I love China"};
	
	char **p;
	p=str;  // str代表 指针数组str首元素的地址 而str首元素是一个字符指针 所以str是一个二级字符指针 
	int i;
	for(i=0;i<3;i++)
	  printf("%s\n",*(p+i));
	  
	return 0;
}
