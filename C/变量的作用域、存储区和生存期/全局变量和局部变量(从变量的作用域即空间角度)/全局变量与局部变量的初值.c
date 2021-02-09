#include<stdio.h>

// 全局变量 和 静态变量 是存储在 静态存储区（全局区）内的，若在定义它们是未赋初值，系统自动赋值为 0 或 '\0' 
// 局部变量 和 自动变量 是存储在栈区的，若未赋初值，它的值是不可预料的(undefined) 

int x;
int main()
{
	int a = 3;
    if (a > 1) {
        int x;
        printf("%d ", x); // undefined value 未定义的 
    }
    printf("%d\n", x); // 0
    return 0;
	
	return 0;
} 
