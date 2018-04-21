// 实现 int sqrt(int x) 函数。
// 计算并返回 x 的平方根，其中 x 是非负整数。
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

// 示例 1:
// 输入: 4
// 输出: 2

// 示例 2:
// 输入: 8
// 输出: 2
// 说明: 8 的平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。

// ============================================================================

class Solution {
public:
    long long mySqrt(long long x) {
        long long begin = 0;
        long long end = x;
        while (begin <= end) {
            long long mid = (begin + end) / 2;
            if (x < mid * mid) end = mid - 1;
            else if (x > mid * mid) begin = mid + 1;
            else return mid;
        }
        return end;
    }
};

// 执行用时：24 ms
// 已经战胜 69.51 % 的 cpp 提交记录