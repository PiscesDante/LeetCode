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
    void findRoot(TreeNode* s, TreeNode* t) {
        if (s == nullptr) return;
        if (s->val == t->val) sub_roots.push_back(s);
        findRoot(s->left, t);
        findRoot(s->right, t);
    }

    void sameTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return;
        if (s != nullptr && t == nullptr) {
            is_same_tree = false;
            return;
        }
        if (s == nullptr && t != nullptr) {
            is_same_tree = false;
            return;
        }
        if (s != nullptr && t != nullptr) {
            if (s->val != t->val) {
                is_same_tree = false;
                return;
            }
        }
        sameTree(s->left, t->left);
        sameTree(s->right, t->right);
    }

    // main function
    bool isSubtree(TreeNode* s, TreeNode* t) {
        findRoot(s, t);
        if (sub_roots.empty()) return false;
        for (TreeNode* sub_root : sub_roots) {
            is_same_tree = true;
            sameTree(sub_root, t);
            if (is_same_tree) return is_same_tree;
        }
        return is_same_tree;
    }

private:
    vector<TreeNode*> sub_roots;
    bool is_same_tree = true;
};

// 执行用时：20 ms
// 已经战胜 97.92 % 的 cpp 提交记录