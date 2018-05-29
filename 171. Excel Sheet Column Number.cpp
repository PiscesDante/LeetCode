class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        int sum = 0;
        int time = 1;
        for (int i = len - 1; i >= 0; --i) {
            sum += ((s[i] - 'A' + 1) * time);
            time *= 26;
        }
        return sum;
    }
};

// 执行用时：4 ms
// 已经战胜 100.00 % 的 cpp 提交记录