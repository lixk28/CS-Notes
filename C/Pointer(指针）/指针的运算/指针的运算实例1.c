#include<stdio.h>

int main()
{
	double *p = (double *)100;  //这是野指针 
	// 必须要加上(double *) 因为要把整数100转换成 double型指针值 
	p = p + 2;  // p+2*sizeof(double)  double数据占8字节 
	printf("%d\n",p);
	
	return 0;
}
