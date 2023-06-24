class MyStack {
public:
    queue<int> q1;
    MyStack() {
        //constructor
    }
    
    void push(int x) {
        q1.push(x);
        int sz = q1.size();
        
        for (int i = 0; i < sz-1; i++)
        {
            int top = q1.front();
            q1.pop();
            q1.push(top);
        }
    }
    
    int pop() {
        int f = q1.front();
        if (!q1.empty())
            q1.pop();
        return f;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if (q1.size() == 0) return true;
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