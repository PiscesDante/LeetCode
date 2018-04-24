class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = nums[0];
        for (int number : nums) {
            sum += number;
            if (sum > max) max = sum;
            if (sum < 0) sum = 0;
        }
        return max;
    }
};

// 执行用时：12 ms
// 已经战胜 63.51 % 的 cpp 提交记录