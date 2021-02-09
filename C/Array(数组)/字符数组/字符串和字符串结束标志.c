/* 字符串及字符串结束标志 */

// C语言中，是将字符串作为字符数组处理的
// C语言规定，以空字符 '\0' 作为字符串结束标志
// 在读到字符'\0'时，表示字符串结束，把\0前面的字符组成一个字符串
#include<stdio.h>

int main()
{
	// C系统在用字符数组存储字符串常量时会自动加一个'\0'作为结束符
	// 而用字符数组存储单个字符时不会这么做，可以不包含'\0' 
	char c1[]={"Hello, world"}; // 1
	
	char c2[]={'H','e','l','l','o',',',' ','w','o','r','l','d'}; // 2
	
	char c3[]={'H','e','l','l','o',',',' ','w','o','r','l','d','\0'}; // 3
	
	printf("string length = %d %d %d\n",strlen(c1),strlen(c2),strlen(c3)); // c2会 warning 
	printf("size = %d %d %d\n",sizeof(c1)/sizeof(char),sizeof(c2)/sizeof(char),sizeof(c3)/sizeof(char));
	
    // *** 注意 *** //
	//  1与3等价，而1与2不等价
	//  1和3数组长度都为 13，而2数组长度为 12
	//  字符数组长度=字符串长度+1 (存储字符串的数组)
	
	return 0;
} 
