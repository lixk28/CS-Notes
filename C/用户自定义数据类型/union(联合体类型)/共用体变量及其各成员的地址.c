#include<stdio.h>

int main()
{
	union data
	{
		int i;
		char ch;
		float f;
	}a;
	
	printf("%p\n",&a);
	printf("%p\n",&a.i);
	printf("%p\n",&a.ch);
	printf("%p\n",&a.f);
	
	return 0;
} 
