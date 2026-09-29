#include <stdio.h>
// 题目核心理解：
// 1.何为“面对面时转向”？
// 因为士兵之间没有区别，故面对面相遇之后两士兵转向再继续走相当于两个士兵互相”穿过“彼此
// 2.求最大时间和最小时间，本质是求？
// 不考虑转向后，即：一条路走到头，此时求最大时间和最小时间本质是找到两个极端情况。
// 对于坐标为x的士兵：
//      向左走：用时   x
//      向右走，用时  L+1-x
// 对于每个士兵：
//      最短时间：min(x,L+1-x)
//      最长时间：max(x,L+1-x)
//
// PS：需要注意的是：
// 对于全局来说：
// 1）最小时间：求的是所有士兵最小时间的最大值（最慢的决定整体）
// 2）最大时间：求的是所有士兵最大时间的最大值

// 注意！！两次都是所有士兵的时间中最大的一个！！
int main()
{
    int L, N;
    scanf("%d %d", &L, &N);
    int coord[5050];
    // coord[i]表示第i个士兵当前所在的坐标
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &coord[i]);
    }
    int min_time[5050];
    int max_time[5050];
    for (int i = 1; i <= N; i++)
    {
        min_time[i] = coord[i] < (L + 1 - coord[i]) ? coord[i] : (L + 1 - coord[i]);
        max_time[i] = coord[i] > (L + 1 - coord[i]) ? coord[i] : (L + 1 - coord[i]);
    }
    int min_time_all = 0;
    int max_time_all = 0;
    for (int i = 1; i <= N; i++)
    {
        if (min_time[i] > min_time_all)
            min_time_all = min_time[i];
        if (max_time[i] > max_time_all)
            max_time_all = max_time[i];
    }
    printf("%d %d\n", min_time_all, max_time_all);
    return 0;
}