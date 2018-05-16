# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = None
        tail = None
        carry = 0
        while l1 or l2 or carry :
            temp_val = 0
            if l1 : temp_val += l1.val
            if l2 : temp_val += l2.val
            if carry : temp_val += carry
            if temp_val > 9 : carry = 1
            else : carry = 0
            temp_val %= 10
            if not head :
                head = tail = ListNode(temp_val)
            else :
                tail.next = ListNode(temp_val)
                tail = tail.next
            if l1 : l1 = l1.next
            if l2 : l2 = l2.next
        return head

# 执行用时：156 ms
# 已经战胜 92.56 % 的 python3 提交记录