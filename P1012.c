#include <stdio.h>
#include <string.h>

// 比较两个字符串拼接后的大小
int compare(char a[], char b[])
{
    // 拼接两个字符串
    char concat1[40], concat2[40];
    sprintf(concat1, "%s%s", a, b);
    sprintf(concat2, "%s%s", b, a);
    // 比较拼接后的字符串
    return strcmp(concat1, concat2);
}

int main()
{
    int numbers[25];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    // 将数字转换为字符串
    char str_num[25][15]; // 每个数字最多有10位，加上终止符
    for (int i = 1; i <= n; i++)
    {
        sprintf(str_num[i], "%d", numbers[i]);
    }
    // 对字符串数组进行排序，使得拼接后的结果最大
    // 使用冒泡排序

    // 注意点：冒泡排序，我们根据拼接数的大小对所有数进行冒泡排序
    for (int i = n-1; i>0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (compare(str_num[j], str_num[j + 1]) < 0)
            {
                char temp[15];
                strcpy(temp, str_num[j]);
                strcpy(str_num[j], str_num[j + 1]);
                strcpy(str_num[j + 1], temp);
            }
        }
    }
    // 输出拼接后的结果
    for (int i = 1; i <= n; i++)
    {
        printf("%s", str_num[i]);
    }
}