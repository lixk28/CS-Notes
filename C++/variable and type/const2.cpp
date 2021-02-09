#include <iostream>
using namespace std;

void f1(const int& aref); // only read
void f2(int & aref); // only write

int main()
{
    int a = 9;
    f1(a);
    f2(a);

    return 0;   
}