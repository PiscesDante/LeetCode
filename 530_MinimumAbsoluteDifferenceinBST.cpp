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
    void inorderTreavers(TreeNode* root) {
        if (root == nullptr) return;
        inorderTreavers(root->left);
        inorder.push_back(root->val);
        inorderTreavers(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorderTreavers(root);
        int len = inorder.size();
        int min_value = inorder[1] - inorder[0];
        for (int i = 1; i < len - 1; ++i) {
            if (inorder[i + 1] - inorder[i] < min_value)
                min_value = inorder[i + 1] - inorder[i];
        }
        return min_value;
    }
    
private:
    vector<int> inorder;
};

// 执行用时：16 ms
// 已经战胜 90.32 % 的 cpp 提交记录