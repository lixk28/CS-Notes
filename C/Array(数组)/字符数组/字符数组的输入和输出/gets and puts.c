// puts and gets // << putstring and getstring >>

#include<stdio.h>  // puts 和 gets 函数都是在标准输入输出函数内的 不用include头文件string.h

// puts函数的一般形式为 puts(字符数组名)
// gets函数的一般形式为 gets(字符数组名)  
  
int main()
{
	char str1[15]={"Hello world"};
	puts(str1);  // 在用puts输出时将字符串结束标志'\0'转换成'\n'，即输出完字符串后换行
	             // 当然，\0仍起到结束字符串的作用 
	             // 也就是说puts输出字符串后自动换行 
	             
	char str2[15]={"Hello\0World"}; 
	puts(str2);    //world 不会被输出 
	
	char str3[15];
	gets(str3);  // 输入字符串，将字符串送给字符数组，注意送给的字符串包括自动添加的'\0'          
	             // gets 函数有返回值！！！ 返回值是字符数组的起始地址，即第一个元素的地址 
	puts(str3);
	
	return 0;
}
