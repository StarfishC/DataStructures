/******************************************************************************
 * File:           1-1-6.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/

#include <iostream>

int test(int);

int main(int argc, char* argv[])
{
    int ret1 = test(100);
    int ret2 = test(160);
    std::cout << "Times: " << ret1 << std::endl;
    std::cout << "Times: " << ret2 << std::endl;
    return 0;
}

int test(int n)
{
    int m = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 2 * i; j <= n; j++)
            m = m + 1;
    return m;
}
