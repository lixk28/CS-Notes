#include<stdio.h>

int main()
{
	//两个实数相除的结果是双精度实数，两个整数相除的结果为整数
	printf("8/3 = %d\n", 8/3); 
	printf("2/3 = %d\n", 2/3);
	printf("1/1 = %d\n", 1/1);
	
	printf("8.0/3 = %f\n", 8.0/3);
	printf("8.0/3.0 = %f\n", 8.0/3.0);
	
	printf("-5/3 = %d\n", -5/3);
	printf("-4/2 = %d\n", -4/2);
	
	return 0;
}
