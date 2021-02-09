#include<stdio.h> 
 
#define PRINT_SUM1(A,B) printf("The sum of A and B is %d.\n", ((A)+(B)))
#define PRINT_SUM2(A,B) printf("The sum of " #A " and " #B " is %d.\n", ((A)+(B)))
#define STRING(X) #X 

int main()
{
	PRINT_SUM1(1,2); //显示的是：The sum of A and B is 3.
	PRINT_SUM2(1,2); //显示的是：The sum of 1 and 2 is 3.
	
	printf("%s\n",STRING(Hello World)); 
	printf("%s\n",STRING(I am Groot));
	
	return 0;
}
