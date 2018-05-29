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
    void helperFunc(TreeNode* root) {
        if (root == nullptr) return;
        helperFunc(root->left);
        helperFunc(root->right);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        helperFunc(root);
        return res;
    }
    
private:
    vector<int> res;
};

// Runtime: 3 ms
// Your runtime beats 97.19 % of cpp submissions.