#include <iostream>
using namespace std;

void Date(int day = 1, int month = 1, int year = 2000);
//可以全部都有默认参数
//也可以部分有默认参数，但是部分有必须从左到右连续有默认参数，中间不能缺

int main()
{
    Date();
    Date(15);            // day = 15
    Date(15, 2);         // day = 15, month = 2
    Date(15, 2, 2012);   // day = 15, month = 2, year = 2012

    return 0;
}

void Date(int day, int month, int year) //这里不需要再标明默认参数的值
{
    cout << "day = " << day << " ";
    cout << "month = " << month << " ";
    cout << "year = " << year << endl;
}