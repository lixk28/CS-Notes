#include <stdio.h>
int main()
{
	void foo(int *p);
    int i = 97, *p = &i;
    foo(&i);
    printf("%d ", *p);
}

void foo(int *p)
{
    int j = 2;
    p = &j;
    printf("%d ", *p);
}
