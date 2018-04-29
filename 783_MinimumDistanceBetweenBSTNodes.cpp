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
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        v.reserve(100);
        inorder(root);
        min_value = v[1] - v[0];
        int len = v.size();
        for (int i = 1; i < len - 1; ++i) {
            if (min_value > (v[i + 1] - v[i])) min_value = v[i + 1] - v[i];
        }
        return min_value;
    }

private:
    int min_value;
    vector<int> v;
};

// 执行用时：4 ms
// 已经战胜 97.50 % 的 cpp 提交记录