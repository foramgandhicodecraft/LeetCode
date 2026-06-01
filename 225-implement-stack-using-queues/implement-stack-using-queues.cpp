class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int size = q1.size();
        int i = 0;
        while (i < size-1){
            q2.push(q1.front());
            q1.pop();
            i++;
        }
        int ans = q1.front();
        q1.pop();
        i = 0;
        while (i < size-1){
            q1.push(q2.front());
            q2.pop();
            i++;
        }
        return ans;
    }
    
    int top() {
        int size = q1.size();
        int i = 0;
        while (i < size-1){
            q2.push(q1.front());
            q1.pop();
            i++;
        }
        int ans = q1.front();
        q2.push(q1.front());
        q1.pop();
        i = 0;
        while (i < size){
            q1.push(q2.front());
            q2.pop();
            i++;
        }
        return ans;
    }
    
    bool empty() {
        if (q1.size() == 0){
            return true;
        }
        return false;
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