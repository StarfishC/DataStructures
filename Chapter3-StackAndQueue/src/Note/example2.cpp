// File:    example2.cpp
// Author:  csh
// Date:    2021/02/21
// ===================


#include <iostream>
#include <stack>


class Calculator
{
    private:
        std::stack<double> S;
        bool GetTwoOperands(double &opd1, double &opd2);
        void Compute(char op);
    public:
        Calculator(): S(std::stack<double>()){}
        void run();
        void clear();
};


bool Calculator::GetTwoOperands(double &opd1, double &opd2)
{
    using namespace std;
    if(S.empty())
    {
        cerr << "Missing operand!" << endl;
        return false;
    }
    opd1 = S.top();
    S.pop();
    if(S.empty())
    {
        cerr << "Missing operand!" << endl;
        return false;
    }
    opd2 = S.top();
    S.pop();
    return true;
}

void Calculator::Compute(char op)
{
    using namespace std;
    bool result;
    double operand1, operand2;
    result = GetTwoOperands(operand1, operand2);
    if(result == true)
    {
        switch(op)
        {
            case '+': S.push(operand2 + operand1);
                      break;
            case '-': S.push(operand2 - operand1);
                      break;
            case '*': S.push(operand2 * operand1);
                      break;
            case '/': if(abs(operand1) < 1E-7)
                      {
                          cerr << "Divide by 0!" << endl;
                          S = stack<double>();
                      }else
                          S.push(operand2 / operand1);
                      break;
        }
    }else
        S = stack<double>();
}

void Calculator::run()
{
    using namespace std;
    char c;
    double newOperand, res;
    while(cin >> c, c != '=')
    {
        switch(c)
        {
            case '+':
            case '-':
            case '*':
            case '/':
                Compute(c);
                break;
            default:
                cin.putback(c);
                cin >> newOperand;
                S.push(newOperand);
                break;
        }
    }
    res = S.top();
    cout << res << endl;
}


int main()
{
    // 23 34 45 * 5 6 + 7 + / +
    Calculator c;
    c.run();
}
