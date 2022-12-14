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
     * 递归方法实现基本算法
     * 阶乘、Fibonacci数列、汉诺塔问题、二分查找、快速排序
     */
public:
    void test_Recursion();
    int Factorial(int n);
    int Fibonacci(int n);
    void Hanota(vector<int>& A, vector<int>& B, vector<int>& C, int n);
    int BinarySearch(int a[], int x, int n);
    void QuickSort(int a[], int left, int right);
    void RotateArray(vector<int>& nums, int k);
};


#endif //RECURSION_RECURSION_H
