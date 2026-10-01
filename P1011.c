// 记第i站上车人数为Ai,下车人数为Bi（i>=3）
// Ai=A(i-1)+A(i-2)，Bi=A(i-1).
// 故每站实际上车人数为A(i-1)+A(i-2)-A(i-1)=A(i-2)。
// 故从离开第n-1站到第n站前时，车上人数为a+A(1)+...+A(n-3)，即m。
// 记Fibonacci数列为F(1)=1,F(2)=1,F(3)=2,F(4)=3,F(5)=5,...；记A2=p
// 观察规律可得Ai=F(i-2)*a+F(i-1)*p, i>=3。
// 再由Fibonacci数列求和公式S(n)=F(n-2)-F(2)得：
// m=a  +  （F(n-3)-F(2))*a   +   (F(n-2)-F(2)-F(1))*p  +  a  +  p
// PS：最后的a和p是A1和A2的值，前面是从A3到A(n-1)的和。

// 先求p,再求对应的m(x)即可。
#include <stdio.h>

// 定义Fibonacci数列函数
int fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int a, n, m, x;
    scanf("%d %d %d %d", &a, &n, &m, &x);
    int p = (m - a - fibonacci(n - 3) * a) / (fibonacci(n - 2) - 1);
    int mx = a + fibonacci(x - 2) * a + (fibonacci(x - 1) - 1) * p;
    printf("%d\n", mx);
    return 0;
}
