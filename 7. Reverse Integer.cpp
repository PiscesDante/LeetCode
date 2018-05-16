/*
 * 解题思路：
 * 通过除以10来取余的方式取出数字的每一位，这种方式会先取最低位的数字
 * 所以我们需要一个队列来实现先进先出，即完成反转
 * 首先我们判定这个数字是否为负，如果为负则先处理成正数
 * 接下来反转这个数字，最后检查越界和正负号即可
 */

#include <queue>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        queue<int> digits;
        int input_number = x;
        bool is_less_than_zero = false;
        if (input_number < 0) {
            is_less_than_zero = true;
            input_number *= -1;
        }
        while (input_number != 0) {
            digits.push(input_number % 10);
            input_number /= 10;
        }
        long long res = 0;
        while (digits.front() == 0) digits.pop();
        while (!digits.empty()) {
            res *= 10;
            res += digits.front();
            digits.pop();
        }
        if (is_less_than_zero) res *= -1;
        if (res > INT_MAX || res < INT_MIN) return 0;
        return res;
    }
};

// 执行用时：24 ms
// 已经战胜 52.29 % 的 cpp 提交记录