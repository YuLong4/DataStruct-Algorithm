//
// Created by Yulong on 2022/9/4.
//

#include "Recursion.h"

/*
 * 测试函数
 */
void Recursion::test_Recursion()
{
    /*
     * Function:Factorial
     * 测试阶乘函数
     */
    cout<<"执行函数:"<< "Factorial:" <<endl;
    cout << "5的阶乘:" << Factorial(5) << endl;

    /*
     * Function:Fibonacci
     * 测试fibonacci函数
     */
    cout<<"\n执行函数:"<< "Fibonacci:" <<endl;
    cout<<"前20个Fibonacci数:"<<endl;
    for(int i=0;i<20;i++)
    {
        cout << Fibonacci(i) << " ";
    }
    cout<<endl;

    /*
     * Function:Hanota
     * 测试hanota函数
     */
    cout<<"\n执行函数:"<< "Hanota:" <<endl;
    vector<int> A = {5,4,3,2,1}, B, C;
    cout<<"初始数据:"<<endl;
    cout<<"A:";
    for(int i : A) cout<<i<<" ";
    cout<<"\nB:";
    for(int i : B) cout<<i<<" ";
    cout<<"\nC:";
    for(int i : C) cout<<i<<" ";
    Hanota(A, B, C, A.size());
    cout<<"\n移动后:"<<endl;
    cout<<"A:";
    for(int i : A) cout<<i<<" ";
    cout<<"\nB:";
    for(int i : B) cout<<i<<" ";
    cout<<"\nC:";
    for(int i : C) cout<<i<<" ";
    cout<<endl;

    /*
     * Function:BinarySearch
     * 测试二分查找
     */
    cout<<"\n执行函数:"<< "BinarySearch:" <<endl;
    int a[10] = {1, 23, 42, 56, 78, 89, 100, 140, 150, 560};
    cout<<"在数列:";
    for(int i : a) cout<<i<<" ";
    cout<<"中 查找56\n";
    int res= BinarySearch(a, 56, 10);
    if(res!=-1)
    {
        cout<<"找到了56，位置（下标）为："<<res<<endl;
    }
    else cout<<"未找到"<<endl;


    /*
     * Function: QuickSort
     * 测试快速排序
     */
    cout<<"\n执行函数:"<< "QuickSort:" <<endl;
    int b[10] = {50, 823, 23, 65, 78, 101, 100, 1, 150, 10};
    cout<<"原数列为：";
    for(int i: b) cout<<i<<" ";
    QuickSort(b, 0, 9);
    cout<<"\n快速排序后:";
    for(int i: b) cout<<i<<" ";
    cout<<endl;


    /*
     * 测试轮转数组函数
     */
    vector<int> nums={1,2,3,4,5,6,7};
    int k=4;
    cout<<"\n原数组为:";
    for(int i: nums) cout<<i<<" ";
    cout<<endl;
    RotateArray(nums, k);
    cout<<"循环右移4位后:";
    for(int i: nums) cout<<i<<" ";
    cout<<endl;
}

/*
 * 计算数的阶乘，递归方法
 */
int Recursion::Factorial(int n)
{
    if(n==0) return 1;      //0的阶乘为1 同时也是出口
    return n * Factorial(n - 1);
}

/*
 * Fibonacci数列，递归方法
 */
int Recursion::Fibonacci(int n)
{
    if(n<=1) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
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
void Recursion::Hanota(vector<int> &A, vector<int> &B, vector<int> &C, int n)
{
    if(n==1)
    {
        C.push_back(A.back());
        A.pop_back();
        return;
    }
    Hanota(A, C, B, n - 1);
    Hanota(A, B, C, 1);
    Hanota(B, A, C, n - 1);

}

/*
 * 分治法:
 * 二分查找
 * 三个参数分别为：查找数组、查找值、数组长度
 * 找到x时返回其在数组中的位置(下标), 未找到返回0
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

/*
 * 快速排序
 * 基于分治策略
 * 其中while循环体的含义：
 * 从数组中间的左侧找到一个大于中间值的数，从右侧找到一个小于中间值的数，
 * 将两个数交换位置
 */
void Recursion::QuickSort(int a[], int left, int right)
{
    if(left>=right) return;
    int i= left-1, j= right+1, middle= a[(left+right)/2];
    while(i<j)
    {
        do i++;
        while(a[i]<middle);
        do j--;
        while(a[j]>middle);
        if(i<j)
            swap(a[i],a[j]);
    }
    QuickSort(a, left, j);
    QuickSort(a, j+1, right);
}
/*
 * 循环右移数组；
 * 如 1,2,3,4,5,6,7 循环右移4位变为 4,5,6,7,1,2,3
 * 方法：
 * 确定一个k值,即右移4次
 * 首先写一个翻转数组的函数，进行3次翻转
 * 1.将原数组整体翻转 2.0到k-1位翻转 3. k到n-1位翻转
 */
void reverse(vector<int>& nums, int begin, int end)
{
    while(begin<end)
    {
        swap(nums[begin++], nums[end--]);
    }
}
void Recursion::RotateArray(vector<int>& nums, int k)
{
    int length = nums.size();
    reverse(nums, 0, length-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, length-1);
}






