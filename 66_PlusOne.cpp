class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry = false;
        
        digits[len - 1] += 1;
        
        if (digits[len - 1] > 9) {
            carry = true;
            digits[len - 1] %= 10;
        } else {
            return digits;
        }
        
        for (int i = len - 2; i >= 0 && carry; --i) {    
            if (carry) digits[i] += 1;
            if (digits[i] > 9) {
                carry = true;
                digits[i] %= 10;
            } else {
                carry = false;
            }
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};


// 109 / 109 个通过测试用例
// 状态：通过
// 执行用时：4 ms

// 已经战胜 95.35 % 的 cpp 提交记录