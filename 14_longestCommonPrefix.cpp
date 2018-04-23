// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1:
// 输入: ["flower","flow","flight"]
// 输出: "fl"

// 示例 2:
// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。

// 说明: 所有输入只包含小写字母 a-z 。

// ===================================================================

#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) return res;
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];
        int common_length = (first.size() < last.size()) ? first.size() : last.size();
        for (int index = 0; index < common_length; ++index) {
            if (first[index] != last[index]) return res;
            else res += first[index];
        }
        return res;
    }
};

// 执行用时：8 ms
// 已经战胜 74.90 % 的 cpp 提交记录