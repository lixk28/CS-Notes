#include<stdio.h>

//***** sizeof是运算符！！！ 不是函数！！！
 
// sizeof用法： 
//  sizeof (类型说明符)
//　sizeof (表达式)

// sizeof的作用：返回一个对象或者类型所占的内存字节数
// 其返回值类型为 size_t (即 unsigned int ) 

int main()
{
	int num[5];
	char str[15];
	int *p1;
	char *p2;
	float *p3;
	
	printf("%d\n",sizeof(int));
	printf("%d\n",sizeof(short));
    printf("%d\n",sizeof(long));
    printf("%d\n",sizeof(long long));
    printf("%d\n",sizeof(float));
    printf("%d\n",sizeof(double));
    printf("%d\n",sizeof(num));
    printf("%d\n",sizeof(str));
    
    printf("%d\n",sizeof(p1)); // 指针型数据都是 8字节（64位系统） 
	printf("%d\n",sizeof(p2));
	printf("%d\n",sizeof(p3));
	
	return 0;
}
