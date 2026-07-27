//电控组考核中极其简单的题，当时的基本功还不够扎实，完全不够用。
#include <stdio.h>
struct student
{
    char name[10];
    int age;
    float score;
}all[10];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %f", all[i].name, &all[i].age, &all[i].score);
    }
    for (int i = 0; i < n; i++)
    {
        if(all[i].score >= 60)
        printf("%s %d %.1f\n", all[i].name, all[i].age, all[i].score);
    }
    return 0;
}