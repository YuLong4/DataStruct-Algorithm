//
// Created by Yulong on 2022/9/4.
//

#ifndef RECURSION_RECURSION_H
#define RECURSION_RECURSION_H
#include <iostream>
using namespace std;
#include <vector>

class Recursion
{
    /*
     * 递归方法
     */
public:
    void test_Recursion();
    int factorial(int n);
    int fibonacci(int n);
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C, int n);
};


#endif //RECURSION_RECURSION_H
