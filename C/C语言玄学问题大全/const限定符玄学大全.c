#include<stdio.h>

int main()
{
	const char *p1; //*p��const,p�ɱ�
    const (char *) p2;//p��const,*p�ɱ�
    char* const p3; //p��const,*p�ɱ�
    const char* const p4; //p��*p����const ?
    char const *p5;// *p��const,p�ɱ�
    (char*) const p6;//p��const,*p�ɱ�
    char* const p7;// p��const,*p�ɱ�
    char const* const p8;// p��*p����const
    char *const *p9;// *p��const,**p��p�ɱ�
	const char **p10;// **p��const,p�ɱ�
	char** const p11;// p��const,*p��**p���ɱ� 
	char const *p12,p13;// *p1��p2��const,p1�ɱ� 
	char const * const p14,p15;// p1��p2��*p1����const 
	char * const p16,p17;// p1��const,*p1��p17�ɱ� 
} 

//***ָ��ָ����ָ�������ֵ�ı仯***// 
//const ��*����ߣ���ָ��ָ��ı�����ֵ����ֱ��ͨ��ָ��ı䣨����ͨ������;���ı䣩
//const ��*���ұߣ���ָ���ָ�򲻿ɱ�
// ���Ϊ "��ֵ���Ҷ���"

//��c�У�����const�����ָ�룬������ֵ���벻����
//int* const px;���ֶ����ǲ�����ġ���ָ�볣�������ʱ�������г�ʼ����
//int const *px;���ֶ���������ġ�����ָ������ٶ����ʱ�򲻳�ʼ����
//���ǣ���C++��
//int* const px;��const int* const px;�ᱨ��const int* px;������
//�����ʼ��ָ���ָ��int* const px = &x;const int* const px=&x;
//ǿ�ҽ����ڳ�ʼ��ʱ˵��ָ���ָ�򣬷�ֹ����Ұָ�룡


// ��Ȼconst���εı����ڸ����ֵ���� �ٶ��丳ֵ���������Լ������
// ���ǿ��Խ���������ĵ�ַ����һ��ָ����� 
// ����ͨ�����ָ������޸ı�����ֵ  ���ǿ��Եģ�����

 
