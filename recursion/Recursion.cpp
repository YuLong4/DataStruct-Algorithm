//
// Created by Yulong on 2022/9/4.
//

#include "Recursion.h"

/*
 * ���Ժ���
 */
void Recursion::test_Recursion()
{
    cout<<"ִ�к���:"<< __func__ <<endl;
    cout<<"5�Ľ׳�:"<<factorial(5) <<endl;
    cout<<"ǰ20��Fibonacci��:"<<endl;
    for(int i=0;i<20;i++)
    {
        cout<<fibonacci(i)<<" ";
    }
    cout<<endl;
}

/*
 * �������Ľ׳ˣ��ݹ鷽��
 */
int Recursion::factorial(int n)
{
    if(n==0) return 1;      //0�Ľ׳�Ϊ1 ͬʱҲ�ǳ���
    return n* factorial(n-1);
}

/*
 * Fibonacci���У��ݹ鷽��
 */
int Recursion::fibonacci(int n)
{
    if(n<=1) return 1;
    return fibonacci(n-1)+ fibonacci(n-2);
}






