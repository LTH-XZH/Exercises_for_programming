#include "high_num.h"
high_num::high_num(int x) // 构造函数
{
    memset(bits, 0, sizeof(bits));
    len = 0;
    while (x)
    {
        bits[len++] = x % 10;
        x /= 10;
    }
}
// 重新定义加法
high_num high_num::operator+(const high_num &other) const
{
    high_num result;
    int carry = 0;
    int max_len = std::max(len, other.len);
    for (int i = 0; i < max_len || carry; ++i)
    {
        int sum = carry;
        if (i < len)
            sum += bits[i];
        if (i < other.len)
            sum += other.bits[i];
        result.bits[result.len++] = sum % 10;
        carry = sum / 10;
    }
    return result;
}
// 重新定义乘法
high_num high_num::operator*(int x) const
{
    high_num result;
    int carry = 0;
    for (int i = 0; i < len || carry; ++i)
    {
        long long product = carry;
        if (i < len)
            product += (long long)bits[i] * x;
        result.bits[result.len++] = product % 10;
        carry = product / 10;
    }
    return result;
}
// 重新定义赋值运算符
high_num &high_num::operator=(int x)
{
    memset(bits, 0, sizeof(bits));
    len = 0;

    if (x == 0)
    {
        len = 1;
        bits[0] = 0;
        return *this;
    }

    while (x)
    {
        bits[len++] = x % 10;
        x /= 10;
    }

    return *this;
}
// 定义一个比较大小的函数
high_num high_num::max_high(const high_num &a, const high_num &b)
{
    if (a.len != b.len)
        return a.len > b.len ? a : b;
    for (int i = a.len - 1; i >= 0; --i)
    {
        if (a.bits[i] != b.bits[i])
            return a.bits[i] > b.bits[i] ? a : b;
    }
    return a; // They are equal
}
// 定义自己的输出函数
void high_num::print() const
{
    for (int i = len - 1; i >= 0; --i)
        std::cout << bits[i];
    std::cout << std::endl;
}