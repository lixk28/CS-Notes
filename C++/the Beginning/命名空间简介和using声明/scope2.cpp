#include <iostream>
using namespace std;

class A
{
    public:
        int x;
};

class B
{
    public:
        static int x;
};

namespace User{
    int x = 0;
};

int main()
{
    A::x; //error

    A a;
    a.x; //right

    B::x; //right


    return 0;
}