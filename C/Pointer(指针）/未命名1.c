#include<stdio.h>

int main()
{
	int num=1;
	int *p=&num;
	printf("*&p=%p\n",*&p);
	printf("&*p=%p\n",&*p);  
	
	return 0;
} 

// &和* 优先级相同 与++ -- 强制类型转换符 优先级相同
// & 和 * 是右结合的 即从右向左 
// & 和 * 在一起会相互抵消 
//& 不能用于表达式常量和寄存器变量
 
