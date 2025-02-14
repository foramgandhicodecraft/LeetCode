class MyStack {
public:
    vector<int>queue;

    MyStack() {
        
    }
    
    void push(int x) {
        queue.push_back(x);
    }
    
    int pop() {
        int x;
        x = queue[queue.size()-1];
        queue.pop_back();
        return x;
    }
    
    int top() {
        int element = queue[queue.size()-1];
        return element;
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
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */