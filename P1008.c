#include <stdio.h>

int prepare_2num(int x, int y)
{
    int a1 = x / 100, b1 = (x / 10) % 10, c1 = x % 10;
    int a2 = y / 100, b2 = (y / 10) % 10, c2 = y % 10;
    int nums[6] = {a1, b1, c1, a2, b2, c2};
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j <= 5; j++)
        {
            if (nums[i] == nums[j] || nums[i] == 0 || nums[j] == 0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    for (int i = 123; i <= 329; i++)
    {
        if (prepare_2num(i, 2 * i) && prepare_2num(i, 3 * i) && prepare_2num(2 * i, 3 * i))
            printf("%d %d %d\n", i, 2 * i, 3 * i);
    }
}