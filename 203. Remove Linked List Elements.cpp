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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        while (head != nullptr && head->val == val) {
            ListNode* del = head;
            head = head->next;
            delete del;
            del = nullptr;
        }
        if (head == nullptr) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            if (curr->val == val) {
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

// 执行用时：24 ms
// 已经战胜 98.45 % 的 cpp 提交记录