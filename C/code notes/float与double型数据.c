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
/* %f��ʽ��������ݣ�ֻ�ܵõ� 6 λС�� 
   float��double���ʱ��ʽ������ %f double���������Ҳֻ�����λС��  ����Ч����λ����float�� 
   ������ʱfloat��%f double������%lf  ���⾫�ȶ�ʧ
    
     ע�⣺�������Ч���ֲ��Ǵ���ߵ�һ����Ϊ 0 ����������
	       ����ָ �����ݵ�����ߵ�һλ�������� 
   float������ֻ�ܱ�֤ 6-7 λ��Ч���� 
   �����ﱣ֤���� 7 λ��Ч����  ���� 7 λ�Ժ�����ֲ���׼ȷ��
   
   double������ֻ�ܱ�֤ 15-16 λ��Ч����
   �����ﱣ֤���� 16 λ��Ч����  ���� 16 λ�Ժ�����ֲ���׼ȷ��  
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

