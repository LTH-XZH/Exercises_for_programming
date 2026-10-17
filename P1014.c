#include <stdio.h>

int max_sumbase(int n);

int main()
{
    int n;
    scanf("%d", &n);
    int line = max_sumbase(n);
    int sum_before = 0;
    for (int i = 1; i < line; i++)
        sum_before += i;
    if (line % 2 == 0)
        printf("%d/%d", n - sum_before, line + 1 - (n - sum_before));
    else if (line % 2 == 1)
        printf("%d/%d", line - (n - sum_before) + 1, n - sum_before);
}

int max_sumbase(int n)
{
    int sum = 0;
    int i = 0;
    while (sum < n)
    {
        i++;
        sum += i;
    }
    return i;
}