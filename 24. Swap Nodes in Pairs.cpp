/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 * 解题思路：
 * 链表两两反转的话因为后面一组的反转会影响前面一组第二个结点的next指针
 * 所以只能采用递归，先让反转指针对触底然后从后往前反转链表，并且将当前
 * 组反转后的第一个结点的地址保存在全局变量内供上一层的操作来使用
 */

class Solution {
public:
    void exchangeNode(ListNode* prev, ListNode* curr) {
        if (curr == nullptr) {
            catch_node = prev;
            return;
        }
        if (curr->next != nullptr) exchangeNode(curr->next, curr->next->next);
        prev->next = catch_node;
        curr->next = prev;
        catch_node = curr;
    }
    
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        exchangeNode(head, head->next);
        return catch_node;
    }

private:
    ListNode* catch_node = nullptr;
};

// 执行用时：4 ms
// 已经战胜 100.00 % 的 cpp 提交记录