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
// ���ű��ʽ��ֵ �����һ��ʽ�ӵ�ֵ 

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
// �������û�д�  switch������ı����� ch+1   
