#include <iostream>
using namespace std;

struct fivenumber
{
    int sub1, sub2, sub3;
};

int main()
{
    int k = 0;
    cin >> k;
    bool out = false;
    fivenumber num[20001];
    for (int i = 10000; i <= 30000; i++)
    {
        num[i - 10000].sub1 = i / 100;
        num[i - 10000].sub2 = (i % 10000) / 10;
        num[i - 10000].sub3 = i % 1000;
    }
    for (int i = 0; i <= 20000; i++)
    {
        if (num[i].sub1 % k == 0 && num[i].sub2 % k == 0 && num[i].sub3 % k == 0)
        {
            out = true;
            cout<< i+10000 << endl;
        }
    }
    if (!out)
    {
        cout << "No" << endl;
    }
    return 0;
}