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
        if (head == nullptr || head->next == nullptr) return head;
        while (head->next && head->val == head->next->val) {
            ListNode* del = head;
            head = head->next;
            delete del;
            del = nullptr;
        }
        if (head == nullptr) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (prev->val == curr->val) {
                ListNode* del = curr;
                curr = curr->next;
                prev->next = curr;
                delete del;
                del = nullptr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

// 执行用时：8 ms
// 已经战胜 100.00 % 的 cpp 提交记录