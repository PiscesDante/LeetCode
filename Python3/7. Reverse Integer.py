class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if -10 < x and x < 10 : return x
        is_negative = False
        if x < 0 :
            is_negative = True
            x *= -1
        while x % 10 == 0 : x /= 10
        x = int(x)
        ret = int(str(x)[::-1])
        if is_negative : ret *= -1
        if ret > 2 ** 31 - 1 or ret < -2 ** 31 : return 0
        else : return ret

# 执行用时：76 ms
# 已经战胜 87.61 % 的 python3 提交记录