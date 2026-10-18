#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int F[1005] = {0};
    F[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        int fn = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            fn += F[j];
        }
        F[i] = fn + 1;
    }
    printf("%d", F[n]);
    return 0;
}