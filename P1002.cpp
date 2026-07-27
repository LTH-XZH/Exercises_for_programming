#include <iostream>
using namespace std;

int main()
{
    int n, m, horse_x, horse_y;
    cin >> n >> m >> horse_x >> horse_y;
    //     if ((horse_x <= 2 && n <= 4) || horse_y <= 2 && m <= 4)
    //         cout << 0 << endl;
    //     if(horse_x<)
    //  原本想采用分类讨论，但发现情况很复杂。
    //  询问ChatGPT后，发现可以用总路径数减去经过禁点的路径数，但是存在重复的情况，复杂度暴涨

    // 采用动态规划，f(i,j)=f(i-1,j)+f(i,j-1)  (i,j) != 马的控制点
    const int ctrl_x[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
    const int ctrl_y[9] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
    int ways[21][21] = {0};
    bool horse_control[21][21] = {false};
    for (int k = 0; k < 9; k++)
    {
        int x = horse_x + ctrl_x[k];
        int y = horse_y + ctrl_y[k];
        if (x >= 0 && y >= 0)
            horse_control[x][y] = true; // 马的控制点标记为true
    }
    for (int j = 1; j <= m; j++)
    {
        if (horse_control[0][j])
            ways[0][j] = 0; // 马的控制点不能走
        else
            ways[0][j] = 1; // 初始化第一行
    }
    for (int i = 1; i <= n; i++)
    {
        if (horse_control[i][0])
            ways[i][0] = 0; // 马的控制点不能走
        else
            ways[i][0] = 1; // 初始化第一列
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (horse_control[i][j])
            {
                ways[i][j] = 0;
                continue; // 马的控制点不能走
            }
            ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
        }
    }
    cout << ways[n][m] << endl;
}