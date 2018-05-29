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
    void func(ListNode* longer, ListNode* shorter) {
        int count = 0;
        while (count < distance) {
            longer = longer->next;
            count += 1;
        }
        while (longer != nullptr) {
            if (longer == shorter) {
                ret = longer;
                break;
            }
            longer = longer->next;
            shorter = shorter->next;
        }
    }

    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int len1 = 0;
        for (ListNode* temp = head1; temp != nullptr; temp = temp->next) len1 += 1;
        int len2 = 0;
        for (ListNode* temp = head2; temp != nullptr; temp = temp->next) len2 += 1;
        if (len1 > len2) {
            distance = len1 - len2;
            func(head1, head2);
        } else {
            distance = len2 - len1;
            func(head2, head1);
        }
        return ret; 
    }

private:
    ListNode* ret = nullptr;
    int distance = 0;
};

// 执行用时：32 ms
// 已经战胜 88.92 % 的 cpp 提交记录