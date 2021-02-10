#include <iostream>
using namespace std;

namespace User{
    int x = 0;
};

// using User::x; //rigth

int main()
{
    // using User::x; //error
    int x = 1;
    cout << x;

    return 0;
}