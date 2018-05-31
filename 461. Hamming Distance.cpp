class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y;
        int ret = 0;
        while (ans != 0) {
            if (ans % 2 == 1) ret += 1;
            ans /= 2;
        }
        return ret;
    }
};

// 执行用时：4 ms
// 已经战胜 98.72 % 的 cpp 提交记录