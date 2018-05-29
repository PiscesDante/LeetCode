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
    ListNode* insertionSortList(ListNode* head) {
        int len = 0;
        for (ListNode* temp = head; temp != nullptr; temp = temp->next) len++;
        for (int i = 0; i < len; ++i) {
            ListNode* sentinel = head;
            while (sentinel->next != nullptr) {
                if (sentinel->val > sentinel->next->val) {
                    std::swap(sentinel->val, sentinel->next->val);
                }
                sentinel = sentinel->next;
            }
        }
        return head;
    }
};

// 执行用时：160 ms