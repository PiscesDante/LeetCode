class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;
        int mid = head;
        while (head < tail) {
            mid = (head + tail) / 2;
            if (mid == head) break;
            if (target > nums[mid]) head = mid;
            else if (target < nums[mid]) tail = mid;
            else return mid;
        }
        if (target > nums[tail]) return tail + 1;
        else if (target > nums[head]) return head + 1;
        else return head;
    }
};

// 执行用时：4 ms
// 已经战胜 100.00 % 的 cpp 提交记录