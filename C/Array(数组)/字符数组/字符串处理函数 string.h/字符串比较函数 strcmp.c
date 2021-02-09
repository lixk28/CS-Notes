/* 字符串比较函数 strcmp (STRing CoMPare) */

// 一般形式为 strcmp(字符串1,字符串2)
#include<stdio.h>
#include<string.h> 

int main()
{ 
  /***** 字符串的比较规则 *****/
  // 将两个字符串从左到右逐个字符相比，按ASCII码值的大小比较，直到出现不同的字符或遇到 '\0'为止 
  // (1) 若全部字符都逐个相同，则认为两个字符串相等
  // (2) 若出现不相同的字符，则以第一对不相同的字符的比较结果为准
  
  /***** 比较的结果由函数值带回，strcmp函数有返回值 *****/ 
  // (1) 如果 字符串1 = 字符串2，则函数值为 0
  // (2) 如果 字符串1 > 字符串2，则函数值为一个正整数(一般是1)
  // (3) 如果 字符串1 < 字符串2，则函数值为一个负整数(一般是-1) 
  
  //Example： 
  char str8[]={"computer"},str9[]={"compare"};
  int return_value1,return_value2,return_value3;
  
  return_value1=strcmp(str8,str9);
  return_value2=strcmp("A","a");
  return_value3=strcmp("DOG","cat");
  
  printf("return_value1=%d\n",return_value1);
  printf("return_value2=%d\n",return_value2);
  printf("return_value3=%d\n",return_value3);
  
  getchar(); // Press a key to continue the next part
  printf("Please input two strings:\n");
  char str10[100],str11[100];
  gets(str10);
  gets(str11);
  if(strcmp(str10,str11) == 0)
  printf("str1 = str2");
  else if(strcmp(str10,str11) > 0)
  printf("str1 > str2");
  else if(strcmp(str10,str11) < 0)
  printf("str1 < str2");
  
  // 小写字母比大写字母大！！！ 因为ASCII码值大        
   
	return 0;
} 
