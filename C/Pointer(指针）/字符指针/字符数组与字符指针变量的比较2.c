#include <stdio.h>
#include <string.h>

int main() {
    char *s1 = "hello world";
    char s2[] = "hello world";
    *s1 = 'H';   // (1)
    *s2 = 'H';   // (2)
    s1 = s2 + 1; // (3)
    s2 = s2 + 1; // (4)  
    return 0;
}
// (4)�ڱ���ʱ����  ��Ϊs2���ַ�����������ָ�볣�������ܸı�����ֵ 
