/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 * 解题思路：
 * 首先设置快慢指针来检查链表中是否有环，如果无环直接返回nullptr
 * 如果有环，慢指针指向链表的头，快指针不动，然后快慢指针同时向前走直到相遇
 * 相遇的结点就是链表入环的第一个结点
 */

class Solution {
public:
    ListNode* checkCircle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return fast;
            }
        }
        return nullptr;
    }

    ListNode* getEntry(ListNode* head, ListNode* meeting_ptr) {
        while (head != meeting_ptr) {
            head = head->next;
            meeting_ptr = meeting_ptr->next;
        }
        return head;
    }

    // main function
    ListNode *detectCycle(ListNode *head) {
        ListNode* meeting_ptr = checkCircle(head);
        if (meeting_ptr) {
            return getEntry(head, meeting_ptr);
        } else {
            return nullptr;
        }
    }
};

// 执行用时：8 ms
// 已经战胜 100.00 % 的 cpp 提交记录