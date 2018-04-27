/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <queue>
#include <stack>

class Solution {
public:
    // main function
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || m > n) return head;
        ListNode* sentinel = head;
        int count = 1;
        while (count < m) {
            sentinel = sentinel->next;
            count += 1;
        }
        while (count <= n) {
            pointer_queue.push(sentinel);
            data_stack.push(sentinel->val);
            sentinel = sentinel->next;
            count += 1;
        }
        while (!data_stack.empty()) {
            pointer_queue.front()->val = data_stack.top();
            pointer_queue.pop();
            data_stack.pop();
        }
        return head;
    }
    
private:
    queue<ListNode*> pointer_queue;
    stack<int> data_stack;
};

// 执行用时：4 ms
// 已经战胜 100.00 % 的 cpp 提交记录