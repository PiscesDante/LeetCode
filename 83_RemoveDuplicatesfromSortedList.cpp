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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int current_data = head->val;
        while (curr != nullptr) {
            if (curr->val == current_data) {
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
                temp = nullptr;
            } else {
                current_data = curr->val;
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

// 执行用时：12 ms
// 已经战胜 85.67 % 的 cpp 提交记录