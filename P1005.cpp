#include <iostream>
#include <cmath>
#include "high_num.h"

using namespace std;

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
                    max_for_line[i][j] = high_num::max_high((max_for_line[i - 1][j] + power_2[m - j + i - 1] * matrix[p][i - 1]), (max_for_line[i][j + 1] + power_2[m - j + i - 1] * matrix[p][j + 1]));
                else if (i - 1 >= 1)
                    max_for_line[i][j] = (max_for_line[i - 1][j] + power_2[m - j + i - 1] * matrix[p][i - 1]);
                else if (j + 1 <= m)
                    max_for_line[i][j] = (max_for_line[i][j + 1] + power_2[m - j + i - 1] * matrix[p][j + 1]);
                else
                    max_for_line[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            max_sum = high_num::max_high(max_sum, max_for_line[i][i] + power_2[m] * matrix[p][i]);
        }
        ans = ans + max_sum;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                max_for_line[i][j] = 0;
            }
        }
    }
    ans.print();
    return 0;
}