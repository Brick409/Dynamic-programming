// Dynamic-programming.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <malloc.h>
#include <math.h>

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
    /* LeetCode120:����һ�������ε��������У�ѡ��һ���Զ����µ�·����ʹ����;����������֮����С��
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
    /* LeetCode64:����һ��m*n�ľ�������ÿһ�����Ӱ���һ���Ǹ�������Ѱ��һ�������Ͻǵ����½ŵ�·����
       �ǵ���·�����ֺ���С����ÿһ��ֻ�����ƻ������ƣ�
    */
    /*
    (��̬�滮)��ʱ�临��Ϊo(n*m)�Ϳռ临�Ӷ�Ϊo(n*m)��
    ���͵Ķ�̬�滮���⣬���赱ǰ�Ѿ���ʼ����s[i][j]��
    ��ôs[i][j]ֻ���ܴ�s[i-1][j]+grid[i][j]����s[i][j-1]+grid[i][j]����õ���
    Ҳ����s[i][j] = min(s[i-1][j],s[i][j-1])+grid[i][j]��
    ������Ҫһ��o(n*m)����ռ䱣���Ѿ������s[i][j]��ֵ������ֻ��Ҫ����һ�����鼴�ɡ�
    ���ʱ�临�Ӷ�Ϊo(n*m)���ռ临�Ӷ�Ϊo(n*m)��
    ������Ҫ���⴦������е�һ�к͵�һ�С�
    ��Ϊ��һ��û��s[i-1][j]Ԫ�أ�ֻ��s[i][j-1]Ԫ�ء�
    ��һ��û��s[i][j-1]Ԫ�أ�ֻ��s[i-1][j]Ԫ�ء�
    */
    int matrixMinPathSum(vector<vector<int>>& grid)
    {
        int minSum = 0;
        //��gridΪ��ʱ������0
        if (grid.empty())
        {
            return 0;
        }

        //���grid����
        int row = grid.size();
        //���grid������
        int col = grid[0].size();
        //����һ����άvector�����ڴ洢��Ӧ·����
        vector<vector<int>> preSum(row);

        //������vector,ȫ��Ϊ0
        for (int i = 0; i < row; i++) {
            preSum[i].resize(col);
        }

        preSum[0][0] = grid[0][0];

        //��ʼ����һ������
        for (int i = 1; i < col;i++)
        {
            preSum[0][i] = preSum[0][i-1] + grid[0][i];
        }
        //��ʼ����һ������
        for (int i = 1; i < row; i++)
        {
            preSum[i][0] = preSum[i-1][0] + grid[i][0];
        }

        //����a[i][j]��Ӧ��preSum��ֵ
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
                //a[i][j]ֻ��ͨ����һ������ǰһ������ߵ�
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
#endif

    vector<vector<int> >num =
    { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };

    int sumMinWay = solution.matrixMinPathSum(num);

    cout << sumMinWay << endl;

    system("pause");
    return 0;
}

