class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x_tostring = str(x)
        reverse_x_tostring = x_tostring[::-1]
        if x_tostring == reverse_x_tostring :
            return True
        else :
            return False

# 执行用时：380 ms
# 已经战胜 89.06 % 的 python3 提交记录