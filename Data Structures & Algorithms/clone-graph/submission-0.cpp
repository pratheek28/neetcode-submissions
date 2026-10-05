/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* cloneGraph(Node* og, unordered_map<Node*, Node*>& mp) {

        if (mp.find(og) != mp.end()) return mp[og];

        Node* newNode = new Node(og->val);
        mp[og] = newNode;

        for (int i = 0; i < og->neighbors.size(); i++) {
            newNode->neighbors.push_back(cloneGraph(og->neighbors[i], mp));
        }

        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;

        return cloneGraph(node, mp);
    }
};
