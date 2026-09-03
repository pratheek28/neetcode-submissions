/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int res = 1;
    void goodNodes(TreeNode* root, int mostRecent) {
        if (!root) return;

        if (root->val >= mostRecent) {
            res++;
            mostRecent = root->val;
        }

        goodNodes(root->left, mostRecent);
        goodNodes(root->right, mostRecent);
    }
public:
    int goodNodes(TreeNode* root) {
        goodNodes(root->left, root->val);
        goodNodes(root->right, root->val);

        return res;
    }
};
