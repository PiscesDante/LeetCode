/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <deque>

class Solution {
public:
    void stringMaker() {
        string temp;
        int len = route.size();
        for (int i = 0; i < len; ++i) {
            if (i != len - 1) {
                temp += to_string(route[i]);
                temp += "->";
            } else {
                temp += to_string(route[i]);
            }
        }
        res.push_back(temp);
    }
    
    void routeMaker(TreeNode* root) {
        route.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) stringMaker();
        if (root->left != nullptr) routeMaker(root->left);
        if (root->right != nullptr) routeMaker(root->right);
        route.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return res;
        else routeMaker(root);
        return res;
    }
    
private:
    deque<int> route;
    vector<string> res;
};

// 执行用时：16 ms
// 已经战胜 6.34 % 的 cpp 提交记录