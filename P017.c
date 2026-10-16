#include <stdio.h>
#include <math.h>
int main()
{
    int n, R;
    scanf("%d %d", &n, &R);
    int input = n;
    char num_out[20];
    for (int i = 0; i < 20; i++)
        num_out[i] = -1;
    char numcode;
    int i = 0;
    while (!(0 <= n && n < -R))
    {
        if (R != 0)
        {
            if ((n % R) < 0)
            {
                if ((n % R - R) > 9)
                    numcode = 'A' + (n % R - R - 10);
                else
                    numcode = (char)(n % R - R);
                n = n / R + 1;
            }
            else
            {
                if ((n % R) > 9)
                    numcode = 'A' + (n % R - 10);
                else
                    numcode = (char)(n % R);
                n = n / R;
            }
            num_out[i++] = numcode;
        }
    }
    if (n > 9)
        num_out[i] = n - 10 + 'A';
    else
        num_out[i] = (char)n;
    printf("%d=", input);
    for (int i = 19; i >= 0; i--)
    {
        if (num_out[i] != -1)
        {
            if (num_out[i] > 9)
                printf("%c", num_out[i]);
            else
                printf("%d", num_out[i]);
        }
    }
    printf("(base%d)\n", R);
    return 0;
}