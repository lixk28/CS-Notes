#include<stdio.h>

int main()
{
	double *p = (double *)100;  //����Ұָ�� 
	// ����Ҫ����(double *) ��ΪҪ������100ת���� double��ָ��ֵ 
	p = p + 2;  // p+2*sizeof(double)  double����ռ8�ֽ� 
	printf("%d\n",p);
	
	return 0;
}
