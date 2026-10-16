#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int locker[16];
    int out[16] = {0};
    for (int i = 1; i <= n; i++)
        locker[i] = i;
    for (int i = 1; i <= m; i++)
    {
        static int operate = 0;
        scanf("%d", &operate);
        if (operate == 1)
        {
            int locker_beout;
            scanf("%d", &locker_beout);
            int item_operated = locker[locker_beout];
            out[item_operated] = item_operated;
            locker[locker_beout] = 0;
        }
        else if (operate == 2)
        {
            int item_operated;
            scanf("%d", &item_operated);
            if (out[item_operated] != 0 && locker[item_operated] == 0)
            {
                locker[item_operated] = item_operated;
                out[item_operated] = 0;
            }
        }
        else if (operate == 3)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", locker[i]);
            }
            printf("\n");
        }
        else if (operate == 4)
        {
            // 初版冒泡排序发现会造成0 0 0 2 3 5的局面，故要先将非零储物柜集中在前面
            int k = 0; // 定义k来记录非零储物柜的个数
            for (int i = 1; i <= n; i++)
            {
                if (locker[i] != 0)
                {
                    k++;
                    int temp = locker[k];
                    locker[k] = locker[i];
                    locker[i] = temp;
                }
            }
            // 冒泡排序
            for (int i = k - 1; i > 0; i--)
            {
                for (int j = 1; j <= i; j++)
                {
                    if (locker[j] > locker[j + 1])
                    {
                        int temp = locker[j];
                        locker[j] = locker[j + 1];
                        locker[j + 1] = temp;
                    }
                }
            }
        }
        else if (operate == 0)
        {
            int empty = 0;
            for (int i = 1; i <= n; i++)
            {
                if (out[i] != 0)
                {
                    printf("%d ", out[i]);
                    empty = 1;
                }
            }
            if (empty == 0)
                printf("0");
            printf("\n");
        }
    }
    return 0;
}