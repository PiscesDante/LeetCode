/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 我的思路：虽然非常慢……
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* front = head;
        while (front != nullptr) {
            ListNode* back = head;
            while (back != front) {
                if (back == front->next) return true;
                back = back->next;
            }
            if (front->next == back) return true;
            front = front->next;
        }
        return false;
    }
};

// ==============================================================

// 范例思路
// 分别设置快慢指针
// 如果链表内存在环路，则快慢指针必然相遇
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != nullptr && head != slow) {
            fast = fast->next;
            if (!fast) break;
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == nullptr) return false;
        if (fast == slow) return true;
    }
};