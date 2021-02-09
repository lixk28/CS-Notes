#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int main()
{
	char *str=(char *)malloc(sizeof(char)*MAX_SIZE);
	char c;
	
	printf("请设置密码:\n");
	scanf("%s", str);
	printf("请确认密码(Y/N):\n");
//	while (getchar() != '\n') //在getchar()之前获取完缓冲区中所有的字符
//		continue;
	c = getchar();
	if(c == 'Y')
		printf("1\n");
	else 
		printf("2\n");
		
	return 0;
}
