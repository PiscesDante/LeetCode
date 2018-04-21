// 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
// 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

// 示例:
// 给定 nums = [2, 7, 11, 15], target = 9
// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]

// ===================================================================

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                } 
            }
        }
    }
};

// 执行用时：96 ms
// 已经战胜 55.35 % 的 cpp 提交记录