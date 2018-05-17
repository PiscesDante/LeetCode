/*
 * 解题思路：
 * 先将字串的头尾下标都设置为0
 * 尾部每次递增1，如果新纳入字串的字符和之前的某个字符相等，则头部设置为相同字符的后一个字符的下标
 * 这样形成的新字符串看长度是否超过当前已知的最长字符串的长度，如果超过，更新最大值
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int head = 0;
        int tail = 1;
        int len = s.size();
        while (tail < len) {
            for (int k = head; k < tail; ++k) {
                if (s[k] == s[tail]) {
                    head = k + 1;
                    break;
                }
            }
            if ((tail - head) > max_length) max_length = tail - head;
            tail += 1;
        }
        return max_length + 1;
    }
private:
    int max_length = 0;
};

// 执行用时：24 ms
// 已经战胜 96.92 % 的 cpp 提交记录