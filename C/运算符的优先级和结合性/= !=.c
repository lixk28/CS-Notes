#include <stdio.h>
int main() {
	/* 1 */ //input abc 
    char c1;
    while ((c1 = getchar())!= '\n') {
        printf("%d ", c1);  
    }
    printf("\n");
    
    /* 2 */ //input abc
    char c2;
    while (c2 = getchar() != '\n') {
    	printf("%d ",c2);
	}
	printf("\n");

    return 0;
}

// != �����ȼ����� =
// !=�����ϵ� =���ҽ�ϵ�
// ���2����ִ�� getchar() != '\n' ������
// ��Ϊ����abc����Ϊ'\n' ���Ը��߼����ʽ��ֵΪ 1
// �����ֵ����c2  ��� c2 ����1 
