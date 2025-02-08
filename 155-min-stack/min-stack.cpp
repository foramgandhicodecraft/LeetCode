class MinStack {
public:
    int top_stack = 0;
    vector<int>stack;
    MinStack() {
        // int top = -1;
        // vector<int>stack;
        // return NULL;
    }
    
    void push(int val) {
        top_stack++;
        stack.push_back(val);
    }
    
    void pop() {
        top_stack--;
        stack.pop_back();
    }
    
    int top() {
        return stack[top_stack-1];
    }
    
    int getMin() {
        int min = stack[0];
        for (int i = 1; i < stack.size(); i++){
            if (stack[i] < min){
                min = stack[i];
            }
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */