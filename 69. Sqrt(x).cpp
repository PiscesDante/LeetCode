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