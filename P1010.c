#include <stdio.h>
#include <math.h>
void micifang(int);
int main()
{
    int a;
    scanf("%d", &a);
    micifang(a);
    return 0;
}
void micifang(int n)
{
    while (n != 0)
    {
        int t = 0;
        int i;
        for (i = 1; i <= n / 2; i *= 2)
            t++;
        if (t == 1)
        {
            printf("2");
        }
        else if (t == 0)
        {
            printf("2(0)");
        }
        else
        {
            printf("2(");
            micifang(t);
            printf(")");
        }
        // 关于递归：137->2(7)->2(2(2))

        n -= i;
        if (n != 0)
            printf("+");
        // 删除了i判断是否输出+的部分，只要下一次不再进入循环，也就是一个数已经被化为最简则不输出+号，否则输出加号
    }
    // 对最小可拆解的幂做循环直到拆解为0
    // 依次向上层进行（剥桔子但从内向外剥）
}