/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <utility> // std::swap

class Solution {
public:
    void deleteNode(ListNode* node) {
        std::swap(node->val, node->next->val);
        ListNode* del = node->next;
        node->next = node->next->next;
        delete del;
    }
};

// 执行用时：12 ms
// 已经战胜 95.22 % 的 cpp 提交记录