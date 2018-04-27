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
        if (head == nullptr) return head;
        
        ListNode* left = nullptr;
        ListNode* curr = head;
        ListNode* right = head->next;
        
        while (curr != nullptr) {
            if (left == nullptr || right == nullptr) {
                if (left == nullptr && right == nullptr) nonduplicate_numbers.push_back(curr->val);
                else if (left != nullptr && right == nullptr) {
                    if (left->val != curr->val) nonduplicate_numbers.push_back(curr->val);
                } else {
                    if (right->val != curr->val) nonduplicate_numbers.push_back(curr->val);
                }
            }
            if (left != nullptr && right != nullptr) {
                if (left->val != curr->val && right->val != curr->val) {
                    nonduplicate_numbers.push_back(curr->val);
                }
            }
            left = curr;
            curr = right;
            if (right != nullptr) right = right->next;
        }
        
        ListNode* new_head = nullptr;
        ListNode* new_tail = nullptr;
        
        for (int elem : nonduplicate_numbers) {
            if (new_head == nullptr) {
                new_head = new ListNode(elem);
                new_head->next = nullptr;
                new_tail = new_head;
            } else {
                ListNode* new_temp = new ListNode(elem);
                new_temp->next = nullptr;
                new_tail->next = new_temp;
                new_tail = new_tail->next;
            }
        }
        
        return new_head;
    }
    
private:
    vector<int> nonduplicate_numbers;
};

// 执行用时：8 ms
// 已经战胜 94.40 % 的 cpp 提交记录