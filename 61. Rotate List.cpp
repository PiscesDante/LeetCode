/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len += 1;
            temp = temp->next;
        }
        int real_k = k % len;
        if (real_k == 0) return head;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 1;
        while (count < real_k) {
            fast = fast->next;
            ++count;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        ListNode* new_head = slow;
        fast->next = head;
        prev->next = nullptr;

        return new_head;
    }
};

// 执行用时：12 ms
// 已经战胜 97.22 % 的 cpp 提交记录