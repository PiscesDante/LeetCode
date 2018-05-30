class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int number = nums[0];
        int count = 1;
        for (auto iter = nums.begin() + 1; iter != nums.end(); ) {
            if (*iter == number) {
                count++;
                if (count > 2) nums.erase(iter);
                else iter++;
            } else {
                number = *iter;
                count = 1;
                iter++;
            }
        }
        return nums.size();
    }
};

// 执行用时：16 ms
// 已经战胜 40.72 % 的 cpp 提交记录