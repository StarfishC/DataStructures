// File:    4-3-1.cpp
// Author:  csh
// Date:    2020/08/29
// ===================



#include <string>
#include <iostream>


int main()
{
    using namespace std;
    string A = " ";
    string B = "MULE";
    string C = "OLD";
    string D = "MY";

    cout << "A + B = " << A + B << endl;
    cout << "B + A = " << B + A << endl;
    cout << "D + C + B = " << D + C + B << endl;
    cout << "B.substr(3,2) = " << B.substr(3, 2) << endl;
    cout << "C.substr(1,1) = " << C.substr(1, 1) << endl;
    cout << "A.strlength() = " << A.length() << endl;
    cout << "D.strlength() = " << D.length() << endl;
    cout << "B.Find('L') = " << B.find('L') << endl;
    cout << "C.FindLast('D') = " << C.find_last_of('D') << endl;
    cout << "D.insert(B,2) = " << D.insert(2, B) << endl;
    cout << "B.insert(B,1) = " << B.insert(1, B) << endl;
    return 0;
}
