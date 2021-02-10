/* 类型的隐式转换导致的二义性 */
#include <iostream>
using namespace std;

long get(long n)
{
    return n;
}

double get(double x)
{
    return x;
}

char get(char c)
{
    return c;
}

int main()
{
    cout << get(100) << endl;
    //编译器将100进行类型的隐式转换，可以匹配为long、double或char
    //多个匹配产生冲突，导致二义性

    return 0;
}