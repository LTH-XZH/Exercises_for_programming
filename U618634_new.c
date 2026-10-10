// 鉴于开大数组有可能导致内存过大，进而导致没有办法正常运行，故我们尝试只记录每次操作
// 每次询问的时候根据已经记录的操作“笔记本”计算
#include <stdio.h>

struct Update
{
    int l, r, k;
} updates[1005];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int updt_count = 0;
    for (int i = 0; i < m; i++)
    {
        int condition;
        scanf("%d", &condition);
        if (condition == 1)
        {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            updates[updt_count].l = l;
            updates[updt_count].r = r;
            updates[updt_count].k = k;
            updt_count++;
        }
        else if (condition == 2)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            int sum = 0;
            for (int j = 0; j < updt_count; j++)
            {
                int left = (l > updates[j].l) ? l : updates[j].l;
                int right = (r < updates[j].r) ? r : updates[j].r;
                if (left <= right)
                {
                    sum += (long long)(right - left + 1) * updates[j].k;
                }
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}