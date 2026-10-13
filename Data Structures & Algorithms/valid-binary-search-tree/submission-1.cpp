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

    bool isValidBST(TreeNode* root, int min, int max) {
        if (!root) return true;

        if (root->val <= min || root->val >= max) return false;

        bool left = isValidBST(root->left, min, root->val);
        bool right = isValidBST(root->right, root->val, max);

        if (!left || !right) return false;

        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
