/* ָ������� */

// һ����˵��ֻ����ָ���ָ��������Ԫ��ʱ���Ż�ʹ��ָ�����������
// ��Ϊ������Ԫ��ռ���ڴ��������ģ�������ָ��������������� 

#include<stdio.h>
#include<stdlib.h>

int main()
{
	// C supports three forms of pointer arithmetics:
    // <1> Adding an integer to a pointer
    // <2> Subtracting an integer from a pointer
    // <3> Subtracting two pointers

	// ��ָ����ָ��һ������Ԫ��(��һ���������ڴ�ռ�,�����ͱ�֤�������������)ʱ�����Զ�ָ�������������
	// 1> ���ϻ��ȥһ��������+��+=��-��-=
	// 2> �Լӡ��Լ����㣺++��--
	// 3> ָ������� ���� p1-p2 
	 
	//*****ע��������ַ�������!!!!!!!!!!!!!!!!!!!!! p1+p2����ʵ������� *****//
	
	// ���pָ�������е�һ��Ԫ�أ���p+1ָ����һ��Ԫ�أ�p-1ָ����һ��Ԫ��
	
	//***** ע�⣺ִ�� p+i ʱ�����ǽ� p ��ֵ�򵥵ļ� i
	//*****       ʵ������ p + i*d  ( d��p��ָ�����������ռ�õ��ֽ������� d = sizeof(*p) ) 
	
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
	
	//***** ���ָ����� p1 �� p2��ָ��ͬһ�����е�Ԫ��
	//  �� p2-p1 �Ľ���� p2-p1��ֵ������ַ֮��ٳ��Ե�������Ԫ�ص��ֽ�������p1��p2��ָԪ��֮������Ԫ�ظ����� 
	//  �����Ϳ���֪�� p1��p2 ��ָԪ�ص����λ�� 
	p1=&a[1];
	p2=&a[4];
	int distance=p2-p1;
	printf("The position difference between *p1 and *p2 is %d\n\n",distance); 
/*-----------------------------------------------------------------------------------------------------------*/	
	
//***** ��Ȼ����������ռ�õ��ڴ���������֮��
//***** ��malloc��calloc�ڶ����з�����ڴ�ռ�Ҳ��������
	
    //*** ��ַ�������⣺ 
    // ��ַ����� []  ��˫Ŀ������� 
    // ��������߿�����һ�����ʽ���������ڿ�����һ�����ʽ
	
    // ��ַ�������������̣�
    //  p[a] : ( a[p] Ҳ�ǿ��Եģ�a�ǳ�����p��ָ�� ) 
    // <1> �ȼ��� p+a*d ��ֵ (���� d Ϊ p ��ָ��ı�������ռ�õĴ洢��Ԫ���ֽ���)
    // <2> ��ȡ���õ�ֵַ��Ӧ�Ĵ洢��Ԫ�е�ֵ 
    // ע�⣺��������� p ��ֵ���ı䣡���� 
	 
	int length;
	printf("Please input the length of the array:\n");
	scanf("%d",&length);
	int *p=(int *)malloc(sizeof(int)*length); //�Լ��ڶ����д�����һ�� int �����飬p�Ǹ�������Ԫ�صĵ�ַ 
	
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
