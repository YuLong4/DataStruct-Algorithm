//
// Created by Yulong on 2022/9/4.
//

#include "Recursion.h"

/*
 * ���Ժ���
 */
void Recursion::test_Recursion()
{
    /*
     * Function:factorial
     * ���Խ׳˺���
     */
    cout<<"ִ�к���:"<< "factorial:" <<endl;
    cout<<"5�Ľ׳�:"<<factorial(5) <<endl;

    /*
     * Function:fibonacci
     * ����fibonacci����
     */
    cout<<"\nִ�к���:"<< "fibonacci:" <<endl;
    cout<<"ǰ20��Fibonacci��:"<<endl;
    for(int i=0;i<20;i++)
    {
        cout<<fibonacci(i)<<" ";
    }
    cout<<endl;

    /*
     * Function:hanota
     * ����hanota����
     */
    cout<<"\nִ�к���:"<< "hanota:" <<endl;
    vector<int> A = {5,4,3,2,1}, B, C;
    cout<<"��ʼ����:"<<endl;
    cout<<"A:";
    for(int i : A) cout<<i<<" ";
    cout<<"\nB:";
    for(int i : B) cout<<i<<" ";
    cout<<"\nC:";
    for(int i : C) cout<<i<<" ";
    hanota(A, B, C, A.size());
    cout<<"\n�ƶ���:"<<endl;
    cout<<"A:";
    for(int i : A) cout<<i<<" ";
    cout<<"\nB:";
    for(int i : B) cout<<i<<" ";
    cout<<"\nC:";
    for(int i : C) cout<<i<<" ";
    cout<<endl;

    /*
     * Function:BinarySearch
     * ���Զ��ֲ���
     */
    int a[10] = {1, 23, 42, 56, 78, 89, 100, 140, 150, 560};
    int res= BinarySearch(a, 56, 10);
    if(res!=-1)
    {
        cout<<"�ҵ���x��λ�ã��±꣩Ϊ��"<<res<<endl;
    }
    else cout<<"δ�ҵ�"<<endl;
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

/*
 * ��ŵ�����⣺
 * �ھ��人ŵ�������У��� 3 �����Ӽ� N ����ͬ��С�Ĵ���Բ�̣����ӿ��Ի�������һ�����ӡ�
 * һ��ʼ�������������϶��°������������ڵ�һ��������(��ÿһ������ֻ�ܷ��ڸ������������)��
 * �ƶ�Բ��ʱ�ܵ���������:
 * (1) ÿ��ֻ���ƶ�һ������;
 * (2) ����ֻ�ܴ����Ӷ��˻����Ƶ���һ������;
 * (3) ����ֻ�ܵ��ڱ�����������ϡ�
 * ���ӣ�https://leetcode.cn/problems/hanota-lcci
 *
 * 4������: A��B��CΪ����, nΪ��n��ߵ����Ƶ���һ������
 * ˼·��n��ߵ�����A�ƶ���C�൱��n-1��ߵ����ƶ���B���ٰ�n�ƶ���C���ٽ�B�е�n-1���ƶ���C
 * �ݹ��ֹ������Aֻ��һ���
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

/*
 * ���η�:
 * ���ֲ���
 * ���������ֱ�Ϊ���������顢����ֵ�����鳤��
 * �ҵ�xʱ�������������е�λ��(�±�), δ�ҵ�����0
 */
int Recursion::BinarySearch(int a[], int x, int n)
{
    int left= 0, right= n-1;
    while(left<= right)
    {
        int middle= (left+right)/2;
        if(x == a[middle])
            return middle;
        if(x > a[middle])
            left= middle+1;
        else
            right= middle-1;
    }
    return -1;
}






