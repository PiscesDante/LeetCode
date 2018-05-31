class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            if (n % 2) ret += 1;
            n /= 2;
        }
        return ret;
    }
};

// 执行用时：4 ms
// 已经战胜 98.70 % 的 cpp 提交记录