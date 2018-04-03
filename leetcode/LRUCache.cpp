class LRUCache{
public:
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->prev = head->next = tail;
        tail->prev = tail->next = head;
        cap = capacity;
        lookup.clear();
    }
    
    int get(int key) {
        if (lookup.find(key) == lookup.end()) return -1;
        Node *cur = lookup[key];
        detach(cur);
        attach(cur);
        return cur->val;
    }
    
    void set(int key, int value) {
        Node *cur;
        if (lookup.find(key) != lookup.end()) {
            cur = lookup[key];
            cur->val = value;
            detach(cur);
            attach(cur);
            return;
        }
        
        if (lookup.size() == cap) {
            Node *tmptail = tail->prev;
            detach(tmptail);
            lookup.erase(tmptail->key);
            delete tmptail;
        }
        
        cur = new Node(key, value);
        attach(cur);
        lookup[key] = cur;
    }
    
private:
    struct Node {
        Node *prev, *next;
        int key, val;
        Node (int nkey, int value) : key(nkey), val(value), prev(NULL), next(NULL) {}
    };
    Node *head, *tail;
    unordered_map<int, Node *> lookup;
    int cap;
    
    void attach(Node *cur) {
        cur->next = head->next;
        cur->prev = head;
        head->next = cur;
        cur->next->prev = cur;
    }
    
    void detach(Node *cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
};
