#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    int p, q;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            p = i;
            q = n / i;
            break;
        }
    }

    printf("%d\n", q);
    return 0;
}
