// Dynamic-programming.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <malloc.h>

using namespace std;
#define MAX 101
vector<int> memo; //记录之前计算过的f(n)
int a[MAX][MAX];
int minSum[MAX][MAX];
int n = 0;

/*
动态规划：将原问题拆解成若干个子问题，同时保存子问题的答案，
使得每个子问题只求解一次，最终获得原问题的答案。
*/
class Solution
{
public:
    /* 给定一个三角形的数字阵列，选择一条自顶向下的路径，使得沿途的所有数字之和最小。
    （每一步只能移动到相邻的格子中）
    例如：     【2】
             【3，4】
            【6，5，7】
           【4，1，8，3】
    其最小路径和为11   （2+3+5+1）=11
    */
    /* 以a[i][j]为起始点，可以遍及的下一层的最小路径之和 */
    int triangleMinSum(int i,int j)
    {
        //最后一行的最小路径值就是a[i][j]+0
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
    /* 给出一个m*n的矩阵，其中每一个格子包含一个非负整数。寻找一条从左上角到右下脚的路径，
       是的沿路的数字和最小。（每一步只能右移或者下移）
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
    //输入三角型对应的行数n
    cout << "输入三角形的行数：" << endl;
    cin >> n;
    cout << "输入二维数组内容：" << endl;
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

