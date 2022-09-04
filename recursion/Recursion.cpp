//
// Created by Yulong on 2022/9/4.
//

#include "Recursion.h"

/*
 * 测试函数
 */
void Recursion::test_Recursion()
{
    cout<<"执行函数:"<< "factorial:" <<endl;
    cout<<"5的阶乘:"<<factorial(5) <<endl;
    cout<<"\n执行函数:"<< "fibonacci:" <<endl;
    cout<<"前20个Fibonacci数:"<<endl;
    for(int i=0;i<20;i++)
    {
        cout<<fibonacci(i)<<" ";
    }
    cout<<endl;
    cout<<"\n执行函数:"<< "hanota:" <<endl;

    vector<int> A = {5,4,3,2,1}, B, C;
    cout<<"初始数据:"<<endl;
    cout<<"A:";
    for(int i : A) cout<<i<<" ";
    cout<<"\nB:";
    for(int i : B) cout<<i<<" ";
    cout<<"\nC:";
    for(int i : C) cout<<i<<" ";
    hanota(A, B, C, A.size());
    cout<<"\n移动后:"<<endl;
    cout<<"A:";
    for(int i : A) cout<<i<<" ";
    cout<<"\nB:";
    for(int i : B) cout<<i<<" ";
    cout<<"\nC:";
    for(int i : C) cout<<i<<" ";
}

/*
 * 计算数的阶乘，递归方法
 */
int Recursion::factorial(int n)
{
    if(n==0) return 1;      //0的阶乘为1 同时也是出口
    return n* factorial(n-1);
}

/*
 * Fibonacci数列，递归方法
 */
int Recursion::fibonacci(int n)
{
    if(n<=1) return 1;
    return fibonacci(n-1)+ fibonacci(n-2);
}

/*
 * 汉诺塔问题：
 * 在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。
 * 一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。
 * 移动圆盘时受到以下限制:
 * (1) 每次只能移动一个盘子;
 * (2) 盘子只能从柱子顶端滑出移到下一根柱子;
 * (3) 盘子只能叠在比它大的盘子上。
 * 链接：https://leetcode.cn/problems/hanota-lcci
 *
 * 4个参数: A、B、C为柱子, n为将n层高的塔移到另一个上面
 * 思路：n层高的塔从A移动到C相当于n-1层高的塔移动到B，再把n移动到C，再将B中的n-1层移动到C
 * 递归截止条件：A只有一层高
 */
void Recursion::hanota(vector<int> &A, vector<int> &B, vector<int> &C, int n)
{
    if(n==1)
    {
        C.push_back(A.back());
        A.pop_back();
        return;
    }
    hanota(A, C, B, n-1);
    hanota(A, B, C, 1);
    hanota(B, A, C, n-1);

}






