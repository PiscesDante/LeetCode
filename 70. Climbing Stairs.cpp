class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int val1 = 1;
        int val2 = 2;
        for (int i = 3; i <= n; ++i) {
            int temp = val2;
            val2 += val1;
            val1 = temp;
        }
        return val2;
    }
};

// 斐波那契数列的原型
// 执行用时：0 ms
// 已经战胜 100.00 % 的 cpp 提交记录