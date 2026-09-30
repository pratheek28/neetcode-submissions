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
    bool findP (TreeNode* node, TreeNode* target, unordered_map<TreeNode*, int>& mp) {
        if (!node) return false;

        if (node == target) return true;

        mp[node] = 1;

        bool checkL = findP(node->left, target, mp);

        if (checkL) return true;

        bool checkR =  findP(node->right, target, mp);

        if (!checkR) {
            mp[node] = 0;
            return false;
        }

        return true;
    }

    bool findQ(TreeNode* node, TreeNode* target, stack<TreeNode*>& st) {
        if (!node) return false;

        if (node == target) return true;

        st.push(node);

        bool checkL = findQ(node->left, target, st);

        if (checkL) return true;

        bool checkR =  findQ(node->right, target, st);

        if (!checkR) {
            st.pop();
            return false;
        }

        return true;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, int> pMap;
        stack<TreeNode*> qStack;

        findP(root, p, pMap);
        findQ(root, q, qStack);

        pMap[p] = 1;
        qStack.push(q);

        while (!qStack.empty()) {
            if (pMap.find(qStack.top()) != pMap.end() && pMap[qStack.top()] != 0) return qStack.top();

            qStack.pop();
        }

        return nullptr;
    }
};
