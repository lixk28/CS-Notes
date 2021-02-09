/* 指针的运算 */

// 一般来说，只有在指针的指向是数组元素时，才会使用指针的算术运算
// 因为数组中元素占用内存是连续的，这样对指针做运算才有意义 

#include<stdio.h>
#include<stdlib.h>

int main()
{
	// C supports three forms of pointer arithmetics:
    // <1> Adding an integer to a pointer
    // <2> Subtracting an integer from a pointer
    // <3> Subtracting two pointers

	// 在指针已指向一个数组元素(或一段连续的内存空间,这样就保证运算是有意义的)时，可以对指针进行以下运算
	// 1> 加上或减去一个整数：+、+=、-、-=
	// 2> 自加、自减运算：++、--
	// 3> 指针间的相减 ，如 p1-p2 
	 
	//*****注意两个地址不能相加!!!!!!!!!!!!!!!!!!!!! p1+p2是无实际意义的 *****//
	
	// 如果p指向数组中的一个元素，则p+1指向下一个元素，p-1指向上一个元素
	
	//***** 注意：执行 p+i 时并不是将 p 的值简单的加 i
	//*****       实际上是 p + i*d  ( d是p所指向的数据类型占用的字节数，即 d = sizeof(*p) ) 
	
	int *p1,*p2;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	
	p1=&a[0];
	
	p1+=3;
	printf("The fourth element in a is %d\n",*p1);
	
	p1++;
	printf("The fifth element in a is %d\n",*p1);
	
	p1-=2;
	printf("The third element in a is %d\n",*p1);
	
	p1--;
	printf("The second element in a is %d\n",*p1);
	
	p2=p1+4;
	printf("The sixth element in a is %d\n",*p2);
	
	//***** 如果指针变量 p1 和 p2都指向同一数组中的元素
	//  则 p2-p1 的结果是 p2-p1的值（两地址之差）再除以单个数组元素的字节数（即p1、p2所指元素之间间隔的元素个数） 
	//  这样就可以知道 p1、p2 所指元素的相对位置 
	p1=&a[1];
	p2=&a[4];
	int distance=p2-p1;
	printf("The position difference between *p1 and *p2 is %d\n\n",distance); 
/*-----------------------------------------------------------------------------------------------------------*/	
	
//***** 当然，除了数组占用的内存是连续的之外
//***** 用malloc和calloc在堆区中分配的内存空间也是连续的
	
    //*** 变址运算符详解： 
    // 变址运算符 []  （双目运算符） 
    // 中括号左边可以是一个表达式，中括号内可以是一个表达式
	
    // 变址运算符的运算过程：
    //  p[a] : ( a[p] 也是可以的，a是常量，p是指针 ) 
    // <1> 先计算 p+a*d 的值 (其中 d 为 p 所指向的变量类型占用的存储单元的字节数)
    // <2> 再取出该地址值对应的存储单元中的值 
    // 注意：做完运算后 p 的值不改变！！！ 
	 
	int length;
	printf("Please input the length of the array:\n");
	scanf("%d",&length);
	int *p=(int *)malloc(sizeof(int)*length); //自己在堆区中创建了一个 int 型数组，p是该数组首元素的地址 
	
	int i;
	printf("Please initialize the array:\n");
	for(i=0;i<length;i++)
	  scanf("%d",&p[i]);
	  
	printf("The array is:\n");
	for(i=0;i<length;i++)
	  printf("%d ",p[i]);
	
	free(p);
	 
	return 0;
} 
