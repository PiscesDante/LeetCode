// 将两个有序链表合并为一个新的有序链表并返回。
// 新链表是通过拼接给定的两个链表的所有节点组成的。 

// 示例：
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

// ==============================================================

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode* root = nullptr;
        ListNode* now = nullptr;
        while (l1 && l2) {
            if (root == nullptr) {
                if (l1->val < l2->val) {
                    root = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    root = new ListNode(l2->val);
                    l2 = l2->next;
                }
                now = root;
            } else {
                ListNode* temp = nullptr;
                if (l1->val < l2->val) {
                    temp = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    temp = new ListNode(l2->val);
                    l2 = l2->next;
                }
                now->next = temp;
                now = temp;
            }
        }
        if (l1) now->next = l1;
        if (l2) now->next = l2;
        return root;
    }
};

// 执行用时：12 ms
// 已经战胜 91.06 % 的 cpp 提交记录