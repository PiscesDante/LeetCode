class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int index_a = a.size() - 1;
        int index_b = b.size() - 1;
        int carry = 0;
        while (index_a >= 0 || index_b >= 0 || carry) {
            int digit_a = 0;
            int digit_b = 0;
            if (index_a >= 0) if (a[index_a--] == '1') digit_a = 1;
            if (index_b >= 0) if (b[index_b--] == '1') digit_b = 1;
            int digit = digit_a + digit_b + carry;
            if (digit > 1) carry = 1;
            else carry = 0;
            digit %= 2;
            ret += to_string(digit);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// 执行用时：4 ms
// 已经战胜 94.33 % 的 cpp 提交记录