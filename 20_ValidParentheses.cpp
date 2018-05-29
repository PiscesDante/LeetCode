class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stck;
        for (char elem : s) {
            if (elem == '(' || elem == '[' || elem == '{') {
                stck.push(elem);
            } else {
                if (stck.empty()) {
                    return false;
                } else if (elem == ')') {
                    if (stck.top() == '(') stck.pop();
                    else return false;
                } else if (elem == ']') {
                    if (stck.top() == '[') stck.pop();
                    else return false;
                } else if (elem == '}') {
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