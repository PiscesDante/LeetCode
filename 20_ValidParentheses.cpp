// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 1:
// 输入: "()"
// 输出: true

// 示例 2:
// 输入: "()[]{}"
// 输出: true

// 示例 3:
// 输入: "(]"
// 输出: false

// 示例 4:
// 输入: "([)]"
// 输出: false

// 示例 5:
// 输入: "{[]}"
// 输出: true

// =======================================================================

#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stck;
        for (char elem : s) {
            if (elem == '(' || elem == '[' || elem == '{') {
                stck.push(elem);
            } else {
                if (stck.empty()) return false;
                if (elem == ')') {
                    if (stck.top() == '(') stck.pop();
                    else return false;
                }
                if (elem == ']') {
                    if (stck.top() == '[') stck.pop();
                    else return false;
                }
                if (elem == '}') {
                    if (stck.top() == '{') stck.pop();
                    else return false;
                }
            }
        }
        if (!stck.empty()) return false;
        else return true;
    }
};

// 执行用时：4 ms
// 已经战胜 91.35 % 的 cpp 提交记录