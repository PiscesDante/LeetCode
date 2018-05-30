/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 * 解题思路：
 * 就是最普通的中序遍历，然后检查cache数组中是否存在相邻的逆序
 * 如果存在，则无效
 */

class Solution {
public:
    void inoderTraveral(TreeNode* root) {
        if (root == nullptr) return;
        inoderTraveral(root->left);
        cache.push_back(root->val);
        inoderTraveral(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inoderTraveral(root);
        int len = cache.size();
        for (int i = 0; i < len - 1; ++i) {
            if (cache[i] >= cache[i + 1]) return false;
        }
        return true;
    }

private:
    vector<int> cache;
};

// 执行用时：12 ms
// 已经战胜 33.09 % 的 cpp 提交记录