// Dynamic-programming.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <malloc.h>

using namespace std;
#define MAX 101
vector<int> memo; //��¼֮ǰ�������f(n)
int a[MAX][MAX];
int minSum[MAX][MAX];
int n = 0;

/*
��̬�滮����ԭ����������ɸ������⣬ͬʱ����������Ĵ𰸣�
ʹ��ÿ��������ֻ���һ�Σ����ջ��ԭ����Ĵ𰸡�
*/
class Solution
{
public:
    /* ����һ�������ε��������У�ѡ��һ���Զ����µ�·����ʹ����;����������֮����С��
    ��ÿһ��ֻ���ƶ������ڵĸ����У�
    ���磺     ��2��
             ��3��4��
            ��6��5��7��
           ��4��1��8��3��
    ����С·����Ϊ11   ��2+3+5+1��=11
    */
    /* ��a[i][j]Ϊ��ʼ�㣬���Ա鼰����һ�����С·��֮�� */
    int triangleMinSum(int i,int j)
    {
        //���һ�е���С·��ֵ����a[i][j]+0
        if (i == n-1)
        {
            return a[i][j];
        }

        int sum1 = triangleMinSum(i + 1, j);
        int sum2 = triangleMinSum(i + 1, j + 1);

        if (sum1 < sum2)
        {
            minSum[i][j] = sum1 + a[i][j];
        }
        else
        {
            minSum[i][j] = sum2 + a[i][j];
        }

        return minSum[i][j];
    }
    /* ����һ��m*n�ľ�������ÿһ�����Ӱ���һ���Ǹ�������Ѱ��һ�������Ͻǵ����½ŵ�·����
       �ǵ���·�����ֺ���С����ÿһ��ֻ�����ƻ������ƣ�
    */
    int matrixMinPathSum(int n)
    {
        return 0;
    }
};



int _tmain(int argc, _TCHAR* argv[])
{
    Solution solution;
    memo = vector<int>(n + 1, -1);

    int i = 0, j = 0;
    //���������Ͷ�Ӧ������n
    cout << "���������ε�������" << endl;
    cin >> n;
    cout << "�����ά�������ݣ�" << endl;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j <= i;j++)
        {
            cout << "a[" << i << "]" << "[" << j << "]=";
            cin >> a[i][j];
        }
    }

    int sumMin = solution.triangleMinSum(0, 0);

    cout << sumMin << endl;


    system("pause");
    return 0;
}

