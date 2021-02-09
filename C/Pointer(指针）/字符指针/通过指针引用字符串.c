// C语言中两种字符串的引用方式
// <1> 通过字符数组
// <2> 通过指针 

#include<stdio.h>
#include<stdlib.h>

int main()
{
	// 定义字符指针变量：char *p 
	// <1> 可以在定义的字符指针变量的同时对其初始化 
    char *str1="I am Groot"; 
	
	// <2> 也可以定义之后，再初始化 
	char *str2;
	str2="I am Groot"; // 不要写成 *str2="I am Groot" 
	
	//*** 对字符指针变量初始化，实际上是把字符串首元素的地址赋给指针变量，使其指向字符串的第一个字符 
	
	// 可以对字符指针变量再赋值
	str1="Hello World";
	char str3[15]="I am Groot";
	str2=str3;
	printf("str1=%s\n",str1);
	printf("str2=%s\n",str2);
	printf("str3=%s\n",str3);
	
	//可以输入一个字符串，将其首地址赋给字符指针变量
    //<1> 可以用scanf输入 但输入的字符串里不能包含空格，因为空格是字符串分隔标志 
    //<2> 也可以用gets输入 此时空格也会被读入字符串中，直到输入换行符
    //注意!!!：但要事先用 malloc函数 给该字符指针变量分配一段内存空间 
    
    //也可以通过字符指针变量输出其所指向的字符串 
    //<1> 可以用printf输出 
	//<2> 也可以用puts输出 
	// 都是写字符指针变量名，不要加* 
    char *str4;
    unsigned int num1;
    printf("Please input the length of str4 you need:\n");
    scanf("%u",&num1);
    str4=(char *)malloc(num1*sizeof(char));
    printf("Please input str4:\n"); 
    scanf("%s",str4); 
	printf("str4=%s\n",str4); 
	//系统会输出string所指向的字符串的第一个字符，然后自动使其加1，指向下一个字符
	//直到遇到'\0'为止，注意在内存中，字符串的最后被自动加'\0'                         
	free(str4);
    
    char *str5;
    unsigned int num2;
    printf("Please input the length of str5 you need:\n");
    scanf("%u",&num2);
    str5=(char *)malloc(num2*sizeof(char));
    getchar();
    printf("Please input str5:\n"); 
	gets(str5);
    printf("str5=%s\n",str5);
    free(str5);
	 
	// 可以通过指针访问字符串，通过改变指针变量的值来使其指向字符串中的不同字符
	int num3;
	printf("Please input the length of str6 you want:\n");
	scanf("%d",&num3);
	getchar();
	char str6[num3+1];
	printf("Please input str6:\n");
	gets(str6);
	int i;
	char *p=str6;
	printf("str6=");
	for(i=0;*(p+i)!='\0';i++) // 通过改变指针变量的值逐个访问字符串的字符 
	printf("%c",*(p+i));
	 
	return 0;
}
