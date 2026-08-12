// 用时更少更简洁的代码！

// 使用了__int128避免手动定义高精度，需要自己定义print函数

// 最大的亮点：转移方程。
// f(i,j)表示从（i，j）中的数开始重新取，可以取到的最大值。
// 例如第一行：1 2 3；f(2,3)=2*2^1+3*2^2。
// 则有f(1,3)=(f(2,3)+1)*2
// 以此类推，f(i,j)=max(takeLeft,takeRight)
// 其中takeLeft=(f(i+1,j)+A(i,j))*2
// 同理takeRight=(f(i,j-1)+A(i,j))*2


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define i128 __int128 //define一下方便后面写

int n, m;
int matrix[85][85];
i128 max_for_line[85][85];

void print(i128 x);

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    i128 ans = 0;
    for (int p = 1; p <= n; p++)
    {
        memset(max_for_line, 0, sizeof(max_for_line)); //每行都要初始化max_for_line!
        for (int len = 1; len <= m; len++)
        {
            for (int i = 1; i <= m - len + 1; i++)
            {
                int j = i + len - 1;
                i128 takeLeft = (max_for_line[i + 1][j] + matrix[p][i]) * 2;
                i128 takeRight = (max_for_line[i][j - 1] + matrix[p][j]) * 2;
                max_for_line[i][j] = max(takeLeft, takeRight);
            }
        }
        ans += max_for_line[1][m]; //结果取f(1,m),即从区间（1，m）开始取到的最大值
    }
    print(ans);
    cout<<endl;
    return 0;
}
void print(i128 x)
{
    if (x == 0)
    {
        cout << 0;
        return;
    }
    string s;
    while (x > 0)
    {
        s += (x % 10) + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end()); //反转函数reverse();
    // begin()和end()是迭代器，类似指针，可在使用中感受二者的不同之处
    cout << s;
}