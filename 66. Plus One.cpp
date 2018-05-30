class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos = digits.size() - 1;
        int carry = 1;
        for (; pos >= 0 && carry; --pos) {
            if (carry == 0) return digits;
            digits[pos] += carry;
            if (digits[pos] > 9) carry = 1;
            else carry = 0;
            digits[pos] %= 10;
        }
        if (pos < 0 && carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};

// 执行用时：4 ms
// 已经战胜 92.95 % 的 cpp 提交记录