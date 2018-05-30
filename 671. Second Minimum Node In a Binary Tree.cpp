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
    void findDifferentNumber(TreeNode* root) {
        if (root == nullptr) return;
        if (root->val > min_value) {
            res = root->val;
            return;
        }
        findDifferentNumber(root->left);
        findDifferentNumber(root->right);
    }
    
    void findSecondMinimum(TreeNode* root) {
        if (root == nullptr) return;
        if (root->val > min_value && root->val < res) res = root->val;
        findSecondMinimum(root->left);
        findSecondMinimum(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        min_value = root->val;
        res = root->val;
        findDifferentNumber(root);
        if (res == min_value) return -1;
        findSecondMinimum(root);
        return res;
    }
    
private:
    int min_value;
    int res;
};

// 执行用时：12 ms
// Your runtime beats 97.05 % of cpp submissions.