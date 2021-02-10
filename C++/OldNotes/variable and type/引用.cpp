#include <iostream>

using namespace std;

int main()
{
    int i = 1;
    int &refi1 = i;
    int &refi2 = i;

    refi1 = 2;
    cout << "i = " << i << endl;
    cout << "refi1 = " << refi1 << endl << endl;

    refi1 = refi1 * refi1;
    cout << "i = " << i << endl;
    cout << "refi1 = " << refi1 << endl << endl;

    refi1 = refi1 / 4;
    cout << "i = " << i << endl;
    cout << "refi1 = " << refi1 << endl << endl;

    int j = 9;
    refi1 = j; // 将 j 的值赋给与 refi1 绑定的对象
    cout << "i = " << i << endl;
    cout << "refi1 = " << refi1 << endl << endl;

    j = refi2; // j 的值被修改为与 refi2 绑定的对象的值
    cout << "j = " << j << endl << endl;

    int k = 3;
    int &refk1 = k;
    int &refk2 = refk1; // refk2 绑定到与 refk2 绑定的对象上，即绑定到k上
    cout << "refk2 = " << refk2 << endl << endl;

    return 0;
}