/* �ַ�����Сдת������ strlwr and strupr (STRing LoWeR and STRing UPpeR) */ 

// һ����ʽΪ strlwr(�ַ�����) and strupr(�ַ�����) 
#include<stdio.h>
#include<string.h>

int main()
{
	char str1[15]={"I am Groot"};
	char str2[15]={"Hello World"};
	
	strupr(str1);
	strlwr(str2);
	
	printf("%s\n",str1);
	printf("%s\n",str2);
	
	return 0;
}
