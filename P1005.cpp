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
    long long max_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int lt = 1, rt = m;
        for (int j = 1; j <= m; j++)
        {
            if (matrix[i][lt] < matrix[i][rt])
            {
                max_sum += matrix[i][lt] * pow(2, j);
                lt++;
            }
            else
            {
                max_sum += matrix[i][rt] * pow(2, j);
                rt--;
            }
        }
    }
    cout << max_sum << endl;
    return 0;
}