#include<stdio.h>

// ȫ�ֱ��� �� ��̬���� �Ǵ洢�� ��̬�洢����ȫ�������ڵģ����ڶ���������δ����ֵ��ϵͳ�Զ���ֵΪ 0 �� '\0' 
// �ֲ����� �� �Զ����� �Ǵ洢��ջ���ģ���δ����ֵ������ֵ�ǲ���Ԥ�ϵ�(undefined) 

int x;
int main()
{
	int a = 3;
    if (a > 1) {
        int x;
        printf("%d ", x); // undefined value δ����� 
    }
    printf("%d\n", x); // 0
    return 0;
	
	return 0;
} 
