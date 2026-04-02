class MinStack {
public:
    stack<int> minStack;
    stack<int> numStack;

    MinStack() {
       
    }
    
    void push(int val) {
        numStack.push(val);
        if (!minStack.empty()) {
            int prevMin = minStack.top();
            minStack.push(min(val, prevMin));
        } else {
            minStack.push(val);
        }
        
    }
    
    void pop() {
        numStack.pop();
        minStack.pop();
    }
    
    int top() {
        return numStack.top();
        
    }
    
    int getMin() {
        return minStack.top();
    }
};
