#include <iostream>
using namespace std;
struct carpet
{
    int a, b, g, k;
} carpet_use[10000];
int main()
{
    int n,x,y;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> carpet_use[i].a >> carpet_use[i].b >> carpet_use[i].g >> carpet_use[i].k;
    }
    cin >> x >> y;
    for(int i = n-1; i >= 0; i--)
    {
        if(x >= carpet_use[i].a && x <= carpet_use[i].a + carpet_use[i].g && y >= carpet_use[i].b && y <= carpet_use[i].b + carpet_use[i].k)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}