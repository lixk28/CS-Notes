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
	// 定义一个数组指针，p只能指向一个包含n个元素的一维整型数组 
    // 其基类型为 int(*)[n] 型  
	//***** 注意:*p 的括号必须要写，否则就是定义了一个指针数组      
	
	printf("Please input m strings:\n");
	int i;
	for(i=0;i<m;i++)
	scanf("%s",str[i]);
	p=str; // 注意:不能写成 p=str[0]!!! 因为str[0]是0行首元素的地址,而p指向的类型是数组
	for(p;p<str+m;p++)
	printf("%s\n",*p);  // 输出每一行的字符串 
	
	return 0;
} 
