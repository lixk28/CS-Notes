#include <iostream>

int main()
{
    int sum = 0, data = 0;
    while(std::cin >> data) // 输入 ctrl+z 再敲 enter 即可输入文件结束符EOF
        sum = sum + data;
    
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}