/* 传引用参数导致的二义性 */
#include <iostream>
using namespace std;

int get(int n)
{
    return n;
}

int get(int &n)
{
    return n;
}

int main()
{
    int m = 10;
    int &rm = m;
    cout << get(m) << endl;
    cout << get(rm) << endl;
    
    return 0;
}