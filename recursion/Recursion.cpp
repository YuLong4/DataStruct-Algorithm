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
     * Function:Factorial
     * ���Խ׳˺���
     */
    cout<<"ִ�к���:"<< "Factorial:" <<endl;
    cout << "5�Ľ׳�:" << Factorial(5) << endl;

    /*
     * Function:Fibonacci
     * ����fibonacci����
     */
    cout<<"\nִ�к���:"<< "Fibonacci:" <<endl;
    cout<<"ǰ20��Fibonacci��:"<<endl;
    for(int i=0;i<20;i++)
    {
        cout << Fibonacci(i) << " ";
    }
    cout<<endl;

    /*
     * Function:Hanota
     * ����hanota����
     */
    cout<<"\nִ�к���:"<< "Hanota:" <<endl;
    vector<int> A = {5,4,3,2,1}, B, C;
    cout<<"��ʼ����:"<<endl;
    cout<<"A:";
    for(int i : A) cout<<i<<" ";
    cout<<"\nB:";
    for(int i : B) cout<<i<<" ";
    cout<<"\nC:";
    for(int i : C) cout<<i<<" ";
    Hanota(A, B, C, A.size());
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
    cout<<"\nִ�к���:"<< "BinarySearch:" <<endl;
    int a[10] = {1, 23, 42, 56, 78, 89, 100, 140, 150, 560};
    cout<<"������:";
    for(int i : a) cout<<i<<" ";
    cout<<"�� ����56\n";
    int res= BinarySearch(a, 56, 10);
    if(res!=-1)
    {
        cout<<"�ҵ���56��λ�ã��±꣩Ϊ��"<<res<<endl;
    }
    else cout<<"δ�ҵ�"<<endl;


    /*
     * Function: QuickSort
     * ���Կ�������
     */
    cout<<"\nִ�к���:"<< "QuickSort:" <<endl;
    int b[10] = {50, 823, 23, 65, 78, 101, 100, 1, 150, 10};
    cout<<"ԭ����Ϊ��";
    for(int i: b) cout<<i<<" ";
    QuickSort(b, 0, 9);
    cout<<"\n���������:";
    for(int i: b) cout<<i<<" ";
    cout<<endl;


    /*
     * ������ת���麯��
     */
    vector<int> nums={1,2,3,4,5,6,7};
    int k=4;
    cout<<"\nԭ����Ϊ:";
    for(int i: nums) cout<<i<<" ";
    cout<<endl;
    RotateArray(nums, k);
    cout<<"ѭ������4λ��:";
    for(int i: nums) cout<<i<<" ";
    cout<<endl;
}

/*
 * �������Ľ׳ˣ��ݹ鷽��
 */
int Recursion::Factorial(int n)
{
    if(n==0) return 1;      //0�Ľ׳�Ϊ1 ͬʱҲ�ǳ���
    return n * Factorial(n - 1);
}

/*
 * Fibonacci���У��ݹ鷽��
 */
int Recursion::Fibonacci(int n)
{
    if(n<=1) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
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

/*
 * ��������
 * ���ڷ��β���
 * ����whileѭ����ĺ��壺
 * �������м������ҵ�һ�������м�ֵ���������Ҳ��ҵ�һ��С���м�ֵ������
 * ������������λ��
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
 * ѭ���������飻
 * �� 1,2,3,4,5,6,7 ѭ������4λ��Ϊ 4,5,6,7,1,2,3
 * ������
 * ȷ��һ��kֵ,������4��
 * ����дһ����ת����ĺ���������3�η�ת
 * 1.��ԭ�������巭ת 2.0��k-1λ��ת 3. k��n-1λ��ת
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






