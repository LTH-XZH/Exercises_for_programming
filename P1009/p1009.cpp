// 只是使用普通__int128会发现只能通过3/4个测试点，本体实际要求自己定义一中高精度类型。
// 故我们仿照P1005中的high_num类，自己定义了一个i128类，来实现高精度整数的加法和乘法运算。
// 注意我们没有定义*=和+=运算符，故我们需要使用ans = ans * i和ans = ans + factorial(i)来实现阶乘和累加的计算。

// ！！！注意0的定义，因为要比较大小，故0也应该为i128类型的一个实例，故我们在比较大小的语句中使用了 i128（0）来表示0。

#include <iostream>
#include <algorithm>
#include <cstring>
#include "i128.cpp"

using namespace std;

// 题目要求使用高精度整数,我们引入类i128,类的定义里已经定义过输出函数

// 定义阶乘函数
i128 factorial(int n)
{
    i128 ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans = ans * i;
    }
    return ans;
}

// 定义输出答案的S函数
i128 S(int n)
{
    i128 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans + factorial(i);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    i128 ans = S(n);
    ans.print();
    cout << endl;
    return 0;
}