#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

/* ����stdin��stdout��Ϊfgets��fputs�������������gets��puts */
 
int main()
{
	char str[MAX_SIZE]={'\0'};
	printf("Please input the string:\n");
	fgets(str,MAX_SIZE,stdin);  //�Ӽ��̶����ַ��� 
	printf("The string is:\n");
	fputs(str,stdout);  //����ʾ������ַ��� 
	
	return 0;
} 
