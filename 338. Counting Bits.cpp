class Solution {
public:
    void countBitsHelper(int num) {
        int count = 0;
        while (num) {
            if (num % 2) count += 1;
            num /= 2;
        }
        ret.push_back(count);
    }

    vector<int> countBits(int num) {
        for (int i = 0; i <= num; ++i) countBitsHelper(i);
        return ret;
    }

private:
    vector<int> ret;
};

// 执行用时：72 ms
// 已经战胜 51.05 % 的 cpp 提交记录