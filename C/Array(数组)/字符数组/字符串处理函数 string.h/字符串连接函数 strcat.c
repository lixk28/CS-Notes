/* 字符串连接函数 strcat // (STRing CATenate) */ 

// strcat函数作用是把两个字符串1、字符串2连接起来，结果存放到字符串1中
// 一般形式为：strcat(字符数组1,字符数组2) 
#include<stdio.h>
#include<string.h> 

int main()
{	 
	char str1[15]={"I am "}; // 注意：字符数字1要足够大，可以容纳连接后的新字符串 
	char str2[10]={"Groot"};
	
	printf("%s",strcat(str1,str2)); // 连接后字符串1后面的\0取消 只在新串最后保留0 
	printf("\n");
	
	return 0;
}
