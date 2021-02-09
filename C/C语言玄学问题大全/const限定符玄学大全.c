#include<stdio.h>

int main()
{
	const char *p1; //*p是const,p可变
    const (char *) p2;//p是const,*p可变
    char* const p3; //p是const,*p可变
    const char* const p4; //p和*p都是const ?
    char const *p5;// *p是const,p可变
    (char*) const p6;//p是const,*p可变
    char* const p7;// p是const,*p可变
    char const* const p8;// p和*p都是const
    char *const *p9;// *p是const,**p、p可变
	const char **p10;// **p是const,p可变
	char** const p11;// p是const,*p、**p都可变 
	char const *p12,p13;// *p1、p2是const,p1可变 
	char const * const p14,p15;// p1、p2、*p1都是const 
	char * const p16,p17;// p1是const,*p1、p17可变 
} 

//***指针指向及其指向变量的值的变化***// 
//const 在*的左边，则指针指向的变量的值不可直接通过指针改变（可以通过其他途径改变）
//const 在*的右边，则指针的指向不可变
// 简记为 "左定值，右定向"

//在c中，对于const定义的指针，不赋初值编译不报错，
//int* const px;这种定义是不允许的。（指针常量定义的时候对其进行初始化）
//int const *px;这种定义是允许的。（常指针可以再定义的时候不初始化）
//但是，在C++中
//int* const px;和const int* const px;会报错，const int* px;不报错。
//必须初始化指针的指向int* const px = &x;const int* const px=&x;
//强烈建议在初始化时说明指针的指向，防止出现野指针！


// 虽然const修饰的变量在赋予初值后不能 再对其赋值、自增、自减运算等
// 但是可以将这个变量的地址赋给一个指针变量 
// 可以通过这个指针变量修改变量的值  这是可以的！！！

 
