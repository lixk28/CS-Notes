#include <iostream>
using namespace std;

namespace User{
    int x = 0;
};

int main()
{
    User::x = 1;
    int x = 10;
    cout << x;

    return 0;
}