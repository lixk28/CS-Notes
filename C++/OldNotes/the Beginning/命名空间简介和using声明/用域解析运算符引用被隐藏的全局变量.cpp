#include <iostream>
using namespace std;

int x = 1;

int main()
{
    int x = 2;
    x = 3;
    ::x = -1;
    cout << x << endl;
    cout << ::x << endl;
    {
        int x = 3;
        x = 4;
        ::x = 10;
        cout << x << endl;
        cout << ::x << endl;
    }

    return 0;
}