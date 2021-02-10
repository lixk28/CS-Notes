#include <iostream>
using namespace std;

int main()
{
    int a = 9;
    const int& aref = a;
    aref++;  //error
    cout << a;

    return 0;
}