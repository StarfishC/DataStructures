// File:    3-2-1.cpp
// Author:  csh
// Date:    2020/06/14
// ===================

#include <cassert>
#include <iostream>


class string{
    private:
        char *str;                                      // 字符串
        int size;                                       // 字符串大小
    public:
        string();                                       // 默认构造函数
        string(const char *s);                          // 带参数构造函数
        ~string();                                      // 析构函数
        string substr(const int p, const int len);      // 子串
        int strlength();                                // 字符串大小
        int Find(const char c);                         // 找字符c第一次出现位置
        int FindLast(const char c);                     // 找字符c最后一次出现位置
        bool insert(string s, const int p);             // 位置p插入字符串s
        bool remove(const int p, const int len);        // 位置p开始移除长度为len的字符串
        string operator+(const string& b);              // 运算符重载
        void showstr(){
            using std::cout;
            using std::endl;
            for(int i = 0; i < size; i++)
                cout << str[i] << "";
            cout << endl;
        }
};

string::string(const char *s){
    using std::cout;
    using std::endl;
    cout << "sizeof(s):" << sizeof(s);
    cout << "sizeof(char):" << sizeof(char) << endl;
    size = sizeof(s)/sizeof(char);
    cout << size << endl;
    str = new char[size];
    for(int i = 0; i < size; i++)
        str[i] = s[i];
    size = size - 1;                // 不应包含'\0'
}

string::~string(){
    delete []str;
}


int main(){
    char s[] = "a12a";
    string str = string(s);
    // str.showstr();
    using std::cout;
    using std::endl;
    int a[] = {1, 2, 3};
    cout << sizeof(a)/sizeof(int) << endl;
    cout << sizeof(s)/sizeof(char) << endl;
    return 0;
}
