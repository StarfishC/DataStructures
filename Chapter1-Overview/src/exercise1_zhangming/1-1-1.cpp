/******************************************************************************
 * File:           1-1-1.cpp
 * Author:         caoshenghui <576365750@qq.com>
 * Github:         https://github.com/caoshenghui
 * Description:
 * LICENSE:        MIT
******************************************************************************/

#include <iostream>

// 或者使用std::swap
void swap(int&, int&);

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;
    int t; // 临时变量，用来交换值
    if (x < y)
        swap(x, y);
    if (x < z)
        swap(x, z);
    if (y < z)
        swap(y, z);
    std::cout << x << " " << y << " " << z << std::endl;
    return 0;
}

inline void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}
