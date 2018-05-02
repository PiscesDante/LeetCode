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
        while (head != nullptr && head->val == val) {
            ListNode* del = head;
            head = head->next;
            delete del;
            del = nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val == val) {
                ListNode* del = curr;
                prev->next = curr->next;
                curr = curr->next;
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

// 执行用时：36 ms
// 已经战胜 11.76 % 的 cpp 提交记录