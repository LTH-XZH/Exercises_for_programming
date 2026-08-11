#include <iostream>
#include <cmath>
#include "high_num.cpp"
// 题目数据太大，故只能自己实现大数类来进行计算。定义一个大数类high_num，使用数组来存储大数的每一位数字，并重载加法、乘法和赋值运算符，以及定义一个比较大小的函数和输出函数。
using namespace std;

// max_for_line[i][j]表示第p行剩余区间为[i,j]时取到的最大值，power_2[i]表示2的i次方。
high_num max_for_line[85][85];
high_num power_2[85];

void calculate_power_2(int m)
{
    power_2[0] = high_num(1);
    for (int i = 1; i <= m; ++i)
    {
        power_2[i] = power_2[i - 1] * 2;
    }
}

int main()
{
    int n, m;
    int matrix[85][85];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    high_num ans;
    calculate_power_2(m);
    for (int p = 1; p <= n; p++)
    {
        high_num max_sum;
        max_for_line[1][m] = high_num(0);
        for (int len = m; len >= 1; len--)
        {
            for (int i = 1; i <= m - len + 1; i++)
            {
                int j = i + len - 1;
                if (i - 1 >= 1 && j + 1 <= m)
                // 递推关系，转移方程，判断是从两侧之中哪一侧的最大值转移过来。
                // 注意2的指数是m - j + i - 1。
                    max_for_line[i][j] = high_num::max_high((max_for_line[i - 1][j] + power_2[m - j + i - 1] * matrix[p][i - 1]), (max_for_line[i][j + 1] + power_2[m - j + i - 1] * matrix[p][j + 1]));
                else if (i - 1 >= 1)
                    max_for_line[i][j] = (max_for_line[i - 1][j] + power_2[m - j + i - 1] * matrix[p][i - 1]);
                else if (j + 1 <= m)
                    max_for_line[i][j] = (max_for_line[i][j + 1] + power_2[m - j + i - 1] * matrix[p][j + 1]);
                else
                    max_for_line[i][j] = 0;
            }
        }
        // 最后剩下一个数，比较所有的max_for_line[i][i]，加上对应的matrix[p][i]乘以2的m次方，取最大值。
        for (int i = 1; i <= m; i++)
        {
            max_sum = high_num::max_high(max_sum, max_for_line[i][i] + power_2[m] * matrix[p][i]);
        }
        ans = ans + max_sum;
        // 重新初始化max_for_line数组，避免影响下一行的计算。
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                max_for_line[i][j] = 0;
            }
        }
    }
    // 输出最终答案。
    ans.print();
    return 0;
}