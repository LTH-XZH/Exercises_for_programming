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
    int i = 1;

    while (n != 0)
    {

        int t = log(n) / log(2); // 执行micifang(t)时两个t不同，类比数学“此x非彼x”
        if (i != 1)
        {
            printf("+");
        }

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

        n -= pow(2, t);
        i = 0; // 不能直接替换为输出“+”
        // 用i=0告诉下一次循环此处执行了n-=的拆分操作，拆分玩n不为零进入下一次循环时才打印+
        // 例如n==2时，拆分完为0，已经拆分完毕则不打印+
    }
    // 对最小可拆解的幂做循环直到拆解为0
    // 依次向上层进行（剥桔子但从内向外剥）
}