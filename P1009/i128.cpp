#include "i128.h"
// 注意新定义的加法乘法等实现逻辑，有助于加深理解算法和运算。
i128::i128(int x) // 构造函数
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
i128 i128::operator+(const i128 &other) const
{
    i128 result;
    int carry = 0; // 进位
    int max_len = std::max(len, other.len);
    for (int i = 0; i < max_len || carry; ++i)
    {
        int sum = carry; // 类比竖式计算，先加进位值
        if (i < len)
            sum += bits[i];
        if (i < other.len)
            sum += other.bits[i];
        // 与构造函数相似逻辑，将“数”转存入数组
        result.bits[result.len++] = sum % 10;
        carry = sum / 10;
    }
    return result;
}
// 重新定义乘法
i128 i128::operator*(int x) const
{
    i128 result;
    int carry = 0; // 进位
    for (int i = 0; i < len || carry; ++i)
    {
        long long product = carry; // 同上，先加进位值
        if (i < len)
            product += (long long)bits[i] * x;
        result.bits[result.len++] = product % 10;
        carry = product / 10;
    }
    return result;
}
// 重新定义赋值运算符
i128 &i128::operator=(int x)
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
i128 i128::max_i128(const i128 &a, const i128 &b)
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
void i128::print() const
{
    for (int i = len - 1; i >= 0; --i)
        std::cout << bits[i];
    std::cout << std::endl;
}