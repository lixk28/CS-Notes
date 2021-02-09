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

// != 的优先级低于 =
// !=是左结合的 =是右结合的
// 因此2中先执行 getchar() != '\n' 的运算
// 因为输入abc都不为'\n' 所以该逻辑表达式的值为 1
// 将这个值赋给c2  因此 c2 都是1 
