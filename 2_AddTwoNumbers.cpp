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
    void push(int val) {
        if (head == nullptr) {
            head = new ListNode(val);
            tail = head;
        } else {
            ListNode* temp_new = new ListNode(val);
            tail->next = temp_new;
            tail = temp_new;
        }
    }

    void step_one(ListNode*& ptr1, ListNode*& ptr2) {
        while (ptr1 && ptr2) {
            int temp_val = ptr1->val + ptr2->val;
            if (is_carry) {
                temp_val += 1;
                is_carry = false;
            }
            if (temp_val > 9) {
                temp_val %= 10;
                is_carry = true;
            }
            push(temp_val);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    void step_two(ListNode*& ptr) {
        while (ptr) {
            int temp_val = ptr->val;
            if (is_carry) {
                temp_val += 1;
                is_carry = false;
            }
            if (temp_val > 9) {
                temp_val %= 10;
                is_carry = true;
            }
            push(temp_val);
            ptr = ptr->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        step_one(l1, l2);
        if (l1) step_two(l1);
        if (l2) step_two(l2);
        if (is_carry) push(1);
        return head;
    }
    
private:
    bool is_carry = false;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
};

// 执行用时：48 ms
// 已经战胜 83.78 % 的 cpp 提交记录