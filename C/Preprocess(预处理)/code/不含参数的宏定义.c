#include<stdio.h>
#define TWO 2
#define FOUR TWO*TWO

#define S1 "I am Groot"
#define S2 I am Groot
#define PS1 printf("%s\n",S1) //无双引号 
#define PS2 printf("%s\n",S2) //有双引号 

#define P1 printf("X is %d\n",X);
#define P2 printf("X is %d\n",X)
#define FORMAT "X is %d\n" 

int main()
{
	int X=TWO;
	P1
	P2; //注意分号要加 
	
	X=FOUR;
	printf(FORMAT,X);
	
	PS1; //输出结果是 I am Groot 
	PS2; //输出结果是 S2  
	
	return 0;
}
