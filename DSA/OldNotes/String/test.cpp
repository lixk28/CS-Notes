#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s = "Hello";
    cout << s.substr(0,1) << endl;
    cout << s.substr(0,0) << endl;

}