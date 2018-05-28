class Solution {
public:
    void permute(vector<int>& nums, int index) {
        if (index == len) {
            ret.push_back(nums);
        } else {
            for (int i = index; i < len; ++i) {
                swap(nums[index], nums[i]);
                permute(nums, index + 1);
                swap(nums[index], nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        permute(nums, 0);
        return ret;
    }

private:
    vector<vector<int>> ret;
    int len = 0;

};

// 执行用时：8 ms
// 已经战胜 100.00 % 的 cpp 提交记录