/*
 * 解题思路：
 * 这个逆波兰表达式的求值的核心就是借助一个栈即可
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (string ch : tokens) {
            if (ch == "+") {
                int second = value_stack.top();
                value_stack.pop();
                int first = value_stack.top();
                value_stack.pop();
                int new_value = first + second;
                value_stack.push(new_value);
            } else if (ch == "-") {
                int second = value_stack.top();
                value_stack.pop();
                int first = value_stack.top();
                value_stack.pop();
                int new_value = first - second;
                value_stack.push(new_value);
            } else if (ch == "*") {
                int second = value_stack.top();
                value_stack.pop();
                int first = value_stack.top();
                value_stack.pop();
                int new_value = first * second;
                value_stack.push(new_value);
            } else if (ch == "/") {
                int second = value_stack.top();
                value_stack.pop();
                int first = value_stack.top();
                value_stack.pop();
                int new_value = first / second;  
                value_stack.push(new_value);
            } else {
                value_stack.push(atoi(ch.c_str()));
            }
        }
        return value_stack.top();
    }

private:
    stack<int> value_stack;
};

// 执行用时：12 ms
// 已经战胜 44.23 % 的 cpp 提交记录