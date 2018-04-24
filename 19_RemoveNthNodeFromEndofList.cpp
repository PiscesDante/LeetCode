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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        ListNode* front = head;
        int count = 1;
        
        while (count < n) {
            front = front->next;
            count += 1;
        }
        
        ListNode* prev = nullptr;
        ListNode* target = head;
        
        while (front->next != nullptr) {
            front = front->next;
            prev = target;
            target = target->next;
        }
        
        if (target == head) {
            ListNode* del = head;
            head = head->next;
            delete del;
            del = nullptr;
        } else {
            prev->next = target->next;
            delete target;
            target = nullptr;
        }
        
        return head;
    }
};

// 执行用时：8 ms
// 已经战胜 94.24 % 的 cpp 提交记录