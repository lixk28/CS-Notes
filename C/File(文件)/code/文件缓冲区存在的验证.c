#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int main()
{
	char *str=(char *)malloc(sizeof(char)*MAX_SIZE);
	char c;
	
	printf("����������:\n");
	scanf("%s", str);
	printf("��ȷ������(Y/N):\n");
//	while (getchar() != '\n') //��getchar()֮ǰ��ȡ�껺���������е��ַ�
//		continue;
	c = getchar();
	if(c == 'Y')
		printf("1\n");
	else 
		printf("2\n");
		
	return 0;
}
