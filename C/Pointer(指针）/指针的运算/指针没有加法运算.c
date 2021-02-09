#include<stdio.h>

int main()
{
	int *p = (int *)2;
	int *q = (int *)3;
	printf("%d\n", p + q); // compile error 
	
	return 0;
} 
