#include<stdio.h>

int main()
{
	int a=1;
	int b,c;
	b=(a++)+(++a);
	c=(++a)+(a++);
	printf("%d\n",b);
	printf("%d\n",c);
	
	return 0;
 } 
