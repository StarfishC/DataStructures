// File:    1-4-5.cpp
// Author:  csh
// Date:    2020/05/01
// ===================


#include <iostream>

using namespace std;

typedef enum {A, B} SchoolName;
typedef enum {FEMALE, MALE} Sex;
typedef enum {X, Y, Z} Event;


class Grade{
    public:
        SchoolName school;          // 学校
        Sex sex;                    // 性别
        Event e;                    // 项目名称
        int score;                  // 得分(成绩)
        Grade(){};
        Grade(SchoolName sn, Sex s, Event ev, int sc)
            : school{sn}, sex{s}, e{ev}, score{sc} {}
};


class Sum{
    private:
        SchoolName school;          // 校名
        int malesum;                // 男总分
        int femalesum;              // 女总分
        int totalsum;               // 团体总分
    public:
        Sum();
        Sum(SchoolName sn);
        void getScore(Grade gra[], int n);   // 获取分数
        void showScore();           // 输出总分
};

Sum::Sum(SchoolName sn){
    femalesum = 0;
    malesum = 0;
    totalsum = 0;
    school = sn;
}

void Sum::getScore(Grade gra[], int n){
    for(int i = 0; i < n; i++){
        Grade temp = gra[i];
        if(temp.school == this->school){
            if(temp.sex == FEMALE)
                this->femalesum += temp.score;
            else
                this->malesum += temp.score;
            this->totalsum += temp.score;
        }
    } 
}

void Sum::showScore(){
    cout << "学校" << school << "分数如下:" << endl;
    cout << "男总分:" << malesum << endl;
    cout << "女总分:" << femalesum << endl;
    cout << "团体总分:" << totalsum << endl;
}



int main(){
    // 假设有四条记录
    Grade report[4];
    report[0] = Grade(A, MALE, X, 90);
    report[1] = Grade(B, MALE, X, 80);
    report[2] = Grade(A, FEMALE, X, 95);
    report[3] = Grade(A, MALE, X, 90);

    Sum ASchool(A);
    ASchool.getScore(report, 4);
    ASchool.showScore();
    return 0;
}
