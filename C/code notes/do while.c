
#include <stdio.h>
int main()
{
    do
        printf("In while loop\n");
    while (0);
        printf("After loop\n");
}
/* 输出的结果是  In while loop
                 After loop
    因为 do while语句的执行过程是 先无条件地执行循环体 再来判断循环条件是否成立
	如果成立 继续执行 否则结束循环
	也就是说 do while必定执行过一次循环体 无论循环条件是否成立 
*/ 
