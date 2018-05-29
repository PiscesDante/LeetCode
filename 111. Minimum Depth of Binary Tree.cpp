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
    void initial_depth(TreeNode* root) {
        if (root == nullptr) return;
        current_depth += 1;
        if (root->left == nullptr && root->right == nullptr) {
            min_depth = current_depth;
        }
        initial_depth(root->left);
        initial_depth(root->right);
        current_depth -= 1;        
    }

    void find_min_depth(TreeNode* root) {
        if (root == nullptr) return;
        current_depth += 1;
        if (root->left == nullptr && root->right == nullptr) {
            if (current_depth < min_depth) min_depth = current_depth;
        }
        find_min_depth(root->left);
        find_min_depth(root->right);
        current_depth -= 1;
    }

    int minDepth(TreeNode* root) {
        current_depth = 0;
        min_depth = 0;
        initial_depth(root);
        current_depth = 0;
        find_min_depth(root);
        return min_depth;
    }

private:
    int current_depth;
    int min_depth;
};

// 执行用时：8 ms
// 已经战胜 98.62 % 的 cpp 提交记录