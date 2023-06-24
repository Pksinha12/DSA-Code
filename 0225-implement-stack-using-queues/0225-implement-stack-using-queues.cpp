class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        //constructor
    }
    
    void push(int x) {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
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