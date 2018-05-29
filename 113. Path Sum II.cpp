/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>

class Solution {
public:
    void vectorMaker() {
        vector<int> temp;
        for (int num : route) temp.push_back(num);
        res.push_back(temp);
    }

    void routeMaker(TreeNode* root) {
        present_sum += root->val;
        route.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && present_sum == input_sum) vectorMaker();
        if (root->left != nullptr) routeMaker(root->left);
        if (root->right != nullptr) routeMaker(root->right);
        present_sum -= root->val;
        route.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // initialization
        input_sum = sum;
        present_sum = 0;
        if (root != nullptr) routeMaker(root);
        return res;
    }

private:
    int input_sum;
    int present_sum;
    list<int> route;
    vector<vector<int>> res;
};

// 执行用时：12 ms
// 已经战胜 64.83 % 的 cpp 提交记录