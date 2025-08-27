class LRUCache {
public:

    class node {
        public:
          node* next;
          node* prev;
          int key;
          int val;
          node (int key_, int val_){
            this->key = key_;
            this->val=val_;
            next = nullptr;
            prev = nullptr;
          }

    };

    int cap;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    map<int, node*>m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newNode){
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev =head;
    }

    void deleteNode(node* oldNode){
        oldNode->prev->next = oldNode->next;
        oldNode->next->prev = oldNode->prev;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()){
            node* target = m[key];
            deleteNode(target);
            addNode(target);
            return target->val;
        }

        return -1;
    }
    
    void put(int key, int val) {
        if (m.find(key) != m.end()){
            node* target = m[key];
            deleteNode(target);
            delete(target);
            m.erase(key);
        }

        if (m.size() == cap){
            node* lol = tail->prev;
            deleteNode(lol);
            m.erase(lol->key);
            delete(lol);
            
        }

        node* lol2 = new node(key, val);
        addNode(lol2);
        m[key] = lol2;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */