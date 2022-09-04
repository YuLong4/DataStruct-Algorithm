//
// Created by Yulong on 2022/9/4.
//

#include "Recursion.h"

/*
 * 测试函数
 */
void Recursion::test_Recursion()
{
    cout<<"执行函数:"<< __func__ <<endl;
    cout<<"5的阶乘:"<<factorial(5) <<endl;
    cout<<"前20个Fibonacci数:"<<endl;
    for(int i=0;i<20;i++)
    {
        cout<<fibonacci(i)<<" ";
    }
    cout<<endl;
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






