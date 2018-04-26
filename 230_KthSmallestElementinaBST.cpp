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
    void getMinValue(TreeNode* root) {
        if (root == nullptr) return;
        while (root->left != nullptr) root = root->left;
        min_value = root->val;
    }
    
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        if (count < target_count && root->val > value) {
            value = root->val;
            ++count;
        }
        inorder(root->right);
    }
    
    // main function
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return value;
        target_count = k;
        getMinValue(root);
        value = min_value;
        count = 1;
        inorder(root);
        return value;
    }
    
private:
    int target_count = 0;
    int min_value = 0;
    int count = 0;
    int value = 0;
};

// 执行用时：12 ms
// 已经战胜 99.27 % 的 cpp 提交记录