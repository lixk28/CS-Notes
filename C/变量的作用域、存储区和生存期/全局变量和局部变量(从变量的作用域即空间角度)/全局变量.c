/* 全局变量 (global)*/ 

// 在函数内定义的是局部变量，在函数外定义的是全局变量
// 全局变量也称外部变量或全程变量 

//*** 全局变量可以在本文件中被所有函数所共用 
//*** 全局变量的作用域：从定义变量的位置到本源文件结束

//编程的好习惯: 将全局变量的第一个字母大写表示 
 
#include<stdio.h>

int a=1,b=2;

int fun1(int a, int b) //注意:在fun1中不能引用c1和c2，因为c1,c2在fun1之前未定义 
{
	return a+b;
}

char c1,c2;

char fun2(char c1, char c2)
{
	return c1>c2? c1:c2;
}
int main()
{
	int p=1,q=2;
	int sum;
	sum=a+b+fun1(p,q);
	printf("%d",sum);
	
	return 0;
} 
