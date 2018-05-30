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
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        inorder_traversal.push_back(root->val);
        inorderTraversal(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        inorderTraversal(root);
        int head = 0;
        int tail = inorder_traversal.size() - 1;
        while (head < tail) {
            if (inorder_traversal[head] + inorder_traversal[tail] < k) ++head;
            else if (inorder_traversal[head] + inorder_traversal[tail] > k) --tail;
            else return true;
        }
        return false;
    }

private:
    vector<int> inorder_traversal;
};

// 执行用时：36 ms
// 已经战胜 66.30 % 的 cpp 提交记录