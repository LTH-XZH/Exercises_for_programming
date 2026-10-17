#include <stdio.h>
#include <string.h>

// 第一遍实现逻辑太过复杂，鉴于依靠数组运算引入cstring库，依赖字符串处理函数
// 为了便于实现，不妨设为全局变量
#define MAX_LEN 110

int R, Len;
char num[MAX_LEN] = {0}, reverse[MAX_LEN] = {0};
void reverse_plus();
int prove();

int main()
{
    scanf("%d %s", &R, num);
    Len = strlen(num);
    for (int i = 0; i < Len; i++)
    {
        // 字符由ASCII码转换为数字方便计算
        // 由于只需要比较每一位是否相等，最后输出的是步骤数，故大于10的数不需要再由10转换为A
        if ('0' <= num[i] && num[i] <= '9')
            num[i] -= '0';
        else if ('A' <= num[i] && num[i] <= 'F')
            num[i] -= 'A' - 10;
    }
    while (1)
    {
        static int ans = 0;
        reverse_plus();
        ans++;
        if (prove() && ans <= 30)
        {
            printf("STEP=%d\n", ans);
            break;
        }
        else if (ans > 30)
        {
            printf("Impossible!\n");
            break;
        }
    }
    return 0;
}

void reverse_plus()
{
    for (int i = 0; i < Len; i++)
    {
        reverse[i] = num[Len - 1 - i];
    }
    int k;
    for (int k = 0; k < Len + 1; k++)
    {
        num[k] += reverse[k];
        if (num[k] >= R)
        {
            num[k + 1]++;
            num[k] -= R;
        }
    }
    if (num[Len] != 0)
        Len += 1;
}
int prove()
{
    for (int i = 0; i < Len / 2; i++)
    {
        if (num[i] != num[Len - 1 - i])
            return 0;
    }
    return 1;
}