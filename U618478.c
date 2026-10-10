#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    int table[15][15];
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            table[i][j] = num;
            num++;
        }
    }
    int top = 1, bottom = n, left = 1, right = n;
    while (top < bottom && left < right)
    {
        for (int i = left; i <= right; i++)
        {
            printf("%d ", table[top][i]);
        }
        for (int i = top + 1; i <= bottom; i++)
        {
            printf("%d ", table[i][right]);
        }
        for (int i = right - 1; i >= left; i--)
        {
            printf("%d ", table[bottom][i]);
        }
        for (int i = bottom - 1; i > top; i--)
        {
            printf("%d ", table[i][left]);
        }
        top++;
        bottom--;
        left++;
        right--;
    }
    if (top == bottom && left == right)
    {
        printf("%d ", table[top][left]);
    }
    return 0;
}