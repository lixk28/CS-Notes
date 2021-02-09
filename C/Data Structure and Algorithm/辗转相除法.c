#include<stdio.h>

int gcd(int x,int y)
{
	if(y == 0)
		return x;
	else
	 	return gcd(y,x%y);
}

int main()
{
	int x=10;
	int y=200;
	int d=gcd(x,y);
	printf("%d\n",d);
	
	return 0;
} 
