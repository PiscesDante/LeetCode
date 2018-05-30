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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // first list inbound
        // ==============================================================
        int len = lists.size();
        int first_nonEmpty_list_index = 0;
        for (; first_nonEmpty_list_index < len; ++first_nonEmpty_list_index) {
            if (lists[first_nonEmpty_list_index] != nullptr) break;
        }
        ListNode* first_list = nullptr;
        if (first_nonEmpty_list_index == len) return nullptr;
        else first_list = lists[first_nonEmpty_list_index];
        while (first_list != nullptr) {
            if (head == nullptr) {
                head = new ListNode(first_list->val);
                head->next = nullptr;
                now = head;
            } else {
                ListNode* temp = new ListNode(first_list->val);
                temp->next = nullptr;
                now->next = temp;
                now = temp;
            }
            first_list = first_list->next;
        }

        // rest lists inbound
        // ==============================================================
        
        for (int i = first_nonEmpty_list_index + 1; i < len; ++i) {
            ListNode* list_head = lists[i]; // each list head
            while (list_head != nullptr) {
                if (list_head->val < head->val) {
                    ListNode* temp = new ListNode(list_head->val);
                    temp->next = head;
                    head = temp;
                } else {
                    ListNode* prev = nullptr;
                    ListNode* curr = head;
                    while (curr != nullptr) {
                        if (list_head->val < curr->val) {
                            ListNode* temp = new ListNode(list_head->val);
                            temp->next = curr;
                            prev->next = temp;
                            break;
                        }
                        prev = curr;
                        curr = curr->next;
                    }
                    if (curr == nullptr) {
                        ListNode* temp = new ListNode(list_head->val);
                        prev->next = temp;
                        temp->next = nullptr;
                    }
                }
                list_head = list_head->next;
            }
        }
        return head;
    }
    
private:
    ListNode* head = nullptr;
    ListNode* now = nullptr;
};

// 执行用时：220 ms
// 已经战胜 21.61 % 的 cpp 提交记录