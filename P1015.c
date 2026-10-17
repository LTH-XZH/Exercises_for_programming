#include <stdio.h>

int reverse_plus(int n, int R);
int prove(int n);
// int getLen(char *group[])
// {
//     int Len = 0;
//     for (int i = 1; group[i] != -1; i++)
//         Len++;
//     return Len;
// }

int main()
{
    int R, n;
    scanf("%d %d", &R, &n);
    while (1)
    {
        static int ans = 0;
        n = reverse_plus(n, R);
        ans++;
        if (prove(n))
        {
            printf("STEP=%d", ans);
            break;
        }
    }
    return 0;
}

int reverse_plus(int n, int R)
{
    char corre_order[110];
    char reverse_order[110];
    char sum[110];
    for (int i = 0; i < 110; i++)
    {
        corre_order[i] = -1;
        reverse_order[i] = -1;
        sum[i] = -1;
    }
    int i = 1;
    while (1)
    {
        reverse_order[i] = n % 10;
        n /= 10;
        if (n == 0)
            break;
        i++;
    }
    int j = 1;
    for (int i = 109; i > 0; i--)
    {
        if (reverse_order[i] != -1)
        {
            corre_order[j] = reverse_order[i];
            j++;
        }
    }
    sum[1] = (reverse_order[1] + corre_order[1]) % R;
    int k;
    for (k = 2; corre_order[k] != -1; k++)
    {
        sum[k] = ((corre_order[k - 1] + reverse_order[k - 1]) / R + corre_order[k] + reverse_order[k]) % R;
    }
    if ((corre_order[k - 1] + reverse_order[k - 1]) / R > 0)
        sum[k] = (corre_order[k - 1] + reverse_order[k - 1]) / R;
    int plus_out = 0;
    for (int i = 1; sum[i] != -1; i++)
    {
        plus_out *= 10;
        plus_out += sum[i];
    }
    return plus_out;
}
int prove(int n)
{
    char corre_order[110];
    char reverse_order[110];
    for (int i = 0; i < 110; i++)
    {
        corre_order[i] = -1;
        reverse_order[i] = -1;
    }
    int i = 1;
    while (1)
    {
        reverse_order[i] = n % 10;
        n /= 10;
        if (n == 0)
            break;
        i++;
    }
    int j = 1;
    for (int i = 109; i > 0; i--)
    {
        if (reverse_order[i] != -1)
        {
            corre_order[j] = reverse_order[i];
            j++;
        }
    }
    for (int i = 1; corre_order[i] != -1; i++)
    {
        if (reverse_order[i] != corre_order[i])
            return 0;
    }
    return 1;
}