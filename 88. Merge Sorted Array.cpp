class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_length = nums1.size();
        int nums2_length = nums2.size();
        int nums2_index = 0;
        for (int i = m; i < nums1_length; ++i) {
            if (nums2_index < nums2_length) {
                nums1[i] = nums2[nums2_index];
                nums2_index += 1;
            }
        }
        sort(nums1.begin(), nums1.end());
    }
};

// 执行用时：4 ms
// 已经战胜 100.00 % 的 cpp 提交记录