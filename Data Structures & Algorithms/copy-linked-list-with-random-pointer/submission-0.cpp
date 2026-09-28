/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* loop = head;

        Node* newHead = new Node(head->val);
        mp[loop] = newHead;

        Node* newLoop = newHead;

        loop = loop->next;

        while (loop) {
            Node* newNode = new Node(loop->val);
            newLoop->next = newNode;

            mp[loop] = newNode;
            loop = loop->next;
            newLoop = newLoop->next;
        }

        loop = head;
        newLoop = newHead;

        while (loop) {
            if (loop->random) {
                if (mp.find(loop->random) != mp.end()) {
                    newLoop->random = mp[loop->random];
                }else {
                    Node* newNode = new Node(loop->random->val);
                    newLoop->random = newNode;
                    mp[loop->random] = newNode;
                }
            }
            loop = loop->next;
            newLoop = newLoop->next;
        }

        return newHead;
    }
};
