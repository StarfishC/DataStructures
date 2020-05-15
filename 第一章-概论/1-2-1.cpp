// File:    1-2-1.cpp
// Author:  csh
// Date:    2020/05/01
// ===================


// 未做完，学完再补
#include <iostream>
#include <string>

using namespace std;



class strings{
    public:
        string str;
        strings *pNext;
        strings();
        strings(string s){str = s;};
};


class ArrList{
    private:
        strings *aList;
        int curlen;
    public:
        ArrList(){
            curlen = 0;
            aList = NULL;
        }
        int length(){return curlen;}        // 链表长度
        int compareStr(char a, char b){
            int ret;
            // 1. a,b相等
            if(a-b == 0) ret = 0;

            // 2. a,b都属于A-Z或都属于0-9
            if(((a-'A' >= 0) && (b-'A' >= 0)) || ((a-'A' < 0) && (b-'A' < 0))){
                if(a-b > 0) ret = 1;
            }else{
                if(a-b > 0) ret = -1;
            }
            return ret;
        }
        bool compare(string a, string b){
            for(int k = 0; a[k] && b[k]; k++){
                int ret = compareStr(a[k], b[k]);
                if(ret == 0) continue;
                if(ret == 1) return true;
                if(ret == -1) return false;
            }
            return true;
        }
        void append(strings *s){
            strings *current = aList;
            strings *previous = NULL;
            bool stop = false;
            while(current != NULL && not stop){
                if(compare(current->str, s->str) == true)
                    stop = true;
                else{
                    previous = current;
                    current = current->pNext;
                }
            }
            if(previous == NULL){
                s->pNext = aList;
                aList = s;
            }else{
                s->pNext = current;
                previous->pNext = s;
            }
        }
        void printAll(){
            strings *tmp = aList;
            while(tmp){
                cout << tmp->str << endl;
                tmp = tmp->pNext;
            }
        }
};



int main(){
    strings a[8] = {strings("ABC"), strings("5C"), strings("PABC"), strings("CXY"),
                    strings("CRSI"), strings("7"), strings("B899"), strings("B9")};
    ArrList list = ArrList();
    for(int i = 0; i < 8; i++){
        list.append(&a[i]);
    }
    list.printAll();

    return 0;
}

