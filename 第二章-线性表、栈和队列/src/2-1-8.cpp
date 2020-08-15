// File:    2-1-8.cpp
// Author:  csh
// Date:    2020/08/15
// ===================


#include "../headers/linear.hpp"


void Solution(ArrList<int>* A, ArrList<int>* B, ArrList<int>* C){
    int lenA, lenB;
    lenA = A->length();
    lenB = B->length();

    for(int i = 0, j = 0; i < lenA && j < lenB; ){
        int valueA,valueB;
        A->getValue(i, valueA);
        B->getValue(j, valueB);

        if(valueA == valueB){
            C->append(valueA);
            i++, j++;
        }
        else if(valueA > valueB)        // A大B小,j++
            j++;
        else if(valueA < valueB)
            i++;
    }
}


int main(){
    ArrList<int> A = ArrList<int>(10);
    ArrList<int> B = ArrList<int>(10);
    ArrList<int> C = ArrList<int>(10);

    A.append(1);
    A.append(3);
    A.append(5);
    A.append(6);
    A.append(8);
    A.showAll();

    B.append(1);
    B.append(2);
    B.append(3);
    B.append(6);
    B.append(7);
    B.showAll();

    Solution(&A, &B, &C);
    C.showAll();
    return 0;

}
