#include <stdio.h>
#include <math.h>

int gcd(int n, int m);

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int ans = 0;
    if (x == y)
        ans--;
    for (int i = x; i <= sqrt(y*x); i += x)
    {
        if (y % i == 0)
        {
            int j = y / i;
            if (gcd(i/x, j) == 1)
            {
                ans += 2;
            }
        }
    }
    printf("%d", ans);
    return 0;
}

int gcd(int n, int m)
{
    if (m == 0)
        return n;
    int temp = m;
    m = n % m;
    n = temp;
    return gcd(n, m);
}