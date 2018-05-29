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
    void sumMaker() {
        int temp = 0;
        for (int digit : cache) temp = temp * 10 + digit;
        ret += temp;
    }

    void routeMaker(TreeNode* root) {
        if (root == nullptr) return;
        cache.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) sumMaker();
        routeMaker(root->left);
        routeMaker(root->right);
        cache.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return ret;
        routeMaker(root);
        return ret;
    }

private:
    list<int> cache;
    int ret = 0;
};

// 执行用时：0 ms
// 已经战胜 100.00 % 的 cpp 提交记录