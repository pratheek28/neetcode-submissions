class MinStack {
private:
    std::stack<int> main_stack;
    std::stack<int> min_stack;

public:
    MinStack() {}
    
    void push(int val) {
        main_stack.push(val);
        
        if (min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        }
    }
    
    void pop() {
        if (main_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        main_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
