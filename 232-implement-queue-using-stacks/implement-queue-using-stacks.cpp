class MyQueue {
public:
    vector<int>queue;
    MyQueue() {
        
    }
    
    void push(int x) {
        queue.push_back(x);
    }
    
    int pop() {
        int x;
        x = queue[0];
        queue.erase(queue.begin(),queue.begin()+1);
        return x;
    }
    
    int peek() {
        return queue[0];
    }
    
    bool empty() {
        if (queue.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */