class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return (num == 1);
    }
};

// 执行用时：4 ms
// 已经战胜 100.00 % 的 cpp 提交记录