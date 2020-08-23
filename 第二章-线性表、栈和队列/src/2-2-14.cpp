// File:    tmp.cpp
// Author:  csh
// Date:    2020/08/22
// ===================


#include <stack>
#include <cstring>
#include <iostream>
using namespace std;


class MidToPost{
    private:
        int priority(char op);              // 返回操作符优先级
        bool isDigit(char num);             // 判断时候为数字
        bool isOperator(char op);           // 判断是否为操作符
    public:
        string mid;
    public:
        MidToPost(){};
        MidToPost(string str){
            mid = str;
        }
        string transfer();                  // 转换成后缀表达式
};


bool MidToPost::isDigit(char num){
    if(num >= 48 && num <= 57)
        return true;
    else if(num == '.')
        return true;
    return false;
}

int MidToPost::priority(char op){
    switch(op){
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
        default:
            return 0;
    }
}

bool MidToPost::isOperator(char op){
    switch(op){
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    } 
}

string MidToPost::transfer(){
    string post = "";    
    char top;                                   // 存储栈顶元素
    stack<char> sta = stack<char>();
    sta.push(';');                              // 栈底标志元素
    for(auto i = 0; i < mid.size(); i++){
        char tmp = mid[i];
        if(tmp == '(')
            sta.push(tmp);                      // 左括号入栈
        else if(isDigit(tmp)){                  // 如果是数字或'.'则存入post
            post += tmp;
            while(isDigit((tmp = mid[++i])))
                post += tmp;
            i--;                                // 已经不是数字了，返回上一个位置
            post += " ";
        }
        else if(tmp == ')'){                    // 遇到右括号出栈，直到遇到左括号为止
            top = sta.top();
            sta.pop();
            while(top != '('){
                post += top;
                post += " ";
                top = sta.top();
                sta.pop();
            }
        }
        else if(isOperator(tmp)){               // 如果是操作符
            char top = sta.top();
            sta.pop();
            while(priority(top) >= priority(tmp)){
                post += top;
                post += " ";
                top = sta.top();
                sta.pop();
            }
            sta.push(top);                      // 当tmp优先级更大时
            sta.push(tmp);
        }
    }
    // 弹出栈所有元素直至栈底标志
    top = sta.top();
    while(top != ';'){
        sta.pop();
        post += top;
        post += " ";
        top = sta.top();
    }
    return post;
}


int main(){
    MidToPost mid = MidToPost("((100-4)/3+3*(36-7))*2");
    string ret;
    ret = mid.transfer();
    cout << ret << endl;
    return 0;
}
