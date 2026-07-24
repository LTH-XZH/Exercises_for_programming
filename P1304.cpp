#include <iostream>
using namespace std;
bool is_prime[10001]; // 还不会使用向量vector,故使用数组
void era(int n);
void prove(int n);
int main()
{
    for (int i = 0; i <= 10000; i++)
    {
        is_prime[i] = true;
    }
    int n;
    cin >> n;
    era(n);
    for (int i = 4; i <= n; i += 2)
    {
        prove(i);
    }
    return 0;
}
void era(int n) // 埃氏筛的实现
{
    is_prime[0] = is_prime[1] = false; // 0和1不是质数
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i) // 小于i*i的数都在其他循环中被筛掉了，eg. 3*3=9,而6在2的循环中已经被筛掉了
            {
                is_prime[j] = false;
            }
        }
    }
}
void prove(int n)
{
    for (int i = 2; 2 * i <= n; i++) // 要求递增输出，利用“对称性”
    {
        if (is_prime[i] && is_prime[n - i]) // i和n-i都是质数，且i<=n-i
        {
            cout << n << "=" << i << "+" << n - i << endl;
            return;
        }
    }
}