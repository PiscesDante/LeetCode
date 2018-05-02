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
    void deleteNode(ListNode* node) {  
        ListNode* temp = node->next;  
        node->val = temp->val;  
        node->next = temp->next;  
        delete temp;
        temp = nullptr;
    }  
};

// 执行用时：24 ms
// 已经战胜 3.44 % 的 cpp 提交记录