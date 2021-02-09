#include <iostream>

namespace mfc
{
    int inflag;
}

namespace owl
{
    int inflag;
}

// using namespace mfc;
// using namespace owl;

int main()
{
    int inflag;
    //如果上面取消两句using声明的注释，那么编译器会在这一句报错，因为无法识别inflag的所属

    inflag = 100;        // the inflag in main function
    mfc::inflag = 3;     // mfc's inflag
    owl::inflag = -823;  // owl's inflag

    return 0;
}