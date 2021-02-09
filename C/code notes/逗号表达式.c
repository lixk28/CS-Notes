#include<stdio.h>

int main()
{
	int n,i,j;
	i=1;
	j=2;
	n=(++i,++j);
	
	printf("%d",n);
	return 0;
}
// 逗号表达式的值 是最后一个式子的值 

#include <stdio.h>
int main()
{
    int ch;
    printf("enter a value btw 1 to 2:");
    scanf("%d", &ch);
    switch (ch, ch + 1)
    {
    case 1:
        printf("1\n");
        break;
    case 2:
        printf("2");
        break;
    }
}
// 这个程序并没有错  switch括号里的变量是 ch+1   
