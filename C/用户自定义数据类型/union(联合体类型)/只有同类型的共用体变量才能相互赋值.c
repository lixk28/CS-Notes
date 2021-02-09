#include<stdio.h>

union name1{
	int data;
	char ch;
}a={0},b={1};

union name2{
	int data;
	char ch;
}c={2};

int main()
{
	a=b;
	a=c;
	
	return 0;
} 
