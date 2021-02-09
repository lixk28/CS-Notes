// C语言允许建立内存动态分配区域 ，以存放一些临时用的数据
// 这些数据不必在程序的声明部分定义，已不必等到函数结束时才释放
// 而是需要时随时开辟，不需要时随时释放
// 这些数据是临时存放在一个特别的自由存储区，称为 堆区(heap) 

// 由于未在声明部分定义它们为变量或数组，因此不能通过改变变量名或数组名取引用这些数据
// 只 能 通过 指针 来引用
 
#include<stdio.h>
#include<stdlib.h> //要include标准库函数头文件stdlib.h 

int main()
{
	/*** <1> malloc 函数(memory allocation) ***/
	// 函数原型: void *malloc(unsigned int num_bytes);
	// 作用：在内存的动态存储区中分配个长度为 num_bytes字节 的连续内存空间 
	// 参数：形参num_bytes的类型是无符号整型(不可以是负数)，num_bytes表示分配内存的字节数  
	// 返回值：若分配成功则返回分配的内存的指针(指向该内存段的首字节)，否则返回空指针NULL
	// 函数类型为void *表示由用户定义这段内存是用来存储什么样的数据(char、int、float等) 
	// void *,表示未确定类型的指针。C，C++规定，void *类型可以强转为任何其他类型的的指针
	char *p1;
	int n1;
	printf("Please input the bytes you need:\n");
	scanf("%d",&n1);
	p1=(char *)malloc(sizeof(char)*n1);
	printf("Please input the string:\n");
	scanf("%s",p1);
	printf("string=%s\n",p1);
	free(p1); // 必须要释放malloc分配的内存空间，否则可能会导致内存泄漏 
/*-----------------------------------------------------------------------------------------------------------*/	
	
	/*** <2> calloc 函数 ***/
	// 函数原型： void *calloc(unsigned int n,unsigned int num_bytes);
	// 作用：在内存的动态存储区中分配n个长度为num_bytes字节的连续内存空间，这个空间足够大，常用来保存数组
	// 参数：n是内存块的个数，num_bytes是每个内存块的字节数
	// 返回值：若分配成功则返回分配域的首字节的指针，否则返回空指针NULL
	//*** 用calloc函数可以为一维数组开辟动态存储空间，n为数组元素个数，每个元素长度为num_bytes
	//*** 这就是 动态数组
	
	// 一维动态数组的创建 
	char *p2;
	int n2;
	printf("Please input the length of the array you need:\n");
	scanf("%d",&n2);
	p2=(char *)calloc(n2+1,sizeof(char));
	printf("Please input the string:\n");
	scanf("%s",p2);
	printf("string=%s",p2);
	free(p2);
/*-----------------------------------------------------------------------------------------------------------*/	
	 
	/*** <3> realloc 函数 ***/ 
	// 函数原型：void *realloc(void *p,unsigned int num_bytes); 
	// 作用：如果已经通过malloc或calloc函数获得了动态空间，可以用realloc函数重新分配，改变其大小
	// 参数：p是已经分配的动态空间的首字节的指针，num_bytes是用户想要的字节数
	// 返回值：将p所指向的内存空间大小改变为num_bytes，不改变p的值，然后返回p；若分配失败，返回空指针NULL
	int *p3;
	p3=(int *)malloc(sizeof(int)*10);
	p3=(int *)realloc(sizeof(int)*15); 
	free(p3);
/*-----------------------------------------------------------------------------------------------------------*/
	
	/*** <4> free 函数 ***/
	// 函数原型：void free(void *p);
	// 作用：释放p所指向的动态空间，使这部分空间能重新被其他变量使用 
    // 参数：P应是最近一次调用calloc或malloc函数时的到的函数返回值
	// 返回值：free函数无返回值
	 
	return 0;
}
