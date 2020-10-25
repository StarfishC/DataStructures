// File:    后缀表达式求值.cpp
// Author:  csh
// Date:    2020/10/24
// ===================


#include <iostream>
#include <stack>


class Calculator{
    private:
        std::stack<double> s;
        bool getTwoOperands(double &opd1, double &opd2);
        void compute(char op);
    public:
        Calculator(){
            s = std::stack<double>();
        }
        void run();
        void clear();
};

bool Calculator::getTwoOperands(double &opd1, double &opd2){
    using namespace std;
    if(s.empty()){
        cerr << "Missing operand!" << endl;
        return false;
    }
    opd1 = s.top();
    s.pop();
    if(s.empty()){
        cerr << "Miss operand! " << endl;
        return false;
    }
    opd2 = s.top();
    s.pop();
    return true;
}

void Calculator::compute(char op){
    using namespace std;
    bool result;
    double opd1, opd2;
    result = getTwoOperands(opd1, opd2);
    if(result){
        switch(op){
            case '+': s.push(opd2 + opd1);
                      break;
            case '-': s.push(opd2 - opd1);
                      break;
            case '*': s.push(opd2 * opd1);
                      break;
            case '/': if(!opd1){
                          cerr << "Divid by zeor!" << endl;
                          s = stack<double>();
                      }
                      else
                          s.push(opd2 / opd1);
                      break;
        }
    }
    else
        s = stack<double>();
}

void Calculator::run(){
    using namespace std;
    char c;
    double newOpeand, res;
    while(cin >> c, c != ' ' && c != '='){
        switch(c){
            case '+':
            case '-':
            case '*':
            case '/':
                compute(c);
                break;
            default:
                cin.putback(c);
                cin >> newOpeand;
                s.push(newOpeand);
                break;
        }
    }
    res = s.top();
    cout << res << endl;
}


int main(){
    Calculator c;
    c.run();
}
