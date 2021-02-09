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
/*输出的结果是 1 2  因为 case1子句结束后 没有break语句！ 不会跳出switch结构
  编译时吧default语句也作为case1的子句  一起执行
*/  
