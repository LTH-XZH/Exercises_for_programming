#include <iostream>
using namespace std;
// OK,成功完成第一个深度搜索，撒花🎇
// “图遍历”：在一个节点图里如何遍历每一个节点？——深度搜索。尽可能一条路走到底，再回来换另一条：即多个if
int N;
int table[15][15] = {0};
int f[11][11][11][11];

int dfs(int x1, int y1, int x2, int y2)
// x1,y1表示第一个人的坐标位置；x2.y2表示第二个人的坐标位置
// 返回值表示从(x1,y1)和(x2,y2)出发，最终到达(N,N)的最大价值
// f[x1][y1][x2][y2]表示从(x1,y1)和(x2,y2)出发，走到B点最大可以取到的数字
{
    int M = 0;
    // 通过比较找到和最大的路径，用M和下一步的dfs+table[][]来比较，找到最大值
    // 因为dfs不包含该处自己的值，所以要加上table[][]，并且要判断是否重复走到同一个点，如果重复就乘0，不重复就乘1。
    if (f[x1][y1][x2][y2] != -1)
        return f[x1][y1][x2][y2];
    if (x1 == N && y1 == N && x2 == N && y2 == N)
        return 0;
    if (x1 < N && x2 < N)                                                                                                    // condition 1：都向下
        M = max(M, dfs(x1 + 1, y1, x2 + 1, y2) + table[x1 + 1][y1] + table[x2 + 1][y2] * (!(x1 + 1 == x2 + 1 && y1 == y2))); // 重复逻辑的判断，重复乘0，不重复乘1。
    if (x1 < N && y2 < N)                                                                                                    // condition 2：1向下，2向右，condition 3，4以此类推
        M = max(M, dfs(x1 + 1, y1, x2, y2 + 1) + table[x1 + 1][y1] + table[x2][y2 + 1] * (!(x1 + 1 == x2 && y1 == y2 + 1)));
    if (y1 < N && y2 < N)
        M = max(M, dfs(x1, y1 + 1, x2, y2 + 1) + table[x1][y1 + 1] + table[x2][y2 + 1] * (!(x1 == x2 && y1 + 1 == y2 + 1)));
    if (y1 < N && x2 < N)
        M = max(M, dfs(x1, y1 + 1, x2 + 1, y2) + table[x1][y1 + 1] + table[x2 + 1][y2] * (!(x1 == x2 + 1 && y1 + 1 == y2)));
    f[x1][y1][x2][y2] = M;
    return M;
}

int main()
{
    cin >> N;
    // 给f[11][11][11][11]数组全部赋值为-1
    for (int a = 0; a <= N; a++)
    {
        for (int b = 0; b <= N; b++)
        {
            for (int c = 0; c <= N; c++)
            {
                for (int d = 0; d <= N; d++)
                    f[a][b][c][d] = -1;
            }
        }
    }
    // 读取输入，填表
    int x, y, v;
    do
    {
        cin >> x >> y >> v;
        table[x][y] = v;
    } while (!(x == y && y == v && v == 0));
    // 非常优雅的调用dfs函数，然后输出，搞定！
    cout << dfs(1, 1, 1, 1) + table[1][1] << endl;
}