// Dynamic-programming.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <malloc.h>
#include <math.h>

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
    /* LeetCode120:给定一个三角形的数字阵列，选择一条自顶向下的路径，使得沿途的所有数字之和最小。
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
    /* LeetCode64:给出一个m*n的矩阵，其中每一个格子包含一个非负整数。寻找一条从左上角到右下脚的路径，
       是的沿路的数字和最小。（每一步只能右移或者下移）
    */
    /*
    (动态规划)：时间复杂为o(n*m)和空间复杂度为o(n*m)。
    典型的动态规划问题，假设当前已经开始计算s[i][j]，
    那么s[i][j]只可能从s[i-1][j]+grid[i][j]或者s[i][j-1]+grid[i][j]计算得到，
    也就是s[i][j] = min(s[i-1][j],s[i][j-1])+grid[i][j]。
    我们需要一个o(n*m)额外空间保存已经计算的s[i][j]的值，我们只需要访问一遍数组即可。
    因此时间复杂度为o(n*m)，空间复杂度为o(n*m)。
    我们需要特殊处理矩阵中第一行和第一列。
    因为第一行没有s[i-1][j]元素，只有s[i][j-1]元素。
    第一列没有s[i][j-1]元素，只有s[i-1][j]元素。
    */
    int matrixMinPathSum(vector<vector<int>>& grid)
    {
        int minSum = 0;
        //当grid为空时，返回0
        if (grid.empty())
        {
            return 0;
        }

        //获得grid行数
        int row = grid.size();
        //获得grid的列数
        int col = grid[0].size();
        //定义一个二维vector，用于存储对应路径和
        vector<vector<int>> preSum(row);

        //创建该vector,全部为0
        for (int i = 0; i < row; i++) {
            preSum[i].resize(col);
        }

        preSum[0][0] = grid[0][0];

        //初始化第一行数据
        for (int i = 1; i < col;i++)
        {
            preSum[0][i] = preSum[0][i-1] + grid[0][i];
        }
        //初始化第一列数据
        for (int i = 1; i < row; i++)
        {
            preSum[i][0] = preSum[i-1][0] + grid[i][0];
        }

        //计算a[i][j]对应的preSum的值
        for (int i = 1; i < row;i++)
        {
            for (int j = 1; j < col;j++)
            {
                if (preSum[i - 1][j]<preSum[i][j - 1])
                {
                    minSum = preSum[i - 1][j];
                }
                else
                {
                    minSum = preSum[i][j - 1];
                }
                //a[i][j]只能通过上一个结点或前一个结点走到
                preSum[i][j] = minSum + grid[i][j];
            }  
        }

        return preSum[row-1][col-1];
    }
};



int _tmain(int argc, _TCHAR* argv[])
{
    Solution solution;
#if 0
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
#endif

    vector<vector<int> >num =
    { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };

    int sumMinWay = solution.matrixMinPathSum(num);

    cout << sumMinWay << endl;

    system("pause");
    return 0;
}

