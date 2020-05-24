// File:    栈的应用-后缀表达式求值.cpp
// Author:  csh
// Date:    2020/05/24
// ===================

#include <stack>
#include <iostream>
using namespace std;


class Calculator{
    private:
        stack<double> s;
        bool getTwoOpreands(double& opd1, double& opd2);                // 栈顶弹出两个操作数
        void compute(char op);                                          // 取两个操作数，并计算
    public:
        Calculator(void){};
        void run();                         // 读入后缀表达式，遇到符号"="结束计算
};

bool Calculator::getTwoOpreands(double& opd1, double& opd2){
    if(s.empty()){
        cerr << "Missing operand!" << endl;
        return false;
    }
    opd1 = s.top();
    s.pop();
    if(s.empty()){
        cerr << "Missing operand!" << endl;
        return false;
    }
    opd2 = s.top();
    return true;
}

void Calculator::compute(char op){
    bool result;
    double operand1, operand2;
    result = getTwoOpreands(operand1, operand2);
    if(result == true){
        switch(op){
            case '+' : s.push(operand2 + operand1);
                       break;
            case '-' : s.push(operand2 - operand1);
                       break;
            case '*' : s.push(operand2 * operand1);
                       break;
            case '/' : if(operand1 == 0.0){
                            cerr << "Divide by zero!" << endl;
                       }else{
                            s.push(operand2/operand1);
                       }
                       break;
        }
    }else{
        cerr << "error!" << endl;
    }
}

void Calculator::run(){
    char c;
    double newOperand,res;
    while(cin >> c, c != '='){
        switch(c){
            case '+':
            case '-':
            case '*':
            case '/':
                compute(c);
                break;
            default:
                cin.putback(c);
                cin >> newOperand;
                s.push(newOperand);
                break;
        }
    }
    res = s.top();
    s.pop();
    cout << res << endl;
}

