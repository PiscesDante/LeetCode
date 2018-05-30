class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        for (int i = len - 1; i >= 0; --i) {
            if (nums[i] == 0) {
                int j = i;
                while (nums[j] != nums[j + 1] && (j + 1) < len) {
                    std::swap(nums[j], nums[j + 1]);
                    ++j;
                }
            }
        }
    }
};

// 执行用时：24 ms
// 已经战胜 19.41 % 的 cpp 提交记录