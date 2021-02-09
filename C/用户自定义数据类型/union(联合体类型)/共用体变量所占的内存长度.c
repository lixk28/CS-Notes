#include<stdio.h>

union data
{
	int i;
	char c;
	float f1;
	double f2;
}a;

int main()
{
	printf("%d\n",sizeof(a));
	
	return 0;
}
