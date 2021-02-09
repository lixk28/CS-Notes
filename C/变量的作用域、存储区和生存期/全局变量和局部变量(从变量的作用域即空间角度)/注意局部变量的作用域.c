#include<stdio.h>

int main()
{
    int i;
    for(i=0;i<10;i++)
    {
    	int j;
    	for(j=0;j<5;j++)
    	  j=j+2;
	}
    printf("%d\n",j);  // 编译报错，因为j是for循环体中的局部变量 
	
	return 0;
} 
