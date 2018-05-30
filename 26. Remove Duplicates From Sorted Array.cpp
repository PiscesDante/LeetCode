class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int nums_length = nums.size();
        int current_index = 0;
        int sentinel_index = 0;
        while (sentinel_index < nums_length) {
            if (nums[current_index] == nums[sentinel_index]) {
                sentinel_index += 1;
            } else {
                current_index += 1;
                nums[current_index] = nums[sentinel_index];
                sentinel_index += 1;
            }
        }
        return current_index + 1;
    }
};

// 执行用时：28 ms
// 已经战胜 80.48 % 的 cpp 提交记录