struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    unordered_map<int, Node*> keyToNode;
    int cap;
    Node* tail;
    Node* head;
    
    void remove (Node* input) {
        Node* prev = input->prev;
        Node* next = input->next; 

        prev->next = next;
        next->prev = prev;
        input->next = nullptr;
        input->prev = nullptr;
    }
    void insert (Node* input) {
        Node* prev = tail->prev;

        prev->next = input;
        tail->prev = input;

        input->next = tail;
        input->prev = prev;
    }

public:

    LRUCache(int capacity) {
        cap = capacity;
        tail = new Node(0,0);
        head = new Node(0,0);

        tail->prev = head;
        head->next = tail;
        
    }
    
    int get(int key) {
        if (keyToNode.count(key) > 0) {
            Node* toRemove = keyToNode[key];
            remove(toRemove);
            insert(toRemove);
            return toRemove->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // Update condition:
        if (keyToNode.count(key) > 0) {
            Node* cached = keyToNode[key];
            remove(cached);
            cached->val = value;
            insert(cached);
            keyToNode[key] = cached;
            return;
        } 
        // Add
        Node* toAdd = new Node(key, value);
        insert(toAdd);
        keyToNode[key] = toAdd;

        // if exceeded capacity
        if (keyToNode.size() > cap) {
            Node* toRemove = head->next;
            keyToNode.erase(toRemove->key);
            remove(toRemove);
            delete toRemove;
        }
        return;

    }
};
