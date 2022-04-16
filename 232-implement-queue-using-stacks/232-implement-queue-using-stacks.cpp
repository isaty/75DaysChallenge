class MyQueue {
public:\
    stack<int>st;
    int t;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.empty())
            t=x;
        st.push(x);
    }
    
    int pop() {
        stack<int>st1;
        
        while(st.size()>1)
        {
            st1.push(st.top());
            st.pop();
        }
        
        int ans=st.top();
        st.pop();
        
        if(!st1.empty())
            t=st1.top();
        
        while(!st1.empty())
        {
            st.push(st1.top());
            st1.pop();
        }
        
        return ans;
    }
    
    int peek() {
        return t;
    }
    
    bool empty() {
        return st.empty();
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