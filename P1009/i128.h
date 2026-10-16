#include <iostream>
#include <cmath>
#include <cstring>
class i128
{
public:
    i128(int x = 0); // 构造函数
    // 重新定义加法
    i128 operator+(const i128 &other) const;
    // 重新定义乘法
    i128 operator*(int x) const;
    // 重新定义赋值运算符
    i128 &operator=(int x);
    // 定义一个比较大小的函数
    static i128 max_i128(const i128 &a, const i128 &b);
    // 定义自己的输出函数
    void print() const;

private:
    int bits[500];
    int len;
};