class Solution {
public:
    double func(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n % 2) {
            return x * func(x, n / 2) * func(x, n / 2);
        } else {
            return func(x, n / 2) * func(x, n / 2);
        }
    }
    
    double myPow(double x, int n) {
        if (n < 0) {
            n *= -1;
            x = 1.0 / x;
        }
        return func(x, n);
    }
};

// 执行用时：16 ms
// 已经战胜 10.35 % 的 cpp 提交记录