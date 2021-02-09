#include<stdio.h>

#define PRINT(...) printf(__VA_ARGS__)
#define OUTPUT_INTEGER(X,...) printf(#__VA_ARGS__ " = %d\n",X) 

int main()
{
	PRINT("Hello World\n");
	PRINT("I am Groot\n");
	
	int x=1,y=2;
	PRINT("x = %d\ny = %d\n",x,y);
	
	OUTPUT_INTEGER(3,a);
	OUTPUT_INTEGER(4,b);
	
	return 0;
}
