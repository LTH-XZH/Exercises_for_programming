#include <iostream>
using namespace std;

int which_max(int a, int b); // 判断大小取大值的函数
int table[9][9] = {0};
int max_num[9][9] = {0};
int main()
{
    int N;
    int x, y, v;
    cin >> N;
    do
    {
        cin >> x >> y >> v;
        table[x - 1][y - 1] = v;
    } while (!(x == y && y == v && v == 0));
    max_num[0][0] = table[0][0];
    for (int i = 1; i < N; i++)
        max_num[i][0] = max_num[i - 1][0] + table[i][0];
    for (int j = 1; j < N; j++)
        max_num[0][j] = max_num[0][j - 1] + table[0][j];
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            max_num[i][j] = which_max(max_num[i - 1][j], max_num[i][j - 1]) + table[i][j];
        }
    }
    cout << max_num[N - 1][N - 1] << endl;
}

int which_max(int a, int b) // 判断两个数哪个大
{
    if (a > b)
        return a;
    else
        return b;
}
