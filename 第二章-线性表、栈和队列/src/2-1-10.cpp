// File:    2-1-10.cpp
// Author:  csh
// Date:    2020/07/18
// ===================


#include <stack>
#include <iostream>

typedef char Elem;

bool isMatch(Elem *E, int length){
    using std::stack;
    stack<Elem> s;
    for(int i = 0; i < length; i++){
        if(E[i] == '(')
            s.push(E[i]);
        else if(E[i] == ')'){
            // 栈为空且碰到了右括号则匹配失败
            if(s.empty())  return false;
            else{
                s.pop();
            }
        }
    }
    // 遍历完毕后栈空，那么匹配成功
    if(s.empty()) return true;
    return false;
}


int main(){
    using namespace std;
    Elem E[] = {'a', 'b', 'c', '(', ')'};
    bool ret;
    ret = isMatch(E, 5);
    Elem E2[] = {')', 'c', ')'};
    bool ret2 = isMatch(E2, 3);
    cout << ret << endl;
    cout << "ret2: " << ret2 << endl;
    return 0;
};
