class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums1.extend(nums2)
        nums1.sort()
        total_length = len(nums1)
        if total_length % 2 :
            return nums1[total_length // 2]
        else :
            return (nums1[total_length // 2] + nums1[total_length // 2 - 1]) / 2

# 执行用时：156 ms
# 已经战胜 38.20 % 的 python3 提交记录