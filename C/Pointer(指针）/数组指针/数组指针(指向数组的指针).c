#include<stdio.h>

int main()
{
	int m,n;
	printf("Please input the number of the strings:\n");
	scanf("%d",&m);
	printf("Please input the longest length of the string:\n");
	scanf("%d",&n);
	char str[m][n];
    char (*p)[n]; 
	// ����һ������ָ�룬pֻ��ָ��һ������n��Ԫ�ص�һά�������� 
    // �������Ϊ int(*)[n] ��  
	//***** ע��:*p �����ű���Ҫд��������Ƕ�����һ��ָ������      
	
	printf("Please input m strings:\n");
	int i;
	for(i=0;i<m;i++)
	scanf("%s",str[i]);
	p=str; // ע��:����д�� p=str[0]!!! ��Ϊstr[0]��0����Ԫ�صĵ�ַ,��pָ�������������
	for(p;p<str+m;p++)
	printf("%s\n",*p);  // ���ÿһ�е��ַ��� 
	
	return 0;
} 
