/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool res = true;
    
    void isSameNode(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return;
        if (p == nullptr && q != nullptr) {
            res = false;
            return;
        }
        if (p != nullptr && q == nullptr) {
            res = false;
            return;
        }
        if (p != nullptr && q != nullptr) {
            if (p->val != q->val) {
                res = false;
                return;
            }
        }
        isSameNode(p->left, q->left);
        isSameNode(p->right, q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        isSameNode(p, q);
        return res;
    }
};

// 执行用时：4 ms
// 已经战胜 88.75 % 的 cpp 提交记录