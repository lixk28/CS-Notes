#include<stdio.h>

int main()
{ 
	union data
	{
    	int n;
    	char ch;
    	float f;
	}a={1,'A',1.0};  //不能同时对多个成员初始化，因为它们占用同一段内存单元

	union data b={1}; //正确，对第一个成员初始化

	union data c={.ch='A'}; //C99允许对指定的一个成员初始化
	
	return 0;
}
