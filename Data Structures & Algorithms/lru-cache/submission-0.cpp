class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    unordered_map<int, Node*> mp;
    int cap;
    Node* left;
    Node* right;
public:
    void remove(Node* node) {
        Node* previous = node->prev;
        Node* nxt = node->next;

        previous->next = nxt;
        nxt->prev = previous;
    }

    void insert(Node* node) {
        Node* last = right->prev;

        last->next = node;
        node->prev = last;
        right->prev = node;
        node->next = right;
    }

    LRUCache(int capacity) {
        this->cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            remove(node);
            insert(node);
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
        }

        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        insert(newNode);

        if (mp.size() > cap) {
            Node* lru = left->next;
            mp.erase(lru->key);
            remove(lru);
            delete lru;
        }
    }
};