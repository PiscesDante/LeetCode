/*
 * 解题思路：
 * 设置头尾坐标，升序有序数组旋转之后数组分为两个升序的子数组
 * 取中间的数字
 * 如果它比尾坐标的数字大，根据拉格朗日定理，则必然存在最小值
 * 如果它比尾坐标的数字小，则说明后面的数字均比中间的数字大，则最小值必定在前半部分
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (nums[mid] > nums[end]) begin = mid + 1;
            else end = mid;
        }
        return nums[begin];
    }
};

// 执行用时：4 ms
// 已经战胜 97.73 % 的 cpp 提交记录