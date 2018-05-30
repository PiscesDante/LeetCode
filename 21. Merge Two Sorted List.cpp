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
    void push_back(int val) {
        if (head == nullptr) {
            head = new ListNode(val);
            curr = head;
        } else {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        while (l1 || l2) {
            if (!l1) {
                push_back(l2->val);
                l2 = l2->next;
            } else if (!l2) {
                push_back(l1->val);
                l1 = l1->next;
            } else if (l1->val < l2->val) {
                push_back(l1->val);
                l1 = l1->next;
            } else {
                push_back(l2->val);
                l2 = l2->next;
            }
        }
        return head;
    }

private:
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
};

// 执行用时：12 ms
// 已经战胜 94.56 % 的 cpp 提交记录