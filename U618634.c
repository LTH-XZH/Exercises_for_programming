// 开大数组太过耗费内存（可能造成程序超时的问题使得无法通过），故还可以选择只记录“操作”

#include <stdio.h>
unsigned int faith_num[10000000005] = {0};
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int condition;
        int l, r, k;
        scanf("%d", &condition);
        if (condition == 1)
        {
            scanf("%d %d %d", &l, &r, &k);
            for (int i = l; i <= r; i++)
            {
                faith_num[i] += k;
            }
        }
        if (condition == 2)
        {
            scanf("%d %d", &l, &r);
            int sum = 0;
            for (int i = l; i <= r; i++)
            {
                sum += faith_num[i];
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}