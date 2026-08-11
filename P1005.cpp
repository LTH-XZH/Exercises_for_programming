#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    long long matrix[85][85];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    unsigned long long ans = 0;
    for (int p = 1; p <= n; p++)
    {
        unsigned long long max_sum = 0;
        unsigned long long max_for_line[85][85] = {0};
        max_for_line[1][m] = 0;
        for(int len = m; len >= 1; len--)
        {
            for(int i = 1; i <= m - len + 1; i++)
            {
                int j = i + len - 1;
                max_for_line[i][j] = max((max_for_line[i - 1][j] + matrix[p][i - 1] * pow(2, m - j + i - 1)) * (i - 1 >= 0), (max_for_line[i][j + 1] + matrix[p][j + 1] * pow(2, m - j + i - 1)) * (j + 1 <= m));
            }
        }
        for (int i = 1; i <= m; i++)
        {
            max_sum = max(max_sum, max_for_line[i][i] + matrix[p][i] * (unsigned long long)pow(2, m));
        }
        ans += max_sum;
    }
    cout << ans << endl;
    return 0;
}