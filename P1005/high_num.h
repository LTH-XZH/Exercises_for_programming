#include <iostream>
#include <cmath>
#include <cstring>
class high_num
{
public:
    high_num(int x = 0); // 构造函数
    // 重新定义加法
    high_num operator+(const high_num &other) const;
    // 重新定义乘法
    high_num operator*(int x) const;
    // 重新定义赋值运算符
    high_num &operator=(int x);
    // 定义一个比较大小的函数
    static high_num max_high(const high_num &a, const high_num &b);
    // 定义自己的输出函数
    void print() const;

private:
    int bits[500];
    int len;
};