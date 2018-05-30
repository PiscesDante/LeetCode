class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int last_word_length = 0;
        int len = s.size();
        int index = len - 1;
        while (s[index] == ' ' && index >= 0) --index;
        while (s[index] != ' ' && index >= 0) {
            ++last_word_length;
            --index;
        }
        return last_word_length;
    }
};

// 执行用时：4 ms
// 已经战胜 98.84 % 的 cpp 提交记录