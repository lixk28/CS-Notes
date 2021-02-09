/* Function Overloading */
#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}
double sum(double x, double y)
{
    return x + y;
}
string sum(string s1, string s2)
{
    return s1 + s2;
}

int main()
{
    int a, b;
    double x, y;
    string s1, s2;

    cout << sum(10, 10) << endl;
    cout << sum(10.5, 10.5) << endl;
    cout << sum("I am", " Groot") << endl;

    return 0;
}