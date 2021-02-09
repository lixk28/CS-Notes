//#include<stdio.h>
//
//int main()
//{
//	unsigned int a=1;  // 如果把unsigned去掉 输出的结果就会是Yes 而事实上是No 
//	int b=-1;
//	if(a>b)
//	  printf("Yes\n");
//	else if(a<b)
//	  printf("No\n");
//	
//	return 0;
//}
/*  C语言中，机器在遇到无符号数与有符号数之间的操作(运算，比较大小) 
    编译器会自动将有符号数隐式转换为无符号数处理 
    即将有符号数的补码直接作为新的无符号数的补码
	如a=-1 补码表示为11111111 11111111  直接表示成十进制数就是65535 (2^16-1)
*/

//#include<stdio.h>
//
//int main()
//{
//	unsigned int a=2;
//	int b=-1;
//	if(a+b>b)
//	  printf("Yes\n");
//	else 
//	  printf("\n\n\n\tSurprise Motherfucker\n\n\n");
//	
//	return 0;
//}

/* a的补码： 00000000 00000010
   b的补码： 11111111 11111111 转换成unsigned第一位就不表示符号位了，十进制的话就是65535 
*/  
 

//#include<stdio.h>
//
//int main()
//{
//	unsigned int i=-1;
//   	printf("%d\n",i); //  结果为-1，%d是以有符号十进制整数形式输出 
//	printf("%u\n",i); //  结果为2的32次方减一，%u是以无符号十进制整数输出 
//	
//	return 0;
//}  
