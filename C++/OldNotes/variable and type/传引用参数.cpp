#include <iostream>

using namespace std;

void reset(int &n)
{
    cout << "Please input an integer:" << endl;
    cin >> n;
}

void swap(int &x, int &y)
{
    int t;
    t = x;
    x = y;
    y = t;
}

int main()
{
    int a, b, c;
    int &ra = a, &rb = b, &rc = c;
    cout << "Please input 3 integers:" << endl;
    cin >> a >> b >> c;
    
    cout << "a = " << a << endl
         << "b = " << b << endl
         << "c = " << c << endl;

    reset(ra);
    cout << "a after reset: ";
    cout << "a = " << a << endl;

    swap(rb,rc);
    cout << "b and c after swap:" << endl;
    cout << "b = " << b << endl
         << "c = " << c << endl;
    

    return 0;
}