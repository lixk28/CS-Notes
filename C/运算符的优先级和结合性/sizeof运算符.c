#include<stdio.h>

//***** sizeof������������� ���Ǻ���������
 
// sizeof�÷��� 
//  sizeof (����˵����)
//��sizeof (���ʽ)

// sizeof�����ã�����һ���������������ռ���ڴ��ֽ���
// �䷵��ֵ����Ϊ size_t (�� unsigned int ) 

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
    
    printf("%d\n",sizeof(p1)); // ָ�������ݶ��� 8�ֽڣ�64λϵͳ�� 
	printf("%d\n",sizeof(p2));
	printf("%d\n",sizeof(p3));
	
	return 0;
}
