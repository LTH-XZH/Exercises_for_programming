// 对于题目的分析：与P1005类似，在一个矩阵中寻找两条路线，使得两条路线上的数之和最大。
#include <iostream>
using namespace std;
int n, m;
int kindness[55][55];
int max_kind[55][55][55][55];
// 定义：dfs(x,y)表示从(x,y)位置出发能获得的最大善意值    【不含(x,y)位置的善意值】
// max_kind[x][y]同理，max_kind数组是用来存储已经计算过的dfs(x,y)的结果，避免重复计算，提高效率。    ——————即用来存储函数返回值
int dfs(int x1, int y1, int x2, int y2) {
    if(max_kind[x1][y1][x2][y2]!=-1) {
        return max_kind[x1][y1][x2][y2];
    }
    if (x1 == m && y1 == n && x2 == m && y2 == n)
        return 0;
    int max_kindness=0;
    if (x1 < m && x2 < m)                                                                                                    // condition 1：都向下
        max_kindness = max(max_kindness, dfs(x1 + 1, y1, x2 + 1, y2) + kindness[x1 + 1][y1] + kindness[x2 + 1][y2] * (!(x1 + 1 == x2 + 1 && y1 == y2))); // 重复逻辑的判断，重复乘0，不重复乘1。
    if (x1 < m && y2 < n)                                                                                                    // condition 2：1向下，2向右，condition 3，4以此类推
        max_kindness = max(max_kindness, dfs(x1 + 1, y1, x2, y2 + 1) + kindness[x1 + 1][y1] + kindness[x2][y2 + 1] * (!(x1 + 1 == x2 && y1 == y2 + 1)));
    if (y1 < n && y2 < n)
        max_kindness = max(max_kindness, dfs(x1, y1 + 1, x2, y2 + 1) + kindness[x1][y1 + 1] + kindness[x2][y2 + 1] * (!(x1 == x2 && y1 + 1 == y2 + 1)));
    if (y1 < n && x2 < m)
        max_kindness = max(max_kindness, dfs(x1, y1 + 1, x2 + 1, y2) + kindness[x1][y1 + 1] + kindness[x2 + 1][y2] * (!(x1 == x2 + 1 && y1 + 1 == y2)));
    max_kind[x1][y1][x2][y2]=max_kindness;
    return max_kind[x1][y1][x2][y2];
}
int main() {
    
    cin >> m >> n;
    kindness[1][1]=0;
    kindness[m][n]=0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> kindness[i][j];
        }
    }
    for (int a = 0; a <= m; a++)
    {
        for (int b = 0; b <= n; b++)
        {
            for (int c = 0; c <= m; c++)
            {
                for (int d = 0; d <= n; d++)
                    max_kind[a][b][c][d] = -1;
            }
        }
    }
    cout<<dfs(1, 1, 1, 1)<<endl;
    return 0;
}