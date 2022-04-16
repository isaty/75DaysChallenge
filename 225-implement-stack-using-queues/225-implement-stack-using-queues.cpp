class MyStack {
public:
    
    int t;
    queue<int>q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        t=x;
        q.push(x);
    }
    
    int pop() {
        
        int n=q.size()-1;
        while(n--)
        {
            t=q.front();
            q.pop();
            q.push(t);
        }
        
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return t;
    }
    
    bool empty() {
        return q.empty();
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