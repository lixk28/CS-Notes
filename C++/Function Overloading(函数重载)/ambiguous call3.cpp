/* 函数的默认参数导致的二义性 */
#include <iostream>
using namespace std;

int sum(int a, int b, int c = 0)
{
    return a + b + c;
}

int sum(int a, int b)
{
    return a + b;
}

int get()
{
    return 233;
}

int get(int n = 233)
{
    return n;
}

int main()
{
    cout << sum(1, 2) << endl;
    //编译器无法确定是调用sum(1,2,0)还是sum(1,2),导致二义性

    cout << get() << endl;
    //编译器无法确定是调用get()还是get(233),导致二义性

    return 0;
}