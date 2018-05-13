/*
 * 解题思路：
 * 将两个有序数组归并到一个新的数组之中
 * 如果新的数组长度为奇数，则取中间的数值
 * 如果新的数组长度为偶数，则取中间两个数值的平均数
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total_length = len1 + len2;
        int total_index = 0;
        int index1 = 0;
        int index2 = 0;
        while (total_index < total_length) {
            while (index1 == len1 && index2 < len2) {
                v.push_back(nums2[index2++]);
                ++total_index;
            }
            while (index2 == len2 && index1 < len1) {
                v.push_back(nums1[index1++]);
                ++total_index;
            }
            while (index1 < len1 && index2 < len2) {
                if (nums1[index1] < nums2[index2]) {
                    v.push_back(nums1[index1++]);
                } else {
                    v.push_back(nums2[index2++]);
                }
                ++total_index;
            }
        }
        if (total_length % 2) {
            return v[total_length / 2];
        } else {
            return (v[total_length / 2] + v[total_length / 2 - 1]) / 2.0;
        }
    }

private:
    vector<int> v;

};

// 执行用时：68 ms
// 已经战胜 30.91 % 的 cpp 提交记录