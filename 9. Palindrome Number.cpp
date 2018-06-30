class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int rever = 0;
        int raw = x;
        while (x != 0) {
            rever *= 10;
            rever += (x % 10);
            x /= 10;
        }
        return rever == raw;
    }
};

// 执行用时：220 ms
// 已经战胜 37.36 % 的 cpp 提交记录