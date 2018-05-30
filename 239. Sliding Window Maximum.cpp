class Solution {
public:
    void findMaxValue(const vector<int>& nums, int left, int right) {
        int max = nums[left++];
        for (; left <= right; ++left) {
            if (nums[left] > max) max = nums[left];
        }
        ret.push_back(max);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return ret;
        int len = nums.size();
        for (int left = 0, right = k - 1; right < len; ++left, ++right)
            findMaxValue(nums, left, right);
        return ret;
    }

private:
    vector<int> ret;

};

// 执行用时：96 ms
// 已经战胜 4.76 % 的 cpp 提交记录