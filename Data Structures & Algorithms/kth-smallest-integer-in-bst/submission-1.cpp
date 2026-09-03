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
    void traverse(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& minHeap) {
        if (!root) return;

        minHeap.push(root->val);

        traverse(root->left, minHeap);
        traverse(root->right, minHeap);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        traverse(root, minHeap);

        while (!minHeap.empty() && k != 1) {
            minHeap.pop();
            k--;
        }

        return minHeap.top();
    }
};
