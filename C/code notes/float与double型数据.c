#include<stdio.h>

int main()
{
	float a;
	a=1000.0/3.0;
	printf("%f\n",a);
	
	double b;
	b=1000.0/3.0;
	printf("%f\n",b);
	
	float c;
	c=10000.0/3.0;
	printf("%f\n",c);
	
	double d;
	d=10000./3.0;
	printf("%f\n",d);
	
	double e;
	e=10000000000000.0/3.0;
	printf("%f\n",e);
	
	float f;
	f=1.0/30000.0;
	printf("%f\n",f);
	
	return 0;
}
/* %f格式符输出数据，只能得到 6 位小数 
   float和double输出时格式符都用 %f double数据输出是也只输出六位小数  但有效数字位数比float多 
   但输入时float用%f double必须用%lf  以免精度丢失
    
     注意：这里的有效数字不是从左边第一个不为 0 的数字算起
	       就是指 从数据的最左边的一位数字算起 
   float型数据只能保证 6-7 位有效数字 
   在这里保证的是 7 位有效数字  即第 7 位以后的数字不是准确的
   
   double型数据只能保证 15-16 位有效数字
   在这里保证的是 16 位有效数字  即第 16 位以后的数字不是准确的  
*/

//#include <stdio.h>
//    
//int main()
//{
//    float x = 0.1;
//    if (x == 0.1)
//      printf("WDNMD");
//    else
//	  printf("NMLGB"); 
//}

