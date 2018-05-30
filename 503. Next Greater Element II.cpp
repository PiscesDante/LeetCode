class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int j = i + 1;
            bool is_found = false;
            for (int count = 1; count < len; ++count, ++j) {
                if (nums[j % len] > nums[i]) {
                    res.push_back(nums[j % len]);
                    is_found = true;
                    break;
                }
            }
            if (!is_found) res.push_back(-1);
        }
        return res;
    }

private:
    vector<int> res;
};

// 执行用时：384 ms
// 已经战胜 14.29 % 的 cpp 提交记录