#include<stdio.h>

int main()
{
	union data
	{
		int i;
		char ch;
		float f;
	}a;
	a.i=321;
	
	printf("%d\n",a.i);
	printf("%d\n",a.ch);
	printf("%c\n",a.ch);
	printf("%f\n\n",a.f);
	
	union data b;
	b.ch='A';
	b.f=3.14;
	b.i=97;
	
	printf("%d\n",b.i);
	printf("%d\n",b.ch);
	printf("%c\n",b.ch);
	printf("%f\n\n",b.f);
	
	return 0;
} 
