class Solution {
public:
    int max(vector<int>& nums, int k) {
        int ret = nums[0];
        for (int i = 0; i < k; ++i) if (nums[i] > ret) ret = nums[i];
        return ret;
    }
    
    int get_max(vector<int>& nums, int tail, int head) {
        int ret = nums[tail];
        for (int i = tail; i <= head; ++i) {
            if (nums[i] > ret) ret = nums[i];
        }
        return ret;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return res;
        if (k == 1) return nums;
        int tail = 0;
        int head = k - 1;
        int max_value = max(nums, k);
        int len = nums.size();
        while (head < len) {
            max_value = get_max(nums, tail, head);
            res.push_back(max_value);
            head++;
            tail++;
        }
        return res;
    }
    
private:
    vector<int> res;
    
};

// 执行用时：92 ms
// 已经战胜 8.33 % 的 cpp 提交记录