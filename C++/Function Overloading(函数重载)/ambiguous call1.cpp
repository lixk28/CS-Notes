/* 类型的隐式转换导致的二义性 */
#include <iostream>
using namespace std;

int sum1(int a, int b) // 1
{
    return a + b;
} 
double sum1(double a, double b) // 2
{
    return a + b;
}

int sum2(int a, int b) // 3
{
    return a + b;
}
char sum2(char a, int b) // 4
{
    return a + b;
}


int main()
{
    cout << sum1(10, 10.5) << endl;
    //注释掉函数1，则结果是20.5
    //注释掉函数2，则结果是20
    //因为编译器会将参数进行隐式类型转换

    cout << sum2('A', 32) << endl;   //注释掉4，调用3；不注释4，调用4
    cout << sum2(32, 'A') << endl;   //调用3

    return 0;
}