#include <stdio.h>
int main()
{
    int ch;
    printf("enter a value between 1 to 2:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("1 ");
    default:
        printf("2\n");
    }
}
/*����Ľ���� 1 2  ��Ϊ case1�Ӿ������ û��break��䣡 ��������switch�ṹ
  ����ʱ��default���Ҳ��Ϊcase1���Ӿ�  һ��ִ��
*/  
