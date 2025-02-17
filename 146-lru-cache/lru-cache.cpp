class LRUCache {
public:
    class node {
    public:
        node* next;
        node* previous;
        int key;
        int value;
        node(int key_, int value_) {
            this->key = key_;
            this->value = value_;
            next = nullptr;
            previous = nullptr;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    unordered_map<int, node*> m;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->previous = head;
    }

    void addnode(node* newnode) {
        newnode->next = head->next;
        head->next->previous = newnode;
        head->next = newnode;
        newnode->previous = head;
    }

    void deletenode(node* oldnode) {
        oldnode->previous->next = oldnode->next;
        oldnode->next->previous = oldnode->previous;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            node* runnode = m[key];
            deletenode(runnode);
            addnode(runnode);
            return runnode->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            node* existingnode = m[key];
            deletenode(existingnode);
            delete(existingnode);
            m.erase(key);
        }
        if (m.size() == cap) {
            node* lru = tail->previous;
            deletenode(lru);
            m.erase(lru->key);
            delete(lru);
        }

        node* newnode = new node(key, value);
        addnode(newnode);
        m[key] = newnode;
    }
};
