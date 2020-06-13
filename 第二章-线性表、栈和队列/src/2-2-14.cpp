// File:    2-2-14.cpp
// Author:  csh
// Date:    2020/06/13
// ===================


#include <stack>
#include <iostream>

using namespace std;

#define MAXSIZE 1000

// 返回操作符的优先级
int priority(char operato){
    switch(operato){
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

// 判断是否是数字
bool isdigital(char num){
    if((num >= 48) && (num <= 57))
        return true;
    else if(num == '.')
        return true;
    return false;
}

// 判断是否是操作符
bool isoperator(char op){
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

// 中缀转后缀
char *back_expression(char *mid_expression){
    char c_temp = 0;
    char *str_temp;                 // 存放后缀表达式结果
    int str_temp_pos = 0;
    char stack_top_operator = 0;
    str_temp = new char[MAXSIZE];
    stack<char> S;
    S.push(';');                    // 哨兵，栈底的标志元素
    while((c_temp = *(mid_expression++)) != 0){
        if(c_temp == '(')           // 左括号入栈
            S.push(c_temp);
        else if(isdigital(c_temp)){ // 数字或.放入结果中
            str_temp[str_temp_pos++] = c_temp;
            while(((c_temp = *(mid_expression++)) != 0) && (isdigital(c_temp)))
                str_temp[str_temp_pos++] = c_temp;
            mid_expression--;
            str_temp[str_temp_pos++] = ' ';
        }
        else if(c_temp == ')'){     // 遇到右括号出栈，直到遇到左括号为止
            while((c_temp = S.top()) != '('){
                S.pop();
                str_temp[str_temp_pos++] = c_temp;
            }
        }
        else if(isoperator(c_temp)){        // 操作符
            // 比较操作符的优先级push或pop
            stack_top_operator = S.top();
            S.pop();
            while(priority(stack_top_operator) >= priority(c_temp)){
                str_temp[str_temp_pos++] = stack_top_operator;
                stack_top_operator = S.top();
                S.pop();
            }
            S.push(stack_top_operator);
            S.push(c_temp);
        }
    }

    // 弹出栈所有元素直至栈底标志";"，余下的元素存入str_temp中
    while((stack_top_operator = S.top()) != ';'){
        S.pop();
        if(stack_top_operator == '(')
            continue;
        str_temp[str_temp_pos++] = stack_top_operator;
    }
    str_temp[str_temp_pos] = 0;
    return str_temp;
}


int main(){
    char s[] = "((100-4)/3+3*(36-7))*2";
    char *ret;
    ret = back_expression(s);
    cout << ret << endl;
    return 0;
}
