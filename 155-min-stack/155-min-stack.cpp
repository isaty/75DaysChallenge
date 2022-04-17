class MinStack {
private:
    stack<int>mn;
    stack<int>Elem;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(Elem.empty())
        {
            mn.push(val);
        } 
        else
        {
            if(mn.top()>val)
                mn.push(val);
            else 
                mn.push(mn.top());
        }
        
        Elem.push(val);
    }
    
    void pop() {
        
        if(!Elem.empty())
        {
            Elem.pop();
            mn.pop();
        }
    }
    
    int top() {
        
        return Elem.top();
    }
    
    int getMin() {
        return mn.top();
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