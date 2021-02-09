#include<stdio.h>

int main()
{
	int num[]={1,2,3,4,5};
	char str[]="I am Groot";
	
	printf("%d\n",sizeof(num)/sizeof(int)); // 5
	printf("%d\n",sizeof(str)/sizeof(char));  // 11
	// 注意不是 10 ，因为字符数组在末尾自动添上'\0' 
	// 数组的实际长度是 11
	// 实际在使用字符数组时也要考虑到这点，否则很容易造成数组越界 
	
	return 0;
} 
