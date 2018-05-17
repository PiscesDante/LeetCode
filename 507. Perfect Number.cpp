/*
 * 解题思路：
 * 因数的分切点就在原数的根号之前
 * 也就是说只要找到前半部分的因数，也就可以使用 原数/前半部分因数 的方法找到后半部分的因数
 * 全部加起来即可
 */

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0 || num == 1) return false;
        int sum = 1;
        for (int i = 2; i < sqrt(num); ++i) {
            if (num % i == 0) sum += (i + num / i);
        }
        return sum == num;
    }
};

// 执行用时：4 ms
// 已经战胜 98.84 % 的 cpp 提交记录