#include<stdio.h>

#define XNAME(n) x ## n
#define NAME(n) My_ ## Name_ ## n

#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n)
#define PRINT_NAME(n) printf("My_Name_" #n " = %d\n", My_ ## Name_ ## n) 
//注意：用 # 组合字符串，用 ## 把记号组合为一个新的标识符 

int main()
{
	int XNAME(1) = 3;
	int XNAME(2) = 4;
	int x3 = 5;
	
	PRINT_XN(1);  // x1 = 3
	PRINT_XN(2);  // x2 = 4
	PRINT_XN(3);  // x3 = 5
	
	int NAME(1) = 1;
	int My_Name_2 = 2;
	
	PRINT_NAME(1);  // My_Name_1 = 1
	PRINT_NAME(2);  // My_Name_2 = 2
	
	return 0;
} 
